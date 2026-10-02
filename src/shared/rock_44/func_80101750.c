#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_80101750(void* arg0) {
    u8 temp_v1;
    u8 var_v0;
    void* temp_s0;

    temp_s0 = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())func_80017A04)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(temp_v1 - 1);
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 9) {
        var_v0 = M2C_FIELD(temp_s0, u8*, 0x8A) & 0xF0;
    } else {
        var_v0 = M2C_FIELD(temp_s0, u8*, 0x8A) & 0xF;
    }
    M2C_FIELD(temp_s0, u8*, 0x8A) = var_v0;
    M2C_FIELD(arg0, s8*, 4) = 2;
}
