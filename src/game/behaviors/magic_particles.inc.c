extern struct Surface gHoverPseudoFloor;
extern Gfx mat_spawn_border_spawn_radius[];
extern Gfx mat_floating_cloud_cloud[];
extern Gfx mat_time_sphere_time_sphere[];
extern Gfx mat_return_portal_return_portal[];
extern struct Object *gFreezeTime;
struct Object *gReturn;
#include "src/game/magic.h"
#include "src/game/level_update.h"
#include "src/game/text_engine.h"

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
		if (o->oFloor && o->oAction == 1){
			struct Object *obj = o->oFloor->object;
			if (obj != NULL){
				if(obj->activeFlags & ACTIVE_FLAG_NO_COL || obj->activeFlags == ACTIVE_FLAG_DEACTIVATED){
					obj_mark_for_deletion(o);
				}
				o->oPosX += obj->oVelX;
				o->oPosY += obj->oVelY;
				o->oPosZ += obj->oVelZ;
				//copy so platform displacement happens on this obj also
				vec3f_copy(&o->oVelX, &obj->oVelX);
			}
		}
	}
	if (o->oAction == 1){
		o->oOpacity = 210;
		cur_obj_unused_init_on_floor();
		load_object_collision_model();
	}else{
		o->oOpacity = 120;
	}
}

void bhvSpawnBorder_loop(void){
	Gfx *F2 = segmented_to_virtual(mat_spawn_border_spawn_radius);
	ScrollF2(F2+11,10,0);
	if((gMarioState->spawnObj == 0) || (gMarioState->CastSpell == 0)){
		obj_mark_for_deletion(o);
	}
	obj_copy_pos(o, gMarioState->marioObj);
	if (gMarioState->Spell&ACTION_CLOUD_LOB){
		o->header.gfx.scale[0] = 0.75f;
		o->header.gfx.scale[1] = 0.6f;
		o->header.gfx.scale[2] = 0.75f;
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
		if(o->oCeil && o->oAction == 1){
			struct Object *obj = o->oCeil->object;
			if (obj != NULL){
				if(obj->activeFlags & ACTIVE_FLAG_NO_COL || obj->activeFlags == ACTIVE_FLAG_DEACTIVATED){
					obj_mark_for_deletion(o);
					o->oAction = 2;
				}
				o->oPosX += obj->oVelX;
				o->oPosY += obj->oVelY;
				o->oHomeY += obj->oVelY;
				o->oPosZ += obj->oVelZ;
				//copy so platform displacement happens on this obj also
				vec3f_copy(&o->oVelX, &obj->oVelX);
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

//bp4 is distance it moves, bp2 is spd it moves
void back_and_forth_loop(void){
	u16 bp4 = o->oBehParams&0xFFFF;
	u16 bp2 = (o->oBehParams>>16)&0xFFFF;
	if(bp2==0){
		bp2 = 1;
	}
	switch(o->oAction){
		case 0:
			o->oForwardVel = (f32) bp2;
			if(o->oTimer>=bp4/bp2){
				o->oAction = 1;
			}
			break;
		case 1:
			o->oForwardVel = 0;
			if(o->oTimer>=60){
				o->oAction = 2;
			}
			break;
		case 2:
			o->oForwardVel = (f32) -bp2;
			if(o->oTimer>=bp4/bp2){
				o->oAction = 3;
				o->oForwardVel = 0.0f;
			}
			break;
		case 3:
			o->oForwardVel = 0;
			if(o->oTimer>=60){
				o->oAction = 0;
			}
			break;
	}
	cur_obj_compute_vel_xz();
	cur_obj_move_using_vel();
}

//bp4 is distance it moves, bp2 is spd it moves
void up_and_down_loop(void){
	u16 bp4 = o->oBehParams&0xFFFF;
	u16 bp2 = (o->oBehParams>>16)&0xFFFF;
	if(bp2==0){
		bp2 = 1;
	}
	switch(o->oAction){
		case 0:
			o->oVelY = (f32) bp2;
			if(o->oTimer>=bp4/bp2){
				o->oAction = 1;
				o->oVelY = 0.0f;
			}
			break;
		case 1:
			if(o->oTimer>=60){
				o->oAction = 2;
				o->oVelY = (f32) -bp2;
			}
			break;
		case 2:
			if(o->oTimer>=bp4/bp2){
				o->oAction = 3;
				o->oVelY = 0.0f;
			}
			break;
		case 3:
			if(o->oTimer>=60){
				o->oAction = 0;
				o->oVelY = (f32) bp2;
			}
			break;
	}
	cur_obj_move_using_vel();
}

void bhvTEdistLoop(void){
	if( (o->oDistanceToMario < 400.0f) && (o->oAction == 0) ){
		TE_end_str(&TE_Engines[TE_STATE_BG]);
		SetupTextEngine(16,48,TE_Strings[o->oBehParams], TE_STATE_BG);
		o->oAction = 1;
	}else if (o->oAction ==1){
		if( o->oDistanceToMario > 1600.0f){
			o->oAction = 0;
		}
	}
}