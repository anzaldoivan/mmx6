#include "common.h"

void func_800F065C(u8* arg0) {
    s32 v;

    if (*(s8*)(arg0 + 0x46) == 0) {
        arg0[6]++;
    }
    v = *(u16*)(arg0 + 0x7C) + 1;
    *(u16*)(arg0 + 0x7C) = v;
    if (!(v & 1)) {
        *(s32*)(arg0 + 0x24) = -*(s32*)(arg0 + 0x24);
    }
}
