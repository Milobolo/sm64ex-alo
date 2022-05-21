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
	LOAD_MIO0(0x0A, _ccm_skybox_mio0SegmentRomStart, _ccm_skybox_mio0SegmentRomEnd), 
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
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ccm_geo_00042C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ccm_geo_00045C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, ccm_geo_000494), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, ccm_geo_0004BC), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, ccm_geo_0004E4), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_CABIN_DOOR, cabin_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_ROPEWAY_LIFT, ccm_geo_0003D0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_BASE, ccm_geo_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_HEAD, ccm_geo_00040C), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_SL, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_WF, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BOBOMB_BUDDY, -2790, 760, 1081, 0, -180, 0, (0 << 16) | (9), bhvPinkBuddyTE),
		OBJECT(MODEL_NONE, -6775, -521, 210, 0, 90, 0, (0xC << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_DORRIE, 14593, 5113, 7369, 0, 0, 0, (20), bhvTEOnSpawn),
		OBJECT(MODEL_NONE, -6775, -804, 210, 0, 90, 0, (0xA << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_DORRIE, 16820, 4305, 11018, 0, 0, 0, (2 << 16) | (8), bhvDorrieCutscene),
		OBJECT(MODEL_RED_COIN, 2828, 2005, -619, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7950, 3002, 3688, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7558, 2078, -3461, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6521, 4035, -1507, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8628, 2658, 1283, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3023, 2778, 5352, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2750, 2150, 1515, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5208, 1896, -2659, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_NONE, 3788, 1473, 3252, 0, 0, 0, (1 << 24) | (1), bhvHiddenRedCoinStar),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x26),
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
