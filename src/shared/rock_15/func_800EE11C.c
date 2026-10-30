#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EE11C(void* arg0) {
    ((void (*)())set_animation)(arg0, 0xA);
    ((u8*)arg0)[3] = 1;
    ((u8*)arg0)[5] = ((u8*)arg0)[5] + 1;
}
