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

#include "levels/ssl/header.h"
#include "levels/bbh/header.h"

extern u8 _ssl_segment_ESegmentRomStart[];
extern u8 _ssl_segment_ESegmentRomEnd[];

const LevelScript level_ssl_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _ssl_segment_ESegmentRomStart, _ssl_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom22025568_skybox_mio0SegmentRomStart, _SkyboxCustom22025568_skybox_mio0SegmentRomEnd),
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
	JUMP_LINK(local_area_ssl_1_),
	JUMP_LINK(local_area_ssl_2_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_ssl_1_[] = {
	AREA(1, Geo_ssl_1_0x1527480),
	TERRAIN(col_ssl_1_0xe026820),
	SET_BACKGROUND_MUSIC(0, 36),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ssl_1_),
	JUMP_LINK(local_warps_ssl_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ssl_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 110, 0, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(122, -1044, 5333, -4, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 933, 4942, -4036, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(223, -2186, -2000, 1152, 0, 180, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(207, -1588, -2000, 1185, 0, 0, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(129, -1700, -6200, 1350, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -1700, -6200, 1175, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -1700, -6200, 1000, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(122, -1704, -5640, 1715, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 5263, 2642, 2838, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -3752, 5649, -3086, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -1897, 1500, 4507, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(124, 715, -40, -374, 0, -90, 0, 0x270000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 870, 750, 381, 0, -90, 0, 0x280000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(22, -1413, -812, -2523, 0, 0, 0, 0x0,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(124, 3774, 938, 4299, 0, 0, 0, 0x350000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 719, 3746, -1475, 0, 90, 0, 0x3c0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, -1583, -5425, 1527, 0, 0, 0, 0xa00000,  bhvMessagePanel, 31),
	RETURN()
};

const LevelScript local_warps_ssl_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(0, 8, 2, 10, 0),
	WARP_NODE(240, 16, 1, 82, 0),
	WARP_NODE(241, 16, 1, 81, 0),
	RETURN()
};

const LevelScript local_area_ssl_2_[] = {
	AREA(2, Geo_ssl_2_0x1527370),
	TERRAIN(col_ssl_2_0xe0086c0),
	SET_BACKGROUND_MUSIC(0, 36),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ssl_2_),
	JUMP_LINK(local_warps_ssl_2_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ssl_2_[] = {
	OBJECT_WITH_ACTS(0, 0, 549, 0, 0, -180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(137, 0, 7809, -3232, 0, 0, 0, 0xe0000,  bhvExclamationBox, 31),
	RETURN()
};

const LevelScript local_warps_ssl_2_[] = {
	WARP_NODE(10, 9, 2, 0, 0),
	WARP_NODE(240, 16, 1, 82, 0),
	WARP_NODE(241, 16, 1, 81, 0),
	RETURN()
};