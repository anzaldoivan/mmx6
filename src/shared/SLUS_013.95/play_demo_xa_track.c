#include "common.h"
#include "psyq/libsnd.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

s32 func_80016548(s32 arg0, s32* arg1);
void func_800187A0(s32 arg0);
void func_800646E4(s32, u8*);
extern s32 D_8006E76C[][4];
extern s8 D_800CD40C;
extern M2C_UNK D_800E2E04;
extern s32 D_800E2E20;
extern s32 D_800E2E28;
extern u32 D_800E2E2C;
extern s8 D_800E2E50;
extern M2C_UNK D_800E2E64;

void play_demo_xa_track(s16 arg0, s32 arg1) {
    s32* p;
    s32 i;
    s32 t;

    i = arg0 & 0xFFFF;
    ((u8*)&D_800E2E64)[0] = 1;
    D_800E2E28 = D_8006E76C[i][0];
    p = (s32*)((u8*)D_8006E76C - -(i << 4));
    D_800E2E2C = D_8006E76C[i][1];
    D_800E2E50 = ((u8*)p)[0xC];
    t = D_8006E76C[i][2];
    ((u8*)&D_800E2E64)[1] = t;
    D_800E2E28 += func_80016548(0xF6, &D_800E2E20);
    D_800E2E2C += func_80016548(0xF6, &D_800E2E20);
    func_800646E4(D_800E2E28, (u8*)&D_800E2E04);
    SsSetSerialAttr(0, 0, 1);
    {
        s32 k = 0x73;
        D_800E2E14 = k;
    }
    func_800187A0(0x73);
    D_800E2E5C = 2;
    D_800CD40C = 1;
    D_800E2E18 = 7;
}
