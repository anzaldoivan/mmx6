#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;
extern s32 D_800FCA84;

void func_800FBAD0(void* arg0) {
    s16 d;

    ((void (*)(void*, s32))set_animation)(arg0, 5);
    {
        // !FAKE: depin: dropping it breaks the match (59/64)
        register s32 f asm("$3") = M2C_FIELD(arg0, s16*, 0xA);
        // !FAKE: depin: dropping it breaks the match (62/64)
        register s32 g asm("$4") = D_800970AA;
        if (g > f) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    d = *(u16*)((u8*)&D_800FCA84 + 0x3CC) - M2C_FIELD(arg0, u16*, 0xA);
    if ((d < 0 ? -d : d) < 0x20) {
        set_animation(arg0, 8);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (61/64)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 0x6) + 2;
            M2C_FIELD(arg0, u8*, 0x6) = t;
        }
        return;
    }
    play_sound(2, 0x35, arg0);
    M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x2666;
    M2C_FIELD(arg0, u8*, 0x6) += 1;
    M2C_FIELD(arg0, s32*, 0x20) = (d << 16) / 42;
}
