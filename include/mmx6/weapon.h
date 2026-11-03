// prog SLUS_013.95 | system weapon | range -
/* mmx6/weapon.h -- the weapon functions (weapon/) and the callees of the weapon files defined in placeholder files of units 120A0/32208 (system -) or in overlay rock_00 (0x801EE434) (hand-edited; Phase 2.5 T10.c2). Each prototype carries its definition's type
 * (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_WEAPON_H
#define MMX6_WEAPON_H

#include "common.h"
#include "mmx6/x4.h"

// weapon/
void* player_spawn_weapon(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
void init_buster_shot_visual(struct X4_VisualObj*);
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);
void switch_weapon(void* self);
void update_weapon_switch(void* arg0);
// placeholder files and overlays, called by the weapon files
void func_80017B04(u8*, s16, s16);
s8* func_8002BEC4(s8* p, s32 dir);
void* func_8002C32C();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
s32 player_set_animation(void*, s32);
void func_8003CDF0();
void load_buffered_palette(s32, s32, s32);
s32 play_sound_unless_low_health(void*, s32);
void func_8003DD6C(void* self);
s32 set_shot_types(void*);
s32 react_to_weapon_change(void*);
void player_reset_charge();
s32 func_80049800(void*, void*);
void func_800499A0(void*);
s32 func_801EE434(void);
// Phase 2.6 T10.c1: hoisted from the movement files' own declarations
void charge_special_weapon(void* arg0);
s32 check_giga_attack(void* self);
s32 func_8003ED98(struct X4_PlayerObj* p);
void update_special_charge(struct X4_PlayerObj*);
void player_load_weapon_palette(struct X4_PlayerObj* self);
s32 player_set_charge_flash(struct X4_PlayerObj*, s32);
void try_fire_shot(void* arg0);
s32 try_shoot_on_ladder(void*);

#endif /* MMX6_WEAPON_H */
