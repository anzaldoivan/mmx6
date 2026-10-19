#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)

void func_800F24E4(void* arg0) {
    if (--H(arg0, 0x7C) == 0) {
        SB(arg0, 0x7) = -1;
        B(arg0, 0x6)++;
    }
}
