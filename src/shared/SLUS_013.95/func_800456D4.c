#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
extern u8 D_80076194[][2];
extern void (*D_800761A8[])();
extern struct X4_PlayerObj g_Player;

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800456D4(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s8 idx;

    if (arg0->unk2 != 0 && arg0->id == 7) {
        player = &g_Player;
        if (player->unk15 != 0) {
            arg0->x_pos.i.hi =
                player->x_pos.i.hi - (s8)D_80076194[arg0->unk2 - 1][0];
        } else {
            arg0->x_pos.i.hi =
                player->x_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][0];
        }
        idx = arg0->unk2;
        arg0->y_pos.i.hi = player->y_pos.i.hi + (s8)D_80076194[idx - 1][1];
        if (F_S8(arg0->owner, 0x8D) != 0) {
            if (idx < 3) {
                ((void (*)(void*, s32))func_800179A4)(arg0, 4);
            } else {
                ((void (*)(void*, s32))func_800179A4)(arg0, 5);
            }
            arg0->unk50 = 0;
            arg0->state = 2;
            return;
        }
    }
    D_800761A8[arg0->unk5](arg0);
}
