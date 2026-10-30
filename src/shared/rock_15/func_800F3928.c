#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern s32 D_800F6F30[];

void func_800F3928(void* arg0) {
    u32 r;

    M2C_FIELD(arg0, s32**, 0x68) = D_800F6F30;
    M2C_FIELD(arg0, s32*, 0x20) = 0xFFFC0000;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, u8*, 7) = 1;
    r = random_byte();
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    M2C_FIELD(arg0, s16*, 0x8C) = ((u8)(r % 14) + 1) * 4;
}
