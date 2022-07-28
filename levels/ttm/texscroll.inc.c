void scroll_sts_mat_ttm_dl_water() {
	Gfx *mat = segmented_to_virtual(mat_ttm_dl_water);
	shift_s(mat, 18, PACK_TILESIZE(0, 1));
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_ttm() {
	scroll_sts_mat_ttm_dl_water();
}
