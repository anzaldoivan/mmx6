#include "common.h"
#define M2C_UNK s32

#define SPAD4C (*(u8**)0x1F80004C)

extern s32 D_80097420;
#define D_80097420 (*(u8*)&D_80097420)
extern u8 D_800FBA30[];

M2C_UNK func_800F82C0(void* arg0) {
    if (!(D_80097420 & 1)) {
        *(u16*)((u8*)arg0 + 0xE) += (s8)D_800FBA30[(s8)SPAD4C[0x8C]];
        SPAD4C[0x8C] = (SPAD4C[0x8C] + 1) & 0xF;
    }
}

#undef D_80097420
#undef SPAD4C
