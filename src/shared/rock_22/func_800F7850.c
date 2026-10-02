#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D2B0(s32); /* extern */

void func_800F7850(void* arg0) {
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_v0;
    u8 temp_v0;
    void* temp_s1;

    temp_v0 = M2C_FIELD(arg0, u8*, 0x8E);
    temp_s1 = M2C_FIELD(arg0, void**, 0x84);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = (u8)(temp_v0 - 1);
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
    }
    func_8002D2B0(arg0);
    temp_v0_2 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0_2 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
        goto block_12;
    }
    if (temp_v0_2 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
        goto block_12;
    }
    temp_v0_3 = M2C_FIELD(arg0, s32*, 0x24);
    if (temp_v0_3 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 4;
        goto block_12;
    }
    if (temp_v0_3 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 8;
    block_12:
        if (var_v0 != 0) {
            if (M2C_FIELD(temp_s1, s16*, 0x7C) != 0) {
                M2C_FIELD(arg0, u8*, 0x8E) = 0x28U;
            }
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
        }
    }
}
