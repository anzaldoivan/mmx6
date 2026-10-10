#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001A5F8(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
}
