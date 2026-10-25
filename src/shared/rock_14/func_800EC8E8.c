#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
s32 func_800EC430(struct X4_PlayerObj* a, struct X4_PlayerObj* b);
extern struct X4_PlayerObj g_Player;

void func_800EC8E8(struct X4_PlayerObj* arg0) {
    u8 temp_a2;

    if (func_800EC430(arg0, &g_Player) != 0) {
        g_Player.x_pos.i.hi = arg0->x_pos.i.hi;
        temp_a2 = g_Player.unk68->unk3;
        g_Player.y_pos.i.hi = arg0->y_pos.i.hi - temp_a2;
        ((s32(*)(s32, s32, s32))func_8003D308)(0x14, g_Player.unk15, temp_a2);
        arg0->unk6 = arg0->unk6 + 1;
    }
}
