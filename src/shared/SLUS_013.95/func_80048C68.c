#include "common.h"

#define FB_BASE ((s32*)0x801F3000)

void func_80048C68(u8* arg0) {
    s32 t;
    s32 v;

    t = *(s8*)(arg0 + 2);
    arg0[0] = 1;
    arg0[3] = 1;
    arg0[0x15] = 0;
    *(s8*)(arg0 + 0x14) = -1;
    switch (t) {
    case 0:
        arg0[0x16] = 2;
        *(s32*)(arg0 + 0x3C) = FB_BASE[2] + (s32)FB_BASE;
        {
            s32 r = *(s8*)(arg0 + 0x56);
            *(s16*)(arg0 + 0x40) = 0x1E00;
            v = ((r + 8) % 4 + 0x10) | (((r + 8) / 4 + 0x1F0) << 6);
        }
        break;
    case 1: {
        s8 n1;
        arg0[0x16] = 2;
        *(s32*)(arg0 + 0x3C) = FB_BASE[0] + (s32)FB_BASE;
        n1 = *(s8*)(arg0 + 0x56);
        *(s16*)(arg0 + 0x40) = 0x1F00;
        v = ((s8)(n1 % 4) + 0x10) | ((n1 / 4 + 0x1F0) << 6);
    } break;
    case 2:
        goto arm23;
    case 3:
    arm23:
        arg0[0x16] = t;
        *(s32*)(arg0 + 0x3C) = FB_BASE[4] + (s32)FB_BASE;
        {
            s32 r = *(s8*)(arg0 + 0x56);
            *(s16*)(arg0 + 0x40) = 0x1D00;
            v = ((r + 0x18) % 4 + 0x10) | (((r + 0x18) / 4 + 0x1F0) << 6);
        }
        break;
    default:
        arg0[4] = 1;
        arg0[6] = 0;
        return;
    }
    *(s16*)(arg0 + 0x42) = v;
    arg0[4] = 1;
    arg0[6] = 0;
}
