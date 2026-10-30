#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800F8130(void* self) {
    // !FAKE: depin: dropping it breaks the match (43/50)
    register s32 ang asm("$16");
    s32 spd;

    set_animation(self, 0x12);
    M2C_FIELD(self, u8*, 0x3) = 1;
    if (M2C_FIELD(self, u8*, 0x15) == 0) {
        ang = random_byte() * 4 + 0x400;
    } else {
        ang = random_byte() * 4;
    }
    do {
        // !FAKE: depin: dropping it breaks the match (48/50)
        register s32 m asm("$2") = random_byte() & 0x1F;
        spd = m + 0x20;
    } while (0);
    M2C_FIELD(self, s16*, 0xA) += (rcos(ang) * spd) >> 12;
    {
        s32 t = M2C_FIELD(self, u16*, 0xE) + ((-rsin(ang) * spd) >> 12);
        do {
        } while (0);
        M2C_FIELD(self, s16*, 0xE) = t;
    }
    M2C_FIELD(self, u8*, 0x5)++;
}
