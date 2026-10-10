#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_800CCEDC;
extern u8 D_800F0C04[][3];
extern void (*D_800F0BF8[])(s8*);

#define SPAD20 (*(s32**)0x1F800020)
#define F_U8(o) M2C_FIELD(self, u8*, (o))
#define F_S8(o) M2C_FIELD(self, s8*, (o))
#define F_S16(o) M2C_FIELD(self, s16*, (o))
#define F_PTR(o) M2C_FIELD(self, void**, (o))

void func_800EDBC8(struct X4_BaseObj* self) {
    u8* tmp;
    register s32 t asm("$4");

    self->on_screen = 0;
    self->unk15 = 0;
    self->active = 1;
    if (*(s8*)&D_800CCEDC == 0xF) {
        F_S16(0x40) = 0x1800;
        F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[0];
    } else {
        F_S16(0x40) = 0x1900;
        F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[1];
    }
    t = self->unk2;
    F_PTR(0x30) = &D_800F0BF8[3];
    self->bg_offset = -1;
    self->unk16 = 4;
    self->state = 1;
    F_U8(0x47) = 0;
    self->unk6 = 0;
    if ((t & 0xF0) == 0xF0) {
        switch ((u8)self->unk2 & 0xF) {
        case 0:
            self->unk5 = 1;
            break;
        case 1:
            self->unk5 = 2;
            break;
        case 2:
            self->unk5 = 3;
            break;
        case 3:
            self->unk5 = 6;
            break;
        case 4:
            self->unk5 = 4;
            break;
        case 5:
            F_U8(0x47) = F_U8(0x55);
            tmp = (u8*)SPAD20 + SPAD20[1];
            self->unk5 = 0;
            F_S16(0x42) = 0x7844;
            F_PTR(0x3C) = tmp;
            break;
        case 7:
            self->unk5 = 8;
            break;
        case 8:
            self->unk5 = 0x12;
            break;
        case 9:
            self->unk5 = 0x13;
            break;
        }
    } else {
        F_S16(0x42) = (D_800F0C04[(u8)self->unk2][1] & 0xF) |
                      (((D_800F0C04[(u8)self->unk2][1] >> 4) + 0x1E0) << 6);
        F_U8(0x47) = D_800F0C04[(u8)self->unk2][2];
        if (F_U8(0x58) == 0) {
            self->unk5 = D_800F0C04[(u8)self->unk2][0];
        } else {
            self->unk5 = 0x10;
        }
    }
}
