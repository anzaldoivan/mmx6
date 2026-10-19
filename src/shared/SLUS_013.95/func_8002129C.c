#include "common.h"

void func_8002129C(u8* arg0, u8* arg1) {
    u8* self;
    u8* other;
    s8 temp_v0;
    // !FAKE: constant in second arg register
    register s32 one asm("$5");
    // !FAKE: field read in first arg register
    register s32 x asm("$4");
    // !FAKE: constant 8 in v1
    register s32 k8 asm("$3");

    other = arg1;
    self = arg0;
    temp_v0 = *(s8*)(other + 0x8C);
    if (temp_v0 != 0) {
        one = 1;
        if (temp_v0 > 0) {
            x = *(s8*)(self + 0x2);
            k8 = 8;
            *(s16*)(self + 0x54) = 3;
            *(u8*)(self + 0x3) = one;
            *(s16*)(self + 0x56) = k8;
            *(s16*)(self + 0x58) = (5 - x) * 2;
            *(s32*)(self + 0x8) = *(s32*)(other + 0x8);
            *(s32*)(self + 0xC) = *(s32*)(other + 0xC);
            *(u8*)(self + 0x4) = one;
            *(u8*)(self + 0x5) = 0;
            return;
        }
        *(s8*)(other + 0x8C) = 0;
    }
}
