#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ECC4C(void* self) {
    if (F(s16, 0x7C) != 0) {
        F(s16, 0x7C)--;
        return;
    }
    if (F(s32, 0x20) > 0x1FFFF) {
        F(s32, 0x20) = 0x20000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (F(u8, 0x70) & 1) {
        play_sound(2, 0x18, self);
        func_80012D9C(3);
        F(s32, 0x20) = 0xFFFF0000;
        F(s32, 0x28) = 0x1000;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
        F(s16, 0x7C) = 0x3C;
        func_8002943C(0x3C, 2, 1);
        F(u8, 6)++;
    }
}

#undef F
