#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8008EC10;
extern u16 D_80090D6A;
extern u16 D_800A21B8[3][32][64];
extern u8 D_800CD338;
extern u8 D_800CD339;

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
        if (D_80090D6A == 0) {
            n = 0x15;
        }
        if (col >= D_800CD338 || row >= D_800CD339) {
            t = 0;
        } else {
            t = *(SP_BG_TILEMAP + arg0 * D_8008EC10 + D_800CD338 * row + col);
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
                if (col >= D_800CD338 || row >= D_800CD339) {
                    t = 0;
                    t2 = t;
                } else {
                    t = *(*tm + arg0 * D_8008EC10 + D_800CD338 * row + col);
                    t2 = t;
                }
                tile = t2;
            }
        }
    }
}
