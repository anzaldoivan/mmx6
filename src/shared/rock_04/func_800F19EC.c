#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800F19EC(void* arg0) {
    s32 r;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        play_sound(2, 0x11, arg0);
        r = (u32)random_byte() % 3 & 0xFF;
        switch (r) {
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
        set_animation(arg0, 5);
        {
            // !FAKE: depin: dropping it breaks the match (87/89)
            register s32 n1 asm("$4") = 0x500000;
            s32 d1 = 0xA2;
            s32 n2;
            s32 d2;
            M2C_FIELD(arg0, s32*, 0x2C) = n1 / d1;
            n2 = 0xA00000;
            d2 = 0x24;
            M2C_FIELD(arg0, s32*, 0x24) = 0x8E386;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = n2 / d2;
        }
        M2C_FIELD(arg0, u16*, 0x7C) = 0xC;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x471C7;
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
