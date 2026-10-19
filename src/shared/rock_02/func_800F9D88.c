#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F9D88(u8* arg0) {
    if (((s8*)arg0)[0x45] == 1) {
        func_800179A4(arg0, 2);
        func_80016C48(2, 0x66, arg0);
        arg0[5]++;
    }
}
