#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 random_byte();

extern u8 D_800FBF9C[];
extern u8 D_800FBFA0[];

void func_800EC180(void* self) {
    s32 a;
    s32 r;
    s32 t;

    M2C_FIELD(self, u8*, 0x60) = 4;
    M2C_FIELD(self, u8*, 0x5C) = 1;
    M2C_FIELD(self, u8*, 0x16) = 4;
    M2C_FIELD(self, u8*, 0x67) = 1;
    set_animation(self, 8);
    M2C_FIELD(self, void**, 0x68) = D_800FBF9C;
    M2C_FIELD(self, void**, 0x50) = D_800FBFA0;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, u8*, 0x4) = 1;
    M2C_FIELD(self, u8*, 0x5) = 0;
    M2C_FIELD(self, u8*, 0x6) = 0;
    M2C_FIELD(self, u8*, 0x7) = 0;
    play_sound(2, 0, self);
    switch (M2C_FIELD(self, s16*, 0x88)) {
    case 3:
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) -= 12;
            M2C_FIELD(self, s16*, 0xE) -= 1;
        } else {
            M2C_FIELD(self, s16*, 0xA) += 12;
            M2C_FIELD(self, s16*, 0xE) -= 1;
        }
        break;
    case 4:
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) -= 9;
            M2C_FIELD(self, s16*, 0xE) -= 11;
        } else {
            M2C_FIELD(self, s16*, 0xA) += 9;
            M2C_FIELD(self, s16*, 0xE) -= 11;
        }
        break;
    case 5:
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) -= 9;
            M2C_FIELD(self, s16*, 0xE) += 7;
        } else {
            M2C_FIELD(self, s16*, 0xA) += 9;
            M2C_FIELD(self, s16*, 0xE) += 7;
        }
        break;
    case 6:
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) += 1;
            M2C_FIELD(self, s16*, 0xE) -= 13;
        } else {
            M2C_FIELD(self, s16*, 0xA) -= 1;
            M2C_FIELD(self, s16*, 0xE) -= 13;
        }
        break;
    case 7:
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) -= 1;
            M2C_FIELD(self, s16*, 0xE) += 13;
        } else {
            M2C_FIELD(self, s16*, 0xA) += 1;
            M2C_FIELD(self, s16*, 0xE) += 13;
        }
        break;
    }
    a = M2C_FIELD(self, s32*, 0x84);
    if (M2C_FIELD(self, s8*, 0x2) != 0) {
        if (random_byte() & 1) {
            a += 0xAA;
        } else {
            a -= 0xAA;
        }
    }
    r = rcos(a);
    t = r * 16;
    M2C_FIELD(self, s32*, 0x20) = r * 32 + t;
    r = rsin(a);
    t = r * 16;
    M2C_FIELD(self, s32*, 0x24) = r * 32 + t;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    if (func_8002CBFC(self, 0x18, 0x18) == 0) {
        func_8002CCB0(self, 0x10, 0x10);
    } else {
        M2C_FIELD(self, u8*, 0x4)++;
    }
}
