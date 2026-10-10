#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
M2C_UNK func_8003CDBC();               /* extern */

void func_8003A1C8(void* arg0) {
    s32 var_a0;
    u8 temp_a1;

    if ((M2C_FIELD(arg0, s8*, 0xD4) > 0) && (M2C_FIELD(arg0, s8*, 0xA4) <= 0)) {
        func_8003CDBC();
        temp_a1 = M2C_FIELD(arg0, u8*, 0x17);
        var_a0 = temp_a1 == 5;
        if (temp_a1 == 6) {
            var_a0 = 1;
        }
        if (temp_a1 == 0xC) {
            var_a0 = 1;
        }
        if (var_a0 != 0) {
            func_8003BA04(arg0, 0x26);
        }
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s8*, 0xD4) = -1;
        M2C_FIELD(arg0, s8*, 0x8C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 0x13;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}
