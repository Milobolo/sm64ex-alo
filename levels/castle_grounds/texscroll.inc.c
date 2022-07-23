void scroll_sts_mat_castle_grounds_dl_text_rainbow() {
	Gfx *mat = segmented_to_virtual(mat_castle_grounds_dl_text_rainbow);
	shift_s(mat, 17, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_castle_grounds() {
	scroll_sts_mat_castle_grounds_dl_text_rainbow();
}
