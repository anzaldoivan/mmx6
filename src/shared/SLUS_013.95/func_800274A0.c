#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8008EC10;
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800A21B8[3][32][64];
extern u8 D_800CD338;
extern u8 D_800CD339;

void func_800274A0(s32 arg0, s32 arg1, s32 arg2) {
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
    struct X4_BackgroundObj* bg;
    struct X4_BackgroundObj* bg2;
    struct X4_BackgroundObj* base2;
    u8 lo;
    u8 hi;
    u8 mm;
    struct X4_BackgroundObj* base;

    if (arg1 >= 0) {
        if (arg2 < 0) {
            arg2 = 0;
            n = 0x11;
        } else {
            n = 0x12;
        }
        col = arg1 / 256;
        row = arg2 / 256;
        rx = arg1 % 1024 / 16;
        ry = arg2 % 512 / 16;
        py = ry & 0xF;
        px = rx & 0xF;
        base = background_objects;
        bg = &base[arg0];
        lo = bg->unk4D;
        if (col < lo) {
            hi = bg->unk4E;
            col += 1 + (hi - lo);
            if (bg->x_pos.i.hi <= (lo - 1) << 8) {
                bg->x_pos.i.hi = hi << 8;
                return;
            }
        }
        base2 = background_objects;
        bg2 = &base2[arg0];
        lo = bg2->unk4E;
        if (lo < col) {
            mm = bg2->unk4D;
            t = col - 1;
            col = t - lo;
            col += mm;
            if (bg2->x_pos.i.hi >= (lo + 1) << 8) {
                bg2->x_pos.i.hi = mm << 8;
                return;
            }
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
            ry++;
            ry &= 0x1F;
            py++;
            if (py == 16) {
                py = 0;
                row++;
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
