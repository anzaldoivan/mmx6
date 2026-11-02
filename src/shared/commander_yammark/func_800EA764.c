#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800CCF38;

void func_800EA764(u8* arg0) {
    s8 t;

    t = arg0[2];
    if (t == 0) {
        set_animation(arg0, 5);
    } else if (t == 1) {
        set_animation(arg0, 0x13);
    }
    if (D_800CCF38 >= 2) {
        *(s16*)(arg0 + 0x7C) = 0x2D;
    } else {
        *(s16*)(arg0 + 0x7C) = 0x5A;
    }
    arg0[6]++;
}
