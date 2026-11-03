// prog SLUS_013.95 | system movement | range 0x8003AED4-0x8003B050
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

// 0x8003AED4 func_8003AED4: enters walking (action 4) with y speed, x acceleration and gravity cleared.
// basis: none
// callers: update_walk_start, player_check_dash_jump_walk
M2C_UNK func_8003AED4(void* arg0) {
    u8* p = arg0;

    player_set_animation_shooting(arg0, 8);
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    move_by_velocity(p);
    p[5] = 4;
    p[6] = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);
extern u8 D_80073CE4[];

M2C_UNK start_jump(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0xF8);
    M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x134);
    if (M2C_FIELD(arg0, s8*, 0x84) != 0 ||
        (M2C_FIELD(arg0, u16*, 0x7C) & 0x100)) {
        M2C_FIELD(arg0, s8*, 0x84) = 1;
        M2C_FIELD(arg0, s8*, 0x86) = 2;
        M2C_FIELD(arg0, s8*, 0x8C) = 1;
    }
    M2C_FIELD(arg0, s8*, 0x8B) = 0xA;
    player_set_animation_shooting(arg0, 0xA);
    if (random_byte() & 4) {
        play_sound_unless_low_health(
            arg0,
            D_80073CE4[(random_byte() & 3) + M2C_FIELD(arg0, s8*, 2) * 4]);
    }
    set_air_x_velocity(arg0);
    M2C_FIELD(arg0, s8*, 5) = 6;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

M2C_UNK func_8003AFF4(s32 arg0) {
    u8* p = (u8*)arg0;

    player_set_animation_shooting((struct X4_PlayerObj*)p, 0xB);
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s8*)(p + 0x67) = -1;
    *(s32*)(p + 0x2C) = *(s32*)(p + 0x100);
    if (*(s8*)(p + 0x84) != 0) {
        *(s8*)(p + 0x84) = 0;
        *(s8*)(p + 0x8C) = -1;
    }
    p[5] = 7;
    p[6] = 0;
}
