#include "common.h"
#include "mmx6/x4.h"

s32 func_80065944(s32);
s32 func_80065A14(s32);
extern s32 D_80076124;
extern struct X4_PlayerObj D_800970A0;
extern s32 D_80097420;

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_80043DBC(s8* arg0) {
    u8* parent;
    s32 ang;
    s32 v;
    s32 q;
    struct X4_PlayerObj* pl;

    if (arg0[2] != 0) {
        parent = F_PTR(arg0, 0x7C);
        if (parent[0x8F] != 0) {
            F_S32(arg0, 0x50) = 0;
            F_S32(arg0, 0x68) = 0;
            arg0[4] = 2;
            return;
        }
        if ((u8)(arg0[2] - 1) < 3) {
            if (arg0[5] == 7) {
                if ((u32)D_80097420 % 21 == 0) {
                    F_U8(arg0, 0x64)++;
                }
            } else if (!(D_80097420 & 7)) {
                F_U8(arg0, 0x64)++;
            }
            pl = &D_800970A0;
            F_U8(arg0, 0x15) = pl->unk15;
            {
                register s32 off asm("$2") = (arg0[2] - 1) * 0x555 + 0xE00;
                ang = (F_U16(parent, 0x94) + off) & 0xFFF;
            }
            v = func_80065A14(ang) * F_S16(arg0, 0x88);
            if (v < 0) {
                v += 0xFFF;
            }
            F_S16(arg0, 0xA) = pl->x_pos.i.hi + (v >> 12);
            q = func_80065944(ang) * F_S16(arg0, 0x88);
            v = q >> 12;
            if (q < 0) {
                v = (q + 0xFFF) >> 12;
            }
            F_S16(arg0, 0xE) = pl->y_pos.i.hi + v;
            if (F_U8(arg0, 0x8E) != 0) {
                F_U8(arg0, 0x8E)--;
            }
        }
    }
    ((void (**)(s8*)) & D_80076124)[arg0[5]](arg0);
}
