#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
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
        ang = ratan2(F(s16, 0xE) - py, px - F(s16, 0xA));
        v = rcos(ang) * 16;
        F(s32, 0x20) = v * 5;
        v = rsin(ang) * 16;
        F(s32, 0x24) = v * 5;
        F(u8, 0x6)++;
    }
}
