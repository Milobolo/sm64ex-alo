/**
 * Behavior for bhvFloorSwitchHardcodedModel, bhvFloorSwitchGrills, and
 * bhvFloorSwitchAnimatesObject.
 *
 * This controls the purple switches that Mario can step on to affect parts of
 * the environment.
 */

void bhv_purple_switch_loop(void) {
    UNUSED s32 unused;
    switch (o->oAction) {
        /**
         * Set the switch's model and scale. If Mario is standing near the
         * switch's middle section, transition to the pressed state.
         */
        case PURPLE_SWITCH_IDLE:
            cur_obj_set_model(MODEL_PURPLE_SWITCH);
            cur_obj_scale(1.5f);
            if (gMarioObject->platform == o && !(gMarioStates[0].action & MARIO_UNKNOWN_13)) {
                if (lateral_dist_between_objects(o, gMarioObject) < 127.5f) {
                    o->oAction = PURPLE_SWITCH_PRESSED;
                }
            }
            break;
        /**
         * Collapse the switch downward, play a sound, and shake the screen.
         * Immediately transition to the ticking state.
         */
        case PURPLE_SWITCH_PRESSED:
            cur_obj_scale_over_time(2, 3, 1.5f, 0.2f);
            if (o->oTimer == 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = PURPLE_SWITCH_TICKING;
                cur_obj_shake_screen(SHAKE_POS_SMALL);
#ifdef RUMBLE_FEEDBACK
                queue_rumble_data(5, 80);
#endif
            }
            break;
        /**
         * Play a continuous ticking sound that gets faster when time is almost
         * up. When time is up, move to a waiting-while-pressed state.
         */
        case PURPLE_SWITCH_TICKING:
            if (o->oBehParams2ndByte != 0) {
                if (o->oBehParams2ndByte == 1 && gMarioObject->platform != o) {
                    o->oAction++;
                } else {
                    if (o->oTimer < 150) {
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                    } else {
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
                    }
                    if (o->oTimer > 200) {
                        o->oAction = PURPLE_SWITCH_WAIT_FOR_MARIO_TO_GET_OFF;
                    }
                }
            }
            break;
        /**
         * Make the switch look unpressed again, and transition back to the
         * idle state.
         */
        case PURPLE_SWITCH_UNPRESSED:
            cur_obj_scale_over_time(2, 3, 0.2f, 1.5f);
            if (o->oTimer == 3) {
                o->oAction = PURPLE_SWITCH_IDLE;
            }
            break;
        /**
         * Mario is standing on the switch, but time has expired. Wait for
         * him to get off the switch, and when he does so, transition to the
         * unpressed state.
         */
        case PURPLE_SWITCH_WAIT_FOR_MARIO_TO_GET_OFF:
            if (!cur_obj_is_mario_on_platform()) {
                o->oAction = PURPLE_SWITCH_UNPRESSED;
            }
            break;
    }
}


void bhv_purple_heavy_switch_loop(void) {
    UNUSED s32 unused;
    
	switch (o->oAction) {
        /**
         * Set the switch's model and scale. If Mario is standing near the
         * switch's middle section, transition to the pressed state.
         */

        case PURPLE_SWITCH_IDLE:
            cur_obj_set_model(MODEL_PURPLE_SWITCH);
			struct Object *metal_box = cur_obj_nearest_object_with_behavior(bhvPushableMetalBox);
			struct Object *heavy_box = cur_obj_nearest_object_with_behavior(bhvBreakableBoxSmall);
            cur_obj_scale(2.0f);
            if (metal_box) {
                if (lateral_dist_between_objects(o, metal_box) < 127.5f && absf(o->oPosY - metal_box->oPosY)<150.0f) {
                    o->oAction = PURPLE_SWITCH_PRESSED;
					o->parentObj = metal_box;
					break;
                }
            }if (heavy_box){
                if (lateral_dist_between_objects(o, heavy_box) < 127.5f && absf(o->oPosY - heavy_box->oPosY)<150.0f) {
                    o->oAction = PURPLE_SWITCH_PRESSED;
					o->parentObj = heavy_box;
					break;
                }
			}
            break;
        /**
         * Collapse the switch downward, play a sound, and shake the screen.
         * Immediately transition to the ticking state.
         */
        case PURPLE_SWITCH_PRESSED:
            cur_obj_scale_over_time(2, 3, 2.0f, 0.2f);
            if (o->oTimer == 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = PURPLE_SWITCH_TICKING;
                cur_obj_shake_screen(SHAKE_POS_SMALL);
            }
            break;
        /**
         * Play a continuous ticking sound that gets faster when time is almost
         * up. When time is up, move to a waiting-while-pressed state.
         */
        case PURPLE_SWITCH_TICKING:
			o->oAction = PURPLE_SWITCH_WAIT_FOR_MARIO_TO_GET_OFF;
            break;
        /**
         * Make the switch look unpressed again, and transition back to the
         * idle state.
         */
        case PURPLE_SWITCH_UNPRESSED:
            cur_obj_scale_over_time(2, 3, 0.2f, 2.0f);
            if (o->oTimer == 3) {
                o->oAction = PURPLE_SWITCH_IDLE;
            }
            break;
        /**
         * Mario is standing on the switch, but time has expired. Wait for
         * him to get off the switch, and when he does so, transition to the
         * unpressed state.
         */
        case PURPLE_SWITCH_WAIT_FOR_MARIO_TO_GET_OFF:
			if (lateral_dist_between_objects(o, o->parentObj) > 127.5f || absf(o->oPosY - o->parentObj->oPosY)>10.0f) {
                    o->oAction = PURPLE_SWITCH_UNPRESSED;
                }
            break;
	}
}
