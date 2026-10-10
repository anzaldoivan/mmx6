/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_hover_set_direction, AGPL-3.0; proven shared with X6 by exact signature 5022eaa90621 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK func_8003F4C4(void*, M2C_UNK);
void func_801EC478(struct X4_PlayerObj* self, s32 direction) {
    if (direction > 0) {
        ((void (*)())func_8003F4C4)(self, 0x17);
        self->unk6 = 3;
    } else {
        ((void (*)())func_8003F4C4)(self, 0x19);
        self->unk6 = 5;
    }
}
