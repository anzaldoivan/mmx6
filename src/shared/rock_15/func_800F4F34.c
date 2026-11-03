#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */

void func_800F4F34(u8* arg0) {
    // !FAKE: pin keeps the decremented counter in the first return register
    register s32 temp asm("$2");

    animate_object();
    temp = *(u16*)(arg0 + 0x8C) - 1;
    *(u16*)(arg0 + 0x8C) = temp;
    if ((temp << 16) == 0) {
        arg0[4] = 2;
    }
}
