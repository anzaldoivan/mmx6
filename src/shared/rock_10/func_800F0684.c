#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F0684(u8* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 2);
    arg0[6]++;
}
