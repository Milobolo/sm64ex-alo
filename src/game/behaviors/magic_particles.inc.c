extern struct Surface gHoverPseudoFloor;
extern Gfx mat_spawn_border_spawn_radius[];
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
	if (gMarioState->Spell != ice_block){
		obj_mark_for_deletion(o);
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
}

void ceil_vine_loop(void){
	f32 scale = o->parentObj->oHomeY;
	o->header.gfx.scale[1] = scale;
	obj_copy_pos_and_angle(o, o->parentObj);
	o->oPosY += 100.0f;
	if (gMarioState->Spell != hanging_leaf){
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
	if (gMarioState->Spell != hanging_leaf){
		obj_mark_for_deletion(o);
	}
	if (o->oAction == 1){
		o->oAnimState = 1;
		load_object_collision_model();
	}else{
		o->oOpacity = 100;
		o->oAnimState = 0;
	}

}