#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif
#define SPAD (*(u8**)0x1F80004C)

extern s32 D_80097420;
extern u8 D_800F9B40[];

void func_800F6FC8(void* arg0) {
    if (!(*(u8*)&D_80097420 & 1)) {
        M2C_FIELD(arg0, u16*, 0xE) +=
            (s8)D_800F9B40[M2C_FIELD(SPAD, s8*, 0x8C)];
        M2C_FIELD(SPAD, u8*, 0x8C) = (M2C_FIELD(SPAD, u8*, 0x8C) + 1) & 0xF;
    }
}
