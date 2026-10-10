#include "common.h"
#include "mmx6/x4.h"

#define F(p, t, o) (*(t*)((u8*)(p) + (o)))

extern struct X4_PlayerObj D_800970A0;
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
    if (c == F(p, u8, 8) && D_800970A0.x_pos.i.hi >= F(p, s16, 0) &&
        F(D_800F7900 + off, s16, 4) >= D_800970A0.x_pos.i.hi &&
        D_800970A0.y_pos.i.hi >= F(D_800F7900 + off, s16, 2) &&
        F(D_800F7900 + off, s16, 6) >= D_800970A0.y_pos.i.hi) {
        return 1;
    }
    return 0;
}
