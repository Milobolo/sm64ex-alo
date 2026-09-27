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

#include "levels/sl/header.h"
#include "levels/bbh/header.h"

extern u8 _sl_segment_ESegmentRomStart[];
extern u8 _sl_segment_ESegmentRomEnd[];

const LevelScript level_sl_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _sl_segment_ESegmentRomStart, _sl_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd),
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
	JUMP_LINK(local_area_sl_1_),
	JUMP_LINK(local_area_sl_2_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_sl_1_[] = {
	AREA(1, Geo_sl_1_0x1611b80),
	TERRAIN(col_sl_1_0xe0201f0),
	SET_BACKGROUND_MUSIC(0, 39),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_sl_1_),
	JUMP_LINK(local_warps_sl_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_sl_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(122, -5, 5259, -1388, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(130, 3029, 3063, 2791, 0, 0, 0, 0x0,  bhvBreakableBoxSmall, 31),
	OBJECT_WITH_ACTS(122, 3015, 5104, 3550, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 3, 391, 3104, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 2700, -639, -448, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(22, 2925, 0, -430, 0, 0, 0, 0x10000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(124, 2637, 1500, 2667, 0, 180, 0, 0x2b0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, -603, 1500, -1460, 0, 0, 0, 0x930000,  bhvMessagePanel, 31),
	RETURN()
};

const LevelScript local_warps_sl_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(1, 10, 2, 1, 0),
	WARP_NODE(240, 16, 1, 102, 0),
	WARP_NODE(241, 16, 1, 101, 0),
	RETURN()
};

const LevelScript local_area_sl_2_[] = {
	AREA(2, Geo_sl_2_0x1611a60),
	TERRAIN(col_sl_2_0xe00f7c0),
	SET_BACKGROUND_MUSIC(0, 39),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_sl_2_),
	JUMP_LINK(local_warps_sl_2_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_sl_2_[] = {
	OBJECT_WITH_ACTS(0, -55, 750, -528, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 1412, 4300, 1437, 0, 0, 0, 0x4000000,  bhvHiddenStar, 31),
	OBJECT_WITH_ACTS(121, -1215, 4339, 1442, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(22, -5, 750, -12, 0, 0, 0, 0x10000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(137, -898, 4771, -830, 0, 0, 0, 0xe0000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(207, 0, -151, 3183, -11, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 0, -347, 4162, -11, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 0, -821, 6522, -11, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 0, -1038, 7612, -11, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 0, -1807, 11436, -11, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(207, 0, -2010, 12481, -11, 180, 0, 0x0,  bhvFloorSwitchAnimatesObject, 31),
	OBJECT_WITH_ACTS(122, -1, -2299, 14717, 0, 0, 0, 0x5000000,  bhvStar, 31),
	RETURN()
};

const LevelScript local_warps_sl_2_[] = {
	WARP_NODE(10, 9, 2, 0, 0),
	WARP_NODE(1, 10, 1, 1, 0),
	WARP_NODE(240, 16, 1, 102, 0),
	WARP_NODE(241, 16, 1, 101, 0),
	RETURN()
};