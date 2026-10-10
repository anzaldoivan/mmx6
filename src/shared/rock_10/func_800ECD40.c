#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EABD8(void*, M2C_UNK); /* extern */

void func_800ECD40(void* arg0) {
    s32 temp_v1;
    u8 temp_a0;
    u8 temp_v0;

    temp_a0 = M2C_FIELD(arg0, u8*, 0x86);
    temp_v0 = M2C_FIELD(arg0, u8*, 0x88);
    temp_v1 = temp_a0 - temp_v0;
    if (temp_v1 >= 0) {
        if (temp_v1 == 4) {

        } else {
            goto block_4;
        }
    } else if (temp_a0 != (temp_v0 - 4)) {
    block_4:
        func_800EABD8(arg0, 0);
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0x12E;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
