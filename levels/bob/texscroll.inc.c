void scroll_sts_mat_bob_dl_water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl_water_layer5);
	shift_s_down(mat, 15, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 15, PACK_TILESIZE(0, 1));
	shift_s(mat, 23, PACK_TILESIZE(0, 1));
	shift_t(mat, 23, PACK_TILESIZE(0, 1));
};

void scroll_bob() {
	scroll_sts_mat_bob_dl_water_layer5();
}
