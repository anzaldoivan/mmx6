#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_800F2B4C();

void func_800F1CE8(u8* arg0) {
    ((void (*)())func_80017A04)();
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        func_800F2B4C(arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 6);
        arg0[6]++;
    }
}
