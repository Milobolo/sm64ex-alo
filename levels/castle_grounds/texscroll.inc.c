void scroll_sts_mat_castle_grounds_dl_f3dlite_material_layer1() {
	Gfx *mat = segmented_to_virtual(mat_castle_grounds_dl_f3dlite_material_layer1);
	shift_s(mat, 12, PACK_TILESIZE(0, 2));
	shift_t(mat, 12, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 20, PACK_TILESIZE(0, 2));
	shift_t_down(mat, 20, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_castle_grounds_dl_nod_lava() {
	Gfx *mat = segmented_to_virtual(mat_castle_grounds_dl_nod_lava);
	shift_t(mat, 10, PACK_TILESIZE(0, 3));
};

void scroll_sts_mat_castle_grounds_dl_text_rainbow() {
	Gfx *mat = segmented_to_virtual(mat_castle_grounds_dl_text_rainbow);
	shift_s(mat, 17, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_castle_grounds() {
	scroll_sts_mat_castle_grounds_dl_f3dlite_material_layer1();
	scroll_sts_mat_castle_grounds_dl_nod_lava();
	scroll_sts_mat_castle_grounds_dl_text_rainbow();
}
