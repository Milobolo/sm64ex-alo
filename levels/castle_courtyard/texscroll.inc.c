void scroll_sts_mat_castle_courtyard_dl_clouds_layer0() {
	Gfx *mat = segmented_to_virtual(mat_castle_courtyard_dl_clouds_layer0);
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
};

void scroll_castle_courtyard() {
	scroll_sts_mat_castle_courtyard_dl_clouds_layer0();
}
