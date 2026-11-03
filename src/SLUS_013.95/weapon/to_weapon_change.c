// prog SLUS_013.95 | system weapon | range 0x8003F0BC-0x8003F138
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void player_load_weapon_palette(struct X4_PlayerObj* self);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);

M2C_UNK react_to_weapon_change(void* arg0) {
    s8 v;

    player_load_weapon_palette(arg0);
    v = ((s8*)arg0)[0x93];
    if (v == 1) {
        player_spawn_visual(1, 0x1B, 0, 0);
    } else if (v == 6) {
        player_spawn_visual(1, 0x1B, 0xA, 0);
    } else if (v == 8) {
        player_spawn_visual(1, 0x1B, 0xC, 0);
    }
}
