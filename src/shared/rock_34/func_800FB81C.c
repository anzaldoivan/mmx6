#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80016C48(s32, s32, void*);
extern struct X4_PlayerObj D_800970A0;
#define g_Player D_800970A0
extern s16 D_800970AA;
extern s32 D_800FED98;
extern s32 D_800FED9C;
extern s32 D_800FEDA0;
#define rsin func_80065944
#define rcos func_80065A14
#define ratan2 func_80065B74
int rsin(int);
int rcos(int);
long ratan2(long, long);

void func_800FB81C(void* arg0) {
    s32 ang;
    s32 num;
    s32 den;
    s32 dx;
    s32 v;
    s32 t;
    s32 den2;
    s8 type;

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x5) == 3) {
        M2C_FIELD(arg0, s8*, 0x4) = 2;
        M2C_FIELD(arg0, s8*, 0x5) = 0;
        M2C_FIELD(arg0, s8*, 0x3) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        func_80016C48(2, 0x16, arg0);
        M2C_FIELD(arg0, void**, 0x54) = &D_800FED98;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FED9C;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FEDA0;
        type = M2C_FIELD(arg0, s8*, 0x2);
        if (type == 0) {
            dx = D_800970AA - M2C_FIELD(arg0, s16*, 0xA);
            num = 0x600000;
            den = 264;
            M2C_FIELD(arg0, s32*, 0x2C) = num / den;
            M2C_FIELD(arg0, s32*, 0x24) = 0x85D11;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            dx <<= 16;
            den2 = 46;
            M2C_FIELD(arg0, s32*, 0x20) = dx / den2;
        } else if (type == 1) {
            s32 px;
            s32 py;
            struct X4_PlayerObj* p = &g_Player;
            px = p->x_pos.i.hi;
            py = p->y_pos.i.hi;
            ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                         px - M2C_FIELD(arg0, s16*, 0xA));
            M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 6;
            M2C_FIELD(arg0, s32*, 0x24) = rsin(ang) << 6;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
        } else if (type == 2) {
            s32 px;
            s32 py;
            struct X4_PlayerObj* p = &g_Player;
            px = p->x_pos.i.hi;
            py = p->y_pos.i.hi;
            ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                         px - M2C_FIELD(arg0, s16*, 0xA));
            v = rcos(ang);
            M2C_FIELD(arg0, s32*, 0x20) = -(v << 4) + (v << 7);
            v = rsin(ang);
            t = v << 4;
            M2C_FIELD(arg0, s32*, 0x24) = (v << 7) - t;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
