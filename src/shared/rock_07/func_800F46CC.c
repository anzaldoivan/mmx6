#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F46CC(u8* arg0) {
    s8 t = arg0[0x45];

    if (t == 1) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 6);
        arg0[6]++;
    } else if (t == 2) {
        func_80016C48(2, 0x5D, arg0);
    }
}
