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

#include "levels/hmc/header.h"
extern u8 _hmc_segment_ESegmentRomStart[];
extern u8 _hmc_segment_ESegmentRomEnd[];

const LevelScript level_hmc_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_RAW(0x0E, _hmc_segment_ESegmentRomStart, _hmc_segment_ESegmentRomEnd),
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
	JUMP_LINK(local_area_hmc_1_),
	JUMP_LINK(local_area_hmc_2_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_hmc_1_[] = {
	AREA(1, Geo_hmc_1_0x1454e30),
	TERRAIN(col_hmc_1_0xe03d000),
	SET_BACKGROUND_MUSIC(0, 6),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_hmc_1_),
	JUMP_LINK(local_warps_hmc_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_hmc_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 2650, 0, 0, 90, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(223, 1493, 2625, 20, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, 3754, 3550, 449, 0, 180, 0, 0x0,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, 4242, 3375, -317, 0, 0, 0, 0x40000,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, 4249, 3500, -694, 0, 0, 0, 0x40000,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(255, 4250, 3000, -1562, 0, 0, 0, 0x10000,  Bhv_Custom_0x130056bc, 31),
	OBJECT_WITH_ACTS(0, 7200, 3700, -938, 0, -90, 0, 0x0,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, 6252, 3950, 3, 0, 180, 0, 0x0,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(180, 6747, 3900, -448, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 5609, 4150, -443, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(122, 4862, 4500, 68, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(137, 1498, 4176, -2442, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(207, 996, 2750, -4759, 0, 0, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(129, 920, 3125, -5892, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 1120, 3125, -5892, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 920, 3125, -6092, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 1120, 3125, -6092, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 920, 3125, -6974, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 1120, 3125, -6974, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 920, 3125, -7174, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 1120, 3125, -7174, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(122, 1003, 3900, -8370, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(223, -2251, 1875, 13, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(122, -890, 3137, -623, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(129, -893, 6213, 94, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -1093, 6213, 94, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -893, 6213, -106, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -1093, 6213, -106, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(207, -1732, 5938, -2881, 0, 0, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(254, -2200, 6328, -2875, 0, 0, 0, 0xf0000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, 0, 6833, 0, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 7121, 5562, 3821, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, 740, 3541, 2401, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -4131, 6688, -1101, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -5275, 6688, -1114, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -4617, 5938, 10, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -4878, 4688, 2819, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2997, 6063, 11, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2069, 4125, 773, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, 4843, 5473, 68, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 4217, 3250, -2229, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -5009, 6179, -2883, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -6243, 5438, -1627, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1817, 4625, -611, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2887, 4625, -92, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 5498, 3000, -1567, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2114, 3623, 1877, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2103, 3867, 3383, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(124, -862, 4625, -613, 0, -90, 0, 0x130000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, -2707, 3688, 3943, 0, -90, 0, 0x200000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 1763, 3125, 785, 0, 180, 0, 0x230000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 1159, 3125, -175, 0, -90, 0, 0x120000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, -2205, 5938, -2720, 0, 180, 0, 0x240000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 734, 3541, 3014, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 743, 3541, 1748, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(22, 752, 5375, 1561, 0, 0, 0, 0x10000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(124, 749, 7813, 3936, 0, 0, 0, 0x8b0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -30, 4, 5, 0, 0, 20, 0,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_hmc_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(1, 7, 2, 1, 0),
	WARP_NODE(240, 16, 1, 62, 0),
	WARP_NODE(241, 16, 1, 61, 0),
	RETURN()
};

const LevelScript local_area_hmc_2_[] = {
	AREA(2, Geo_hmc_2_0x1454d10),
	TERRAIN(col_hmc_2_0xe010080),
	SET_BACKGROUND_MUSIC(0, 6),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_hmc_2_),
	JUMP_LINK(local_warps_hmc_2_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_hmc_2_[] = {
	OBJECT_WITH_ACTS(0, 1627, 3188, -2, 0, -90, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(253, 1622, 3520, 11, 0, 0, 0, 0x30000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(22, 2091, 3188, -12, 0, -90, 0, 0x10000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(122, 6903, 4510, -6530, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(124, 1518, 3188, -340, 0, 90, 0, 0x3f0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, -4545, 2500, 5877, 0, 90, 0, 0x420000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 2990, 4000, -7779, 0, 0, 0, 0x410000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -4530, 2736, 5890, 0, 0, 0, 0x20000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, 2989, 4279, -7771, 0, 0, 0, 0x20000,  bhvFadingWarp, 31),
	RETURN()
};

const LevelScript local_warps_hmc_2_[] = {
	WARP_NODE(10, 9, 2, 0, 0),
	WARP_NODE(1, 7, 1, 1, 0),
	WARP_NODE(2, 7, 2, 1, 0),
	WARP_NODE(240, 16, 1, 62, 0),
	WARP_NODE(241, 16, 1, 61, 0),
	RETURN()
};