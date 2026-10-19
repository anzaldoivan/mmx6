#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED1D8(void* arg0) {
    void* parent;
    s32 v;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) - 0xA4;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) + 0xA4;
    }
    M2C_FIELD(arg0, u8*, 0x3) = 1;
    v = M2C_FIELD(arg0, s8*, 0x45) * 0x10;
    M2C_FIELD(arg0, s8*, 0x8C) = 0x7F - v;
    M2C_FIELD(arg0, s8*, 0x8E) = v;
    if (M2C_FIELD(arg0, s32*, 0x84) != M2C_FIELD(parent, s8*, 0x6)) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = M2C_FIELD(arg0, u8*, 0x7) + 1;
    }
}
