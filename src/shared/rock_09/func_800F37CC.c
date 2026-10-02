#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);                   /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);   /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800F37CC(void* arg0) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
        goto block_4;
    }
    if (temp_v0 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
    block_4:
        if (var_v0 != 0) {
            func_80016C48(2, 0x3F, arg0);
            func_80012D9C(3);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
        }
    }
    if (M2C_FIELD(arg0, s32*, 0x20) == 0) {
        func_80029478(0x5A, 2, 3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 6) = 5;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) + 1);
    }
}
