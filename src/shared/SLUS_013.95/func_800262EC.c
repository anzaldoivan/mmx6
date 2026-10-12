#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8008EC10;
extern u8 D_800CD338;
extern u8 D_800CD339;

void func_800262EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 sx;
    s32 sy;
    s32 dx;
    s32 dy;
    u32 col;
    u32 row;
    u32 col2;
    u32 row2;
    s32 t;
    u8 tile;

    sx = (arg3 & 0xF0) / 16;
    sy = (arg4 & 0xF0) / 16;
    dx = (arg1 & 0xF0) / 16;
    dy = (arg2 & 0xF0) / 16;
    col = arg3 / 256;
    row = arg4 / 256;
    if (col >= D_800CD338 || row >= D_800CD339) {
        t = 0;
    } else {
        t = *(SP_BG_TILEMAP + arg0 * D_8008EC10 + D_800CD338 * row + col);
    }
    tile = t;
    col2 = arg1 / 256;
    row2 = arg2 / 256;
    if (col2 >= D_800CD338 || row2 >= D_800CD339) {
        t = 0;
    } else {
        t = *(SP_BG_TILEMAP + arg0 * D_8008EC10 + D_800CD338 * row2 + col2);
    }
    *(SP_BG_TILE_PIXELS + t * 256 + dy * 16 + dx) =
        *(SP_BG_TILE_PIXELS + tile * 256 + sy * 16 + sx);
}
