#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F55A8(void*);

extern M2C_UNK D_8007433C;
extern u8 D_800FC8D0[];
extern u8 D_800FC8D8[];

void func_800F461C(struct X4_PlayerObj* self) {
    struct X4_PlayerObj* parent;
    s8 kind;

    self->state++;
    self->on_screen = 1;
    self->hp = 1;
    self->unk60 = 6;
    self->unk50 = D_800FC8D0;
    self->unk58 = &D_8007433C;
    self->unk68 = (void*)D_800FC8D8;
    self->unk54 = D_800FC8D0;
    kind = self->unk2;
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = 0;
    self->unk2C = 0;
    self->unk42 &= 0x7FFF;
    parent = M2C_FIELD(self, struct X4_PlayerObj**, 0x7C);
    if (kind == 0) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0x20;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0x20;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi - 8;
    } else if (kind == 1) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0x1D;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0x1D;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi + 0xE;
    } else {
        if (self->unk15 == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0xC;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0xC;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi + 0x12;
    }
    set_animation(self, 3);
    func_800F55A8(self);
    M2C_FIELD(self, s32*, 0x84) = 0x10;
    M2C_FIELD(self, s32*, 0x8C) = 0;
}
