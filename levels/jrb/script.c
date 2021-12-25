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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _water_mio0SegmentRomStart, _water_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _bitfs_skybox_mio0SegmentRomStart, _bitfs_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group2_mio0SegmentRomStart, _group2_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0c, LEVEL_TOTWC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_JRB, 0x01, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_JRB, 0x01, 0x0E, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BULLY_BOSS, -8635, -2543, 5421, 0, -180, 0, (3 << 24), bhvBigBullyWithMinions),
		OBJECT(MODEL_BULLY, -8030, -2728, 6032, 0, -180, 0, 0, bhvBigBullyMinion),
		OBJECT(MODEL_BULLY, -8030, -2728, 4812, 0, -180, 0, 0, bhvBigBullyMinion),
		OBJECT(MODEL_BULLY, -9246, -2728, 4812, 0, -180, 0, 0, bhvBigBullyMinion),
		OBJECT(MODEL_BULLY, -9246, -2728, 6035, 0, -180, 0, 0, bhvBigBullyMinion),
		OBJECT(MODEL_NONE, -6471, -1773, 7164, 0, 0, 0, (0x0D << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -6158, -2587, -781, 0, 0, 0, (0x0E << 16), bhvFadingWarp),
		OBJECT(MODEL_HANG_SWAP, -6467, -835, 4185, 0, 0, 0, 0, bhvHangswap),
		OBJECT(MODEL_HANG_SWAP, -6467, -349, 4932, 0, 0, 0, 0, bhvHangswap),
		OBJECT(MODEL_PURPLE_SWITCH, -6467, -825, 4818, 0, 0, 0, 0, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_PURPLE_SWITCH, 5141, -1142, 371, 0, -180, 0, 0, bhvFloorSwitchHeavy),
		OBJECT(MODEL_NONE, -6474, -515, 5948, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -6474, -515, 6148, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -6474, -515, 6348, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, 5848, -700, 94, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, 6223, -112, -452, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, 6647, 411, 262, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -6474, -515, 7163, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_STAR, 6638, 880, 259, 0, -180, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_STAR, -8992, -1606, -11925, 0, -180, 0, 0, bhvStar),
		OBJECT(MODEL_NONE, -551, -2640, 3014, 0, 0, 0, 0x000A0000, bhvAirborneWarp),
		OBJECT(MODEL_STAR, -6471, -180, 7161, 0, -180, 0, (0 << 24), bhvStar),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, 2862, -1751, 704, 0, -180, 0, 0, bhvBreakableBoxSmall),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 3589, -3153, 9124, 0, 0, 0, (0x0C << 16), bhvWarpPipe),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
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
