void scroll_sts_mat_bitdw_dl_qs() {
	Gfx *mat = segmented_to_virtual(mat_bitdw_dl_qs);
	shift_s(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 11, PACK_TILESIZE(0, 1));
};

void scroll_bitdw() {
	scroll_sts_mat_bitdw_dl_qs();
}
