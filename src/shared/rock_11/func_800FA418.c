#include "common.h"

s8* func_8002C6F0(s8* arg0, s32 arg1);

void func_800FA418(void* arg0) {
    u8* a = (u8*)arg0;
    u8* p;

    p = (u8*)func_8002C6F0((s8*)arg0, 0);
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xA;
        p[2] = 0x21;
        p[0x15] = a[0x15];
        *(s32*)(p + 0x30) = *(s32*)(a + 0x30);
        p[0x14] = a[0x14];
        *(u16*)(p + 0xA) = *(u16*)(a + 0xA);
        *(s16*)(p + 0x8) = 0;
        *(u16*)(p + 0xE) = *(u16*)(a + 0xE);
        *(s16*)(p + 0xC) = 0;
        *(void**)(p + 0x50) = arg0;
        *(u16*)(p + 0x40) = *(u16*)(a + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(a + 0x42) & 0x7FFF;
        *(s32*)(p + 0x3C) = *(s32*)(a + 0x3C);
    }
}
