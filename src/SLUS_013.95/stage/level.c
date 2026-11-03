#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_8002B2F8(s32);
extern s8 D_80090D56;
#include "mmx6/projectile.h"
extern s8 D_800950A0[];
#define M2C_UNK s32
extern M2C_UNK g_Player;
extern s8 D_8009742C;
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

// 0x8002B838 reset_level: generic reset at level start.
// basis: community tweaks-index.tsv:371
// callers: func_8001D0E4, func_8001D218, func_8001D2CC, func_8001D460 and others
void reset_level(void) {
    s8 z = 0;
    s8* q;
    s32 k;
    u32 i;
    u32 j;

    {
        s8 z1 = 0;
        CLRV(&g_Player, 0x154, z1);
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
            CLRV(&g_enemies[i5 * 0x9C], 0x9C, z5);
        }
        for (i5 = 0; i5 < 0x20; i5++) {
            CLRV(&g_projectiles[i5], 0xA0, z5);
        }
    }
    for (j = 0; j < 0x60; j++) {
        CLR(&D_80091298[j * 0x70], 0x70);
    }
    for (j = 0; j < 0x60; j++) {
        CLR(&g_class3_slots[j], 0x30);
    }
    for (j = 0; j < 0x50; j++) {
        CLR((u8*)g_class4_slots + j * 0xA4, 0xA4);
    }
    for (j = 0; j < 0x60; j++) {
        CLR(&g_displayed_sprites[j], 0x60);
    }
    for (j = 0; j < 0x20; j++) {
        CLR(&D_800964A0[j * 0x60], 0x60);
    }
    for (j = 0; j < 4; j++) {
        CLR(&g_class7_slots[j], 0x30);
    }
    for (j = 0; j < 0x40; j++) {
        CLR(&g_class6_slots[j * 0x60], 0x60);
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
