void scroll_sts_mat_ssl_dl_SM64_DL_rr_1_0xe0932b8_F3D_Mat_1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_SM64_DL_rr_1_0xe0932b8_F3D_Mat_1);
	shift_s(mat, 10, PACK_TILESIZE(0, 2));
	shift_t(mat, 10, PACK_TILESIZE(0, 2));
};

void scroll_ssl() {
	scroll_sts_mat_ssl_dl_SM64_DL_rr_1_0xe0932b8_F3D_Mat_1();
}
