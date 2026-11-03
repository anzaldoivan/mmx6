// prog SLUS_013.95 | system damage | range -
/* mmx6/damage.h -- the damage function and the hurt tables of damage/hurt_8003963C.c called or read outside their file (hand-edited; Phase 2.6 T10.c1). Each prototype carries the type its
 * callers declared (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_DAMAGE_H
#define MMX6_DAMAGE_H

#include "common.h"
#include "mmx6/x4.h"

extern u8 hurt_invincibility_times[];
extern s32 hurt_motion_table[][4];
void start_hurt(void* arg0);

#endif /* MMX6_DAMAGE_H */
