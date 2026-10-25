#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern s16 D_80097202;

void func_800EDD7C(struct X4_MainObj* arg0) {
    if (D_80097202 >= 0x1240) {
        g_Player.x_pos.i.hi = 0x12E0;
        func_8003D308(0x14, g_Player.unk15);
        arg0->state++;
    }
}
