#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F6F44(void* arg0, s32 arg1);

void func_800F9DA8(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x89) ^= 1;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x89) = 0;
        func_800F6F44(arg0, M2C_FIELD(arg0, u8*, 0x2));
        M2C_FIELD(arg0, u8*, 0x5)--;
    }
}
