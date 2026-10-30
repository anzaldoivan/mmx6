#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_800E9CDC();
s32 func_800E9D20(struct X4_PlayerObj* arg0);

void func_800E9C5C(u8* arg0, struct X4_PlayerObj* arg1) {
    if (func_800E9D20(arg1) != 0) {
        ((void (*)())func_80017A04)(arg0);
        arg0[3] = 1;
        return;
    }
    if (func_800E9CDC(arg1) != 0) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0x13);
        arg0[3] = 1;
        arg0[5] = 1;
        return;
    }
    arg0[3] = 0;
    arg0[5] = 0;
}
