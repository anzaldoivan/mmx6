#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCF08;

void func_800EA078(void* arg0) {
    if (D_800CCF08 == 0) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        return;
    }
    M2C_FIELD(arg0, s8*, 3) = 0;
}
