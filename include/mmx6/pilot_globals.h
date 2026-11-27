// prog main | system pilot | range -
/* mmx6/pilot_globals.h -- the declarations the pilot systems player/weapon still repeated per file, all in unit
 * 32208 (hand-edited; Phase 2.5 T10.c5). Not included by x4.h, player.h or object.h (C0331): g_playthrough_state
 * carries other types in non-pilot files (g_Player did until 3.3 T5.c1). The functions stay unprototyped so every caller's
 * argument list fits; clear_object_slot is `s32` as unit 32208 declares it (unit 120A0 has it `void`).
 * Phase 3.3 T5.c1: these are the one declaration spelling every src/ file uses for g_Player, func_8002F288
 * (+func_8002CB50), move_object and func_80030ECC. A return type steers the caller's register allocation
 * (void frees v0 after the call), so a caller whose bytes need the other type casts at its call. */
#ifndef MMX6_PILOT_GLOBALS_H
#define MMX6_PILOT_GLOBALS_H

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/engine_state.h"

extern struct X4_PlayerObj g_Player; // 0x800970A0, the struct at include/mmx6/player.h:15
s32 animate_object();
s32 clear_object_slot();
// defined void at src/main/8002E47C.c:175; s32 because 9 calling functions' bytes need an int return
// (4 need void and cast: 80049670.c:2134, 8004E78C.c:95, :114, item/capsule.c:97)
s32 func_8002F288();
// defined s32 at src/main/8002C9D4.c:68; relocdef alias of func_8002F288 (config/dedup_registry.txt)
s32 func_8002CB50();
// defined void at src/main/object/object_8002D2B0.c:8 (one caller casts to s32: rock_06/800E9860.c:619)
void move_object();
// defined s32 at src/shared/main/func_80030ECC.c:21
s32 func_80030ECC();

#endif /* MMX6_PILOT_GLOBALS_H */
