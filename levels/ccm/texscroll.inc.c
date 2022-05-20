void scroll_sts_mat_ccm_dl_water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_water_layer5);
	shift_s_down(mat, 15, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 15, PACK_TILESIZE(0, 1));
	shift_s(mat, 23, PACK_TILESIZE(0, 1));
	shift_t(mat, 23, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ccm_dl_poison() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_poison);
	shift_s(mat, 10, PACK_TILESIZE(0, 4));
};

void scroll_sts_mat_ccm_dl_shinry_floor_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_shinry_floor_layer1);
	shift_s(mat, 20, PACK_TILESIZE(0, 1));
	shift_t(mat, 20, PACK_TILESIZE(0, 1));
};

void scroll_ccm() {
	scroll_sts_mat_ccm_dl_water_layer5();
	scroll_sts_mat_ccm_dl_poison();
	scroll_sts_mat_ccm_dl_shinry_floor_layer1();
}
