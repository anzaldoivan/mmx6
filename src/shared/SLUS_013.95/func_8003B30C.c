#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK);

M2C_UNK func_8003B30C(void* arg0) {
    s32 t;

    ((void (*)(void*, s32))func_8003BA04)(arg0, 0x13);
    t = M2C_FIELD(arg0, s32*, 0x100);
    M2C_FIELD(arg0, s8*, 0x67) = -1;
    M2C_FIELD(arg0, s8*, 0x8C) = -1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s8*, 0x6) = 2;
    M2C_FIELD(arg0, s32*, 0x2C) = t;
}
