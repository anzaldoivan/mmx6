#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
extern u8 D_80076194[][2];
extern struct X4_PlayerObj g_Player;

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800461E0(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;

    player = &g_Player;
    if (player->unk15 != 0) {
        arg0->x_pos.i.hi =
            player->x_pos.i.hi - (s8)D_80076194[arg0->unk2 - 1][0];
    } else {
        arg0->x_pos.i.hi =
            player->x_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][0];
    }
    arg0->y_pos.i.hi = player->y_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][1];
    ((void (*)())func_80017A04)(arg0);
    if (F_S8(arg0, 0x46) == 0) {
        arg0->on_screen = 0;
        arg0->state = 3;
    }
}
