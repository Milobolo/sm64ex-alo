void scroll_sts_mat_jrb_dl_lava_fall() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_lava_fall);
	shift_t(mat, 20, PACK_TILESIZE(0, 2));
	shift_t(mat, 35, PACK_TILESIZE(0, 4));
};

void scroll_sts_mat_jrb_dl_water() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_water);
	shift_s(mat, 14, PACK_TILESIZE(0, 1));
	shift_t(mat, 14, PACK_TILESIZE(0, 1));

	if (--curInterval1 <= 0) {
		shift_s_down(mat, 22, PACK_TILESIZE(0, 1));
		shift_t_down(mat, 22, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_jrb() {
	scroll_sts_mat_jrb_dl_lava_fall();
	scroll_sts_mat_jrb_dl_water();
}
