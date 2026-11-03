#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK player_set_animation(void*, M2C_UNK);
void player_load_weapon_palette(struct X4_PlayerObj* self);
M2C_UNK player_clear_dash();
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);
M2C_UNK update_rekkoha();

// 0x801EA680 start_rekkoha: Rekkoha input (Zero).
// basis: community tweaks-index.tsv:226
// callers: func_801EAE7C, func_801EBC60, try_start_rekkoha
s32 start_rekkoha(u8* arg0) {
    if (*(s8*)(arg0 + 0xD3) == 0 && (arg0[0xC9] & 0x80)) {
        s32 t;
        if (!(*(u16*)(arg0 + 0x80) & 0x40)) {
            return 0;
        }
        t = get_weapon_energy_cost(arg0, 5);
        if (*(s16*)(arg0 + 0xB2) < t) {
            return 0;
        }
        if (*(s8*)(arg0 + 0x8E) == 0) {
            arg0[0x93] = 5;
            arg0[0xDD] = 1;
            arg0[0x8E] = 1;
            arg0[0xCB] = 0;
            arg0[0x8C] = 0;
            player_clear_dash(arg0);
            player_set_animation(arg0, 0x68);
            play_sound_unless_low_health(arg0, 7);
            arg0[0x61] = 0;
            arg0[0xA4] = 0;
            player_load_weapon_palette((struct X4_PlayerObj*)arg0);
            arg0[0xE0] = 2;
            arg0[0xE1] = 0;
            *(s32*)(arg0 + 0x68) = 0;
            arg0[0x67] = 1;
            arg0[0x7A] = 1;
            D_800CCEEC = 1;
            use_weapon_energy(arg0, *(s8*)(arg0 + 0x93));
            arg0[5] = 0x3B;
            arg0[6] = 0;
            arg0[7] = 0;
            update_rekkoha(arg0);
            return 1;
        }
    }
    return 0;
}
