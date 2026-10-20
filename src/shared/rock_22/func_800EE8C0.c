#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0();
s32 func_8002D354(void* arg0, s32 arg1, s32 arg2);
void func_8002D3B4(void*, s32);
extern struct X4_PlayerObj D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

void func_800EE8C0(struct X4_MainObj* self) {
    struct X4_PlayerObj* pl;
    s32 v;
    s32 dx;

    func_80017A04();
    func_8002D2B0(self);
    pl = &D_800970A0;
    func_8002D3B4(
        self,
        func_8002D354(self, pl->x_pos.val, pl->y_pos.val + 0xFFB00000) & 0xFF);
    v = self->x_speed + self->x_speed / 2;
    self->x_speed = v;
    v = (v < 0 ? -v : v) + 0x20000;
    dx = pl->x_pos.val - self->x_pos.val;
    if (dx < 0) {
        dx = self->x_pos.val - pl->x_pos.val;
    }
    if (v >= dx || --self->unk7C == 0) {
        self->unk5 = 3;
        self->unk6 = 0;
    }
}
#undef D_800970A0
