#include "common.h"

s8* func_8002C6F0(s8* arg0, s32 arg1);

void func_800F40F4(u8* arg0, u8 arg1, s16 arg2, s16 arg3) {
    u8* p;

    p = (u8*)func_8002C6F0(0, 1);
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xB;
        p[2] = arg1;
        p[0x15] = arg0[0x15];
        *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
        *(s16*)(p + 0xA) = 0;
        *(u16*)(p + 0x8) = *(u16*)(arg0 + 0x8C);
        *(s16*)(p + 0xE) = 0;
        *(u16*)(p + 0xC) = *(u16*)(arg0 + 0x8E);
        *(s32*)(p + 0x50) = *(s32*)(arg0 + 0x7C);
        *(s16*)(p + 0x54) = arg2;
        *(s16*)(p + 0x56) = arg3;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
    }
}
