#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_8009728E;

void func_800EC56C(void* arg0) {
    M2C_FIELD(arg0, s16*, 0xE) = (s16)(0x2F8 - D_8009728E);
}
