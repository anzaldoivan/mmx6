#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA0AC(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x5C), s8*, 1) >= 5) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
