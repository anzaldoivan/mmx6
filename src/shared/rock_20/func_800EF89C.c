#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_80097424[];
#define D_80097424 (*(s8*)&D_80097424)

void func_800EF89C(void* arg0) {
    if (D_80097424 == 0) {
        M2C_FIELD(arg0, s8*, 1) = 5;
        M2C_FIELD(arg0, s8*, 2) = 2;
    }
}
#undef D_80097424
