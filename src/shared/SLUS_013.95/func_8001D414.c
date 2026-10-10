#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001D414(void* arg0) {
    M2C_FIELD(arg0, s8*, 0) = 1;
    M2C_FIELD(arg0, s8*, 1) = 0;
}
