#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD4C (*(s8**)0x1F80004C)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0(s32);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F3164(void* arg0) {
    struct X4_MainObj* self = arg0;
    s8* p = SPAD4C;

    if (p[0x89] == 0) {
        p[0x89] = 0x78;
    }
    ((void (*)(void*))func_8002D2B0)(arg0);
    if (self->x_speed < 0) {
        if (D_800971F8[0].unk1E + 0x70 >= self->x_pos.i.hi &&
            self->unk15 == 0) {
            self->unk15 = 0x40;
        }
        if (D_800971F8[0].unk1E + 0x40 >= self->x_pos.i.hi) {
            self->x_pos.i.hi = D_800971F8[0].unk1E + 0x40;
            self->unk15 = 0x40;
            ((void (*)(s32, s32, void*))func_80016C48)(2, 0x23, self);
            ((void (*)(void*, s32))func_800179A4)(self, 0x12);
            self->unk6++;
        }
    } else {
        if (self->x_pos.i.hi >= D_800971F8[0].unk1C + 0xD0 &&
            self->unk15 != 0) {
            self->unk15 = 0;
        }
        if (self->x_pos.i.hi >= D_800971F8[0].unk1C + 0x100) {
            self->x_pos.i.hi = D_800971F8[0].unk1C + 0x100;
            self->unk15 = 0;
            ((void (*)(s32, s32, void*))func_80016C48)(2, 0x23, self);
            ((void (*)(void*, s32))func_800179A4)(self, 0x12);
            self->unk6++;
        }
    }
}
