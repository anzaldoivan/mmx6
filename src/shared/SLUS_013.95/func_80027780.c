#include "common.h"
#include "mmx6/x4.h"

extern u16 g_tilemap_layer_stride;
extern u16 g_wide_mode;
extern u16 D_800A21B8[3][32][64];
extern u8 g_tilemap_width;
extern u8 g_tilemap_height;

void func_80027780(s32 arg0, s32 arg1, s32 arg2) {
    u32 n;
    u32 col;
    u32 row;
    s32 rx;
    s32 ry;
    s32 px;
    s32 py;
    s32 t;
    u8 t2;
    u8 tile;
    u32 i;
    u8** tm;

    if (arg2 >= 0) {
        col = arg1 / 256;
        row = arg2 / 256;
        rx = arg1 % 1024 / 16;
        ry = arg2 % 512 / 16;
        px = rx & 0xF;
        py = ry & 0xF;
        n = 0x21;
        if (g_wide_mode == 0) {
            n = 0x15;
        }
        if (col >= g_tilemap_width || row >= g_tilemap_height) {
            t = 0;
        } else {
            t = *(SP_BG_TILEMAP + arg0 * g_tilemap_layer_stride + g_tilemap_width * row + col);
        }
        tile = t;
        tm = &SP_BG_TILEMAP;
        for (i = 0; i < n; i++) {
            D_800A21B8[arg0][ry][rx] =
                *(SP_BG_TILE_PIXELS + tile * 256 + py * 16 + px);
            rx++;
            rx &= 0x3F;
            px++;
            if (px == 16) {
                px = 0;
                col++;
                if (col >= g_tilemap_width || row >= g_tilemap_height) {
                    t = 0;
                    t2 = t;
                } else {
                    t = *(*tm + arg0 * g_tilemap_layer_stride + g_tilemap_width * row + col);
                    t2 = t;
                }
                tile = t2;
            }
        }
    }
}
