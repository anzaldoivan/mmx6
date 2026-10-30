#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800F46CC(u8* arg0) {
    s8 t = arg0[0x45];

    if (t == 1) {
        ((void (*)(void*, s32))set_animation)(arg0, 6);
        arg0[6]++;
    } else if (t == 2) {
        play_sound(2, 0x5D, arg0);
    }
}
