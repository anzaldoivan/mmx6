// rolefeed (3.1 T4): func_800F1F64 of src/rock_08/E9860.c

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_08.h"

M2C_UNK animate_object();
void move_object();

void func_800F1F64(void* arg0) {
    struct X4_MainObj* self = arg0;

    ((void (*)())animate_object)();
    ((void (*)(void*))move_object)(self);
    if (self->x_speed > 0) {
        if (D_800F6AF8 + 0x880 < self->x_pos.i.hi) {
            self->unk15 = 0;
            self->action = 3;
            self->action_phase = 0;
        }
    } else if (self->x_pos.i.hi < D_800F6AF8 + 0x590) {
        self->unk15 = 0x40;
        self->action = 3;
        self->action_phase = 0;
    }
}
