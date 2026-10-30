#include "common.h"
#include "mmx6/x4.h"

extern u16 g_tilemap_layer_stride;
extern u16 D_800A21B8[3][32][64];
extern u8 g_tilemap_width;
extern u8 g_tilemap_height;

void func_80027E84(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 rx;
    s32 ry;
    s32 px;
    s32 py;
    u32 col;
    u32 row;
    u8 tile;

    rx = (arg1 & 0x3FF) / 16;
    ry = (arg2 & 0x1FF) / 16;
    px = (arg3 & 0xF0) / 16;
    py = (arg4 & 0xF0) / 16;
    col = arg3 / 256;
    row = arg4 / 256;
    if (col >= g_tilemap_width || row >= g_tilemap_height) {
        tile = 0;
    } else {
        tile = *(SP_BG_TILEMAP + arg0 * g_tilemap_layer_stride + g_tilemap_width * row + col);
    }
    D_800A21B8[arg0][ry][rx] = *(SP_BG_TILE_PIXELS + tile * 256 + py * 16 + px);
}
