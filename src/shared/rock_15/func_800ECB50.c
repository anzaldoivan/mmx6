#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);

void func_800ECB50(void* arg0) {
    if ((u8)--M2C_FIELD(arg0, u8*, 0x8C) == 0 &&
        M2C_FIELD(arg0, u8*, 0x91) == 0) {
        register s32 one asm("$3") = 1;
        M2C_FIELD(arg0, s32*, 0x28) = 0x3000;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, u8*, 0x91) = one;
        M2C_FIELD(arg0, u8*, 0x8D) = 0x28;
        func_80016C48(2, 0x58, arg0);
        M2C_FIELD(arg0, u8*, 0x5)++;
    }
    if (M2C_FIELD(arg0, s8*, 0x2) != 0 && M2C_FIELD(arg0, u8*, 0x8C) < 0x15 &&
        M2C_FIELD(arg0, s32*, 0x24) != 0) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
}
