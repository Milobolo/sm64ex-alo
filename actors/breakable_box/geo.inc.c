#include "src/game/envfx_snow.h"

const GeoLayout breakable_box_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, breakable_box__breakable_box_seg8_dl_08012D48_Obj_001_mesh_layer_1),
		GEO_DISPLAY_LIST(1, breakable_box_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

const GeoLayout breakable_box_small_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, breakable_box__breakable_box_seg8_dl_08012D48_Obj_001_mesh_layer_1),
		GEO_DISPLAY_LIST(1, breakable_box_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
