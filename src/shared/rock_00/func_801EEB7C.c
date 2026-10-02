/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_20_plasma_shot.c:buster_shot_follow_muzzle, AGPL-3.0; proven shared with X6 by exact signature 06aa2f0ae247 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_801EEB7C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* owner;

    if (arg0->unk84.word == 0) {
        owner = arg0->owner;
        if (owner->attacking == 0) {
            arg0->unk84.word = 1;
        }
        if (owner->unk15 != arg0->unk15) {
            arg0->unk84.word = 1;
        }
        if (arg0->unk84.word == 0) {
            func_801EE34C(VISUAL_OBJECT(arg0), owner, arg0->id);
        }
    }
}
