#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800743DC;
extern s16 D_800970AA;
extern s32 D_800F6AC0;
extern s32 D_800F6AC4;
extern s32 D_800F6AC8;

void func_800EB3C8(void* self) {
    void* parent;
    void* p2;
    s32 d;
    u8 t;

    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    t = M2C_FIELD(parent, u8*, 0x14);
    M2C_FIELD(self, u8*, 0x16) = 4;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, void**, 0x68) = &D_800F6AC0;
    M2C_FIELD(self, void**, 0x50) = &D_800F6AC4;
    M2C_FIELD(self, u8*, 3) = 0;
    M2C_FIELD(self, void**, 0x54) = &D_800F6AC8;
    M2C_FIELD(self, void**, 0x58) = &D_800743DC;
    M2C_FIELD(self, u8*, 0x14) = t;
    set_animation(self, 0x12);
    p2 = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, u8*, 0x15) = M2C_FIELD(p2, u8*, 0x15);
    if (M2C_FIELD(self, u8*, 0x15) == 0) {
        if (M2C_FIELD(p2, s8*, 5) == 3) {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA) - 12;
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 12;
        } else if (M2C_FIELD(p2, s8*, 5) == 6) {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA) - 16;
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 12;
        } else {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA);
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 14;
        }
    } else {
        if (M2C_FIELD(p2, s8*, 5) == 3) {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA) + 12;
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 12;
        } else if (M2C_FIELD(p2, s8*, 5) == 6) {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA);
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 14;
        } else {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA) + 16;
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 12;
        }
    }
    d = (D_800970AA - M2C_FIELD(self, s16*, 0xA)) << 16;
    M2C_FIELD(self, s32*, 0x24) = 0x30000;
    M2C_FIELD(self, s32*, 0x2C) = 0x1800;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, u8*, 0x5C) = 2;
    M2C_FIELD(self, u8*, 0x60) = 3;
    M2C_FIELD(self, s32*, 0x20) = d / 70;
    play_sound(2, 0xF, self);
    M2C_FIELD(self, u8*, 6) = 0;
    M2C_FIELD(self, u8*, 5) = 0;
    M2C_FIELD(self, u8*, 4)++;
}
