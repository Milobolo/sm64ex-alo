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

#include "levels/cotmc/header.h"
#include "levels/bbh/header.h"

extern u8 _cotmc_segment_ESegmentRomStart[];
extern u8 _cotmc_segment_ESegmentRomEnd[];

const LevelScript level_cotmc_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _cotmc_segment_ESegmentRomStart, _cotmc_segment_ESegmentRomEnd),
	// LOAD_MIO0(0xA, _SkyboxCustom24304432_skybox_mio0SegmentRomStart, _SkyboxCustom24304432_skybox_mio0SegmentRomEnd),
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
	JUMP_LINK(local_area_cotmc_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_cotmc_1_[] = {
	AREA(1, Geo_cotmc_1_0x1753a60),
	TERRAIN(col_cotmc_1_0xe0116d0),
	SET_BACKGROUND_MUSIC(0, 42),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_cotmc_1_),
	JUMP_LINK(local_warps_cotmc_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_cotmc_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 360, 0, 0, 90, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(120, 1962, 3080, -823, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(120, 3508, 3669, 2289, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(120, -2105, 2790, 307, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(120, -6269, 3355, 1604, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(122, -8416, 5897, -1621, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 10661, 5358, 432, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(137, 6099, 5181, 1314, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(144, 1212, 2239, 6004, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(144, 815, 2827, 6150, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(144, 337, 3690, 5829, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(120, 2487, 1531, 6002, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(144, -101, 4514, 6000, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(144, -3883, 6054, 6017, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(122, -4694, 6859, 6001, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 5166, 5118, -17066, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(137, 0, 581, 0, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(124, 3727, 3750, 2213, 0, 180, 0, 0x320000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 2802, 3750, -972, 0, 90, 0, 0x330000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 2939, 5048, 3400, 0, 180, 0, 0xa70000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 5, 5, 144, 0, 1, 5, 29,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 117, 0, 0, 20, 30,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_cotmc_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(240, 16, 1, 212, 0),
	WARP_NODE(241, 16, 1, 211, 0),
	RETURN()
};