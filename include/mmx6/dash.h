// prog SLUS_013.95 | system dash | range -
/* mmx6/dash.h -- the dash functions called outside dash/ (dash/dash_input.c, air_dash.c) (hand-edited; Phase 2.5 T10.c2). Each prototype carries its definition's type
 * (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_DASH_H
#define MMX6_DASH_H

#include "common.h"
#include "mmx6/x4.h"

s32 check_dash_input(struct X4_PlayerObj*);
s32 select_air_dash(void*);
// Phase 2.6 T10.c1: hoisted from the movement files' own declarations
s32 check_dash_end(void*);
extern void (*dash_phase_table[])(struct X4_MainObj*);
extern struct X4_Shot55Unk84 dash_spark_offsets[];
void end_dash(s32 arg0);
s32 start_falcon_dash(void*);
s32 try_start_air_dash(void*);

#endif /* MMX6_DASH_H */
