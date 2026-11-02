// prog SLUS_013.95 | system object | range -
/* mmx6/class4.h -- one slot of the class-4 object pool D_800C1220 (0x50 x 0xA4 bytes; docs/types/object.md: not
 * struct MainObj) (hand-edited; Phase 2.5 T9.c1). Members only where our readers touch them:
 * alloc_class4_slot clears +0x50/+0x54/+0x68 as enemy_slot_alloc clears MainObj's boxes there (names after MainObj);
 * enemy_slot_alloc clears bit (slot % 32) of word (slot / 32) of +0x98 in every class-4 slot when it hands out
 * g_enemies[slot]. */
#ifndef MMX6_CLASS4_H
#define MMX6_CLASS4_H

#include "common.h"

struct Class4Obj {
    s8 active; // +0x00 read by alloc_class4_slot
    s8 pad01[0x50 - 0x01]; // +0x01 cleared by alloc_class4_slot
    const void* attack_box; // +0x50 written by alloc_class4_slot
    const void* hurt_box; // +0x54 written by alloc_class4_slot
    s8 pad58[0x68 - 0x58]; // +0x58 cleared by alloc_class4_slot
    void* terrain_box; // +0x68 written by alloc_class4_slot
    s8 pad6C[0x98 - 0x6C]; // +0x6C cleared by alloc_class4_slot
    s32 enemy_bits[2]; // +0x98 one bit per g_enemies slot, cleared by enemy_slot_alloc
    s8 padA0[0xA4 - 0xA0]; // +0xA0 cleared by alloc_class4_slot
};

#endif /* MMX6_CLASS4_H */
