#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003D308(M2C_UNK, u8);
extern struct X4_PlayerObj g_Player;
extern s16 D_8009721E;

void func_800EBE94(struct X4_MainObj* arg0) {
    if (g_Player.x_pos.i.hi >= 0x17F1) {
        D_8009721E = 0x17C0;
        func_8003D308(0x14, g_Player.unk15);
        arg0->unk6++;
    }
}
