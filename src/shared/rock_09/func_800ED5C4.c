#include "common.h"

extern s8 D_8008EAB0;
extern s8 D_800CCEED;
extern s32 D_800F6BA4;

#define SCRATCH_30 (*(u8**)0x1F800030)

void func_800ED5C4(u8* arg0) {
    u8* p;

    if (D_800CCEED == 3) {
        D_8008EAB0 = 1;
    }
    arg0[0] |= 8;
    p = SCRATCH_30;
    __builtin_memcpy(&D_800F6BA4, p + 0x200, 0x20);
    *(u8**)(arg0 + 0x20) = p + 0x460;
    arg0[4]++;
}

#undef SCRATCH_30
