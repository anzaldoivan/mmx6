#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800F2F78(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        set_animation(arg0, 1);
        play_sound(2, (random_byte() & 1) | 0x24, arg0);
        M2C_FIELD(arg0, u8*, 6) = 1;
        M2C_FIELD(arg0, u16*, 0x7E) -= 1;
    }
}
