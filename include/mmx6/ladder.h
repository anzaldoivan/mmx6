// prog SLUS_013.95 | system ladder | range -
/* mmx6/ladder.h -- the ladder functions called outside their own file (ladder/) (hand-edited; Phase 2.6 T10.c1). Each prototype carries the type its
 * callers declared (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_LADDER_H
#define MMX6_LADDER_H

#include "common.h"
#include "mmx6/x4.h"

void grab_ladder(void*);
void player_enter_ladder_climb_on_top(void*);
void player_enter_ladder_step_off_bottom(void*);
s32 try_enter_ladder(void*);
s32 try_leave_ladder();

#endif /* MMX6_LADDER_H */
