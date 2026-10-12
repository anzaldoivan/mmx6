#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
extern u16 D_800F447E;
#define D_800F447E (*(s16*)&D_800F447E)

void func_800F0318(struct X4_MainObj* self) {
    s16 x;

    self->on_screen = 1;
    if (!(D_80097420 & 1)) {
        D_800971F8[0].y_pos.u.hi += 2;
    } else {
        D_800971F8[0].y_pos.u.hi -= 2;
    }
    func_8002D2B0(self);
    ((void (*)(void*))func_80017A04)(self);
    x = self->x_pos.i.hi;
    if (D_800F447E + 0x1220 < x) {
        self->x_speed = 0xFFF80000;
        self->unk15 = 0;
        self->unk7C = 0x32;
        func_80029478(0x78, 4, 2);
        {
            register s32 t asm("$2") = (u8)self->unk6 - 1;
            self->unk6 = t;
        }
    } else if (x < D_800F447E + 0xF80) {
        self->x_speed = 0x80000;
        self->unk15 = 0x40;
        self->unk7C = 0x32;
        func_80029478(0x78, 4, 2);
        {
            register s32 t asm("$2") = (u8)self->unk6 - 1;
            self->unk6 = t;
        }
    }
}
#undef D_800F447E
