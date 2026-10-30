#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);

void func_800F04E0(struct X4_BaseObj* self) {
    struct X4_BaseObj* parent;
    s32 v;
    s8 step;

    parent = *(struct X4_BaseObj**)((u8*)self + 0x7C);
    if (parent->on_screen != 0 && *(s32*)((u8*)parent + 0x54) != 0) {
        step = self->unk6;
        if (step == 0) {
            v = self->unk15;
            if (v != 0) {
                v = 0xC0000;
            } else {
                v = 0xFFF40000;
            }
            *(s32*)((u8*)self + 0x20) = v;
            goto next;
        } else if (step == 1) {
            if (self->unk15 == 0) {
                if (*(s16*)((u8*)self + 0x8C) - 0x84 >= self->x_pos.i.hi) {
                    self->x_pos.i.hi = *(s16*)((u8*)self + 0x8C) - 0x84;
                } else {
                    move_object(self);
                }
            } else if (self->x_pos.i.hi >= *(s16*)((u8*)self + 0x8C) + 0x84) {
                self->x_pos.i.hi = *(s16*)((u8*)self + 0x8C) + 0x84;
            } else {
                move_object(self);
            }
            if (parent->unk6 == 1) {
                set_animation(self, 0x3F);
            next:
                self->unk6++;
            }
            return;
        } else if (step == 2) {
            if (*(s8*)((u8*)self + 0x45) == 1) {
                goto off;
            }
        }
        return;
    }
off:
    self->on_screen = 0;
    self->state++;
}
