#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8008EC10;
extern u8 D_800CD338;
extern u8 D_800CD339;

void func_80027FA4(s32 arg0, s32 arg1, s32 arg2) {
    s32 px;
    s32 py;
    u32 col;
    u32 row;
    u8 tile;

    px = (arg1 & 0xF0) / 16;
    py = (arg2 & 0xF0) / 16;
    col = arg1 / 256;
    row = arg2 / 256;
    if (col >= D_800CD338 || row >= D_800CD339) {
        tile = 0;
    } else {
        tile = *(SP_BG_TILEMAP + arg0 * D_8008EC10 + D_800CD338 * row + col);
    }
    *(SP_BG_TILE_PIXELS + tile * 256 + py * 16 + px) = 0;
}
