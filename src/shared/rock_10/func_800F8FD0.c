#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800F8FD0(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        play_sound(2, 0x52, arg0);
        set_animation(arg0, 6);
        M2C_FIELD(arg0, s8*, 7) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x14;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
