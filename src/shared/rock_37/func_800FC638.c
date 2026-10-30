#include "common.h"
#define M2C_UNK s32

void set_animation(void*, M2C_UNK);

void func_800FC638(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0);
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}
