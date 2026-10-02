/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_01_lightning_web.c:lightning_web_release, AGPL-3.0; proven shared with X6 by exact signature 9736cfd16dd5 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_8003B114(s32);
void func_80017A04(struct X4_AnimatedObj*);

void func_801ECD24(struct X4_WeaponObj* arg0) {
    func_80017A04(ANIMATED_OBJECT(arg0));
    if (arg0->animation_step.fields.relative_step == 0) {
        func_8003B114(arg0);
    }
}
