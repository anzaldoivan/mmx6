#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800EC6AC(struct X4_BaseObj* self) {
    if (*((s8*)self + 0x45) == 1) {
        *(s32*)((u8*)self + 0x54) = 0;
    }
    if (*((s8*)self + 0x45) == 2) {
        set_animation(self, 0);
        play_sound(2, 0x3C, self);
        {
            u8 v = SPAD[0x8B];
            self->unk6 = 0;
            self->unk5 = v;
        }
    }
}
