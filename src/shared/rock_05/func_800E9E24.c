#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);

void func_800E9E24(u8* arg0) {
    u16 temp_a0;

    set_animation(arg0, 4);
    temp_a0 = M2C_FIELD(arg0, u16*, 0x7E);
    M2C_FIELD(arg0, u16*, 0x7E) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0xC;
    M2C_FIELD(arg0, s16*, 0x7C) = temp_a0 + 0x3C;
    M2C_FIELD(SCRATCH_4C, u8*, 0x84) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}
