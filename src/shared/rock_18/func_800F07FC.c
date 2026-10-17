#include "common.h"

extern s16 D_800CCED4;

void func_800F07FC(u8* arg0) {
    s8 v = arg0[2];
    s32 one;

    if (v >= 0x10) {
        arg0[3] = 1;
        return;
    }
    one = 1;
    if (D_800CCED4 == one) {
        if (v >= 0) {
            if (v < 2 || v == 0xF) {
                arg0[3] = one;
            } else {
                arg0[3] = 0;
            }
        } else {
            arg0[3] = 0;
        }
    } else if (D_800CCED4 == 2 && v == 0xA) {
        arg0[3] = 0;
    } else {
        arg0[3] = one;
    }
}
