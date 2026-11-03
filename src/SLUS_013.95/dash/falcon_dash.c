// prog SLUS_013.95 | system dash | range 0x8003F28C-0x8003F328
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/dash.h"
#include "mmx6/effect.h"
#include "mmx6/movement.h"
#include "mmx6/sound.h"
#include "mmx6/weapon.h"

// 0x8003F28C start_falcon_dash: Falcon dash start.
// basis: community tweaks-index.tsv:246
// callers: select_air_dash
s32 start_falcon_dash(void* arg0) {
    struct X4_PlayerObj* p = arg0;
    s32 r;

    if (!(p->pressed_input & 0x80) && ((s32(*)())check_dash_input)() == 0) {
        r = 0;
    } else {
        func_8003B298(p);
        p->y_vel.val = 0;
        play_sound(1, 5, p);
        p->action = 0x23;
        player_set_animation(p, 0xA9);
        player_spawn_weapon(1, 0x17, 0, p);
        player_spawn_visual(1, 0x12, 0, 0);
        r = 1;
    }
    return r;
}
