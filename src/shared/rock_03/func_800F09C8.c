#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern s16 D_800F7DC0;
extern s16 D_800F7DC2;
extern s16 D_800F7DCA;
extern s16 D_800F7DCC;
extern s16 D_800F7DCE;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F09C8(void* arg0) {
    s16 x;
    s16 y;
    s16 ang;
    s32 t;

    if (H(arg0, 0xA) < (D_800F7DC0 + D_800F7DC2) / 2) {
        x = D_800F7DCA;
        UB(arg0, 0x15) = 0x40;
    } else {
        x = D_800F7DCC;
        UB(arg0, 0x15) = 0;
    }
    y = D_800F7DCE;
    H(arg0, 0x7E) = 0;
    if (H(arg0, 0xA) == x && H(arg0, 0xE) == y) {
        W(arg0, 0x20) = 0;
        W(arg0, 0x24) = 0;
    } else {
        ang = func_80065B74(y - H(arg0, 0xE), x - H(arg0, 0xA));
        W(arg0, 0x20) = func_80065A14(ang) * 32;
        W(arg0, 0x24) = -func_80065944(ang) * 32;
    }
    if (W(arg0, 0x20) != 0) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 2);
    } else {
        t = W(arg0, 0x24);
        if (t > 0) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 3);
        } else if (t < 0) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 4);
        }
    }
    UB(arg0, 6)++;
}
