#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
extern u8 D_80097427;

void func_800EF838(u8* arg0) {
    switch (D_80097427) {
    case 0:
    default:
        arg0[1] = 0xB;
        arg0[2] = 0;
        arg0[3] = 0;
        break;
    case 1:
        ((void (*)(s32))func_800139F4)(8);
        arg0[2]++;
        break;
    }
}
