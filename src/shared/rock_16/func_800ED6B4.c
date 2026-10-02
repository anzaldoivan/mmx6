#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_8008EAFC;

void func_800ED6B4(void* arg0) {
    if (D_8008EAFC == 0) {
        M2C_FIELD(arg0, s8*, 0x43B) = 1;
        M2C_FIELD(arg0, s8*, 1) = 3;
        M2C_FIELD(arg0, s8*, 2) = 0;
    }
}
