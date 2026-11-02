// prog SLUS_013.95 | system object | range -
/* mmx6/object.h -- the object header, base object, animated object and main object (hand-edited; Phase 2.5 T5).
 * Homed here from the generated include/mmx6/x4.h through config/x4/homed.tsv: x4.h never emits these blocks and
 * aliases X4_ObjectHeader, X4_BaseObj, X4_AnimatedObj and X4_MainObj to these tags, so `struct X4_BaseObj` users are
 * unchanged. Members, types and offsets are those of mmx4's ObjectHeader/BaseObj/AnimatedObj/MainObj (x4.h at 807a01b). */
#ifndef MMX6_OBJECT_H
#define MMX6_OBJECT_H

#include "common.h"
#include "mmx6/x4.h" /* X4_f32, union X4_AnimationStep, union X4_MainObjExt, struct X4_Unk_unk68 */

// The common object header, read by func_800F4240 (a cast) and func_800EBFB4 (as D_80097420).
struct ObjectHeader {
    s8 active; // +0x00 read by func_801EF410
    s8 id; // +0x01 read by func_801EF410
    s8 unk2; // +0x02 read by func_801EECA4
    s8 on_screen; // +0x03 read by func_801F1450
    s8 state; // +0x04 read by func_801EE14C
    s8 unk5; // +0x05 read by func_801EEFC0
    s8 unk6; // +0x06 read by func_8004202C
    s8 unk7; // +0x07 read by func_801F29B8
    X4_f32 x_pos; // +0x08 read by func_800F4240
    X4_f32 y_pos; // +0x0C read by func_800F4240
    void* backref; // +0x10 unreferenced
};

// The base object, read by func_80044D04, func_8002CAB4 and drop_item.
struct BaseObj {
    s8 active; // +0x00 read by func_80044D04
    s8 id; // +0x01 read by func_80044D04
    s8 unk2; // +0x02 read by func_80044D04
    s8 on_screen; // +0x03 read by func_800E9CA8
    s8 state; // +0x04 read by func_80049100
    s8 unk5; // +0x05 read by func_80049748
    s8 unk6; // +0x06 read by func_800EFFD8
    s8 unk7; // +0x07 read by func_800E9C84
    X4_f32 x_pos; // +0x08 read by func_8002CAB4
    X4_f32 y_pos; // +0x0C read by func_8002CAB4
    void* backref; // +0x10 read by func_80042C48
    s8 bg_offset; // +0x14 read by drop_item
    u8 unk15; // +0x15 read by func_80044D04
    u8 unk16; // +0x16 read by func_80053A20
    u8 unk17; // +0x17 unreferenced
};

// The animated object, read by func_80020AA8, func_80032C88, func_800F5088 and move_object.
struct AnimatedObj {
    s8 active; // +0x00 written by func_80029F38
    s8 id; // +0x01 read by func_800F5360
    s8 unk2; // +0x02 read by func_80020AA8
    s8 on_screen; // +0x03 read by func_800ECA2C
    s8 state; // +0x04 read by func_80020AA8
    s8 unk5; // +0x05 read by func_800F2014
    s8 unk6; // +0x06 read by func_80020AA8
    s8 unk7; // +0x07 read by func_800EE5AC
    X4_f32 x_pos; // +0x08 read by func_8002CBFC
    X4_f32 y_pos; // +0x0C read by func_8002CBFC
    void* backref; // +0x10 written by func_80029F38
    s8 bg_offset; // +0x14 read by func_8002CBFC
    u8 unk15; // +0x15 read by func_800F2014
    u8 unk16; // +0x16 written by func_800F5378
    u8 unk17; // +0x17 read by func_800F55A0
    X4_f32 unk18; // +0x18 read by func_80032C88
    X4_f32 unk1C; // +0x1C read by func_80032C88
    X4_f32 x_vel; // +0x20 read by func_800F21A8
    X4_f32 y_vel; // +0x24 read by func_800F55A0
    s32 unk28; // +0x28 written by func_800445A8
    s32 unk2C; // +0x2C written by func_800445A8
    u32** animation_table; // +0x30 read by func_800F5088
    u32* animation_cursor; // +0x34 unreferenced
    void* unk38; // +0x38 read by func_800F2014
    void* unk3C; // +0x3C read by func_800F2014
    u16 unk40; // +0x40 read by func_800F5088
    u16 unk42; // +0x42 read by func_800F5088
    union X4_AnimationStep animation_step; // +0x44 read by func_800EA650
    u8 previous_animation_index; // +0x48 unreferenced
};

// The main object (0x9C bytes, the temp#1 slot stride), used through struct X4_MainObj and SP_CUR_MAIN_OBJ
// by 143 src/ files (e.g. src/rock_11/800E9B90.c, src/rock_45/800FA000.c).
// DC7 notes (each struct): `+0xNN read by|written by <fn>|unreferenced`, held to the census by objfields.py --check.
struct MainObj {
    s8 active; // +0x00 read by func_8004D318
    s8 id; // +0x01 read by func_800312DC
    s8 unk2; // +0x02 read by clamp_player_to_ceiling
    s8 on_screen; // +0x03 read by func_800EB098
    s8 state; // +0x04 read by clamp_player_to_ceiling
    s8 unk5; // +0x05 read by func_800324C8
    s8 unk6; // +0x06 read by func_800324C8
    s8 unk7; // +0x07 read by func_800EA2E0
    X4_f32 x_pos; // +0x08 read by func_8002FD3C
    X4_f32 y_pos; // +0x0C read by func_8002FD3C
    void* backref; // +0x10 read by func_800EBEE8
    s8 bg_offset; // +0x14 read by func_8002FD3C
    u8 unk15; // +0x15 read by func_8002D230
    u8 unk16; // +0x16 written by func_80041290
    u8 unk17; // +0x17 read by func_800F167C
    X4_f32 unk18; // +0x18 read by func_800324C8
    X4_f32 unk1C; // +0x1C read by clamp_player_to_ceiling
    s32 x_speed; // +0x20 read by func_8002D230
    s32 y_speed; // +0x24 read by func_8002D230
    s32 x_accel; // +0x28 read by func_8002D230
    s32 gravity; // +0x2C read by func_8002D230
    const u8* const* animation_table; // +0x30 read by func_80042A9C
    const u8* animation_cursor; // +0x34 unreferenced
    s16 animation_speed; // +0x38 unreferenced
    u8 pad3A[2]; // +0x3A unreferenced
    const u8* sprite_frames; // +0x3C read by func_80042A9C
    u16 unk40; // +0x40 read by func_80042A9C
    u16 unk42; // +0x42 read by func_80042A9C
    union X4_AnimationStep animation_step; // +0x44 read by func_8003674C
    u8 previous_animation_index; // +0x48 unreferenced
    s8 pad49[2]; // +0x49 unreferenced
    s8 unk4B; // +0x4B unreferenced
    s8 pad4C[4]; // +0x4C unreferenced
    const void* attack_box; // +0x50 read by func_800EBA64
    const void* hurt_box; // +0x54 read by func_80040800
    const void* collision_data; // +0x58 written by func_80041290
    s8 hp; // +0x5C read by func_800EFE14
    s8 unk5D; // +0x5D unreferenced
    s8 unk5E; // +0x5E unreferenced
    s8 drain_hold_timer; // +0x5F unreferenced
    s8 contact_damage; // +0x60 written by func_80040800
    s8 invincibility_timer; // +0x61 read by func_80040388
    s8 unk62; // +0x62 written by func_800EE8C8
    s8 unk63; // +0x63 read by func_80040388
    s8 unk64; // +0x64 unreferenced
    s8 unk65; // +0x65 unreferenced
    s8 unk66; // +0x66 read by func_80032208
    s8 air_state; // +0x67 read by func_800EB634
    struct X4_Unk_unk68* terrain_box; // +0x68 read by collide_solid_object
    s16 unk6C; // +0x6C written by func_8002FE30
    s16 unk6E; // +0x6E written by func_8002FE30
    u8 collision_flags; // +0x70 read by func_800EB5D4
    s8: 8; // +0x71 unreferenced
    s8 unk72; // +0x72 read by collide_solid_object
    s8 unk73; // +0x73 read by collide_solid_object
    s8 unk74; // +0x74 unreferenced
    s8 unk75; // +0x75 written by init_capsule
    s8 unk76; // +0x76 read by collide_solid_object
    s8 unk77; // +0x77 read by collide_solid_object
    s8 unk78; // +0x78 unreferenced
    s8 unk79; // +0x79 unreferenced
    s8 unk7A; // +0x7A unreferenced
    u8 unk7B; // +0x7B unreferenced
    s16 unk7C; // +0x7C read by func_80041FB0
    s16 unk7E; // +0x7E read by func_800F01FC
    union X4_MainObjExt ext; // +0x80 read by func_80053620
};

#endif /* MMX6_OBJECT_H */
