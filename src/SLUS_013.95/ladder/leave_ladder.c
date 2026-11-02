#include "common.h"
#define M2C_UNK s32

s32 func_8003015C();
void func_8003B6B4(void*);
void player_enter_ladder_step_off_bottom(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);

// 0x8003A514 try_leave_ladder: while climbing: steps off at the floor, tops out on tile 0x21, or falls when off the ladder tiles or on a button.
// basis: xref player_enter_ladder_step_off_bottom (docs/leads/derived.tsv:19)
// callers: func_80037610, func_80037704
s32 try_leave_ladder(u8* arg0) {
    s32 v;
    s32 t;

    v = func_8003015C(arg0);
    if (arg0[0x89] & 8) {
        player_enter_ladder_step_off_bottom(arg0);
        return 1;
    }
    if ((*(u16*)(arg0 + 0x7C) & 4) && v == 0x21) {
        func_8003B6B4(arg0);
        return 1;
    }
    t = (u8)(v - 0x20) >= 2;
    if (*(u16*)(arg0 + 0x80) & 0x80) {
        t = 1;
    }
    if (t != 0) {
        func_8003BA04(arg0, 0x1E);
        arg0[5] = 0xE;
        arg0[6] = 4;
        return 1;
    }
    return 0;
}
