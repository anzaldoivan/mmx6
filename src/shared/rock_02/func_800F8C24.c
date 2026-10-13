#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();

void func_800F8C24(u8* arg0) {
    ((void (*)())func_80017A04)();
    if (arg0[0x8D]++ >= 0x3D) {
        *(s32*)(arg0 + 0x54) = 0;
        *(s32*)(arg0 + 0x50) = 0;
        arg0[0x8D] = 0x28;
        arg0[6]++;
    }
}
