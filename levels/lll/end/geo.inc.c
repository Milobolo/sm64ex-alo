#include "src/game/envfx_snow.h"

const GeoLayout end_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -1205, end_Plane_012_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, end_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
