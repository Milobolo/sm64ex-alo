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

#include "levels/wf/header.h"
extern u8 _wf_segment_ESegmentRomStart[];
extern u8 _wf_segment_ESegmentRomEnd[];

const LevelScript level_wf_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_RAW(0x0E, _wf_segment_ESegmentRomStart, _wf_segment_ESegmentRomEnd),
	// LOAD_MIO0(0xA, _SkyboxCustom19880160_skybox_mio0SegmentRomStart, _SkyboxCustom19880160_skybox_mio0SegmentRomEnd),
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
	JUMP_LINK(local_area_wf_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_wf_1_[] = {
	AREA(1, Geo_wf_1_0x131b810),
	TERRAIN(col_wf_1_0xe023610),
	SET_BACKGROUND_MUSIC(0, 4),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_wf_1_),
	JUMP_LINK(local_warps_wf_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_wf_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 200, 0, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(137, -429, 1930, 2275, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, -3204, 200, 90, 0, -90, 0, 0x10000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, -11314, 200, -6204, 0, -90, 0, 0x20000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(253, -14128, 1919, -6207, 0, 0, 0, 0x30000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, -351, 4445, 1954, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(180, 152, 4287, 6338, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -284, 4287, 4124, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, -15839, 443, -6252, 0, 0, 0, 0x5000000,  bhvHiddenStar, 31),
	OBJECT_WITH_ACTS(0, -13293, 424, -11830, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, -17468, 1181, -5122, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, -13577, 2185, -3822, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, -17951, 230, -10146, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, -14807, 542, -8535, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, -15076, 0, -8830, 0, 0, 0, 0x40000,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, -15128, 0, -8559, 0, 0, 0, 0x40000,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, -15078, 0, -8271, 0, 0, 0, 0x40000,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, -14518, -1, -8856, 0, 0, 0, 0x40000,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, -14463, 0, -8572, 0, 0, 0, 0x40000,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, -14520, 0, -8303, 0, 0, 0, 0x40000,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(122, -189, 3876, -6180, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, -180, 3550, -8932, 0, 0, 0, 0x40000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(122, 5293, 5670, -774, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(120, 3891, -822, -4084, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(122, 15198, 3829, -11607, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(140, -2049, 200, -2426, 0, 0, 0, 0x0,  bhvBlueCoinSwitch, 31),
	OBJECT_WITH_ACTS(118, -2996, 7, -1974, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -3356, 60, -1816, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -3366, 473, -1810, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -3242, 899, -1870, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -2885, 1029, -2071, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -993, 7, -2904, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -661, 61, -3016, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -625, 439, -3028, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -739, 841, -2971, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -975, 1038, -2865, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(0, -3220, 1875, 27, 0, 90, 0, 0x30000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, -12242, 225, 9837, 0, 0, 0, 0x40000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(120, 10157, -270, -10027, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(137, -10517, 1094, 11885, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, -14414, 5608, 11083, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, -1805, 1850, 51, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -55, 794, 2250, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 188, 2151, -3475, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1205, 2521, -563, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -314, 625, 1373, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1724, 200, -2342, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -10513, 1091, 10666, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -11869, 200, 11607, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -10514, 2250, 9154, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -255, 1648, -1224, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -196, 1950, -5955, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(124, 8029, 2200, -6682, 0, 135, 0, 0x9e0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 5, 5, 90, 0, 1, 5, 8,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 6, 0, 0, 20, 9,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 5, 5, 36, 0, 1, 5, 10,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 108, 0, 0, 20, 11,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 36, 0, 0, 20, 12,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 69, 0, 0, 20, 13,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 140, 0, 0, 20, 14,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 5, 5, 4, 0, 1, 5, 15,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 307, 0, 0, 20, 16,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 39, 0, 0, 20, 17,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 69, 0, 0, 20, 18,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 72, 0, 0, 20, 19,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 70, 0, 0, 20, 20,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 5, 5, 44, 0, 1, 5, 21,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 52, 0, 0, 20, 22,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 36, 0, 0, 20, 23,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 5, 5, 142, 0, 1, 5, 24,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 54, 0, 0, 20, 25,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 5, 5, 18, 0, 1, 5, 26,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 168, 0, 0, 20, 27,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 106, 0, 0, 20, 28,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_wf_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(1, 24, 1, 2, 0),
	WARP_NODE(2, 24, 1, 1, 0),
	WARP_NODE(3, 24, 1, 4, 0),
	WARP_NODE(4, 24, 1, 3, 0),
	WARP_NODE(240, 16, 1, 22, 0),
	WARP_NODE(241, 16, 1, 21, 0),
	RETURN()
};