// prog SLUS_013.95 | system movement | range 0x80036B10-0x80036EAC
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32

// 0x80036B10 update_wall_cling: wall cling: lands on the floor flag; while touching a wall faces away from it and counts unk8A down, then start_slide_down (slide); else func_8003AFF4.
// basis: code via=try_wall_jump; derived.tsv:77
// callers: update_player
// dispatch: player_action_handlers[action 9] in update_player
void update_wall_cling(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if (self->latched_collision_flags & 8) {
        player_land(arg0);
        return;
    }
    if (self->move_lock != 0) {
        func_8003AFF4((s32)arg0);
        return;
    }
    if (try_shoot_in_air(arg0) != 0) {
        return;
    }
    if (!(self->latched_collision_flags & 3)) {
        func_8003AFF4((s32)arg0);
        return;
    }
    if (try_wall_jump(arg0) == 0) {
        ((void (*)())animate_object)(arg0);
        if (self->animation_step.fields.event & 0x80) {
            if (self->latched_collision_flags & 1) {
                self->facing = 0;
            } else {
                self->facing = 0x40;
            }
            *(u8*)&self->animation_step.fields.event &= 0x3F;
        }
        if (--*(s8*)&self->unk8A == 0) {
            start_slide_down(arg0);
            return;
        }
        func_8003F508(arg0, 0xD);
    }
}
