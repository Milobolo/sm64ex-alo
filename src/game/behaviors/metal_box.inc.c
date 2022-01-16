// metal_box.c.inc

struct ObjectHitbox sMetalBoxHitbox = {
    /* interactType: */ 0,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 320,
    /* height: */ 400,
    /* hurtboxRadius: */ 320,
    /* hurtboxHeight: */ 400,
};

s32 check_if_moving_over_floor(f32 a0, f32 a1) {
    struct Surface *sp24;
    f32 sp20 = o->oPosX + sins(o->oMoveAngleYaw) * a1;
    f32 floorHeight;
    f32 sp18 = o->oPosZ + coss(o->oMoveAngleYaw) * a1;
    floorHeight = find_floor(sp20, o->oPosY, sp18, &sp24);
	if (sp24 == NULL)
		return 0;
    if (absf(floorHeight - o->oPosY) < a0) // abs
        return 1;
    else
        return 0;
}
u32 collide_ice_block(void){
	if(o->numCollidedObjs){
		u8 i;
		for(i = 0; i<o->numCollidedObjs;i++){
			if(o->collidedObjs[i]->behavior = bhvIceBlock){
				return true;
			}
		}
	}
	return false;
}
void bhv_pushable_loop(void) {
    s16 sp1C;
	if(cur_obj_is_mario_ground_pounding_platform()){
		cur_obj_set_pos_to_home();
	}
    obj_set_hitbox(o, &sMetalBoxHitbox);
    o->oForwardVel = 0.0f;
	o->oPosY = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
    if (obj_check_if_collided_with_object(o, gMarioObject) && gMarioStates[0].flags & MARIO_UNKNOWN_31 && ((gMarioStates->Spell & ACTION_GIGANTIFY) == ACTION_GIGANTIFY)) {
        sp1C = obj_angle_to_object(o, gMarioObject);
        if (abs_angle_diff(sp1C, gMarioObject->oMoveAngleYaw) > 0x4000) {
            o->oMoveAngleYaw = (s16)((gMarioObject->oMoveAngleYaw + 0x2000) & 0xc000);
            if (check_if_moving_over_floor(100.0f, 300.0f) || collide_ice_block()) {
                o->oForwardVel = 8.0f;
                cur_obj_play_sound_1(SOUND_ENV_METAL_BOX_PUSH);
            }
        }
    }
    cur_obj_move_using_fvel_and_gravity();
	o->oWallHitboxRadius = 400.f;
	cur_obj_resolve_wall_collisions();
}
