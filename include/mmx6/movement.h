// prog SLUS_013.95 | system movement | range -
/* mmx6/movement.h -- the callees and data of the movement files (units 32208, 3CE30) defined in placeholder files of those units (system -), in overlays rock_00/rock_01, or declared otherwise by other files of the fleet (C0331): is_off_screen, start_pad_vibration, D_800CD40C, try_start_attack, start_player_attack (hand-edited; Phase 2.6 T10.c1). Each prototype carries the type its
 * callers declared (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_MOVEMENT_H
#define MMX6_MOVEMENT_H

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800CD40C;
s32 func_80029478(s32, s32, s32);
void func_8002ABA8();
s32 apply_object_motion();
u8 func_80030304(struct X4_PlayerObj*, s16, s16);
s32 func_8003040C(void*);
void update_wall_jump_push();
void update_wall_jump_rise();
s32 update_slide_down_let_go();
void func_80037CB4();
void func_80037D68();
s32 func_80038594(void*);
s32 func_80038788(void* arg0);
s32 func_80039C40(struct X4_PlayerObj*);
s32 check_crouch_input(void*);
s32 check_walk_start_input(void*);
s32 check_walk_input(void*);
s32 func_8003A628();
void func_8003A678(void* arg0);
s32 func_8003A814(void*, s32);
void cancel_player_attack(void* arg0);
void func_8003AD18(void* arg0);
void func_8003ADB4(void* arg0);
s32 func_8003AED4(void*);
s32 func_8003B298(void*);
s32 func_8003B30C(void*);
void func_8003B360(void*);
void start_slide_down(void*);
void reach_ladder_top(void*);
s32 player_enter_ladder_climb_up(void*);
s32 player_enter_ladder_climb_down(void*);
void func_8003B870(struct X4_PlayerObj* self);
void func_8003B954(struct X4_PlayerObj* self);
s32 func_8003B9AC(void*);
void spawn_dash_tile24_visual(void* arg0);
void spawn_wall_jump_visual(void* arg0);
void set_pose_size();
void player_clear_dash();
void player_clear_attack();
s32 func_8003D26C(void*);
s32 func_8003D330();
void set_base_move_stats(void*);
s32 load_armor_and_parts(void*);
s32 refresh_weapon_state(void*);
s32 func_8003F700(void*);
s32 func_801EA254(void*);
s32 func_801EB61C(void*);
void func_801EB6E8(void* arg0);
s32 func_801EBE04(void*);
s32 func_801EBE54(void*);
s32 func_801EBEDC(void*);
s32 func_801EC028();
s32 func_801EC0F0(void*);
s32 func_801EC298(void*);
s32 func_801EC86C(void*);
s32 func_801EC9C4(void*);
s32 func_801ECA50(void*);
s32 is_off_screen(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
void start_pad_vibration(s32);
void start_player_attack(void*, s32);
s32 try_start_attack(void*);

#endif /* MMX6_MOVEMENT_H */
