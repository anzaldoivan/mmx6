#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_800F7DC0;
extern s16 D_800F7DC2;
extern s16 D_800F7DCA;
extern s16 D_800F7DCC;
extern s16 D_800F7DCE;
extern s16 D_800F7DD0;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F1334(void* arg0) {
    s16 x;
    s16 y;
    s16 ang;

    if (H(arg0, 0xA) < (D_800F7DC0 + D_800F7DC2) / 2) {
        x = D_800F7DCA;
        UB(arg0, 0x15) = 0x40;
    } else {
        x = D_800F7DCC;
        UB(arg0, 0x15) = 0;
    }
    y = D_800F7DD0;
    H(arg0, 0x7E) = 1;
    if (H(arg0, 0xA) == x && H(arg0, 0xE) == y) {
        W(arg0, 0x20) = 0;
        W(arg0, 0x24) = 0;
    } else {
        ang = ratan2(y - H(arg0, 0xE), x - H(arg0, 0xA));
        W(arg0, 0x20) = rcos(ang) * 32;
        W(arg0, 0x24) = -rsin(ang) * 32;
    }
    if (W(arg0, 0x20) != 0) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 2);
    } else {
        s32 v = W(arg0, 0x24);
        if (v > 0) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 3);
        } else if (v < 0) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 4);
        }
    }
    UB(arg0, 6)++;
}
