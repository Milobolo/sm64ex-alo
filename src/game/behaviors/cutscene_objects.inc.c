u32 DorriCutsceneFlags;
static void Dorrie_Intro_Cutscene(void){
	switch(o->oAction){
		case 0:
			if(DorriCutsceneFlags == 1){
				o->oAction++;
				DorriCutsceneFlags = 0;
			}
			cur_obj_hide();
			break;
		case 1:
			cur_obj_unhide();
			//move forward 1600 units for 3 sec
			o->oForwardVel = 17.77f;
			if(o->oTimer > 90){
				o->oAction++;
			}
			cur_obj_move_xz_using_fvel_and_yaw();
			break;
		//begin talking, send signal with var
		case 2:
			DorriCutsceneFlags = 1;
			break;
	}
}
static void Dorrie_Talk(void){
	o->oIntangibleTimer = 0;
	struct TEState *eng = o->oTextEngine;
	switch(o->oAction){
		case 0:
			if (o->oInteractStatus == INT_STATUS_INTERACTED){
				o->oAction = 1;
				cur_obj_play_sound_2(SOUND_OBJ_DORRIE);
			}
			break;
		case 1:
			if (eng->OgStr == NULL) {
				o->oBobombBuddyHasTalkedToMario = BOBOMB_BUDDY_HAS_TALKED;
				o->oInteractStatus = 0;
				o->oAction = 2;
			}
			break;
		case 2:
			if(o->oBehParams2ndByte == 2){
				f32 Zoff = coss(o->oFaceAngleYaw)*1000.0f;
				f32 Xoff = sins(o->oFaceAngleYaw)*1000.0f;
				//get star to not inherit BP
				u32 tmp = o->oBehParams;
				o->oBehParams = 0;
				spawn_default_star(o->oPosX + Xoff, o->oPosY + 200.0f, o->oPosZ + Zoff);
				o->oBehParams = tmp;
				o->oBehParams2ndByte = 0;
			}
			o->oAction = 0;
			break;
	}
}

void bhv_dorrie_cutscene_loop(void){
	switch(o->oBehParams2ndByte){
		// just an NPC, bp == 2 to spawn star after talking
		case 0:
		case 2:
			Dorrie_Talk();
			break;
		//lvl 1 cutscene
		case 1:
			Dorrie_Intro_Cutscene();
			break;
	}
}

void SavePowerWorld(void){
	
}

void bhv_anime_goomba_TE_loop(void){
	
}

void bhv_goomba_TE_init(void){
	o->oAnimState = o->oBehParams2ndByte;
}

static void obj_start_TE(void){
	SetupTextEngine(32,60,TE_Strings[o->oBehParams],TE_STATE_MAIN);
	obj_mark_for_deletion(o);
	set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
}

u8 TE_collect_star_no_exit = 0;

void bhvTEOnSpawn_Trigger(void){
	switch(o->oBehParams2ndByte){
		//on star collect
		case 0:
			if(TE_collect_star_no_exit && ((gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_STATIONARY)){
				TE_collect_star_no_exit = 0;
				obj_start_TE();
			}
			break;
	}
}

void bhvTEOnSpawn_loop(void){
	if((gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_STATIONARY){
		obj_start_TE();
	}
}

u8 GetCurrentCutscene(void){
	return gCurrentArea->camera->cutscene;
}
void Dorrie_Invite_Cutscene(void){
	start_cutscene(gCurrentArea->camera,CUTSCENE_DORRIE_INVITE);
}

void Star_Anime_Goomba_Cutscene(void){
	start_cutscene(gCurrentArea->camera,CUTSCENE_ANIME_GOOMBAS);
}