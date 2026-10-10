#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80065944(s32);
s32 func_80065A14(s32);
extern s32 D_80097420;
extern u8 D_800E99B4[];

void func_800F1264(void* self) {
    s16 tbl[16][2];
    X4_f32 px;
    X4_f32 py;
    void* parent;
    void* q;
    s32 ang;
    s32 a;
    s32 dx;
    s32 dy;
    s32 i;
    s32 ox;
    s32 oy;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;

    __builtin_memcpy(tbl, D_800E99B4, 0x40);
    parent = M2C_FIELD(self, void**, 0x5C);
    ang = (s16)M2C_FIELD(parent, u16*, 0x88);
    x0 = M2C_FIELD(parent, u16*, 0xA) + tbl[ang >> 8][0];
    y0 = M2C_FIELD(parent, u16*, 0xE) + tbl[ang >> 8][1];
    px.i.hi = x0;
    py.i.hi = y0;
    dx = func_80065A14(ang) << 8;
    dy = -func_80065944(ang) << 8;
    i = 0;
    do {
        px.val += dx;
        py.val += dy;
        if ((u16)(px.i.hi + 0x10) >= 0x161 || py.i.hi < -0x10 ||
            py.i.hi >= 0x101) {
            i = 1000;
        }
        i++;
    } while (i < 50);
    x1 = px.i.hi;
    y1 = py.i.hi;

    switch (M2C_FIELD(self, u8*, 0x2) & 0xF) {
    case 0:
        a = ang - 0x400;
        a &= 0xFFF;
        ox = (func_80065A14(a) * 0x60) >> 16;
        oy = (-func_80065944(a) * 0x60) >> 16;
        M2C_FIELD(self, s16*, 0x16) = x0 + ox;
        M2C_FIELD(self, s16*, 0x1A) = y0 + oy;
        M2C_FIELD(self, s16*, 0x1E) = x0;
        M2C_FIELD(self, s16*, 0x22) = y0;
        M2C_FIELD(self, s16*, 0x26) = x1;
        M2C_FIELD(self, s16*, 0x2A) = y1;
        M2C_FIELD(self, s16*, 0x2E) = x1 + ox;
        M2C_FIELD(self, s16*, 0x32) = y1 + oy;
        break;
    case 1:
        a = ang + 0x400;
        a &= 0xFFF;
        ox = (func_80065A14(a) * 0x60) >> 16;
        oy = (-func_80065944(a) * 0x60) >> 16;
        M2C_FIELD(self, s16*, 0x1E) = x0 + ox;
        M2C_FIELD(self, s16*, 0x22) = y0 + oy;
        M2C_FIELD(self, s16*, 0x16) = x0;
        M2C_FIELD(self, s16*, 0x1A) = y0;
        M2C_FIELD(self, s16*, 0x26) = x1 + ox;
        M2C_FIELD(self, s16*, 0x2A) = y1 + oy;
        M2C_FIELD(self, s16*, 0x2E) = x1;
        M2C_FIELD(self, s16*, 0x32) = y1;
        break;
    case 2:
        a = ang - 0x400;
        a &= 0xFFF;
        ox = (func_80065A14(a) * 0x80) >> 16;
        oy = (-func_80065944(a) * 0x80) >> 16;
        M2C_FIELD(self, s16*, 0x16) = x0 + ox;
        M2C_FIELD(self, s16*, 0x1A) = y0 + oy;
        M2C_FIELD(self, s16*, 0x1E) = x0;
        M2C_FIELD(self, s16*, 0x22) = y0;
        M2C_FIELD(self, s16*, 0x26) = x1;
        M2C_FIELD(self, s16*, 0x2A) = y1;
        M2C_FIELD(self, s16*, 0x2E) = x1 + ox;
        M2C_FIELD(self, s16*, 0x32) = y1 + oy;
        break;
    case 3:
        a = ang + 0x400;
        a &= 0xFFF;
        ox = (func_80065A14(a) * 0x80) >> 16;
        oy = (-func_80065944(a) * 0x80) >> 16;
        M2C_FIELD(self, s16*, 0x1E) = x0 + ox;
        M2C_FIELD(self, s16*, 0x22) = y0 + oy;
        M2C_FIELD(self, s16*, 0x16) = x0;
        M2C_FIELD(self, s16*, 0x1A) = y0;
        M2C_FIELD(self, s16*, 0x26) = x1 + ox;
        M2C_FIELD(self, s16*, 0x2A) = y1 + oy;
        M2C_FIELD(self, s16*, 0x2E) = x1;
        M2C_FIELD(self, s16*, 0x32) = y1;
        break;
    }

    switch ((u32)D_80097420 % 3) {
    case 0:
        M2C_FIELD(self, u8*, 0x3) = 1;
        M2C_FIELD(self, u8*, 0x0) = 3;
        break;
    case 1:
        M2C_FIELD(self, u8*, 0x3) = 0;
        break;
    case 2:
        M2C_FIELD(self, u8*, 0x3) = 1;
        M2C_FIELD(self, u8*, 0x0) = 0x13;
        break;
    }

    q = (s8*)self + 0x38;
    if ((M2C_FIELD(q, s16*, 0x10) = M2C_FIELD(self, u16*, 0x48) - 1) == 0) {
        M2C_FIELD(self, u16*, 0x48) = 0;
        M2C_FIELD(self, u8*, 0x6)++;
    }
    M2C_FIELD(self, s16*, 0x44) = x0;
    M2C_FIELD(self, s16*, 0x46) = y0;
    M2C_FIELD(self, s16*, 0x40) = x1;
    M2C_FIELD(self, s16*, 0x42) = y1;
}
