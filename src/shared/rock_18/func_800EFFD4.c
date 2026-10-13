#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define F_U8(o) M2C_FIELD(arg0, u8*, (o))
#define F_S8(o) M2C_FIELD(arg0, s8*, (o))
#define F_S16(o) M2C_FIELD(arg0, s16*, (o))
#define F(p, t, o) (*(t*)((u8*)(p) + (o)))

extern s16 D_800F1150[][5];

void func_800EFFD4(void* arg0) {
    s16 x;
    s16 y;
    s16 w;
    s32 off;
    s32 c;
    s32 r;
    s32 b;
    s16 h;
    u16 f;

    F_U8(0x36) = 7;
    F_U8(0) = 0x11;
    F_U8(3) = 0;
    F_S8(0x37) = -1;
    F_S16(0xA) = 0;
    F_S16(0xE) = 0;
    off = F_S8(2);
    x = D_800F1150[off][0];
    y = D_800F1150[off][1];
    w = D_800F1150[off][2];
    h = D_800F1150[off][3];
    c = F_U8(4);
    f = (u16)D_800F1150[off][4];
    F_U8(5) = 0;
    F_U8(6) = 0;
    F_U8(4) = c + 1;
    r = x + w;
    F_S16(0x1A) = y;
    F_S16(0x22) = y;
    b = y + h;
    F_S16(0x34) = f;
    F_S16(0x16) = x;
    F_S16(0x1E) = r;
    F_S16(0x26) = r;
    F_S16(0x2A) = b;
    F_S16(0x2E) = x;
    F_S16(0x32) = b;
}
