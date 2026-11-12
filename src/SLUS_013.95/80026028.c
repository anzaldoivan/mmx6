#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define D_800CD3F0 (*(s8(*)[4]) & D_800CD3F0)

void func_800192CC(void);
void func_8001A278(void);
void func_80022E44(void);
void func_80026128(void);

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PTR(off) (*(u8**)(0x1F800000 + (off)))
#define SCR_COUNT (*(s32*)0x1F800124)

M2C_UNK func_80026028(void) {
    s32 i;
    u8* a;
    u8* b;
    s8 saved;

    i = SCR_BUF;
    SCR_COUNT = 0;
    a = D_800A51B8 + i * 0xA000;
    b = D_800C4858 + (i << 13);
    SCR_PTR(0x100) = a;
    SCR_PTR(0x104) = b;
    SCR_PTR(0x110) = a;
    func_80026128();
    saved = D_800CD3F0[0];
    D_800CD3F0[0] = 0xF;
    func_800192CC();
    D_800CD3F0[0] = saved;
    func_8001A278();
    func_80022E44();
}

#undef D_800CD3F0

#include "common.h"

u32 func_800260C4(s32 arg0, s32 arg1, s32 arg2) {
    s32 r, g, b;
    u32 v;

    r = arg0 * 0x4D;
    g = arg1 * 0x97;
    b = arg2 * 0x1C;
    v = r + g + b;
    if (v > 0xFFFF) {
        v = 0xFFFF;
    }
    v >>= 8;
    return v & 0xFFFF;
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/144A4.c:func_800241E8, AGPL-3.0; proven shared with X6 by exact signature df4775baa321 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_80026128(void) {
    u32 buffer;
    u32 i;
    u32 j;

    buffer = SP_DRAW_BUFFER;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            D_80090D70[buffer][i][j] = NULL;
            D_8008EB08[buffer][i][j] = (X4_P_TAG*)&D_80090D70[buffer][i][j];
        }
    }
}

#include "common.h"

void func_80025984(void*, u8);

void func_8002619C(u8* arg0) {
    if (arg0[0xE7] == 4) {
        func_80025984(arg0, arg0[0xDC]);
        return;
    }
    if ((((s8*)arg0)[5] != 1) || (arg0[0x47] != 0x7E)) {
        func_80025984(arg0, arg0[0xDC]);
    }
}

#include "common.h"

void func_80026204(u16 color, u8* r, u8* g, u8* b) {
    u8 c;

    c = color & 0x1F;
    *r = (c << 3) + (c >> 2);
    c = (color >> 5) & 0x1F;
    *g = (c << 3) + (c >> 2);
    c = color >> 10;
    *b = (c << 3) + (c >> 2);
}

#include "common.h"

u8 func_8002624C(u8 from, u8 to, s32 den, s32 t) {
    if (from == to || den == t) {
        return from;
    }
    if (t == 0) {
        return to;
    }
    if (to < from) {
        return to + (u32)((from - to) * t) / (u32)den;
    }
    return from + (u32)((to - from) * (den - t)) / (u32)den;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u8 g_tilemap_height;

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
    if (col >= g_tilemap_width || row >= g_tilemap_height) {
        t = 0;
    } else {
        t = *(SP_BG_TILEMAP + arg0 * g_tilemap_layer_stride +
              g_tilemap_width * row + col);
    }
    tile = t;
    col2 = arg1 / 256;
    row2 = arg2 / 256;
    if (col2 >= g_tilemap_width || row2 >= g_tilemap_height) {
        t = 0;
    } else {
        t = *(SP_BG_TILEMAP + arg0 * g_tilemap_layer_stride +
              g_tilemap_width * row2 + col2);
    }
    *(SP_BG_TILE_PIXELS + t * 256 + dy * 16 + dx) =
        *(SP_BG_TILE_PIXELS + tile * 256 + sy * 16 + sx);
}

#include "common.h"
#include "mmx6/globals.h"

extern s8 D_8008EAB0;
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

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];
void func_80027D6C(u32, s32, s32);

void func_800268B0(s32 arg0) {
    u32 count;
    u32 i;
    u32 j;
    u32 k;
    s32 y;
    s32 x;

    count = 0x40;
    if (g_wide_mode == 0) {
        count = 0x20;
    }
    for (i = 0; i < 3; i++) {
        y = background_objects[i].y_pos.i.hi / 16 + arg0;
        for (j = 0; j < 0x20; y++, j++) {
            if (y >= 0) {
                x = background_objects[i].x_pos.i.hi / 16 + arg0;
                for (k = 0; k < count; k++, x++) {
                    if (x >= 0) {
                        func_80027D6C(i, x, y);
                    }
                }
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800A21B8[3][32][64];
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
            t = *(*tm + arg0 * g_tilemap_layer_stride + g_tilemap_width * row +
                  col);
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
                    t = *(*tm + arg0 * g_tilemap_layer_stride +
                          g_tilemap_width * row + col);
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

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u8 g_bg_sprite_prims[];

void func_800269F4(u8 arg0);
void func_80026E20(s32 arg0);
void func_80026ECC(s32 arg0);
void func_800270D0(s32 arg0);
void func_800273E4(void);

#define SP_PRIM_PTR (*(u8**)SP(0x108))
#define SP_PRIM_COUNT (*(s32*)SP(0x11C))
#define SP_BUF (*(s32*)SP(0x0))

void func_80026D44(void) {
    struct X4_BackgroundObj* bg;
    u32 i;

    i = 0;
    SP_PRIM_COUNT = 0;
    do {
        if (background_objects[i].unk4C != 0 ||
            background_objects[i].pad52[0] >= 0) {
            func_800269F4(i & 0xFF);
        }
        i++;
    } while (i < 3);
    bg = background_objects;
    func_800273E4();
    i = 0;
    SP_PRIM_PTR = (SP_BUF << 14) + g_bg_sprite_prims;
    do {
        if (bg->unk3 != 0) {
            func_80026E20(i);
            func_800270D0(i);
            func_80026ECC(i);
        }
        i++;
        bg++;
    } while (i < 3);
}

#include "common.h"

extern u32* D_8008EC18[2][102];
#define D_8008EC18 (*(u32 * (*)[2][6][17]) & D_8008EC18)
extern u32 D_80090E78[2][6][17];

void func_80026E20(s32 arg0) {
    u32** a;
    u32** b;
    u32* c;
    u32* d;
    u32* e;
    u32* f;
    u32* g;
    u32* h;
    s32 l;
    u32* base;
    u32 i;

    i = 0;
    l = arg0 + 3;
    base = (u32*)D_80090E78;
    h = &base[l * 17 + 102];
    b = D_8008EC18[0][l];
    d = base + l * 17;
    g = d;
    f = &base[arg0 * 17 + 102];
    a = D_8008EC18[0][arg0];
    c = base + arg0 * 17;
    e = c;
    do {
        a[0] = e;
        a[102] = f;
        b[102] = h;
        h++;
        b[0] = g;
        b++;
        g++;
        c[0] = 0;
        c[102] = 0;
        d[0] = 0;
        d[102] = 0;
        d++;
        f++;
        a++;
        e++;
        i++;
        c++;
    } while (i < 17);
}
#undef D_8008EC18

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u32* D_8008EC18[2][102];
#define EC18(b, l, i)                                                          \
    (*(u32**)((u8*)D_8008EC18 + (i) * 4 + (l) * 68 + (b) * 408))
extern u32 D_80090E78[2][6][17];
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800CC870[];
#define D_800CC870 (*(X4_P_TAG(*)[2][6][17]) & D_800CC870)
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))
#define GETADDR(p) ((u32)((X4_P_TAG*)(p))->addr)

void func_80026ECC(s32 arg0) {
    struct X4_DrawInfo* info;
    u32 v;
    s32 buf;
    s32 l;
    u32 i;

    l = arg0 + 3;
    buf = SP_DRAW_BUFFER;
    info = g_cur_draw_info;
    for (i = 0; i < 17; i++) {
        v = D_80090E78[buf][arg0][i];
        if (v != 0) {
            SETADDR(&D_800CC870[buf][arg0][i], v);
            SETADDR(EC18(buf, arg0, i),
                    GETADDR(&info->ordering_table.start +
                            (s8)background_objects[arg0].unk4A));
            SETADDR(&info->ordering_table.start +
                        (s8)background_objects[arg0].unk4A,
                    &D_800CC870[buf][arg0][i]);
        }
        v = D_80090E78[buf][l][i];
        if (v != 0) {
            SETADDR(&D_800CC870[buf][l][i], v);
            SETADDR(EC18(buf, l, i),
                    GETADDR(&info->ordering_table.start +
                            (s8)background_objects[arg0].unk4B));
            SETADDR(&info->ordering_table.start +
                        (s8)background_objects[arg0].unk4B,
                    &D_800CC870[buf][l][i]);
        }
    }
}
#undef GETADDR
#undef SETADDR
#undef D_800CC870
#undef EC18

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u32* D_8008EC18[2][102];
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800A21B8[3][32][64];

#define SP_PRIM_PTR (*(u8**)SP(0x108))
#define SP_PRIM_COUNT (*(s32*)SP(0x11C))

void func_800270D0(s32 arg0) {
    struct X4_BackgroundObj* bg;
    struct X4_BackgroundObj* parent;
    struct X4_BackgroundObj* base;
    u8* prim;
    s8 p;
    s32 x;
    s32 y;
    s32 buf;
    s32 col0;
    s32 col;
    s32 row;
    s16 px0;
    s16 px;
    s16 py;
    u32 n;
    u32 i;
    u32 j;
    u16 tile;
    u32 attr;
    u32 pri;
    s32 layer;
    u32 slot;

    base = background_objects;
    bg = &base[arg0];
    prim = SP_PRIM_PTR;
    p = bg->pad52[0];
    buf = SP_DRAW_BUFFER;
    if (p < 0) {
        x = bg->x_pos.i.hi;
        y = bg->y_pos.i.hi;
    } else {
        parent = &base[p];
        x = bg->x_pos.i.hi + parent->x_pos.i.hi;
        y = bg->y_pos.i.hi + parent->y_pos.i.hi;
    }
    col0 = (x / 16) & 0x3F;
    px0 = -(x & 0xF);
    row = (y / 16) & 0x1F;
    py = -(y & 0xF);
    n = 0x21;
    if (g_wide_mode == 0) {
        n = 0x15;
    }
    for (j = 0; j < 16; j++) {
        px = px0;
        col = col0;
        for (i = 0; i < n; i++) {
            tile = D_800A21B8[arg0][row][col];
            if (tile != 0) {
                if (SP_PRIM_COUNT >= 1000) {
                    return;
                }
                SP_PRIM_COUNT++;
                attr = SP_BG_TILE_ATTRS[tile & 0x3FFF];
                pri = (attr & 0xFF000000) >> 24;
                if (pri != 0xFF) {
                    *(u16*)(prim + 0xE) = (((attr & 0xF000) >> 6) +
                                           (0x7980 + (pri & 0x40) * 16)) |
                                          ((attr & 0xF00) >> 8);
                    if (tile & 0x4000) {
                        prim[7] |= 2;
                    } else {
                        prim[7] &= ~2;
                    }
                    layer = arg0;
                    *(s16*)(prim + 8) = px;
                    *(s16*)(prim + 0xA) = py;
                    prim[0xC] = (attr >> 12) & 0xF0;
                    prim[0xD] = (attr >> 16) & 0xF0;
                    if (tile & 0x8000) {
                        layer += 3;
                    }
                    slot = pri & 0x3F;
                    *D_8008EC18[buf][layer * 17 + slot] =
                        (*D_8008EC18[buf][layer * 17 + slot] & 0xFF000000) |
                        ((u32)prim & 0xFFFFFF);
                    D_8008EC18[buf][layer * 17 + slot] = (u32*)prim;
                    prim += 16;
                }
            }
            px += 16;
            col++;
            col &= 0x3F;
        }
        py += 16;
        row++;
        row &= 0x1F;
    }
    SP_PRIM_PTR = prim;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800274A0(s32 arg0, s32 arg1, s32 arg2);
void func_80027780(s32 arg0, s32 arg1, s32 arg2);

void func_800273E4(void) {
    struct X4_BackgroundObj* p;
    u32 i;
    s16 x;
    s16 y;
    s32 y0;
    s32 t;

    i = 0;
    p = background_objects;
    do {
        if (p->pad52[0] < 0) {
            x = p->x_pos.i.hi;
            y = p->y_pos.i.hi;
            y0 = y - 0x10;
            func_800274A0(i, x - 0x10, y0);
            t = x + 0x10;
            func_800274A0(i, t + g_screen_width, y0);
            func_80027780(i, x, y0);
            func_80027780(i, x, y + 0x100);
        }
        i++;
        p++;
    } while (i < 3);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800A21B8[3][32][64];
extern u8 g_tilemap_height;

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
        if (col >= g_tilemap_width || row >= g_tilemap_height) {
            t = 0;
        } else {
            t = *(SP_BG_TILEMAP + arg0 * g_tilemap_layer_stride +
                  g_tilemap_width * row + col);
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
                if (col >= g_tilemap_width || row >= g_tilemap_height) {
                    t = 0;
                    t2 = t;
                } else {
                    t = *(*tm + arg0 * g_tilemap_layer_stride +
                          g_tilemap_width * row + col);
                    t2 = t;
                }
                tile = t2;
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u16 D_800A21B8[3][32][64];
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
            t = *(SP_BG_TILEMAP + arg0 * g_tilemap_layer_stride +
                  g_tilemap_width * row + col);
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
                    t = *(*tm + arg0 * g_tilemap_layer_stride +
                          g_tilemap_width * row + col);
                    t2 = t;
                }
                tile = t2;
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u8* D_800762E0[][2];
extern struct X4_EngineObj g_playthrough_state;
extern u8* D_800EA514[];

void func_800268B0(s32 arg0);

#define SCRATCH_04 (*(u8**)0x1F800004)

void func_8002798C(void) {
    u8* src;
    u8* dst;
    u32 i;

    if (g_playthrough_state.stage == 0xB) {
        src = D_800EA514[g_playthrough_state.checkpoint];
    } else {
        src =
            D_800762E0[g_playthrough_state.stage][g_playthrough_state.substage];
    }
    i = 0;
    dst = SCRATCH_04;
    if (g_tilemap_layer_stride * 3 != 0) {
        do {
            *dst = *src;
            src++;
            i++;
            dst++;
        } while (i < (u32)(g_tilemap_layer_stride * 3));
    }
    func_800268B0(-1);
}

#include "common.h"
#include "psyq/libgpu.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

extern s16 D_80071E70[][4];
extern s8 D_8008EAB0;
#define D_8008EAB0 (*(u8*)&D_8008EAB0)

#define SCRATCH_44 (*(M2C_UNK**)0x1F800044)

void func_80027A50(void) {
    if (D_8008EAB0 == 1) {
        LoadImage((M2C_UNK*)D_80071E70[g_wide_mode], SCRATCH_44);
        D_8008EAB0 = 2;
    }
}
#undef D_8008EAB0

#include "common.h"

void func_80027E84(s32, s32, s32, s32, s32);

void func_80027AA8(s32 arg0, s16 arg1, s16 arg2, u16* arg3) {
    s32 var_v1;
    s32 var_s4;
    s32 var_s3;
    // !FAKE: depin: dropping it breaks the match (56/62)
    register s32 var_s2 asm("$18");
    s32 var_s1;
    s32 var_s0;
    s32 sp18;

    var_s4 = arg2;
    var_v1 = 0;
    var_s3 = ((s16*)arg3)[1];
    sp18 = arg1;
    if (arg3[3] != 0) {
        do {
            var_s0 = ((s16*)arg3)[0];
            var_s2 = sp18;
            var_s1 = 0;
            if (arg3[2] != 0) {
                do {
                    func_80027E84(arg0, var_s2, var_s4, var_s0, var_s3);
                    var_s1 += 1;
                    var_s2 += 0x10;
                    var_s0 += 0x10;
                } while (var_s1 < arg3[2]);
            }
            var_v1 += 1;
            var_s4 += 0x10;
            var_s3 += 0x10;
        } while (var_v1 < arg3[3]);
    }
}

// clang-format off
#include "../shared/SLUS_013.95/func_80027BA0.c"
// clang-format on

#include "common.h"

void func_80027FA4(s32, s32, s32);

void func_80027C98(s32 arg0, s16 arg1, s16 arg2, u16* arg3) {
    s32 i;
    s32 j;
    s32 x;
    s32 y;

    y = arg2;
    i = 0;
    while (i < arg3[3]) {
        x = arg1;
        j = 0;
        while (j < arg3[2]) {
            func_80027FA4(arg0, x, y);
            j++;
            x += 0x10;
        }
        i++;
        y += 0x10;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u16 D_800A21B8[3][32][64];
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
        t = *(SP_BG_TILEMAP + arg0 * g_tilemap_layer_stride +
              g_tilemap_width * row + col);
    }
    tile = t;
    D_800A21B8[arg0][ry][rx] = *(SP_BG_TILE_PIXELS + tile * 256 + py * 16 + px);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u16 D_800A21B8[3][32][64];
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
        tile = *(SP_BG_TILEMAP + arg0 * g_tilemap_layer_stride +
                 g_tilemap_width * row + col);
    }
    D_800A21B8[arg0][ry][rx] = *(SP_BG_TILE_PIXELS + tile * 256 + py * 16 + px);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u8 g_tilemap_height;

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
    if (col >= g_tilemap_width || row >= g_tilemap_height) {
        tile = 0;
    } else {
        tile = *(SP_BG_TILEMAP + arg0 * g_tilemap_layer_stride +
                 g_tilemap_width * row + col);
    }
    *(SP_BG_TILE_PIXELS + tile * 256 + py * 16 + px) = 0;
}

#include "common.h"
#include "mmx6/globals.h"

extern u8 g_tilemap_height;

#define SCRATCH_04 (*(u8**)0x1F800004)

s32 func_80028078(s32 arg0, s32 arg1, u32 arg2) {
    u32 x = arg1;

    if ((x >= g_tilemap_width) || (arg2 >= g_tilemap_height)) {
        return 0;
    }
    return *(SCRATCH_04 + (arg0 * g_tilemap_layer_stride) +
             (g_tilemap_width * arg2) + x);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern u8 D_80071EE0[];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 g_tilemap_height;
#define D_800CD3F0 (*(u8(*)[4]) & D_800CD3F0)

void func_800280F4(void) {
    struct X4_BackgroundObj* bg;
    u32 i;
    u8* p;

    bg = background_objects;
    i = 0;
    do {
        bg->unk0 = 1;
        bg->unk3 = 1;
        bg->unk44 = 1;
        bg->pad52[0] = -1;
        bg->unk4D = 0;
        bg->min_y = 0;
        bg->unk4E = g_tilemap_width - 1;
        bg->max_y = g_tilemap_height - 1;
        bg++;
        i++;
    } while (i < 3);
    p = &D_80071EE0[g_playthrough_state.stage * 20 +
                    g_playthrough_state.substage * 10];
    D_800CD3F0[0] = *p++;
    D_800CD3F0[1] = *p++;
    D_800CD3F0[2] = *p++;
    D_800CD3F0[3] = *p++;
    background_objects[0].unk4B = *p++;
    background_objects[0].unk4A = *p++;
    background_objects[1].unk4B = *p++;
    background_objects[1].unk4A = *p++;
    background_objects[2].unk4B = *p++;
    background_objects[2].unk4A = *p++;
}
#undef D_800CD3F0

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;

void func_8002820C(struct X4_BackgroundObj* arg0) {
    s16 lim;

    if (arg0->unk1C < arg0->x_pos.i.hi) {
        arg0->x_pos.i.hi = arg0->unk1C;
        lim = (s16)(arg0->x_pos.i.hi + 0x140);
        if (g_Player.x_pos.i.hi + 8 >= lim) {
            g_Player.x_pos.i.hi = arg0->x_pos.i.hi + 0x138;
        }
    }
    if (arg0->unk1E >= arg0->x_pos.i.hi) {
        arg0->x_pos.i.hi = arg0->unk1E;
        if (g_Player.x_pos.i.hi - 8 < arg0->x_pos.i.hi) {
            g_Player.x_pos.i.hi = arg0->x_pos.i.hi + 8;
        }
    }
    if (g_Player.y_pos.i.hi < 0 && D_800CCEDF == 0) {
        g_Player.y_pos.i.hi = 0;
    }
    if (arg0->unk20 < arg0->y_pos.i.hi) {
        arg0->y_pos.i.hi = arg0->unk20;
        lim = (s16)(arg0->y_pos.i.hi + 0x100);
        if (lim <= g_Player.y_pos.i.hi - 8) {
            u8 hp = g_Player.hp;
            u8* e = (u8*)&g_playthrough_state;
            g_Player.hp = -0x80;
            *(s32*)(e + 0x98) += hp & 0x7F;
        }
    } else if (arg0->unk22 >= arg0->y_pos.i.hi) {
        arg0->y_pos.i.hi = arg0->unk22;
    }
}
#undef g_Player

#include "../shared/mugshot/func_80028338.c"

#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];

void func_8002844C(struct X4_BackgroundObj* arg0) {
    s16 pos;
    s16 diff;
    s16 tmp;
    u16 cur;
    u16 ref;

    tmp = background_objects[0].x_pos.i.hi >> 1;
    pos = tmp + (s16)arg0->unk40;
    diff = pos - arg0->unk14.i.hi;
    arg0->x_pos.i.hi = pos;
    arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + arg0->unk42;
    if (diff >= 0) {
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->x_pos.i.hi = pos - 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi + 0x10;
            }
        }
    } else {
        diff = -diff;
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->x_pos.i.hi = pos + 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi - 0x10;
            }
        }
    }
    cur = arg0->y_pos.i.hi;
    ref = arg0->unk18.i.hi;
    diff = cur - ref;
    if (diff >= 0) {
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->y_pos.i.hi = cur - 0x140;
            } else {
                arg0->y_pos.i.hi = ref + 0x10;
            }
        }
    } else {
        diff = -diff;
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->y_pos.i.hi = cur + 0x140;
            } else {
                arg0->y_pos.i.hi = ref - 0x10;
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_8002855C(struct X4_BackgroundObj* arg0) {
    s16 q;
    s16 q2;
    s16 x;
    s16 d;
    u16 t;
    u16 y;
    u16 t2;

    q2 = (background_objects[0].x_pos.i.hi * 3) / 4;
    x = q2 + (s16)arg0->unk40;
    arg0->x_pos.i.hi = x;
    q = (background_objects[0].y_pos.i.hi * 3) / 4;
    arg0->y_pos.i.hi = q + (s16)arg0->unk42;
    t = arg0->unk14.u.hi;
    d = x - t;
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->x_pos.i.hi = x - 0x140;
            } else {
                arg0->x_pos.i.hi = t + 0x10;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->x_pos.i.hi = x + 0x140;
            } else {
                arg0->x_pos.i.hi = t - 0x10;
            }
        }
    }
    y = arg0->y_pos.u.hi;
    t2 = arg0->unk18.u.hi;
    d = y - t2;
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->y_pos.u.hi = y - 0x140;
                return;
            }
            arg0->y_pos.u.hi = t2 + 0x10;
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->y_pos.u.hi = y + 0x140;
                return;
            }
            arg0->y_pos.u.hi = t2 - 0x10;
        }
    }
}

#include "../shared/mugshot/func_800286A0.c"

#include "../shared/mugshot/func_800287D0.c"

#define func_80028338 func_80028900
#define background_objects background_objects
#include "../shared/mugshot/func_80028338.c"
#undef func_80028338
#undef background_objects

#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];

void func_80028A14(struct X4_BackgroundObj* arg0) {
    s16 pos;
    s16 diff;
    s16 tmp;
    u16 cur;
    u16 ref;

    tmp = background_objects[0].x_pos.i.hi >> 1;
    tmp += tmp >> 1;
    pos = tmp + (s16)arg0->unk40;
    diff = pos - arg0->unk14.i.hi;
    arg0->x_pos.i.hi = pos;
    tmp = background_objects[0].y_pos.i.hi >> 1;
    tmp += tmp >> 1;
    arg0->y_pos.i.hi = tmp + (s16)arg0->unk42;
    if (diff >= 0) {
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->x_pos.i.hi = pos - 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi + 0x10;
            }
        }
    } else {
        diff = -diff;
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->x_pos.i.hi = pos + 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi - 0x10;
            }
        }
    }
    cur = arg0->y_pos.i.hi;
    ref = arg0->unk18.i.hi;
    diff = cur - ref;
    if (diff >= 0) {
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->y_pos.i.hi = cur - 0x140;
            } else {
                arg0->y_pos.i.hi = ref + 0x10;
            }
        }
    } else {
        diff = -diff;
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->y_pos.i.hi = cur + 0x140;
            } else {
                arg0->y_pos.i.hi = ref - 0x10;
            }
        }
    }
}

#define func_800286A0 func_80028B4C
#define background_objects background_objects
#include "../shared/mugshot/func_800286A0.c"
#undef func_800286A0
#undef background_objects

#define func_800287D0 func_80028C7C
#define background_objects background_objects
#include "../shared/mugshot/func_800287D0.c"
#undef func_800287D0
#undef background_objects

#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];

void func_80028DAC(struct X4_BackgroundObj* arg0) {
    s16 pos;
    s16 diff;
    s16 tmp;
    u16 cur;
    u16 ref;

    tmp = background_objects[0].x_pos.i.hi >> 2;
    pos = tmp + (s16)arg0->unk40;
    diff = pos - arg0->unk14.i.hi;
    arg0->x_pos.i.hi = pos;
    arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + (s16)arg0->unk42;
    if (diff >= 0) {
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->x_pos.i.hi = pos - 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi + 0x10;
            }
        }
    } else {
        diff = -diff;
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->x_pos.i.hi = pos + 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi - 0x10;
            }
        }
    }
    cur = arg0->y_pos.i.hi;
    ref = arg0->unk18.i.hi;
    diff = cur - ref;
    if (diff >= 0) {
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->y_pos.i.hi = cur - 0x140;
            } else {
                arg0->y_pos.i.hi = ref + 0x10;
            }
        }
    } else {
        diff = -diff;
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->y_pos.i.hi = cur + 0x140;
            } else {
                arg0->y_pos.i.hi = ref - 0x10;
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_80028EBC(struct X4_BackgroundObj* arg0) {
    s32 spd1;
    s32 pos1;
    s32 spd2;
    s32 pos2;
    s32 spd3;
    s32 pos3;
    s32 pos4;
    s32 d;
    s16 t;
    s16 x;

    if (arg0->unk26 != arg0->unk1E) {
        d = arg0->unk26 - arg0->unk1E;
        if (d < 0) {
            d = arg0->unk1E - arg0->unk26;
        }
        spd1 = arg0->unk47;
        if (spd1 < d) {
            x = arg0->x_pos.i.hi;
            pos1 = (u16)arg0->x_pos.i.hi;
            if (arg0->unk26 >= x) {
                t = x + spd1;
                if (t >= arg0->unk26) {
                    arg0->unk1E = arg0->unk26;
                } else {
                    arg0->unk1E = t;
                }
            } else {
                t = g_Player.x_pos.i.hi;
                t = t - pos1;
                if ((s16)(t - arg0->unk30) >= 0) {
                    t = g_Player.x_pos.i.hi - g_Player.unk18.i.hi;
                    if (t >= 0) {
                        t = 0;
                    }
                    t = t + pos1;
                    t = t - spd1;
                    if (t < arg0->unk26) {
                        arg0->unk1E = t;
                    } else {
                        arg0->unk1E = arg0->unk26;
                    }
                } else {
                    arg0->unk1E = arg0->unk26;
                }
            }
        } else {
            arg0->unk1E = arg0->unk26;
        }
    }
    if (arg0->unk24 != arg0->unk1C) {
        d = arg0->unk24 - arg0->unk1C;
        if (d < 0) {
            d = arg0->unk1C - arg0->unk24;
        }
        spd2 = arg0->unk47;
        if (spd2 < d) {
            x = arg0->x_pos.i.hi;
            pos2 = (u16)arg0->x_pos.i.hi;
            if (arg0->unk24 < x) {
                t = x - spd2;
                if (t < arg0->unk24) {
                    arg0->unk1C = arg0->unk24;
                    // !FAKE: goto keeps the shared unk1C store tails; full if/else nesting flipped a branch
                    goto block3;
                }
                // !FAKE: goto keeps the shared unk1C store tails; full if/else nesting flipped a branch
                goto store2;
            }
            t = g_Player.x_pos.i.hi;
            t = t - pos2;
            t = t - arg0->unk32;
            t = t + 2;
            if (t < 4) {
                t = g_Player.x_pos.i.hi - g_Player.unk18.i.hi;
                if (t < 0) {
                    t = 0;
                }
                t = t + pos2;
                t = t + spd2;
                if (arg0->unk24 < t) {
                store2:
                    arg0->unk1C = t;
                    // !FAKE: goto keeps the shared unk1C store tails; full if/else nesting flipped a branch
                    goto block3;
                }
                arg0->unk1C = arg0->unk24;
                // !FAKE: goto keeps the shared unk1C store tails; full if/else nesting flipped a branch
                goto block3;
            }
        }

        arg0->unk1C = arg0->unk24;
    }
block3:
    if (arg0->unk2A != arg0->unk22) {
        d = arg0->unk2A - arg0->unk22;
        if (d < 0) {
            d = arg0->unk22 - arg0->unk2A;
        }
        spd3 = arg0->unk47;
        if (spd3 >= d) {
            arg0->unk22 = arg0->unk2A;
        } else {
            x = arg0->y_pos.i.hi;
            pos3 = (u16)arg0->y_pos.i.hi;
            if (arg0->unk2A >= x) {
                t = x + spd3;
                if (t < arg0->unk2A) {
                    arg0->unk22 = t;
                } else {
                    arg0->unk22 = arg0->unk2A;
                }
            } else {
                t = g_Player.y_pos.i.hi;
                t = t - pos3;
                t = t - arg0->unk2C;
                if (t < 0) {
                    t = g_Player.y_pos.i.hi - g_Player.unk1C.i.hi;
                    if (t >= 0) {
                        t = 0;
                    }
                    t = t + pos3;
                    t = t - spd3;
                    if (t < arg0->unk2A) {
                        t = arg0->unk2A;
                    }
                }
                arg0->unk22 = t;
            }
        }
    }
    if (arg0->unk28 != arg0->unk20) {
        x = arg0->y_pos.i.hi;
        pos4 = (u16)arg0->y_pos.i.hi;
        if (arg0->unk28 < x) {
            t = x - arg0->unk47;
            if (t < arg0->unk28) {
                t = arg0->unk28;
            }
            arg0->unk20 = t;
            return;
        }
        t = g_Player.y_pos.i.hi;
        t = t - pos4;
        t = t - arg0->unk2E;
        t = t + 2;
        if (t < 4) {
            t = g_Player.y_pos.i.hi - g_Player.unk1C.i.hi;
            if (t < 0) {
                t = 0;
            }
            t = t + pos4;
            t = t + arg0->unk47;
            if (t >= arg0->unk28) {
                t = arg0->unk28;
            }
            arg0->unk20 = t;
            return;
        }
        arg0->unk20 = arg0->unk28;
    }
}
#undef g_Player

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_80071E80[])(struct X4_BackgroundObj*);
void func_80028EBC(struct X4_BackgroundObj* arg0);
void func_80029A6C(struct X4_BackgroundObj* arg0);
void func_80029AFC(struct X4_BackgroundObj* arg0);

void func_8002927C(void) {
    struct X4_BackgroundObj* bg = &background_objects[0];
    struct X4_PlayerObj* p;

    if (bg->unk44 != 0) {
        p = &g_Player;
        if (*(s8*)((u8*)p + 0xCC) == 0 &&
            (p->character == 0 || p->nova_strike_active == 0)) {
            D_80071E80[bg->unk4](bg);
            if (p->ride_animation != -2) {
                if (bg->unk34 & 0x10) {
                    func_80029A6C(bg);
                }
                if (bg->unk34 & 1) {
                    func_80029AFC(bg);
                }
            }
            func_80028EBC(bg);
        }
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/background.c:func_80027D40, AGPL-3.0; proven shared with X6 by exact signature 6ee72b467391 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_PlayerObj D_800970B0;
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_80071E88[])(struct X4_BackgroundObj*);

void func_8002935C(void) {
    struct X4_BackgroundObj* ptr = &background_objects[1];
    if (ptr->unk44 != 0 && D_800970B0.update_delay == 0) {
        ptr->unk14.val = ptr->x_pos.val;
        ptr->unk18.val = ptr->y_pos.val;
        D_80071E88[ptr->unk4](ptr);
    }
}

// clang-format off
#include "../shared/SLUS_013.95/func_800293CC.c"
// clang-format on

/* Adapted from sozud/mmx4 @4e16dfc src/main/stage_objects.c:start_screen_shake_x, AGPL-3.0; proven shared with X6 by exact signature 43e71a929bf8 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];

void func_8002943C(s8 arg0, s8 arg1, s8 arg2) {
    background_objects[0].unk36 = arg0;
    background_objects[0].unk45 = arg1;
    background_objects[0].unk3E.bytes[0] = arg1;
    background_objects[0].unk3C = arg2;
    background_objects[0].unk3A = arg2;
    background_objects[0].unk34 |= 0x10;
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/stage_objects.c:start_screen_shake_y, AGPL-3.0; proven shared with X6 by exact signature 503943cdb46f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];

// 0x80029478 func_80029478: sets the vertical shake fields and flag 1 of background object 0 (mmx4 start_screen_shake_y shape).
// basis: none
// callers: func_8004755C, move_ceiling, overlay callers in rock_01, rock_02, rock_05, rock_07, rock_09, rock_15 and others
void func_80029478(s8 arg0, s8 arg1, s8 arg2) {
    background_objects[0].unk37 = arg0;
    background_objects[0].unk46 = arg1;
    background_objects[0].unk3E.bytes[1] = arg1;
    background_objects[0].unk3D = arg2;
    background_objects[0].unk3B = arg2;
    background_objects[0].unk34 |= 1;
}

#include "common.h"
#include "mmx6/globals.h"

void func_800294B4(u8* arg0) {
    s16 v;

    *(u8*)(arg0 + 0x47) = 4;
    *(u8*)(arg0 + 0x48) = 8;
    *(s16*)(arg0 + 0x2C) = 0x60;
    *(s32*)(arg0 + 0x14) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0xC);
    *(s16*)(arg0 + 0x24) = *(s16*)(arg0 + 0x1C);
    *(s16*)(arg0 + 0x26) = *(s16*)(arg0 + 0x1E);
    *(s16*)(arg0 + 0x28) = *(s16*)(arg0 + 0x20);
    *(s16*)(arg0 + 0x2A) = *(s16*)(arg0 + 0x22);
    v = 0xAA;
    if (D_800970A2 == 0) {
        v = 0xAB;
    }
    *(s16*)(arg0 + 0x2E) = v;
    *(s16*)(arg0 + 0x30) = 0xA0;
    *(s16*)(arg0 + 0x32) = 0xA0;
    arg0[4]++;
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/background.c:func_80027974, AGPL-3.0; proven shared with X6 by exact signature a09eb2b42e5f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_80029598(struct X4_BackgroundObj*);
void func_800295E8(struct X4_BackgroundObj*);
void func_800296A8(struct X4_Unk9*);
void func_8002820C(struct X4_BackgroundObj*);

void func_80029538(struct X4_BackgroundObj* arg0) {
    s32 temp_a1;
    arg0->unk14.val = arg0->x_pos.val;
    temp_a1 = arg0->y_pos.val;
    arg0->unk18.val = temp_a1;
    arg0->unk49 = -arg0->unk48;
    func_80029658(arg0);
    func_80029598(arg0);
    func_800295E8(arg0);
    func_800296A8(arg0);
    func_8002820C(arg0);
}

#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800970AA;

void func_80029598(struct X4_BackgroundObj* arg0) {
    s16 delta;

    delta = (D_800970AA - arg0->x_pos.i.hi) - arg0->unk30;
    if (delta < 0) {
        arg0->x_pos.i.hi = delta + arg0->x_pos.i.hi;
        return;
    }
    delta = (D_800970AA - arg0->x_pos.i.hi) - arg0->unk32;
    if (delta > 0) {
        arg0->x_pos.i.hi = delta + arg0->x_pos.i.hi;
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/background.c:func_80027AFC, AGPL-3.0; proven shared with X6 by exact signature 3108906f66dd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_800295E8(struct X4_BackgroundObj* arg0) {
    s16 delta;

    delta = arg0->x_pos.i.hi - arg0->unk14.i.hi;
    if (delta >= 0) {
        if (delta >= arg0->unk48) {
            delta = arg0->unk48;
        }
        arg0->x_pos.i.hi = delta + arg0->unk14.i.hi;
    } else {
        if (delta < arg0->unk49) {
            delta = arg0->unk49;
        }
        arg0->x_pos.i.hi = delta + arg0->unk14.i.hi;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_80029658(struct X4_BackgroundObj* arg0) {
    s16 delta;

    delta = (D_800970AE - arg0->y_pos.i.hi) - arg0->unk2C;
    if (delta < 0) {
        arg0->y_pos.i.hi = delta + arg0->y_pos.i.hi;
        return;
    }
    delta = (D_800970AE - arg0->y_pos.i.hi) - arg0->unk2E;
    if (delta > 0) {
        arg0->y_pos.i.hi = delta + arg0->y_pos.i.hi;
    }
}

#include "common.h"
#include "mmx6/x4.h"

void func_800296A8(struct X4_Unk9* arg0) {
    struct X4_BackgroundObj* obj = (struct X4_BackgroundObj*)arg0;
    s16 delta;

    delta = obj->y_pos.i.hi - obj->unk18.i.hi;
    if (delta >= 0) {
        if (delta >= obj->unk48) {
            delta = obj->unk48;
        }
        obj->y_pos.i.hi = delta + obj->unk18.i.hi;
    } else {
        if (delta < obj->unk49) {
            delta = obj->unk49;
        }
        obj->y_pos.i.hi = delta + obj->unk18.i.hi;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800720AC[];
extern struct X4_EngineObj g_playthrough_state;

void func_80029718(struct X4_BackgroundObj* arg0) {
    arg0->unk4 = D_800720AC[g_playthrough_state.stage * 4 +
                            g_playthrough_state.substage * 2];
}

#include "common.h"

#define M2C_UNK s32

void func_800297D8(u8* arg0);                      /* extern */
M2C_UNK func_800297F8();                           /* extern */
void func_80029818(struct X4_BackgroundObj* arg0); /* extern */

void func_8002974C(s32 arg0) {
    func_800297F8();
    func_800297D8(arg0);
    func_80029818(arg0);
}

#include "../shared/mugshot/func_80029780.c"

void func_800297B4(void) {
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_80097202;

void func_800297BC(void* arg0) {
    M2C_FIELD(arg0, s16*, 0xA) =
        (s16)(D_80097202 + M2C_FIELD(arg0, u16*, 0x40));
}

#include "../shared/mugshot/func_800297D8.c"

#include "../shared/mugshot/func_800297F8.c"

/* Adapted from sozud/mmx4 @4e16dfc src/main/background.c:func_80027FA8, AGPL-3.0; proven shared with X6 by exact signature 8a39aba72637 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_80029818(struct X4_BackgroundObj* arg0) {
    s16 delta;

    delta = arg0->x_pos.i.hi - arg0->unk14.i.hi;
    if (delta >= 0) {
        if (delta >= 0x10) {
            if (delta >= 0x148) {
                arg0->x_pos.i.hi = arg0->x_pos.i.hi - 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi + 0x10;
            }
        }
    } else {
        delta = -delta;
        if (delta >= 0x10) {
            if (delta >= 0x148) {
                arg0->x_pos.i.hi = arg0->x_pos.i.hi + 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi - 0x10;
            }
        }
    }

    delta = arg0->y_pos.i.hi - arg0->unk18.i.hi;
    if (delta >= 0) {
        if (delta >= 0x10) {
            if (delta >= 0x148) {
                arg0->y_pos.i.hi = arg0->y_pos.i.hi - 0x140;
            } else {
                arg0->y_pos.i.hi = arg0->unk18.i.hi + 0x10;
            }
        }
    } else {
        delta = -delta;
        if (delta >= 0x10) {
            if (delta >= 0x148) {
                arg0->y_pos.i.hi = arg0->y_pos.i.hi + 0x140;
            } else {
                arg0->y_pos.i.hi = arg0->unk18.i.hi - 0x10;
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800720AC[];
extern struct X4_EngineObj g_playthrough_state;

void func_800298F4(struct X4_BackgroundObj* arg0) {
    arg0->unk4 = D_800720AC[g_playthrough_state.stage * 4 +
                            g_playthrough_state.substage * 2 + 1];
}

#include "common.h"

#define M2C_UNK s32

void func_80029A2C();    /* extern */
M2C_UNK func_80029A4C(); /* extern */

void func_8002992C(s32 arg0) {
    func_80029A4C();
    func_80029A2C(arg0);
}

#define func_80029780 func_80029958
#define background_objects background_objects
#include "../shared/mugshot/func_80029780.c"
#undef func_80029780
#undef background_objects

#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];
void func_8002998C(struct X4_BackgroundObj* arg0) {
    struct X4_BackgroundObj* bg = background_objects;
    // !FAKE: regalloc
    register s32 x asm("$2") = bg->x_pos.i.hi >> 1;

    arg0->x_pos.i.hi = x + arg0->unk40;
    {
        // !FAKE: regalloc
        register s32 y asm("$3") = bg->y_pos.u.hi;

        arg0->y_pos.i.hi = y + arg0->unk42;
    }
}

void func_800299C4(void) {
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_80097202;

void func_800299CC(void* arg0) {
    M2C_FIELD(arg0, s16*, 0xA) =
        (s16)(D_80097202 + M2C_FIELD(arg0, u16*, 0x40));
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800299E8(struct X4_BackgroundObj* arg0) {
    s32 t;
    u16 y;

    arg0->x_pos.u.hi = background_objects[0].x_pos.u.hi;
    y = background_objects[0].y_pos.u.hi;
    t = (s16)y / 2 + y;
    arg0->y_pos.u.hi = arg0->unk42 + t;
}

#define func_800297D8 func_80029A2C
#include "../shared/mugshot/func_800297D8.c"
#undef func_800297D8

#define func_800297F8 func_80029A4C
#include "../shared/mugshot/func_800297F8.c"
#undef func_800297F8

/* Adapted from sozud/mmx4 @4e16dfc src/main/background.c:update_screen_shake_x, AGPL-3.0; proven shared with X6 by exact signature 53e7a3858f9c (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_80029A6C(struct X4_BackgroundObj* arg0) {
    if (--arg0->unk36 == 0) {
        arg0->unk34 &= ~0x10;
        return;
    }
    if (--arg0->unk3C == 0) {
        arg0->unk3E.bytes[0] ^= 0x80;
        arg0->unk3C = arg0->unk3A;
    }
    if (arg0->unk3E.bytes[0] >= 0) {
        arg0->x_pos.i.hi += arg0->unk45;
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/background.c:update_screen_shake_y, AGPL-3.0; proven shared with X6 by exact signature a0d9f0b7dd5c (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_80029AFC(struct X4_BackgroundObj* arg0) {
    if (--arg0->unk37 == 0) {
        arg0->unk34 &= 0xFFFE;
        return;
    }
    if (--arg0->unk3D == 0) {
        arg0->unk3E.bytes[1] ^= 0x80;
        arg0->unk3D = arg0->unk3B;
    }
    if (arg0->unk3E.bytes[1] >= 0) {
        arg0->y_pos.i.hi += arg0->unk46;
    }
}
