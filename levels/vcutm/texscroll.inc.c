void scroll_sts_mat_vcutm_dl_scroll_eff() {
	Gfx *mat = segmented_to_virtual(mat_vcutm_dl_scroll_eff);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_vcutm() {
	scroll_sts_mat_vcutm_dl_scroll_eff();
}
