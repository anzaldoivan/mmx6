#include "common.h"

void func_800EA0E0(u8* arg0) {
    *(s32*)(arg0 + 0x48) += 0x51EB;
    if (*(s16*)(arg0 + 0x4A) >= 0x28) {
        *(s16*)(arg0 + 0x4A) = 0x28;
        arg0[6]++;
    }
    *(s16*)(arg0 + 0x16) = *(s16*)(arg0 + 0x42) - *(s16*)(arg0 + 0x4A);
    *(s16*)(arg0 + 0x1A) = *(s16*)(arg0 + 0x46);
    *(s16*)(arg0 + 0x1E) = *(s16*)(arg0 + 0x42) + *(s16*)(arg0 + 0x4A);
    *(s16*)(arg0 + 0x22) = *(s16*)(arg0 + 0x46);
    *(s16*)(arg0 + 0x26) = *(s16*)(arg0 + 0x3A) + *(s16*)(arg0 + 0x4A);
    *(s16*)(arg0 + 0x2A) = *(s16*)(arg0 + 0x3E);
    *(s16*)(arg0 + 0x2E) = *(s16*)(arg0 + 0x3A) - *(s16*)(arg0 + 0x4A);
    *(s16*)(arg0 + 0x32) = *(s16*)(arg0 + 0x3E);
}
