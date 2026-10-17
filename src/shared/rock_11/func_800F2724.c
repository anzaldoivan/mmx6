#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800F0050(s32);

void func_800F2724(u8* arg0) {
    arg0[7] = 0;
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        ((void (*)())func_800F0050)();
    }
}
