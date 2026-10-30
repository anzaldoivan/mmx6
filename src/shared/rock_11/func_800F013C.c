#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern struct X4_PlayerObj g_Player;
extern s32 D_800FCBA4;
extern s32 D_800FCBA8;
extern s8 D_800FD51D;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F013C(void* arg0) {
    s32 t;
    u16 x;

    F(u8, 0x5C) = 0;
    F(u8, 0x3) = 0;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x16) = 4;
    F(u8, 0x67) = 1;
    F(void*, 0x50) = 0;
    F(s32, 0x54) = 0;
    F(s32, 0x68) = 0;
    if (D_800FD51D != 0) {
        F(u8, 0x3) = 0;
        F(u8, 0x4)++;
        return;
    }
    t = F(s8, 0x2) & 0xF0;
    switch (t) {
    case 0:
        F(u8, 0x60) = 4;
        F(u8, 0x16) = 4;
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, 0x20, 0xA);
        F(s8, 0x14) = -1;
        F(s16, 0x88) = 0;
        F(s16, 0xA) = 0xA0;
        F(s16, 0xE) = 0x38;
        {
            s32 py;
            struct X4_PlayerObj* pl = &g_Player;
            F(s16, 0x8C) = pl->x_pos.u.hi;
            py = pl->y_pos.u.hi;
            F(u8, 0x5) = 0;
            F(s16, 0x8E) = py;
        }
        ((void (*)(s32, s32, void*))play_sound)(2, 0x30, arg0);
        break;
    case 0x10:
        F(u8, 0x60) = 6;
        F(u8, 0x3) = 0;
        F(s16, 0x88) = 3;
        F(u8, 0x5) = 1;
        break;
    case 0x20:
        F(void*, 0x50) = &D_800FCBA4;
        F(u8, 0x62) = 5;
        F(u8, 0x3) = 0;
        F(u8, 0x60) = 4;
        F(s16, 0x88) = 6;
        F(u8, 0x5) = 2;
        break;
    case 0x30:
        ((void (*)(s32, s32, void*))play_sound)(2, 0x3A, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0x3E);
        x = F(u16, 0xA);
        F(u8, 0x16) = 0x22;
        F(u16, 0x8C) = x;
        if (F(u8, 0x15) == 0) {
            F(u16, 0xA) = x + 0x80;
        } else {
            F(u16, 0xA) = x - 0x80;
        }
        F(u8, 0x3) = 1;
        F(u8, 0x60) = 4;
        F(void*, 0x50) = &D_800FCBA8;
        F(s16, 0x88) = 6;
        F(u8, 0x5) = 3;
        break;
    }
    F(u8, 0x4) = 1;
    F(u8, 0x6) = 0;
    F(u8, 0x7) = 0;
}
