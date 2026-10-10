#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80070C84[][6];
extern u8 D_8008EAFC;
extern X4_P_TAG* D_8008EB08[2][4][8];
u32 func_800260C4(u8, u8, u8);
u8 func_8002624C(u8, u8, s32, s32);

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PRIM (*(u8**)0x1F800100)
#define SCR_TPAGE (*(u32**)0x1F800104)
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))

void func_800199E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5,
                   s32 arg6) {
    u8* prim;
    u32* tp;
    s32 x1;
    s32 y1;
    u32 c;
    s32 lo;

    x1 = arg0 + arg2;
    tp = SCR_TPAGE;
    prim = SCR_PRIM;
    y1 = arg1 + arg3;
    prim[3] = 8;
    prim[7] = 0x38;
    *(s16*)(prim + 0x8) = arg0;
    *(s16*)(prim + 0xA) = arg1;
    *(s16*)(prim + 0x10) = x1;
    *(s16*)(prim + 0x12) = arg1;
    *(s16*)(prim + 0x20) = x1;
    *(s16*)(prim + 0x22) = y1;
    *(s16*)(prim + 0x18) = arg0;
    *(s16*)(prim + 0x1A) = y1;
    prim[4] = D_80070C84[arg4][0];
    prim[5] = D_80070C84[arg4][1];
    prim[6] = D_80070C84[arg4][2];
    prim[0xC] = D_80070C84[arg4][3];
    prim[0xD] = D_80070C84[arg4][4];
    prim[0xE] = D_80070C84[arg4][5];
    prim[0xC] = func_8002624C(prim[0xC], prim[4], arg5, arg6);
    prim[0xD] = func_8002624C(prim[0xD], prim[5], arg5, arg6);
    prim[0xE] = func_8002624C(prim[0xE], prim[6], arg5, arg6);
    prim[0x1E] = prim[0xE];
    prim[0x1C] = prim[0xC];
    prim[0x1D] = prim[0xD];
    prim[0x14] = prim[4];
    prim[0x15] = prim[5];
    prim[0x16] = prim[6];
    if (D_8008EAFC != 0) {
        c = func_800260C4(prim[4], prim[5], prim[6]) >> 1;
        prim[6] = c;
        prim[5] = c;
        prim[4] = c;
        c = func_800260C4(prim[0xC], prim[0xD], prim[0xE]) >> 1;
        prim[0xE] = c;
        prim[0xD] = c;
        prim[0xC] = c;
        c = func_800260C4(prim[0x14], prim[0x15], prim[0x16]) >> 1;
        prim[0x16] = c;
        prim[0x15] = c;
        prim[0x14] = c;
        c = func_800260C4(prim[0x1C], prim[0x1D], prim[0x1E]) >> 1;
        prim[0x1E] = c;
        prim[0x1D] = c;
        prim[0x1C] = c;
    }
    ((u8*)tp)[3] = 1;
    lo = 4;
    tp[1] = 0xE1000000;
    SETADDR(D_8008EB08[SCR_BUF][0][lo], tp);
    SETADDR(tp, prim);
    D_8008EB08[SCR_BUF][0][lo] = (X4_P_TAG*)prim;
    SCR_PRIM += 0x28;
    SCR_TPAGE += 2;
}
