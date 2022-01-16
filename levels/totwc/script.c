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
#include "levels/totwc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_totwc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _totwc_segment_7SegmentRomStart, _totwc_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _sky_mio0SegmentRomStart, _sky_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, totwc_area_1),
		WARP_NODE(0x0A, LEVEL_TOTWC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_JRB, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_JRB, 0x01, 0x1C, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_JRB, 0x01, 0x2C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BALANCE_CENTER, -5822, 1534, 1402, 0, -180, 0, 0x000A0000, bhvBalancer),
		OBJECT(MODEL_BALANCE_CENTER, -4705, 698, 2206, 0, -90, 0, 0x000A0000, bhvBalancer),
		OBJECT(MODEL_NONE, 997, -251, -34, 0, 92, 0, (0 << 24) | (16 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_HINT, -1847, -440, -7, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (6), bhvTEhDist),
		OBJECT(MODEL_HINT, -3701, 1403, 0, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (7), bhvTEhDist),
		OBJECT(MODEL_HINT, -5821, 665, -26, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (9), bhvTEhDist),
		OBJECT(MODEL_HINT, -5795, 2661, -2853, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (10), bhvTEhDist),
		OBJECT(MODEL_HINT, -6247, 2002, -27, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (8), bhvTEhDist),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, -5799, 2661, -3000, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvBreakableBoxSmall),
		OBJECT(MODEL_PURPLE_SWITCH, -5799, 2002, -1540, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvFloorSwitchHeavy),
		OBJECT(MODEL_NONE, -4402, 1519, -1, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (2), bhvHiddenObject),
		OBJECT(MODEL_NONE, -4602, 1519, -1, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (2), bhvHiddenObject),
		OBJECT(MODEL_NONE, -4802, 1519, -1, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (2), bhvHiddenObject),
		OBJECT(MODEL_NONE, -5002, 1519, -1, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (2), bhvHiddenObject),
		OBJECT(MODEL_NONE, -5799, 1890, -1972, 33, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -5799, 2000, -2139, 33, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -5799, 2110, -2306, 33, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -5799, 2220, -2474, 33, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -5799, 2329, -2641, 33, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -6285, 2313, 144, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -6285, 2313, -156, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -6285, 2613, 144, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -6285, 2613, -156, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -6285, 2913, 144, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -6285, 2913, -156, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -5202, 1719, -1, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (2), bhvHiddenObject),
		OBJECT(MODEL_NONE, -5799, 2439, -2808, 33, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_PURPLE_SWITCH, 2221, -440, -5, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (2), bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_PURPLE_SWITCH, -5809, 1166, 2209, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_CAP_SWITCH, -8029, 3270, -4, 0, 0, 0, (0 << 24) | (3 << 16) | (0 << 8) | (11), bhvCapSwitch),
		OBJECT(MODEL_STAR, -8603, 3456, -4, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (1), bhvStar),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 124, -251, 0, 0, -90, 0, (0xB << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, -105, 216, -24, 0, 0, 0, (0xA << 16), bhvAirborneWarp),
		TERRAIN(totwc_area_1_collision),
		MACRO_OBJECTS(totwc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x28),
		TERRAIN_TYPE(TERRAIN_STONE),
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
