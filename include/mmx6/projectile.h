// prog SLUS_013.95 | system projectile | range -
/* mmx6/projectile.h -- the projectile entry, g_projectiles 0x80093C98, 32 x 0xA0 (hand-edited; Phase 2.5 T6).
 * Homed here from the generated include/mmx6/x4.h through config/x4/homed.tsv: x4.h never emits this block and
 * aliases X4_ShotObj to ProjectileObj, so `struct X4_ShotObj` users are unchanged. +0x00..+0x9B: members, types and
 * names of mmx4's ShotObj (x4.h at 807a01b), the AnimatedObj prefix inlined. +0x9C..+0x9F: X6 only (mmx4's struct
 * ends at 0x9C; X6 strides 0xA0), members only where X6 readers touch them. */
#ifndef MMX6_PROJECTILE_H
#define MMX6_PROJECTILE_H

#include "common.h"
#include "mmx6/x4.h" /* X4_f32, union X4_AnimationStep, X4_ShotUnk58/8C, X4_Shot24Ext, X4_Shot55Unk84, X4_f32_halves */

// One projectile slot (0xA0 bytes); the pool is g_projectiles below (docs/types/projectile.md).
// DC7 notes: `+0xNN read by|written by <fn>|unreferenced`, held to the census by objfields.py --check.
struct ProjectileObj {
    s8 active; // +0x00 read by check_enemy_hits
    s8 id; // +0x01 read by func_8002012C
    s8 unk2; // +0x02 read by func_80049854
    s8 on_screen; // +0x03 read by func_8002012C
    s8 state; // +0x04 written by func_800F65DC
    s8 unk5; // +0x05 written by func_80049854
    s8 unk6; // +0x06 unreferenced
    s8 unk7; // +0x07 unreferenced
    X4_f32 x_pos; // +0x08 read by func_80049854
    X4_f32 y_pos; // +0x0C read by func_80049854
    void* backref; // +0x10 unreferenced
    s8 bg_offset; // +0x14 unreferenced
    u8 unk15; // +0x15 read by func_80049854
    u8 unk16; // +0x16 read by func_80049854
    u8 unk17; // +0x17 unreferenced
    X4_f32 unk18; // +0x18 unreferenced
    X4_f32 unk1C; // +0x1C unreferenced
    X4_f32 x_vel; // +0x20 written by func_800F65DC
    X4_f32 y_vel; // +0x24 written by func_800EB1F4
    s32 unk28; // +0x28 written by func_800EB1F4
    s32 unk2C; // +0x2C written by func_800EB1F4
    u32** animation_table; // +0x30 read by func_80049854
    u32* animation_cursor; // +0x34 unreferenced
    void* unk38; // +0x38 unreferenced
    void* unk3C; // +0x3C read by func_80049854
    u16 unk40; // +0x40 read by func_80049854
    u16 unk42; // +0x42 read by func_80049854
    union X4_AnimationStep animation_step; // +0x44 read by func_80049854
    u8 previous_animation_index; // +0x48 unreferenced
    s8 pad49[0x50 - 0x49]; // +0x49 unreferenced
    union {
        const u8* data;
        s16* frames;
        struct X4_PlayerObj* player;
    } unk50; // +0x50 written by func_8002C32C
    const u8* unk54; // +0x54 written by func_8002C32C
    union X4_ShotUnk58 unk58; // +0x58 unreferenced
    s8 unk5C; // +0x5C unreferenced
    s8 pad5D[0x60 - 0x5D]; // +0x5D unreferenced
    s8 unk60; // +0x60 unreferenced
    s8 unk61; // +0x61 unreferenced
    s8 unk62; // +0x62 unreferenced
    s8 unk63; // +0x63 unreferenced
    s8 unk64; // +0x64 unreferenced
    s8 unk65; // +0x65 unreferenced
    s8 unk66; // +0x66 unreferenced
    s8 unk67; // +0x67 read by func_800EB1F4
    struct X4_Unk_unk68* unk68; // +0x68 written by func_8002C32C
    s8 pad6C[0x70 - 0x6C]; // +0x6C unreferenced
    u8 unk70; // +0x70 written by func_80032BE8
    s8 pad71; // +0x71 unreferenced
    s8 unk72; // +0x72 unreferenced
    s8 unk73; // +0x73 unreferenced
    s8 unk74; // +0x74 unreferenced
    s8 unk75; // +0x75 unreferenced
    s8 unk76; // +0x76 unreferenced
    s8 unk77; // +0x77 unreferenced
    s8 unk78; // +0x78 unreferenced
    s8 : 8; // +0x79 unreferenced
    s8 unk7A; // +0x7A unreferenced
    s8 : 8; // +0x7B unreferenced
    struct X4_WeaponObj* unk7C; // +0x7C read by func_800F65DC
    s32 : 32; // +0x80 unreferenced
    union {
        s32 value;
        u32* collision_state;
        struct X4_EffectObj* effect;
        u16 halves[2];
        u8 bytes[4];
        struct X4_Shot24Ext shot_24;
        struct X4_Shot55Unk84 shot_55;
    } unk84; // +0x84 read by func_800EFAEC
    s16 timer; // +0x88 unreferenced
    s16 unk8A; // +0x8A unreferenced
    union X4_ShotUnk8C unk8C; // +0x8C read by func_800EFAEC
    X4_f32_halves unk90; // +0x90 unreferenced
    s8 unk94; // +0x94 unreferenced
    u8 unk95; // +0x95 unreferenced
    s8 unk96; // +0x96 unreferenced
    s8 pad97; // +0x97 unreferenced
    s8 unk98; // +0x98 read by func_800EFAEC
    s8 unk99; // +0x99 unreferenced
    s8 unk9A; // +0x9A unreferenced
    s8 pad9B; // +0x9B unreferenced
    s8 unk9C; // +0x9C read by check_enemy_hits
    s8 unk9D; // +0x9D read by func_8003208C
    s8 pad9E[0xA0 - 0x9E]; // +0x9E unreferenced
};

// The pool: 32 slots, 0x80093C98..0x80095098 (config/symbols.SLUS_013.95.txt). Views that keep a byte spelling:
// docs/types/projectile.md.
extern struct ProjectileObj g_projectiles[32];

#endif /* MMX6_PROJECTILE_H */
