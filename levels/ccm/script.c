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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _snow_mio0SegmentRomStart, _snow_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group7_mio0SegmentRomStart, _group7_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group16_mio0SegmentRomStart, _group16_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(22, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(WARP_NODE_SUCCESS, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_STAR_GET, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_DEATH, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_REVIVE, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, -9233, -4219, 7644, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(0, -7758, -4200, 10578, 0, -90, 0, 0x10000, bhvAirborneDeathWarp),
		OBJECT(0, -7758, -4200, 10578, 0, 90, 0, 0x0, bhvAirborneStarCollectWarp),
		OBJECT(31, -9604, -4419, 10576, 0, 90, 0, 0x1010000, bhvDoor),
		OBJECT(137, 1938, 964, 7527, 0, 0, 0, 0xf0000, bhvExclamationBox),
		OBJECT(0, 583, 2683, -5387, 0, -154, 0, 0xb0000, bhvFadingWarp),
		OBJECT(0, 1680, 3835, -5523, 0, -153, 0, 0xc0000, bhvFadingWarp),
		OBJECT(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 1980, 768, 6618, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT(180, 9938, 1750, 2341, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 821, 1395, -4910, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, -3545, -2363, 5614, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(0, 4271, 1395, -5733, 0, 0, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -5988, 52, -4375, 0, -180, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -6138, 52, -4375, 0, -180, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -5838, 52, -4375, 0, -180, 0, 0x0, bhvFlamethrower),
		OBJECT(207, 11252, 1575, 1971, 0, 0, 0, 0x0, bhvFloorSwitchAnimatesObject),
		OBJECT(207, 11002, 1575, 1071, 0, 0, 0, 0x0, bhvFloorSwitchAnimatesObject),
		OBJECT(207, 11077, 1875, 571, 30, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(192, 2780, 1219, -4921, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(129, 10877, 3275, -2471, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 11077, 2475, -29, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 11077, 2675, -1771, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 10077, 3271, -3275, 0, 45, 0, 0x0, bhvHiddenObject),
		OBJECT(124, -9110, -4419, 9260, 0, 90, 0, 0x0, bhvMessagePanel),
		OBJECT(124, -9269, -4419, 8270, 0, 90, 0, 0x10000, bhvMessagePanel),
		OBJECT(124, -6551, -152, -2017, 0, -180, 0, 0x30000, bhvMessagePanel),
		OBJECT(217, -5105, -4338, 7075, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, -4245, -3938, 6764, 0, 0, 45, 0x0, bhvPushableMetalBox),
		OBJECT(217, -3345, -3370, 6764, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, -2745, -2370, 6164, 45, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, -3545, -2770, 5764, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, -2045, -2070, 6964, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, 2560, 1041, -694, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, -1958, -300, 7988, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, 10777, 2675, -871, 0, 0, 45, 0x0, bhvPushableMetalBox),
		OBJECT(217, 9277, 3196, -4075, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, 9277, 3196, -4375, 0, -180, 0, 0x0, bhvPushableMetalBox),
		OBJECT(0, -7633, -2572, 12753, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(0, -9848, -4369, 10578, 0, 0, 0, 0xb0000, bhvWarp),
		OBJECT(MODEL_STAR, -5968, 305, -2562, 0, -180, 0, 0x00000000, bhvStar),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x27),
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
