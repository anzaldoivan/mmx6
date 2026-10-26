#include "common.h"
#include "mmx6/x4.h"

extern u32* D_8008EC18[2][102];
extern u16 D_80090D6A;
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800A21B8[3][32][64];

#define SP_PRIM_PTR (*(u8**)SP(0x108))
#define SP_PRIM_COUNT (*(s32*)SP(0x11C))

void func_800270D0(s32 arg0) {
    struct X4_BackgroundObj* bg;
    struct X4_BackgroundObj* parent;
    struct X4_BackgroundObj* base;
    u8* prim;
    s8 p;
    s32 x;
    s32 y;
    s32 buf;
    s32 col0;
    s32 col;
    s32 row;
    s16 px0;
    s16 px;
    s16 py;
    u32 n;
    u32 i;
    u32 j;
    u16 tile;
    u32 attr;
    u32 pri;
    s32 layer;
    u32 slot;

    base = background_objects;
    bg = &base[arg0];
    prim = SP_PRIM_PTR;
    p = bg->pad52[0];
    buf = SP_DRAW_BUFFER;
    if (p < 0) {
        x = bg->x_pos.i.hi;
        y = bg->y_pos.i.hi;
    } else {
        parent = &base[p];
        x = bg->x_pos.i.hi + parent->x_pos.i.hi;
        y = bg->y_pos.i.hi + parent->y_pos.i.hi;
    }
    col0 = (x / 16) & 0x3F;
    px0 = -(x & 0xF);
    row = (y / 16) & 0x1F;
    py = -(y & 0xF);
    n = 0x21;
    if (D_80090D6A == 0) {
        n = 0x15;
    }
    for (j = 0; j < 16; j++) {
        px = px0;
        col = col0;
        for (i = 0; i < n; i++) {
            tile = D_800A21B8[arg0][row][col];
            if (tile != 0) {
                if (SP_PRIM_COUNT >= 1000) {
                    return;
                }
                SP_PRIM_COUNT++;
                attr = SP_BG_TILE_ATTRS[tile & 0x3FFF];
                pri = (attr & 0xFF000000) >> 24;
                if (pri != 0xFF) {
                    *(u16*)(prim + 0xE) = (((attr & 0xF000) >> 6) +
                                           (0x7980 + (pri & 0x40) * 16)) |
                                          ((attr & 0xF00) >> 8);
                    if (tile & 0x4000) {
                        prim[7] |= 2;
                    } else {
                        prim[7] &= ~2;
                    }
                    layer = arg0;
                    *(s16*)(prim + 8) = px;
                    *(s16*)(prim + 0xA) = py;
                    prim[0xC] = (attr >> 12) & 0xF0;
                    prim[0xD] = (attr >> 16) & 0xF0;
                    if (tile & 0x8000) {
                        layer += 3;
                    }
                    slot = pri & 0x3F;
                    *D_8008EC18[buf][layer * 17 + slot] =
                        (*D_8008EC18[buf][layer * 17 + slot] & 0xFF000000) |
                        ((u32)prim & 0xFFFFFF);
                    D_8008EC18[buf][layer * 17 + slot] = (u32*)prim;
                    prim += 16;
                }
            }
            px += 16;
            col++;
            col &= 0x3F;
        }
        py += 16;
        row++;
        row &= 0x1F;
    }
    SP_PRIM_PTR = prim;
}
