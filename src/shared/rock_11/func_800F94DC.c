#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800F94DC(void* arg0) {
    set_animation(arg0, 0);
    M2C_FIELD(arg0, s16*, 0x7C) = (random_byte() & 0x7F) + 0x78;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
