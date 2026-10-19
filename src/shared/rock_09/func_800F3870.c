#include "common.h"

void func_800F3870(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 0x7C) + 1;
    *(u16*)(arg0 + 0x7C) = t;
    if ((s16)t == 0x3C) {
        arg0[6] = 3;
    }
}
