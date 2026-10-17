#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_800F5488(struct X4_MainObj* self);

void func_800F34B4(struct X4_MainObj* self) {
    s32 v;

    func_800F5488(self);
    if (self->animation_step.fields.event == 1) {
        func_80016C48(2, 0x12, self);
        v = 0x40000;
        if (self->unk15 == 0) {
            v = 0xFFFC0000;
        }
        self->x_speed = v;
        do {
        } while (0);
        self->unk6++;
    }
}
