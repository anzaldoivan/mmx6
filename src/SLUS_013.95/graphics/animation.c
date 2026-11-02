#include "common.h"
#define M2C_UNK s32

// 0x800179A4 set_animation: animation trigger; table at +0x30.
// basis: community tweaks-index.tsv:191
// callers: func_80020AA8, func_80021194, func_80040CB0, func_80040E3C and others
M2C_UNK set_animation(void* arg0, M2C_UNK arg1) {
    s32* temp_a2;

    temp_a2 = (*(s32***)((u8*)arg0 + 0x30))[arg1];
    *((u8*)arg0 + 0x48) = 0xFF;
    *((u8*)arg0 + 0x17) = arg1;
    *(s32**)((u8*)arg0 + 0x34) = temp_a2;
    *(s32*)((u8*)arg0 + 0x44) = *temp_a2;
}

#include "common.h"
#define M2C_UNK s32

// 0x800179D0 set_animation_frame: points an object's animation cursor at entry arg1 of its table plus arg2.
// basis: code src/shared/SLUS_013.95/set_animation_frame.c:11 via=arg1
// callers: func_801EEA8C, func_801F30B0, func_800F2884
M2C_UNK set_animation_frame(void* arg0, M2C_UNK arg1, s32 arg2) {
    u8* p = arg0;
    s32* temp_a3;

    temp_a3 = (*(s32***)(p + 0x30))[arg1];
    p[0x48] = 0xFF;
    p[0x17] = arg1;
    temp_a3 += arg2;
    *(s32**)(p + 0x34) = temp_a3;
    *(s32*)(p + 0x44) = *temp_a3;
}
