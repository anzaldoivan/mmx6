// prog SLUS_013.95 | system movement | range 0x80036E70-0x800370AC
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"

#define M2C_UNK s32

// 0x80036E70 update_slide_down: wall slide: phase 0 runs handle_slide_down, later phases update_slide_down_let_go.
// basis: xref derived.tsv:16; xref:callee=handle_slide_down
// callers: update_player
// dispatch: player_action_handlers[action 11] in update_player
void update_slide_down(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if (self->action_phase == 0) {
        handle_slide_down();
        return;
    }
    update_slide_down_let_go();
}

// prog SLUS_013.95 | system player | range 0x80036EB0-0x80036FB8
#include "common.h"

#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#include "mmx6/pilot_globals.h"

// 0x80036EB0 handle_slide_down: sliding-down state routine.
// basis: community tweaks-index.tsv:188
// callers: update_slide_down
M2C_UNK handle_slide_down(struct X4_PlayerObj* arg0) {
    s32 var_v0;

    if (arg0->latched_collision_flags & 8) {
        ((void (*)())player_land)();
        return;
    }
    if (arg0->move_lock != 0) {
        func_8003AFF4((s32)arg0);
        return;
    }
    if (arg0->character == 0) {
        var_v0 = try_shoot_in_air(arg0);
    } else {
        if (func_801EA560(arg0) != 0) {
            return;
        }
        var_v0 = func_801EC178(arg0);
    }
    if (var_v0 != 0) {
        return;
    }
    if (!(arg0->latched_collision_flags & 3)) {
        func_8003AFF4((s32)arg0);
        return;
    }
    if (try_wall_jump(arg0) == 0) {
        if (is_pressing_into_wall(arg0) != 0) {
            animate_object(arg0);
            move_by_velocity(arg0);
            func_8003D394(arg0);
            func_8003F508(arg0, 0xF);
            return;
        }
        func_8003B5B8(arg0);
    }
}

// prog SLUS_013.95 | system movement | range 0x80036FBC-0x800370AC
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32

// 0x80036FBC update_slide_down_let_go: action 11 phase 1+: lands on the floor flag, func_8003AFF4 on lock; else moves for unk8A frames, then falls (action 7) with x_vel 0.
// basis: code via=is_pressing_into_wall; derived.tsv:81
// callers: update_slide_down
M2C_UNK update_slide_down_let_go(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 var_v0;

    if (self->latched_collision_flags & 8) {
        ((void (*)())player_land)();
        return;
    }
    if (self->move_lock != 0) {
        func_8003AFF4((s32)arg0);
        return;
    }
    if (self->character == 0) {
        var_v0 = try_shoot_in_air(arg0);
    } else {
        if (func_801EA560(arg0) != 0) {
            return;
        }
        var_v0 = func_801EC028(arg0);
    }
    if (var_v0 != 0) {
        return;
    }
    animate_object(arg0);
    apply_player_motion(arg0);
    func_8003D394(arg0);
    if (--*(s8*)&self->unk8A == 0) {
        self->x_vel.val = 0;
        self->action = 7;
        self->action_phase = 0;
        return;
    }
    func_8003F508(arg0, 0xB);
}
