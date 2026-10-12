#include "common.h"
#define M2C_UNK s32

extern M2C_UNK D_800F7798;

#define SP_30 (*(u8**)0x1F800030)

void func_800EE3A0(u8* arg0) {
    u8* src;

    arg0[0] |= 8;
    if (*(s8*)(arg0 + 2) == 0) {
        *(s16*)(arg0 + 0x20) = 0xF;
        src = SP_30 + 0x200;
    } else {
        *(s16*)(arg0 + 0x20) = 0x16;
        src = SP_30;
    }
    __builtin_memcpy(&D_800F7798, src, 0x20);
    arg0[4]++;
}

#undef SP_30
