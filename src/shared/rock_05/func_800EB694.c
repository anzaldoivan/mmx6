#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800EB694(void* self) {
    s8 old;
    s32 dir;

    if (M2C_FIELD(self, s16*, 0x7C) != 0) {
        M2C_FIELD(self, s16*, 0x7C)--;
        return;
    }
    if (M2C_FIELD(self, s32*, 0x20) > 0x1FFFF) {
        M2C_FIELD(self, s32*, 0x20) = 0x20000;
    }
    if (M2C_FIELD(self, s32*, 0x24) <= -0x20000) {
        M2C_FIELD(self, s32*, 0x24) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (M2C_FIELD(self, s16*, 0xA) > 0x7A0 && M2C_FIELD(self, s8*, 0x8C) == 0) {
        M2C_FIELD(self, s8*, 0x8C)++;
        M2C_FIELD(self, s32*, 0x2C) = 0xD00;
        M2C_FIELD(self, s32*, 0x24) = 0x2D000;
        play_sound(2, 0x18, self);
        func_80012D9C(3);
        func_8002943C(0x3C, 2, 1);
    }
    if (M2C_FIELD(self, s16*, 0xA) > 0x8C0 && M2C_FIELD(self, s8*, 0x8C) == 1) {
        M2C_FIELD(self, s8*, 0x8C)++;
        M2C_FIELD(self, s32*, 0x2C) = 0xD00;
        M2C_FIELD(self, s32*, 0x24) = 0x2D000;
        play_sound(2, 0x18, self);
        func_80012D9C(3);
        func_8002943C(0x3C, 2, 1);
    }
    if ((M2C_FIELD(self, u8*, 0x70) & 1) &&
        M2C_FIELD(self, s16*, 0xA) > 0xA60) {
        play_sound(2, 0x18, self);
        func_80012D9C(3);
        M2C_FIELD(self, s16*, 0x7C) = 0x3C;
        func_8002943C(0x3C, 2, 1);
        M2C_FIELD(self, s8*, 6) = 0;
    }
    old = M2C_FIELD(self, s8*, 0x67);
    if (M2C_FIELD(self, u8*, 0x70) & 8) {
        M2C_FIELD(self, s8*, 0x67) = 0;
    } else {
        dir = M2C_FIELD(self, s32*, 0x24);
        if (dir < 0) {
            dir = -1;
        } else {
            dir = 1;
        }
        M2C_FIELD(self, s8*, 0x67) = dir;
    }
    if (M2C_FIELD(self, s8*, 0x67) == 0 && old != 0) {
        play_sound(2, 0x18, self);
        func_80012D9C(3);
        func_8002943C(0x1E, 2, 1);
    }
}
