#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern s32 D_800761A4;

void func_80046478(u8* arg0) {
    ((void (*)())func_80017A04)();
    if (*(s8*)(arg0 + 0x45) & 0x80) {
        *(s32**)(arg0 + 0x50) = &D_800761A4;
        arg0[5] = arg0[5] + 1;
    }
}
