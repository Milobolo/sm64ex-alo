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
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _outside_mio0SegmentRomStart, _outside_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group10_mio0SegmentRomStart, _group10_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_grounds_geo_0006F4), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_VCUTM_GRILL, castle_grounds_geo_00070C), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_FLAG, castle_grounds_geo_000660), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CANNON_GRILL, castle_grounds_geo_000724), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(WARP_NODE_ENTRANCE, LEVEL_BOB, 1, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 1, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 1, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_F0, LEVEL_BOB, 1, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_DEATH, LEVEL_CASTLE_GROUNDS, 1, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x2A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x3A, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x4A, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x5A, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x6A, LEVEL_HMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x7A, LEVEL_LLL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x8A, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x9A, LEVEL_DDD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xAA, LEVEL_SL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xBA, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCA, LEVEL_TTM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 195, 0, 0, 0, 0, (0xC << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_WOODEN_SIGNPOST, 1113, 0, -5861, 0, 0, 0, (0 << 16) | (0), bhvMessagePanelTE),
		OBJECT(MODEL_WOODEN_SIGNPOST, 5198, 0, -3547, 0, 0, 0, (0 << 16) | (1), bhvMessagePanelTE),
		OBJECT(MODEL_WOODEN_SIGNPOST, 6488, -2065, -1028, 0, 16, 0, (0 << 16) | (2), bhvMessagePanelTE),
		OBJECT(MODEL_WOODEN_SIGNPOST, 8710, -51, 3307, 0, -90, 0, (0 << 16) | (3), bhvMessagePanelTE),
		OBJECT(MODEL_WOODEN_SIGNPOST, 4815, 121, 4687, 0, 180, 0, (0 << 16) | (4), bhvMessagePanelTE),
		OBJECT(MODEL_WOODEN_SIGNPOST, 1204, 639, 5098, 0, 180, 0, (0 << 16) | (5), bhvMessagePanelTE),
		OBJECT(MODEL_WOODEN_SIGNPOST, -1850, 1302, 3999, 0, 179, 0, (0 << 16) | (6), bhvMessagePanelTE),
		OBJECT(MODEL_WOODEN_SIGNPOST, -6395, 238, 195, 0, 90, 0, (0 << 16) | (7), bhvMessagePanelTE),
		OBJECT(MODEL_WOODEN_SIGNPOST, -7308, -1479, -3943, 0, 55, 0, (0 << 16) | (8), bhvMessagePanelTE),
		OBJECT(MODEL_WOODEN_SIGNPOST, -1071, 198, -7425, 0, 0, 0, (0 << 16) | (9), bhvMessagePanelTE),
		OBJECT(MODEL_EXCLAMATION_BOX, -1234, -126, -5503, 0, 0, 0, (1 << 16), bhvExclamationBox),
		OBJECT(MODEL_NONE, 0, 195, 0, 0, 0, 0, (0xB << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 0, 195, 0, 0, 0, 0, (0xA << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 995, 0, -6060, 0, 0, 0, (0x1A << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 4947, 0, -3724, 0, 0, 0, (0x2A << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 8240, -2065, 395, 0, 0, 0, (0x3A << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 9009, -51, 2976, 0, 0, 0, (0x4A << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 4617, 121, 4987, 0, 0, 0, (0x5A << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 1002, 639, 5242, 0, 0, 0, (0x6A << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -1638, 1302, 4232, 0, 0, 0, (0x7A << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -6599, 238, 499, 0, 0, 0, (0x8A << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -7312, -1479, -4195, 0, -33, 0, (0x9A << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -1217, 198, -7564, 0, 0, 0, (0xAA << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -18, -27, 1079, 0, -180, 0, (0xBA << 16), bhvWarpPipe),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x23),
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
