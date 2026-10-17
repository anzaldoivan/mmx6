#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK func_8002C9D4();
extern struct X4_RideArmorObj D_800CD340;

void func_800EE158(struct X4_MainObj* self) {
    self->state = 1;
    self->unk5 = 0;
    D_800CD340.active = 0x41;
    D_800CD340.id = self->unk2;
    D_800CD340.state = 0;
    D_800CD340.unk5 = 0;
    D_800CD340.unk6 = 0;
    D_800CD340.unk7 = 0;
    D_800CD340.unk2 = self->unk2;
    D_800CD340.backref = self->backref;
    *(s32*)&D_800CD340.x_pos = *(s32*)&self->x_pos;
    *(s32*)&D_800CD340.y_pos = *(s32*)&self->y_pos;
    func_8002C9D4();
}
