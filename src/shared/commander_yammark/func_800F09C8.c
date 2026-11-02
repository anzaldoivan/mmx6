#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
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
        ang = ratan2(y - H(arg0, 0xE), x - H(arg0, 0xA));
        W(arg0, 0x20) = rcos(ang) * 32;
        W(arg0, 0x24) = -rsin(ang) * 32;
    }
    if (W(arg0, 0x20) != 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 2);
    } else {
        t = W(arg0, 0x24);
        if (t > 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 3);
        } else if (t < 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 4);
        }
    }
    UB(arg0, 6)++;
}
