// prog SLUS_013.95 | system cling | range -
/* mmx6/cling.h -- the wall-cling functions called outside cling/ (cling/enter_wall_cling.c) (hand-edited; Phase 2.5 T10.c2). Each prototype carries its definition's type
 * (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_CLING_H
#define MMX6_CLING_H

#include "common.h"
#include "mmx6/x4.h"

s32 try_enter_wall_cling(void*);
// Phase 2.6 T10.c1: hoisted from the movement files' own declarations
extern void (*ceiling_jump_phase_table[])(void*);
extern void (*ceiling_state_table[])(struct X4_MainObj*);
s32 check_ceiling_jump();
void player_enter_wall_cling(void* arg0);
void start_wall_jump(void* arg0);

#endif /* MMX6_CLING_H */
