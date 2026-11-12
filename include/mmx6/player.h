// prog SLUS_013.95 | system player | range -
/* mmx6/player.h -- the player object, g_Player 0x800970A0 (hand-edited; Phase 2.5 T6).
 * Homed here from the generated include/mmx6/x4.h through config/x4/homed.tsv: x4.h never emits this block and
 * aliases X4_PlayerObj to PlayerObj, so `struct X4_PlayerObj` users are unchanged. +0x00..+0xE3: members, types and
 * names of mmx4's PlayerObj (x4.h at 807a01b), the AnimatedObj prefix inlined. +0xE4..+0x157: X6 only (mmx4's struct
 * ends at 0xE4; the symbol ends at background_objects 0x800971F8), members only where X6 readers touch them. */
#ifndef MMX6_PLAYER_H
#define MMX6_PLAYER_H

#include "common.h"
#include "mmx6/x4.h" /* X4_f32, union X4_AnimationStep, X4_PlayerUnk8A/DC, X4_PlayerChargeState, X4_Unk_unk68 */

// The player object (0x158 bytes), file-scope `extern struct X4_PlayerObj g_Player` in ~245 src/ files.
// DC7 notes: `+0xNN read by|written by <fn>|unreferenced`, held to the census by objfields.py --check.
struct PlayerObj {
    s8 active; // +0x00 read by func_8001D60C
    s8 id; // +0x01 read by func_800EA0EC
    s8 character; // +0x02 read by apply_capsule_part
    s8 on_screen; // +0x03 read by func_80022960
    s8 state; // +0x04 read by func_8001D60C
    s8 action; // +0x05 read by check_box_collision
    s8 action_phase; // +0x06 read by func_80020AA8
    s8 action_timer; // +0x07 read by func_800EC7DC
    X4_f32 x_pos; // +0x08 read by apply_capsule_part
    X4_f32 y_pos; // +0x0C read by check_box_collision
    void* backref; // +0x10 unreferenced
    s8 bg_offset; // +0x14 read by get_tile_attr_origin
    u8 facing; // +0x15 read by check_box_collision
    u8 unk16; // +0x16 read by func_80034288
    u8 unk17; // +0x17 read by func_8004672C
    X4_f32 unk18; // +0x18 read by func_80028EBC
    X4_f32 unk1C; // +0x1C read by func_80028EBC
    X4_f32 x_vel; // +0x20 read by apply_player_motion
    X4_f32 y_vel; // +0x24 read by func_80020AA8
    s32 x_accel; // +0x28 read by apply_player_motion
    s32 gravity; // +0x2C read by apply_player_motion
    u32** animation_table; // +0x30 read by func_800EC7DC
    u32* animation_cursor; // +0x34 unreferenced
    void* unk38; // +0x38 read by func_80020E1C
    void* unk3C; // +0x3C read by func_80020E1C
    u16 unk40; // +0x40 read by func_800EC7DC
    u16 unk42; // +0x42 read by func_800EC7DC
    union X4_AnimationStep animation_step; // +0x44 read by func_80020E1C
    u8 previous_animation_index; // +0x48 unreferenced
    s8 unk49; // +0x49 unreferenced
    s8 wall_climbable; // +0x4A written by check_box_collision
    s8 pad4B[0x50 - 0x4B]; // +0x4B read by func_8001D60C
    void* unk50; // +0x50 written by func_800E9F04
    struct X4_Unk_unk68* unk54; // +0x54 written by func_800E9878
    void* unk58; // +0x58 written by func_800E9F04
    s8 hp; // +0x5C read by exit_stage_by_clear
    s8 hud_hp; // +0x5D unreferenced
    s8 spawn_hp; // +0x5E unreferenced
    s8 drain_hold_timer; // +0x5F unreferenced
    s8 unk60; // +0x60 read by check_box_collision
    s8 invincibility_timer; // +0x61 written by func_800E9878
    s8 unk62; // +0x62 unreferenced
    s8 hurt_type; // +0x63 read by player_hurt
    s8 unk64; // +0x64 unreferenced
    s8 unk65; // +0x65 written by func_80032B34
    s8 unk66; // +0x66 unreferenced
    s8 air_state; // +0x67 read by func_8002F840
    struct X4_Unk_unk68* terrain_box; // +0x68 read by check_box_collision
    s16 unk6C; // +0x6C read by func_80032208
    s16 unk6E; // +0x6E read by func_80032208
    u8 collision_flags; // +0x70 read by collide_solid_object
    s8 unk71; // +0x71 read by func_8002F5FC
    u8 unk72; // +0x72 read by func_8002F288
    u8 unk73; // +0x73 written by check_box_collision
    u8 unk74; // +0x74 written by check_box_collision
    s8 unk75; // +0x75 read by check_box_collision
    s8 unk76; // +0x76 written by check_box_collision
    s8 unk77; // +0x77 written by check_box_collision
    s8 unk78; // +0x78 written by check_box_collision
    s8 touching_spikes; // +0x79 written by func_8002F288
    s8 spike_immune; // +0x7A read by func_80050C88
    union {
        u32 history;
        struct {
            u16 held;
            u16 previous;
        } buttons;
        struct {
            u8 held_low;
            u8 held_high;
            u8 previous_low;
            u8 previous_high;
        } bytes;
    } input; // +0x7C read by check_dash_input
    u16 pressed_input; // +0x80 read by check_dash_input
    u16 double_tap_direction; // +0x82 read by func_800ECE74
    s8 dash_momentum; // +0x84 read by func_80049100
    s8 dash_timer; // +0x85 written by func_800ECE74
    s8 air_action; // +0x86 written by start_hover
    s8 double_tap_dash; // +0x87 read by check_dash_input
    // +0x88..+0x89: mmx4's `union X4_PlayerUnk88 unk88` split into its two bytes (2.6 T5.c6).
    s8 double_tap_timer; // +0x88 read by update_double_tap_dash
    u8 latched_collision_flags; // +0x89 read by check_dash_input
    // +0x8A..+0x8B: X6 bytes; mmx4's `union X4_PlayerUnk8A unk8A` split (T9.c1).
    u8 unk8A; // +0x8A written by player_enter_wall_cling
    s8 wall_cling_delay; // +0x8B read by handle_jump_rise
    s8 afterimage; // +0x8C read by func_80020E1C
    u8 low_health_timer; // +0x8D read by update_player
    s8 attacking; // +0x8E read by func_80050C88
    s8 shot_fired; // +0x8F written by func_80044EA0
    s8 attack_ended; // +0x90 read by player_ladder_shoot
    u8 attack_pose_timer; // +0x91 written by func_801F28F4
    u8 shot_cooldown; // +0x92 read by update_player
    s8 weapon; // +0x93 read by exit_stage_by_clear
    s8 shot_types[2]; // +0x94 read by func_8004B50C
    s8 shot_type; // +0x96 read by func_80043890
    s8 last_shot_type; // +0x97 read by func_8004B50C
    s8 shot_count; // +0x98 read by func_801EFCF4
    s8 special_shot_count; // +0x99 read by func_801EFCF4
    s8 shot_cycle; // +0x9A read by func_800FDC6C
    X4_PlayerChargeState charge_state[2]; // +0x9B read by func_80020AA8
    u8 charge_timer; // +0x9D read by func_8003ED98
    u8 special_charge_timer; // +0x9E read by func_8003ED98
    s8 flash_delay; // +0x9F read by player_update_flash
    s8 flash_phase; // +0xA0 read by player_update_flash
    s8 flash_palette; // +0xA1 read by player_update_flash
    s8 shot_palette_timer; // +0xA2 read by player_update_flash
    s8 : 8; // +0xA3 unreferenced
    s8 hurt_phase; // +0xA4 read by player_update_flash
    s8 hit_facing; // +0xA5 read by start_hurt
    s8 stock_charge; // +0xA6 read by func_8003ED98
    s8 armor_parts; // +0xA7 unreferenced
    s16 weapon_energy[8]; // +0xA8 read by exit_stage_by_clear
    u8 arm_type; // +0xB8 unreferenced
    s8 boss_flags; // +0xB9 unreferenced
    s8 stun_timer; // +0xBA unreferenced
    s8 combo; // +0xBB unreferenced
    s8 update_delay; // +0xBC unreferenced
    s8 update_delay_request; // +0xBD unreferenced
    s8 beam_in_delay; // +0xBE unreferenced
    s8 actions_reset; // +0xBF unreferenced
    s8 script_state; // +0xC0 unreferenced
    s8 script_action; // +0xC1 unreferenced
    s8 script_facing; // +0xC2 unreferenced
    s8 input_locked; // +0xC3 unreferenced
    s8 capsule_state; // +0xC4 unreferenced
    s8 ride_state; // +0xC5 unreferenced
    s8 unkC6; // +0xC6 unreferenced
    s8 death_timer; // +0xC7 unreferenced
    // +0xC8..+0xD3: X6 bytes; mmx4's `struct X4_MainObj* weapon_06_slots[3]` does not hold here (T9.c1).
    s8 padC8; // +0xC8 unreferenced
    u8 beaten_stages; // +0xC9 read by switch_weapon
    s8 unkCA; // +0xCA read by func_800379AC
    s8 padCB[0xCE - 0xCB]; // +0xCB read by func_8002935C
    s8 unkCE; // +0xCE read by update_stage_entry
    s8 unkCF; // +0xCF written by update_player
    s8 unkD0; // +0xD0 read by update_player
    s8 padD1; // +0xD1 unreferenced
    u8 unkD2; // +0xD2 read by func_80037E88
    s8 move_lock; // +0xD3 read by handle_jump_rise
    s8 ride_animation; // +0xD4 read by func_8002927C
    u8 hover_timer; // +0xD5 written by func_800EFFCC; mmx4 name, unconfirmed in X6: 0 through the whole hover (mv_hover2-0037, mv_hover2-0040); held: nonzero holds action 18 (func_80037BC4 ends it at 0) and blocks fire (weapon.c:21); >0 enters action 18 phase 1 and is negated (func_8003A268); the rock_06 object func_800EFFCC clears it
    u8 hover_bob; // +0xD6 unreferenced
    s8 voice_timer; // +0xD7 unreferenced
    u8 unkD8; // +0xD8 read by func_80037BC4
    s8 is_clone; // +0xD9 written by start_hover
    u16 clone_timer; // +0xDA written by start_hover
    // +0xDC..+0xDD: X6 bytes; mmx4's `union X4_PlayerUnkDC clone_offset` does not hold here (T9.c1).
    s8 padDC; // +0xDC unreferenced
    s8 unkDD; // +0xDD written by update_player
    s8 controlling_clone; // +0xDE unreferenced
    s8 unkDF; // +0xDF written by func_80049A14
    s8 nova_strike_active; // +0xE0 read by clamp_player_to_ceiling
    s8 nova_strike_timer; // +0xE1 written by check_giga_attack
    u8 item_step; // +0xE2 read by func_80051D28
    u8 unkE3; // +0xE3 read by func_80039984
    // X6 only from here (mmx4's PlayerObj ends at 0xE4).
    u8 unkE4; // +0xE4 read by func_8001EA28
    u8 unkE5; // +0xE5 read by func_80051890
    u8 hit_damage; // +0xE6 written by check_box_collision
    u8 armor; // +0xE7 read by func_800F1980
    s8 padE8[0xEC - 0xE8]; // +0xE8 unreferenced
    s32 equipped_parts; // +0xEC read by func_801ECF64
    s32 walk_start_speed; // +0xF0 read by func_80037E88
    s32 walk_speed; // +0xF4 read by func_80037E88
    s32 jump_speed; // +0xF8 read by check_ceiling_jump
    s32 unkFC; // +0xFC read by apply_object_motion
    s32 base_gravity; // +0x100 read by check_giga_attack
    s32 dash_speed; // +0x104 read by func_800ED3A4
    s32 dash_base_speed; // +0x108 read by check_dash_end
    s32 unk10C; // +0x10C written by set_base_move_stats
    s32 slide_down_speed; // +0x110 read by start_slide_down
    s32 wall_jump_y_speed; // +0x114 read by start_wall_jump
    s32 unk118; // +0x118 read by grab_ladder
    s32 unk11C; // +0x11C written by set_base_move_stats
    s32 unk120; // +0x120 written by set_base_move_stats
    s32 unk124; // +0x124 read by func_80038CD0
    s32 unk128; // +0x128 read by func_800389B4
    s32 unk12C; // +0x12C read by func_80038594
    s32 unk130; // +0x130 read by func_80038BA8
    s32 jump_gravity; // +0x134 read by start_wall_jump
    s8 pad138[0x13C - 0x138]; // +0x138 unreferenced
    s32 unk13C; // +0x13C read by func_800ED3A4
    s8 pad140[0x144 - 0x140]; // +0x140 unreferenced
    s32 timed_item; // +0x144 read by use_weapon_energy; kind of the timed pickup: func_80034288 sets it from the item's
    // +0x2D with a frame count at +0x148, func_80034830 clears it when that runs out; 3: shots cost no energy
    s8 pad148[0x14A - 0x148]; // +0x148 unreferenced
    s16 giga_energy_max; // +0x14A read by check_giga_attack
    s16 unk14C; // +0x14C read by func_800F116C
    s8 pad14E[0x150 - 0x14E]; // +0x14E unreferenced
    s8 unk150; // +0x150 read by move_by_velocity
    s8 pad151[0x158 - 0x151]; // +0x151 unreferenced
};

// Functions the player files call (Phase 2.5 T10.c2), each with its definition's type: player_update_flash
// (player/update_flash.c); the rest are defined in placeholder files of unit 32208 (system -) or in overlay
// rock_01 (0x801E....), so they live with their calling system. Callees of other systems: their own headers.
void player_update_flash(struct X4_PlayerObj* self);
s32 move_by_velocity(void*);
void update_player_damage(void* arg0);
s32 func_80039984(void*);
void check_floor_lost(void* arg0);
void update_double_tap_dash(void* arg0);
void func_8003A1C8(void* arg0);
void func_8003A268(void* arg0);
s32 try_wall_jump(void*);
s32 is_pressing_into_wall(void*);
s32 try_grab_ladder_from_air(void*);
void start_dash(struct X4_PlayerObj*);
s32 start_jump(void*);
s32 func_8003AFF4(s32);
s32 player_land(void*);
s32 func_8003B5B8(void*);
void func_8003C3C8(void* arg0);
void set_air_x_velocity(void* arg0);
void func_8003D394(void* arg0);
s32 try_shoot_in_air(void*);
void update_player_charge(struct X4_PlayerObj* arg0);
s32 func_8003F508(void*, s32);
s32 func_801EA454(void*);
s32 func_801EA560(void*);
s32 func_801EBF94(void*);
s32 func_801EC178(void*);
// Phase 2.6 T10.c1: hoisted from the movement files' own declarations
s32 apply_player_motion(void* arg);
s32 handle_slide_down();
s32 init_move_stats(void*);
s32 player_check_dash_jump_walk(struct X4_PlayerObj* self);
s32 start_hover(struct X4_PlayerObj* self);
s32 start_walk(void*);

#endif /* MMX6_PLAYER_H */
