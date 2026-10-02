/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_61_ride_armor_punch.c:ride_armor_punch_main, AGPL-3.0; proven shared with X6 by exact signature e7d22a6ee35c (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern u8 D_80076254[][4];
extern u8 D_80076270[8];
extern u8 D_80076278[8];
M2C_UNK func_8002C9B0();

void func_8004672C(struct X4_WeaponObj* self) {
    s8 index;
    s8 event;
    u16 timer;
    struct X4_PlayerObj* owner;

    owner = self->owner;
    self->x_pos.i.hi = (s16)(u16)owner->x_pos.i.hi;
    self->y_pos.i.hi = (s16)(u16)owner->y_pos.i.hi;
    self->animation_step.fields.event =
        (owner->animation_step.fields.event >> 4) & 0xF;
    if (self->unk2 != 0) {
        timer = --self->unk88.half;
        if ((timer << 16) == 0) {
            self->unk88.half = 6;
            self->unk64 = (u8)self->unk64 + 1;
        }
    }
    index = self->unk2;
    if ((D_80076270[index] == owner->unk17) &&
        (D_80076278[index] == owner->unk5) && (owner->state == 1)) {
        event = self->animation_step.fields.event;
        if (event == 0) {
            self->unk50 = NULL;
            return;
        }
        self->unk50 = &D_80076254[event];
        return;
    }
    func_8002C9B0(OBJECT_HEADER(self));
}
