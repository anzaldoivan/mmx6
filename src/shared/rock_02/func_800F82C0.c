// rolefeed (3.1 T4): func_800F82C0 of src/rock_02/E9860.c

#include "common.h"
#define M2C_UNK s32

#define SPAD4C (*(u8**)0x1F80004C)

#include "mmx6/state.h"
extern u8 D_800FBA30[];

M2C_UNK func_800F82C0(void* arg0) {
    if (!(*(u8*)&D_80097420 & 1)) {
        *(u16*)((u8*)arg0 + 0xE) += (s8)D_800FBA30[(s8)SPAD4C[0x8C]];
        SPAD4C[0x8C] = (SPAD4C[0x8C] + 1) & 0xF;
    }
}
