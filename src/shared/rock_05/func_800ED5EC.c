#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED5EC(void* arg0) {
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 8) >= 2U) {
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
}
