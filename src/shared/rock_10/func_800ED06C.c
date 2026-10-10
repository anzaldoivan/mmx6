#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ED06C(void* arg0) {
    u8 temp_v1;
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_a0, s8*, 4) == 4) {
        return 0;
    }
    temp_v1 = M2C_FIELD(temp_a0, u8*, 0x89);
    if (temp_v1 == 1) {
        return 1;
    }
    return temp_v1 != 0;
}
