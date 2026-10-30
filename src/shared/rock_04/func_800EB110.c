#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F6AB8;
extern s32 D_800F6ABC;

void func_800EB110(void* self) {
    void* parent;

    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, s16*, 0x42) = M2C_FIELD(parent, s16*, 0x42) & 0x7FFF;
    M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(parent, u8*, 0x14);
    M2C_FIELD(self, u8*, 0x16) = 4;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, u8*, 0x3) = 0;
    M2C_FIELD(self, s32*, 0x68) = 0;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, s32*, 0x58) = 0;
    M2C_FIELD(self, u8*, 0x15) = M2C_FIELD(parent, u8*, 0x15);
    if (M2C_FIELD(parent, s8*, 0x2) == 0) {
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) - 0x29;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(parent, s16*, 0xE) + 6;
            set_animation(self, 0xF);
            {
                // !FAKE: depin: dropping it breaks the match (37/99)
                register s32 a asm("$2") = (s32)&D_800F6AB8;
                M2C_FIELD(self, s32*, 0x50) = a;
            }
        } else {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) + 0x24;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(parent, s16*, 0xE) - 0x11;
            set_animation(self, 0x1E);
            {
                // !FAKE: depin: dropping it breaks the match (48/99)
                register s32 a asm("$2") = (s32)&D_800F6ABC;
                M2C_FIELD(self, s32*, 0x50) = a;
            }
        }
    } else {
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) - 0x24;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(parent, s16*, 0xE) - 0x11;
            set_animation(self, 0x1E);
            {
                // !FAKE: depin: dropping it breaks the match (62/99)
                register s32 a asm("$2") = (s32)&D_800F6ABC;
                M2C_FIELD(self, s32*, 0x50) = a;
            }
        } else {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) + 0x29;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(parent, s16*, 0xE) + 6;
            set_animation(self, 0xF);
            {
                // !FAKE: depin: dropping it breaks the match (38/99)
                register s32 a asm("$2") = (s32)&D_800F6AB8;
                M2C_FIELD(self, s32*, 0x50) = a;
            }
        }
    }
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
