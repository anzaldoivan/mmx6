#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

// 0x8003EB0C get_weapon_energy_cost: energy cost by armor and parts.
// basis: community tweaks-index.tsv:208
// callers: func_800246B4, func_800249D4, update_player_damage, func_8003FA00 and others
s32 get_weapon_energy_cost(void* self, s32 arg1) {
    struct X4_PlayerObj* arg0 = self;
    s8 idx = arg1;
    s16 v;

    if (arg0->character != 0) {
        if (arg0->equipped_parts & 0x20) {
            return (s16)(D_80073DF4[idx] * 3);
        }
        if (D_800CCF2F & 0x20) {
            return (s16)(D_80073DF4[idx] * 4);
        }
        return (s16)(D_80073DF4[idx] * 6);
    }
    v = D_80073D74[idx] * 6;
    if (v == 0) {
        return 0;
    }
    if (arg0->equipped_parts & 0x20) {
        v = v / 2;
    } else {
        switch (arg0->armor) {
        case 1:
        case 3:
        case 4:
            v = (v * 2) / 3;
            break;
        }
    }
    if (v == 0) {
        v = 1;
    }
    return v;
}
