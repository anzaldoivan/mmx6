/* Adapted from sozud/mmx4 @807a01b src/main/weapons/weapon_02_frost_tower.c:frost_tower_despawn, AGPL-3.0; proven shared with X6 by exact signature d5fdc58f219e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

M2C_UNK func_8002C9B0(void*);
void func_801F0814(struct X4_WeaponObj* arg0) {
    arg0->unk50 = 0;
    arg0->unk68 = 0;
    g_Player.shot_count--;
    g_Player.special_shot_count--;
    func_8002C9B0(OBJECT_HEADER(arg0));
}
#undef g_Player
