#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50();
extern u8 D_800F0B44[];
extern s32 D_800F0BF0;

#define SPAD20 (*(s32**)0x1F800020)
#define F_S16(o) M2C_FIELD(self, s16*, (o))
#define F_S32(o) M2C_FIELD(self, s32*, (o))
#define F_U8(o) M2C_FIELD(self, u8*, (o))
#define F_PTR(o) M2C_FIELD(self, void**, (o))

void func_800ED96C(struct X4_BaseObj* self) {
    s32 off;
    u8* e;
    u8 v;
    u8* t;

    F_PTR(0x30) = &D_800F0BF0;
    self->bg_offset = -1;
    self->unk16 = 3;
    self->unk15 = 0;
    F_S16(0x40) = 0x1800;
    self->state++;
    F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[0];
    t = D_800F0B44;
    off = (u8)self->unk2 * 6;
    e = off + t;
    v = e[5];
    F_S16(0x42) = (v & 0xF) | (((v >> 4) + 0x1E0) << 6);
    F_S32(8) = *(s16*)e << 16;
    F_S32(0xC) = ((s16*)(D_800F0B44 + off))[1] << 16;
    F_U8(0x47) = e[4];
    func_8002CB50(self);
}
