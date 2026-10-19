#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

M2C_UNK func_8002C9B0(void*);
void func_801F29B8(struct X4_WeaponObj* arg0) {
    struct X4_WeaponObj* owner;

    if (arg0->unk2 == 0) {
        if (arg0->unk7 != 0) {
            return;
        }
        D_800970A0.special_shot_count--;
        D_800970A0.shot_count--;
    } else {
        owner = (struct X4_WeaponObj*)arg0->owner;
        if (owner->unk7 != 0) {
            owner->unk7--;
        }
    }
    ((void (*)())func_8002C9B0)(OBJECT_HEADER(arg0));
}
#undef D_800970A0
