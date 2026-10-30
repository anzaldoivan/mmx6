#include "common.h"

extern s8 D_8008EAB0;
extern u16 g_wide_mode;
extern u8 D_80097438[];
extern u8 g_bg_sprite_prims[];
extern u8 D_800CC870[];

#define SCRATCH_04 (*(u8**)0x1F800004)

#define GET_TPAGE(tp, abr, x, y)                                               \
    ((((tp) & 0x3) << 7) | (((abr) & 0x3) << 5) | (((y) & 0x100) >> 4) |       \
     (((x) & 0x3FF) >> 6) | (((y) & 0x200) << 2))
#define SET_DRAW_TPAGE(p, tpage)                                               \
    ((p)[3] = 1, *(u32*)((p) + 4) = 0xE1000000 | ((tpage) & 0x9FF))

void func_8002649C(s32 arg0, s32 arg1) {
    u32 i;
    u32 j;
    u32 k;
    u16 x;

    D_8008EAB0 = 0;
    if (g_wide_mode == 0) {
        for (i = 0; i < 2; i++) {
            {
                u8* p;
                for (j = 0; j < 0x400; j++) {
                    p = g_bg_sprite_prims + (i * 0x4000 + j * 16);
                    p[3] = 3;
                    p[7] = 0x7D;
                }
            }
            for (j = 0; j < 6; j++) {
                u8* p = D_800CC870 + i * 0x330 + j * 0x88;
                x = 0x140;
                for (k = 0; k < 8; k++) {
                    SET_DRAW_TPAGE(p, GET_TPAGE(arg0, arg1, x, 256));
                    p += 8;
                    x += 0x40;
                }
            }
            for (j = 0; j < 6; j++) {
                u8* p = D_800CC870 + i * 0x330 + j * 0x88 + 0x40;
                x = 0x140;
                for (k = 0; k < 4; k++) {
                    SET_DRAW_TPAGE(p, GET_TPAGE(1, arg1, x, 256));
                    p += 8;
                    x += 0x80;
                }
            }
            for (j = 0; j < 6; j++) {
                u8* p = D_800CC870 + i * 0x330 + j * 0x88 + 0x60;
                x = 0x180;
                for (k = 0; k < 5; k++) {
                    SET_DRAW_TPAGE(p, GET_TPAGE(1, arg1, x, 0));
                    p += 8;
                    x += 0x80;
                }
            }
        }
    } else {
        for (i = 0; i < 2; i++) {
            {
                u8* p;
                for (j = 0; j < 0x400; j++) {
                    p = g_bg_sprite_prims + (i * 0x4000 + j * 16);
                    p[3] = 3;
                    p[7] = 0x7D;
                }
            }
            for (j = 0; j < 6; j++) {
                u8* p = D_800CC870 + i * 0x330 + j * 0x88;
                x = 0x200;
                for (k = 0; k < 8; k++) {
                    SET_DRAW_TPAGE(p, GET_TPAGE(arg0, arg1, x, 0));
                    p += 8;
                    x += 0x40;
                }
            }
            for (j = 0; j < 6; j++) {
                u8* p = D_800CC870 + i * 0x330 + j * 0x88 + 0x40;
                x = 0x200;
                for (k = 0; k < 4; k++) {
                    SET_DRAW_TPAGE(p, GET_TPAGE(1, arg1, x, 0));
                    p += 8;
                    x += 0x80;
                }
            }
            for (j = 0; j < 6; j++) {
                u8* p = D_800CC870 + i * 0x330 + j * 0x88 + 0x60;
                x = 0xC0;
                for (k = 0; k < 5; k++) {
                    SET_DRAW_TPAGE(p, GET_TPAGE(1, arg1, x, 256));
                    p += 8;
                    x += 0x80;
                }
            }
        }
    }
    SCRATCH_04 = D_80097438;
}
