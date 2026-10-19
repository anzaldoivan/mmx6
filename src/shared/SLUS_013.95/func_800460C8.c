#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800460C8(void* arg0) {
    ((void (*)())func_80017A04)();
    if (M2C_FIELD(arg0, u8*, 0x9C) & 2) {
        M2C_FIELD(arg0, s8*, 0x8F) = 1;
        if (M2C_FIELD(arg0, s8*, 0x2) < 3) {
            func_800179A4(arg0, 2);
        } else {
            func_800179A4(arg0, 3);
        }
        M2C_FIELD(arg0, s8*, 0x8E) = 0x14;
        M2C_FIELD(arg0, u8*, 0x5) = M2C_FIELD(arg0, u8*, 0x5) + 1;
    }
}
