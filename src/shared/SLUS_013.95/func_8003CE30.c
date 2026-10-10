#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003CE30(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xA1) = 0;
}
