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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _water_mio0SegmentRomStart, _water_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _bitfs_skybox_mio0SegmentRomStart, _bitfs_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group2_mio0SegmentRomStart, _group2_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 0x01, 0x1D, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 0x01, 0x2D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_TOTWC, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_JRB, 0x01, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_JRB, 0x01, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1C, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x2C, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BALANCE_CENTER, -801, -4294, -11326, 0, 27, 0, 0, bhvBalancer),
		OBJECT(MODEL_BALANCE_CENTER, -12469, -4986, 4727, 0, 0, 0, 0, bhvBalancer),
		OBJECT(MODEL_BULLY_BOSS, -12460, -4965, 7093, 0, -180, 0, (2 << 24), bhvBigBullyWithMinions),
		OBJECT(MODEL_BULLY, -11854, -5279, 7705, 0, -180, 0, 0, bhvBigBullyMinion),
		OBJECT(MODEL_BULLY, -11854, -5279, 6485, 0, -180, 0, 0, bhvBigBullyMinion),
		OBJECT(MODEL_BULLY, -13071, -5279, 6485, 0, -180, 0, 0, bhvBigBullyMinion),
		OBJECT(MODEL_BULLY, -13071, -5279, 7707, 0, -180, 0, 0, bhvBigBullyMinion),
		OBJECT(MODEL_BULLY, -1394, -5821, -4265, 0, -180, 0, 0, bhvSmallBully),
		OBJECT(MODEL_BULLY, -777, -5821, -1289, 0, -180, 0, 0, bhvSmallBully),
		OBJECT(MODEL_BULLY, -5528, -5821, -4114, 0, -180, 0, 0, bhvSmallBully),
		OBJECT(MODEL_SKEETER, -5471, -5821, -383, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -5444, -5947, 4637, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -3188, -5947, 4764, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -3107, -6366, 7283, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -5925, -6366, 9195, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -3270, -6366, 10617, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -2256, -5814, -901, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -3468, -5820, -4792, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -7774, -5820, -4778, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -11707, -5820, -7180, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -9388, -5818, -10840, 0, -180, 0, 0, bhvSkeeter),
		OBJECT(MODEL_NONE, -11778, -5818, -11364, 0, -180, 0, 0, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -10406, -5820, -7725, 0, -180, 0, 0, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -13381, -5821, -8864, 0, -180, 0, 0, bhvGoombaTripletSpawner),
		OBJECT(MODEL_STAR, 2813, -1868, 940, 0, -180, 0, (5 << 24), bhvStar),
		OBJECT(MODEL_NONE, -284, -4752, -8751, 0, -90, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1077, -5421, -6519, 0, -90, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1985, -5466, -11494, 0, -90, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10295, -4520, 7845, 0, 0, 0, (0x0D << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -9982, -5335, -99, 0, 0, 0, (0x0E << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 17189, 2258, -2309, 0, -90, 0, 0x00100000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1918, -4668, -6561, 0, 90, 0, 0x00100000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10288, -3506, 3445, 0, 180, 0, 0x00100000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10288, -3658, 5136, 0, 180, 0, 0x00100000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -12441, -4307, 5839, 0, 180, 0, 0x00100000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -991, -5696, 9803, 0, -90, 0, (0x1C << 16) | (0), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, -6507, -5821, -4295, 0, 90, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7494, -5567, 116, 0, -90, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_NONE, 82, -5728, 1141, 0, 8, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4375, -6193, 5215, 0, -1, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_NONE, -11282, -5454, 3933, 0, -90, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_HANG_SWAP, -10292, -3583, 4866, 0, 0, 0, 0, bhvHangswap),
		OBJECT(MODEL_HANG_SWAP, -10292, -3097, 5614, 0, 0, 0, 0, bhvHangswap),
		OBJECT(MODEL_PURPLE_SWITCH, -10292, -3573, 5499, 0, 0, 0, 0, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_HANG_SWAP, -1299, -5427, -10400, 0, -61, 0, 0, bhvHangswap),
		OBJECT(MODEL_HANG_SWAP, 580, -5427, -7350, 0, 119, 0, 0, bhvHangswap),
		OBJECT(MODEL_PURPLE_SWITCH, 1316, -3890, 1053, 0, -180, 0, 0, bhvFloorSwitchHeavy),
		OBJECT(MODEL_PURPLE_SWITCH, -12124, -5821, -10287, 0, -180, 0, (1), bhvFloorSwitchHeavy),
		OBJECT(MODEL_NONE, -10299, -3263, 6629, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -10299, -3263, 6829, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -10299, -3263, 7029, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, 2023, -3448, 775, 0, -180, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_NONE, 2398, -2860, 229, 0, -180, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_NONE, 2822, -2337, 943, 0, -180, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_NONE, -11738, -3339, -8712, 0, -180, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -11438, -3339, -8712, 0, -180, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -10299, -3263, 7844, 0, -180, 0, 0, bhvHiddenObject),
		OBJECT(MODEL_NONE, -11738, -3339, -9012, 0, -180, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -11438, -3339, -9012, 0, -180, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -12147, -4509, -7977, 0, -180, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -11847, -4209, -7977, 0, -180, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -11547, -3909, -7977, 0, -180, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, -289, -5865, -8748, 0, -180, 0, (3 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, 1618, 60, -8856, 0, 140, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_RED_COIN, -3579, -4518, -11261, 0, -180, 0, (3 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -976, -5540, -9847, 0, -180, 0, (3 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -290, -4649, -8752, 0, -180, 0, (3 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1146, -4564, -11948, 0, -180, 0, (3 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 897, -3945, -7559, 0, -1, 0, (3 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 897, -4478, -7559, 0, -1, 0, (3 << 24), bhvRedCoin),
		OBJECT(MODEL_NONE, -4376, -5447, 4267, 0, -180, 0, 0x000A0000, bhvAirborneWarp),
		OBJECT(MODEL_METAL_BOX, -13507, -5821, -10287, 0, -180, 0, 0, bhvPushableMetalBox),
		OBJECT(MODEL_RED_COIN, -692, -3780, -11117, 0, -180, 0, (3 << 24), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3580, -5928, -11268, 0, -180, 0, (3 << 24), bhvRedCoin),
		OBJECT(MODEL_STAR, -11129, -2244, -8849, 0, -180, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_WOODEN_SIGNPOST, -789, -5874, 9803, 0, -90, 0, (0 << 16) | (5), bhvMessagePanel),
		OBJECT(MODEL_NONE, -991, -5696, 9803, 0, -90, 0, (0x2C << 16) | (0), bhvAirborneDeathWarp),
		OBJECT(MODEL_STAR, -10296, -2928, 7842, 0, -180, 0, (0 << 24), bhvStar),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, -963, -4498, 1385, 0, -180, 0, 0, bhvBreakableBoxSmall),
		OBJECT(MODEL_ROT_SMALL, 498, -5021, 3255, 0, -180, 0, 0, bhvRotatingBig),
		OBJECT(MODEL_ROT_SMALL, -12122, -4506, -8898, 0, -180, 0, 0, bhvRotatingBig),
		OBJECT(MODEL_ROT_SMALL, -11587, -3596, -8858, 0, -180, 0, 0, bhvRotatingBig),
		OBJECT(MODEL_ROT_SMALL, 1076, -5421, -6530, 0, -180, 0, 0, bhvRotatingBig),
		OBJECT(MODEL_ROT_SMALL, -1972, -5466, -11487, 0, -180, 0, 0, bhvRotatingBig),
		OBJECT(MODEL_ROT_SMALL, -289, -4752, -8749, 0, -180, 0, 0, bhvRotatingBig),
		OBJECT(MODEL_ROT_SMALL, 526, -4299, 1912, 0, -180, 0, 0, bhvRotatingSmall),
		OBJECT(MODEL_SQUARE_FLAT, 2520, -4284, -7356, 0, 0, 0, (20 << 16) | (0xc << 8) | (0x41), bhvSquareVert),
		OBJECT(MODEL_SQUARE_FLAT, 1807, -4778, -6571, 0, 90, 0, (20 << 16) | (2 << 8) | (0x8A), bhvSquareForward),
		OBJECT(MODEL_NONE, 16571, 1376, -7954, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -3578, -5610, -11262, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10982, -5624, 192, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -236, -5900, 9805, 0, 90, 0, (0x0C << 16), bhvWarpPipe),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x27),
		TERRAIN_TYPE(TERRAIN_GRASS),
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
