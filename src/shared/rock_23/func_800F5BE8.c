#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800179A4(void*, s32);
void func_800F6FC8();

void func_800F5BE8(void* arg0) {
    s32 t;
    func_800F6FC8(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0x1F) {
        func_800179A4(arg0, 0x13);
        t = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = t + 1;
    }
}
