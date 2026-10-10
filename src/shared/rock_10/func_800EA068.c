/* Adapted from sozud/mmx4 @29b62af src/main/misc/misc_00_static_sprite.c:spawn_common_effect, AGPL-3.0; proven shared with X6 by exact signature 1d1542c14e9b (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
struct X4_MiscObj* func_8002C530(void);

void func_800EA068(struct X4_MainObj* self, s8 arg1) {
    struct X4_MiscObj* misc;

    misc = func_8002C530();
    if (misc != NULL) {
        misc->active = 0x41;
        misc->id = 1;
        misc->unk2 = arg1;
        misc->unk15 = self->unk15;
        misc->x_pos = self->x_pos;
        misc->y_pos = self->y_pos;
    }
}
