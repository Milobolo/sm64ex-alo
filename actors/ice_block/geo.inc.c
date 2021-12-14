#include "src/game/envfx_snow.h"

const GeoLayout ice_block_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_layer_transparency),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(5, ice_block_Cube_002_mesh_layer_5),
			GEO_DISPLAY_LIST(5, ice_block_material_revert_render_settings),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};