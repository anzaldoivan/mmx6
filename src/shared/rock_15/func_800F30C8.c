#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800F1DA8(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800F30C8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_80016C48(2, 0x71, arg0);
        func_800F1DA8(arg0, 0xB, 3);
        func_800F1DA8(arg0, 0xC, 3);
        M2C_FIELD(arg0, s16*, 0x8E) = 0;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) - 1);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
