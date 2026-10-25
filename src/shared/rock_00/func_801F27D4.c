#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_801EE34C();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3AAC;
extern s32 D_801F3AB4;

void func_801F27D4(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;

    player = &g_Player;
    if (arg0->unk6 != 0) {
        goto set;
    }
    switch (player->unk5) {
    case 9:
    case 10:
    case 11:
    case 14:
    case 15:
    case 16:
    case 27:
    case 28:
    case 32:
        arg0->unk6 = 1;
        *(s16*)((u8*)arg0 + 0x8C) = arg0->y_pos.i.hi - player->y_pos.i.hi;
        break;
    }
    if (arg0->unk6 != 0) {
    set:
        arg0->y_pos.i.hi = g_Player.y_pos.i.hi + *(s16*)((u8*)arg0 + 0x8C);
    } else {
        func_801EE34C(arg0, player, arg0->id);
    }
    func_80017A04((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[0x45] & 0x80) {
        arg0->unk50 = &D_801F3AAC;
        arg0->unk68 = (struct X4_Unk_unk68*)&D_801F3AB4;
        if (arg0->unk15 == 0) {
            arg0->x_vel.val = -arg0->x_vel.val;
        }
        arg0->unk5++;
    }
}
#undef g_Player
