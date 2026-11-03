// prog SLUS_013.95 | system movement | range 0x80037B10-0x80037DC0
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

// 0x80037B10 func_80037B10: as move_x_backward, and also zeroes y_vel when the motion meets a wall.
// basis: none
// callers: none known
// unnamed callers: func_80037920
void func_80037B10(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 temp_v0;
    s32 var_v1;

    if (self->ride_animation == 0) {
        temp_v0 = self->x_vel.val;
        if (temp_v0 != 0) {
            var_v1 = 2;
            if (temp_v0 > 0) {
                var_v1 = 1;
            }
            if (self->latched_collision_flags & var_v1) {
                self->x_vel.val = 0;
                self->y_vel.val = 0;
                self->x_accel = 0;
            }
        }
        apply_player_motion(arg0);
        if (self->facing != 0) {
            if (self->x_vel.val > 0) {
                self->x_vel.val = 0;
                self->x_accel = 0;
            }
        } else if (self->x_vel.val < 0) {
            self->x_vel.val = 0;
            self->x_accel = 0;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"

// 0x80037BC4 func_80037BC4: g_playthrough_state.unkF set leads to func_8003B870; hover_timer 0 ends the state (air_action 1, gameplay unlocked); phase 0 sets animation unkD8.
// basis: none
// callers: update_player
// dispatch: player_action_handlers[action 18] in update_player
void func_80037BC4(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    struct X4_EngineObj* e = &g_playthrough_state;

    if (e->unkF != 0) {
        ((void (*)())func_8003B870)();
        return;
    }
    if (*(s8*)&self->hover_timer == 0) {
        set_pose_size(arg0);
        ((void (*)(void*))start_jump)(arg0);
        self->air_action = 1;
        e->gameplay_locked = 0;
        return;
    }
    if (self->action_phase == 0) {
        ((void (*)(void*, s32))player_set_animation)(arg0, self->unkD8);
        *(u8*)&self->action_phase += 1;
    }
    animate_object(arg0);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"

#define M2C_UNK s32

// 0x80037C74 func_80037C74: phase 0 runs func_80037CB4, later phases func_80037D68.
// basis: none
// callers: update_player
// dispatch: player_action_handlers[action 19] in update_player
void func_80037C74(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if (self->action_phase == 0) {
        func_80037CB4();
        return;
    }
    func_80037D68();
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

// 0x80037CB4 func_80037CB4: action 19 phase 0: not riding: stands on the floor flag, else zeroes motion with base gravity and goes to phase 1; riding: animates on the ground.
// basis: none
// callers: none known
// unnamed callers: func_80037C74 (action 19 phase 0)
void func_80037CB4(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if (self->ride_animation == 0) {
        ((void (*)())set_pose_size)();
        if (self->latched_collision_flags & 8) {
            self->air_state = 0;
            do {
                func_8003ADB4(arg0);
            } while (0);
            self->dash_momentum = 0;
        } else {
            player_set_animation(arg0, 0xB);
            self->x_vel.val = 0;
            self->x_accel = 0;
            self->y_vel.val = 0;
            self->air_state = -1;
            self->gravity = self->base_gravity;
            self->action_phase = 1 + *(u8*)&self->action_phase;
            do {
            } while (0);
            self->dash_momentum = 0;
        }
        self->air_action = 0;
        return;
    }
    if (self->air_state == 0) {
        animate_object(arg0);
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

M2C_UNK animate_object();
s32 apply_player_motion(void* arg);

// 0x80037D68 func_80037D68: action 19 phase 1+: lands on the floor flag, else animates and moves.
// basis: none
// callers: none known
// unnamed callers: func_80037C74 (action 19 phase 1+)
void func_80037D68(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->latched_collision_flags & 8) {
        player_land(arg0);
        return;
    }
    animate_object(arg0);
    apply_player_motion(arg0);
    func_8003D394(arg0);
}
