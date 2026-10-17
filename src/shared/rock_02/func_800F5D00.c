#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F5D00(u8* arg0) {
    func_800179A4(arg0, 6);
    func_80016C48(2, 0x22, arg0);
    arg0[6]++;
}
