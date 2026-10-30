#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
s32 random_byte();
void func_800F2B4C();
extern s32 D_800F4144;
extern s16 D_800F4480;

void func_800F28AC(struct X4_BaseObj* self) {
    ((void (*)())func_800F2B4C)();
    ((void (*)(void*))func_80017A04)(self);
    ((void (*)(void*))move_object)(self);
    if (F16(self, 0xE) < D_800F4480 + 0x3E0) {
        FP(self, 0x68) = &D_800F4144;
    }
    if (FU8(self, 0x70) & 4) {
        if (!(random_byte() & 3)) {
            SPAD[0x89]++;
            self->unk5 = 4;
            self->unk6 = 0;
            return;
        }
        self->unk6++;
        ((void (*)(void*, s32))set_animation)(self, 0);
        F16(self, 0x7C) = 0x3C;
    }
}
