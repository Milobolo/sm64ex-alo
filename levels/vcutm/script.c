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
#include "levels/vcutm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_vcutm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0_TEXTURE(0x09, _outside_mio0SegmentRomStart, _outside_mio0SegmentRomEnd), 
	LOAD_MIO0(0x07, _vcutm_segment_7SegmentRomStart, _vcutm_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x05, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	LOAD_MODEL_FROM_GEO(MODEL_VCUTM_SEESAW_PLATFORM, vcutm_geo_0001F0), 
	LOAD_MODEL_FROM_GEO(MODEL_VCUTM_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, vcutm_area_1),
		WARP_NODE(0x0A, LEVEL_VCUTM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_WF, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_WF, 0x01, 0x1C, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_WF, 0x01, 0x2C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_HINT, -5, -304, -1554, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (12), bhvTEhDist),
		OBJECT(MODEL_HINT, 1241, 696, -3795, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (13), bhvTEhDist),
		OBJECT(MODEL_HINT, -2969, 4811, 140, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (14), bhvTEhDist),
		OBJECT(MODEL_HINT, -4958, 5023, 2254, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (15), bhvTEhDist),
		OBJECT(MODEL_CAP_SWITCH, -8727, 5942, 6022, 0, 0, 0, (0 << 24) | (9 << 16) | (0 << 8) | (12), bhvCapSwitch),
		OBJECT(MODEL_STAR, -10952, 4887, 8230, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (1), bhvStar),
		OBJECT(MODEL_SQUARE_FLAT, -861, 4055, -2883, 0, -45, 0, (0 << 24) | (16 << 16) | (0xB << 8) | (0xD8), bhvSquareForward),
		OBJECT(MODEL_SQUARE_FLAT, -2298, 4055, -32, 0, 135, 0, (0 << 24) | (16 << 16) | (0xB << 8) | (0xD8), bhvSquareForward),
		OBJECT(MODEL_SQUARE_FLAT, 2264, 559, -3831, 0, 0, 0, (0 << 24) | (16 << 16) | (5 << 8) | (0xa0), bhvSquareVert),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 4, -485, 767, 0, 180, 0, (0xB << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 0, 20, -110, 0, -180, 0, (0xA << 16), bhvAirborneWarp),
		TERRAIN(vcutm_area_1_collision),
		MACRO_OBJECTS(vcutm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2B),
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
