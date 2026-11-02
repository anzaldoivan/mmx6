#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EA480(u8* arg0) {
    s8 t;

    t = arg0[2];
    if (t == 0) {
        set_animation(arg0, 0);
    } else if (t == 1) {
        set_animation(arg0, 0xE);
    }
    arg0[6]++;
}
