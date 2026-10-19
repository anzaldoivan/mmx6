#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */

void func_800F2934(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 7) = 6;
        func_800F3E10(arg0, 0x30);
        func_800F3E10(arg0, 0x31);
        func_800F3E10(arg0, 0x32);
        func_800F3E10(arg0, 0x33);
        func_800F3E10(arg0, 0x34);
        func_800F3E10(arg0, 0x35);
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
