#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EBF58(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x82) = 0xA0;
    M2C_FIELD(arg0, s16*, 0x86) = -0x40;
    func_80016C48(2, 0x45, arg0);
    M2C_FIELD(arg0, s8*, 0x8F) = 2;
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
