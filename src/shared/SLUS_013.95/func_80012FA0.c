#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8006663C(s32, M2C_UNK); /* extern */

void func_80012FA0(void* arg0) {
    func_8006663C(arg0 + 0x70, 0x20);
    M2C_FIELD(arg0, s8*, 0x2A) = 0;
    M2C_FIELD(arg0, s8*, 0x2C) = 1;
    M2C_FIELD(arg0, s8*, 0x2D) = 0;
    M2C_FIELD(arg0, s8*, 0x2E) = 0;
    M2C_FIELD(arg0, s8*, 0x2F) = 0;
}
