#include "common.h"
#include "mmx6/x4.h"

#define F(p, t, o) (*(t*)((u8*)(p) + (o)))

extern struct X4_PlayerObj g_Player;
extern s8 D_800CCEDC;
extern u8 D_800F7900[];

s32 func_800EF4D4(u32 arg0) {
    s32 off;
    u8* p;
    u8* b;
    s32 c;

    arg0 &= 0xFFFF;
    c = D_800CCEDC;
    b = D_800F7900;
    off = arg0 * 10;
    p = off + b;
    if (c == F(p, u8, 8) && g_Player.x_pos.i.hi >= F(p, s16, 0) &&
        F(D_800F7900 + off, s16, 4) >= g_Player.x_pos.i.hi &&
        g_Player.y_pos.i.hi >= F(D_800F7900 + off, s16, 2) &&
        F(D_800F7900 + off, s16, 6) >= g_Player.y_pos.i.hi) {
        return 1;
    }
    return 0;
}
