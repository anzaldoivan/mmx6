// prog SLUS_013.95 | system engine_state | range -
/* mmx6/engine_state.h -- g_playthrough_state 0x800CCED0 for the pilot files (hand-edited; Phase 2.5 T10.c5).
 * Apart from pilot_globals.h because unit 120A0 (object/layer.c) types g_Player `s32`. Not included by x4.h
 * (C0331): other files type g_playthrough_state otherwise. */
#ifndef MMX6_ENGINE_STATE_H
#define MMX6_ENGINE_STATE_H

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

#endif /* MMX6_ENGINE_STATE_H */
