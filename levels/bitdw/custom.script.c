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

#include "levels/bitdw/header.h"
#include "levels/bbh/header.h"

extern u8 _bitdw_segment_ESegmentRomStart[];
extern u8 _bitdw_segment_ESegmentRomEnd[];

const LevelScript level_bitdw_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _bitdw_segment_ESegmentRomStart, _bitdw_segment_ESegmentRomEnd),
	// LOAD_MIO0(0xA, _SkyboxCustom25069344_skybox_mio0SegmentRomStart, _SkyboxCustom25069344_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd),
	LOAD_RAW(12, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd),
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
	// LOAD_MODEL_FROM_DL(84, 0x05002e00, 4),
	// LOAD_MODEL_FROM_DL(86, 0x05003120, 4),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_9),
	JUMP_LINK(local_area_bitdw_1_),
	JUMP_LINK(local_area_bitdw_2_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_bitdw_1_[] = {
	AREA(1, Geo_bitdw_1_0x180e640),
	TERRAIN(col_bitdw_1_0xe027f30),
	SET_BACKGROUND_MUSIC(0, 43),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_bitdw_1_),
	JUMP_LINK(local_warps_bitdw_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_bitdw_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 120, 0, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 0, 4260, 0, 0, 0, 0, 0x14010000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(124, -52, -2056, -4186, 0, 210, 0, 0x700000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 60, 5, 132, 0, 0, 20, 5,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_bitdw_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(1, 31, 1, 10, 0),
	WARP_NODE(240, 16, 1, 232, 0),
	WARP_NODE(241, 16, 1, 231, 0),
	RETURN()
};

const LevelScript local_area_bitdw_2_[] = {
	AREA(2, Geo_bitdw_2_0x180e520),
	TERRAIN(col_bitdw_2_0xe027890),
	SET_BACKGROUND_MUSIC(0, 37),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_bitdw_2_),
	JUMP_LINK(local_warps_bitdw_2_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_bitdw_2_[] = {
	OBJECT_WITH_ACTS(0, -2528, -1211, -1583, 0, 45, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(85, -5563, 4063, 2808, 0, -4545, 0, 0x20000,  bhvCapSwitch, 31),
	OBJECT_WITH_ACTS(137, -2526, -761, -1581, 0, 0, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -2527, 1616, -3566, 0, 30, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -2641, 1277, 3039, 0, 0, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(201, -4543, -727, -582, 0, 90, 0, 0x7f0000,  bhvCannonClosed, 31),
	OBJECT_WITH_ACTS(195, -5397, 2824, 2689, 0, 45, 0, 0x0,  bhvBobombBuddyOpensCannon, 31),
	OBJECT_WITH_ACTS(137, -8502, 2526, -581, 0, 0, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -5556, 3060, 2855, 0, 45, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -7455, 4458, -4685, 0, -15, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, -2736, 5048, -17, 0, 0, 0, 0x14010000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(124, 111, -1562, -631, 0, 60, 0, 0x710000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -50, 4, 52, 0, 0, 20, 6,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -50, 4, 132, 0, 0, 20, 7,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_bitdw_2_[] = {
	WARP_NODE(10, 9, 2, 0, 0),
	WARP_NODE(1, 27, 1, 10, 0),
	WARP_NODE(240, 16, 1, 252, 0),
	WARP_NODE(241, 16, 1, 233, 0),
	RETURN()
};