#include "common.h"

#ifndef M2C_UNK
#define M2C_UNK s32
#endif

M2C_UNK func_800139A0(M2C_UNK); /* extern */

void func_800E9B68(u8* arg0) {
    register s32 temp asm("$2");

    func_800139A0(8);
    temp = arg0[1] + 1;
    arg0[1] = temp;
}
