#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);
extern s16 D_800F4480;

void func_800EF9B8(struct X4_MainObj* self) {
    u8 mode = SCRATCH_4C[0x8B];

    if (mode == 1) {
        if (self->y_speed > 0) {
            if (self->y_pos.i.hi <= D_800F4480 + 0x3D8) {
                self->y_pos.i.hi = D_800F4480 + 0x3D8;
                self->unk6++;
                return;
            }
        } else if (self->y_pos.i.hi >= D_800F4480 + 0x3D8) {
            self->y_pos.i.hi = D_800F4480 + 0x3D8;
            self->unk6++;
            return;
        }
    } else if (mode == 2) {
        if (self->y_speed > 0) {
            if (self->y_pos.i.hi <= D_800F4480 + 0x438) {
                self->y_pos.i.hi = D_800F4480 + 0x438;
                self->unk6++;
                return;
            }
        } else if (self->y_pos.i.hi >= D_800F4480 + 0x438) {
            self->y_pos.i.hi = D_800F4480 + 0x438;
            self->unk6++;
            return;
        }
    }
    ((void (*)(void*))func_80017A04)(self);
    ((void (*)(s32))func_8002D2B0)((s32)self);
}
