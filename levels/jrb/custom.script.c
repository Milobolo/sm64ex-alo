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

#include "levels/jrb/header.h"
#include "levels/bbh/header.h"

extern u8 _jrb_segment_ESegmentRomStart[];
extern u8 _jrb_segment_ESegmentRomEnd[];

const LevelScript level_jrb_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _jrb_segment_ESegmentRomStart, _jrb_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR,           haunted_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP,         geo_bbh_0005B0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM,      geo_bbh_0005E0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF,       geo_bbh_000610),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR,          geo_bbh_000628),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND,         geo_bbh_000640),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB,            geo_bbh_000658),
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
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(local_area_jrb_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_jrb_1_[] = {
	AREA(1, Geo_jrb_1_0x1361850),
	TERRAIN(col_jrb_1_0xe035580),
	SET_BACKGROUND_MUSIC(0, 26),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_jrb_1_),
	JUMP_LINK(local_warps_jrb_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_jrb_1_[] = {
	OBJECT_WITH_ACTS(0, 0, -3060, 0, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(122, -3499, 1525, 3499, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, -3875, -4651, 1624, 0, 0, 0, 0xe60000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -3875, -4651, 0, 0, 0, 0, 0x6e0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -3125, -4651, 0, 0, 0, 0, 0x6e0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -693, -5147, -694, 0, 0, 0, 0x780000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -693, -5157, 693, 0, 0, 0, 0x780000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -308, -4651, 0, 0, 0, 0, 0x6e0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -3875, -4651, 874, 0, 0, 0, 0x6e0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(122, -9, -3339, -5, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 3191, 636, 3186, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 2873, -3095, -4880, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -8467, -1624, -4145, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(192, 3867, -3525, 1626, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 3743, -3500, -1622, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 3968, -3500, -2999, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(122, 3961, -1995, -4496, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(140, 1889, -2250, 3913, 0, 0, 0, 0x0,  bhvBlueCoinSwitch, 31),
	OBJECT_WITH_ACTS(118, 1001, -2250, 3754, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, 156, -2250, 3916, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -647, -2250, 3584, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -1388, -2250, 4071, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(0, 2545, -3500, 2, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2600, -3500, 2, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -4, -3500, 2599, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -10, -3500, -2573, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3859, -3500, -3876, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3730, -2061, -3756, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3872, -2250, -729, 0, 0, 0, 0x40000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3385, -750, -2239, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(192, -38, -3500, -1404, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 1322, -3500, 50, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 41, -3500, 1311, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -1359, -3500, 1, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(0, -1094, -1902, -3717, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3895, -3500, 819, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3189, 706, -4206, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1365, -3500, -3877, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2971, -1426, -1797, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2971, -2485, -1797, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1235, -2485, 2996, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3870, -3500, 3122, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -4323, -125, 2605, 0, 135, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2368, -250, 3155, 0, 15, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3874, -125, 4628, 0, 255, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(124, -3794, -2250, 817, 0, 90, 0, 0x3d0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, -1625, -2250, -4673, 0, 180, 0, 0x950000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 60, 4, 42, 0, 0, 20, 1,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_jrb_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(240, 16, 1, 32, 0),
	WARP_NODE(241, 16, 1, 31, 0),
	RETURN()
};