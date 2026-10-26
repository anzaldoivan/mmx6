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
