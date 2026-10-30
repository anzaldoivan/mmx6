#include "common.h"
#define M2C_UNK s32
s32 play_sound(s32 a0, s32 a1, void* arg2);
extern s8 D_800CCEEC;
extern s8 D_80073EC0[];
extern s8 D_80073EC8[];
extern s8 D_80073ED0[];

#define B(o) (*(s8*)((u8*)self + (o)))
#define UB(o) (*(u8*)((u8*)self + (o)))
#define UH(o) (*(u16*)((u8*)self + (o)))

// 0x8003DBDC switch_weapon: weapon menu-select input.
// basis: community tweaks-index.tsv:221
// callers: func_8003F048
void switch_weapon(void* self) {
    s32 a;
    s32 m;
    u16 h;
    s8 i;

    if (B(0xD3) != 0) {
        return;
    }
    if (B(0xD5) != 0) {
        return;
    }
    if (D_800CCEEC != 0) {
        return;
    }
    h = UH(0x80);
    m = h & 0x600;
    if (m == 0) {
        return;
    }
    a = UH(0x7C) & 0x600;
    if (a == 0x600 || m == 0x600) {
        if (B(0x93) != 0) {
            UB(0x93) = 0;
            play_sound(0, 0xC, 0);
        }
    } else {
        i = D_80073ED0[B(0x93)];
        if (h & 0x200) {
            do {
                i++;
                if (i == 6) {
                    i = 0;
                    break;
                }
            } while (!(D_80073EC0[i] & UB(0xC9)));
        } else {
            do {
                i--;
                if (i < 0) {
                    i = 5;
                }
                if (i == 0) {
                    break;
                }
            } while (!(D_80073EC0[i] & UB(0xC9)));
        }
        i = D_80073EC8[i];
        if (i != B(0x93)) {
            B(0x93) = i;
            play_sound(0, 0xC, 0);
        }
    }
}
