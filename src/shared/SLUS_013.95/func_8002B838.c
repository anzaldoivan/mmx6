#include "common.h"
#include "mmx6/x4.h"

s32 func_8002B2F8(s32);
extern struct X4_AbcObj D_8008EAF0;
extern s8 D_8008EF48[];
extern s8 D_80090D56;
extern u8 D_800911A8[];
extern u8 D_80091298[];
extern u8 D_80093C98[];
extern s8 D_800950A0[];
extern u8 D_800964A0[];
#define M2C_UNK s32
extern M2C_UNK D_800970A0;
extern struct X4_UnkObj D_800972F8[3];
extern s8 D_8009742C;
extern struct X4_EffectObj D_8009B7B0[0x20];
extern u8 D_8009C9B0[];
extern s32 D_800C1220[];
extern struct X4_LayerObj D_800C4778[4];
extern struct X4_RideArmorObj D_800CD340;
extern struct X4_MiscObj D_800CD410[];
extern u8 D_800CF810[];
extern s8 D_800CF850;

#define CLRV(p, n, v)                                                          \
    {                                                                          \
        s8* q = (s8*)(p);                                                      \
        s32 k = (n);                                                           \
        while (k--) {                                                          \
            *q++ = (v);                                                        \
        }                                                                      \
    }
#define CLR(p, n)                                                              \
    {                                                                          \
        q = (s8*)(p);                                                          \
        k = (n);                                                               \
        while (k--) {                                                          \
            *q++ = z;                                                          \
        }                                                                      \
    }

void func_8002B838(void) {
    s8 z = 0;
    s8* q;
    s32 k;
    u32 i;
    u32 j;

    {
        s8 z1 = 0;
        CLRV(&D_800970A0, 0x154, z1);
    }
    for (i = 0; i < 3; i++) {
        CLR(&D_800972F8[i], 0x60);
    }
    for (i = 0; i < 3; i++) {
        CLR(&D_800911A8[i * 0x50], 0x50);
    }
    {
        s8 z4 = 0;
        u32 i4;
        for (i4 = 0; i4 < 0x20; i4++) {
            CLRV(&D_800950A0[i4 * 0xA0], 0xA0, z4);
        }
    }
    {
        s8 z5 = 0;
        u32 i5;
        for (i5 = 0; i5 < 0x30; i5++) {
            CLRV(&D_8008EF48[i5 * 0x9C], 0x9C, z5);
        }
        for (i5 = 0; i5 < 0x20; i5++) {
            CLRV(&D_80093C98[i5 * 0xA0], 0xA0, z5);
        }
    }
    for (j = 0; j < 0x60; j++) {
        CLR(&D_80091298[j * 0x70], 0x70);
    }
    for (j = 0; j < 0x60; j++) {
        CLR(&D_8009B7B0[j], 0x30);
    }
    for (j = 0; j < 0x50; j++) {
        CLR((u8*)D_800C1220 + j * 0xA4, 0xA4);
    }
    for (j = 0; j < 0x60; j++) {
        CLR(&D_800CD410[j], 0x60);
    }
    for (j = 0; j < 0x20; j++) {
        CLR(&D_800964A0[j * 0x60], 0x60);
    }
    for (j = 0; j < 4; j++) {
        CLR(&D_800C4778[j], 0x30);
    }
    for (j = 0; j < 0x40; j++) {
        CLR(&D_8009C9B0[j * 0x60], 0x60);
    }
    CLR(&D_800CD340, 0xB0);
    CLR(D_800CF810, 0x3C);
    func_8002B2F8(0);
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    CLR(&D_8008EAF0, 0x14);
}
#undef CLR
#undef CLRV
