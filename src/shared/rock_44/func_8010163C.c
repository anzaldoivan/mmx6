#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                                 /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_8010163C(void* arg0) {
    s32 var_s0;
    u8 temp_v1;

    ((M2C_UNK(*)())func_80017A04)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        if (!(temp_v1 & 7)) {
            func_80049EBC(arg0, 1, 0x20, 0x40);
        }
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(M2C_FIELD(arg0, u8*, 0x8D) - 1);
        return;
    }
    var_s0 = 3;
    do {
        func_80049EBC(arg0, 1, 0x20, 0x40);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    M2C_FIELD(arg0, s8*, 4) = 2;
}
