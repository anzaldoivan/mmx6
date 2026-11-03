// prog SLUS_013.95 | system effect | range -
/* mmx6/effect.h -- the effect functions called outside effect/ (effect/spawn_visual.c) (hand-edited; Phase 2.5 T10.c2). Each prototype carries its definition's type
 * (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_EFFECT_H
#define MMX6_EFFECT_H

#include "common.h"
#include "mmx6/x4.h"

s32 player_spawn_visual(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
// Phase 2.6 T10.c1: hoisted from the movement files' own declarations
struct X4_VisualObj* find_free_visual_obj(void);
void spawn_dust(struct X4_PlayerObj* self);

#endif /* MMX6_EFFECT_H */
