#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
s32 func_800EA480(s8* arg0);

void func_800FA4D0(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        ((void (*)(s32))func_800139F4)(8);
        arg0[1]++;
    }
}
