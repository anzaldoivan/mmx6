#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)

void func_800F493C(void* arg0) {
    B(arg0, 0x3) = 0;
    if (--H(arg0, 0x88) == 0) {
        B(arg0, 0x4)++;
    }
}
