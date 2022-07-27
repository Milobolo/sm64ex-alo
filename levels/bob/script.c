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
	LOAD_MIO0(0x0A, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd), 
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
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(WARP_NODE_DEATH, LEVEL_BOB, 1, 0x1C, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_F0, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_STAR_GET, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BOB, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(212, 306, -2500, 2792, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(140, 3432, 2055, 6286, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(129, 4069, 3018, 6342, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 3445, 3018, 6349, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 3749, 3018, 6349, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(130, -335, -2097, -5901, 0, 0, 0, 0x0, bhvBreakableBoxSmall),
		OBJECT(223, -1238, -18, -3979, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 1001, -17, -3830, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, -840, -1601, 2886, 45, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 310, 304, 7176, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -2690, 8336, 5914, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -1311, 6791, -4838, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -1565, 9855, -7375, 50, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -5486, 9358, 4130, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(84, -1927, 10520, 1241, 0, 0, 0, 0x0, bhvEnemyLakitu),
		OBJECT(84, -841, 624, -6898, 0, 0, 0, 0x0, bhvEnemyLakitu),
		OBJECT(84, -1610, -4376, -4462, 0, 0, 0, 0x0, bhvEnemyLakitu),
		OBJECT(137, 2535, 3644, -75, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, -366, 4582, 3339, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, -2782, 6956, -6836, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(0, -669, 7693, 2743, 0, 0, 0, 0xc0000, bhvFadingWarp),
		OBJECT(0, -1288, 6092, -4228, 0, 0, 0, 0xb0000, bhvFadingWarp),
		OBJECT(180, -2175, -789, -7520, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 2032, 1546, -4980, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 2034, 3699, -4988, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 1499, 2606, -655, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 1505, 2606, 481, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 1905, 4005, 229, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 1917, 1629, 4536, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 487, 3235, 6882, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, -677, 5875, 4548, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, -1302, 6042, -5365, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, -823, 8585, -6157, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(207, -1849, 10165, 663, 0, -180, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, 642, -18, -6914, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(118, 3355, 2291, 5582, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 3188, 3671, 5610, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 3189, 3782, 5839, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 3436, 3064, 6130, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 4072, 3064, 6113, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 4703, 2567, 6345, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(129, -2208, 10370, 662, 0, 0, 45, 0x0, bhvHiddenObject),
		OBJECT(129, -1822, 11005, 663, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -2319, 11614, 663, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -2319, 11414, 663, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -2319, 11214, 663, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 497, 9166, 3616, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -482, 9294, 4540, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 497, 9294, 4527, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(0, -196, 433, -6861, 0, 0, 0, 0x5000000, bhvHiddenRedCoinStar),
		OBJECT(194, 540, 260, -3966, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT(194, 88, 677, -3587, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT(194, 389, 1146, -3693, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT(129, -2329, -18, -5122, 0, 0, 0, 0x0, bhvJumpingBox),
		OBJECT(124, 2024, -3214, 97, 0, -154, 0, 0x340000, bhvMessagePanel),
		OBJECT(124, 1709, 3173, -7390, 0, 180, 0, 0x350000, bhvMessagePanel),
		OBJECT(124, -208, 7601, -6829, 0, -90, 0, 0x360000, bhvMessagePanel),
		OBJECT(0, -1091, 8291, -6822, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(0, -1447, 9585, -2869, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(0, -3963, 9640, 6557, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(217, 2277, 2522, -5808, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, 2202, 4389, -397, 0, 0, 45, 0x0, bhvPushableMetalBox),
		OBJECT(217, 1996, 4583, -704, 0, 0, 45, 0x0, bhvPushableMetalBox),
		OBJECT(217, 1786, 4792, -396, 0, 0, 45, 0x0, bhvPushableMetalBox),
		OBJECT(217, 250, 4586, 7191, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, 250, 4586, 7497, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(215, 2928, -616, -87, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -813, -1472, -2277, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2677, -3763, -3942, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1881, 1868, -7464, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1818, 1868, -6350, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -105, 2641, -3489, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 2878, 5760, -102, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -399, 4297, 4526, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3051, -1527, 4545, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1631, -2990, 2491, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4221, -257, 7155, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 749, 4573, 5732, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3111, 4877, 5541, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1447, 6892, 2958, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(101, 1682, -468, -6981, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 856, -3186, -1310, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 826, -2064, -5937, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(206, 11, -1927, -4278, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, -1607, -1927, -4315, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, 1924, 1198, 190, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, -667, 521, 4529, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, -2002, 8385, -6861, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(0, 1761, -2818, -260, 0, 0, 0, (0x0A << 16), bhvSpinAirborneWarp),
		OBJECT(0, 1761, -2818, -260, 0, 0, 0, (0x1C << 16), bhvAirborneDeathWarp),
		OBJECT(122, -4065, -3078, 4741, 0, 0, 0, 0x0, bhvStar),
		OBJECT(122, 1905, 5457, -85, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 2204, 3359, 7426, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(122, -1849, 11904, 663, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(122, -2484, 7306, 7122, 0, 0, 0, 0x4000000, bhvStar),
		OBJECT(100, -255, -4010, -4069, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 2032, 417, -6933, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 1571, 3333, -126, 0, 0, 0, 0x0, bhvSwoop),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x24),
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
