void scroll_sts_mat_ddd_dl_SM64_DL_bitdw_1_0xe027a28_F3D_Mat_0() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_SM64_DL_bitdw_1_0xe027a28_F3D_Mat_0);
	shift_s(mat, 10, PACK_TILESIZE(0, 2));
	shift_t_down(mat, 10, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_ddd_dl_SM64_DL_bitdw_1_0xe027a28_F3D_Mat_1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_SM64_DL_bitdw_1_0xe027a28_F3D_Mat_1);
	shift_s(mat, 10, PACK_TILESIZE(0, 2));
	shift_t(mat, 10, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_ddd_dl_SM64_DL_bitdw_2_0xe026d28_F3D_Mat_0() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_SM64_DL_bitdw_2_0xe026d28_F3D_Mat_0);
	shift_s(mat, 10, PACK_TILESIZE(0, 2));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_SM64_DL_bitdw_2_0xe026d28_F3D_Mat_2() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_SM64_DL_bitdw_2_0xe026d28_F3D_Mat_2);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_ddd() {
	scroll_sts_mat_ddd_dl_SM64_DL_bitdw_1_0xe027a28_F3D_Mat_0();
	scroll_sts_mat_ddd_dl_SM64_DL_bitdw_1_0xe027a28_F3D_Mat_1();
	scroll_sts_mat_ddd_dl_SM64_DL_bitdw_2_0xe026d28_F3D_Mat_0();
	scroll_sts_mat_ddd_dl_SM64_DL_bitdw_2_0xe026d28_F3D_Mat_2();
}
