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
	LOAD_MIO0(0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _grass_mio0SegmentRomStart, _grass_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group7_mio0SegmentRomStart, _group7_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_18), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_WDW, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_WF, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_MR_BLIZZARD, -1924, 2472, 4420, 0, 0, 0, 0x00000000, bhvMrBlizzard),
		OBJECT(MODEL_MR_BLIZZARD, 10432, 3702, -6034, 0, 0, 0, (0x20 << 16), bhvMrBlizzard),
		OBJECT(MODEL_MR_BLIZZARD, 5920, 473, 3169, 0, 0, 0, 0x00000000, bhvMrBlizzard),
		OBJECT(MODEL_MR_I, -83, 1802, 4442, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -5984, 2415, 4793, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -11849, 3066, 1881, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -3695, 3835, -1599, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -5984, 2415, 4545, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -5984, 2415, 4247, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -5984, 2415, 3980, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -5984, 2415, 3668, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -5984, 2848, 4793, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -5984, 2848, 4545, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -5984, 2848, 4247, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -5984, 2848, 3980, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -5984, 2848, 3668, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_NONE, -2032, 1052, 63, 0, 90, 0, (19), bhvTEOnSpawn),
		OBJECT(MODEL_NONE, 13845, 622, 3892, 0, -90, 0, (0xC << 16), bhvAirborneWarp),
		OBJECT(MODEL_NONE, 13845, 352, 3890, 0, -90, 0, (0xA << 16), bhvInstantActiveWarp),
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
