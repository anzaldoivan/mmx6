#include "common.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

void* alloc_sprite_slot();
extern s8 D_800F0F00[];
extern s8 D_800F0F08[];
extern u8 D_800F1CA9;
extern u8 D_800F1CF0[];

void func_800EAEF8(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (89/98)
    register s32 tbl asm("$2");
    s32 idx;
    s8* p;
    s8* o;
    s32 a;
    s32 b;
    s32 n;

    if (D_800F1CA9 >= 9) {
        tbl = (s32)D_800F0F08;
        idx = FX(arg0, s16, 0xA) * 2;
    } else {
        tbl = (s32)D_800F0F00;
        idx = FX(arg0, s16, 0xA) * 2;
    }
    p = (s8*)(idx + tbl);
    a = *p;
    {
        s32 j = idx + 1;
        b = *(s8*)(j + tbl);
    }
    do {
    } while (0);
    if (FX(arg0, s16, 0x8) == 0) {
        o = alloc_sprite_slot(p);
        if (o != 0) {
            o[0] = 1;
            o[1] = 0xC;
            o[2] = a | 0x20;
        }
        if (b != -1) {
            o = alloc_sprite_slot();
            if (o != 0) {
                o[0] = 1;
                o[1] = 0xC;
                o[2] = b | 0x20;
            }
        }
    }
    FX(arg0, s16, 0x8)++;
    if (FX(arg0, s16, 0x8) >= 4) {
        D_800F1CF0[a] = 0;
        if (b != -1) {
            D_800F1CF0[b] = 0;
        }
        FX(arg0, s16, 0x8) = 0;
        n = (u16)FX(arg0, s16, 0xA) + 1;
        FX(arg0, s16, 0xA) = n;
        if (D_800F1CA9 >= 9) {
            if ((s16)n >= 5) {
                goto block;
            }
            return;
        }
        if ((s16)n >= 4) {
        block:
            FX(arg0, s16, 0xA) = 0;
            FX(arg0, u8, 0x2)++;
        }
    }
}
