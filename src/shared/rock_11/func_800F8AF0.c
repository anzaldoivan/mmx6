#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F8AF0(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) == 1) {
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        arg0[0x8A] = 0;
        *(s32*)(arg0 + 0x24) = 0xFFF70000;
        *(s32*)(arg0 + 0x20) = 0;
        arg0[6]++;
    }
}
