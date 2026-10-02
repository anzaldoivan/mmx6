#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void* D_800F9878;

void func_800F75D8(void* arg0) {
    if ((M2C_FIELD(M2C_FIELD(arg0, void**, 0x8C), s8*, 4) != 3) ||
        (M2C_FIELD(D_800F9878, s8*, 0x45) < (M2C_FIELD(arg0, u8*, 2) & 0xF))) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}
