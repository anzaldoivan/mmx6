#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_800EA480(s8* arg0);

void func_800FA3A8(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        func_800139F4(8);
        func_80016C48(0, 8, 0);
        arg0[1]++;
    }
}
