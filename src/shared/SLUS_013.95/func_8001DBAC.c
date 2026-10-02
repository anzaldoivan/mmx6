#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_80097424;

void func_8001DBAC(void* arg0) {
    if (D_80097424 == 0) {
        M2C_FIELD(arg0, s8*, 0) = 3;
        M2C_FIELD(arg0, s8*, 1) = 0;
        M2C_FIELD(arg0, s8*, 2) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
    }
}
