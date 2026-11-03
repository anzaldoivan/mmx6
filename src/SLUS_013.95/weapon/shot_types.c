// prog SLUS_013.95 | system weapon | range 0x8003DF58-0x8003E068
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
void func_8003F7BC(void* arg0, M2C_UNK arg1, M2C_UNK arg2);

// 0x8003DF58 set_shot_types: sets the two shot types from armor, weapon, charge and parts.
// basis: code via=shot_types; derived.tsv:130
// callers: update_weapon_switch, check_giga_attack, refresh_weapon_state
// unnamed callers: func_80034CD0, func_8003F000
M2C_UNK set_shot_types(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    u8 t;
    // !FAKE: depin: dropping it breaks the match (62/69)
    register s32 k asm("$6");

    t = self->armor;
    k = 2;
    if (t == k) {
        if (self->timed_item == 6 && self->action != 0x1F) {
            func_8003F7BC(self, 1, k);
            return;
        }
        self->shot_types[0] = 0x32;
        self->shot_types[1] = 0x2D;
        if (self->charge_state[1] == 2 || (self->equipped_parts & 0x80000)) {
            self->shot_types[1] = 0x2E;
        }
    } else {
        self->shot_types[0] = *(u8*)&self->weapon;
        if (self->shot_types[0] != 0) {
            if (self->charge_state[0] == k) {
                *(u8*)&self->shot_types[0] += 9;
            } else if ((self->equipped_parts & 0x80000) &&
                       (t == 1 || t == 4 || t == 3)) {
                *(u8*)&self->shot_types[0] += 9;
            }
        } else {
            self->shot_types[0] = 0x32;
        }
        self->shot_types[1] = 0;
        func_8003F7BC(self, 1, k);
    }
}
