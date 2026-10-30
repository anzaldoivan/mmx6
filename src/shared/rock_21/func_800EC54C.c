#include "common.h"

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot(); /* extern */

void func_800EC54C(void* arg0) {
    s32 var_v0;
    u16 temp_v0;
    void* temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x78) {
        M2C_FIELD(arg0, u16*, 4) = 0U;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        temp_v0_2 = alloc_sprite_slot();
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, s8*, 0) = 1;
            M2C_FIELD(temp_v0_2, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_2, s8*, 2) = 0;
            M2C_FIELD(temp_v0_2, s16*, 0xA) = 0x100;
            M2C_FIELD(temp_v0_2, s16*, 0xE) = 0x20;
        }
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
