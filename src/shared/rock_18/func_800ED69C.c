#include "common.h"

extern void* D_800E2F9C;

s32 func_800ED69C(u8 arg0) {
    s32 s;
    // !FAKE: pin to the target register
    register u32* p asm("$3");

    s = arg0 & 7;
    p = D_800E2F9C;
    p += arg0 >> 3;
    return ((p[0x11] >> (s * 4)) & 0xF) == 2;
}
