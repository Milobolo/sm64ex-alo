void scroll_sts_mat_hmc_dl_lava() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_lava);
	shift_s_down(mat, 17, PACK_TILESIZE(0, 3));
};

void scroll_hmc() {
	scroll_sts_mat_hmc_dl_lava();
}
