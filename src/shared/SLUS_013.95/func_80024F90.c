#include "common.h"
#include "mmx6/x4.h"

void func_800253AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, u32 arg5,
                   u32 arg6);
extern s16 D_80071E40[][2];
#define M2C_UNK s32
extern M2C_UNK g_Player;
extern s8 D_800970A2;
extern s32 D_80097420;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCF5C;

#define FB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_80024F90(void* arg0, s32 arg1) {
    s16 x0;
    s16 y;
    // !FAKE: depin: dropping it breaks the match (156/174)
    register s32 lvl asm("$18");
    s32 max;
    s32 f;
    s32 g;

    {
        // !FAKE: depin: dropping it breaks the match (172/174)
        register s32 b asm("$2") = *(u8*)((u8*)arg0 + 0x5C);
        lvl = b & 0x7F;
    }
    if (arg1 == 0) {
        u8* e = (u8*)&g_playthrough_state;
        s32 j = D_800970A2;
        max = *(s8*)(e - -j + 0x5B);
    } else {
        s32 t = D_800CCF5C;
        if (t < 0x20) {
            max = 0x30;
        } else {
            max = t;
        }
    }
    x0 = D_80071E40[arg1][0];
    if (arg1 == 0 && D_800970A2 == 1) {
        x0++;
    }
    f = lvl < 8;
    y = D_80071E40[arg1][1];
    g = f;
    if (arg1 == 0) {
        struct X4_PlayerObj* p = &g_Player;
        if (FB(p, 0xE8) != 0) {
            FB(p, 0xE8)--;
            g = 3;
        }
        if (FB(p, 2) != 0) {
            x0--;
        }
        func_800253AC(x0, x0 + 3, y - lvl, y, g, max, lvl);
    } else {
        func_800253AC(x0, x0 + 3, y + (max - lvl), y + max, f, max, lvl);
    }
    if (lvl != FB(arg0, 0x5D)) {
        if (FB(arg0, 0x5D) < lvl) {
            FB(arg0, 0x5D) = lvl;
            return;
        }
        if (FB(arg0, 0x5C) & 0x80) {
            FB(arg0, 0x5F) = 0x10;
        }
        if (arg1 == 0) {
            do {
                func_800253AC(x0, x0 + 3, y - FB(arg0, 0x5D), y - lvl, 3, 1, 1);
            } while (0);
        } else {
            func_800253AC(x0, x0 + 3, y + (max - FB(arg0, 0x5D)), y - lvl + max,
                          3, 1, 1);
        }
        if (FB(arg0, 0x5F) != 0) {
            FB(arg0, 0x5F)--;
            return;
        }
        if (!(D_80097420 & 3)) {
            FB(arg0, 0x5D)--;
        }
    }
}
