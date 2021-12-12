#include "src/game/envfx_snow.h"

const GeoLayout spawn_border_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(5, spawn_border_sapawn_border_mesh_layer_5),
		GEO_DISPLAY_LIST(5, spawn_border_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
