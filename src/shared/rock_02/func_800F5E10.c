#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800F5E10(u8* arg0) {
    play_sound(2, 0x23, arg0);
    ((void (*)(void*, s32))set_animation)(arg0, 7);
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[6] = arg0[6] + 1;
}
