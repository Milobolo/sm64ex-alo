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

#include "make_const_nonconst.h"
#include "levels/cotmc/header.h"

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

	AREA(1, cotmc_area_1),
		WARP_NODE(0x0A, LEVEL_COTMC, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BOB, 0x01, 0x1C, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_BOB, 0x01, 0x2C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BREAKABLE_BOX, -245, 3599, -147, 0, 0, 0, 0x00010001, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 55, 3599, -147, 0, 0, 0, 0x00010001, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 355, 3599, -147, 0, 0, 0, 0x00010001, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 9992, 3406, -3563, 0, 0, 0, 0x00010000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 8138, 3009, 1859, 0, 0, 0, 0x00010002, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 6459, 4673, -2084, 0, 0, 0, 0x00010000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 655, 3599, -147, 0, 0, 0, 0x00010001, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 955, 3599, -147, 0, 0, 0, 0x00010001, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1255, 3599, -147, 0, 0, 0, 0x00010001, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1555, 3599, -147, 0, 0, 0, 0x00010001, bhvHiddenObject),
		OBJECT(MODEL_CAP_SWITCH, 16187, 3745, -166, 0, -90, 0, 0x0006000A, bhvCapSwitch),
		OBJECT(MODEL_CHUCKYA, -4278, 3514, 4257, 0, 0, 0, 0, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -3563, 3514, 5211, 0, 0, 0, 0, bhvChuckya),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, -3886, 3745, -7252, 0, 0, 0, 0, bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, 8229, 3745, -3559, 0, 0, 0, 0, bhvBreakableBoxSmall),
		OBJECT(MODEL_CHUCKYA, -3531, 3514, 3225, 0, 0, 0, 0, bhvChuckya),
		OBJECT(MODEL_PURPLE_SWITCH, 10566, 3745, -2091, 0, 0, 0, 0, bhvFloorSwitchHeavy),
		OBJECT(MODEL_PURPLE_SWITCH, -8339, 4503, -147, 0, 0, 0, 1, bhvFloorSwitchHeavy),
		OBJECT(MODEL_PURPLE_SWITCH, 6882, 3745, 3392, 0, 0, 0, 2, bhvFloorSwitchHeavy),
		OBJECT(MODEL_NONE, 12355, 4272, -166, 0, 0, 0, 1, bhvHiddenStar),
		OBJECT(MODEL_HINT, -3828, 2611, 8938, 0, 0, 0, 0, bhvTEhDist),
		OBJECT(MODEL_HINT, -3828, 3745, 6657, 0, 0, 0, 1, bhvTEhDist),
		OBJECT(MODEL_HINT, -3766, 3745, -112, 0, 0, 0, 2, bhvTEhDist),
		OBJECT(MODEL_HINT, 15138, 3745, -112, 0, 0, 0, 3, bhvTEhDist),
		OBJECT(MODEL_METAL_BOX, -3828, 2611, 8275, 0, 0, 0, 0x000A0000, bhvPushableMetalBox),
		OBJECT(MODEL_METAL_BOX, 9454, 3745, 1817, 0, 0, 0, 0x000A0000, bhvPushableMetalBox),
		OBJECT(MODEL_METAL_BOX, 5824, 3745, -128, 0, 0, 0, 0x000A0000, bhvPushableMetalBox),
		OBJECT(MODEL_METAL_BOX, 6053, 3745, 3414, 0, 0, 0, 0x000A0000, bhvPushableMetalBox),
		OBJECT(MODEL_NONE, 8133, 3464, 1857, 0, 0, 0, 0x000A0000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 9455, 3764, 1809, 0, 0, 0, 0x000A0000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 5820, 3764, -135, 0, 0, 0, 0x000A0000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 9989, 3787, -3572, 0, 0, 0, 0x000A0000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 6456, 4868, -2093, 0, 0, 0, 0x000A0000, bhvHiddenStarTrigger),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -3828, 2611, 9605, 0, -180, 0, 0x000A0000, bhvWarpPipe),
		TERRAIN(cotmc_area_1_collision),
		MACRO_OBJECTS(cotmc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x25),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
