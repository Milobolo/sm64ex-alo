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
#include "levels/bbh/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _bits_skybox_mio0SegmentRomStart, _bits_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _spooky_mio0SegmentRomStart, _spooky_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group9_mio0SegmentRomStart, _group9_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR, haunted_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP, geo_bbh_0005B0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM, geo_bbh_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF, geo_bbh_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR, geo_bbh_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND, geo_bbh_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB, geo_bbh_000658), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bbh_area_1),
		WARP_NODE(WARP_NODE_DEATH, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_REVIVE, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_SUCCESS, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_STAR_GET, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_PSS, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(0, -3065, 0, -12796, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 752, 4080, -13890, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -6154, 1446, -6319, 0, 0, 0, 0x0, bhvHiddenRedCoinStar),
		OBJECT(124, 802, 750, -471, 0, 0, 0, 0x400000, bhvMessagePanel),
		OBJECT(124, -6958, -356, -15208, 0, 135, 0, 0x410000, bhvMessagePanel),
		OBJECT(120, 6702, 742, -7401, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(120, 2723, 600, 3896, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(215, 4599, 1458, 3554, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 6710, 1072, -7409, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 708, 390, -7648, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 2859, 4800, -13434, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 762, 3390, -13792, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4890, 210, -11443, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3023, 0, -12524, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 6, 930, -1737, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, 765, 1350, 213, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(0, 764, 1920, -13281, 0, 0, 0, 0x0, bhvWarp),
		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
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
