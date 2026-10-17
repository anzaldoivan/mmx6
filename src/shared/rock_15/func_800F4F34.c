#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04(); /* extern */

void func_800F4F34(u8* arg0) {
    // !FAKE: pin keeps the decremented counter in the first return register
    register s32 temp asm("$2");

    func_80017A04();
    temp = *(u16*)(arg0 + 0x8C) - 1;
    *(u16*)(arg0 + 0x8C) = temp;
    if ((temp << 16) == 0) {
        arg0[4] = 2;
    }
}
