// prog SLUS_013.95 | system damage | range 0x8003963C-0x800397F4
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/damage.h"
#include "mmx6/graphics.h"
#include "mmx6/movement.h"
#include "mmx6/sound.h"
#include "mmx6/system.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x8003963C start_hurt: starts the hurt: vibration, hurt sounds, then unless in action 17, animation, speeds and invincibility from the hurt-type tables and action 17.
// basis: code via=hurt_type; derived.tsv:92
// callers: none known
void start_hurt(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 i;
    s32 f;

    ((void (*)())set_pose_size)();
    self->hp = *(u8*)&self->hp & 0x7F;
    start_pad_vibration(1);
    play_sound(3, (random_byte() & 1) ^ 1, arg0);
    play_sound(3, 0x11, arg0);
    if (self->action != 0x11) {
        s32 one = 1;
        self->hurt_phase = one;
        self->unkCF = one;
        self->dash_momentum = 0;
        self->afterimage = 0;
        player_clear_attack(arg0);
        clear_flash_palette(arg0);
        i = self->hurt_type;
        self->facing = *(u8*)&self->hit_facing;
        ((void (*)(void*, s32))player_set_animation)(arg0, D_80073C70[i]);
        self->x_vel.val = hurt_motion_table[i][0];
        self->x_accel = hurt_motion_table[i][1];
        f = 0;
        self->y_vel.val = hurt_motion_table[i][2];
        self->gravity = hurt_motion_table[i][3];
        if ((self->equipped_parts & 0x200) ||
            (self->character != 0 && (D_800CCF2F & 0x20))) {
            f = 1;
        }
        if (f != 0 && ((u32)(i - 1) < 2U || i == 4)) {
            self->x_accel = 0;
            self->x_vel.val = 0;
            self->gravity = 0;
            self->y_vel.val = 0;
        }
        if (self->facing != 0) {
            self->x_vel.val = -self->x_vel.val;
        }
        self->invincibility_timer = hurt_invincibility_times[i];
        if ((u32)(i - 2) < 2U || i == 5) {
            self->air_state = 1;
        }
        self->action = 0x11;
        self->action_phase = 0;
    }
}
