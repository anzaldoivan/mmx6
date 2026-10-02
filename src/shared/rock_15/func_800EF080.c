#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800F636C;
extern M2C_UNK D_800F6370;

void func_800EF080(void* arg0) {
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F636C;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F6370;
    if (M2C_FIELD(arg0, u8*, 0x8C) != 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = NULL;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = NULL;
    }
}
