#include "common.h"

extern u8 D_800CCF5F;
extern u8 D_800F7620[];

void func_800F4400(u8* arg0) {
    s32 v = D_800F7620[D_800CCF5F];

    arg0[6]++;
    *(s16*)(arg0 + 0x7E) = v;
}
