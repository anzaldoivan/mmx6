#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_ObjectHeader D_80097420;

#define EA_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define EA_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define EA_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F40FC(void* arg0) {
    struct X4_PlayerObj* p;
    s16 y;
    s16 x;
    s32 ang;
    s32 c;
    s32 t;
    s32 v;

    if (D_800970A0.x_pos.i.hi > EA_S16(arg0, 0xA)) {
        EA_U8(arg0, 0x15) = 0x40;
    } else {
        EA_U8(arg0, 0x15) = 0;
    }
    p = &D_800970A0;
    y = p->y_pos.i.hi + EA_S16(arg0, 0x82);
    x = p->x_pos.i.hi + EA_S16(arg0, 0x80);
    ang = func_80065B74(y - EA_S16(arg0, 0xE), x - EA_S16(arg0, 0xA));
    c = func_80065A14(ang);
    v = c * 16;
    EA_S32(arg0, 0x20) = c * 64 + v;
    c = -func_80065944(ang);
    v = c * 16;
    EA_S32(arg0, 0x24) = c * 64 + v;
    if (((EA_S16(arg0, 0xA) - x >= 0) ? (EA_S16(arg0, 0xA) - x)
                                      : (x - EA_S16(arg0, 0xA))) < 0x10 &&
        ((EA_S16(arg0, 0xE) - y >= 0) ? (EA_S16(arg0, 0xE) - y)
                                      : (y - EA_S16(arg0, 0xE))) < 0x20) {
        EA_S32(arg0, 0x20) = 0;
        EA_S32(arg0, 0x24) = 0;
        if (!(*(u8*)&D_80097420 & 1)) {
            t = (EA_U8(arg0, 0x84) + 1) & 0x3F;
            EA_U8(arg0, 0x84) = t;
            EA_S16(arg0, 0xE) += func_80065944(t << 7) / 2096;
        }
    }
    func_80017A04(arg0);
    func_8002D2B0(arg0);
}
