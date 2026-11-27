// rolefeed (3.1 T4): func_800EC4C8 of src/rock_09/E9860.c
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;

void func_800E9970(s8* self, s8* parent);
void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1);

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_32_bomb_bat.c:bomb_bat_drop_start, AGPL-3.0; proven shared with X6 by exact signature 32f9f02b5c88 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_Unk_unk68 D_800F5F04;
s32 set_animation(void*, s32);

void func_800EC4C8(struct X4_MainObj* self) {
    set_animation(self, 1);
    self->x_speed = 0;
    self->ext.main_32.unk80 = 5;
    self->hurt_box = (const u8*)&D_800F5F04;
    self->attack_box = (const u8*)&D_800F5F04;
    self->action_phase++;
}
