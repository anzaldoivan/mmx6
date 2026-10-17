#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern M2C_UNK D_8007433C;

void func_800F53D4(u8* arg0) {
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    func_800179A4(arg0, 8);
    func_80016C48(2, 0x21, arg0);
    *(s32*)(arg0 + 0x50) = 0;
    *(s32**)(arg0 + 0x58) = &D_8007433C;
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[6]++;
}
