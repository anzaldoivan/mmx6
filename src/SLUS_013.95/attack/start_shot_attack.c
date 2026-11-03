// prog SLUS_013.95 | system attack | range 0x8003F644-0x8003F6FC
#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK player_set_animation(void*, M2C_UNK);
s32 check_giga_attack(void* self);
void try_fire_shot(void* arg0);
M2C_UNK start_player_attack(void*, M2C_UNK);

// 0x8003F644 try_start_shot_attack: X only: tries a giga attack, else starts the attack of a fired shot type; returns 1 when one starts.
// basis: xref derived.tsv:138; xref:caller=start_player_attack
// callers: func_80035D38
s32 try_start_shot_attack(void* arg0) {
    s8* p = arg0;
    s8 idx;

    if (p[0xD3] != 0) {
        return 0;
    }
    if (p[2] != 0) {
        return 0;
    }
    if (check_giga_attack(arg0) != 0) {
        return 1;
    }
    try_fire_shot(arg0);
    if (p[0x8F] == 0) {
        return 0;
    }
    idx = p[0x96];
    if (D_80073E00[idx] == 0) {
        return 0;
    }
    p[0x8C] = 0;
    if (idx == 5 || idx == 14) {
        player_set_animation(arg0, 0x6C);
    }
    start_player_attack(arg0, 0);
    return 1;
}
