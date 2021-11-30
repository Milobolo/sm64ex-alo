#ifndef TEXT_ENGINE_H
#define TEXT_ENGINE_H

#include <PR/ultratypes.h>

void start_render_magic_spells_hud(void);
void cancel_render_magic_spells_hud(void);
void magic_hud_render_controller(struct MarioState *m);
void update_mario_exp(struct MarioState *m);
#endif