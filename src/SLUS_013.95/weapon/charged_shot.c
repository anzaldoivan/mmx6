#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/system.h"
#include "mmx6/effect.h"
#include "mmx6/weapon.h"

// 0x8003FA8C fire_charged_shot: X charged shot sound.
// basis: community tweaks-index.tsv:327
// callers: none known
void fire_charged_shot(struct PlayerObj* arg0) {
    s8 temp_v1;

    player_spawn_visual(0x21, 2, arg0->shot_type, 0);
    temp_v1 = arg0->shot_type;
    if (((temp_v1 == 0x12) || (temp_v1 == 0x14) || (temp_v1 == 0x13)) &&
        (random_byte() & 1)) {
        play_sound_unless_low_health(arg0, 6);
    }
}
