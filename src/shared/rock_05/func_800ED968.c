#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);                 /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8003D330();                        /* extern */
extern s32 D_80097420;

void func_800ED968(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7E) == 0) {
        func_80016C48(0, 0xE, 0);
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
    }
    if (!(D_80097420 & 1)) {
        if (++M2C_FIELD(arg0, s8*, 0x5C) == 0x7F) {
            func_8003D330();
            M2C_FIELD(arg0, u8*, 5) = 6;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x1000;
            M2C_FIELD(arg0, u8*, 6) = 4;
            func_80016C48(5, 1, arg0);
            func_80012D9C(4);
        }
    }
}
