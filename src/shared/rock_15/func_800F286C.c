#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);                   /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);   /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800F1DA8(void*, M2C_UNK, M2C_UNK);   /* extern */

void func_800F286C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        func_80016C48(2, 0x14, arg0);
        func_80016C48(2, 0x76, arg0);
        func_800F1DA8(arg0, 6, 2);
        func_800F1DA8(arg0, 7, 2);
        func_80029478(0x78, 2, 2);
        M2C_FIELD(arg0, s8*, 7) = 2;
        M2C_FIELD(arg0, s8*, 0x8B) = 1;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_80012D9C(9);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
}
