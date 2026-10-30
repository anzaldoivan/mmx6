#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern s16 D_8009721E;

void func_800F38B4(struct X4_MainObj* self) {
    u8 r;

    self->unk7C--;
    if (self->unk7C == 0) {
        play_sound(2, 0x11, self);
        r = (u32)random_byte() % 3;
        switch (r) {
        case 0:
            play_sound(2, 0x22, self);
            break;
        case 1:
            play_sound(2, 0x23, self);
            break;
        case 2:
            play_sound(2, 0x24, self);
            break;
        }
        ((void (*)(void*, s32))set_animation)(self, 0xA);
        if (self->x_pos.i.hi < D_8009721E + 0xC0) {
            *(s16*)((u8*)self + 0x84) = 0x170;
        } else {
            *(s16*)((u8*)self + 0x84) = 0x10;
        }
        *(s16*)((u8*)self + 0x86) = 0x80;
        self->unk6++;
    }
}
