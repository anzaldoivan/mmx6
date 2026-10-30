#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F8044(void* self) {
    ((M2C_UNK(*)())func_80017A04)();
    if (F(s8, 0x45) == 1) {
        play_sound(2, 0x1E, self);
        F(s16, 0x7C) = 0;
        F(u8, 0x6) = F(u8, 0x6) + 1;
    }
    if (SPAD4C[0x8A] != 0x11) {
        set_animation(self, 0x13);
        {
            // !FAKE: depin: dropping it breaks the match (30/32)
            register s32 v asm("$2") = 5;
            F(u8, 0x6) = v;
        }
        F(s16, 0x7C) = 0;
    }
}

#undef F
#undef SPAD4C
