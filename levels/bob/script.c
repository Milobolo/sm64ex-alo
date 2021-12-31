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

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _generic_mio0SegmentRomStart, _generic_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group5_mio0SegmentRomStart, _group5_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(2, bob_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 0x01, 0x1B, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 0x01, 0x2B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHUCKYA, -1258, 865, -201, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 1161, 865, 931, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_BOWLING_BALL, 168, 865, 943, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, 927, 1057, -1209, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, -1299, 888, -1271, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvFireSpitter),
		OBJECT(MODEL_NONE, -28, 975, 3961, 0, 0, 0, 0x00020000, bhvHiddenStar),
		OBJECT(MODEL_PURPLE_SWITCH, 3209, 659, 945, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (1), bhvFloorSwitchHeavy),
		OBJECT(MODEL_PURPLE_SWITCH, -4068, 787, -1183, 0, 0, 0, 0x00000000, bhvFloorSwitchHeavy),
		OBJECT(MODEL_NONE, 1548, 543, 1768, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1548, 543, 2396, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -2400, 520, -2203, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_NONE, -1297, 520, -2203, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), bhvHiddenObject),
		OBJECT(MODEL_METAL_BOX, -3504, 787, -1182, 0, 0, 0, 0x00000000, bhvPushableMetalBox),
		OBJECT(MODEL_TRIGGER, -1299, 888, -2209, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRIGGER, 1548, 888, 2396, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenStarTrigger),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, -1245, 831, 914, 0, 0, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 152, 966, -3385, 0, 0, 0, (0 << 24) | (10 << 16) | (0 << 8) | (0), bhvWarpPipe),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x24),
		TERRAIN_TYPE(TERRAIN_SAND),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 0x01, 0x1B, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 0x01, 0x2B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_COTMC, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1C, LEVEL_BOB, 0x01, 0x1C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x2C, LEVEL_BOB, 0x01, 0x2C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 565, 626, 3914, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvBlueCoinSwitch),
		OBJECT(MODEL_BLUE_COIN, 888, 624, 2900, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 29, 624, 2712, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 1, 624, 3333, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 575, 602, 2159, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvHiddenBlueCoin),
		OBJECT(MODEL_NONE, -5861, 1198, 1697, 0, -90, 0, (0 << 24) | (2 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2669, 1620, 6706, 0, 0, 0, (0 << 24) | (0x2C << 16) | (0 << 8) | (0), bhvAirborneDeathWarp),
		OBJECT(MODEL_BOWLING_BALL, 3224, 906, 1597, 0, 0, 0, 0, bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, 2087, 2205, -1921, 0, 0, 0, 0, bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, 11873, -459, 1282, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, 8440, 399, 4401, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvFireSpitter),
		OBJECT(MODEL_NONE, 3319, 2258, 4523, 0, -90, 0, (0 << 24) | (16 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 10664, 495, 5336, 0, -90, 0, (0 << 24) | (16 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2095, 1745, -9071, 0, 90, 0, (0 << 24) | (16 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_WOODEN_SIGNPOST, 2669, 1219, 6187, 0, -180, 0, (0 << 24) | (0 << 16) | (0 << 8) | (4), bhvMessagePanel),
		OBJECT(MODEL_NONE, 2097, 2011, -2162, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 515, 2108, -3691, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2650, 1106, 1566, 0, 90, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5900, 1643, 3612, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -7145, 972, -236, 0, -90, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_HEART, 9468, 1787, -4625, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvRecoveryHeart),
		OBJECT(MODEL_NONE, -258, 2274, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -258, 2474, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -258, 2674, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -258, 2874, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -258, 3074, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -258, 3274, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, 182, 2474, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, 182, 2674, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, 182, 2874, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, 182, 3074, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, 182, 3274, -5727, 0, 0, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, 9867, 48, 3454, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 10117, -152, 3457, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (1), bhvHiddenObject),
		OBJECT(MODEL_STAR, -36, 3433, 4222, 0, 0, 0, 0x00010000, bhvStar),
		OBJECT(MODEL_NONE, 8924, 1655, -5014, 0, 0, 0, 0, bhvPokey),
		OBJECT(MODEL_NONE, 6460, 1655, -4495, 0, 0, 0, 0, bhvPokey),
		OBJECT(MODEL_POKEY_HEAD, 417, 2074, -6764, 0, 0, 0, 0, bhvPokey),
		OBJECT(MODEL_POKEY_HEAD, 3574, 1217, 3454, 0, 0, 0, 0, bhvPokey),
		OBJECT(MODEL_POKEY_HEAD, 2149, 1217, 4354, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvPokey),
		OBJECT(MODEL_NONE, -1187, 2161, -129, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvPokey),
		OBJECT(MODEL_NONE, -2142, 2161, 851, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), bhvPokey),
		OBJECT(MODEL_PURPLE_SWITCH, 1208, 605, -4520, 0, 26, 0, (0 << 24) | (0), bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_PURPLE_SWITCH, 10130, -576, 299, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (1), bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_NONE, -3094, 2377, 210, 0, 0, 0, 0x00040000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, -7930, 2837, 3167, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -11142, 816, -239, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -8604, 1804, -4866, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -11012, 2340, 1338, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_METAL_BOX, 4163, 1853, -9793, 0, 0, 0, 0x00000000, bhvPushableMetalBox),
		OBJECT(MODEL_METAL_BOX, -11145, 816, -238, 0, 0, 0, 0x00000000, bhvPushableMetalBox),
		OBJECT(MODEL_RED_COIN, -12577, 1627, -202, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -7192, 2072, -1299, 0, 0, 180, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -6561, 3092, -2219, 0, 0, 180, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5438, 1974, -3504, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, -177, 4005, -6806, 0, 0, 0, 0x00030000, bhvStar),
		OBJECT(MODEL_SQUARE_FLAT, 3622, 2049, 4523, 0, -90, 0, 0x00100805, bhvSquareForward),
		OBJECT(MODEL_SQUARE_FLAT, 9178, -439, 273, 0, 0, 0, (0 << 24) | (16 << 16) | (4 << 8) | (133), bhvSquareVert),
		OBJECT(MODEL_SQUARE_FLAT, -4399, 886, -161, 0, 0, 0, (0 << 24) | (16 << 16) | (4 << 8) | (133), bhvSquareVert),
		OBJECT(MODEL_SQUARE_FLAT, -5428, 884, -1274, 0, 0, 0, (0 << 24) | (16 << 16) | (2 << 8) | (64), bhvSquareVert),
		OBJECT(MODEL_SQUARE_FLAT, 11303, 356, 5311, 0, -90, 0, (0 << 24) | (16 << 16) | (5 << 8) | (12), bhvSquareForward),
		OBJECT(MODEL_SQUARE_FLAT, 2807, 1568, -9064, 0, -90, 0, (0 << 24) | (16 << 16) | (3 << 8) | (232), bhvSquareForward),
		OBJECT(MODEL_STAR, 15404, 712, 5444, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 10232, 2305, -4646, 0, -90, 0, 0X000a0000, bhvAirborneWarp),
		OBJECT(MODEL_NONE, 2669, 1620, 6706, 0, 0, 0, (0 << 24) | (0x1C << 16) | (0 << 8) | (0), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 2701, 1376, -1123, 0, 90, 0, (0 << 24) | (17 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 328, 1910, -8228, 0, 90, 0, (0 << 24) | (17 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9162, 401, 274, 0, 90, 0, (0 << 24) | (17 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 11287, -482, 2323, 0, 90, 0, (0 << 24) | (17 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 4235, 1379, 4286, 0, 90, 0, (0 << 24) | (17 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4402, 1061, -173, 0, 90, 0, (0 << 24) | (17 << 16) | (0 << 8) | (0), bhvCoinFormation),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 4098, 1853, -11535, 0, 0, 0, 0x000B0000, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 2669, 1219, 7166, 0, -180, 0, (0 << 24) | (0xC << 16) | (0 << 8) | (0), bhvWarpPipe),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x24),
		TERRAIN_TYPE(TERRAIN_SAND),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
