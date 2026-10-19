#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800EE11C(void* arg0) {
    ((void (*)())func_800179A4)(arg0, 0xA);
    ((u8*)arg0)[3] = 1;
    ((u8*)arg0)[5] = ((u8*)arg0)[5] + 1;
}
