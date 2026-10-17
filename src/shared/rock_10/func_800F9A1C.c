#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
extern M2C_UNK D_800FC758;
extern M2C_UNK D_800FC75C;

void func_800F9A1C(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x88) == 1) {
        func_800179A4(arg0, 0x1A);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC758;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC75C;
        M2C_FIELD(arg0, u8*, 5)++;
    }
}
