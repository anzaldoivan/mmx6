#include "common.h"

extern u8 D_800ED098[];

void func_800E9B1C(u8* arg0) {
    arg0[0x14] = 0;
    *(u8**)(arg0 + 0x18) = (((s8*)arg0)[2] << 4) + D_800ED098;
    arg0[4] = arg0[4] + 1;
}
