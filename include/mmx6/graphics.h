// prog SLUS_013.95 | system graphics | range -
/* mmx6/graphics.h -- the animation functions called outside graphics/ (graphics/animation.c, animation_8003F4C4.c) (hand-edited; Phase 2.5 T10.c2). Each prototype carries its definition's type
 * (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_GRAPHICS_H
#define MMX6_GRAPHICS_H

#include "common.h"
#include "mmx6/x4.h"

s32 set_animation(void*, s32);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);
// Phase 2.6 T10.c1: hoisted from the movement files' own declarations
void clear_flash_palette(void* arg0);
void load_player_palette(struct X4_PlayerObj*, s32);
s32 player_set_animation_frame(void*, s32, s8);
s32 set_stand_animation_by_hp(void*);

#endif /* MMX6_GRAPHICS_H */
