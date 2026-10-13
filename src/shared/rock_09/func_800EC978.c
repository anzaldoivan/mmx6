#include "common.h"

#define M2C_UNK s32
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
extern u8 D_800F4BF0[];

void func_800EC978(void* arg0) {
    *(u8**)((u8*)arg0 + 0x50) = D_800F4BF0 + 0x1314;
    func_800179A4(arg0, 3);
    ((void (*)())func_80017A04)(arg0);
    *(s32*)((u8*)arg0 + 0x88) = 1;
    *(s16*)((u8*)arg0 + 0x7C) = 0x12C;
    *((u8*)arg0 + 6) += 1;
}
