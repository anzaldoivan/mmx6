#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4CBC(void* arg0) {
    M2C_FIELD(arg0, u8*, 5) = (u8)M2C_FIELD(arg0, u8*, 0x94);
}
