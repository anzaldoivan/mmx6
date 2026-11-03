// prog SLUS_013.95 | system weapon | range 0x8003FA60-0x8003FA88
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/weapon.h"

// 0x8003FA60 player_fire_weapon: spawns the player's current shot type as a weapon object.
// basis: x4 exact 8c58cd89382c
// callers: none known
void player_fire_weapon(struct PlayerObj* arg0) {
    player_spawn_weapon(1, arg0->shot_type, 0, arg0);
}
