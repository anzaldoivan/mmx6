#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800EB750(void* self) {
    void* parent = M2C_FIELD(self, void**, 0x7C);

    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(parent, u8*, 0x14);
    M2C_FIELD(self, u8*, 0x16) = 4;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, u8*, 0x3) = 0;
    M2C_FIELD(self, s32*, 0x68) = 0;
    M2C_FIELD(self, s32*, 0x50) = 0;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, s32*, 0x58) = 0;
    set_animation(self, 0xC);
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, u8*, 0x5C) = 1;
    M2C_FIELD(self, u8*, 0x60) = 4;
    play_sound(2, 0x10, self);
    M2C_FIELD(self, u8*, 0x6) = 0;
    M2C_FIELD(self, u8*, 0x5) = 0;
    M2C_FIELD(self, u8*, 0x4)++;
}
