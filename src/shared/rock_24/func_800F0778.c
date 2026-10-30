#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F0778 (*(s32**)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern M2C_UNK D_8007433C;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F0778(void* self) {
    play_sound(2, 0x21, self);
    F(s16, 0x40) = 0x140;
    F(s16, 0x42) = ((func_8002A47C(F(s8, 1)) * 4 + 0x20) % 16) |
                   (((func_8002A47C(F(s8, 1)) + 8) / 4 + 0x1E0) << 6);
    F(u8*, 0x3C) =
        (u8*)SPAD20_800F0778 + SPAD20_800F0778[func_8002A47C(F(s8, 1))];
    set_animation(self, 7);
    F(void*, 0x58) = &D_8007433C;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(s16, 0x7C) = 0;
    F(u8, 6)++;
    func_8002CCB0(self, 0x30, 0x40);
    func_8002D230(self);
}

#undef F
