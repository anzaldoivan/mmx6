// prog SLUS_013.95 | system movement | range 0x80035144-0x80035270
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x80035144 update_stage_entry: stage-start drop-in: phase 0 falls until the floor flag (latched & 8), phase 1 runs player init on the animation event and hands off at the animation end.
// basis: code via=init_move_stats; derived.tsv:69
// callers: update_player
// dispatch: player_action_handlers[action 0] in update_player
void update_stage_entry(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s8 temp_v0;

    ((void (*)())animate_object)();
    if (self->action_phase == 0) {
        if (self->unkCE != 0) {
            if (--self->unkCE == 0) {
                set_pose_size(arg0);
            }
            move_by_velocity(arg0);
            return;
        }
        if (self->latched_collision_flags & 8) {
            player_set_animation(arg0, 2);
            self->air_state = 0;
            background_objects[0].unk44 = 1;
            background_objects[1].unk44 = 1;
            background_objects[2].unk44 = 1;
            self->action_phase = 1 + *(u8*)&self->action_phase;
            return;
        }
        move_by_velocity(arg0);
        func_8003D394(arg0);
        return;
    }
    if (self->animation_step.fields.event != 0) {
        self->animation_step.fields.event = 0;
        load_armor_and_parts(arg0);
        init_move_stats(arg0);
    }
    if (self->animation_step.fields.relative_step == 0) {
        D_800CCEEC = 0;
        if (self->character != 0) {
            load_armor_and_parts(arg0);
            init_move_stats(arg0);
        }
        func_8003AD18(arg0);
    }
}
