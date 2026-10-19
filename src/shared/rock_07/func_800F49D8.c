#include "common.h"

void func_800F49D8(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x2C) = 0x4000;
        arg0[6]++;
    }
}
