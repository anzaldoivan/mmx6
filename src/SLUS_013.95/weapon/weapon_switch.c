// prog SLUS_013.95 | system weapon | range 0x8003F048-0x8003F0B8
#include "common.h"

#define M2C_UNK s32
#include "mmx6/x4.h"

#include "mmx6/weapon.h"

// 0x8003F048 update_weapon_switch: runs switch_weapon when requested, else steps the weapon selection and reacts when the weapon byte 0x93 changed.
// basis: xref derived.tsv:22; xref:caller=switch_weapon
// callers: update_player
void update_weapon_switch(void* self) {
    struct X4_PlayerObj* arg0 = self;
    s8 temp_s0;

    if (arg0->character != 0) {
        switch_weapon(arg0);
        return;
    }
    temp_s0 = arg0->weapon;
    func_8003DD6C(arg0);
    set_shot_types(arg0);
    {
        // !FAKE: retail reads the re-loaded byte into the first return register
        register s32 cur asm("$2") = arg0->weapon;
        if (temp_s0 != cur) {
            react_to_weapon_change(arg0);
        }
    }
}
