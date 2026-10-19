#include "common.h"
#define M2C_UNK s32

extern u8 D_8008EAFC;
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_80051B28(u8* arg0) {
    if (D_8008EAFC == 1) {
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xB);
        arg0[6] = 0;
        arg0[5]++;
    }
}
