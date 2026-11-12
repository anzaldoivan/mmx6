#include "common.h"

extern u8 D_800F0F88[][3];
extern u8 D_800F1024[][3];

#define SPAD20 (*(s32**)0x1F800020)

void func_800EFDE4(u8* p) {
    s32 b;
    s32* sp;
    p[0] = 1;
    p[3] = 0;
    p[0x15] = 0;
    switch (((s8)p[2]) & 0xF0) {
    case 0xF0:
        *(s16*)(p + 0x40) = 0x1F00;
        *(s32*)(p + 0x3C) = (s32)SPAD20 + SPAD20[3];
        *(s16*)(p + 0x42) = 0x78C4;
        switch (p[2] & 0xF) {
        case 0:
            p[5] = 2;
            break;
        case 1:
            p[5] = 3;
            break;
        case 2:
            p[5] = 4;
            break;
        case 3:
        case 4:
            p[5] = 5;
            break;
        }
        break;
    case 0xE0:
        *(s16*)(p + 0x40) = 0x1F00;
        *(s32*)(p + 0x3C) = (s32)SPAD20 + SPAD20[3];
        *(s16*)(p + 0x42) = 0x78C4;
        p[5] = 8;
        break;
    case 0xD0:
        *(s16*)(p + 0x40) = 0x1F00;
        *(s32*)(p + 0x3C) = (s32)SPAD20 + SPAD20[3];
        *(s16*)(p + 0x42) = 0x78C4;
        p[5] = 9;
        break;
    case 0:
        b = 0x1900;
        *(s16*)(p + 0x40) = b;
        sp = SPAD20;
        b = sp[1];
        *(s32*)(p + 0x3C) = (s32)sp + b;
        *(s16*)(p + 0x42) = (D_800F1024[p[2]][1] & 0xF) |
                            (((D_800F1024[p[2]][1] >> 4) + 0x1E0) << 6);
        p[0x47] = D_800F1024[p[2]][2];
        p[5] = D_800F1024[p[2]][0];
        break;
    default:
        b = 0x1F00;
        *(s16*)(p + 0x40) = b;
        sp = SPAD20;
        b = sp[3];
        *(s32*)(p + 0x3C) = (s32)sp + b;
        *(s16*)(p + 0x42) = (D_800F1024[p[2]][1] & 0xF) |
                            (((D_800F1024[p[2]][1] >> 4) + 0x1E0) << 6);
        p[0x47] = D_800F1024[p[2]][2];
        p[5] = D_800F1024[p[2]][0];
        break;
    }
    *(u8**)(p + 0x30) = (u8*)D_800F0F88;
    p[0x16] = 0;
    *(s8*)(p + 0x14) = -1;
    p[4] = 1;
    p[6] = 0;
}

#undef SPAD20
