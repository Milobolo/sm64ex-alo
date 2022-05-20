void scroll_sts_mat_wf_dl_scroll() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_scroll);
	shift_t(mat, 17, PACK_TILESIZE(0, 10));
};

void scroll_wf_dl_slate_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 214;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_slate_mesh_layer_1_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_wf_dl_star_pattern() {
	static int intervalTex0 = 24;
	static int curInterval0 = 24;
	Gfx *mat = segmented_to_virtual(mat_wf_dl_star_pattern);

	if (--curInterval0 <= 0) {
		shift_s(mat, 17, PACK_TILESIZE(0, 32));
		curInterval0 = intervalTex0;
	}
};

void scroll_wf_dl_slate_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 214;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_slate_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf_dl_slate_002_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 214;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_slate_002_mesh_layer_1_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf_dl_slate_003_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 214;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_slate_003_mesh_layer_1_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf_dl_slate_004_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 214;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_slate_004_mesh_layer_1_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf_dl_slate_005_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 214;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_slate_005_mesh_layer_1_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_wf_dl_water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_water_layer5);
	shift_s_down(mat, 15, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 15, PACK_TILESIZE(0, 1));
	shift_s(mat, 23, PACK_TILESIZE(0, 1));
	shift_t(mat, 23, PACK_TILESIZE(0, 1));
};

void scroll_wf() {
	scroll_sts_mat_wf_dl_scroll();
	scroll_wf_dl_slate_mesh_layer_1_vtx_0();
	scroll_sts_mat_wf_dl_star_pattern();
	scroll_wf_dl_slate_001_mesh_layer_1_vtx_0();
	scroll_wf_dl_slate_002_mesh_layer_1_vtx_0();
	scroll_wf_dl_slate_003_mesh_layer_1_vtx_0();
	scroll_wf_dl_slate_004_mesh_layer_1_vtx_0();
	scroll_wf_dl_slate_005_mesh_layer_1_vtx_0();
	scroll_sts_mat_wf_dl_water_layer5();
}
