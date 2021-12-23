#include "src/game/envfx_snow.h"

const GeoLayout hint_geo[] = {
	GEO_BILLBOARD(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(4, hint_Plane_003_mesh_layer_4),
		GEO_DISPLAY_LIST(4, hint_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
