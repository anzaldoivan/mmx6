#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED258(void* arg0) {
    M2C_FIELD(arg0, s8*, 4) = 2;
}
