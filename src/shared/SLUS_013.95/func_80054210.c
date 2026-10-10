#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_80097424;

void func_80054210(void* arg0) {
    if (D_80097424 == 0) {
        M2C_FIELD(arg0, s8*, 0x14) = 0;
        M2C_FIELD(arg0, s8*, 0x15) = 0;
        M2C_FIELD(arg0, s8*, 0x16) = 0;
        M2C_FIELD(arg0, s8*, 4) = 1;
        M2C_FIELD(arg0, s8*, 5) = 0;
    }
}
