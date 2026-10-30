#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;

void func_800FCF4C(void* self) {
    s32 g;

    set_animation(self, 5);
    play_sound(2, 0x98, self);
    g = D_800970AA;
    if (M2C_FIELD(self, s16*, 0xA) < g) {
        M2C_FIELD(self, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(self, u8*, 0x15) = 0;
    }
    M2C_FIELD(self, u8*, 6) = M2C_FIELD(self, u8*, 6) + 1;
}
