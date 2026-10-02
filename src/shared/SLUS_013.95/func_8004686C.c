/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_61_ride_armor_punch.c:ride_armor_punch_init, AGPL-3.0; proven shared with X6 by exact signature ef5dce611697 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_8004672C(struct X4_WeaponObj*);

void func_8004686C(struct X4_WeaponObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 0;
    arg0->bg_offset = 0;
    arg0->unk68 = NULL;
    arg0->unk54 = 0;
    arg0->unk50 = 0;
    arg0->unk64 = 1;
    arg0->unk5C = 1;
    arg0->unk60 = 3;
    arg0->unk88.half = 6;
    func_8004672C(arg0);
}
