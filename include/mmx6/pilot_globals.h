// prog SLUS_013.95 | system pilot | range -
/* mmx6/pilot_globals.h -- the declarations the pilot systems player/weapon still repeated per file, all in unit
 * 32208 (hand-edited; Phase 2.5 T10.c5). Not included by x4.h, player.h or object.h (C0331): g_Player and
 * g_playthrough_state carry other types in non-pilot files. The functions stay unprototyped so every caller's
 * argument list fits; clear_object_slot is `s32` as unit 32208 declares it (unit 120A0 has it `void`). */
#ifndef MMX6_PILOT_GLOBALS_H
#define MMX6_PILOT_GLOBALS_H

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/engine_state.h"

extern struct X4_PlayerObj g_Player;
s32 animate_object();
s32 clear_object_slot();

#endif /* MMX6_PILOT_GLOBALS_H */
