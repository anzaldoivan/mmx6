#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC458(void* arg0) {
    s32 var_v0;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x438) {
        M2C_FIELD(arg0, u16*, 4) = 0U;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
