#include "common.h"

s8* func_8002C5F0(s8* p, s32 back);
extern u8 D_800FBFD4[];

void func_800F1FD0(s8* arg0) {
    s8* p;
    s32 t;

    p = func_8002C5F0(arg0, 0);
    if (p != 0) {
        t = *(u8*)(arg0 + 0);
        p[1] = 7;
        p[2] = 1;
        p[0] = t;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
        t = *(u8*)(arg0 + 0x14);
        p[0x16] = 6;
        p[0x14] = t;
        {
            s32 a = *(u16*)(arg0 + 0xA);
            *(s16*)(p + 8) = 0;
            *(u16*)(p + 0xA) = a;
        }
        {
            s32 e = *(u16*)(arg0 + 0xE);
            *(s16*)(p + 0xC) = 0;
            *(u16*)(p + 0xE) = e;
        }
        *(s32*)(p + 0x50) = *(s32*)(arg0 + 0x50);
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
        p[0x47] =
            (D_800FBFD4 + *(s16*)(arg0 + 0x54) * 2)[0] + *(u8*)(arg0 + 0x56);
        p[0x15] = (D_800FBFD4 + *(s16*)(arg0 + 0x54) * 2)[1];
    }
}
