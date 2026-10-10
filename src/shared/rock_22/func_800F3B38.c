/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_19_surface_hopper.c:surface_hopper_update, AGPL-3.0; proven shared with X6 by exact signature a46c53ea4229 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_800FC674[])(struct X4_MainObj*);
extern void (*D_800FC680[])(struct X4_MainObj*);

void func_800F3B38(struct X4_MainObj* self) {
    if (self->unk2 < 3) {
        D_800FC674[self->state](self);
    } else {
        D_800FC680[self->state](self);
    }
}
