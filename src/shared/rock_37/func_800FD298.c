#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800FD298(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 3) {
        M2C_FIELD(arg0, s8*, 7) = 0;
        set_animation(arg0, 3);
        if (!(random_byte() & 1)) {
            play_sound(2, 0x27, arg0);
        } else {
            play_sound(2, 0x28, arg0);
        }
        M2C_FIELD(arg0, s8*, 6) = 2;
    }
}
