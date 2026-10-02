#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FD2AC(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 4;
    M2C_FIELD(arg0, s8*, 6) = 0;
}
