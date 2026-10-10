#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800757DC;

void func_800FA110(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 0;
    if (M2C_FIELD(arg0, u8*, 0x92) != 0) {
        M2C_FIELD(arg0, u8*, 0x92) = 0U;
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800757DC;
        M2C_FIELD(arg0, s8*, 3) = 1;
    }
}
