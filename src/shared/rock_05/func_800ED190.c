#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800ED190(void* arg0) {
    s32 x = D_800970AA;

    if (M2C_FIELD(arg0, s16*, 0xA) < x) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x10000;
        M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        return;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0xFFFF0000;
    M2C_FIELD(arg0, s32*, 0x28) = 0x1000;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = 3;
}
