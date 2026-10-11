#include "common.h"

void* func_8002C458();

void func_800F6AD0(u8* arg0, u8 arg1) {
    u8* p;

    p = func_8002C458();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x16;
        p[2] = arg1;
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        p[0x15] = arg0[0x15];
        p[0x14] = arg0[0x14];
        *(u16*)(p + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(p + 0x8) = 0;
        *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE);
        *(u16*)(p + 0xC) = 0;
        *(s32*)(p + 0x7C) = *(s32*)(arg0 + 0x80);
        *(u8**)(p + 0x8C) = arg0;
        arg0[7] = 1;
    }
}
