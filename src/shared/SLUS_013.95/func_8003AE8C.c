#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D5D0(void*);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

M2C_UNK func_8003AE8C(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    player_set_animation_shooting(self, 7);
    self->y_vel.val = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    func_8002D5D0(self);
    self->unk5 = 3;
    self->unk6 = 0;
}
