#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_800E9CDC();
s32 func_800E9D20(struct X4_PlayerObj* arg0);

void func_800E9B5C(u8* arg0, struct X4_PlayerObj* arg1) {
    if (func_800E9CDC(arg1) != 0) {
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0x13);
        arg0[3] = 1;
        arg0[5] = 1;
        return;
    }
    if (func_800E9D20(arg1) != 0) {
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0x14);
        arg0[3] = 1;
        arg0[5] = 2;
    }
}
