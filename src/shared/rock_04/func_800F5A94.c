#include "common.h"

void* func_8002C458();

void func_800F5A94(void* arg0, u8 arg1) {
    u8* s = arg0;
    u8* d;

    d = func_8002C458();
    if (d != 0) {
        d[0] = 0x41;
        d[1] = 0x14;
        d[2] = arg1;
        *(u16*)(d + 0x42) = *(u16*)(s + 0x42) & 0x7FFF;
        *(s32*)(d + 0x30) = *(s32*)(s + 0x30);
        *(s32*)(d + 0x3C) = *(s32*)(s + 0x3C);
        *(u16*)(d + 0x40) = *(u16*)(s + 0x40);
        d[0x15] = s[0x15];
        d[0x14] = s[0x14];
        *(u16*)(d + 0xA) = *(u16*)(s + 0xA);
        *(u16*)(d + 0x8) = 0;
        *(u16*)(d + 0xE) = *(u16*)(s + 0xE);
        *(u16*)(d + 0xC) = 0;
        *(s32*)(d + 0x7C) = *(s32*)(s + 0x7C);
    }
}
