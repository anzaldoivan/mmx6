#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "psyq/libgpu.h"
#include "mmx6/psyq_api.h"

extern struct LoadingSprtRow D_8006E1D4[];

#define setaddr(p, _addr) (((X4_P_TAG*)(p))->addr = (u32)(_addr))
#define getaddr(p) (u32)(((X4_P_TAG*)(p))->addr)
#define setlen(p, _len) (((X4_P_TAG*)(p))->len = (u8)(_len))
#define setcode(p, _code) (((X4_P_TAG*)(p))->code = (u8)(_code))
#define getcode(p) (u8)(((X4_P_TAG*)(p))->code)
#define setSprt(p) setlen(p, 4), setcode(p, 0x64)
#define setXY0(p, _x0, _y0) (p)->x0 = (_x0), (p)->y0 = (_y0)
#define setUV0(p, _u0, _v0) (p)->u0 = (_u0), (p)->v0 = (_v0)
#define setWH(p, _w, _h) (p)->w = _w, (p)->h = _h
#define setShadeTex(p, tge)                                                    \
    ((tge) ? setcode(p, getcode(p) | 1) : setcode(p, getcode(p) & ~1))
#define setSemiTrans(p, abe)                                                   \
    ((abe) ? setcode(p, getcode(p) | 2) : setcode(p, getcode(p) & ~2))
#define catPrim(p0, p1) setaddr(p0, p1)
#define addPrims(ot, p0, p1) setaddr(p1, getaddr(ot)), setaddr(ot, p0)

#define SCR_PRIM (*(X4_SPRT**)SP(0x100))
#define SCR_TPAGE (*(struct DR_MODE**)SP(0x104))

// Draws sprite `idx` of D_8006E1D4; sprite 0 blinks (skipped on frames with bit 4 of the frame counter set).
void func_800144DC(u8 idx) {
    struct LoadingSprtRow* e;
    X4_SPRT* prim;
    struct DR_MODE* tp;

    if (idx != 0 || !(D_80097420.frame_counter & 0x10)) {
        e = &D_8006E1D4[idx];
        prim = SCR_PRIM;
        tp = SCR_TPAGE;
        SetDrawMode(tp, 0, 0, GetTPage(0, 0, 0x340, 0x100), 0);
        setSprt(prim);
        setXY0(prim, e->x, e->y);
        setUV0(prim, (e->uv % 16) * 16, (e->uv / 16) * 16);
        prim->clut = (e->clut % 16) | ((0x1E0 + e->clut / 16) << 6);
        setShadeTex(prim, 1);
        setSemiTrans(prim, 0);
        setWH(prim, e->w * 16, e->h * 16);
        catPrim(tp, prim);
        addPrims(&g_cur_draw_info->ordering_table.unk5[1], tp, prim);
        prim++;
        tp = (struct DR_MODE*)((u32*)tp + 3);
        SCR_PRIM = prim;
        SCR_TPAGE = tp;
    }
}

#undef SCR_PRIM
#undef SCR_TPAGE
#undef setaddr
#undef getaddr
#undef setlen
#undef setcode
#undef getcode
#undef setSprt
#undef setXY0
#undef setUV0
#undef setWH
#undef setShadeTex
#undef setSemiTrans
#undef catPrim
#undef addPrims
