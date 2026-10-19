#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK);

void func_8003FCD4(void* arg0) {
    ((void (*)(void*, s32))func_8003BA04)(arg0, 0x5F);
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    M2C_FIELD(arg0, u8*, 0xA6) = 2;
    M2C_FIELD(arg0, u8*, 5) = 0x2A;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
