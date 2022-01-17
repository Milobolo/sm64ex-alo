#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bitdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bitdw_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _sky_mio0SegmentRomStart, _sky_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group11_mio0SegmentRomStart, _group11_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitdw_area_1),
		WARP_NODE(0x0A, LEVEL_BITDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 0x01, 0x1E, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 0x01, 0x2E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOWSER_1, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xD, LEVEL_BITDW, 0x01, 0xD, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BALANCE_CENTER, 689, 5037, 1574, 0, 40, 0, 0x000A0000, bhvBalancer),
		OBJECT(MODEL_BLACK_BOBOMB, -2223, 2490, -1763, 0, -91, 0, (0), bhvBobomb),
		OBJECT(MODEL_CHUCKYA, -126, 4459, -102, 0, -91, 0, (1), bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 2124, 2490, -1425, 0, -91, 0, (1), bhvChuckya),
		OBJECT(MODEL_NONE, -347, 4459, 45, 0, -91, 0, (1), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 93, 359, 2241, 0, -91, 0, (1), bhvGoombaTripletSpawner),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, -2037, 2490, -1555, 0, -136, 0, (1), bhvBreakableBoxSmall),
		OBJECT(MODEL_NONE, 1459, 2283, -1070, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1317, 2283, -928, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1176, 2283, -787, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1035, 2283, -646, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 129, 2283, -393, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -13, 2283, -252, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -154, 2283, -111, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -296, 2283, 31, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -1139, 2283, 121, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -1280, 2283, 262, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -1421, 2283, 404, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -1563, 2283, 545, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1617, 467, 1072, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1475, 467, 1214, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1334, 467, 1355, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1192, 467, 1496, 0, 45, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -2265, 2283, -648, 0, 90, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -2265, 2283, -448, 0, 90, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -2265, 2283, -248, 0, 90, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -2265, 2283, -48, 0, 90, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -1362, 2559, -2173, 0, 135, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -1150, 2859, -2385, 0, 135, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_PURPLE_SWITCH, -69, 359, 2070, 0, -91, 0, (1), bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_PURPLE_SWITCH, -2080, 2490, 963, 0, -136, 0, (1), bhvFloorSwitchHeavy),
		OBJECT(MODEL_ROT_SMALL, -85, 3293, -2114, 0, 0, 0, 0x000A0000, bhvRotatingBig),
		OBJECT(MODEL_NONE, 2230, 975, -292, 0, -91, 0, (0xA << 16) | (0), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 2332, 1607, -830, 0, 90, 0, (0 << 24) | (17 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -67, 3870, -2124, 0, 90, 0, (0 << 24) | (17 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 828, 5964, 1771, 0, 90, 0, (0 << 24) | (17 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1884, 6712, 1538, 0, 0, 0, (0xD << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_BITDW_WARP_PIPE, -2370, 6491, 1987, 0, 0, 0, (0xc << 16), bhvWarpPipe),
		TERRAIN(bitdw_area_1_collision),
		MACRO_OBJECTS(bitdw_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x29),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
