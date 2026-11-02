#include "common.h"
#include "mmx6/x4.h"

void func_80039228(void* arg0);
void func_80039DFC(void* arg0);
void func_80039F78(void* arg0);
void func_8003A1C8(void* arg0);
void func_8003A268(void* arg0);
void func_8003C3C8(void* arg0);
void player_update_flash(struct X4_PlayerObj* self);
void func_8003EC78(struct X4_PlayerObj* arg0);
void update_weapon_switch(void* arg0);
extern void (*D_80073ACC[])(struct X4_PlayerObj*);
extern struct X4_EngineObj g_playthrough_state;

// 0x80034FBC update_player: per-frame player step: timers, weapon switch, the player state handler table, charge and shot, flash.
// basis: xref player_update_flash (docs/leads/derived.tsv:15)
// callers: none known (no jal caller)
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
    p->unk88.bytes.collision_flags = p->unk70 | t;
    if (g_playthrough_state.unk10 == 0) {
        if (p->unkE5 != 0) {
            p->unkE5--;
        }
        func_80039228(p);
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
        if (*(s8*)&p->unk8D > 0) {
            if (--*(s8*)&p->unk8D == 0) {
                *(s8*)&p->unk8D = -1;
            }
        }
        func_8003A1C8(p);
        func_8003A268(p);
        func_80039F78(p);
        func_80039DFC(p);
        update_weapon_switch(p);
        D_80073ACC[p->unk5](p);
        p->unk71 = 0;
        p->unk72 = 0;
        p->wall_climbable = 0;
    }
    if (g_playthrough_state.unk10 != 2) {
        func_8003EC78(p);
        player_update_flash(p);
        func_8003C3C8(p);
    }
}
