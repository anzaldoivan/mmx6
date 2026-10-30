#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F90C8;
extern s32 D_800F90CC;

void func_800F6578(u8* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0x1A);
    *(s32**)(arg0 + 0x50) = &D_800F90C8;
    *(s32**)(arg0 + 0x54) = &D_800F90CC;
    arg0[6]++;
}
