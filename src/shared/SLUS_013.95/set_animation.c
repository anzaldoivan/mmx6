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
