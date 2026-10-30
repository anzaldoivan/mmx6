#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F03BC (*(s32**)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 random_byte();
extern s16 D_800970AA;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F03BC(void* self) {
    s32 t = D_800970AA;

    {
        // !FAKE: depin: dropping it breaks the match (63/68)
        register s32 f asm("$3") = F(s16, 0xA);
        if (f < t) {
            F(u8, 0x15) = 0x40;
        } else {
            F(u8, 0x15) = 0;
        }
    }
    if (!(random_byte(t) & 3)) {
        play_sound(2, 0x24, self);
    }
    F(u16, 0x40) = 0x140;
    F(s16, 0x42) = ((func_8002A47C(F(s8, 1)) * 4 + 0x20) % 16) |
                   (((func_8002A47C(F(s8, 1)) + 8) / 4 + 0x1E0) << 6);
    F(u8*, 0x3C) =
        (u8*)SPAD20_800F03BC + SPAD20_800F03BC[func_8002A47C(F(s8, 1))];
    ((void (*)(void*, s32))set_animation)(self, 6);
    F(s16, 0x7C) = 0;
    F(u8, 0x6)++;
}

#undef F
#undef SPAD20_800F03BC
#undef M2C_FIELD
