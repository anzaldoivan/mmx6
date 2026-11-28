#include "common.h"
#include "psyq/libspu.h"

extern u8* D_80097780;

s32 func_800175F0(u8 arg0) {
    u8* p = D_80097780 + arg0 * 4;
    return SpuGetKeyStatus(1 << (p[3] & 0x1F)) == 0;
}

#ifdef NON_MATCHING
#include "common.h"
#include "mmx6/globals.h"

extern s32 D_801F3008;

#define SCR_PRIM (*(u8**)0x1F800100)
#define SCR_TPAGE (*(u32**)0x1F800104)
#define SPR_BANK 0x801F3000
#define OT_AC ((X4_P_TAG*)((u8*)g_cur_draw_info + 0xAC))
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))
#define GETADDR(p) (((X4_P_TAG*)(p))->addr)

void func_80017630(u8 idx, s16 dx, s16 dy, u8 pal, u8* limit) {
    u8* prim;
    u32* tp;
    u8* tbl;
    u8* e;
    u8* p;
    s32 n;
    u16 clut;
    u32 tile;
    s32 len;
    s32 m;
    u32 tpage;
    u8 b0;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;
    u8 u0;
    u8 u1;
    u8 v0;
    u8 v1;
    s32 cbase;
    s32 xo;

    tbl = (u8*)(D_801F3008 + SPR_BANK);
    xo = pal >> 2;
    xo = (xo + 0x1F0) << 6;
    cbase = (pal & 3) | 0x10 | xo;
    prim = SCR_PRIM;
    tp = SCR_TPAGE;
    e = tbl + idx * 4;
    n = *(u16*)e;
    p = tbl + *(u16*)(e + 2) * 4;
    while (n != 0) {
        if (prim >= limit) {
            return;
        }
        x0 = ((s8*)p)[2];
        b0 = p[0];
        x1 = x0 + 0x10;
        x0 = x0 + dx;
        x1 = x1 + dx;
        y0 = dy + (s8)p[3];
        y1 = y0 + 0x10;
        tile = p[1] | ((b0 & 3) << 8);
        tile += 0x1E00;
        do {
        } while (0);
        {
            u32 k;
            k = b0 & 0xC;
            k >>= 2;
            clut = cbase + k;
        }
        if (!(b0 & 0x80)) {
            v0 = tile & 0xF0;
            if (!(b0 & 0x40)) {
                tpage = (tile >> 8) | 0xE1000020;
                len = 3;
                prim[3] = len;
                prim[0xC] = tile << 4;
                m = 0x7D;
                prim[7] = m;
                *(u16*)(prim + 0xE) = clut;
                *(s16*)(prim + 8) = x0;
                *(s16*)(prim + 0xA) = y0;
                prim[0xD] = v0;
                tp[1] = tpage;
                ((u8*)tp)[3] = 1;
                SETADDR(tp, prim);
                SETADDR(prim, tp + 2);
            } else {
                u1 = (tile << 4) - 1;
                m = u1 + 0x10;
                u0 = m;
                len = 9;
                prim[3] = len;
                *(u16*)(prim + 0x16) = (tile >> 8) | 0x20;
                prim[7] = 0x2D;
                *(u16*)(prim + 0xE) = clut;
                if (u1 == 0xFF) {
                    u1 = 0;
                    x1--;
                }
                v1 = v0 + 0x10;
                if (v1 == 0) {
                    v1 = 0xFF;
                    y1--;
                }
                *(s16*)(prim + 8) = x0;
                *(s16*)(prim + 0xA) = y0;
                *(s16*)(prim + 0x10) = x1;
                *(s16*)(prim + 0x12) = y0;
                *(s16*)(prim + 0x18) = x0;
                *(s16*)(prim + 0x1A) = y1;
                *(s16*)(prim + 0x20) = x1;
                *(s16*)(prim + 0x22) = y1;
                prim[0xC] = u0;
                prim[0xD] = v0;
                prim[0x14] = u1;
                prim[0x15] = v0;
                prim[0x1C] = u0;
                prim[0x1D] = v1;
                prim[0x24] = u1;
                prim[0x25] = v1;
                tpage = 0xE1000020;
                tp[1] = tpage;
                ((u8*)tp)[3] = 1;
                SETADDR(tp, prim);
                SETADDR(prim, tp + 2);
            }
        } else {
            v1 = (tile & 0xF0) - 1;
            v0 = v1 + 0x10;
            len = 9;
            prim[3] = len;
            *(u16*)(prim + 0xE) = clut;
            prim[7] = 0x2D;
            *(u16*)(prim + 0x16) = (tile >> 8) | 0x20;
            if (v1 == 0xFF) {
                v1 = 0;
                y1--;
            }
            if (!(b0 & 0x40)) {
                u0 = tile << 4;
                u1 = u0 + 0x10;
                if (u1 == 0) {
                    u1 = 0xFF;
                    x1--;
                }
            } else {
                u1 = (tile << 4) - 1;
                u0 = u1 + 0x10;
                if (u1 == 0xFF) {
                    u1 = 0;
                    x1--;
                }
            }
            *(s16*)(prim + 8) = x0;
            *(s16*)(prim + 0xA) = y0;
            *(s16*)(prim + 0x10) = x1;
            *(s16*)(prim + 0x12) = y0;
            *(s16*)(prim + 0x18) = x0;
            *(s16*)(prim + 0x1A) = y1;
            *(s16*)(prim + 0x20) = x1;
            *(s16*)(prim + 0x22) = y1;
            prim[0xC] = u0;
            prim[0xD] = v0;
            prim[0x14] = u1;
            prim[0x15] = v0;
            prim[0x1C] = u0;
            prim[0x1D] = v1;
            prim[0x24] = u1;
            prim[0x25] = v1;
            tpage = 0xE1000020;
            tp[1] = tpage;
            ((u8*)tp)[3] = 1;
            SETADDR(tp, prim);
            SETADDR(prim, tp + 2);
        }
        SETADDR(prim, GETADDR(OT_AC));
        SETADDR(OT_AC, tp);
        tp += 2;
        prim += 0x28;
        p += 4;
        n--;
    }
    SCR_PRIM = prim;
    SCR_TPAGE = tp;
}
#else
// clang-format off
INCLUDE_ASM("main/nonmatchings/120A0", func_80017630);
// clang-format on
#endif
