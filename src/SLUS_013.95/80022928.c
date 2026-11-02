#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
#define SCR_A8 (*(s32*)0x1F8000A8)

M2C_UNK func_80022928(s32 arg0, s32 arg1) {
    load_palette((arg0 << 4) + 0x1E0, (M2C_UNK*)(SCR_A8 + (arg1 << 9)), 0x10);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PTR(off) (*(u8**)(0x1F800000 + (off)))
#define ONS(p) (((s8*)(p))[3])

extern s8 g_enemies[];
extern u8 D_800911A8[];
extern u8 D_80091298[];
#include "mmx6/projectile.h"
extern s8 D_800950A0[];
extern u8 D_800964A0[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern u8 D_800973B8[];
#include "mmx6/state.h"
extern u8 D_8009C9B0[];
extern u8 D_800A51B8[];
extern s32 D_800C1220[];
extern u8 D_800C4858[];
extern struct X4_RideArmorObj D_800CD340;
extern struct X4_MiscObj g_displayed_sprites[];
extern u8 D_800E3420[];
extern u8 D_800E3C20[];
extern u8 D_800E4020[];

void func_80022E44(void);
void func_800232D4(void*);
void func_800239CC(void*);
void func_80023ED8(u8* arg0);
void func_800241D4(void*);
void func_800244C0(void);
void func_80026128(void);
void func_8002619C(u8* arg0);
s32 func_8002FE30(void*);

void func_80022960(void) {
    struct X4_PlayerObj* pl;
    u8* p;
    u8* end;
    s32 buf;
    s16 savedX;
    u8 e7;

    buf = SCR_BUF;
    SCR_PTR(0x124) = 0;
    SCR_PTR(0x100) = D_800A51B8 + buf * 0xA000;
    SCR_PTR(0x104) = D_800C4858 + buf * 0x2000;
    SCR_PTR(0x108) = D_800E3420 + buf * 0x400;
    SCR_PTR(0x10C) = D_800E3C20 + buf * 0x200;
    SCR_PTR(0x110) = D_800E4020 + buf * 0xB4;
    if (D_80097420.character_mode == 0) {
        func_800244C0();
    }
    func_80026128();
    pl = &g_Player;
    if (pl->on_screen != 0) {
        savedX = pl->x_pos.i.hi;
        if (pl->unk5 == 0x1B ||
            (pl->unk5 == 0x3D && func_8002FE30(pl) == 0x2E)) {
            if (pl->unk2 == 0) {
                if (pl->unk15 == 0x40) {
                    pl->x_pos.i.hi++;
                }
            } else if (pl->unk15 == 0x40) {
                pl->x_pos.i.hi--;
            }
        }
        func_800232D4(pl);
        if (pl->unk2 == 0) {
            e7 = ((u8*)pl)[0xE7];
            if (e7 == 3 || e7 == 1 || e7 == 2 || e7 == 4) {
                func_8002619C(pl);
            }
        }
        pl->x_pos.i.hi = savedX;
    }
    if (pl->unk2 == 0) {
        p = D_800911A8;
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
        p += 0x50;
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
        p += 0x50;
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = D_800973B8; p >= D_800973B8 - 0xC0; p -= 0x60) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = (u8*)g_enemies; p < (u8*)g_enemies + 0x1D40; p += 0x9C) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = (u8*)D_800950A0; p < (u8*)D_800950A0 + 0x1400; p += 0xA0) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = (u8*)g_projectiles; p < (u8*)g_projectiles + 0x1400; p += 0xA0) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = D_80091298; p < D_80091298 + 0x2A00; p += 0x70) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = (u8*)D_800C1220; p < (u8*)D_800C1220 + 0x3340; p += 0xA4) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = (u8*)g_displayed_sprites; p < (u8*)g_displayed_sprites + 0x2400;
         p += 0x60) {
        if (ONS(p) == 1) {
            func_800232D4(p);
        }
        if (ONS(p) == 2) {
            func_800239CC(p);
        }
    }
    for (p = D_800964A0; p < D_800964A0 + 0xC00; p += 0x60) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    if (D_800CD340.on_screen != 0) {
        func_800232D4(&D_800CD340);
    }
    for (p = D_8009C9B0; p < D_8009C9B0 + 0x1800; p += 0x60) {
        if (ONS(p) != 0) {
            if (*p & 2) {
                func_800241D4(p);
            } else {
                func_80023ED8(p);
            }
        }
    }
    func_80022E44();
}
#undef g_Player

/* Adapted from sozud/mmx4 @807a01b src/main/14A60.c:func_80024260, AGPL-3.0; proven shared with X6 by exact signature ce7e7513ad74 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern X4_P_TAG* D_8008EB08[2][4][8];
extern X4_P_TAG* D_80090D70[2][4][8];
extern struct X4_DrawInfo* g_cur_draw_info;
#define M2C_UNK s32
/* libgpu ordering-table link helpers: read or write a primitive's next-pointer */
#ifndef setaddr
#define setaddr(p, a) (((X4_P_TAG*)(p))->addr = (X4_u_long)(a))
#define getaddr(p) (X4_u_long)(((X4_P_TAG*)(p))->addr)
#endif
extern M2C_UNK D_800CD3F0;
#define D_800CD3F0 (*(s8(*)[4]) & D_800CD3F0)

void func_80022E44(void) {
    u32 buffer;
    u32 i;
    u32 j;
    X4_OT_TYPE* otag;

    buffer = SP_DRAW_BUFFER;

    for (i = 0; i < 4; i++) {
        otag = &g_cur_draw_info->ordering_table.start + D_800CD3F0[i];

        for (j = 0; j < 8; j++) {
            if (D_80090D70[buffer][i][j] != NULL) {
                setaddr(D_8008EB08[buffer][i][j], getaddr(otag));
                setaddr(otag, D_80090D70[buffer][i][j]);
            }
        }
    }
}
#undef D_800CD3F0

#include "common.h"
#include "mmx6/x4.h"

extern X4_P_TAG* D_8008EB08[2][4][8];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_DrawInfo* g_cur_draw_info;

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PRIM (*(u8**)0x1F800100)
#define SCR_TPAGE (*(u32**)0x1F800104)
#define SCR_COUNT (*(s32*)0x1F800124)
#define OT_AC ((X4_P_TAG*)((u8*)g_cur_draw_info + 0xAC))
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))
#define GETADDR(p) (((X4_P_TAG*)(p))->addr)

void func_80022F1C(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (232/238)
    register s32 code asm("$18");
    s16 dx;
    s16 dy;
    u8* prim;
    u32* tp;
    u8* p;
    s32 n;
    s32 tbase;
    u16 cbase;
    s32 cnt;
    u8 b0;
    s16 x;
    s16 y;
    s16 x2;
    s16 y2;
    u8 y0;
    u16 clut;
    u32 tile;
    u8 vv;
    s32 tag;
    u32 hi;
    s32 lo;
    u8* tbl;
    u8* e;

    if (SCR_COUNT < 1000) {
        if (*(s8*)(arg0 + 0x14) < 0) {
            dx = *(s16*)(arg0 + 0xA);
            dy = *(s16*)(arg0 + 0xE);
        } else {
            dx = *(u16*)(arg0 + 0xA) -
                 background_objects[*(s8*)(arg0 + 0x14)].x_pos.u.hi;
            dy = *(u16*)(arg0 + 0xE) -
                 background_objects[*(s8*)(arg0 + 0x14)].y_pos.u.hi;
        }
        prim = SCR_PRIM;
        tp = SCR_TPAGE;
        tbl = *(u8**)(arg0 + 0x3C);
        tbase = *(u16*)(arg0 + 0x40);
        cbase = *(u16*)(arg0 + 0x42);
        e = tbl + arg0[0x47] * 4;
        n = *(u16*)e;
        p = tbl + *(u16*)(e + 2) * 4;
        if (n != 0) {
            code = 0x7D;
            do {
                cnt = SCR_COUNT;
                if (cnt >= 1000) {
                    hi = arg0[0x16] >> 4;
                    lo = arg0[0x16] & 7;
                    SETADDR(D_8008EB08[SCR_BUF][hi][lo], SCR_TPAGE);
                    D_8008EB08[SCR_BUF][hi][lo] = (X4_P_TAG*)(prim - 0x28);
                    SCR_PRIM = prim;
                    SCR_TPAGE = tp;
                    return;
                }
                b0 = p[0];
                x = ((s8*)p)[2];
                y0 = p[3];
                clut = cbase + ((b0 & 0xC) >> 2);
                x2 = x + 16;
                x += dx;
                x2 += dx;
                y = dy + (s8)y0;
                y2 = y + 16;
                if (x < 0x141 && x2 >= 0 && y < 0xF1 && y2 >= 0) {
                    SCR_COUNT = cnt + 1;
                    tile = p[1] | ((b0 & 3) << 8);
                    tile = (u16)(tile + tbase);
                    prim[3] = 3;
                    prim[7] = code;
                    vv = tile & 0xF0;
                    if (arg0[0] & 0x10) {
                        prim[7] = 0x7F;
                    }
                    prim[0xC] = tile << 4;
                    *(u16*)(prim + 0xE) = clut;
                    *(s16*)(prim + 8) = x;
                    *(s16*)(prim + 0xA) = y;
                    prim[0xD] = vv;
                    ((u8*)tp)[3] = 1;
                    tp[1] = (tile >> 8) | 0xE1000020;
                    SETADDR(tp, prim);
                    SETADDR(prim, tp + 2);
                    tp += 2;
                    prim += 0x28;
                }
                n--;
                p += 4;
            } while (n != 0);
        }
        tag = arg0[0x16];
        hi = (u8)tag;
        if (hi == 0xFF) {
            SETADDR(prim - 0x28, GETADDR(OT_AC));
            SETADDR(OT_AC, SCR_TPAGE);
        } else {
            hi >>= 4;
            lo = tag & 7;
            SETADDR(D_8008EB08[SCR_BUF][hi][lo], SCR_TPAGE);
            D_8008EB08[SCR_BUF][hi][lo] = (X4_P_TAG*)(prim - 0x28);
        }
        SCR_PRIM = prim;
        SCR_TPAGE = tp;
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_800232D4);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_800239CC);
// clang-format on

#include "common.h"
#include "psyq/libgpu.h"
#include "mmx6/x4.h"

extern X4_P_TAG* D_8008EB08[2][4][8];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_DrawInfo* g_cur_draw_info;

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PRIM (*(u8**)0x1F800100)
#define SCR_TPAGE (*(u32**)0x1F800104)
#define SCR_COUNT (*(s32*)0x1F800124)
#define OT_78 ((X4_P_TAG*)((u8*)g_cur_draw_info + 0x78))
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))
#define GETADDR(p) (((X4_P_TAG*)(p))->addr)

void func_80023ED8(u8* arg0) {
    s16 dx;
    s16 dy;
    u8* prim;
    u32* tp;
    u8 c;
    s32 tag;
    u32 hi;
    s32 lo;
    s32 cnt;

    cnt = SCR_COUNT;
    if (cnt < 1000) {
        SCR_COUNT = cnt + 1;
        if (*(s8*)(arg0 + 0x37) < 0) {
            dx = *(s16*)(arg0 + 0xA);
            dy = *(s16*)(arg0 + 0xE);
        } else {
            dx = *(u16*)(arg0 + 0xA) -
                 background_objects[*(s8*)(arg0 + 0x37)].x_pos.u.hi;
            dy = *(u16*)(arg0 + 0xE) -
                 background_objects[*(s8*)(arg0 + 0x37)].y_pos.u.hi;
        }
        tp = SCR_TPAGE;
        prim = SCR_PRIM;
        prim[3] = 5;
        prim[7] = 0x28;
        if (arg0[0] & 0x10) {
            prim[7] |= 2;
        } else {
            prim[7] &= ~2;
        }
        *(s16*)(prim + 0x8) = dx + *(s16*)(arg0 + 0x16);
        *(s16*)(prim + 0xA) = dy + *(s16*)(arg0 + 0x1A);
        *(s16*)(prim + 0xC) = dx + *(s16*)(arg0 + 0x1E);
        *(s16*)(prim + 0xE) = dy + *(s16*)(arg0 + 0x22);
        *(s16*)(prim + 0x10) = dx + *(s16*)(arg0 + 0x2E);
        *(s16*)(prim + 0x12) = dy + *(s16*)(arg0 + 0x32);
        *(s16*)(prim + 0x14) = dx + *(s16*)(arg0 + 0x26);
        *(s16*)(prim + 0x16) = dy + *(s16*)(arg0 + 0x2A);
        c = arg0[0x34] & 0x1F;
        prim[4] = (c << 3) + (c >> 2);
        c = (*(u16*)(arg0 + 0x34) >> 5) & 0x1F;
        prim[5] = (c << 3) + (c >> 2);
        c = *(u16*)(arg0 + 0x34) >> 10;
        prim[6] = (c << 3) + (c >> 2);
        ((u8*)tp)[3] = 1;
        tp[1] = (GetTPage(0, (s32)(arg0[0] << 24) >> 29, 0, 0) & 0x9FF) |
                0xE1000000;
        tag = arg0[0x36];
        hi = (u8)tag;
        if (hi == 0xFF) {
            SETADDR(SCR_PRIM, GETADDR(OT_78));
            SETADDR(OT_78, SCR_TPAGE);
        } else {
            s32 h = hi >> 4;
            lo = tag & 7;
            SETADDR(D_8008EB08[SCR_BUF][h][lo], tp);
            SETADDR(tp, prim);
            D_8008EB08[SCR_BUF][h][lo] = (X4_P_TAG*)prim;
        }
        SCR_PRIM += 0x28;
        SCR_TPAGE += 2;
    }
}

#include "common.h"
#include "psyq/libgpu.h"
#include "mmx6/x4.h"

extern X4_P_TAG* D_8008EB08[2][4][8];
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_80071414[];

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PRIM (*(u8**)0x1F800100)
#define SCR_TPAGE (*(u32**)0x1F800104)
#define SCR_COUNT (*(s32*)0x1F800124)

// str 0x80071414 sha1=da17cf3c1e17339ae83536220ac20010c213d1ea = "six 0xC6 bytes: data, not text"
void func_800241D4(void* arg0) {
    u8* a = arg0;
    s16 dx;
    s16 dy;
    u8* prim;
    u32* tp;
    u8* c;
    s32 code;
    u32 hi;
    u32 lo;
    s32 cnt;

    cnt = SCR_COUNT;
    if (cnt < 1000) {
        SCR_COUNT = cnt + 1;
        if (*(s8*)(a + 0x37) < 0) {
            dx = *(s16*)(a + 0xA);
            dy = *(s16*)(a + 0xE);
        } else {
            dx = *(u16*)(a + 0xA) -
                 background_objects[*(s8*)(a + 0x37)].x_pos.u.hi;
            dy = *(u16*)(a + 0xE) -
                 background_objects[*(s8*)(a + 0x37)].y_pos.u.hi;
        }
        tp = SCR_TPAGE;
        prim = SCR_PRIM;
        ((X4_P_TAG*)prim)->len = 8;
        ((X4_P_TAG*)prim)->code = 0x38;
        if (a[0] & 0x10) {
            ((X4_P_TAG*)prim)->code |= 2;
        } else {
            ((X4_P_TAG*)prim)->code &= ~2;
        }
        *(s16*)(prim + 0x8) = dx + *(s16*)(a + 0x16);
        *(s16*)(prim + 0xA) = dy + *(s16*)(a + 0x1A);
        *(s16*)(prim + 0x10) = dx + *(s16*)(a + 0x1E);
        *(s16*)(prim + 0x12) = dy + *(s16*)(a + 0x22);
        *(s16*)(prim + 0x18) = dx + *(s16*)(a + 0x2E);
        *(s16*)(prim + 0x1A) = dy + *(s16*)(a + 0x32);
        *(s16*)(prim + 0x20) = dx + *(s16*)(a + 0x26);
        *(s16*)(prim + 0x22) = dy + *(s16*)(a + 0x2A);
        c = &D_80071414[*(u16*)(a + 0x34) * 12];
        prim[0x4] = *c++;
        prim[0x5] = *c++;
        prim[0x6] = *c++;
        prim[0xC] = *c++;
        prim[0xD] = *c++;
        prim[0xE] = *c++;
        prim[0x1C] = *c++;
        prim[0x1D] = *c++;
        prim[0x1E] = *c++;
        prim[0x14] = *c++;
        prim[0x15] = *c++;
        prim[0x16] = *c++;
        ((X4_P_TAG*)tp)->len = 1;
        tp[1] =
            (GetTPage(0, (s32)(a[0] << 24) >> 29, 0, 0) & 0x9FF) | 0xE1000000;
        hi = a[0x36] >> 4;
        lo = a[0x36] & 7;
        D_8008EB08[SCR_BUF][hi][lo]->addr = (u32)tp;
        ((X4_P_TAG*)tp)->addr = (u32)prim;
        D_8008EB08[SCR_BUF][hi][lo] = (X4_P_TAG*)prim;
        SCR_PRIM += 0x28;
        SCR_TPAGE += 2;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
void func_800246B4(void* arg0);
void func_800249D4(void* arg0);
void func_80024CC0(s32 arg0, u8 arg1);
void func_80024F90(void* arg0, s32 arg1);
extern M2C_UNK g_Player;
extern struct X4_EngineObj g_playthrough_state;

#define B8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800244C0(void) {
    u8* p = (u8*)&g_Player;
    struct X4_EngineObj* e = &g_playthrough_state;
    s32 v;
    s32 q;
    s32 a0;

    if (e->unk1F != 0) {
        func_80024F90(p, 0);
        if (B8(p, 2) == 0) {
            func_800246B4(p);
        } else {
            func_800249D4(p);
        }
        if (B8(p, 0x14E) != 0) {
            func_80024CC0(0xA, 0);
        }
        if (S16(p, 0x148) != 0) {
            if (S16(p, 0x148) >= 0x3D) {
                func_80024CC0(0x12, U8(p, 0x144) + 0x1A);
            } else if (D_80097420.frame_counter & 1) {
                func_80024CC0(0x12, U8(p, 0x144) + 0x1A);
            }
        }
        if (e->enable_boss != 0) {
            struct X4_EngineObj* e2 = &g_playthrough_state;
            s16 n = U8(e2, 0x8F) + 1;
            v = n;
            q = v / 10;
            func_80024CC0(0xE, q + 0x3B);
            func_80024CC0(0xF, v - q * 10 + 0x3B);
            func_80024F90(e->boss_ptr, 1);
            if (e->unk25 == 0) {
                v = (B8(e, 0x8C) - 0x20) / 2 + 0xA3;
                a0 = 7;
                if (v >= 0xD4) {
                    v = 0xD3;
                }
                goto call;
            }
            if (e->unk25 == 1) {
                v = (B8(e, 0x8C) - 0x20) / 2;
                a0 = 0x10;
                if (v >= 0x31) {
                    v = 0x30;
                }
            call:
                func_80024CC0(a0, v);
                return;
            }
            func_80024CC0(0x11, 0xA2);
        }
    }
}

#undef B8
#undef U8
#undef S16

#include "common.h"
#include "mmx6/x4.h"

void func_80024CC0(s32 arg0, u8 arg1);
void func_800253AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, u32 arg5,
                   u32 arg6);
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
extern u8 D_80071DBC[];
extern s8 D_800970A2;
extern struct X4_EngineObj g_playthrough_state;

#define FB(p, o) (*(s8*)((u8*)(p) + (o)))
#define FH(p, o) (*(s16*)((u8*)(p) + (o)))
#define FUH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800246B4(void* arg0) {
    s32 x;
    s32 d;
    s32 w;
    s32 i;

    if (FB(arg0, 0x93) == 0) {
        struct X4_EngineObj* e = &g_playthrough_state;
        x = (s8) * ((u8*)&e->controlled_player + 1);
        d = x / 10;
        func_80024CC0(3, d + 0x3B);
        func_80024CC0(4, x - d * 10 + 0x3B);
    } else {
        i = FB(arg0, 0x93) * 2;
        x = *(s16*)((u8*)arg0 + i + 0xA8);
        x = (s16)(x / get_weapon_energy_cost(arg0, FB(arg0, 0x94)));
        func_80024CC0(0xB, x / 100 + 0x3B);
        func_80024CC0(0xC, (s16)(x % 100) / 10 + 0x3B);
        func_80024CC0(0xD, x % 10 + 0x3B);
    }
    if (FB(arg0, 0x93) != 0) {
        func_80024CC0(5, D_80071DBC[FB(arg0, 0x93) - 1]);
        if (FB(arg0, 0x93) != 0) {
            w = FB(arg0, 0x93) * 2;
            w = (s16) * (u16*)((u8*)arg0 + w + 0xA8);
            x = (s16)(w / 6);
            if (x == 0 && w != 0) {
                x = 1;
            }
            func_800253AC(0x1F, 0x22, 0x50 - x, 0x50, 2,
                          (s16)((s16)FUH(arg0, 0x14A) / 6), x);
            if (FB(arg0, 0x93) != 0) {
                x = (s16)(((s16)((s16)FUH(arg0, 0x14A) / 6) - 0x30) / 2 + 0x99);
                if (x >= 0xA2) {
                    x = 0xA1;
                }
                func_80024CC0(2, x);
            }
        }
    }
    {
        u8* p = (u8*)&g_playthrough_state;
        s32 j = D_800970A2;
        x = (*(s8*)(p - -j + 0x5B) - 0x20) / 2 + 0x88;
    }
    if (x >= 0x99) {
        x = 0x98;
    }
    func_80024CC0(0, x);
}

#include "common.h"
#include "mmx6/x4.h"

void func_80024CC0(s32 arg0, u8 arg1);
void func_800253AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, u32 arg5,
                   u32 arg6);
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
extern u8 D_80071DC4[];
extern s8 D_800970A2;
extern struct X4_EngineObj g_playthrough_state;

#define FB(p, o) (*(s8*)((u8*)(p) + (o)))
#define FH(p, o) (*(s16*)((u8*)(p) + (o)))
#define FUH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800249D4(void* arg0) {
    s32 x;
    s32 d;
    s32 w;
    s32 i;
    s16* t;

    i = FB(arg0, 0x93);
    if (i == 0) {
        struct X4_EngineObj* e = &g_playthrough_state;
        x = (s8) * ((u8*)&e->controlled_player + 1);
        d = x / 10;
        func_80024CC0(3, d + 0x3B);
        func_80024CC0(4, x - d * 10 + 0x3B);
    } else {
        {
            s32 k = i << 1;
            t = (s16*)((u8*)arg0 + 0xA8);
            x = *(s16*)((u8*)t + k);
        }
        x = (s16)(x / get_weapon_energy_cost(arg0, i));
        func_80024CC0(0xB, x / 100 + 0x3B);
        func_80024CC0(0xC, (s16)(x % 100) / 10 + 0x3B);
        func_80024CC0(0xD, x % 10 + 0x3B);
        func_80024CC0(5, D_80071DC4[FB(arg0, 0x93) - 1]);
        w = *(s16*)((u8*)t + (FB(arg0, 0x93) << 1));
        x = (s16)(w / 6);
        func_800253AC(0x1F, 0x22, 0x50 - x, 0x50, 2,
                      (s16)((s16)FUH(arg0, 0x14A) / 6), x);
        x = (s16)(((s16)((s16)FUH(arg0, 0x14A) / 6) - 0x30) / 2 + 0x99);
        if (x >= 0xA2) {
            x = 0xA1;
        }
        func_80024CC0(2, x);
    }
    {
        u8* p = (u8*)&g_playthrough_state;
        s32 j = D_800970A2;
        x = (*(s8*)(p - -j + 0x5B) - 0x20) / 2 + 0x88;
    }
    if (x >= 0x99) {
        x = 0x98;
    }
    func_80024CC0(0, x);
}

#include "common.h"
#include "mmx6/x4.h"

extern s16 D_80071DCC[][3];
extern struct X4_DrawInfo* g_cur_draw_info;
extern struct X4_EngineObj g_playthrough_state;

#define SP_1C (*(u8**)SP(0x01C))
#define SP_3C (*(u8**)SP(0x03C))
#define PRIM_NEXT (*(u8**)SP(0x108))
#define TPAGE_NEXT (*(u8**)SP(0x10C))
#define PB(p, o) (*(u8*)((p) + (o)))
#define PH(p, o) (*(s16*)((p) + (o)))
#define PW(p, o) (*(u32*)((p) + (o)))

void func_80024CC0(s32 arg0, u8 arg1) {
    u8* base;
    u8* ent;
    u8* src;
    u8* p;
    u8* t;
    s32 count;
    s8* e;
    u16 clut;
    s32 add;
    s32 flags;
    s16 x;
    s16 y;
    u8 b0;
    u32 tile;
    u32* ot;
    s32 w;
    u8 c;

    add = 0;
    flags = 0x21;
    if (arg0 == 10) {
        base = SP_1C + *(s32*)(SP_1C + 0x58);
    } else if (arg0 == 16) {
        base = SP_1C + *(s32*)(SP_1C + 0x5C);
    } else if (arg0 == 5 || arg0 == 18) {
        flags = 0;
        add = 0x1E00;
        base = SP_3C + *(s32*)SP_3C;
    } else {
        base = SP_1C + *(s32*)(SP_1C + 4);
    }
    ent = base + arg1 * 4;
    count = *(u16*)ent;
    p = PRIM_NEXT;
    t = TPAGE_NEXT;
    src = base + *(u16*)(ent + 2) * 4;
    clut = D_80071DCC[arg0][2];
    if (count != 0) {
        do {
            b0 = src[0];
            x = D_80071DCC[arg0][0] + (s8)src[2];
            y = D_80071DCC[arg0][1] + (s8)src[3];
            if ((u32)(arg0 - 0xE) < 2) {
                e = (s8*)&g_playthrough_state;
                y += ((e[0x8C] - 0x20) >> 1) << 1;
            }
            {
                u32 h = (b0 & 3) << 8;
                tile = src[1] | h;
            }
            w = flags & 0x20;
            tile += add;
            if (w) {
                u16 q = tile / 80;
                tile = (u16)((q << 8) + tile % 80 + 0x5B0);
            }
            c = 0x7D;
            PB(p, 3) = 3;
            PB(p, 7) = c;
            PB(p, 0xC) = tile << 4;
            PB(p, 0xD) = tile & 0xF0;
            PH(p, 8) = x;
            PH(p, 0xA) = y;
            PH(p, 0xE) = clut + ((b0 & 0xC) >> 2);
            PB(t, 3) = 1;
            PW(t, 4) = (tile >> 8) | 0xE1000000;
            ((X4_P_TAG*)t)->addr = (u32)p;
            ((X4_P_TAG*)p)->addr = (u32)(t + 8);
            t += 8;
            p += 0x10;
            src += 4;
            count--;
        } while (count != 0);
    }
    ot = &g_cur_draw_info->ordering_table.unk5[0];
    PW(p, -0x10) = (PW(p, -0x10) & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)TPAGE_NEXT & 0xFFFFFF);
    PRIM_NEXT = p;
    TPAGE_NEXT = t;
}

#include "common.h"
#include "mmx6/x4.h"

void func_800253AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, u32 arg5,
                   u32 arg6);
extern s16 D_80071E40[][2];
#define M2C_UNK s32
extern M2C_UNK g_Player;
extern s8 D_800970A2;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCF5C;

#define FB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_80024F90(void* arg0, s32 arg1) {
    s16 x0;
    s16 y;
    // !FAKE: depin: dropping it breaks the match (156/174)
    register s32 lvl asm("$18");
    s32 max;
    s32 f;
    s32 g;

    {
        // !FAKE: depin: dropping it breaks the match (172/174)
        register s32 b asm("$2") = *(u8*)((u8*)arg0 + 0x5C);
        lvl = b & 0x7F;
    }
    if (arg1 == 0) {
        u8* e = (u8*)&g_playthrough_state;
        s32 j = D_800970A2;
        max = *(s8*)(e - -j + 0x5B);
    } else {
        s32 t = D_800CCF5C;
        if (t < 0x20) {
            max = 0x30;
        } else {
            max = t;
        }
    }
    x0 = D_80071E40[arg1][0];
    if (arg1 == 0 && D_800970A2 == 1) {
        x0++;
    }
    f = lvl < 8;
    y = D_80071E40[arg1][1];
    g = f;
    if (arg1 == 0) {
        struct X4_PlayerObj* p = &g_Player;
        if (FB(p, 0xE8) != 0) {
            FB(p, 0xE8)--;
            g = 3;
        }
        if (FB(p, 2) != 0) {
            x0--;
        }
        func_800253AC(x0, x0 + 3, y - lvl, y, g, max, lvl);
    } else {
        func_800253AC(x0, x0 + 3, y + (max - lvl), y + max, f, max, lvl);
    }
    if (lvl != FB(arg0, 0x5D)) {
        if (FB(arg0, 0x5D) < lvl) {
            FB(arg0, 0x5D) = lvl;
            return;
        }
        if (FB(arg0, 0x5C) & 0x80) {
            FB(arg0, 0x5F) = 0x10;
        }
        if (arg1 == 0) {
            do {
                func_800253AC(x0, x0 + 3, y - FB(arg0, 0x5D), y - lvl, 3, 1, 1);
            } while (0);
        } else {
            func_800253AC(x0, x0 + 3, y + (max - FB(arg0, 0x5D)), y - lvl + max,
                          3, 1, 1);
        }
        if (FB(arg0, 0x5F) != 0) {
            FB(arg0, 0x5F)--;
            return;
        }
        if (!(D_80097420.frame_counter & 3)) {
            FB(arg0, 0x5D)--;
        }
    }
}

#include "common.h"

extern s32 D_80090C90[][16];
#define D_80090C90 (*(s32(*)[]) & D_80090C90)
extern s8 D_80090D56;
#define D_80090D56 (*(u8*)&D_80090D56)
extern s16 D_80090D5C;
extern s8 D_8009742C;
#define D_8009742C (*(u8*)&D_8009742C)
extern s16 D_80097430;
extern s8 D_800CF850;
#define D_800CF850 (*(u8*)&D_800CF850)
extern s16 D_800CF854;

u32 func_80025248(u16 arg0) {
    s32 r;
    s32 g;
    s32 b;
    u32 v;
    u32 x;

    if (D_80090C90[0] & 0xC000) {
        v = (u16)D_800CF854;
        x = v | (u16)D_80097430;
        if (((u16)D_80090D5C | x) != 0) {
            v &= 0xFFFF;
            if ((v == ((u16)D_80097430 >> 5)) &&
                (v == ((u16)D_80090D5C >> 10))) {
                if (D_800CF850 != 0) {
                    r = 0;
                    if ((arg0 & 0x1F) >= v) {
                        r = (arg0 & 0x1F) - (u16)D_800CF854;
                    }
                } else {
                    r = (arg0 & 0x1F) + (u16)D_800CF854;
                    if (r >= 0x20) {
                        r = 0x1F;
                    }
                }
                if (D_8009742C != 0) {
                    g = 0;
                    if ((arg0 & 0x3E0) >= (u16)D_80097430) {
                        g = (arg0 & 0x3E0) - (u16)D_80097430;
                    }
                } else {
                    g = (arg0 & 0x3E0) + (u16)D_80097430;
                    if (g >= 0x3E1) {
                        g = 0x3E0;
                    }
                }
                if (D_80090D56 != 0) {
                    if ((arg0 & 0x7C00) >= (u16)D_80090D5C) {
                        b = (arg0 & 0x7C00) - (u16)D_80090D5C;
                    } else {
                        b = 0;
                    }
                } else {
                    b = (arg0 & 0x7C00) + (u16)D_80090D5C;
                    if (b >= 0x7C01) {
                        b = 0x7C00;
                    }
                }
                arg0 = (r | g | b | (arg0 & 0x8000));
            }
        }
    }
    return arg0;
}

#undef D_80090C90
#undef D_80090D56
#undef D_8009742C
#undef D_800CF850

#include "common.h"
#include "mmx6/x4.h"

u32 func_80025248(u16);
extern u16 D_80071E48[][4];
extern struct X4_DrawInfo* g_cur_draw_info;

#define PRIM_NEXT (*(u8**)SP(0x110))
#define PB(p, o) (*(u8*)((p) + (o)))
#define PH(p, o) (*(s16*)((p) + (o)))
#define PW(p, o) (*(u32*)((p) + (o)))

#define RGB15(o, k)                                                            \
    {                                                                          \
        u32 c, r, g, b, rr, gg, bb;                                            \
        c = func_80025248(D_80071E48[arg4][k]);                                \
        b = c >> 10;                                                           \
        do {                                                                   \
            r = c & 0x1F;                                                      \
            rr = r * 8 + (r >> 2);                                             \
            g = (c >> 5) & 0x1F;                                               \
            gg = g * 8 + (g >> 2);                                             \
        } while (0);                                                           \
        b &= 0xFF;                                                             \
        bb = b * 8 + (b >> 2);                                                 \
        PB(p, (o)) = rr;                                                       \
        PB(p, (o) + 1) = gg;                                                   \
        PB(p, (o) + 2) = bb;                                                   \
    }

#define BLEND(o, o2)                                                           \
    {                                                                          \
        u8 a, e;                                                               \
        u32 v;                                                                 \
        a = PB(p, (o));                                                        \
        e = PB(p, (o2));                                                       \
        if (a == e || arg5 == arg6) {                                          \
            v = a;                                                             \
        } else if (arg6 == 0) {                                                \
            v = e;                                                             \
        } else if (e < a) {                                                    \
            v = e + (a - e) * arg6 / arg5;                                     \
        } else {                                                               \
            v = a + (e - a) * (arg5 - arg6) / arg5;                            \
        }                                                                      \
        PB(p, (o)) = v;                                                        \
    }

void func_800253AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, u32 arg5,
                   u32 arg6) {
    u8* p;
    u32* ot;

    p = PRIM_NEXT;
    PB(p, 3) = 8;
    PB(p, 7) = 0x38;
    PH(p, 8) = PH(p, 0x18) = arg0;
    PH(p, 0x10) = PH(p, 0x20) = arg1;
    PH(p, 0xA) = PH(p, 0x12) = arg2;
    PH(p, 0x1A) = PH(p, 0x22) = arg3;
    RGB15(4, 0);
    RGB15(0xC, 1);
    RGB15(0x14, 2);
    RGB15(0x1C, 3);
    BLEND(4, 0x14);
    BLEND(5, 0x15);
    BLEND(6, 0x16);
    BLEND(0xC, 0x1C);
    BLEND(0xD, 0x1D);
    BLEND(0xE, 0x1E);
    ot = &g_cur_draw_info->ordering_table.unk5[0];
    PW(p, 0) = (PW(p, 0) & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    PRIM_NEXT += 0x24;
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80025984);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80025E1C);
// clang-format on

/* Adapted from sozud/mmx4 @807a01b src/main/144A4.c:func_80023CE0, AGPL-3.0; proven shared with X6 by exact signature 6affe00825b4 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_80071D88[16][2];

void func_80025F34() {
    func_8002649C(
        0, D_80071D88[g_playthrough_state.stage][g_playthrough_state.substage]);
    func_8002798C();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800CD3F0;

void func_80025F84(void) {
    M2C_FIELD(&D_800CD3F0, s8*, 0) = 5;
    M2C_FIELD(&D_800CD3F0, s8*, 1) = 6;
    M2C_FIELD(&D_800CD3F0, s8*, 2) = 7;
    M2C_FIELD(&D_800CD3F0, s8*, 3) = 8;
}

#include "common.h"

#define M2C_UNK s32

void func_80022960(void); /* extern */
void func_80026D44(void); /* extern */

void func_80025FB0(void) {
    func_80026D44();
    func_80022960();
}
