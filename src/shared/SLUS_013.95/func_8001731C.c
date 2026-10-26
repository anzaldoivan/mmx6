#include "common.h"
#include "mmx6/x4.h"

void func_80016178(void);
void func_8001642C(s32 arg0, s32* arg1, u8* arg2);
void SsSepClose(s8);
s8 SsSepOpen(void*, s8, s32);
void SsSepSetVol(s8, u32, s32, s32);
extern u8 D_8006E35C[];
extern s8 D_80090D50[6];
extern s8 D_80090D64[];
extern struct X4_EngineObj D_800CCED0;
extern s32 D_800E2600;
extern s32 D_800E2604;

void func_8001731C(void) {
    u8 i;
    u8* p;

    for (i = 0; i < 6; i++) {
        if (D_80090D64[i] != -1) {
            SsSepClose(D_80090D64[i]);
            D_80090D64[i] = -1;
        }
    }
    {
        struct X4_EngineObj* e = &D_800CCED0;
        p = &D_8006E35C[*(s8*)&e->controlled_player];
    }
    func_8001642C(*p, &D_800E2600, p);
    func_80016178();
    D_80090D64[0] =
        SsSepOpen((u8*)&D_800E2600 + D_800E2600, D_80090D50[0], 8);
    for (i = 0; i < 8; i++) {
        SsSepSetVol(D_80090D64[0], i, 0x7F, 0x7F);
    }
    D_80090D64[1] =
        SsSepOpen((u8*)&D_800E2604 - 4 + D_800E2604, D_80090D50[1], 2);
    for (i = 0; i < 2; i++) {
        SsSepSetVol(D_80090D64[1], i, 0x7F, 0x7F);
    }
}
