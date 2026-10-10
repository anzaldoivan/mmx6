#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EB898(void* self) {
    s8 old;
    s32 dir;

    if (F(s16, 0x7C) != 0) {
        F(s16, 0x7C)--;
        return;
    }
    if (F(s32, 0x20) <= -0x20000) {
        F(s32, 0x20) = -0x20000;
    }
    if (F(s32, 0x24) <= -0x20000) {
        F(s32, 0x24) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (F(s16, 0xA) < 0x960 && F(s8, 0x8C) == 0) {
        F(s8, 0x8C)++;
        F(s32, 0x2C) = 0xD00;
        F(s32, 0x24) = 0x2D000;
        func_80016C48(2, 0x18, self);
        func_80012D9C(3);
        func_8002943C(0x3C, 2, 1);
    }
    if (F(s16, 0xA) < 0x840 && F(s8, 0x8C) == 1) {
        F(s8, 0x8C)++;
        F(s32, 0x2C) = 0xD00;
        F(s32, 0x24) = 0x2D000;
        func_80016C48(2, 0x18, self);
        func_80012D9C(3);
        func_8002943C(0x3C, 2, 1);
    }
    if ((F(u8, 0x70) & 2) && F(s16, 0xA) < 0x680) {
        func_80016C48(2, 0x18, self);
        func_80012D9C(3);
        F(s32, 0x20) = 0x10000;
        F(s32, 0x28) = -0x1000;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
        F(s16, 0x7C) = 0x3C;
        func_80016C48(2, 0x18, self);
        func_80012D9C(3);
        func_8002943C(0x3C, 2, 1);
        F(s8, 0x8C) = 0;
        F(u8, 6) = 1;
    }
    old = F(s8, 0x67);
    if (F(u8, 0x70) & 8) {
        F(s8, 0x67) = 0;
    } else {
        dir = F(s32, 0x24);
        if (dir < 0) {
            dir = -1;
        } else {
            dir = 1;
        }
        F(s8, 0x67) = dir;
    }
    if (F(s8, 0x67) == 0 && old != 0) {
        func_80016C48(2, 0x18, self);
        func_80012D9C(3);
        func_8002943C(0x1E, 2, 1);
    }
}

#undef F
