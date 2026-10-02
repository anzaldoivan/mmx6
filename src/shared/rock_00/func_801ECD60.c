#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_801ECD60(void* arg0) {
    M2C_FIELD(arg0, u8*, 0xE1) = (u8)(M2C_FIELD(arg0, u8*, 0xE1) + 1);
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
