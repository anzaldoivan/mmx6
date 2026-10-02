#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */

void func_800F3064(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
        return;
    }
    func_800179A4(arg0, 2);
    func_80016C48(2, 0x26, arg0);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
