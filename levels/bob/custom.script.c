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

#include "levels/bob/header.h"
#include "levels/bbh/header.h"

extern u8 _bob_segment_ESegmentRomStart[];
extern u8 _bob_segment_ESegmentRomEnd[];

const LevelScript level_bob_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _bob_segment_ESegmentRomStart, _bob_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom19537920_skybox_mio0SegmentRomStart, _SkyboxCustom19537920_skybox_mio0SegmentRomEnd),
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
	JUMP_LINK(local_area_bob_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_bob_1_[] = {
	AREA(1, Geo_bob_1_0x12c7f20),
	TERRAIN(col_bob_1_0xe047f20),
	SET_BACKGROUND_MUSIC(0, 3),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_bob_1_),
	JUMP_LINK(local_warps_bob_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_bob_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 5103, 0, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(122, -4501, 5140, 6, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 737, 11519, 6049, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 3370, 6554, -11380, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, 724, 7000, 2501, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(129, 6444, 4125, -5051, 0, 0, 0, 0x20000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(122, 8439, 6409, 1986, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, -44, 4047, -8291, 0, 0, 0, 0x4000000,  bhvHiddenStar, 31),
	OBJECT_WITH_ACTS(0, -119, 5645, -9631, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, -856, 2895, -9628, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, -1455, 2878, -8115, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, -153, 5628, -6622, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, 351, 2134, -7870, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(122, -1628, 6553, 6867, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, -1620, 6875, 6846, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -150, 5762, 2070, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3164, 6000, -1127, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -178, 5750, -4507, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3357, 6250, -4103, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 5991, 6191, -5109, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 6492, 4875, -4773, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(129, 6344, 4125, -4851, 0, 0, 0, 0x20000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, 6244, 4125, -5051, 0, 0, 0, 0x20000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, 6344, 4325, -4950, 0, 0, 0, 0x20000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(0, -1713, 3450, -8121, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3356, 6000, -6885, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 328, 4500, -4473, 0, 90, 0, 0x40000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 942, 5603, 3400, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1662, 6134, 5775, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 558, 6130, 6900, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -817, 3500, -6649, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(124, 716, 4531, 7, 0, -9090, 0, 0x310000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, -527, 5000, -4889, 0, -90, 0, 0x9f0000,  bhvMessagePanel, 31),
	RETURN()
};

const LevelScript local_warps_bob_1_[] = {
	WARP_NODE(10, 9, 1, 10, 0),
	WARP_NODE(240, 16, 1, 12, 0),
	WARP_NODE(241, 16, 1, 11, 0),
	RETURN()
};