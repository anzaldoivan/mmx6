#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
#define SCRATCH_24 (*(s32*)0x1F800024)

void func_80048584(void* arg0, s32 arg1) {
    load_palette(1, (s32*)(SCRATCH_24 + ((arg1 + 0x39) << 5)), 1);
}
