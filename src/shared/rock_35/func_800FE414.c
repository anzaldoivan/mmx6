#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D230(void*);          /* extern */
s32 func_80031474(void*);              /* extern */

void func_800FE414(void* arg0) {
    s8 temp_v1_2;
    u8 temp_v1;

    ((M2C_UNK(*)())func_80017A04)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x95);
    if (temp_v1 < 0x1EU) {
        M2C_FIELD(arg0, u8*, 0x95) = (u8)(temp_v1 + 1);
        return;
    }
    func_8002D230(arg0);
    if (func_80031474(arg0) < 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        func_800179A4(arg0, 9);
    }
    temp_v1_2 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1_2 == 2) {
        M2C_FIELD(arg0, s8*, 4) = temp_v1_2;
    }
    M2C_FIELD(arg0, s8*, 3) = 1;
}
