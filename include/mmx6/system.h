// prog SLUS_013.95 | system system | range -
/* mmx6/system.h -- the system functions called outside system/ (system/buttons.c, random_byte.c) (hand-edited; Phase 2.5 T10.c2). Each prototype carries its definition's type
 * (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_SYSTEM_H
#define MMX6_SYSTEM_H

#include "common.h"
#include "mmx6/x4.h"

u16 map_buttons(u16 arg0);
s32 random_byte();

#endif /* MMX6_SYSTEM_H */
