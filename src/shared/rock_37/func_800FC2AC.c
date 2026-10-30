#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
s32 random_byte();

void func_800FC2AC(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 r;

    r = random_byte() & 0xF;
    ((void (*)(void*))func_80017A04)(arg0);
    if (r < 5) {
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        self->unk5 = 5;
        self->unk6 = 0;
        return;
    }
    if (r < 0xA) {
        self->unk5 = 6;
        self->unk6 = 0;
        self->input.buttons.held = 0x5A;
        return;
    }
    ((void (*)(void*))move_object)(arg0);
    self->unk5 = 2;
    self->unk6 = 1;
}
