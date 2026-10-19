#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800E4190;

s32 func_80030834(struct X4_PlayerObj* arg0, s16 arg1, s16 arg2, s32 arg3) {
    s16 d;

    D_800E4190 = 1;
    if (arg0->air_state != 0) {
        if ((arg3 == 0) && ((arg1 & 0xF) < arg2)) {
            return 0;
        }
    }
    arg0->unk70 = 8;
    d = arg1 - (arg2 + (arg1 & ~0xF));
    arg0->y_pos.i.lo = 0;
    arg0->y_pos.i.hi -= d;
    return -1;
}
