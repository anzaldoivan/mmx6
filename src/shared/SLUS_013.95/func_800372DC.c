#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039FFC(void*);     /* extern */
M2C_UNK func_8003B30C(void*); /* extern */
M2C_UNK func_8003D26C(void*); /* extern */
s32 func_801EC028();          /* extern */

void func_800372DC(void* arg0) {
    u8 temp_v1;

    if ((M2C_FIELD(arg0, s8*, 2) != 0) && (func_801EC028() != 0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = -1;
        M2C_FIELD(arg0, s8*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = (s32)M2C_FIELD(arg0, s32*, 0x100);
        return;
    }
    if (func_80039FFC(arg0) != 0) {
        func_8003B30C(arg0);
        return;
    }
    temp_v1 = M2C_FIELD(arg0, u8*, 0x45);
    if (temp_v1 & 0x40) {
        M2C_FIELD(arg0, u8*, 0x45) = (u8)(temp_v1 & 0x3F);
        func_8003D26C(arg0);
    }
}
