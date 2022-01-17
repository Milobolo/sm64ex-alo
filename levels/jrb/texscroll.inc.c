void scroll_sts_mat_jrb_dl_lava_fall_layer1() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_lava_fall_layer1);
	shift_t(mat, 21, PACK_TILESIZE(0, 2));
	shift_t(mat, 36, PACK_TILESIZE(0, 4));
};

void scroll_sts_mat_jrb_dl_water_layer5() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_water_layer5);
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));

	if (--curInterval1 <= 0) {
		shift_s_down(mat, 23, PACK_TILESIZE(0, 1));
		shift_t_down(mat, 23, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_jrb() {
	scroll_sts_mat_jrb_dl_lava_fall_layer1();
	scroll_sts_mat_jrb_dl_water_layer5();
}
