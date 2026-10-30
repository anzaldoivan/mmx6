#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F3AC4(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = t;
    if ((t << 0x10) == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 0x53);
        arg0[6] = 1;
    }
}
