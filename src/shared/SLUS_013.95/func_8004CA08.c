#include "common.h"

extern u16 D_800782C0[];
extern u16 D_800782D4[][8];
extern u16 D_80078374[][8];
extern u16 D_80078444;
void func_8004D0B0(u8*, u8, u8, u16*);

#define B(o) (*(s8*)(p + (o)))
#define UB(o) (*(u8*)(p + (o)))
#define H(o) (*(u16*)(p + (o)))

void func_8004CA08(u8* p) {
    u8* q;
    u32 i;
    s32 c;
    u16 d;
    u16 x;
    u16* t;

    switch (B(5)) {
    case 0:
        B(5) = 1;
        H(0xA) = 0;
        H(0x16) = D_800782C0[B(7)];
        H(0x2E) = D_800782C0[B(7)];
        H(0x1E) = D_800782C0[B(7)] + 0x3F;
        H(0x26) = D_800782C0[B(7)] + 0x3F;
        H(0xE) = 0;
        if (B(7) < 5) {
            H(0x1A) = 0;
            H(0x22) = 0;
            H(0x2A) = 0;
            H(0x32) = 0;
        } else {
            H(0x1A) = 0xF0;
            H(0x22) = 0xF0;
            H(0x2A) = 0xF0;
            H(0x32) = 0xF0;
        }
        B(0x55) = 1;
        B(0x54) = 1;
        B(0x4C) = 0;
        B(0x4D) = 0;
        B(0x4E) = 0;
        B(0x4F) = 0;
        H(0x50) = 8;
        break;
    case 1:
        i = 0;
        q = p + 0x38;
        for (; i < 4; i++) {
            func_8004D0B0(p, UB(7), i, &D_800782D4[B(7)][i * 2]);
        }
        c = H(0x50) - 1;
        *(u16*)(q + 0x18) = c;
        if (!(c & 0xFFFF)) {
            t = D_800782D4[B(7)];
            H(0x16) = *t++;
            H(0x1A) = *t++;
            H(0x1E) = *t++;
            H(0x22) = *t++;
            H(0x26) = *t++;
            H(0x2A) = *t++;
            H(0x2E) = *t++;
            H(0x32) = *t++;
            B(5) = 2;
            B(0x55) = 1;
            B(0x54) = 1;
            B(0x4C) = 0;
            B(0x4D) = 0;
            B(0x4E) = 0;
            B(0x4F) = 0;
            H(0x50) = 8;
        }
        break;
    case 2:
        i = 0;
        q = p + 0x38;
        for (; i < 4; i++) {
            func_8004D0B0(p, UB(7), i, &D_80078374[B(7)][i * 2]);
        }
        c = H(0x50) - 1;
        *(u16*)(q + 0x18) = c;
        if (!(c & 0xFFFF)) {
            t = D_80078374[B(7)];
            H(0x16) = *t++;
            H(0x1A) = *t++;
            H(0x1E) = *t++;
            H(0x22) = *t++;
            H(0x26) = *t++;
            H(0x2A) = *t++;
            H(0x2E) = *t++;
            x = *t;
            B(5) = 3;
            B(0x55) = 1;
            B(0x54) = 1;
            B(0x4C) = 0;
            B(0x4D) = 0;
            B(0x4E) = 0;
            B(0x4F) = 0;
            d = D_80078444;
            H(0x50) = 0x10;
            H(0x32) = x;
            if (d != 0) {
                D_80078444 = d - 1;
            }
        }
        break;
    case 3:
        *(u8*)(*(u8**)(p + 0x58) + 0x14) = 0;
        B(4) = 2;
        B(5) = 0;
        break;
    }
}

#undef B
#undef UB
#undef H
