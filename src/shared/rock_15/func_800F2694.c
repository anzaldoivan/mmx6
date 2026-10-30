#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F2694(u8* arg0) {
    set_animation(arg0, 4);
    *(s16*)(arg0 + 0x86) = 0x12C;
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[6]++;
}
