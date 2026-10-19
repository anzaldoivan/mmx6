#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif
#define SPAD (*(u8**)0x1F80004C)

extern u8 D_800CCF5F;

void func_800F5F80(void* arg0) {
    if (M2C_FIELD(SPAD, u8*, 0x8A) != 0x11) {
        M2C_FIELD(arg0, u8*, 0x5) = 0xE;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        return;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    if (D_800CCF5F == 0) {
        M2C_FIELD(arg0, s16*, 0x7E) = 1;
    } else if (D_800CCF5F == 1) {
        M2C_FIELD(arg0, s16*, 0x7E) = 2;
    } else if (D_800CCF5F == 2) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
    } else {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFC0000;
    M2C_FIELD(arg0, u8*, 0x6)++;
}
