#include "common.h"
s32 func_800179A4(void*, s32);

void func_800EE7C8(u8* arg0) {
    u8* p;

    p = *(u8**)(arg0 + 0x50);
    *(u8*)(arg0 + 0x14) = *(u8*)(p + 0x14);
    *(u16*)(arg0 + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(arg0 + 0xE) = *(u16*)(p + 0xE);
    *(u16*)(arg0 + 0x42) = *(u16*)(p + 0x42);
    *(u16*)(arg0 + 0x40) = *(u16*)(p + 0x40);
    *(s32*)(arg0 + 0x3C) = *(s32*)(p + 0x3C);
    *(s32*)(arg0 + 0x30) = *(s32*)(p + 0x30);
    if (*(s8*)(arg0 + 2) == 0) {
        func_800179A4(arg0, 3);
        arg0[5] = 0;
    } else {
        ((void (*)(void*, s32))func_800179A4)(arg0, 4);
        arg0[5] = 2;
    }
    arg0[4]++;
}
