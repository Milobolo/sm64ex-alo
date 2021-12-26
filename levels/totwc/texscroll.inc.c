void scroll_sts_mat_totwc_dl_spell_sand_001() {
	Gfx *mat = segmented_to_virtual(mat_totwc_dl_spell_sand_001);
	shift_t_down(mat, 19, PACK_TILESIZE(0, 1));
	shift_t(mat, 34, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_totwc_dl_spell_sand_xlu() {
	Gfx *mat = segmented_to_virtual(mat_totwc_dl_spell_sand_xlu);
	shift_t_down(mat, 19, PACK_TILESIZE(0, 1));
	shift_t(mat, 34, PACK_TILESIZE(0, 1));
};

void scroll_totwc() {
	scroll_sts_mat_totwc_dl_spell_sand_001();
	scroll_sts_mat_totwc_dl_spell_sand_xlu();
}
