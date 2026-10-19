#include "common.h"

void func_8003D598(void* arg0) {
    u8* p = arg0;
    s32 k0 = 0x20000;
    // !FAKE: register order of a shared constant
    register s32 k1 asm("$2") = 0x4200;
    s32 k2 = 0x5D000;
    // !FAKE: register order of a shared constant
    register s32 k3 asm("$8") = 0xFFF98000;
    // !FAKE: register order of a shared constant
    register s32 k4 asm("$9") = 0x68000;
    // !FAKE: register order of a shared constant
    register s32 k5 asm("$11") = 0x42000;
    // !FAKE: register order of a shared constant
    register s32 k6 asm("$10") = 0xFFFE9000;
    // !FAKE: register order of a shared constant
    register s32 k7 asm("$7") = 0x5A000;
    s32 k8 = 0x18000;

    *(s32*)(p + 0xF0) = 0x8000;
    *(s32*)(p + 0xF4) = k0;
    *(s32*)(p + 0x134) = k1;
    *(s32*)(p + 0x100) = k1;
    *(s32*)(p + 0x10C) = -0x3000;
    *(s32*)(p + 0xF8) = k2;
    *(s32*)(p + 0xFC) = k3;
    *(s32*)(p + 0x104) = k4;
    *(s32*)(p + 0x108) = k5;
    *(s32*)(p + 0x110) = k6;
    *(s32*)(p + 0x114) = k7;
    *(s32*)(p + 0x118) = 0x10000;
    *(s32*)(p + 0x11C) = k8;
    *(s32*)(p + 0x120) = k0;
    *(s32*)(p + 0x124) = k0;
    *(s32*)(p + 0x128) = k8;
    *(s32*)(p + 0x12C) = k5;
    *(s32*)(p + 0x130) = k5;
}
