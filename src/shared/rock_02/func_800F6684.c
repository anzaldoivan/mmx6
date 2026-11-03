#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800F6684(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0xA) {
        play_sound(2, 0x1D, arg0);
        start_pad_vibration(7);
    }
    if (M2C_FIELD(arg0, s16*, 0x7C)++ >= 0x3D) {
        set_animation(arg0, 8);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (30/33)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}
