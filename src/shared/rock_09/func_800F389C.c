#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);                   /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);   /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800F389C(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 4) {
        func_80016C48(2, 0x3F, arg0);
        func_80012D9C(3);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        func_80029478(0x5A, 2, 3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 6) = 7;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) + 1);
    }
}
