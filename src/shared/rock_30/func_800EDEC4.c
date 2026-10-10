#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_8003D330();               /* extern */
M2C_UNK func_8004E78C(M2C_UNK);        /* extern */
extern s8 D_800CCEF7;

void func_800EDEC4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        func_8003D330();
        D_800CCEF7 = 0;
        func_800179A4(arg0, 0);
        func_8004E78C(0);
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 0) = (u8)(M2C_FIELD(arg0, u8*, 0) & 0xF7);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
