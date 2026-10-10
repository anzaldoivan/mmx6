#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
extern u8 D_800CCF38;

void func_800F0014(void* arg0) {
    s32 var_a0;

    var_a0 = 0xFFFE0000;
    if ((M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x5C) < 4) ||
        ((u8)D_800CCF38 >= 2U)) {
        M2C_FIELD(arg0, s16*, 0x80) = 0xA;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            var_a0 = 0x20000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = var_a0;
        if (M2C_FIELD(arg0, s8*, 3) != 0) {
            func_80016C48(2, 0xC, arg0);
        }
        M2C_FIELD(arg0, u8*, 7) = (u8)(M2C_FIELD(arg0, u8*, 7) + 1);
    }
}
