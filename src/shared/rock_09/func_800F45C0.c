#include "common.h"

void func_800F45C0(u8* arg0) {
    if (++*(s16*)(arg0 + 0x7C) == 0x32) {
        *(s32*)(arg0 + 0x2C) = 0x10000;
        arg0[6] = arg0[6] + 1;
    }
}
