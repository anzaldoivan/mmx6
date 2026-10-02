#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();      /* extern */
M2C_UNK func_8002D2B0(s32); /* extern */

void func_800F9B30(void* arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;

    func_80017A04();
    func_8002D2B0(arg0);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
        goto block_8;
    }
    if (temp_v0 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
        goto block_8;
    }
    temp_v0_2 = M2C_FIELD(arg0, s32*, 0x24);
    if (temp_v0_2 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 4;
        goto block_8;
    }
    if (temp_v0_2 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 8;
    block_8:
        if (var_v0 != 0) {
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    }
}
