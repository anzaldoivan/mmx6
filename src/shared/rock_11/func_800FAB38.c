#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
extern u16 D_80097222;
extern M2C_UNK D_800FD48C;

void func_800FAB38(void* arg0) {
    func_80016C48(2, 0x4C, arg0);
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FD48C;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFF00000;
    M2C_FIELD(arg0, s16*, 0xE) = (s16)(D_80097222 - 0x20);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
