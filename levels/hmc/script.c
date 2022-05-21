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
#include "levels/hmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_hmc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _hmc_segment_7SegmentRomStart, _hmc_segment_7SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _cave_mio0SegmentRomStart, _cave_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group7_mio0SegmentRomStart, _group7_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0xa, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, hmc_area_1),
		WARP_NODE(0x0A, LEVEL_HMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_HMC, 0x01, 0xA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_HMC, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_HMC, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOWSER_1, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_HMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GOOMBA, 5991, -385, 25, 0, -90, 0, (1 << 16) | (24), bhvGoombaTE),
		OBJECT(MODEL_GOOMBA, -2399, 2887, -5578, 0, -90, 0, (2 << 16) | (24), bhvGoombaTE),
		OBJECT(MODEL_GOOMBA, -12121, 5057, 983, 0, -90, 0, (0 << 16) | (28), bhvGoombaTE),
		OBJECT(MODEL_GOOMBA, 2846, 1301, -5273, 0, -90, 0, (1 << 16) | (30), bhvGoombaTE),
		OBJECT(MODEL_KOOPA_WITH_SHELL, -16822, 4295, -6030, 0, -90, 0, (25), bhvKoopaTE),
		OBJECT(MODEL_KOOPA_WITH_SHELL, 2524, 1437, -493, 0, -135, 0, (29), bhvKoopaTE),
		OBJECT(MODEL_MR_BLIZZARD, 2754, 1467, -13631, 0, -90, 0, (27), bhvMrBlizzardTE),
		OBJECT(MODEL_NONE, 4948, 376, 38, 0, -90, 0, (0xC << 16), bhvAirborneWarp),
		OBJECT(MODEL_NONE, -14647, 4844, 953, 0, -90, 0, (1), bhvBowserCourseRedCoinStar),
		OBJECT(MODEL_NONE, -14162, 4844, 953, 0, -90, 0, (0xD << 16), bhvAirborneWarp),
		OBJECT(MODEL_NONE, 4948, -385, 35, 0, -90, 0, (0xA << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_MR_I, 1756, 1467, -13660, 0, -90, 0, (26), bhvMrITE),
		OBJECT(MODEL_BITDW_WARP_PIPE, -13313, 4336, 953, 0, -90, 0, (0xB << 16) | (3), bhvWarpPipe),
		TERRAIN(hmc_area_1_collision),
		MACRO_OBJECTS(hmc_area_1_macro_objs),
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
