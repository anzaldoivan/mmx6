#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_80097202;

void func_800297BC(void* arg0) {
    M2C_FIELD(arg0, s16*, 0xA) =
        (s16)(D_80097202 + M2C_FIELD(arg0, u16*, 0x40));
}
