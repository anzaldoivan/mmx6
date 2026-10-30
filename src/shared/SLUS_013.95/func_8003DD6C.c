#include "common.h"
#define M2C_UNK s32
s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_8003F480();
extern s8 D_800CCEEC;
extern s8 D_80073ED8[];
extern s8 D_80073EE4[];
extern s8 D_80073EF0[];

#define B(o) (*(s8*)((u8*)self + (o)))
#define UB(o) (*(u8*)((u8*)self + (o)))
#define UH(o) (*(u16*)((u8*)self + (o)))

void func_8003DD6C(void* self) {
    s32 a;
    s32 m;
    s8 i;
    s8 k;

    if (B(0xD3) != 0) {
        return;
    }
    if (B(0x99) != 0) {
        return;
    }
    if (B(0xD5) != 0) {
        return;
    }
    if (B(0xE0) != 0) {
        return;
    }
    if (D_800CCEEC != 0) {
        return;
    }
    k = B(0x5);
    if (k == 0x2D) {
        return;
    }
    if (k == 0x2E) {
        return;
    }
    if (k == 0x2F) {
        return;
    }
    if (k == 0x4C) {
        return;
    }
    a = UH(0x7C) & 0x600;
    m = UH(0x80) & 0x600;
    if (a == 0x600 || m == 0x600) {
        if (B(0x93) != 0) {
            UB(0x93) = 0;
            func_8003F480(self);
            play_sound(0, 0xC, 0);
        }
    } else if (m != 0) {
        i = D_80073EF0[B(0x93)];
        if (m & 0x200) {
            do {
                i++;
                if (i == 9) {
                    i = 0;
                    break;
                }
            } while (!(D_80073ED8[i] & UB(0xC9)));
        } else {
            do {
                i--;
                if (i < 0) {
                    i = 8;
                }
                if (i == 0) {
                    break;
                }
            } while (!(D_80073ED8[i] & UB(0xC9)));
        }
        i = D_80073EE4[i];
        if (B(0x93) != i) {
            B(0x93) = i;
            func_8003F480(self);
            play_sound(0, 0xC, 0);
        }
    }
}
