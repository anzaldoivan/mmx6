#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
s32 func_8004FE8C(void*);              /* extern */

void func_8004F9A0(void* arg0) {
    u8 temp_v0;

    ((M2C_UNK(*)())func_80017A04)();
    if (func_8004FE8C(arg0) != 0) {
        if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
            if (M2C_FIELD(arg0, u8*, 0x7E) == 0) {
                if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                    func_800179A4(arg0, 9);
                } else {
                    func_800179A4(arg0, 0x11);
                }
            } else if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                func_800179A4(arg0, 0xA);
            } else {
                func_800179A4(arg0, 0x12);
            }
        } else if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
            func_800179A4(arg0, 0x19);
        } else {
            func_800179A4(arg0, 0x20);
        }
    }
    temp_v0 = M2C_FIELD(arg0, u8*, 0x81);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x81) = (u8)(temp_v0 - 1);
        return;
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s8*, 4) = 5;
    if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
        func_800179A4(arg0, 8);
        return;
    }
    func_800179A4(arg0, 0x1D);
}
