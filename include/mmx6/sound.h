// prog SLUS_013.95 | system sound | range -
/* mmx6/sound.h -- the sound functions called outside sound/ (sound/sound.c) (hand-edited; Phase 2.5 T10.c2). Each prototype carries its definition's type
 * (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_SOUND_H
#define MMX6_SOUND_H

#include "common.h"
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
// Phase 2.6 T10.c1: hoisted from the movement files' own declarations
void silence_sound(u8, u8);

#endif /* MMX6_SOUND_H */
