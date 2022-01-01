void scroll_sts_mat_bowser_1_dl_ss2_black() {
	Gfx *mat = segmented_to_virtual(mat_bowser_1_dl_ss2_black);
	shift_t(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_bowser_1() {
	scroll_sts_mat_bowser_1_dl_ss2_black();
}
