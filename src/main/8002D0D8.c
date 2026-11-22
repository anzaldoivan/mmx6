#include "common.h"

extern u32 D_800737A8[];

s32 func_8002D0D8(s32 x, s32 y) {
    s32 sx;
    s32 sy;
    s32 q;
    // !FAKE: depin: dropping it breaks the match (2/86)
    register s32 v asm("$2");
    // !FAKE: depin: dropping it breaks the match (56/86)
    register s32 t asm("$3");
    s16 a;
    u32* p;

    v = y;
    if (x < 0) {
        sx = 1;
        x = -x;
    } else {
        sx = -1;
    }
    sy = 1;
    if (y < 0) {
        sy = -1;
        v = -y;
    }
    t = v >> 16;
    if (t != 0) {
        q = x / t;
        if (q <= 0xFFFF) {
            p = &D_800737A8[4];
            while (q < *p) {
                p--;
            }
            a = p - D_800737A8;
        } else {
            p = &D_800737A8[5];
            while (*p < q) {
                p++;
            }
            a = (p - D_800737A8) - 1;
        }
    } else {
        a = 8;
    }
    if (sy < 0) {
        if (sx > 0) {
            if (a == 8) {
                return 0;
            }
            return (u8)(a + 0x18);
        }
        return (u8)(0x18 - a);
    } else if (sx > 0) {
        return (u8)(8 - a);
    } else {
        return (u8)(a + 8);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s32 D_8009719C;

M2C_UNK apply_object_motion(struct X4_MainObj* self) {
    s32 vy;
    s32* vyp;

    self->x_pos.val += self->x_speed;
    self->y_pos.val -= self->y_speed;
    if (self->unk15 != 0) {
        self->x_speed = self->x_speed + self->x_accel;
    } else {
        self->x_speed = self->x_speed - self->x_accel;
    }
    vyp = &self->y_speed;
    vy = *vyp - self->gravity;
    *vyp = vy;
    if (vy < D_8009719C) {
        *vyp = D_8009719C;
    }
}
