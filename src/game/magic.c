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
#include "sm64.h"
#include "main.h"
#include "mario.h"
#include "save_file.h"
#include "level_update.h"
#include "engine/math_util.h"
#include "object_list_processor.h"
#include "area.h"
#include "audio/external.h"
#include "text_engine.h"
#include "ingame_menu.h"
#include "segment2.h"
#include "game_init.h"
#include "object_helpers.h"
#include "puppyprint.h"
#include "rendering_graph_node.h"

#include "src/game/magic_str_te.py"
#include "src/game/magic_str_te.h"

void start_render_magic_spells_hud(void){
	SetupTextEngine(16,212,magic_spells_init, TE_STATE_AUX);
}

void cancel_render_magic_spells_hud(void){
	TE_end_str(&TE_Engines[TE_STATE_AUX]);
}

void magic_hud_render_controller(struct MarioState *m){
	if (gPlayer1Controller->buttonPressed&D_JPAD){
		start_render_magic_spells_hud();
	}if (gPlayer1Controller->buttonPressed&U_JPAD){
		cancel_render_magic_spells_hud();
	}
}

void update_mario_exp(struct MarioState *m){
	u32 Next = 100*m->Level*(m->Level/5);
	if (m->Exp >= Next){
		m->Exp -= Next;
		m->Level += 1;
		save_file_udpate_level(gCurrSaveFileNum - 1,  m);
	}
}