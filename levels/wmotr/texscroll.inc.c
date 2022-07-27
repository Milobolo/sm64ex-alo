void scroll_sts_mat_wmotr_dl_text_rainbow_001() {
	Gfx *mat = segmented_to_virtual(mat_wmotr_dl_text_rainbow_001);
	shift_s(mat, 17, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_wmotr() {
	scroll_sts_mat_wmotr_dl_text_rainbow_001();
}
