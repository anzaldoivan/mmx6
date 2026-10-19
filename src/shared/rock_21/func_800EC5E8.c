#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C530(); /* extern */

void func_800EC5E8(void* arg0) {
    s32 var_v0;
    u16 temp_v0;
    void* temp_v0_2;
    s32 one;

    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x28) {
        M2C_FIELD(arg0, u16*, 4) = 0U;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        temp_v0_2 = func_8002C530();
        one = 1;
        if (temp_v0_2 != 0) {
            M2C_FIELD(temp_v0_2, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_2, s8*, 0) = one;
            M2C_FIELD(temp_v0_2, s8*, 2) = one;
            M2C_FIELD(temp_v0_2, s16*, 0xA) = 0x100;
            M2C_FIELD(temp_v0_2, s16*, 0xE) = 0x40;
        }
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
