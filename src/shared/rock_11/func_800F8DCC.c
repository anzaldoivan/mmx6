#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F8DCC(u8* arg0) {
    u8 t;

    set_animation(arg0, 1);
    t = arg0[0x8B];
    arg0[0x8B] = 0;
    *(s16*)(arg0 + 0x7C) = 0x1E;
    arg0[0x8C] = t;
    arg0[6]++;
}
