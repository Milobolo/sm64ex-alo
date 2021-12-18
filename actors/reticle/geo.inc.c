#include "src/game/envfx_snow.h"

const GeoLayout reticle_geo[] = {
	GEO_BILLBOARD(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(4, reticle_Plane_002_mesh_layer_4),
		GEO_DISPLAY_LIST(4, reticle_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
