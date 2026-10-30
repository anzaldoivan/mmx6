#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

M2C_UNK clear_object_slot();
void func_801EECA4(struct X4_WeaponObj* arg0) {
    if (arg0->unk2 == 0) {
        g_Player.shot_count--;
    }
    ((void (*)())clear_object_slot)(arg0);
}
#undef g_Player
