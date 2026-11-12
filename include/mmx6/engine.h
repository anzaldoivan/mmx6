// prog SLUS_013.95 | system engine_state | range -
/* mmx6/engine.h -- the playthrough state block g_playthrough_state 0x800CCED0 (hand-edited; Phase 2.6 T14.c8, homed 2.6 T16.c1).
 * Homed here from the generated include/mmx6/x4.h through config/x4/homed.tsv: x4.h never emits the block and
 * aliases X4_EngineObj to EngineObj, so `struct X4_EngineObj` users are unchanged. +0x00..+0x63: members, types and
 * names of mmx4's EngineObj (x4.h at 807a01b). The X6 tail from +0x64 holds the members X6 readers touch; the
 * block's extent is not proven: asm reaches +0x9C, +0xD6, +0x43A and +0x464 off its %lo base (C0322 scan, T14.c8).
 * The extern stays in mmx6/engine_state.h (C0331). */
#ifndef MMX6_ENGINE_H
#define MMX6_ENGINE_H

#include "common.h"
#include "mmx6/x4.h" /* union X4_EngineCharacterState, struct X4_MainObj, X4_PlayerObj, X4_BaseObj */

struct EngineObj {
    s8 state;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s16 unk4;
    s8 unk6;
    s8 unk7;
    s16 unk8;
    s16 unkA;
    s8 stage;
    s8 substage;
    s8 unkE;
    s8 unkF;
    s8 unk10;
    s8 unk11;
    s8 unk12;
    s8 unk13;
    s8 unk14;
    s8 unk15;
    s8 unk16;
    s8 unk17;
    s8 unk18;
    s8 unk19;
    s8 unk1A;
    s8 unk1B;
    s8 gameplay_locked;
    s8 checkpoint;
    s8 unk1E;
    s8 unk1F;
    struct X4_MainObj* boss_ptr;
    s8 enable_boss;
    s8 unk25;
    union X4_EngineCharacterState character_state;
    union {
        s8 value;
        u8 timer;
    } unk36;
    s8 unk37;
    struct X4_PlayerObj* controlled_player;
    struct X4_BaseObj* unk3C;
    u8 unk40;
    s8 unk41;
    u8 unk42;
    s8 cur_character;
    s8 player_lives;
    u8 checkpoint_hp;
    s8 max_hp;
    s8 armor_parts;
    s8 arm_type;
    s8 player_initial_data[0x10];
    s8 palette_flags;
    u16 collected_upgrades;
    s8 sub_tanks[3];
    u8 unk5F;
    u8 unk60;
    u8 pad61[3];
    // X6 tail (past mmx4's 0x64 bytes)
    u8 pad64[0x68 - 0x64];
    u8 unk68; // +0x68 read by func_800472D0
    u8 pad69[0x74 - 0x69];
    s32 unk74[2]; // +0x74 per character, read by load_armor_and_parts
    u8 pad7C[0x98 - 0x7C];
    s32 unk98; // +0x98 added to by update_player_damage
};

#endif /* MMX6_ENGINE_H */
