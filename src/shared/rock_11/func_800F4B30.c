#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4B30(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        return;
    }
    M2C_FIELD(arg0, s8*, 0x16) = 7;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}
