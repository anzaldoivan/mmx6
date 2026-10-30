#include "common.h"
#include "mmx6/x4.h"

extern u16 g_tilemap_layer_stride;
extern u16 g_wide_mode;
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800A21B8[3][32][64];
extern u8 g_tilemap_width;
extern u8 g_tilemap_height;

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
    base = background_objects;
    bg = &base[arg0];
    p = bg->pad52[0];
    if (p < 0) {
        x = bg->x_pos.i.hi / 16;
        y = bg->y_pos.i.hi / 16;
    } else {
        parent = &base[p];
        x = (bg->x_pos.i.hi + parent->x_pos.i.hi) / 16;
        y = (bg->y_pos.i.hi + parent->y_pos.i.hi) / 16;
    }
    n = 0x22;
    if (g_wide_mode == 0) {
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
        if (col >= g_tilemap_width || row >= g_tilemap_height) {
            t = 0;
        } else {
            t = *(*tm + arg0 * g_tilemap_layer_stride + g_tilemap_width * row + col);
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
                if (col >= g_tilemap_width || row >= g_tilemap_height) {
                    t = 0;
                } else {
                    t = *(*tm + arg0 * g_tilemap_layer_stride + g_tilemap_width * row + col);
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
    background_objects[arg0].unk4C = 0;
}
