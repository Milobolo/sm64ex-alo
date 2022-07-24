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
	LOAD_MIO0(0x0A, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(22, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(WARP_NODE_DEATH, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_REVIVE, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_SUCCESS, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_STAR_GET, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(0, 7074, 10215, 7709, 0, -180, 0, 0xa0000, bhvAirborneWarp),
		OBJECT(137, 6472, -7139, -1945, 0, 42, 0, 0xa0000, bhvExclamationBox),
		OBJECT(0, 1980, 772, 6618, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT(180, -6422, -8426, 7642, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, -8004, 1016, 6504, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 5204, -2944, -4607, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 4246, -984, 3189, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 7106, 9321, 6761, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 7141, 9321, 5775, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, -2253, 5768, -6213, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 4536, -2493, -2094, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 4869, -2321, -1480, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 6291, 7071, -6539, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(0, 4820, -3084, -6898, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 5480, -3061, -6205, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 5871, -1190, 3583, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 6418, -1225, 3121, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 7636, -1536, 2038, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 3817, 6708, -6669, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(89, 5970, -2199, -514, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, -2859, 3525, 2634, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, -6591, 526, 3475, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(0, -7272, -3484, -7213, 0, 107, 0, 0x0, bhvHiddenStar),
		OBJECT(121, 368, 6218, -7167, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(121, -7330, 1364, 8232, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(121, 4203, -3749, -5191, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(121, -2180, 559, 3230, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(121, 6347, -1635, -2308, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(217, -2259, 1665, 6174, -13, -157, 32, 0x0, bhvPushableMetalBox),
		OBJECT(122, -6239, -3774, -7136, 0, 0, 0, 0x2000000, bhvStar),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x26),
		TERRAIN_TYPE(TERRAIN_SLIDE),
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
