#include "src/game/envfx_snow.h"

const GeoLayout anim_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_FORCE, -155, -617, -7335, 123, 0, 0, anim_b_clouds_mesh_layer_0),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_FORCE, -262, -1819, -8320, 123, 0, 0, anim_d_stone_mesh_layer_0),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -262, -1819, -8320, 123, 0, 0, anim_e_atrium_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_FORCE, anim_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, anim_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
