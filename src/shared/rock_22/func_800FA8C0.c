#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_8002F288(M2C_UNK*);
extern void (*D_800FD584[])(struct X4_MainObj*);

void func_800FA8C0(struct X4_MainObj* self) {
    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    D_800FD584[self->state](self);
    func_8002F288((M2C_UNK*)self);
    self->on_screen = 0;
}
