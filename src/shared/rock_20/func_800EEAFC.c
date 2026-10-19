#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139A0(M2C_UNK);
extern u8 D_800CD40C;

void func_800EEAFC(u8* arg0) {
    if (D_800CD40C == 2) {
        ((void (*)(s32))func_800139A0)(8);
        arg0[2]++;
    }
}
