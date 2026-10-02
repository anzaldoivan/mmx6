#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8003D26C(void*);                   /* extern */
s32 func_801EC028();                            /* extern */

void func_80037220(void* arg0) {
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
    temp_v1 = M2C_FIELD(arg0, u8*, 0x45);
    if (temp_v1 & 0x40) {
        M2C_FIELD(arg0, u8*, 0x45) = (u8)(temp_v1 & 0x3F);
        func_8003D26C(arg0);
    }
    if ((s8)M2C_FIELD(arg0, u8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, u8*, 0x45) = (u8)(M2C_FIELD(arg0, u8*, 0x45) & 0x3F);
        func_80016C48(1, 5, arg0);
        M2C_FIELD(arg0, s8*, 0x8C) = 1;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
