// prog SLUS_013.95 | system state | range -
/* mmx6/state.h -- the main loop's state block, D_80097420 0x80097420..0x8009742B, 0xC bytes (hand-edited; Phase 2.5
 * T7). Homed here from the generated include/mmx6/x4.h through config/x4/homed.tsv: x4.h never emits these blocks
 * and aliases X4_TransitionState to TransitionState and X4_MainBssState to MainBssState, so `struct X4_...` users
 * are unchanged. Members, types and names of mmx4's TransitionState and MainBssState (x4.h at 807a01b). */
#ifndef MMX6_STATE_H
#define MMX6_STATE_H

#include "common.h"

// The screen transition (fade) state, MainBssState +0x04 (docs/types/state.md).
// DC7 notes: `+0xNN read by|written by <fn>|unreferenced`, held to the census by objfields.py --check.
struct TransitionState {
    s8 active; // +0x00 read by exit_stage_from_menu
    s8 fade_amount; // +0x01 read by func_80053B6C
    s8 suspended; // +0x02 read by start_pad_vibration
    u8 selection; // +0x03 read by func_8001F0C8
};

// The state block (0xC bytes): the frame counter the main loop increments, the transition, the character mode.
struct MainBssState {
    s32 frame_counter; // +0x00 read by func_80021694
    struct TransitionState transition; // +0x04 read by exit_stage_from_menu
    u8 character_mode; // +0x08 read by func_80022960
    u8 alignment_padding[3]; // +0x09 unreferenced
};

// The head keeps its placeholder name (frame_counter is held). Views that keep a byte spelling: docs/types/state.md.
extern struct MainBssState D_80097420;

#endif /* MMX6_STATE_H */
