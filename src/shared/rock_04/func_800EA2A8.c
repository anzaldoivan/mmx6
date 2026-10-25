#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;

#define S_ID(s) M2C_FIELD(s, u8*, 0x0)
#define S_STATE(s) M2C_FIELD(s, s8*, 0x6)
#define S_X(s) M2C_FIELD(s, s16*, 0xA)
#define S_FACE(s) M2C_FIELD(s, u8*, 0x15)
#define S_46(s) M2C_FIELD(s, s8*, 0x46)
#define S_TIMER(s) M2C_FIELD(s, s16*, 0x7C)

#define ABS(v) ((v) < 0 ? -(v) : (v))

void func_800EA2A8(void* self) {
    void* p;

    S_TIMER(self)++;
    switch (S_STATE(self)) {
    case 0:
        if (D_800970AA > S_X(self)) {
            S_FACE(self) = 0x40;
        } else {
            S_FACE(self) = 0;
        }
        if (S_FACE(self) == 0) {
            func_800179A4(self, 6);
        } else {
            func_800179A4(self, 0x18);
        }
        S_STATE(self)++;
        S_TIMER(self) = 0;
        break;
    case 1:
        if (ABS(g_Player.x_pos.i.hi - S_X(self)) <= 0x60) {
            p = func_8002C458();
            if (p != NULL) {
                M2C_FIELD(p, u8*, 0) = S_ID(self);
                M2C_FIELD(p, u8*, 1) = 5;
                M2C_FIELD(p, u8*, 2) = 1;
                M2C_FIELD(p, void**, 0x7C) = self;
            }
            if (g_Player.x_pos.i.hi > S_X(self)) {
                S_FACE(self) = 0x40;
            } else {
                S_FACE(self) = 0;
            }
            if (S_FACE(self) == 0) {
                func_800179A4(self, 8);
            } else {
                func_800179A4(self, 0x1A);
            }
            S_TIMER(self) = 0;
            S_STATE(self) = 3;
        } else if (S_TIMER(self) % 200 == 0) {
            if (g_Player.x_pos.i.hi > S_X(self)) {
                S_FACE(self) = 0x40;
            } else {
                S_FACE(self) = 0;
            }
            if (S_FACE(self) == 0) {
                func_800179A4(self, 7);
            } else {
                func_800179A4(self, 0x19);
            }
            S_STATE(self)++;
        }
        break;
    case 2:
        if (ABS(g_Player.x_pos.i.hi - S_X(self)) <= 0x60) {
            p = func_8002C458();
            if (p != NULL) {
                M2C_FIELD(p, u8*, 0) = S_ID(self);
                M2C_FIELD(p, u8*, 1) = 5;
                M2C_FIELD(p, u8*, 2) = 1;
                M2C_FIELD(p, void**, 0x7C) = self;
            }
            if (g_Player.x_pos.i.hi > S_X(self)) {
                S_FACE(self) = 0x40;
            } else {
                S_FACE(self) = 0;
            }
            if (S_FACE(self) == 0) {
                func_800179A4(self, 8);
            } else {
                func_800179A4(self, 0x1A);
            }
            S_TIMER(self) = 0;
            S_STATE(self) = 3;
        } else if (S_46(self) == 0) {
            S_STATE(self) = 0;
        }
        break;
    case 3:
        if (S_TIMER(self) == 0x5A) {
            if (D_800970AA > S_X(self)) {
                S_FACE(self) = 0x40;
            } else {
                S_FACE(self) = 0;
            }
            if (S_FACE(self) == 0) {
                func_800179A4(self, 6);
            } else {
                func_800179A4(self, 0x18);
            }
            S_STATE(self)++;
            S_TIMER(self) = 0;
        }
        break;
    case 4:
        if (S_TIMER(self) == 0x28) {
            S_STATE(self) = 0;
        }
        break;
    }
}
