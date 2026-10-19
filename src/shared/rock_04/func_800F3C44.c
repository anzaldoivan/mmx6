#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F3C44(void* arg0) {
    ((void (*)(void*, s32))func_800179A4)(arg0, 9);
    ((s16*)arg0)[0x7C / 2] = 0x14;
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}
