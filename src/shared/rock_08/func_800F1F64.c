#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern s16 D_800F6AF8;

void func_800F1F64(void* arg0) {
    struct X4_MainObj* self = arg0;

    ((void (*)())func_80017A04)();
    ((void (*)(void*))move_object)(self);
    if (self->x_speed > 0) {
        if (D_800F6AF8 + 0x880 < self->x_pos.i.hi) {
            self->unk15 = 0;
            self->unk5 = 3;
            goto block_5;
        }
    } else if (self->x_pos.i.hi < D_800F6AF8 + 0x590) {
        self->unk15 = 0x40;
        self->unk5 = 3;
    block_5:
        self->unk6 = 0;
    }
}
