#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8008EC10;
extern u16 D_80090D6A;
extern struct X4_BackgroundObj D_800971F8[3];
extern u16 D_800A21B8[3][32][64];
extern u8 D_800CD338;
extern u8 D_800CD339;

void func_800269F4(u8 arg0) {
    s32 px0;
    u32 col0;
    s32 rx0;
    s32 n;
    struct X4_BackgroundObj* bg;
    struct X4_BackgroundObj* base;
    struct X4_BackgroundObj* parent;
    s8 p;
    s32 x;
    s32 y;
    u32 col;
    u32 row;
    s32 rx;
    s32 px;
    s32 ry;
    s32 py;
    u8 tile;
    s32 t;
    s8 i;
    s8 j;
    u8** tm;

    tm = &SP_BG_TILEMAP;
    base = D_800971F8;
    bg = &base[arg0];
    p = bg->pad51[1];
    if (p < 0) {
        x = bg->x_pos.i.hi / 16;
        y = bg->y_pos.i.hi / 16;
    } else {
        parent = &base[p];
        x = (bg->x_pos.i.hi + parent->x_pos.i.hi) / 16;
        y = (bg->y_pos.i.hi + parent->y_pos.i.hi) / 16;
    }
    n = 0x22;
    if (D_80090D6A == 0) {
        n = 0x16;
    }
    col0 = col = x / 16;
    row = y / 16;
    rx0 = x & 0x3F;
    ry = y & 0x1F;
    px0 = x & 0xF;
    py = y & 0xF;
    for (j = 0; j < 0x11; j++) {
        px = px0;
        rx = rx0;
        if (col >= D_800CD338 || row >= D_800CD339) {
            t = 0;
        } else {
            t = *(*tm + arg0 * D_8008EC10 + D_800CD338 * row + col);
        }
        tile = t;
        for (i = 0; i < n; i++) {
            D_800A21B8[arg0][ry][rx] =
                *(SP_BG_TILE_PIXELS + tile * 256 + py * 16 + px);
            rx++;
            px++;
            rx &= 0x3F;
            if (px == 16) {
                col++;
                px = 0;
                if (col >= D_800CD338 || row >= D_800CD339) {
                    t = 0;
                } else {
                    t = *(*tm + arg0 * D_8008EC10 + D_800CD338 * row + col);
                }
                tile = t;
            }
        }
        col = col0;
        ry = (ry + 1) & 0x1F;
        py++;
        if (py == 16) {
            py = 0;
            row++;
        }
    }
    D_800971F8[arg0].unk4C = 0;
}
