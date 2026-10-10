#include "common.h"

void func_800EAAA4(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = t;
    if ((s16)t == -1) {
        *(s32*)(arg0 + 0x24) = 0x30000;
        arg0[5]++;
    }
}
