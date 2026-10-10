#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D230(void*);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F5A60(void* arg0) {
    struct X4_MainObj* self = arg0;
    s16 x;

    ((void (*)(void*))func_8002D230)(arg0);
    if (D_800971F8[0].unk22 - 0x40 >= self->y_pos.i.hi) {
        self->y_pos.i.hi = D_800971F8[0].unk22 - 0x40;
        if (self->unk15 != 0) {
            x = D_800971F8[0].unk1C + 0x100;
            self->unk15 = 0;
            self->x_pos.i.hi = x;
        } else {
            x = D_800971F8[0].unk1E + 0x40;
            self->unk15 = 0x40;
            self->x_pos.i.hi = x;
        }
        self->unk7C = 0x32;
        self->x_speed = 0;
        self->y_speed = 0;
        self->gravity = 0;
        self->unk6++;
    }
}
