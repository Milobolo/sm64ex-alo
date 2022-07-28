void scroll_sts_mat_sl_dl_nod_lava() {
	Gfx *mat = segmented_to_virtual(mat_sl_dl_nod_lava);
	shift_t(mat, 10, PACK_TILESIZE(0, 3));
};

void scroll_sl() {
	scroll_sts_mat_sl_dl_nod_lava();
}
