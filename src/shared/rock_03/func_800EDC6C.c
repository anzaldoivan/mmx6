#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800EDC6C(void* arg0) {
    ((void (*)(void*, s32))func_800179A4)(arg0, 3);
    ((s16*)arg0)[0x7C / 2] = 0;
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}
