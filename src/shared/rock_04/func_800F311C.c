#include "common.h"

void func_800F311C(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(u16*)(arg0 + 0x7C) = 4;
        *(s32*)(arg0 + 0x50) = 0;
        arg0[5]++;
    }
}
