#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

M2C_UNK func_8002C9B0(void*);
void func_801F29B8(struct X4_WeaponObj* arg0) {
    struct X4_WeaponObj* owner;

    if (arg0->unk2 == 0) {
        if (arg0->unk7 != 0) {
            return;
        }
        g_Player.special_shot_count--;
        g_Player.shot_count--;
    } else {
        owner = (struct X4_WeaponObj*)arg0->owner;
        if (owner->unk7 != 0) {
            owner->unk7--;
        }
    }
    ((void (*)())func_8002C9B0)(OBJECT_HEADER(arg0));
}
#undef g_Player
