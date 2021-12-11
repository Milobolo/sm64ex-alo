#include "src/game/envfx_snow.h"

const GeoLayout hover_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_layer_transparency),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(5, hover_Plane_001_mesh_layer_5),
			GEO_DISPLAY_LIST(5, hover_material_revert_render_settings),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
