// prog SLUS_013.95 | system weapon | range 0x8003EEE4-0x8003EFFC
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#include "mmx6/sound.h"
#include "mmx6/weapon.h"

// 0x8003EEE4 charge_special_weapon: charging special weapons by armor.
// basis: community tweaks-index.tsv:207
// callers: update_player_charge
void charge_special_weapon(void* self) {
    struct X4_PlayerObj* arg0 = self;
    // !FAKE: depin: dropping it breaks the match (62/71)
    register s16* hp asm("$16");
    s32 n;
    // !FAKE: depin: dropping it breaks the match (60/71)
    register u32 b asm("$6");
    u32 x;
    s32 c;
    s32 m;
    u8 k;

    if (arg0->weapon == 0) {
        arg0->charge_state[0] = 0;
        return;
    }
    if (!(arg0->input.buttons.held & 0x10)) {
        return;
    }
    if (arg0->charge_state[0] == 2) {
        return;
    }
    k = arg0->armor;
    if (k != 1 && k != 4) {
        x = 0x5A;
        if (k != 3) {
            return;
        }
    }
    hp = (s16*)arg0->weapon_energy;
    hp += arg0->weapon;
    if (get_weapon_energy_cost(arg0, (s8)(9 + *(u8*)&arg0->weapon)) > *hp) {
        return;
    }
    b = x;
    c = arg0->charge_timer + 1;
    arg0->charge_timer = c;
    n = 0x19;
    do {
    } while (0);
    if (arg0->equipped_parts & 0x100000) {
        b >>= 1;
        n = 0xC;
    }
    m = c & 0xFF;
    if (m == n) {
        play_sound(1, 7, arg0);
        arg0->charge_state[0] = 1;
        return;
    }
    if (m == b) {
        arg0->charge_state[0] = 2;
    }
}
