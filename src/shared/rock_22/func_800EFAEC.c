#include "common.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

s32 func_8002D654(s8*, u8*);
extern s8 D_800950A0[];
extern u8 D_800FC004[][8];
extern s16 D_800FC084[][3];

s32 func_800EFAEC(u8* arg0) {
    s8* p;
    s16 dx;
    s16 dy;
    s32 t;
    u8 idx;
    // !FAKE: depin: dropping it breaks the match (113/118)
    register s32 sub asm("$4");
    // !FAKE: depin: dropping it breaks the match (114/118)
    register s32 k asm("$2");

    for (p = D_800950A0; p < D_800950A0 + 0x1400; p += 0xA0) {
        if (p[0] == 0 || p[1] != 0x4F) {
            continue;
        }
        if (M2C_FIELD(arg0, u16*, 0x84) == M2C_FIELD(p, u16*, 0x8C)) {
            continue;
        }
        if (func_8002D654(p, arg0) == 0) {
            continue;
        }
        if (M2C_FIELD(p, s8*, 0x98) != 0) {
            return 0;
        }
        if (M2C_FIELD(arg0, u8*, 0x8A) == 0) {
            dy = 0;
            t = M2C_FIELD(arg0, s8*, 2) & 0xF0;
            sub = M2C_FIELD(arg0, u8*, 2);
            dx = 0;
            if (t == 0x30 || t == 0x40) {
                idx = D_800FC004[M2C_FIELD(arg0, u8*, 0x88)]
                                [M2C_FIELD(p, s32*, 0x84)];
                if (idx != 0xFF) {
                    dx = D_800FC084[idx][1];
                    dy = D_800FC084[idx][2];
                } else {
                    goto zero;
                }
            } else if (t == 0x30) {
            zero:
                dx = 0;
            } else if (t == 0x50) {
                dx = 0x1E;
                k = (sub & 0xF) - 4;
                if ((u32)k < 2) {
                    dy = -8;
                } else {
                    dx = -8;
                    dy = -0x1E;
                }
            }
            M2C_FIELD(p, s8*, 0x98) = 2;
            M2C_FIELD(p, s16*, 0xA) = dx + M2C_FIELD(arg0, s16*, 0xA);
            M2C_FIELD(p, s16*, 0xE) = dy + M2C_FIELD(arg0, s16*, 0xE);
        } else {
            M2C_FIELD(p, s8*, 0x98) = 1;
            M2C_FIELD(arg0, u8*, 0x8A) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x86) = M2C_FIELD(p, u8*, 0x84);
        return 1;
    }
    return 0;
}
