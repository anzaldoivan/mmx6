/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_19_surface_hopper.c:surface_hopper_crawl, AGPL-3.0; proven shared with X6 by exact signature 6c2ea09cdb15 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_800FC6A8[])(struct X4_MainObj*);

void func_800F3C64(struct X4_MainObj* self) {
    self->unk7C++;
    D_800FC6A8[self->unk6](self);
}
