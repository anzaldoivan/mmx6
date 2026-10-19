#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
extern u8 D_800970B5;
extern s16 D_80097206;
extern const u8* const D_800FBC2C[];

void func_800F9BAC(struct X4_MainObj* self) {
    u8 dir;

    self->animation_table = D_800FBC2C;
    dir = D_800970B5;
    self->unk15 = dir;
    if (dir == 0) {
        self->x_pos.i.hi += 0x60;
    } else {
        self->x_pos.i.hi -= 0x60;
    }
    {
        s32 y = (u16)D_80097206;
        self->unk16 = 3;
        self->y_pos.i.hi = y - 0x20;
    }
    ((void (*)(void*, s32))func_800179A4)(self, 0);
    {
        s32 st = (u8)self->state;
        self->on_screen = 1;
        self->bg_offset = 0;
        self->unk6 = 0x3C;
        self->state = ++st;
    }
}
