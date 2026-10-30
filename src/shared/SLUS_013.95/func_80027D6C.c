#include "common.h"
#include "mmx6/x4.h"

extern u16 g_tilemap_layer_stride;
extern u16 D_800A21B8[3][32][64];
extern u8 g_tilemap_width;
extern u8 g_tilemap_height;

void func_80027D6C(u32 arg0, s32 arg1, s32 arg2) {
    u32 col;
    u32 row;
    s32 rx;
    s32 ry;
    s32 px;
    s32 py;
    s32 t;
    u8 tile;

    col = arg1 / 16;
    row = arg2 / 16;
    rx = arg1 % 64;
    ry = arg2 % 32;
    px = rx & 0xF;
    py = ry & 0xF;
    if (col >= g_tilemap_width || row >= g_tilemap_height) {
        t = 0;
    } else {
        t = *(SP_BG_TILEMAP + arg0 * g_tilemap_layer_stride + g_tilemap_width * row + col);
    }
    tile = t;
    D_800A21B8[arg0][ry][rx] = *(SP_BG_TILE_PIXELS + tile * 256 + py * 16 + px);
}
