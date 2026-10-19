#include "common.h"
#include "mmx6/x4.h"

extern void (*D_8007606C[])(struct X4_ObjectHeader*);
extern struct X4_BackgroundObj D_800971F8[3];

void func_8004202C(struct X4_ObjectHeader* self) {
    if (self->x_pos.i.hi < D_800971F8[0].x_pos.i.hi + 0x10 ||
        D_800971F8[0].x_pos.i.hi + 0x130 < self->x_pos.i.hi ||
        self->y_pos.i.hi < D_800971F8[0].y_pos.i.hi + 0x10 ||
        D_800971F8[0].y_pos.i.hi + 0xE0 < self->y_pos.i.hi) {
        self->unk5 = 2;
        self->unk6 = 0;
        return;
    }
    D_8007606C[self->unk6](self);
}
