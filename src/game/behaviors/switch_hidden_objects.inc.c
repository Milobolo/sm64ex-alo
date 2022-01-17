// switch_hidden_objects.c.inc

struct ObjectHitbox sBreakableBoxHitbox = {
    /* interactType: */ INTERACT_BREAKABLE,
    /* downOffset: */ 20,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 150,
    /* height: */ 200,
    /* hurtboxRadius: */ 150,
    /* hurtboxHeight: */ 200,
};

void breakable_box_init(void) {
    o->oHiddenObjectUnkF4 = NULL;
    o->oAnimState = 1;
    switch (o->oBehParams2ndByte) {
        case 0:
            o->oNumLootCoins = 0;
            break;
        case 1:
            o->oNumLootCoins = 3;
            break;
        case 2:
            o->oNumLootCoins = 5;
            break;
        case 3:
            cur_obj_scale(1.5f);
            break;
    }
}

void hidden_breakable_box_actions(void) {
    struct Object *sp1C;
    obj_set_hitbox(o, &sBreakableBoxHitbox);
    cur_obj_set_model(MODEL_BREAKABLE_BOX_SMALL);
    if (o->oAction == 0) {
        cur_obj_set_model(MODEL_HOLLOW_BOX);
		cur_obj_unhide();
        cur_obj_become_intangible();
			if (o->oBehParams2ndByte == 0){
				o->oHiddenObjectUnkF4 = cur_obj_find_nearest_object_with_behavior_and_bparam(bhvFloorSwitchHiddenObjects,o->oBehParams & 0xFF);
			}else{
				o->oHiddenObjectUnkF4 = cur_obj_find_nearest_object_with_behavior_and_bparam(bhvFloorSwitchHeavy,o->oBehParams & 0xFF);
				cur_obj_scale(1.5f);
			}
        if ((sp1C = o->oHiddenObjectUnkF4) != NULL)
            if (sp1C->oAction == 2) {
                o->oAction++;
                cur_obj_enable_rendering();
                cur_obj_unhide();
            }
    } else if (o->oAction == 1) {
        // cur_obj_become_tangible();
		if (o->oBehParams2ndByte == 0){
			if (cur_obj_wait_then_blink(200, 25))
				o->oAction = 0;
		}else{
			if(o->oHiddenObjectUnkF4->oAction == 0){
				o->oAction = 0;
			}
		}
        load_object_collision_model();
    } else {
        cur_obj_become_intangible();
        cur_obj_set_model(MODEL_HOLLOW_BOX);
		cur_obj_unhide();
        o->oInteractStatus = 0;
        if ((sp1C = o->oHiddenObjectUnkF4) != NULL)
            if (sp1C->oAction == 0)
                o->oAction = 0;
    }
}

void hidden_unbreakable_box_actions(void) {
    struct Object *sp1C;
    obj_set_collision_data(o, wdw_seg7_collision_07018528);
    if (o->oAction == 0) {
        cur_obj_set_model(MODEL_HOLLOW_BOX);
        cur_obj_become_intangible();
        if (o->oHiddenObjectUnkF4 == NULL)
            o->oHiddenObjectUnkF4 = cur_obj_find_nearest_object_with_behavior_and_bparam(bhvFloorSwitchHiddenObjects,o->oBehParams & 0xFF);
        if ((sp1C = o->oHiddenObjectUnkF4) != NULL)
            if (sp1C->oAction == 2) {
                o->oAction++;
                cur_obj_enable_rendering();
                cur_obj_unhide();
            }
    } else {
        // cur_obj_become_tangible();
        if (cur_obj_wait_then_blink(360, 20))
            o->oAction = 0;
        load_object_collision_model();
    }
}

void bhv_hidden_object_loop(void) {
    hidden_breakable_box_actions(); // Confused, that function has code depending on the action
}
