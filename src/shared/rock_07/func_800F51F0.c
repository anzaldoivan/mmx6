#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002D230();

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F51F0(void* self) {
    if (F(u8, 0x70) & 8) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x5C, self);
        ((void (*)(void*, s32))set_animation)(self, 7);
        F(u8, 6)++;
    }
    func_8002D230(self);
}

#undef F
