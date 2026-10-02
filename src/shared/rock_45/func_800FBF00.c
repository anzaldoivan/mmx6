#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_800FBF00(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 3) {
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            M2C_FIELD(arg0, s8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s32*, 0x20) = -0x10000;
        } else {
            M2C_FIELD(arg0, s8*, 0x15) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0x10000;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x2222;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
    ((M2C_UNK(*)())func_80017A04)();
}
