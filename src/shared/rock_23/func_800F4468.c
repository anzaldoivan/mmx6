#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*); /* extern */
M2C_UNK func_8003D330();      /* extern */
M2C_UNK func_800F6FC8();      /* extern */

void func_800F4468(void* arg0) {
    func_800F6FC8();
    func_80017A04(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_8003D330();
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
        M2C_FIELD(arg0, s32*, 0x2C) = -0x1000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
