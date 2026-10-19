#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800ECD24(u8* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) - 1;
        return;
    }
    if (M2C_FIELD(arg0, s32*, 0x20) <= -0x20000) {
        M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        ((void (*)(s32, s32, void*))func_80016C48)(2, 0x18, arg0);
        ((void (*)(s32))func_80012D9C)(3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        ((void (*)(s32, s32, s32))func_8002943C)(0x3C, 2, 1);
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}
