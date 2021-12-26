#ifndef MAGIC_H
#define MAGIC_H

#include <PR/ultratypes.h>
extern u32 gMagicHUDRequest;

//hud requests

#define HUD_OPEN                      /* 0x00000001 */ (1 <<  0)
#define START_CAST                    /* 0x00000002 */ (1 <<  1)
#define CANCEL_CAST                   /* 0x00000004 */ (1 <<  2)
#define HUD_MAIN                      /* 0x00000008 */ (1 <<  3)
#define CANCEL_HUD                    /* 0x00000010 */ (1 <<  4)
#define CASTING_SEL                   /* 0x00000020 */ (1 <<  5)
#define CASTING_ON_PLAT               /* 0x00000040 */ (1 <<  6)
#define CAST_SPELL                    /* 0x00000080 */ (1 <<  7)
#define CAST_SPIRIT                   /* 0x00000100 */ (1 <<  8)
#define CAST_ENVIRONMENT              /* 0x00000200 */ (1 <<  9)
#define CAST_ITEM                     /* 0x00000400 */ (1 <<  10)
#define CAST_WAIT                     /* 0x00000800 */ (1 <<  11)


//spells inside save struct
enum spells{
	//items
	magic_hat,
	metal_cap,
	vanish_cap,
	//spells
	sp_return,
	swap,
	time_freeze,
	//spirit
	gigantify,
	hover,
	stick,
	//env
	ice_block,
	hanging_leaf,
	cloud_lob,
	cancel,
};

//spell defines
#define ACTION_NULL                          /* 0x00000000 */ 0
#define ACTION_MAGIC_HAT                     /* 0x00000001 */ (1 <<  0)
#define ACTION_METAL_CAP                     /* 0x00000002 */ (1 <<  1)
#define ACTION_VANISH_CAP                    /* 0x00000004 */ (1 <<  2)
#define ACTION_RETURN                        /* 0x00000008 */ (1 <<  3)
#define ACTION_SWAP                          /* 0x00000010 */ (1 <<  4)
#define ACTION_TIME_FREEZE                   /* 0x00000020 */ (1 <<  5)
#define ACTION_GIGANTIFY                     /* 0x00000040 */ (1 <<  6)
#define ACTION_HOVER                         /* 0x00000080 */ (1 <<  7)
#define ACTION_STICK                         /* 0x00000100 */ (1 <<  8)
#define ACTION_ICE_BLOCK                     /* 0x00000200 */ (1 <<  9)
#define ACTION_HANGING_LEAF                  /* 0x00000400 */ (1 <<  10)
#define ACTION_CLOUD_LOB                     /* 0x00000800 */ (1 <<  11)
#define ACTION_CANCEL_ENV                    /* 0x00001000 */ (1 <<  12)
#define ACTION_CANCEL_SPIRIT                 /* 0x00002000 */ (1 <<  13)



void start_render_magic_spells_hud(void);
void cancel_render_magic_spells_hud(void);
void magic_hud_render_controller(struct MarioState *m);
void update_mario_exp(struct MarioState *m);
void update_mario_colors_spirit(struct MarioState *m);
u32 wait_set_mario_cast(struct MarioState *m);
void handle_magic_actions(struct MarioState *m);
u32 create_magic_list_dialog(u32 list, u8 usr);
void list_scroll_y_dialog(void);
u32 mario_has_spell_TE(s16 *file, u32 spell);
u32 Get_Spell_Sel(u32 list);
void mario_set_spell(u32 spell);
u32 mario_can_cast(void);
#endif