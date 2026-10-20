#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();

void func_800F27B0(void* arg0) {
    ((void (*)(s32, s32, void*))func_80016C48)(2, (func_8002D2D4() & 1) | 0x22,
                                               arg0);
    ((void (*)(void*, s32))func_800179A4)(arg0, 1);
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}
