#include "common.h"
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

void func_800E9D68(struct X4_BaseObj* self) {
    struct X4_BaseObj* p;
    s8 t;

    p = *(struct X4_BaseObj**)(SPAD + 0x80);
    t = p->state;
    if (t == 2) {
        self->unk5 = 5;
        self->unk6 = 0;
        return;
    }
    if (t == 3) {
        self->state = 4;
        return;
    }
    if (*((u8*)p + 0x88) == 1) {
        self->unk5 = 4;
        self->unk6 = 0;
    }
    if (p->unk15 == 0) {
        switch (self->unk2) {
        case 16:
            self->x_pos.u.hi = p->x_pos.u.hi - 0x10;
            self->y_pos.u.hi = p->y_pos.u.hi - 0x20;
            break;
        case 17:
            self->x_pos.u.hi = p->x_pos.u.hi - 0x10;
            self->y_pos.u.hi = p->y_pos.u.hi + 0x20;
            break;
        case 18:
            self->x_pos.u.hi = p->x_pos.u.hi - 0x20;
            self->y_pos.u.hi = p->y_pos.u.hi - 0x40;
            break;
        case 19:
            self->x_pos.u.hi = p->x_pos.u.hi - 0x20;
            self->y_pos.u.hi = p->y_pos.u.hi + 0x40;
            break;
        }
    } else {
        switch (self->unk2) {
        case 16:
            self->x_pos.u.hi = p->x_pos.u.hi + 0x10;
            self->y_pos.u.hi = p->y_pos.u.hi - 0x20;
            break;
        case 17:
            self->x_pos.u.hi = p->x_pos.u.hi + 0x10;
            self->y_pos.u.hi = p->y_pos.u.hi + 0x20;
            break;
        case 18:
            self->x_pos.u.hi = p->x_pos.u.hi + 0x20;
            self->y_pos.u.hi = p->y_pos.u.hi - 0x40;
            break;
        case 19:
            self->x_pos.u.hi = p->x_pos.u.hi + 0x20;
            self->y_pos.u.hi = p->y_pos.u.hi + 0x40;
            break;
        }
    }
}

#undef SPAD
