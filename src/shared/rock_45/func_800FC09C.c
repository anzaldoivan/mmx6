#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800FC09C(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        if (M2C_FIELD(arg0, s32*, 0x24) != 0) {
            ((void (*)(s32, s32, void*))func_80016C48)(2, 0x42, arg0);
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 6);
        ((void (*)(s32, s32, void*))func_80016C48)(2, 0x44, arg0);
        ((void (*)(s32))func_80012D9C)(6);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
