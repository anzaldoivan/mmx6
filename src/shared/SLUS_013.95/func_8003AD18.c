#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8003A628(void*);                   /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8); /* extern */
M2C_UNK func_8003CD9C();                    /* extern */
M2C_UNK func_8003D10C(void*);               /* extern */

void func_8003AD18(void* arg0) {
    s32 var_a2;
    u8 temp_v0;
    u8 temp_v1;

    func_8003CD9C();
    if (func_8003A628(arg0) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 2;
        M2C_FIELD(arg0, s8*, 6) = 0;
        if ((M2C_FIELD(arg0, s8*, 2) == 0) &&
            (M2C_FIELD(arg0, s8*, 0x8E) != 0)) {
            temp_v0 = M2C_FIELD(arg0, u8*, 0x91);
            var_a2 = temp_v0 < 9U;
            if (temp_v0 < 5U) {
                var_a2 = 2;
            }
            func_8003BB94(arg0, 0x5E, var_a2);
            temp_v1 = M2C_FIELD(arg0, u8*, 0x91);
            if (temp_v1 >= 9U) {
                M2C_FIELD(arg0, s8*, 0x44) = (s8)(temp_v1 - 8);
            }
        } else {
            func_8003D10C(arg0);
        }
    }
}
