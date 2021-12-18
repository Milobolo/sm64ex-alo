#include "src/game/envfx_snow.h"

const GeoLayout hollow_box_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(4, hollow_box__breakable_box_seg8_dl_08012D48_Obj_mesh_layer_4),
		GEO_DISPLAY_LIST(4, hollow_box_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
