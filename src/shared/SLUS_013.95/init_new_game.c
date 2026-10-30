#include "common.h"

extern u8 g_temp_options;
extern u8 default_options;
extern u8 D_8006D5FC[];
extern s32 D_8006D634[];
extern s32 D_80097420;
extern s32 D_800E3130[];

// 0x8001E088 init_new_game: new game status init.
// basis: community tweaks-index.tsv:302
// callers: none known
void init_new_game(u8* arg0) {
    s32* p;
    s32 i;
    u8* g;
    s32 a;
    s32 b;

    i = 0;
    arg0[0x39] = 2;
    arg0[0x5B] = 0x20;
    arg0[0x5C] = 0x20;
    arg0[0x61] = 0x30;
    arg0[0x62] = 0x30;
    arg0[0x8D] = 7;
    arg0[0x8E] = 7;
    *(s32*)(arg0 + 0xCC) = 0;
    arg0[0xC9] = g_temp_options;
    a = default_options;
    arg0[0] = 1;
    arg0[0x68] = a;
    arg0[0xD0] = D_8006D5FC[0];
    b = D_8006D5FC[2];
    *(s16*)(arg0 + 0xD2) = 0;
    *(s16*)(arg0 + 0xD4) = 0;
    arg0[0x438] = 0;
    arg0[0xD1] = b;
    do {
        u8* q = arg0 + 0x168;
        ((s32*)(arg0 + 0xD8))[i] = D_8006D634[i];
        q[i] = 0;
        i++;
    } while (i < 0x10);
    g = (u8*)&D_80097420;
    g[8] = 0;
    {
        s32 c = 0x8CA0;
        p = (s32*)(arg0 + 0x440);
        i = 7;
        do {
            *p++ = c;
            i--;
        } while (i >= 0);
    }
    {
        s32 one;
        i = 9;
        one = 1;
        arg0[0x5F] = one;
        arg0[0x5E] = one;
        if (D_800E3130[0] == 4) {
            arg0[0x5F] = i;
            arg0[0x5E] = 4;
        }
        if (D_800E3130[1] == 4) {
            arg0[0x5F] |= 0x20;
        }
    }
    arg0[0] = 0x13;
    arg0[0x1D] = 0;
}
