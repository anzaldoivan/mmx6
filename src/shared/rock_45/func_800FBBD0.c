#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;

void func_800FBBD0(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        if (M2C_FIELD(arg0, s32*, 0x24) != 0) {
            play_sound(2, 0x42, arg0);
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        ((void (*)(void*, s32))set_animation)(arg0, 8);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}
