#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
s32 func_80065944(s32);
s32 func_80065A14(s32);
extern s16 D_800115B0[16][2];
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;

void func_80041770(void* arg0) {
    s16 tbl[16][2];
    void* ext;
    void* parent;
    X4_f32 px;
    X4_f32 py;
    s16 ang;
    s16 ang2;
    s16 bx;
    s16 by;
    s16 r;
    s16 q;
    s16 cx;
    s16 cy;
    s16 z;
    s32 dx;
    s32 dy;
    s32 n;
    s32 t;
    s32 w;
    s32 k;
    s32 a;
    u16 bgx;
    u16 bgy;
    s32 y;
    // !FAKE: depin: dropping it breaks the match (200/210)
    register s32 e asm("$4");

    __builtin_memcpy(tbl, D_800115B0, sizeof(tbl));
    M2C_FIELD(arg0, s8*, 3) = 1;
    a = M2C_FIELD(arg0, u16*, 0x46) & 0xFFF;
    ang = a;
    parent = M2C_FIELD(arg0, void**, 0x5C);
    bx = M2C_FIELD(parent, s16*, 0xA) + tbl[(a << 16) >> 24][0];
    by = M2C_FIELD(parent, s16*, 0xE) + tbl[(a << 16) >> 24][1];
    px.i.hi = bx;
    py.i.hi = by;
    ext = (s8*)arg0 + 0x38;
    dx = func_80065A14(ang) << 6;
    dy = -func_80065944(ang) << 6;
    for (n = 0; n < M2C_FIELD(arg0, s16*, 0x4C); n++) {
        px.val += dx;
        py.val += dy;
    }
    ang2 = (ang + 0x400) & 0xFFF;
    t = func_80065A14(ang2);
    w = M2C_FIELD(arg0, s16*, 0x4E) + 1;
    r = (t * (s16)(((s16)(n >> 2) >> 1) + w)) >> 12;
    t = func_80065944(ang2);
    z = py.i.hi;
    bgx = background_objects[0].x_pos.i.hi;
    bgy = background_objects[0].y_pos.i.hi;
    bx -= bgx;
    by -= bgy;
    e = bx + (r >> 2);
    M2C_FIELD(arg0, s16*, 0x16) = e;
    M2C_FIELD(arg0, s16*, 0x1E) = bx - (r >> 2);
    cx = px.i.hi - bgx;
    M2C_FIELD(arg0, s16*, 0x26) = cx - r;
    M2C_FIELD(arg0, s16*, 0x2E) = cx + r;
    k = M2C_FIELD(arg0, s16*, 0x4E) + 1;
    q = (-t * (s16)(((s16)(n >> 2) >> 1) + k)) >> 12;
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
    M2C_FIELD(arg0, u16*, 0x46) -= M2C_FIELD(arg0, u16*, 0x4A);
    if ((s16)(M2C_FIELD(ext, s16*, 0x14) = M2C_FIELD(arg0, u16*, 0x4C) - 1) ==
        0) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s16*, 0x4C) = n;
        M2C_FIELD(arg0, u8*, 4) += 1;
    }
}
