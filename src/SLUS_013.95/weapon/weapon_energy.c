#include "common.h"

s32 get_weapon_energy_cost(void* arg0, s32 arg1);
extern s32 D_800971E4;

// 0x8003F740 use_weapon_energy: energy deduction on shot.
// basis: community tweaks-index.tsv:209
// callers: func_8003E614, func_80043890, func_80045810, func_801EA254 and others
void use_weapon_energy(void* arg0, s32 arg1) {
    s8 id = arg1;
    u16* p;
    s32 t;

    if ((D_800971E4 != 3) || (id == 0x2F) || (id == 0x2C) || (id == 0x31)) {
        t = get_weapon_energy_cost(arg0, id);
        p = (u16*)((u8*)arg0 + 0xA8);
        p += *((s8*)arg0 + 0x93);
        *p -= t;
    }
}
