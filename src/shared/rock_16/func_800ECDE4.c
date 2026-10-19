#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
extern s8 D_800CCF01;

void func_800ECDE4(u8* arg0) {
    if ((s16)++ * (u16*)(arg0 + 8) >= 8) {
        *(u16*)(arg0 + 8) = 0;
        D_800CCF01 = 0;
        ((void (*)(s32))func_800139F4)(8);
        arg0[2]++;
    }
}
