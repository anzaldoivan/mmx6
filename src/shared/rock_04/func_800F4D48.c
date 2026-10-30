#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s8 D_800CCF5C;

void func_800F4D48(struct X4_MainObj* self) {
    if (--self->unk7E == 0) {
        play_sound(0, 0xE, 0);
        self->unk7E = 3;
    }
    if (++self->hp == D_800CCF5C) {
        self->unk6++;
    }
}
