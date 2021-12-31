#include "src/game/envfx_snow.h"

const GeoLayout trigger_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, trigger_Cube_006_mesh_layer_1),
		GEO_BILLBOARD_WITH_PARAMS(LAYER_OPAQUE, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_ROTATION_NODE(LAYER_OPAQUE, 90, 0, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, trigger_Plane_004_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, trigger_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, trigger_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
