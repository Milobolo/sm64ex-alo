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
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group3_mio0SegmentRomStart, _group3_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_RED_COIN, deo_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x1B, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x1C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GOOMBA, 4867, -44, -7018, 0, -90, 0, (2 << 16) | (4), bhvGoombaTE),
		OBJECT(MODEL_GOOMBA, 4879, -44, -6070, 0, -90, 0, (1 << 16) | (7), bhvGoombaTE),
		OBJECT(MODEL_GOOMBA, 3313, -44, -6036, 0, -90, 0, (6), bhvGoombaTE),
		OBJECT(MODEL_GOOMBA, 3321, -44, -7015, 0, 90, 0, (1 << 16) | (5), bhvGoombaTE),
		OBJECT(MODEL_NONE, 6235, 474, 0, 0, 0, 0, (0X1B << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_DORRIE, -5316, -139, -1890, 0, 90, 0, (1 << 16), bhvDorrieCutscene),
		OBJECT(MODEL_NONE, 5965, 486, -1809, 0, 0, 0, (1), bhvTEOnTrigger),
		OBJECT(MODEL_NONE, 6235, 172, 0, 0, 90, 0, (0XA << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_BOBOMB_BUDDY, 5810, 162, 1489, 0, -180, 0, (2), bhvPinkBuddyTE),
		OBJECT(MODEL_RED_COIN, -4491, 83, 56, 0, 0, 0, (0XA << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3395, 655, 6182, 0, 0, 0, (0XA << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -12240, 1910, 4932, 0, 0, 0, (0XA << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -13075, 1926, 209, 0, 0, 0, (0XA << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -10121, 1121, 118, 0, 0, 0, (0XA << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -11529, 1625, -5547, 0, 0, 0, (0XA << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5638, 2326, -5519, 0, 0, 0, (0XA << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -8503, -3972, 120, 0, 0, 0, (0XA << 16), bhvRedCoin),
		OBJECT(MODEL_NONE, 1161, 410, -1482, 0, 0, 0, (1), bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, 5965, 486, -558, 0, 0, 0, (0), bhvTEOnSpawn),
		OBJECT(MODEL_NONE, 6235, 474, 0, 0, 0, 0, (0X1B << 16), bhvAirborneStarCollectWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x24),
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
