// prog SLUS_013.95 | system player | range 0x80034FBC-0x80035140
#include "common.h"
#include "mmx6/x4.h"

#include "mmx6/globals.h"
#include "mmx6/weapon.h"
#include "mmx6/pilot_globals.h"

// 0x80034FBC update_player: per-frame player step: timers, weapon switch, the player state handler table, charge and shot, flash.
// basis: xref derived.tsv:15; xref:caller=player_update_flash
// callers: none known
void update_player(struct X4_PlayerObj* p) {
    s32 d = *(u8*)&p->unkD0;
    s32 f = (u8)g_playthrough_state.unkF;
    s32 d4 = *(u8*)&p->ride_animation;
    s32 t = *(u8*)&p->unk71;

    p->shot_fired = 0;
    p->attack_ended = 0;
    p->unkCF = 0;
    p->unkDD = 0;
    p->move_lock = d | f | d4;
    p->latched_collision_flags = p->collision_flags | t;
    if (g_playthrough_state.unk10 == 0) {
        if (p->unkE5 != 0) {
            p->unkE5--;
        }
        update_player_damage(p);
        if (p->hp == 0) {
            return;
        }
        if (p->shot_cooldown != 0) {
            p->shot_cooldown--;
        }
        if (p->attack_pose_timer != 0) {
            if (--p->attack_pose_timer == 0) {
                p->attack_ended = 1;
                p->attacking = 0;
            }
        }
        if (*(s8*)&p->low_health_timer > 0) {
            if (--*(s8*)&p->low_health_timer == 0) {
                *(s8*)&p->low_health_timer = -1;
            }
        }
        func_8003A1C8(p);
        func_8003A268(p);
        update_double_tap_dash(p);
        check_floor_lost(p);
        update_weapon_switch(p);
        player_action_handlers[p->action](p);
        p->unk71 = 0;
        p->unk72 = 0;
        p->wall_climbable = 0;
    }
    if (g_playthrough_state.unk10 != 2) {
        update_player_charge(p);
        player_update_flash(p);
        func_8003C3C8(p);
    }
}
