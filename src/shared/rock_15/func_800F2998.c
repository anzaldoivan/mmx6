#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F2998(s8* arg0) {
    if (arg0[7] == 0) {
        func_800179A4(arg0, 5);
        func_80016C48(2, 0x14, arg0);
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
    }
}
