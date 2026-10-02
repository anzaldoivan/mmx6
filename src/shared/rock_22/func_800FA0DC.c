#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA0DC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) >= 2) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 7) = 0;
    }
}
