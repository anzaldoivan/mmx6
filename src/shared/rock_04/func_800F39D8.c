#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
extern struct X4_PlayerObj g_Player;

void func_800F39D8(void* arg0) {
    struct X4_PlayerObj* player;
    s32 t;

    ((void (*)(void*, s32))func_800179A4)(arg0, 0xB);
    player = &g_Player;
    F(arg0, s16*, 0x7C) = 0x5A;
    t = player->x_pos.u.hi;
    F(arg0, u16*, 0x84) = t;
    t = player->y_pos.u.hi;
    F(arg0, u8*, 6) += 1;
    F(arg0, u16*, 0x86) = t;
}
