#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);                 /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
extern s8 D_800970A5;
extern s8 D_8009724F;

void func_800EC250(void* arg0) {
    if (D_800970A5 == 0x14) {
        D_8009724F = 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0xA;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_80016C48(5, 1, arg0);
        func_80012D9C(4);
    }
}
