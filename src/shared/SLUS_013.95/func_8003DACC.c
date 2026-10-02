#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003DACC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD7) != 0) {
        M2C_FIELD(arg0, s8*, 0xD7) = (s8)((u8)M2C_FIELD(arg0, s8*, 0xD7) - 1);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 3;
    M2C_FIELD(arg0, s8*, 5) = 0;
}
