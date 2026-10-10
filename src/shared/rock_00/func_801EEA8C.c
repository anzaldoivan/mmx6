#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_800179D0(void*, M2C_UNK, s8);      /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_801EEA8C(void* arg0) {
    u8 temp_v0;
    u8 temp_v0_2;
    void* temp_a0;

    if (M2C_FIELD(arg0, s8*, 5) == 0) {
        temp_v0 = M2C_FIELD(arg0, u8*, 0x8C);
        temp_a0 = arg0 + 0x8C;
        if (temp_v0 == 0) {
            if (M2C_FIELD(arg0, s8*, 2) != 0) {
                func_800179D0(arg0, 3, M2C_FIELD(arg0, s8*, 0x45));
            } else {
                func_800179A4(arg0, 0x1F);
            }
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s8*, 5) = 1;
        } else {
            M2C_FIELD(arg0, u8*, 0x8C) = (u8)(temp_v0 - 1);
            temp_v0_2 = M2C_FIELD(temp_a0, u8*, 1);
            if (temp_v0_2 == 0) {
                M2C_FIELD(temp_a0, u8*, 1) = 8U;
                M2C_FIELD(arg0, u8*, 0x64) =
                    (u8)(M2C_FIELD(arg0, u8*, 0x64) + 1);
            } else {
                M2C_FIELD(temp_a0, u8*, 1) = (u8)(temp_v0_2 - 1);
            }
        }
        goto block_12;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 3;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        return;
    }
block_12:
    func_8002CCB0(arg0, 0x2A, 0x22);
}
