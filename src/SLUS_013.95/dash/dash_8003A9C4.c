// prog SLUS_013.95 | system dash | range 0x8003A9C4-0x8003AACC
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);
extern u8 D_80073CE4[];

// 0x8003A9C4 start_dash: enters the ground dash (action 12, dash_timer 30 or 15), or a dash jump (action 6) on a jump press.
// basis: code via=dash_timer; derived.tsv:103
// callers: player_check_dash_jump_walk
void start_dash(struct X4_PlayerObj* self) {
    s8 state;

    self->dash_momentum = 1;
    self->air_action = 1;
    if (self->pressed_input & 0x80) {
        s32 temp = M2C_FIELD(self, s32*, 0xF8);
        self->air_state = 1;
        {
            // !FAKE: depin: dropping it breaks the match (63/67)
            register s32 one asm("$3") = 1;
            self->afterimage = one;
        }
        self->air_action = 2;
        M2C_FIELD(self, s32*, 0x20) = 0;
        M2C_FIELD(self, s32*, 0x28) = 0;
        M2C_FIELD(self, s8*, 0x8B) = 0xA;
        M2C_FIELD(self, s32*, 0x24) = temp;
        M2C_FIELD(self, s32*, 0x2C) = M2C_FIELD(self, s32*, 0x134);
        ((void (*)())player_set_animation_shooting)(self, 0xA, temp);
        if (random_byte() & 4) {
            play_sound_unless_low_health(
                self,
                D_80073CE4[(random_byte() & 3) + M2C_FIELD(self, s8*, 2) * 4]);
        }
        set_air_x_velocity(self);
        state = 6;
    } else {
        player_set_animation_shooting(self, 0x10);
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x2C) = 0;
        M2C_FIELD(self, s32*, 0x28) = M2C_FIELD(self, s32*, 0x10C);
        if (M2C_FIELD(self, s32*, 0xEC) & 0x10) {
            self->dash_timer = 0xF;
        } else {
            self->dash_timer = 0x1E;
        }
        state = 0xC;
    }
    M2C_FIELD(self, s8*, 5) = state;
    do {
    } while (0);
    M2C_FIELD(self, s8*, 6) = 0;
}
