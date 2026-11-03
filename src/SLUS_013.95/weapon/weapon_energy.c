// prog SLUS_013.95 | system weapon | range 0x8003F740-0x8003F7B8
#include "common.h"
#include "mmx6/x4.h"

#include "mmx6/globals.h"
#include "mmx6/weapon.h"
#include "mmx6/pilot_globals.h"

#define PLAYER (*(struct X4_PlayerObj*)&g_Player)

// 0x8003F740 use_weapon_energy: energy deduction on shot.
// basis: community tweaks-index.tsv:209
// callers: init_yammar_option, start_rekkoha, try_hyoroga_from_ceiling, update_guard_shell, try_fire_shot, check_yammar_option_input
// unnamed callers: func_80043890, func_80045810 and others
void use_weapon_energy(void* self, s32 arg1) {
    struct X4_PlayerObj* arg0 = self;
    s8 id = arg1;
    u16* p;
    s32 t;

    if ((PLAYER.timed_item != 3) || (id == 0x2F) || (id == 0x2C) ||
        (id == 0x31)) {
        t = get_weapon_energy_cost(arg0, id);
        p = (u16*)arg0->weapon_energy;
        p += arg0->weapon;
        *p -= t;
    }
}
