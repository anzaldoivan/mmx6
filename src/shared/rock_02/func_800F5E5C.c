#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800F5E5C(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (25/35)
    register u16 t asm("$2");

    if (M2C_FIELD(arg0, s16*, 0x7C) == 0xA) {
        start_pad_vibration(7);
        play_sound(2, 0x1D, arg0);
    }
    animate_object(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, s16*, 0x7C) = t + 1;
    if ((s16)t > 0x28) {
        set_animation(arg0, 8);
        t = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = t + 1;
    }
}
