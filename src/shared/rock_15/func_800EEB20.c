#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800EEB20(void* self) {
    if (M2C_FIELD(self, u8*, 0x70) & 8) {
        ((void (*)(M2C_UNK, M2C_UNK, void*))play_sound)(2, 0x81, self);
        set_animation(self, 7);
        ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))func_8002943C)(0x1E, 5, 2);
        M2C_FIELD(self, s16*, 0x7C) = 0xB4;
        M2C_FIELD(self, s8*, 6)++;
    } else {
        func_8002D230(self);
    }
}
