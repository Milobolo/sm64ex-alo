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

#include "levels/lll/header.h"
#include "levels/bbh/header.h"

extern u8 _lll_segment_ESegmentRomStart[];
extern u8 _lll_segment_ESegmentRomEnd[];

const LevelScript level_lll_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _lll_segment_ESegmentRomStart, _lll_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom21632896_skybox_mio0SegmentRomStart, _SkyboxCustom21632896_skybox_mio0SegmentRomEnd),
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
	JUMP_LINK(local_area_lll_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_lll_1_[] = {
	AREA(1, Geo_lll_1_0x14c76a0),
	TERRAIN(col_lll_1_0xe03f8c0),
	SET_BACKGROUND_MUSIC(0, 5),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_lll_1_),
	JUMP_LINK(local_warps_lll_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_lll_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 150, 0, 0, -135, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(122, -3675, 623, 5369, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -4337, 1523, 3023, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(192, 2024, -25, 2472, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 3189, -25, 3635, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 2770, -25, 4096, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 2091, -25, 4578, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 2216, -25, 5095, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 1395, 225, 6750, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 686, -25, 6750, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -985, -25, 6750, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(122, -1655, 508, 6742, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(140, -3992, -225, -1578, 0, 0, 0, 0x0,  bhvBlueCoinSwitch, 31),
	OBJECT_WITH_ACTS(122, -1826, 1523, -5724, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 7453, 452, 4366, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(140, 3215, 675, -3010, 0, 0, 0, 0x0,  bhvBlueCoinSwitch, 31),
	OBJECT_WITH_ACTS(118, -3987, -150, -280, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -3987, -50, -280, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -3987, 50, -280, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -5114, -150, -934, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -5114, -50, -934, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -5114, 50, -934, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -5114, -150, -2231, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -5111, -50, -2233, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -5111, 50, -2233, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, 3856, 350, -4104, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, 3856, 450, -4104, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, 3856, 550, -4104, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, 4491, 350, -3007, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, 4491, 450, -3007, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, 4491, 550, -3007, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, 2590, 350, -4105, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, 2590, 450, -4105, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, 2590, 550, -4105, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(194, 5823, 1238, -2522, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, 5997, 493, -1205, 0, 0, 0, 0x5000000,  bhvHiddenStar, 31),
	OBJECT_WITH_ACTS(194, 6021, 143, -220, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(194, 8134, 61, -1203, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(194, 6959, 1065, -2514, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(194, 4977, 1181, -1005, 0, -45, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, -3991, -220, -2869, 0, 0, 0, 0x10000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, -11, 533, 11, 0, -135, 0, 0x20000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, 4403, 30, -5050, 0, 0, 0, 0x10000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, -746, 1162, -978, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3994, -180, -2867, 0, 900, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 4409, 88, -5053, 0, 900, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -5070, 0, 272, 0, 0, 0, 0xc0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -5686, 0, 1031, 0, 0, 0, 0xc0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -6627, 0, 710, 0, 0, 0, 0xc0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(124, -7630, 25, 1017, 0, 90, 0, 0x8c0000,  bhvMessagePanel, 31),
	RETURN()
};

const LevelScript local_warps_lll_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(1, 22, 1, 2, 0),
	WARP_NODE(2, 22, 1, 2, 0),
	WARP_NODE(240, 16, 1, 72, 0),
	WARP_NODE(241, 16, 1, 71, 0),
	RETURN()
};