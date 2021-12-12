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

//vars
u32 gMagicHUDRequest = 0;

void start_render_magic_spells_hud(void){
	if ( !((gMarioState->action == ACT_CAST_ACTION) || (gMagicHUDRequest&HUD_OPEN)))
		SetupTextEngine(16,212,magic_spells_init, TE_STATE_AUX);
}

void cancel_render_magic_spells_hud(void){
	TE_end_str(&TE_Engines[TE_STATE_AUX]);
}

void magic_hud_render_controller(struct MarioState *m){
	if (gPlayer1Controller->buttonPressed&L_TRIG){
		start_render_magic_spells_hud();
	}if ( (gPlayer1Controller->buttonPressed&Z_TRIG && gMagicHUDRequest<=0x40) || gMagicHUDRequest&CANCEL_HUD){
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

void handle_magic_actions(struct MarioState *m){
	if(gMagicHUDRequest & START_CAST){
		if(wait_set_mario_cast(m) != 0){
			gMagicHUDRequest &= ~START_CAST;
			gMagicHUDRequest |= CASTING_SEL;
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
			ret = set_mario_action(m, ACT_CAST_SELECT, 0);
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
			for (i = 0; i<8; i++){
				cnt += mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//spell list
		case 1:
			for (i = 8; i<16; i++){
				cnt += mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//spirit list
		case 2:
			for (i = 16; i<24; i++){
				cnt += mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//env list
		case 3:
			for (i = 24; i<32; i++){
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
	u8 cnt[8];
	u32 i;
	u8 y = TE_Engines[TE_STATE_AUX].ReturnedDialog+1;
	switch(list){
		//item list
		case 0:
			for (i = 0; i<8; i++){
				cnt[i] = mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//spell list
		case 1:
			for (i = 8; i<16; i++){
				cnt[i-8] = mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//spirit list
		case 2:
			for (i = 16; i<24; i++){
				cnt[i-16] = mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
		//env list
		case 3:
			for (i = 24; i<32; i++){
				cnt[i-24] = mario_has_spell(gCurrSaveFileNum-1,i);
			}
			break;
	}
	u8 x = 0;
	u8 z = 0;
	for (i = 0; i<8; i++){
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

void mario_set_spell(u32 spell){
	gMarioState->Spell = spell;
}

//file at bottom so function in here are declared before compile
#include "src/game/magic_str_te.py"
