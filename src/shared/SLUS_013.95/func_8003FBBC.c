#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BA04(void*, M2C_UNK);

void func_8003FBBC(void* arg0) {
    ((void (*)(void*, s32))func_8003BA04)(arg0, 0x5F);
    ((u8*)arg0)[0x67] = 1;
    ((u8*)arg0)[5] = 0x2B;
    ((u8*)arg0)[6] = 0;
}
