#include "common.h"
#define M2C_UNK s32

#define SPAD_28_B3D4 (*(s32*)0x1F800028)

void memcpy(s32, M2C_UNK*, s32);
extern u8 D_800C4560;

// 0x8002B3D4 load_palette: on-the-fly palette load.
// basis: community tweaks-index.tsv:381
// callers: func_80013D10, func_80022838, func_80022928, func_8003C4EC and others
M2C_UNK load_palette(M2C_UNK arg0, M2C_UNK* arg1, M2C_UNK arg2) {
    memcpy(SPAD_28_B3D4 + (arg0 << 5), arg1, arg2 << 5);
    D_800C4560 |= 1;
}

#undef SPAD_28_B3D4
