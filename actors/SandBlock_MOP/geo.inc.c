#include "src/game/envfx_snow.h"

const GeoLayout SandBlock_MOP[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SCALE(LAYER_OPAQUE, 65536),
		GEO_OPEN_NODE(),
			GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, SandBlock_MOP_DL_Sandblock_MOP_0x30222d4_Obj_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, SandBlock_MOP_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
