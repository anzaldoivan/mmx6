/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_19_surface_hopper.c:surface_hopper_probe_tile, AGPL-3.0; proven shared with X6 by exact signature bc88cc45895f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
u8 func_80030234(struct X4_PlayerObj*, s16, s16);

u8 func_800F4094(struct X4_PlayerObj* self, s16 arg1, s16 arg2) {
    arg1 = self->x_pos.i.hi + arg1;
    arg2 = self->y_pos.i.hi + arg2;
    return func_80030234(self, arg1, arg2);
}
