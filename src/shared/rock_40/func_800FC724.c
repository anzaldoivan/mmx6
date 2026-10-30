#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
s32 random_byte();
extern M2C_UNK D_800FF804;
extern M2C_UNK D_800FF808;

void func_800FC724(u8* self) {
    u32 r;

    if (*(s8*)(self + 0x45) == 1) {
        set_animation_frame(self, 0x13, random_byte() & 3);
        {
            // !FAKE: depin: dropping it breaks the match (40/45)
            register void* a asm("$2") = &D_800FF804;
            // !FAKE: depin: dropping it breaks the match (41/45)
            register void* b asm("$3") = &D_800FF808;
            *(void**)(self + 0x50) = a;
            *(void**)(self + 0x54) = b;
        }
        r = random_byte();
        *(u16*)(self + 0x7E) = 8;
        self[5]++;
        *(u16*)(self + 0x7C) = (u8)(r % 70) + 20;
    }
}
