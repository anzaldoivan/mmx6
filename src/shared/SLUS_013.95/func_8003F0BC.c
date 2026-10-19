#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8003C4EC(struct X4_PlayerObj* self);
M2C_UNK func_8003D510(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3);

M2C_UNK func_8003F0BC(void* arg0) {
    s8 v;

    func_8003C4EC(arg0);
    v = ((s8*)arg0)[0x93];
    if (v == 1) {
        func_8003D510(1, 0x1B, 0, 0);
    } else if (v == 6) {
        func_8003D510(1, 0x1B, 0xA, 0);
    } else if (v == 8) {
        func_8003D510(1, 0x1B, 0xC, 0);
    }
}
