#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
s32 func_800F2FB8(void*, u8, s32);
extern s32 D_800FC62C[];
extern u8 D_800FC6C4[];
extern u8 D_800FC6C8[];

void func_800F26C0(struct X4_BaseObj* self) {
    s32 anim;

    if (SPAD[0x81] < 2) {
        if (SPAD[0x81] == 0) {
            self->unk15 = 0x40;
            SPAD[0x82] = 1;
        } else {
            self->unk15 = 0;
            SPAD[0x82] = 2;
        }
        F16(SPAD, 0x84) = (func_8002D2D4() & 1) ? 0x50 : 0x20;
        if (func_800F2FB8(self, SPAD[0x80], 0) != 0) {
            SPAD[0x80] ^= 1;
        }
        anim = D_800FC6C4[SPAD[0x80]];
        F16(SPAD, 0x8A) = 0x15;
    } else {
        F16(SPAD, 0x84) = (func_8002D2D4() & 1) ? 0x40 : 0x20;
        if (func_800F2FB8(self, SPAD[0x80], 1) != 0) {
            SPAD[0x80] ^= 1;
        }
        anim = 2;
        self->unk15 = D_800FC6C8[SPAD[0x80]];
        F16(SPAD, 0x8A) = 0x17;
        SPAD[0x82] = 4;
    }
    {
        register s32 v asm("$6");

        v = D_800FC62C[(s8)self->unk2 >> 1];
        F32(self, 0x68) = v;
        ((void (*)(void*, s32, s32))func_800179A4)(self, anim, v);
    }
    self->unk6 = 1;
    F16(SPAD, 0x86) = F16(self, 0xA);
    F16(SPAD, 0x88) = F16(self, 0xE);
}
