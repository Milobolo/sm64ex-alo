void scroll_sts_mat_bitdw_dl_qs_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bitdw_dl_qs_layer1);
	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 12, PACK_TILESIZE(0, 1));
};

void scroll_bitdw() {
	scroll_sts_mat_bitdw_dl_qs_layer1();
}
