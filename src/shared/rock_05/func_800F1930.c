#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);

void func_800F1930(u8* arg0) {
    arg0[0x15] = 0;
    func_800179A4(arg0, 7);
    func_80029478(0x5A, 4, 2);
    *(s16*)(arg0 + 0x7C) = 0x5A;
    func_80016C48(2, 0x22, arg0);
    func_80016C48(2, 2, arg0);
    ((void (*)(s32))func_80012D9C)(4);
    arg0[6]++;
}
