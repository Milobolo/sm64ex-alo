#include "levels/intro/header.h"
void scroll_sts_mat_title_globe_layer1() {
	Gfx *mat = segmented_to_virtual(mat_title_globe_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 5));
	shift_t(mat, 13, PACK_TILESIZE(0, 2));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 3));
	shift_t_down(mat, 21, PACK_TILESIZE(0, 3));
};

void scroll_sts_mat_title_ssrm() {
	Gfx *mat = segmented_to_virtual(mat_title_ssrm);
	shift_s_down(mat, 17, PACK_TILESIZE(0, 16));
};

void scroll_bob_level_geo_title() {
	scroll_sts_mat_title_globe_layer1();
	scroll_sts_mat_title_ssrm();
}
