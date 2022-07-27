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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _sr25_b3_skybox_mio0SegmentRomStart, _sr25_b3_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _grass_mio0SegmentRomStart, _grass_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(22, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(77, LEVEL_WF, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(99, LEVEL_WF, 1, 99, WARP_NO_CHECKPOINT),
		WARP_NODE(30, LEVEL_WF, 1, 20, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_WF, 1, 30, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_DEATH, LEVEL_WF, 1, WARP_NODE_REVIVE, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_SUCCESS, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_STAR_GET, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1E, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_REVIVE, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(212, 9747, 6595, 2618, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 3414, -5203, 9791, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -10347, 11250, 8798, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -5843, 6019, -1526, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 11252, 7931, -6061, 0, 90, 0, 0x0, bhv1Up),
		OBJECT(0, 12130, 4187, -11842, 0, -180, 0, 0xf10000, bhvAirborneDeathWarp),
		OBJECT(20, 12130, 4182, -11842, 0, 0, 0, 0x0, bhvBowserCourseRedCoinStar),
		OBJECT(129, 10932, 7342, 3239, 30, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(46, -11445, 1930, 8530, 0, 90, 0, 0x0, bhvCheckpoint_Flag_MOP),
		OBJECT(46, -5531, 9691, -7717, 0, -180, 0, 0x0, bhvCheckpoint_Flag_MOP),
		OBJECT(46, 8908, -1204, 2288, 0, -45, 0, 0x0, bhvCheckpoint_Flag_MOP),
		OBJECT(46, 12132, 3661, -13540, 0, 0, 0, 0x10000, bhvCheckpoint_Flag_MOP),
		OBJECT(223, -2762, -3377, 11752, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, -614, 4459, -7129, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, -6224, 9706, -5125, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, -5369, 9568, 2762, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, -10338, 3469, 8298, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 925, -5000, 10000, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 11634, 6755, 1821, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 8630, -985, 540, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(137, -5747, -2843, 8715, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, -5747, -2843, 9337, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, -5747, -2843, 9962, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, 11602, 6985, 1816, 0, 0, 0, 0x90000, bhvExclamationBox),
		OBJECT(0, 12134, 3661, -13538, 0, 0, 0, 0x4d0000, bhvFadingWarp),
		OBJECT(192, -9012, 5590, 8813, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, -5872, 9693, 2382, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, -8566, 10965, 7694, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, -5861, 4624, -2359, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, -10773, 1930, 8535, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, -5008, -2516, 11058, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, 4950, 5846, -11872, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, -8256, 10320, 8774, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, 11072, 8304, 288, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, 9429, 5691, 923, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(89, -201, -5007, 10195, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, -8637, 10221, 8260, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, -4393, 8411, 2822, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, 1594, 3991, -14516, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, 3730, 3991, -14267, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, 9291, -1004, -248, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, 11386, 7885, -5205, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, -5776, -3196, 9347, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, 1763, -5007, 9946, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(124, 3222, -7582, 9151, 0, 90, 0, 0x470000, bhvMessagePanel),
		OBJECT(124, 11227, 8706, -5939, 0, 0, 0, 0x480000, bhvMessagePanel),
		OBJECT(123, 10064, 4034, 80, 0, 0, 0, 0x2d0000, bhvNoteblock_MOP),
		OBJECT(215, -2610, -3623, 14294, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -6888, 10991, 7686, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -848, 4141, -10931, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -5844, 6901, -511, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -14518, 1575, 8744, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 10929, 8064, 2775, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -6679, 10441, -5755, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3970, 5736, -11489, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(153, -3210, 9114, -4531, 0, 0, 0, 0x0, bhvSandBlock_MOP),
		OBJECT(152, -5235, -2899, 10615, 0, 0, 0, 0x0, bhvShrink_Platform_MOP),
		OBJECT(206, -9977, 11188, 8734, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, 8621, 354, -1788, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, -5433, 8610, 5514, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, 2651, -4813, 10576, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, -5831, 8977, -6694, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, 9508, 4473, -113, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, 10943, 8314, 2427, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, -9366, 7359, 8690, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(0, 3534, -7118, 8812, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(0, 3534, -7118, 8812, 0, 0, 0, (WARP_NODE_REVIVE << 16), bhvAirborneDeathWarp),
		OBJECT(146, -488, 4483, -7412, -90, -176, 0, 0xb4960000, bhvSpring_MOP),
		OBJECT(22, 174, 3991, -13728, 0, 0, 0, 0x140000, bhvWarpPipe),
		OBJECT(22, 10555, -1164, -223, 0, 0, 0, 0x1e0000, bhvWarpPipe),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x25),
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
