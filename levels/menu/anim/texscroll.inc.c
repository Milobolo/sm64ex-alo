void scroll_sts_mat_anim_clouds_layer0() {
	Gfx *mat = segmented_to_virtual(mat_anim_clouds_layer0);
	shift_s(mat, 14, PACK_TILESIZE(0, 1));
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
};

void scroll_menu_level_geo_anim() {
	scroll_sts_mat_anim_clouds_layer0();
}
