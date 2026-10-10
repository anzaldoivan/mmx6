#include "common.h"

void func_800EE698(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = t;
    if ((t << 16) == 0) {
        *(u16*)(arg0 + 0x7C) = 2;
        arg0[6]++;
    }
}
