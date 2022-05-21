#include "src/game/envfx_snow.h"

const GeoLayout title_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 326, -310, -183, title_Plane_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 326, -310, -183, title_Plane_011_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 326, -310, -183, title_Plane_013_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, title_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
