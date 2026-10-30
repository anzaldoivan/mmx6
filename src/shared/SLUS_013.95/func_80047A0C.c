#include "common.h"

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot(); /* extern */
s32 random_byte();       /* extern */

void func_80047A0C(s32 arg0, u8* arg1, void* arg2, s32 arg3, s32 arg4) {
    s32 var_s1;
    u8* var_s2;
    u8 temp_v0_2;
    void* temp_v0;

    var_s2 = arg1;
    var_s1 = arg0 & 0xFF;
    if (var_s1 != 0) {
        do {
            temp_v0 = alloc_sprite_slot();
            if (temp_v0 != NULL) {
                M2C_FIELD(temp_v0, s8*, 0) = 0x41;
                M2C_FIELD(temp_v0, s8*, 1) = 3;
                M2C_FIELD(temp_v0, s8*, 2) = 0;
                M2C_FIELD(temp_v0, s8*, 0x15) = (s8)(random_byte() & 0x40);
                M2C_FIELD(temp_v0, s8*, 4) = 0;
                M2C_FIELD(temp_v0, s8*, 5) = 0;
                M2C_FIELD(temp_v0, s8*, 6) = 0;
                M2C_FIELD(temp_v0, s32*, 8) =
                    (s32)(M2C_FIELD(arg2, s32*, 8) + (random_byte() & 3) +
                          arg3);
                M2C_FIELD(temp_v0, s32*, 0xC) =
                    (s32)(M2C_FIELD(arg2, s32*, 0xC) + (random_byte() & 3) +
                          arg4);
                temp_v0_2 = *var_s2;
                var_s2 += 1;
                M2C_FIELD(temp_v0, void**, 0x54) = arg2;
                M2C_FIELD(temp_v0, u8*, 0x58) = temp_v0_2;
            }
            var_s1 = (var_s1 - 1) & 0xFF;
        } while (var_s1 != 0);
    }
}
