#include "common.h"

#define FB_BASE ((s32*)0x801F3000)

extern u8 D_800CCED3;

void func_80048EC8(u8* arg0) {
    s32 t;

    arg0[0] = 1;
    *(s8*)(arg0 + 0x14) = -1;
    t = arg0[2] & 0xF;
    arg0[0x15] = 0;
    switch (t) {
    case 0: {
        s32 b = (s32)FB_BASE;
        s32 v;
        arg0[0x16] = 2;
        v = FB_BASE[5];
        *(s16*)(arg0 + 0x40) = 0x1F00;
        *(s16*)(arg0 + 0x42) = 0x7C10;
        *(s32*)(arg0 + 0x3C) = v + b;
        arg0[0x47] = D_800CCED3;
        arg0[5] = 0;
    } break;
    case 1: {
        s32 b = (s32)FB_BASE;
        s32 v;
        arg0[0x16] = 2;
        v = FB_BASE[2];
        *(s16*)(arg0 + 0x40) = 0x1E00;
        *(s16*)(arg0 + 0x42) = 0x7C92;
        arg0[0x47] = t;
        arg0[5] = t;
        *(s32*)(arg0 + 0x3C) = v + b;
    } break;
    case 2: {
        s32 b = (s32)FB_BASE;
        s32 v;
        arg0[0x16] = t;
        v = FB_BASE[2];
        *(s16*)(arg0 + 0x40) = 0x1E00;
        *(s16*)(arg0 + 0x42) = 0x7C92;
        arg0[0x47] = 0x32;
        arg0[5] = t;
        *(s32*)(arg0 + 0x3C) = v + b;
    } break;
    }
    arg0[4]++;
}
