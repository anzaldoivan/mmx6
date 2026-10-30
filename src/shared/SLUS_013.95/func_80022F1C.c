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
