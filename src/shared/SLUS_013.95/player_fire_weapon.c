#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* player_spawn_weapon(s8 arg0, s8 arg1, s8 arg2, s32 arg3); /* extern */

void player_fire_weapon(void* arg0) {
    player_spawn_weapon(1, M2C_FIELD(arg0, s8*, 0x96), 0, arg0);
}
