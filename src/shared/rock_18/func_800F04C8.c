#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_8006D5F9;

void func_800F04C8(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    if (D_8006D5F9 != 0) {
        M2C_FIELD(arg0, s8*, 0x47) = 9;
        return;
    }
    M2C_FIELD(arg0, s8*, 0x47) = 7;
}
