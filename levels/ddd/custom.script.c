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

#include "levels/ddd/header.h"
#include "levels/bbh/header.h"

extern u8 _ddd_segment_ESegmentRomStart[];
extern u8 _ddd_segment_ESegmentRomEnd[];

const LevelScript level_ddd_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _ddd_segment_ESegmentRomStart, _ddd_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom22727296_skybox_mio0SegmentRomStart, _SkyboxCustom22727296_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(6, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd),
	LOAD_RAW(13, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd),
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
	JUMP_LINK(script_func_global_15),
	JUMP_LINK(local_area_ddd_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_ddd_1_[] = {
	AREA(1, Geo_ddd_1_0x15d29a0),
	TERRAIN(col_ddd_1_0xe072cd0),
	SET_BACKGROUND_MUSIC(0, 10),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ddd_1_),
	JUMP_LINK(local_warps_ddd_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ddd_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(207, 834, -145, -2730, 0, 0, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 834, -145, -3500, 0, 0, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 1357, -145, -4427, 0, -30, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 1774, -145, -5120, 0, -30, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 2704, -145, -5602, 0, -60, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 3460, -145, -5999, 0, -60, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 5443, -145, -4809, 0, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 5436, -145, -3783, 0, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 5435, -145, -3058, 0, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 5989, -145, -3484, 0, -45, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 6676, -145, -4161, 0, -45, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 7239, -145, -4688, 0, -45, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 7365, -145, -3950, 0, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 7361, -145, -2986, 0, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 8143, -145, -928, 0, -9090, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(122, 8561, 1400, -1874, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -1264, 1660, -6411, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -11011, 387, -6918, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(129, -1582, 0, 6515, 0, 0, 0, 0x0,  bhvJumpingBox, 31),
	OBJECT_WITH_ACTS(207, -5040, -145, 11622, 0, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, -5040, -145, 10683, 0, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, -5040, -145, 12510, 0, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, -3333, -145, 18029, 0, -90, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(122, 1785, 1501, 18052, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(100, -19, -2125, 3380, 0, 0, 0, 0x10000,  bhvFirePiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 1217, -2125, 5414, 0, 0, 0, 0x10000,  bhvFirePiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 1206, -2125, 497, 0, 0, 0, 0x10000,  bhvFirePiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 4499, -2125, 3398, 0, 0, 0, 0x10000,  bhvFirePiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 3046, -2125, -1133, 0, 0, 0, 0x10000,  bhvFirePiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 420, -2125, 3361, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 4004, -2125, -1124, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 6724, -125, 6817, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 8169, -125, 6822, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 8349, -125, 7294, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 8166, -125, 7813, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 7938, -125, 8326, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 8770, -125, 8760, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 9511, -125, 8763, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(122, 12475, 3458, 7669, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(124, 1221, 0, -1786, 0, 0, 0, 0x2a0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -1384, 1070, 1957, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2845, 1070, 6943, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 5629, 1070, 3673, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1679, 1511, -599, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -5342, 1168, 1351, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -162, 1621, 4196, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1202, 2242, 4952, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2127, 2362, 2336, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2777, 1621, 3417, 0, 90, 0, 0x130000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 727, 2813, 2031, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 839, -64, -3493, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3356, 857, 4086, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -918, 815, 4435, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1678, 724, -579, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(124, 2611, 3686, 3922, 0, 180, 0, 0x940000,  bhvMessagePanel, 31),
	RETURN()
};

const LevelScript local_warps_ddd_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(240, 16, 1, 92, 0),
	WARP_NODE(241, 16, 1, 91, 0),
	RETURN()
};