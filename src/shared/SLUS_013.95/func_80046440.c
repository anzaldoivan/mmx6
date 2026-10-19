#include "common.h"

void func_80046440(u8* arg0) {
    s32 v;

    v = arg0[0x8E] + 1;
    arg0[0x8E] = v;
    arg0[3] = v & 1;
    if ((s8)v >= 0x14) {
        arg0[4] = 3;
    }
}
