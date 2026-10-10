#include "common.h"

void func_800EBEF4(u8* arg0) {
    s32 temp_v0;

    temp_v0 = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = temp_v0;
    if ((temp_v0 << 0x10) == 0) {
        *(u16*)(arg0 + 0x7C) = 0x14;
        arg0[6]++;
    }
}
