#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800FD004;

void func_800F9A80(u8* arg0) {
    s32 temp_v0;

    temp_v0 = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = temp_v0;
    if ((temp_v0 << 0x10) == 0) {
        D_800FD004 = 8;
        ((void (*)(void*, s32))set_animation)(arg0, 0x1B);
        arg0[5]++;
    }
}
