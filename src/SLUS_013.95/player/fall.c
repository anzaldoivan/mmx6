// prog SLUS_013.95 | system player | range 0x800368FC-0x80036A00
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/cling.h"
#include "mmx6/dash.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32

// 0x800368FC update_fall: falling: lands on the floor flag (or ceiling jump), else the air checks (wall cling, air dash) then gravity and motion.
// basis: oracle derived.tsv:75; oracle:docs/systems/movement.md mv_jump-0028 mv_jump-0041 mv_hover2-0040
// callers: update_player
// dispatch: player_action_handlers[action 7] in update_player
void update_fall(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 var_v0;

    if (self->latched_collision_flags & 8) {
        if (((s32(*)())check_ceiling_jump)() == 0) {
            player_land(arg0);
        }
    } else {
        if (self->character == 0) {
            var_v0 = try_shoot_in_air(arg0);
        } else if ((func_801EA560(arg0) == 0) && (func_801EA454(arg0) == 0)) {
            var_v0 = func_801EC028(arg0);
        } else {
            return;
        }
        if ((var_v0 == 0) && (try_grab_ladder_from_air(arg0) == 0) &&
            (func_80039984(arg0) == 0) && (try_enter_wall_cling(arg0) == 0) &&
            (select_air_dash(arg0) == 0)) {
            animate_object(arg0);
            set_air_x_velocity(arg0);
            func_8003D394(arg0);
            func_8003F508(arg0, 0xB);
        }
    }
}
