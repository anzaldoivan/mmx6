#include "common.h"
#include "mmx6/x4.h"

extern X4_P_TAG* D_8008EB08[2][4][8];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_DrawInfo* D_8009B7A0;
s32 func_80068DD4(s32, s32, s32, s32);

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PRIM (*(u8**)0x1F800100)
#define SCR_TPAGE (*(u32**)0x1F800104)
#define SCR_COUNT (*(s32*)0x1F800124)
#define OT_78 ((X4_P_TAG*)((u8*)D_8009B7A0 + 0x78))
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
        tp[1] = (func_80068DD4(0, (s32)(arg0[0] << 24) >> 29, 0, 0) & 0x9FF) |
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
