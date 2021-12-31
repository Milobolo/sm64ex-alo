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
#include "levels/cotmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_cotmc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _cotmc_segment_7SegmentRomStart, _cotmc_segment_7SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _cave_mio0SegmentRomStart, _cave_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_9), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_global_1), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, cotmc_area_1),
		WARP_NODE(0x0A, LEVEL_COTMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BOB, 0x01, 0x1C, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_BOB, 0x01, 0x2C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BREAKABLE_BOX, -123, 4224, -291, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 177, 4224, -291, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 477, 4224, -291, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 10114, 4032, -3707, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 8260, 3635, 1715, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (2), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 6581, 5299, -2229, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 777, 4224, -291, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1077, 4224, -291, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1377, 4224, -291, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1677, 4224, -291, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_CAP_SWITCH, 16309, 4370, -310, 0, -90, 0, (0 << 24) | (6 << 16) | (0 << 8) | (10), bhvCapSwitch),
		OBJECT(MODEL_CHUCKYA, -4156, 4139, 4113, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -3441, 4139, 5066, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvChuckya),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, 8351, 4370, -3704, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvBreakableBoxSmall),
		OBJECT(MODEL_CHUCKYA, -3409, 4139, 3081, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvChuckya),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, -3764, 4370, -7397, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvBreakableBoxSmall),
		OBJECT(MODEL_PURPLE_SWITCH, 10688, 4370, -2235, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvFloorSwitchHeavy),
		OBJECT(MODEL_PURPLE_SWITCH, -8217, 5129, -291, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (1), bhvFloorSwitchHeavy),
		OBJECT(MODEL_PURPLE_SWITCH, 7004, 4370, 3248, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (2), bhvFloorSwitchHeavy),
		OBJECT(MODEL_NONE, 12477, 4897, -310, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (1), bhvHiddenStar),
		OBJECT(MODEL_HINT, -3706, 3237, 8794, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvTEhDist),
		OBJECT(MODEL_HINT, -3706, 4370, 6513, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (1), bhvTEhDist),
		OBJECT(MODEL_HINT, -3644, 4370, -256, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (2), bhvTEhDist),
		OBJECT(MODEL_HINT, 15260, 4370, -256, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (3), bhvTEhDist),
		OBJECT(MODEL_METAL_BOX, -3706, 3237, 8130, 0, 0, 0, (0 << 24) | (10 << 16) | (0 << 8) | (0), bhvPushableMetalBox),
		OBJECT(MODEL_METAL_BOX, 9576, 4370, 1673, 0, 0, 0, (0 << 24) | (10 << 16) | (0 << 8) | (0), bhvPushableMetalBox),
		OBJECT(MODEL_METAL_BOX, 5946, 4370, -273, 0, 0, 0, (0 << 24) | (10 << 16) | (0 << 8) | (0), bhvPushableMetalBox),
		OBJECT(MODEL_METAL_BOX, 6175, 4370, 3270, 0, 0, 0, (0 << 24) | (10 << 16) | (0 << 8) | (0), bhvPushableMetalBox),
		OBJECT(MODEL_TRIGGER, 8255, 4090, 1712, 0, 0, 0, (0 << 24) | (10 << 16) | (0 << 8) | (0), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRIGGER, 9577, 4390, 1664, 0, 0, 0, (0 << 24) | (10 << 16) | (0 << 8) | (0), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRIGGER, 5942, 4390, -280, 0, 0, 0, (0 << 24) | (10 << 16) | (0 << 8) | (0), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRIGGER, 10111, 4413, -3716, 0, 0, 0, (0 << 24) | (10 << 16) | (0 << 8) | (0), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRIGGER, 6578, 5493, -2238, 0, 0, 0, (0 << 24) | (10 << 16) | (0 << 8) | (0), bhvHiddenStarTrigger),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -3706, 3237, 9461, 0, -180, 0, (0 << 24) | (0xB << 16) | (0 << 8) | (0), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -3711, 3736, 8976, 0, -180, 0, (0 << 24) | (0xA << 16) | (0 << 8) | (0), bhvWarpPipe),
		TERRAIN(cotmc_area_1_collision),
		MACRO_OBJECTS(cotmc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x25),
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
