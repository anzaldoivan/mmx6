#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj g_Player;
extern s32 D_800F6720;

#define S_ID(s) M2C_FIELD(s, u8*, 0x0)
#define S_2(s) M2C_FIELD(s, s8*, 0x2)
#define S_STATE(s) M2C_FIELD(s, s8*, 0x6)
#define S_7(s) M2C_FIELD(s, s8*, 0x7)
#define S_X(s) M2C_FIELD(s, s16*, 0xA)
#define S_Y(s) M2C_FIELD(s, s16*, 0xE)
#define S_FACE(s) M2C_FIELD(s, u8*, 0x15)
#define S_46(s) M2C_FIELD(s, s8*, 0x46)
#define S_TIMER(s) M2C_FIELD(s, s16*, 0x7C)

#define ABS(v) ((v) < 0 ? -(v) : (v))

void func_800EA048(void* self) {
    void* parent;
    void* p;

    parent = M2C_FIELD(self, void**, 0x80);
    if (S_2(self) == 5 && S_7(self) == 0 &&
        (S_Y(self) = S_Y(parent) - 0x27) > 0x520 && S_STATE(parent) == 6) {
        M2C_FIELD(self, void**, 0x68) = &D_800F6720;
    }

    if (g_Player.x_pos.i.hi > S_X(self)) {
        S_FACE(self) = 0x40;
    } else {
        S_FACE(self) = 0;
    }
    S_TIMER(self)++;
    switch (S_STATE(self)) {
    case 0:
        ((void (*)(void*, s32))set_animation)(self, 3);
        S_TIMER(self) = 0;
        S_STATE(self)++;
        break;
    case 1:
        if (ABS(g_Player.x_pos.i.hi - S_X(self)) < 0xB5) {
            goto attack;
        } else if (S_TIMER(self) % 200 == 0) {
            ((void (*)(void*, s32))set_animation)(self, 4);
            S_STATE(self)++;
        }
        break;
    case 2:
        if (ABS(g_Player.x_pos.i.hi - S_X(self)) < 0xB5) {
        attack:
            set_animation(self, 5);
            S_TIMER(self) = 0;
            S_STATE(self) = 3;
        } else if (S_46(self) == 0) {
            S_STATE(self) = 0;
        }
        break;
    case 3:
        if (S_TIMER(self) == 0xC) {
            p = func_8002C458();
            if (p != NULL) {
                u8 id = S_ID(self);
                M2C_FIELD(p, u8*, 1) = 5;
                M2C_FIELD(p, u8*, 2) = 2;
                M2C_FIELD(p, void**, 0x7C) = self;
                M2C_FIELD(p, u8*, 0) = id;
            }
        } else if (S_TIMER(self) == 0x5A) {
            S_STATE(self) = 0;
        }
        break;
    }
}
