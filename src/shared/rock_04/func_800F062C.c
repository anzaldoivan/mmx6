#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
extern u32* D_80095098;

void func_800F062C(struct X4_PlayerObj* self) {
    s32 a;
    s32 b;

    self->active = 0x49;
    self->unk40 = D_80095098[func_8002A47C(0x90)] >> 7;
    a = func_8002A47C(0x90);
    b = func_8002A47C(0x90);
    self->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    self->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(0x90)];
    self->unk16 = 0x30;
    M2C_FIELD(self, u8*, 0x47) = self->unk2;
    self->state++;
}
