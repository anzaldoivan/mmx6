#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8009B79C;
extern struct X4_DrawInfo* D_8009B7A0;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800CF8A0[];
extern u8 D_800CF8B8[];

#define SCR_BUF (*(s32*)0x1F800000)
#define ENG_D0 (*(s8*)(eng + 0xD0))
#define ENG_D1 (*(s8*)(eng2 + 0xD1))
#define OT_E8 ((X4_P_TAG*)((u8*)D_8009B7A0 + 0xE8))
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))
#define GETADDR(p) (((X4_P_TAG*)(p))->addr)
#define H(p, o) (*(s16*)((p) + (o)))

void func_800123D0(void) {
    u8* prim;
    u8* eng;
    u8* eng2;

    eng = (u8*)&D_800CCED0;
    if (ENG_D0 != 0) {
        prim = D_800CF8A0 + SCR_BUF * 0x30;
        prim[3] = 5;
        prim[7] = 0x28;
        prim[4] = 0;
        prim[5] = 0;
        prim[6] = 0;
        if (ENG_D0 > 0) {
            H(prim, 0x8) = 0;
            H(prim, 0xA) = 0;
            H(prim, 0xC) = ENG_D0;
            H(prim, 0xE) = 0;
            H(prim, 0x10) = 0;
            H(prim, 0x12) = 0xF0;
            H(prim, 0x14) = ENG_D0;
            H(prim, 0x16) = 0xF0;
        } else {
            u16 w = D_8009B79C;
            H(prim, 0x8) = ENG_D0 + w;
            H(prim, 0xA) = 0;
            H(prim, 0xC) = ENG_D0 + w - ENG_D0;
            H(prim, 0xE) = 0;
            H(prim, 0x10) = ENG_D0 + w;
            H(prim, 0x12) = 0xF0;
            H(prim, 0x14) = ENG_D0 + w - ENG_D0;
            H(prim, 0x16) = 0xF0;
        }
        SETADDR(prim, GETADDR(OT_E8));
        SETADDR(OT_E8, prim);
    }
    eng2 = (u8*)&D_800CCED0;
    if (*(s8*)(eng2 + 0xD1) != 0) {
        prim = D_800CF8B8 + SCR_BUF * 0x30;
        prim[3] = 5;
        prim[7] = 0x28;
        prim[4] = 0;
        prim[5] = 0;
        prim[6] = 0;
        if (ENG_D1 > 0) {
            u16 w = D_8009B79C;
            H(prim, 0x8) = 0;
            H(prim, 0xA) = 0;
            H(prim, 0xC) = w;
            H(prim, 0xE) = 0;
            H(prim, 0x10) = 0;
            H(prim, 0x12) = ENG_D1;
            H(prim, 0x14) = w;
            H(prim, 0x16) = ENG_D1;
        } else {
            u16 w;
            H(prim, 0x8) = 0;
            w = D_8009B79C;
            H(prim, 0xA) = ENG_D1 + 0xF0;
            H(prim, 0xC) = w;
            H(prim, 0xE) = ENG_D1 + 0xF0;
            H(prim, 0x10) = 0;
            H(prim, 0x12) = 0xF0;
            H(prim, 0x14) = w;
            H(prim, 0x16) = 0xF0;
        }
        SETADDR(prim, GETADDR(OT_E8));
        SETADDR(OT_E8, prim);
    }
}
