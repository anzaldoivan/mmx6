#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object();
s32 random_byte();

void func_800F82AC(u8* self) {
    u32 r;

    ((void (*)(void*))move_object)(self);
    if (--*(s16*)(self + 0x7C) == 0) {
        if (--*(s16*)(self + 0x7E) == -1) {
            set_animation(self, 0x14);
            {
                // !FAKE: depin: dropping it breaks the match (46/49)
                register s32 t asm("$2") = self[5] + 1;
                self[5] = t;
            }
            return;
        }
        r = random_byte();
        self[5]--;
        *(u16*)(self + 0x7C) = (u8)(r % 30) + 60;
    }
}
