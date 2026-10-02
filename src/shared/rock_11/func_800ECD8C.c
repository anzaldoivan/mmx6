#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*);                            /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800ECD8C(void* arg0) {
    s32 var_s0;
    u16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x42) = (u16)(M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v1 + 1);
    if ((s16)temp_v1 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0U;
    var_s0 = 3;
    do {
        func_80049EBC(arg0, 1, 0x10, 0x10);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    func_8002CA14(arg0);
}
