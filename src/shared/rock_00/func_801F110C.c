#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3A18;
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_801EE34C(struct X4_WeaponObj* arg0, struct X4_PlayerObj* arg1,
                  s32 arg2);

void func_801F110C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;

    if (player->unk6 == 2) {
        play_sound(1, 0x23, arg0);
        arg0->x_vel.val = 0x80000;
        arg0->y_vel.val = 0x40000;
        arg0->unk2C = 0x4000;
        if (player->unk15 == 0) {
            arg0->x_vel.val = 0xFFF80000;
        }
        arg0->unk50 = &D_801F3A18;
        arg0->unk5++;
    }
    func_801EE34C(arg0, player, arg0->id);
}
#undef g_Player
