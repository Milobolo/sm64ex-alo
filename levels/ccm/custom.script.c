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

#include "levels/ccm/header.h"
extern u8 _ccm_segment_ESegmentRomStart[];
extern u8 _ccm_segment_ESegmentRomEnd[];

const LevelScript level_ccm_custom_entry[] = {
	INIT_LEVEL(),
	LOAD_RAW(0x0E, _ccm_segment_ESegmentRomStart, _ccm_segment_ESegmentRomEnd),
	// LOAD_MIO0(0xA, _SkyboxCustom20528736_skybox_mio0SegmentRomStart, _SkyboxCustom20528736_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group6_mio0SegmentRomStart, _group6_mio0SegmentRomEnd),
	LOAD_RAW(12, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd),
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
	// LOAD_MODEL_FROM_DL(84, 0x05000840, 4),
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
	JUMP_LINK(script_func_global_7),
	JUMP_LINK(local_area_ccm_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_ccm_1_[] = {
	AREA(1, Geo_ccm_1_0x13b9d90),
	TERRAIN(col_ccm_1_0xe028470),
	SET_BACKGROUND_MUSIC(0, 35),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ccm_1_),
	JUMP_LINK(local_warps_ccm_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ccm_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 5250, 0, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(122, -1545, 9587, 2311, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 5202, 8562, -1844, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 5129, 8454, 4393, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -52, 6962, -9531, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(129, -5818, 6152, -528, 0, 0, 0, 0x0,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, -5818, 6152, -728, 0, 0, 0, 0x0,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, -5818, 6352, -528, 0, 0, 0, 0x0,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, -5818, 6352, -728, 0, 0, 0, 0x0,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(0, -3209, 5250, -638, 0, -90, 0, 0x40000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(122, -8646, 11683, -4458, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, -4481, 6370, -4541, 0, 0, 0, 0xd20000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -3457, 5359, -5134, 0, 0, 0, 0xff0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -3456, 8877, -3951, 0, 0, 0, 0x960000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(122, -3455, 10831, -3962, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, 0, 5149, 0, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1897, 4750, -1615, 0, 120, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2540, 4750, -2797, 0, 120, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, -206, 6159, -4610, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, -215, 7602, -4587, 0, 30, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -148, 7750, -5981, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2128, 5625, -4, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3509, 5625, -15, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2806, 5892, -8, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2693, 6585, -3256, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2696, 6250, -1903, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3140, 7126, 597, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2696, 7750, -1903, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2691, 7750, -3275, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -240, 5750, -3246, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1547, 6125, 2311, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 0, 5214, 0, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, -3455, 5410, -3944, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(124, -532, 5000, 896, 0, 150, 0, 0x80000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, -851, 4250, 855, 0, 60, 0, 0xf0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(180, -796, 6769, -3590, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(130, -2217, 4750, -2215, 0, 0, 0, 0x0,  bhvBreakableBoxSmall, 31),
	OBJECT_WITH_ACTS(254, -4289, 6550, -629, 0, 0, 0, 0xf0000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, -4269, 4888, -626, 0, -89, 0, 0x0,  bhvCloud, 31),
	OBJECT_WITH_ACTS(0, -6153, 4783, -627, 0, 90, 0, 0x10000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, -6153, 5188, -627, 0, -90, 0, 0x20000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(124, -4285, 6250, -214, 0, 180, 0, 0x7a0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, -1015, 5150, 1657, 0, 45, 0, 0xa90000,  bhvMessagePanel, 31),
	RETURN()
};

const LevelScript local_warps_ccm_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(2, 5, 1, 1, 0),
	WARP_NODE(1, 5, 1, 2, 0),
	WARP_NODE(240, 16, 1, 42, 0),
	WARP_NODE(241, 16, 1, 41, 0),
	RETURN()
};