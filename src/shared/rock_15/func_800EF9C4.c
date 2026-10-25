#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj g_Player;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EF9C4(void* arg0) {
    s32 ang;
    s32 v;
    s32 px;
    s32 py;

    if (--F(s16, 0x88) == 0) {
        func_80016C48(2, 0x84, arg0);
        px = g_Player.x_pos.i.hi;
        py = g_Player.y_pos.i.hi;
        ang = func_80065B74(F(s16, 0xE) - py, px - F(s16, 0xA));
        v = func_80065A14(ang) * 16;
        F(s32, 0x20) = v * 5;
        v = func_80065944(ang) * 16;
        F(s32, 0x24) = v * 5;
        F(u8, 0x6)++;
    }
}
