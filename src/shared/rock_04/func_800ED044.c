#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_80075B9C;
extern s32 D_800F6B90;
extern s32 D_800F6B94;

void func_800ED044(void* arg0) {
    M2C_FIELD(arg0, void**, 0x58) = &D_80075B9C;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F6B94;
    M2C_FIELD(arg0, void**, 0x68) = (s8*)arg0 + 0x80;
    __builtin_memcpy((s8*)arg0 + 0x80, &D_800F6B90, 4);
    M2C_FIELD(arg0, u8*, 0x6) = 2;
}
