#include "common.h"

void func_800ECDC0(u8* arg0) {
    arg0[0x8C] = 0;
    *(s32*)(arg0 + 0x20) = 0xFFFF0000;
    *(s32*)(arg0 + 0x24) = 0xFFFF0000;
    *(s32*)(arg0 + 0x28) = 0x1000;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[6] = 3;
}
