#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
extern s8 D_800CCEF6;
extern u8 D_800F366C[];

void func_800EF060(u8* arg0) {
    s32 i;
    u8* t = D_800F366C + 4;
    u8* p;
    i = D_800CCEF6 - 1;
    p = t;
    p -= -(i * 6);
    ((void (*)(s32, s32, s32))func_80021760)(*(u16*)(p + 2), 0xFF, 0);
    arg0[2]++;
}
