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

#include "areas/1/custom.model.inc.h"

#include "areas/2/custom.model.inc.h"

#include "areas/3/custom.model.inc.h"

#include "areas/4/custom.model.inc.h"

#include "levels/totwc/header.h"
extern u8 _totwc_segment_ESegmentRomStart[];
extern u8 _totwc_segment_ESegmentRomEnd[];

const LevelScript level_totwc_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_RAW(0x0E, _totwc_segment_ESegmentRomStart, _totwc_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Unspecified Models
	LOAD_MODEL_FROM_GEO(22,  warp_pipe_geo),
	LOAD_MODEL_FROM_GEO(23,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(24,  spiky_tree_geo),
	LOAD_MODEL_FROM_GEO(25,  snow_tree_geo),
	LOAD_MODEL_FROM_GEO(27,  palm_tree_geo),
	LOAD_MODEL_FROM_GEO(31,  metal_door_geo),
	LOAD_MODEL_FROM_GEO(32,  hazy_maze_door_geo),
	LOAD_MODEL_FROM_GEO(34,  castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(35,  castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(36,  castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(37,  key_door_geo),
	LOAD_MODEL_FROM_GEO(38,  castle_door_geo),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	// LOAD_MODEL_FROM_GEO(253, 0x07003c30),
	// LOAD_MODEL_FROM_GEO(254, 0x070028d0),
	// LOAD_MODEL_FROM_GEO(255, 0x07001570),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(local_area_totwc_1_),
	JUMP_LINK(local_area_totwc_2_),
	JUMP_LINK(local_area_totwc_3_),
	JUMP_LINK(local_area_totwc_4_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_totwc_1_[] = {
	AREA(1, Geo_totwc_1_0x178ad00),
	TERRAIN(col_totwc_1_0xe00c460),
	SET_BACKGROUND_MUSIC(0, 41),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_totwc_1_),
	JUMP_LINK(local_warps_totwc_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_totwc_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 2750, 0, 0, 90, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(22, 17, 3188, -1753, 0, 0, 0, 0x10000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(22, -1988, 2188, -4, 0, 90, 0, 0x20000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(137, 0, 3198, 0, 0, 0, 0, 0x0,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, 4047, 9958, -3494, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(22, 10, 2688, 2741, 0, 180, 0, 0x30000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(124, 4, 2384, -88, 0, 0, 0, 0xa60000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -50, 4, 52, 0, 0, 20, 31,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -50, 4, 52, 0, 0, 20, 32,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -50, 4, 52, 0, 0, 20, 33,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -50, 4, 52, 0, 0, 20, 34,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_totwc_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(1, 29, 2, 1, 0),
	WARP_NODE(2, 29, 3, 2, 0),
	WARP_NODE(3, 29, 4, 3, 0),
	WARP_NODE(240, 16, 1, 202, 0),
	WARP_NODE(241, 16, 1, 201, 0),
	RETURN()
};

const LevelScript local_area_totwc_2_[] = {
	AREA(2, Geo_totwc_2_0x178abf0),
	TERRAIN(col_totwc_2_0xe00ced0),
	SET_BACKGROUND_MUSIC(0, 41),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_totwc_2_),
	JUMP_LINK(local_warps_totwc_2_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_totwc_2_[] = {
	OBJECT_WITH_ACTS(0, 0, 2688, 0, 0, 90, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(22, 0, 2688, 0, 0, 90, 0, 0x10000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(253, 0, 3048, -507, 0, 0, 0, 0x30000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, 1522, 7101, 138, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(137, -12, 3048, 548, 0, 0, 0, 0x0,  bhvExclamationBox, 31),
	RETURN()
};

const LevelScript local_warps_totwc_2_[] = {
	WARP_NODE(2, 9, 2, 0, 0),
	WARP_NODE(1, 29, 1, 1, 0),
	WARP_NODE(240, 16, 1, 202, 0),
	WARP_NODE(241, 16, 1, 201, 0),
	RETURN()
};

const LevelScript local_area_totwc_3_[] = {
	AREA(3, Geo_totwc_3_0x178aad0),
	TERRAIN(col_totwc_3_0xe00a0a0),
	SET_BACKGROUND_MUSIC(0, 41),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_totwc_3_),
	JUMP_LINK(local_warps_totwc_3_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_totwc_3_[] = {
	OBJECT_WITH_ACTS(0, 0, 2688, 0, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(22, 0, 2688, 0, 0, 0, 0, 0x20000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(122, 1513, 3217, -5063, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(137, 0, 3048, -507, 0, 0, 0, 0x0,  bhvExclamationBox, 31),
	RETURN()
};

const LevelScript local_warps_totwc_3_[] = {
	WARP_NODE(10, 9, 3, 0, 0),
	WARP_NODE(2, 29, 1, 2, 0),
	WARP_NODE(240, 16, 1, 202, 0),
	WARP_NODE(241, 16, 1, 201, 0),
	RETURN()
};

const LevelScript local_area_totwc_4_[] = {
	AREA(4, Geo_totwc_4_0x178a9c0),
	TERRAIN(col_totwc_4_0xe007250),
	SET_BACKGROUND_MUSIC(0, 41),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_totwc_4_),
	JUMP_LINK(local_warps_totwc_4_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_totwc_4_[] = {
	OBJECT_WITH_ACTS(0, 0, 2688, 0, 0, 90, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(22, 0, 2688, 0, 0, 90, 0, 0x30000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(122, -3563, 5829, 3753, 0, 0, 0, 0x3000000,  bhvStar, 31),
	RETURN()
};

const LevelScript local_warps_totwc_4_[] = {
	WARP_NODE(10, 9, 4, 0, 0),
	WARP_NODE(3, 29, 1, 3, 0),
	WARP_NODE(240, 16, 1, 202, 0),
	WARP_NODE(241, 16, 1, 201, 0),
	RETURN()
};