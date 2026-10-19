#include "common.h"

void func_800F56CC(u8* arg0) {
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    if (*(s8*)(arg0 + 2) == 0x20) {
        *(s32*)(arg0 + 0x24) = 0x100000;
    } else {
        *(s32*)(arg0 + 0x24) = 0xFFF00000;
    }
    *(s16*)(arg0 + 0x88) = 8;
    arg0[6] = arg0[6] + 1;
}
