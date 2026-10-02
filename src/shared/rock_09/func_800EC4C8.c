/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_32_bomb_bat.c:bomb_bat_drop_start, AGPL-3.0; proven shared with X6 by exact signature 32f9f02b5c88 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_Unk_unk68 D_800F5F04;
s32 func_800179A4(void*, s32);

void func_800EC4C8(struct X4_MainObj* self) {
    func_800179A4(self, 1);
    self->x_speed = 0;
    self->ext.main_32.unk80 = 5;
    self->hurt_box = (const u8*)&D_800F5F04;
    self->attack_box = (const u8*)&D_800F5F04;
    self->unk6++;
}
