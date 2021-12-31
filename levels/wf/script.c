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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _ccm_skybox_mio0SegmentRomStart, _ccm_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _grass_mio0SegmentRomStart, _grass_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group11_mio0SegmentRomStart, _group11_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 0x01, 0x1C, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 0x01, 0x2C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_VCUTM, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLUE_COIN, -417, 1461, -3709, 0, 90, 0, 0x00110000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 382, 1633, -3501, 0, 90, 0, 0x00110000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -319, 932, -4241, 0, 90, 0, 0x00110000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 385, 932, -3416, 0, 90, 0, 0x00110000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -449, 932, -3075, 0, 90, 0, 0x00110000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 2373, 1165, -3184, 0, 90, 0, 0x00110000, bhvBlueCoinSwitch),
		OBJECT(MODEL_CHUCKYA, -3228, 1388, -2865, 0, 0, 0, (0 << 16), bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -1527, 2075, -1496, 0, 0, 0, (0 << 16), bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 2600, 1165, -3460, 0, 0, 0, (0 << 16), bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 534, 2193, -10204, 0, 0, 0, (0 << 16), bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -3405, 2193, -8772, 0, 0, 0, (0 << 16), bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -5960, 2071, -5854, 0, 0, 0, (0 << 16), bhvChuckya),
		OBJECT(MODEL_NONE, -3663, 2194, -8473, 0, -90, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 3063, 2593, -9817, 0, -90, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_BOWLING_BALL, -416, 2233, 3755, 0, 0, 0, (0 << 16), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, -416, 2233, -114, 0, 0, 0, (0 << 16), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, -416, 1125, 1262, 0, 0, 0, (0 << 16), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, -416, 1125, 2415, 0, 0, 0, (0 << 16), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, -3258, 3076, -4408, 0, 0, 0, (0 << 16), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, -1572, 2584, -9324, 0, 0, 0, (0 << 16), bhvFireSpitter),
		OBJECT(MODEL_NONE, -507, 3672, -9945, 0, 92, 0, 0x00100000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -600, 2898, -6195, 0, 92, 0, 0x00100000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -931, 2760, -7716, 0, 0, 0, (0 << 16), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -5086, 919, -4884, 0, 0, 0, (0 << 16), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -709, 3299, 843, 0, 0, 0, (0 << 16), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -1691, 1364, 3738, 0, 64, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_NONE, 925, 1364, 3837, 0, 112, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_NONE, -414, 2015, -107, 0, 90, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1578, 2759, -5729, 0, -125, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4616, 1625, -5604, 0, -98, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5211, 1284, 744, 0, 6, 0, 0, bhvCoinFormation),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, 1653, 3028, -2129, 0, 121, 0, (0), bhvBreakableBoxSmall),
		OBJECT(MODEL_PURPLE_SWITCH, 2356, 2615, -3193, 0, 158, 0, (1), bhvFloorSwitchHeavy),
		OBJECT(MODEL_NONE, 2592, 2484, -3991, 0, 176, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1996, 3250, -2402, 0, 147, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 2307, 2623, -2653, 0, 147, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 2140, 2623, -2763, 0, 147, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 2086, 2623, -2319, 0, 147, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1920, 2623, -2430, 0, 147, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1975, 3888, -3349, 0, 157, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1791, 3888, -3426, 0, 157, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1607, 3888, -3504, 0, 157, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1422, 3888, -3582, 0, 157, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 2106, 3450, -2569, 0, 147, 0, (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1422, 3588, -3582, 0, 157, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_NONE, 593, 3793, -3932, 0, 157, 0, (1 << 16) | (1), bhvHiddenObject),
		OBJECT(MODEL_METAL_BOX, -407, 3844, 1868, 0, -180, 0, 0, bhvPushableMetalBox),
		OBJECT(MODEL_RED_COIN, 3336, 2964, -6587, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4128, 3452, -7749, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1242, 3982, -10054, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5347, 3461, -7385, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 359, 2462, -9681, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3099, 2941, -9756, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2827, 4243, -6779, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3256, 3538, -9550, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_PURPLE_SWITCH, 2386, 2739, -4602, 0, -159, 0, (1), bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_ROT_SMALL, -2741, 2759, -427, 0, -180, 0, 0, bhvRotatingSmall),
		OBJECT(MODEL_ROT_SMALL, -3013, 2969, -802, 0, -146, 0, 0, bhvRotatingSmall),
		OBJECT(MODEL_ROT_SMALL, -2626, 3218, -829, 0, -173, 0, 0, bhvRotatingSmall),
		OBJECT(MODEL_SCUTTLEBUG, -2935, 2639, -9837, 0, 0, 0, (0 << 16), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -2416, 2760, -7341, 0, 0, 0, (0 << 16), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 1605, 2760, -7627, 0, 0, 0, (0 << 16), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 2972, 2589, -9559, 0, 0, 0, (0 << 16), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -2010, 1271, 3551, 0, 0, 0, (0 << 16), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 1061, 1257, 3742, 0, 0, 0, (0 << 16), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 471, 3297, 1497, 0, 0, 0, (0 << 16), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -601, 3299, -719, 0, 0, 0, (0 << 16), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -1396, 980, -4779, 0, 0, 0, (0 << 16), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 710, 980, -1893, 0, 0, 0, (0 << 16), bhvScuttlebug),
		OBJECT(MODEL_TRIGGER, -2899, 1181, 2224, 0, 0, 0, (2 << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRIGGER, 2004, 1344, 700, 0, 0, 0, (2 << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRIGGER, -461, 2014, -438, 0, 0, 0, (2 << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRIGGER, -333, 2841, 3131, 0, 0, 0, (2 << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_SNUFIT, 1415, 3064, -5766, 0, 0, 0, (0 << 16), bhvSnufit),
		OBJECT(MODEL_SNUFIT, -651, 3534, -1369, 0, 0, 0, (0 << 16), bhvSnufit),
		OBJECT(MODEL_SQUARE_FLAT, -2046, 2252, -9994, 0, 0, 0, (0 << 24) | (16 << 16) | (2 << 8) | (58), bhvSquareVert),
		OBJECT(MODEL_SQUARE_FLAT, -1581, 1805, -5892, 0, 29, 0, (0 << 24) | (16 << 16) | (3 << 8) | (75), bhvSquareVert),
		OBJECT(MODEL_NONE, -218, 3048, -7591, 0, 0, 0, (0 << 16), bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, -407, 5469, 4521, 0, 0, 0, (1 << 16), bhvStar),
		OBJECT(MODEL_BOWLING_BALL, -4293, 1688, 2043, 0, 0, 0, (0 << 16), bhvFireSpitter),
		OBJECT(MODEL_NONE, -380, 995, 4118, 0, 0, 0, (2 << 16), bhvHiddenStar),
		OBJECT(MODEL_TRIGGER, -1785, 2842, 1371, 0, 0, 0, (2 << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_STAR, -254, 4400, -4277, 0, 0, 0, (3 << 16), bhvStar),
		OBJECT(MODEL_WIGGLER_HEAD, -326, 962, 1816, 0, 0, 0, (4 << 16), bhvWigglerHead),
		OBJECT(MODEL_NONE, -2049, 2425, -9998, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1571, 1972, -5848, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2644, 1745, -2037, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1828, 2373, -1561, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -393, 2269, 3727, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2003, 1545, 736, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2739, 1260, 2790, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -407, 3394, 2315, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -30, 1049, -3616, 0, 90, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -2532, 3297, -1381, 0, 0, 0, (0xC << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, -4725, 1074, -959, 0, -169, 0, (0xA << 16), bhvAirborneWarp),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x26),
		TERRAIN_TYPE(TERRAIN_STONE),
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
