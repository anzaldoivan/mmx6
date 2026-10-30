#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);

#define PAL_BUF (*(u8**)0x1F800024)

void func_8003CF24(s32 arg0, s32 arg1, s32 arg2) {
    load_palette(arg1, (s32*)(PAL_BUF + (arg0 << 5)), arg2);
}
#undef PAL_BUF
