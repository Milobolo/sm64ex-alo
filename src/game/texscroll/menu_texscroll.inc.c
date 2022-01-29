#include "levels/menu/header.h"
#include "levels/menu/anim/texscroll.inc.c"
extern u8 gJaboCheck;
#include "src/game/magic_str_te.h"
#include "src/game/magic_tuts_te.h"
void scroll_textures_menu() {
	scroll_menu_level_geo_anim();
	if(gJaboCheck == 1){
		//print msg
		gJaboCheck = 0;
		SetupTextEngine(10,50,no_jabo, TE_STATE_AUX);
	}
}
