#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_80097180;
extern s32 D_800F6B9C;

void func_800ECDE8(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    if (D_80097180 != 2) {
        ((void (**)(void*)) & D_800F6B9C)[M2C_FIELD(arg0, s8*, 4)](arg0);
    }
}
