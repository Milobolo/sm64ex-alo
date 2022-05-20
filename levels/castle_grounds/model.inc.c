Lights1 castle_grounds_dl_f3d_material_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx castle_grounds_dl_Plane_mesh_layer_1_vtx_0[6] = {
	{{{-573, 0, 573},0, {-16, 1008},{0x96, 0x71, 0xAD, 0xFF}}},
	{{{573, 0, -573},0, {1008, -16},{0xDC, 0xA7, 0xFF, 0xFF}}},
	{{{-573, 0, -573},0, {-16, -16},{0x98, 0xA0, 0xFF, 0xFF}}},
	{{{573, 0, 573},0, {1008, 1008},{0x84, 0x8E, 0xFF, 0xFF}}},
	{{{573, 352, 573},0, {1008, 1008},{0x84, 0x8E, 0xFF, 0xFF}}},
	{{{573, 352, -573},0, {1008, -16},{0xDC, 0xA7, 0xFF, 0xFF}}},
};

Gfx castle_grounds_dl_Plane_mesh_layer_1_tri_0[] = {
	gsSPVertex(castle_grounds_dl_Plane_mesh_layer_1_vtx_0 + 0, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(1, 3, 4, 0),
	gsSP1Triangle(1, 4, 5, 0),
	gsSPEndDisplayList(),
};

Gfx mat_castle_grounds_dl_f3d_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(castle_grounds_dl_f3d_material_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_castle_grounds_dl_f3d_material[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx castle_grounds_dl_Plane_mesh_layer_1[] = {
	gsSPDisplayList(mat_castle_grounds_dl_f3d_material),
	gsSPDisplayList(castle_grounds_dl_Plane_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_castle_grounds_dl_f3d_material),
	gsSPEndDisplayList(),
};

Gfx castle_grounds_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

