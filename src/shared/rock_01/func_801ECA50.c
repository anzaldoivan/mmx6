#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);
void attack_hyoroga_from_ceiling(u8* arg0);
s32 func_801ECCD4(void*);

s32 func_801ECA50(u8* p) {
    if (get_weapon_energy_cost(p, 1) <= *(s16*)(p + 0xAA)) {
        if (func_801ECCD4(p) != 0) {
            func_8003BA04(p, 0x64);
            play_sound(1, 0x14, p);
            p[0x84] = 0;
            p[0x86] = 0;
            p[0x93] = 1;
            use_weapon_energy(p, 1);
            p[5] = 0x3F;
            p[6] = 0;
            attack_hyoroga_from_ceiling(p);
            return 1;
        }
        return 0;
    }
    return 0;
}
