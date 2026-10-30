#include "common.h"

#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK); /* extern */

void func_800EDACC(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0xE);
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}
