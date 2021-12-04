#ifndef MAGIC_H
#define MAGIC_H

#include <PR/ultratypes.h>
extern u32 gMagicHUDRequest;

//hud requests

#define HUD_OPEN                      /* 0x00000001 */ (1 <<  0)
#define START_CAST                    /* 0x00000002 */ (1 <<  1)
#define CANCEL_CAST                   /* 0x00000004 */ (1 <<  2)
#define CAST_SPELL                    /* 0x00000008 */ (1 <<  3)
#define CAST_SPIRIT                   /* 0x00000010 */ (1 <<  4)
#define CAST_ENVIRONMENT              /* 0x00000020 */ (1 <<  5)
#define HOLD_CAST                     /* 0x00000040 */ (1 <<  6)
#define CANCEL_HUD                    /* 0x00000080 */ (1 <<  7)
#define CASTING_SEL                   /* 0x00000100 */ (1 <<  8)
#define CASTING_UNK                   /* 0x00000200 */ (1 <<  9)

//spells
enum spells{
	//items
	//consumables (should change later to be less dumb)
	magic_pot,
	magic_pot2,
	magic_pot3,
	magic_pot4,
	health_pot,
	health_pot2,
	health_pot3,
	health_pot4,
	//spells
	checkpoint,
	time_freeze,
	destroy_enemy,
	teleport_portal,
	spell5,
	spell6,
	spell7,
	spell8,
	//spirit
	super_strength,
	floaty_jumps,
	wall_stick,
	water_walk,
	immunity,
	test1,
	test2,
	test3,
	//env
	ice_block,
	rising_leaf,
	cloud_lob,
	unk4,
	unk5,
	unk6,
	unk7,
	unk8,
};


void start_render_magic_spells_hud(void);
void cancel_render_magic_spells_hud(void);
void magic_hud_render_controller(struct MarioState *m);
void update_mario_exp(struct MarioState *m);
u32 wait_set_mario_cast(struct MarioState *m);
void handle_magic_actions(struct MarioState *m);
u32 create_magic_list_dialog(u32 list, u8 usr);
void list_scroll_y_dialog(void);
u32 mario_has_spell_TE(s16 *file, u32 spell);

#endif