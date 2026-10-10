#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004D6A8(void* arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32*, 0x44) - 1;
    M2C_FIELD(arg0, s32*, 0x44) = temp_v0;
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
