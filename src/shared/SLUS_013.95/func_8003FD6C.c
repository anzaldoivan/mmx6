#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
M2C_UNK func_801EAA38(void*);          /* extern */
M2C_UNK func_801EACA0(void*);          /* extern */

void func_8003FD6C(void* arg0, s32 arg1) {
    if (((M2C_FIELD(arg0, s32*, 4) & 0xFFFF00) == 0xB00) ||
        (M2C_FIELD(arg0, s8*, 5) == 0x2F)) {
        func_8003BA04(arg0, 0xBB);
        M2C_FIELD(arg0, s8*, 5) = 0x2F;
        M2C_FIELD(arg0, s8*, 6) = 0;
        func_801EACA0(arg0);
        return;
    }
    M2C_FIELD(arg0, s8*, 6) = 0;
    if (arg1 == 0) {
        M2C_FIELD(arg0, s8*, 5) = 0x2D;
        if (M2C_FIELD(arg0, u8*, 0xE7) != 2) {
            func_8003BA04(arg0, 0xB7);
            return;
        }
        func_8003BA04(arg0, 0xB9);
        return;
    }
    M2C_FIELD(arg0, s8*, 5) = 0x2E;
    if (M2C_FIELD(arg0, u8*, 0xE7) != 2) {
        func_8003BA04(arg0, 0xB8);
    } else {
        func_8003BA04(arg0, 0xBA);
    }
    if (M2C_FIELD(arg0, s32*, 0x2C) == 0) {
        M2C_FIELD(arg0, s32*, 0x2C) = (s32)M2C_FIELD(arg0, s32*, 0x100);
    }
    func_801EAA38(arg0);
}
