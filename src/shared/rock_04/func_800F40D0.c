#include "common.h"

extern s8 D_800970A2;
extern u8 D_800CCF5F;
extern u8 D_800F75F0[][4];

void func_800F40D0(u8* arg0) {
    s16 v = D_800F75F0[D_800970A2][D_800CCF5F];
    arg0[6] = arg0[6] + 1;
    *(s16*)(arg0 + 0x7E) = v;
}
