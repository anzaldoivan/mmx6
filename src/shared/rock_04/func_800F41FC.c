// rolefeed (3.1 T4): func_800F41FC of src/rock_04/E9860.c

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5488(struct X4_MainObj* self);

void func_800F41FC(struct X4_MainObj* self) {
    func_800F5488(self);
    ((void (*)(void*, s32))set_animation)(self, 0x13);
    self->action_phase++;
}
