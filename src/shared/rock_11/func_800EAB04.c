#include "common.h"

void* func_8002C458();

#define A ((u8*)arg0)

void func_800EAB04(void* arg0) {
    u8* p;
    u8 b;
    u16 h;

    p = func_8002C458();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 6;
        b = A[0x15];
        p[2] = 0;
        p[0x15] = b;
        h = *(u16*)(A + 0xA);
        *(u16*)(p + 0x8) = 0;
        *(u16*)(p + 0xA) = h;
        h = *(u16*)(A + 0xE);
        *(u16*)(p + 0xC) = 0;
        *(u16*)(p + 0xE) = h;
        *(u16*)(p + 0x42) = *(u16*)(A + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(A + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(A + 0x3C);
        *(u16*)(p + 0x40) = *(u16*)(A + 0x40);
        p[0x14] = A[0x14];
    }
}
#undef A
