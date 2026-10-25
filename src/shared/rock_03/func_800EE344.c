#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define F16(n) M2C_FIELD(self, s16*, (n))

extern struct X4_PlayerObj g_Player;
extern u16 D_800F7784[];

void func_800EE344(struct X4_BaseObj* self) {
    u16* rect;
    s32 step;
    s32 neg;
    u16 cx;
    u16 cy;
    u16 w;
    u16 h;
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;
    s32 n;

    rect = M2C_FIELD(self, u16**, 0x3C);
    cx = rect[0];
    w = rect[2];
    cy = rect[1];
    h = rect[3];
    F16(0x40) += M2C_FIELD(self, u16*, 0x42);
    left = cx - w;
    right = cx + w;
    top = cy - h;
    bottom = cy + h;
    if ((u16)(F16(0x40) + 0x80) > 0x100) {
        neg = F16(0x42);
        F16(0x42) = -neg;
    }
    if (g_Player.x_pos.i.hi < left || right < g_Player.x_pos.i.hi ||
        g_Player.y_pos.i.hi < top || bottom < g_Player.y_pos.i.hi) {
        if (--M2C_FIELD(self, s32*, 0x38) < 0) {
            M2C_FIELD(self, s32*, 0x38) = 0;
            F16(0x34) = 0;
            return;
        }
    } else {
        if (++M2C_FIELD(self, s32*, 0x38) >= 0x40) {
            M2C_FIELD(self, s32*, 0x38) = 0x3F;
        }
    }
    if (self->unk2 >= 0x40) {
        F16(0x1E) = 0x100;
        F16(0x26) = 0x100;
        F16(0x2A) = 0;
        F16(0x2E) = 0;
        F16(0x32) = 0;
        F16(0x16) = F16(0x40) + 0x78;
        F16(0x1A) = -self->y_pos.i.hi;
        F16(0x22) = -self->y_pos.i.hi;
    } else if (self->unk2 >= 0x30) {
        F16(0x16) = -0x100;
        F16(0x2E) = -0x100;
        F16(0x26) = 0;
        F16(0x2A) = 0;
        F16(0x32) = 0;
        F16(0x1A) = -self->y_pos.i.hi;
        F16(0x1E) = F16(0x40) - 0x78;
        F16(0x22) = -self->y_pos.i.hi;
    } else if (self->unk2 >= 0x20) {
        F16(0x16) = 0;
        F16(0x1A) = 0;
        F16(0x22) = 0;
        F16(0x1E) = 0x100;
        F16(0x26) = 0x100;
        F16(0x2E) = F16(0x40) + 0x78;
        F16(0x2A) = 0xF0;
        F16(0x32) = 0xF0;
    } else if (self->unk2 >= 0x10) {
        F16(0x16) = -0x100;
        F16(0x1A) = 0;
        F16(0x1E) = 0;
        F16(0x22) = 0;
        F16(0x2A) = 0xF0;
        F16(0x2E) = -0x100;
        F16(0x32) = 0xF0;
        F16(0x26) = F16(0x40) - 0x78;
    }
    n = M2C_FIELD(self, s32*, 0x38);
    F16(0x34) = D_800F7784[n / 4];
    self->on_screen = 1;
}
