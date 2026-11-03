// prog SLUS_013.95 | system movement | range 0x80037FD4-0x800381EC
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/graphics.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x80037FD4 func_80037FD4: action 23 handler: moves until y_vel ends, then on landing sets action 20.
// basis: none
// callers: update_player
// dispatch: player_action_handlers[action 23] in update_player
void func_80037FD4(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->action_phase == 0) {
        ((M2C_UNK(*)())animate_object)();
        apply_player_motion(arg0);
        if (self->y_vel.val <= 0) {
            player_set_animation(arg0, 0xB);
            self->air_state = -1;
            self->y_vel.val = 0;
            self->action_phase = (s8)((u8)self->action_phase + 1);
        }
    } else {
        if (self->latched_collision_flags & 8) {
            func_8003CDF0(arg0);
            set_stand_animation_by_hp(arg0);
            self->air_state = 0;
            self->unkD0 = -1;
            self->action = 0x14;
            self->action_phase = 0;
            return;
        }
        ((M2C_UNK(*)())animate_object)(arg0);
        apply_player_motion(arg0);
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/sound.h"
#include "mmx6/weapon.h"
#define M2C_UNK s32

// 0x8003809C func_8003809C: action 24 handler: waits for item_step 4, plays animation 0x27 with sound 0x21, then func_8003D330 and func_8003AD18.
// basis: none
// callers: update_player
// dispatch: player_action_handlers[action 24] in update_player
void func_8003809C(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    ((void (*)())animate_object)();
    if (self->action_phase == 0) {
        if (self->item_step == 4) {
            ((void (*)(void*, s32))player_set_animation)(self, 0x27);
            (*(u8*)&self->action_phase)++;
        }
    } else {
        if (self->animation_step.fields.event & 0x80) {
            self->animation_step.fields.event = 0;
            ((void (*)(s32, s32, void*))play_sound)(0, 0x21, 0);
        }
        if (self->animation_step.fields.relative_step == 0) {
            ((void (*)())func_8003D330)();
            func_8003AD18(self);
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/sound.h"
#include "mmx6/weapon.h"

// 0x80038144 func_80038144: action 25 handler: waits for D_800CD40C to clear, plays animation 0x27 with sound 0x21, then animation 0x28 and func_8003B954.
// basis: none
// callers: update_player
// dispatch: player_action_handlers[action 25] in update_player
void func_80038144(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    ((void (*)())animate_object)();
    if (self->action_phase == 0) {
        if (D_800CD40C == 0) {
            ((void (*)(void*, s32))player_set_animation)(arg0, 0x27);
            (*(u8*)&self->action_phase)++;
        }
    } else {
        if (self->animation_step.fields.event & 0x80) {
            self->animation_step.fields.event = 0;
            play_sound(0, 0x21, 0);
        }
        if (self->animation_step.fields.relative_step == 0) {
            player_set_animation(arg0, 0x28);
            func_8003B954(arg0);
        }
    }
}
