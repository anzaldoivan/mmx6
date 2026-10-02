#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_8004FE8C();               /* extern */

void func_8004F8C0(void* arg0) {
    func_8004FE8C();
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
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s8*, 4) = 4;
    M2C_FIELD(arg0, s8*, 0x81) = 0x50;
}
