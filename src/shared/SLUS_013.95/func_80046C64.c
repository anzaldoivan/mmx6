/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_62_flame_jet.c:flame_jet_update, AGPL-3.0; proven shared with X6 by exact signature 38e1a722ce8e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_800762A0[])(struct X4_MainObj*);

void func_80046C64(struct X4_MainObj* self) {
    self->on_screen = 0;
    D_800762A0[self->state](self);
}
