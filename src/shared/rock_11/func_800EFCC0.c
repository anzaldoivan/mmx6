#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
s32 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_800F402C(void*, s32);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800FD516;
extern s16 D_800FD518;
extern s8 D_800FD51A;
extern s8 D_800FD51B;

#define F(type, off) M2C_FIELD(self, type*, off)

static inline u8 tile_hit_800EFCC0(s32 c) {
    if (c == 0) {
        return 0;
    }
    if (c >= 0) {
        if (c < 0x30) {
            if (c >= 0x25) {
                return 0;
            }
            return 1;
        }
    }
    return 1;
}

void func_800EFCC0(struct X4_PlayerObj* self) {
    s32 n;
    s32 c;
    u8 hit;
    s32 d;
    s32 x;
    s32 y;
    s16 t;

    n = 0;
    self->bg_offset = 0;
    self->x_pos.u.hi = F(u16, 0x84);
    self->y_pos.u.hi = F(u16, 0x86);
    self->x_pos.u.hi = background_objects[0].x_pos.u.hi + self->x_pos.u.hi;
    self->y_pos.u.hi = background_objects[0].y_pos.u.hi + self->y_pos.u.hi;
    self->x_vel.val = rcos(F(s16, 0x7C)) << 7;
    self->y_vel.val = rsin(F(s16, 0x7C)) << 7;
    do {
        move_object(self);
        c = func_80030234(self, self->x_pos.i.hi, self->y_pos.i.hi) & 0xFF;
        hit = tile_hit_800EFCC0(c);
        if (hit) {
            n = 1000;
        }
        if ((u32)(self->x_pos.i.hi - background_objects[0].x_pos.i.hi + 0x10) >=
                0x161 ||
            (d = self->y_pos.i.hi - background_objects[0].y_pos.i.hi,
             d < -0x10) ||
            d > 0x100) {
            n = 1000;
        }
        n++;
    } while (n < 0x46);
    self->bg_offset = -1;
    x = self->x_pos.u.hi - background_objects[0].x_pos.u.hi;
    self->x_pos.u.hi = x;
    t = F(s16, 0x7E);
    y = self->y_pos.u.hi - background_objects[0].y_pos.u.hi;
    self->y_pos.u.hi = y;
    D_800FD516 = x;
    D_800FD518 = y;
    if (t != 0) {
        F(s16, 0x7C) -= 0x14;
        if (F(s16, 0x7C) < 0xA01) {
            F(s16, 0x7E) = 0;
            return;
        }
    } else {
        F(s16, 0x7C) += 0x14;
        if (F(s16, 0x7C) >= 0xE00) {
            F(s16, 0x7E) = 1;
        }
    }
    if (D_800FD51B == 0) {
        self->on_screen = 1;
        func_800F402C(self, 4);
    } else if (D_800FD51B == 1) {
        u16 v;
        self->bg_offset = -1;
        D_800FD516 = v = g_Player.x_pos.u.hi - background_objects[0].x_pos.u.hi;
        D_800FD518 = g_Player.y_pos.u.hi - background_objects[0].y_pos.u.hi;
        self->x_pos.u.hi = v;
        self->y_pos.u.hi =
            g_Player.y_pos.u.hi - background_objects[0].y_pos.u.hi;
        func_800F402C(self, 4);
        F(s16, 0x7C) = 0x3C;
        self->unk6++;
    }
    D_800FD51A = self->on_screen;
}
