#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */

void func_800F28C0(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 6;
    func_800F3E10(arg0, 2);
    func_800F3E10(arg0, 0x10);
    func_800F3E10(arg0, 0x11);
    func_800F3E10(arg0, 0x12);
    func_800F3E10(arg0, 0x13);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
