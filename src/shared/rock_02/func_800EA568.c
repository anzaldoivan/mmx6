#include "common.h"
#define M2C_UNK s32

#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800EA568(u8* arg0) {
    play_sound(2, 1, arg0);
    *(s32*)(arg0 + 0x24) = 0x1000;
    *(s32*)(arg0 + 0x2C) = 0x2000;
    set_animation(arg0, 3);
    SPAD4C[0x82] = 2;
    arg0[6]++;
}
