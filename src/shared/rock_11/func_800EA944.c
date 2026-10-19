#include "common.h"

void func_800EA944(u8* arg0) {
    s32 v;

    v = arg0[0x15];
    if (v != 0) {
        v = 0x20000;
    } else {
        v = 0xFFFE0000;
    }
    *(s32*)(arg0 + 0x20) = v;
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    *(s16*)(arg0 + 0x7C) = 0x14;
    arg0[6]++;
}
