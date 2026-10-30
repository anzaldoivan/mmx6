#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F6F44(void* arg0, s32 arg1);

void func_800F8464(void* arg0) {
    s8 st = M2C_FIELD(arg0, s8*, 0x45);

    if (st == 2) {
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        play_sound(2, 0x53, arg0);
        func_800F6F44(arg0, 0);
    } else if (st == 1) {
        set_animation(arg0, 0x16);
        {
            // !FAKE: depin: dropping it breaks the match (39/42)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}
