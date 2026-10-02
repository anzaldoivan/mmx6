#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EC240(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x80) = (s32)(M2C_FIELD(arg0, s32*, 0x80) + 0x18000);
    if (M2C_FIELD(arg0, s16*, 0x82) >= 0xD0) {
        func_80016C48(2, 0x48, arg0);
        M2C_FIELD(arg0, s16*, 0x82) = 0xD0;
        M2C_FIELD(arg0, s8*, 7) = 4;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
