#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();

void func_800F4238(void* arg0) {
    s8 state;

    state = M2C_FIELD(arg0, s8*, 0x45);
    if (state == 1) {
        play_sound(2, 0x11, arg0);
        switch ((u8)((u32)random_byte() % 3)) {
        case 0:
            play_sound(2, 0x22, arg0);
            break;
        case 1:
            play_sound(2, 0x23, arg0);
            break;
        case 2:
            play_sound(2, 0x24, arg0);
            break;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x60000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
}
