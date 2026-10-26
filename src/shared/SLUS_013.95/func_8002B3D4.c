#include "common.h"
#define M2C_UNK s32

#define SPAD_28_B3D4 (*(s32*)0x1F800028)

void memcpy(s32, M2C_UNK*, s32);
extern u8 D_800C4560;

M2C_UNK func_8002B3D4(M2C_UNK arg0, M2C_UNK* arg1, M2C_UNK arg2) {
    memcpy(SPAD_28_B3D4 + (arg0 << 5), arg1, arg2 << 5);
    D_800C4560 |= 1;
}

#undef SPAD_28_B3D4
