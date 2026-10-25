#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80073738[];
extern u8 D_80091298[];
extern s8 D_800950A0[];
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_8002B6B0(void) {
    u32 i;
    s8* p;
    s8* q;
    s32 n;
    s8 z;

    z = 0;

    for (i = 0; i < 0x20; i++) {
        p = &D_800950A0[i * 0xA0];
        if (p[0] == 0 || p[1] != 0x37) {
            q = p;
            n = 0x9F;
            do {
                *q++ = z;
            } while (n--);
        }
    }
    for (i = 0; i < 0x60; i++) {
        p = (s8*)&D_80091298[i * 0x70];
        if (p[0] != 0 && D_80073738[p[1]] != 0) {
            q = p;
            n = 0x6F;
            do {
                *q++ = z;
            } while (n--);
        }
    }
    g_Player.special_shot_count = 0;
    g_Player.shot_count = 0;
    g_Player.stock_charge = 0;
}
#undef g_Player
