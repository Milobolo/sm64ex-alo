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

#include "levels/bbh/header.h"
extern u8 _bbh_segment_ESegmentRomStart[];
extern u8 _bbh_segment_ESegmentRomEnd[];

const LevelScript level_bbh_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _bbh_segment_ESegmentRomStart, _bbh_segment_ESegmentRomEnd),
	LOAD_MIO0(        /*seg*/ 0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
	LOAD_MIO0(0xA, _ccm_skybox_mio0SegmentRomStart, _ccm_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group7_mio0SegmentRomStart, _group7_mio0SegmentRomEnd),
	LOAD_RAW(12, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd),
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
	JUMP_LINK(script_func_global_8),
	JUMP_LINK(local_area_bbh_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_bbh_1_[] = {
	AREA(1, Geo_bbh_1_0x13f2bf0),
	TERRAIN(col_bbh_1_0xe029c00),
	SET_BACKGROUND_MUSIC(0, 8),
	TERRAIN_TYPE(2),
	JUMP_LINK(local_objects_bbh_1_),
	JUMP_LINK(local_warps_bbh_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_bbh_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(122, 3612, 3480, 2270, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -4758, 3360, 2027, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(129, 561, 0, 2228, 0, 0, 0, 0x0,  bhvJumpingBox, 31),
	OBJECT_WITH_ACTS(129, -1355, 2172, 4291, 0, 60, 0, 0x0,  bhvJumpingBox, 31),
	OBJECT_WITH_ACTS(122, -1784, 3687, 2030, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -1841, 147, 3696, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -8555, 2263, 2786, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 6072, 2140, -2928, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(140, -4014, 0, 1244, 0, 1, 0, 0x0,  bhvBlueCoinSwitch, 31),
	OBJECT_WITH_ACTS(118, -4011, 540, 1262, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -4434, 898, 1628, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -3550, 881, 895, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(0, 2248, 250, 1256, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3342, 250, -1817, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -520, 1500, -3007, 0, 229, 0, 0x40000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1678, 2030, -4029, 0, 127, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -534, 1672, 6311, 0, 59, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2099, 2037, -22, 0, 52, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2019, -50, 36, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -134, 750, -1140, 0, 52, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1904, 839, 4121, 0, 52, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, -106, 500, -4194, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 2360, 0, -1245, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(85, -1962, 0, -2876, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, 1959, 0, -1891, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, -1792, 0, 1650, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(124, -4948, 0, -357, 0, 90, 0, 0x100000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 2899, 0, -1664, 0, -90, 0, 0x0,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 1405, 1500, -3103, 0, 180, 0, 0x2e0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 222, 0, 2514, 0, 180, 0, 0x340000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, -5368, 0, 3105, 0, 90, 0, 0x400000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 3454, 3000, -2758, 0, -90, 0, 0x7f0000,  bhvMessagePanel, 31),
	RETURN()
};

const LevelScript local_warps_bbh_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(240, 16, 1, 52, 0),
	WARP_NODE(241, 16, 1, 51, 0),
	RETURN()
};