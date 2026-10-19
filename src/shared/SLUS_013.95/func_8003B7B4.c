#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CD9C();

M2C_UNK func_8003B7B4(void* arg0) {
    M2C_FIELD(arg0, s16*, 8) = 0;
    M2C_FIELD(arg0, s16*, 0xC) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u16*, 0xA) = (M2C_FIELD(arg0, u16*, 0xA) & 0xFFF0) + 8;
    M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x11C);
    ((void (*)())func_8003CD9C)(arg0);
    M2C_FIELD(arg0, u8*, 5) = 0xF;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
