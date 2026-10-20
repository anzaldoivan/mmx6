#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800EEB9C(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = t;
    if ((t << 0x10) == 0) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 8);
        arg0[6] = arg0[6] + 1;
    }
}
