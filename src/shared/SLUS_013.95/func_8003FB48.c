#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK);
void* func_8003D3F8(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
M2C_UNK func_8003D510(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3);

void func_8003FB48(void* arg0) {
    func_8003BA04(arg0, 0x5F);
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    func_8003D3F8(1, 0xB, 0, 0);
    M2C_FIELD(arg0, s8*, 0xA6) = 1;
    func_8003D510(1, 0x1B, 9, 0);
    M2C_FIELD(arg0, s8*, 5) = 0x27;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
}
