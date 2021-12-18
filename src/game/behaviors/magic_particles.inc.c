extern struct Surface gHoverPseudoFloor;
extern Gfx mat_spawn_border_spawn_radius[];
extern Gfx mat_floating_cloud_cloud[];
extern Gfx mat_time_sphere_time_sphere[];
extern Gfx mat_return_portal_return_portal[];
extern struct Object *gFreezeTime;
struct Object *gReturn;
#include "src/game/magic.h"
#include "src/game/level_update.h"

void hover_particle_loop(void){
	obj_copy_pos_and_angle(o, o->parentObj);
	if (gHoverPseudoFloor.room == 90 || gMarioState->floor != &gHoverPseudoFloor){
		o->parentObj->oActiveParticleFlags &= (ACTIVE_PARTICLE_HOVER ^ 0xFFFFFFFF);
		obj_mark_for_deletion(o);
	}else{
		o->oOpacity = 255-(u32)((f32)gHoverPseudoFloor.room) * 255.0f/ 90.0f;
	}
}


void ice_block_loop(void){
	o->oDistanceToMario = lateral_dist_between_objects(o,gMarioObject);
	if(cur_obj_is_mario_on_platform()){
		gMagicHUDRequest |= CASTING_ON_PLAT;
	}else{
		gMagicHUDRequest &= ~CASTING_ON_PLAT;
	}
	if (!(gMarioState->Spell&ACTION_ICE_BLOCK) || (!(o->oFloor) && o->oAction == 1)){
		obj_mark_for_deletion(o);
	}else{
		if (o->oFloor){
			struct Object *obj = o->oFloor->object;
			if (obj != NULL){
				o->oPosX += obj->oVelX;
				o->oPosY += obj->oVelY;
				o->oPosZ += obj->oVelZ;
			}
		}
	}
	if (o->oAction == 1){
		o->oOpacity = 210;
		load_object_collision_model();
	}else{
		o->oOpacity = 120;
	}
}

void bhvSpawnBorder_loop(void){
	Gfx *F2 = segmented_to_virtual(mat_spawn_border_spawn_radius);
	ScrollF2(F2+11,10,0);
	if(gMarioState->spawnObj == 0){
		obj_mark_for_deletion(o);
	}
	if (gMarioState->Spell&ACTION_CLOUD_LOB){
		o->header.gfx.scale[0] = 0.5f;
		o->header.gfx.scale[1] = 0.6f;
		o->header.gfx.scale[2] = 0.5f;
	}
}

void bhvTimeSphere_loop(void){
	Gfx *F2 = segmented_to_virtual(mat_time_sphere_time_sphere);
	ScrollF2(F2+11,1,3);
	if (!(gMarioState->Spell&ACTION_TIME_FREEZE)){
		obj_mark_for_deletion(o);
		gFreezeTime = 0;
	}
}

void bhvReturnPortal_loop(void){
	Gfx *F2 = segmented_to_virtual(mat_return_portal_return_portal);
	ScrollF2(F2+11,6,0);
	if (!(gMarioState->Spell&ACTION_RETURN)){
		obj_mark_for_deletion(o);
	}
}

void ceil_vine_loop(void){
	f32 scale = o->parentObj->oHomeY;
	o->header.gfx.scale[1] = scale;
	obj_copy_pos_and_angle(o, o->parentObj);
	o->oPosY += 100.0f;
	if (!(gMarioState->Spell&ACTION_HANGING_LEAF) || (o->parentObj->oAction == 2)){
		obj_mark_for_deletion(o);
	}
}

void hanging_leaf_loop(void){
	o->oDistanceToMario = lateral_dist_between_objects(o,gMarioObject);
	if(cur_obj_is_mario_on_platform()){
		gMagicHUDRequest |= CASTING_ON_PLAT;
	}else{
		gMagicHUDRequest &= ~CASTING_ON_PLAT;
	}
	if (!(gMarioState->Spell&ACTION_HANGING_LEAF) || (!(o->oCeil) && o->oAction == 1)){
		obj_mark_for_deletion(o);
		o->oAction = 2;
	}else{
		if(o->oCeil){
			struct Object *obj = o->oCeil->object;
			if (obj){
				o->oPosX += obj->oVelX;
				o->oPosY += obj->oVelY;
				o->oPosZ += obj->oVelZ;
			}
		}
	}
	if (o->oAction == 1){
		o->oAnimState = 1;
		load_object_collision_model();
	}else{
		o->oOpacity = 100;
		o->oAnimState = 0;
	}

}

void floating_cloud_loop(void){
	o->oDistanceToMario = lateral_dist_between_objects(o,gMarioObject);
	Gfx *F2 = segmented_to_virtual(mat_floating_cloud_cloud);
	ScrollF2(F2+11,0,5);
	if(cur_obj_is_mario_on_platform()){
		gMagicHUDRequest |= CASTING_ON_PLAT;
	}else{
		gMagicHUDRequest &= ~CASTING_ON_PLAT;
	}
	if (!(gMarioState->Spell&ACTION_CLOUD_LOB)){
		obj_mark_for_deletion(o);
	}
	if (o->oAction == 1){
		load_object_collision_model();
	}
}