// prog SLUS_013.95 | system object | range -
/* mmx6/class4.h -- one slot of the class-4 object pool g_class4_slots (0x50 x 0xA4 bytes; docs/types/object.md: not
 * struct MainObj) (hand-edited; Phase 2.5 T9.c1). Members only where our readers touch them:
 * alloc_class4_slot clears +0x50/+0x54/+0x68 as enemy_slot_alloc clears MainObj's boxes there (names after MainObj);
 * enemy_slot_alloc clears bit (slot % 32) of word (slot / 32) of +0x98 in every class-4 slot when it hands out
 * g_enemies[slot]. */
#ifndef MMX6_CLASS4_H
#define MMX6_CLASS4_H

#include "common.h"

struct Class4Obj {
    s8 active; // +0x00 read by alloc_class4_slot
    s8 pad01[0x0A - 0x01]; // +0x01 cleared by alloc_class4_slot
    s16 x; // +0x0A read by func_8002E84C
    s8 pad0C[0x0E - 0x0C]; // +0x0C cleared by alloc_class4_slot
    s16 y; // +0x0E read by func_8002E84C
    s8 pad10[0x15 - 0x10]; // +0x10 cleared by alloc_class4_slot
    u8 dir; // +0x15 read by func_8002E84C
    s8 pad16[0x50 - 0x16]; // +0x16 cleared by alloc_class4_slot
    const void* attack_box; // +0x50 written by alloc_class4_slot
    const void* hurt_box; // +0x54 written by alloc_class4_slot
    s8 pad58[0x68 - 0x58]; // +0x58 cleared by alloc_class4_slot
    void* terrain_box; // +0x68 written by alloc_class4_slot
    s8 pad6C[0x72 - 0x6C]; // +0x6C cleared by alloc_class4_slot
    s8 unk72; // +0x72 written by update_player_damage
    s8 pad73[0x76 - 0x73]; // +0x73 cleared by alloc_class4_slot
    s8 unk76; // +0x76 written by update_player_damage
    s8 pad77[0x98 - 0x77]; // +0x77 cleared by alloc_class4_slot
    s32 enemy_bits[2]; // +0x98 one bit per g_enemies slot, cleared by enemy_slot_alloc
    s8 padA0[0xA2 - 0xA0]; // +0xA0 cleared by alloc_class4_slot
    s8 alive; // +0xA2 read by func_8002E84C
    s8 padA3[0xA4 - 0xA3]; // +0xA3 cleared by alloc_class4_slot
};

#endif /* MMX6_CLASS4_H */
