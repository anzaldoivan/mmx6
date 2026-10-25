#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_801EE34C(struct X4_WeaponObj* arg0, struct X4_PlayerObj* arg1,
                  s32 arg2);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_801F10A4(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;

    func_80017A04((struct X4_AnimatedObj*)arg0);
    if (arg0->animation_step.fields.relative_step == 0) {
        player->unk7 = 1;
        arg0->unk5++;
    }
    func_801EE34C(arg0, player, arg0->id);
}
#undef g_Player
