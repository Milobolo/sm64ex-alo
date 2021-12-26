#include <sm64.h>

/**
magic.c is a file for holding the special gimmick of SS4, magic.
Basically, this will contain the logic for magic spells, as well as mario's actions for casting them.
It will also contain basic enemy logic and enemy battle stuff like arenas, exp etc.
**/

#include <PR/ultratypes.h>
#include <PR/gbi.h>
#include "gfx_dimensions.h"
#include "print.h"
#include "rendering_graph_node.h"
#include "area.h"
#include "sm64.h"
#include "mario.h"
#include "game_init.h"
#include "save_file.h"
#include "level_update.h"
#include "engine/math_util.h"
#include "text_engine.h"
#include "ingame_menu.h"
#include "segment2.h"

#include "magic.h"

//header at the top for declarations
#include "src/game/magic_str_te.h"
#include "src/game/magic_tuts_te.h"

//vars
u32 gMagicHUDRequest = 0;

void start_render_magic_spells_hud(void){
	if ( !((gMarioState->action == ACT_CAST_ACTION) || (gMagicHUDRequest&HUD_OPEN)))
		switch(gMarioState->ForceSpell){
			default:
			case 0:
				SetupTextEngine(16,212,magic_spells_init, TE_STATE_AUX);
				break;
			case sp_return:
				SetupTextEngine(16,212,magic_spells_spell_init, TE_STATE_AUX);
				break;
		}
	
}

void cancel_render_magic_spells_hud(void){
	TE_end_str(&TE_Engines[TE_STATE_AUX]);
}

void magic_hud_render_controller(struct MarioState *m){
	if (gPlayer1Controller->buttonPressed&L_TRIG){
		start_render_magic_spells_hud();
	}if ( ((gPlayer1Controller->buttonPressed&Z_TRIG && gMagicHUDRequest<=0x40) || gMagicHUDRequest&CANCEL_HUD) && (gMarioState->action != ACT_CAST_ACTION)){
		cancel_render_magic_spells_hud();
		gMagicHUDRequest=0;
	}
}

void update_mario_exp(struct MarioState *m){
	u32 Next = 100*m->Level*(m->Level/3);
	if ((m->Level<20) && (m->Exp >= Next)){
		m->Exp -= Next;
		m->Level += 1;
		save_file_udpate_level(gCurrSaveFileNum - 1,  m);
	}
}

//cringe
extern Lights1 mario_shoes_v4_lights;
extern Lights1 mario_shoes_hover_v4_lights;
extern Lights1 mario_white_v4_lights;
extern Lights1 mario_white_stick_v4_lights;
extern Gfx mat_mario_white_v4[];
extern Gfx mat_mario_shoes_v4[];

void update_mario_colors_spirit(struct MarioState *m){
	Gfx *gloves = segmented_to_virtual(&mat_mario_white_v4);
	Gfx *shoes = segmented_to_virtual(&mat_mario_shoes_v4);
	if(m->Spell & ACTION_HOVER){
		gSPSetLights1(&shoes[5],mario_shoes_hover_v4_lights);
	}else{
		gSPSetLights1(&shoes[5],mario_shoes_v4_lights);
	}
	if(m->Spell & ACTION_STICK){
		gSPSetLights1(&gloves[5],mario_white_stick_v4_lights);
	}else{
		gSPSetLights1(&gloves[5],mario_white_v4_lights);
	}
}


void handle_magic_actions(struct MarioState *m){
	if(gMagicHUDRequest & HUD_MAIN){
		if(wait_set_mario_cast(m) == 0){
			gMagicHUDRequest |= CAST_WAIT;
		}else{
			gMagicHUDRequest &= ~CAST_WAIT;
		}
	}
	if(gMagicHUDRequest & START_CAST){
		if(wait_set_mario_cast(m) != 0){
			set_mario_action(m, ACT_CAST_SELECT, 0);
			gMagicHUDRequest &= ~START_CAST;
			gMagicHUDRequest |= CASTING_SEL;
			gMagicHUDRequest &= ~CAST_WAIT;
		}
	}
	if(gMagicHUDRequest & CAST_SPIRIT){
		if(m->action != ACT_CAST_ACTION){
			set_mario_action(m, ACT_CAST_ACTION, 1);
			gMagicHUDRequest &= ~CASTING_SEL;
		}
	}
	if(gMagicHUDRequest & CAST_ENVIRONMENT){
		if(m->action != ACT_CAST_ACTION){
			set_mario_action(m, ACT_CAST_ACTION, 2);
			gMagicHUDRequest &= ~CASTING_SEL;
		}
	}
	if(gMagicHUDRequest & CAST_SPELL){
		if(m->action != ACT_CAST_ACTION){
			set_mario_action(m, ACT_CAST_ACTION, 0);
			gMagicHUDRequest &= ~CASTING_SEL;
		}
	}
	if(gMagicHUDRequest & CAST_ITEM){
		if(m->action != ACT_CAST_ACTION){
			set_mario_action(m, ACT_CAST_ACTION, 3);
			gMagicHUDRequest &= ~CASTING_SEL;
		}
	}
}

u32 wait_set_mario_cast(struct MarioState *m){
	u32 action = m->action;
	u32 ret = 0;
	switch (action & ACT_GROUP_MASK) {
		case ACT_GROUP_MOVING:
		case ACT_GROUP_STATIONARY:
			if(m->heldObj == NULL){
				ret = 1;
			}
			break;

		case ACT_GROUP_AIRBORNE:
		case ACT_GROUP_OBJECT:
		case ACT_GROUP_SUBMERGED:
		case ACT_GROUP_CUTSCENE:
		case ACT_GROUP_AUTOMATIC:
			//wait
			break;
	}
	return ret;
}

u32 create_magic_list_dialog(u32 list, u8 usr){
	u8 cnt = 0;
	u32 i;
	switch(list){
		//item list
		case 0:
			for (i = 0; i<3; i++){
				cnt += mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//spell list
		case 1:
			for (i = 3; i<6; i++){
				cnt += mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//spirit list
		case 2:
			for (i = 6; i<9; i++){
				cnt += mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//env list
		case 3:
			for (i = 9; i<12; i++){
				cnt += mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
	}
	if (cnt){
		UserInputs[TE_STATE_AUX][usr][0] = 0x85;
		UserInputs[TE_STATE_AUX][usr][1] = cnt-1;
		UserInputs[TE_STATE_AUX][usr][2] = 0x45;
		return 1;
	}
	else{
		UserInputs[TE_STATE_AUX][usr][0] = 0x45;
		return 0;
	}
}
s32 sYoffset = 0;
void list_scroll_y_dialog(void){
	u8 y = TE_Engines[TE_STATE_AUX].HoveredDialog;
	if (((0xD * (y-2))>sYoffset) || ((sYoffset-(0xD * y))>0)){
		sYoffset = (0xD * (y-2));
		if (sYoffset<0){
			sYoffset = 0;
		}
	}
	TE_Engines[TE_STATE_AUX].TempY += sYoffset;
}

//TE has the limitation where you cannot compile runtime vars, only pointers to them
u32 mario_has_spell_TE(s16 *file, u32 spell){
	return mario_has_spell(*file-1,spell);
}

u32 Get_Spell_Sel(u32 list){
	u8 cnt[3];
	u32 i;
	u8 y = TE_Engines[TE_STATE_AUX].ReturnedDialog+1;
	switch(list){
		//item list
		case 0:
			for (i = 0; i<3; i++){
				cnt[i] = mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//spell list
		case 1:
			for (i = 3; i<6; i++){
				cnt[i-3] = mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//spirit list
		case 2:
			for (i = 6; i<9; i++){
				cnt[i-6] = mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//env list
		case 3:
			for (i = 9; i<12; i++){
				cnt[i-9] = mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
	}
	u8 x = 0;
	u8 z = 0;
	for (i = 0; i<3; i++){
		if (cnt[i]==1){
			x += 1;
		}
		if (x == y){
			z = i;
			break;
		}
	}
	return z;
}

u32 mario_can_cast(void){
	if (gMarioState->flags & MARIO_WING_CAP){
		return 1;
	}else{
		return 0;
	}
}

void mario_set_spell(u32 spell){
	gMarioState->CastSpell = spell;
	//update spell
	if (spell == 0){
		return;
	}
	//item
	if(spell<ACTION_RETURN){
		if(spell != ACTION_MAGIC_HAT){
			gMarioState->Spell = 0;
		}else{
			gMarioState->Spell = spell;
		}
	}
	//spell
	else if(spell<ACTION_GIGANTIFY){
		gMarioState->Spell = spell | (gMarioState->Spell&(~0x38));
	}
	//spirit
	else if(spell<ACTION_ICE_BLOCK){
		if((gMarioState->Spell & spell) == spell){
			gMarioState->Spell = (gMarioState->Spell&(~0x1c0));
			gMarioState->CastSpell = ACTION_CANCEL_SPIRIT;
		}else{
			gMarioState->Spell = spell | (gMarioState->Spell&(~0x1c0));
		}
	}
	//env
	else{
		gMarioState->Spell = spell | (gMarioState->Spell&(~0x1e00));
	}
}


//file at bottom so function in here are declared before compile
#include "src/game/magic_str_te.py"
#include "src/game/magic_tuts_te.py"
