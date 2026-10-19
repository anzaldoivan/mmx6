#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F0718(u8* arg0) {
    s8 v;

    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x100, 0x100);
    v = arg0[2];
    if (v == 1) {
        arg0[3] = v;
    }
}
