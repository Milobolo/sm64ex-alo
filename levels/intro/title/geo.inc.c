#include "src/game/envfx_snow.h"

const GeoLayout title_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 26, -55, -1353, 0, -1, 0, title_Icosphere_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -1194, 491, -671, 90, 0, 1, title_Text_011_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, title_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
