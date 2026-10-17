#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8009725A;
extern s16 D_800F4480;
extern s16 D_800F4484;

void func_800F2C60(struct X4_MainObj* self) {
    if (self->unk2 == 3) {
        self->y_pos.i.hi =
            D_800F4480 - (s16)((D_8009725A - D_800F4484) - 0xDD8);
        return;
    }
    {
        s16* p = &D_800F4484;
        s32 a = D_8009725A;
        self->y_pos.i.hi = D_800F4480 + (s16)((*p - a) + 0xF18);
    }
}
