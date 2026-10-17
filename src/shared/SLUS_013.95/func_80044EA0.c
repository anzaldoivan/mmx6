#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8002F288(struct X4_PlayerObj*);
extern void (*D_80076170[])(struct X4_PlayerObj*);
extern struct X4_PlayerObj D_800970A0;

void func_80044EA0(struct X4_PlayerObj* self) {
    struct X4_PlayerObj* p = &D_800970A0;
    s32 flag;

    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    flag = ((s8*)p)[0xD3] != 0;
    if (((s8*)p)[0xD4] != 0) {
        flag = 1;
    }
    if (p->unk2 == 0) {
        if (p->weapon != 4) {
            flag = 1;
        }
        if (p->shot_type == 0xD) {
            flag = 1;
        }
    }
    if (flag != 0) {
        self->state = 2;
    }
    self->shot_fired = self->unk70 | self->unk71;
    D_80076170[self->state](self);
    func_8002F288((M2C_UNK*)self);
    self->unk71 = 0;
}
