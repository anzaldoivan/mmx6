#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_800CCEDC;
extern u8 D_800F0F88[][3];
extern void (*D_800F0F80[])(s8*);
void func_800F02F4(void*, s32, s32, s32, s32);

#define SPAD20 (*(s32**)0x1F800020)
#define F_U8(o) M2C_FIELD(self, u8*, (o))
#define F_S16(o) M2C_FIELD(self, s16*, (o))
#define F_PTR(o) M2C_FIELD(self, void**, (o))

void func_800EFC78(struct X4_BaseObj* self) {
    s32 t;

    self->on_screen = 0;
    self->unk15 = 0;
    self->active = 1;
    if (*(s8*)&D_800CCEDC == 0xF) {
        F_S16(0x40) = 0x1800;
        F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[2];
    } else {
        F_S16(0x40) = 0x1900;
        F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[2];
    }
    F_PTR(0x30) = &D_800F0F80[2];
    t = self->unk2;
    F_U8(0x47) = 0;
    self->bg_offset = -1;
    self->unk16 = 0;
    self->state = 1;
    self->unk6 = 0;
    switch (t & 0xF0) {
    case 0xF0:
        F_S16(0x42) = 0x7844;
        F_U8(0x47) = 0;
        self->unk5 = 1;
        if (t < 0x14) {
            func_800F02F4(self, 0xE0, 0, 0, 0);
        }
        break;
    case 0xE0:
        F_S16(0x42) = 0x7844;
        F_U8(0x47) = 0;
        self->unk5 = 2;
        break;
    default:
        F_S16(0x42) = (D_800F0F88[(u8)self->unk2][1] & 0xF) |
                      (((D_800F0F88[(u8)self->unk2][1] >> 4) + 0x1E0) << 6);
        F_U8(0x47) = D_800F0F88[(u8)self->unk2][2];
        if (F_U8(0x58) == 0) {
            self->unk5 = D_800F0F88[(u8)self->unk2][0];
        } else {
            self->unk5 = 3;
        }
        break;
    }
}
