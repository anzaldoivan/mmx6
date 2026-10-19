#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCF08;

void func_800EA09C(void* arg0) {
    s32 v = D_800CCF08;

    if (v == 1) {
        M2C_FIELD(arg0, s8*, 3) = v;
        return;
    }
    M2C_FIELD(arg0, s8*, 3) = 0;
}
