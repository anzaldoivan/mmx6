#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
extern s16 D_800115B0[16][2];
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;

void func_800413D0(void* arg0) {
    s16 tbl[16][2];
    void* parent;
    X4_f32 px;
    X4_f32 py;
    s16 ang;
    s16 ang2;
    s16 bx;
    s16 by;
    s16 h;
    s16 cx;
    s16 cy;
    s32 dx;
    s32 dy;
    s32 n;
    s16 r;
    s16 q;
    s32 t;
    s32 w;
    // !FAKE: depin: dropping it breaks the match (201/232)
    register s32 x asm("$5");
    s32 y;
    s32 k;
    s32 a;
    s32 z;
    u16 bgx;
    u16 bgy;

    __builtin_memcpy(tbl, D_800115B0, sizeof(tbl));
    n = 0;
    M2C_FIELD(arg0, s8*, 3) = 1;
    a = M2C_FIELD(arg0, u16*, 0x46) & 0xFFF;
    ang = a;
    parent = M2C_FIELD(arg0, void**, 0x5C);
    bx = M2C_FIELD(parent, s16*, 0xA) + tbl[(a << 16) >> 24][0];
    by = M2C_FIELD(parent, s16*, 0xE) + tbl[(a << 16) >> 24][1];
    px.i.hi = bx;
    py.i.hi = by;
    dx = rcos(ang) << 8;
    dy = -rsin(ang) << 8;
    do {
        px.val += dx;
        py.val += dy;
        if (px.i.hi < background_objects[0].x_pos.i.hi - 0x10) {
            break;
        }
        if (background_objects[0].x_pos.i.hi + 0x150 < px.i.hi) {
            break;
        }
        if (py.i.hi < background_objects[0].y_pos.i.hi - 0x30) {
            break;
        }
        if (background_objects[0].y_pos.i.hi + 0x100 < py.i.hi) {
            break;
        }
        n++;
    } while (n < 50);
    ang2 = (ang + 0x400) & 0xFFF;
    t = rcos(ang2);
    w = M2C_FIELD(arg0, s16*, 0x4E) + 1;
    r = (t * (s16)(((s16)n >> 1) + w)) >> 12;
    t = rsin(ang2);
    x = px.i.hi;
    z = py.i.hi;
    bgx = background_objects[0].x_pos.i.hi;
    bgy = background_objects[0].y_pos.i.hi;
    bx -= bgx;
    by -= bgy;
    M2C_FIELD(arg0, s16*, 0x16) = bx + (r >> 2);
    M2C_FIELD(arg0, s16*, 0x1E) = bx - (r >> 2);
    cx = x - bgx;
    M2C_FIELD(arg0, s16*, 0x26) = cx - r;
    M2C_FIELD(arg0, s16*, 0x2E) = cx + r;
    M2C_FIELD(arg0, u16*, 0x46) -= M2C_FIELD(arg0, u16*, 0x4A);
    k = M2C_FIELD(arg0, s16*, 0x4E) + 1;
    q = (-t * (s16)(((s16)n >> 1) + k)) >> 12;
    y = q >> 2;
    M2C_FIELD(arg0, s16*, 0x1A) = by + y;
    M2C_FIELD(arg0, s16*, 0x22) = by - y;
    cy = z - bgy;
    M2C_FIELD(arg0, s16*, 0x2A) = cy - q;
    M2C_FIELD(arg0, s16*, 0x32) = cy + q;
    if ((D_80097420 + M2C_FIELD(arg0, s8*, 2)) & 1) {
        M2C_FIELD(arg0, s16*, 0x34) = (func_8002D2D4() & 1) + 0x1A;
    } else {
        M2C_FIELD(arg0, s16*, 0x34) = 0x1C;
    }
    if (M2C_FIELD(arg0, s16*, 0x46) <= M2C_FIELD(arg0, s16*, 0x48) ||
        M2C_FIELD(arg0, s8*, 7) != M2C_FIELD(parent, s8*, 6)) {
        M2C_FIELD(arg0, s16*, 0x4C) = n * 4;
        M2C_FIELD(arg0, u8*, 5) += 1;
    }
}
