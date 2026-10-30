#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern s8 D_80097244;
extern u8 D_800FB220[];
extern u8 D_800FB230[];

void func_800F09FC(struct X4_MainObj* self) {
    // !FAKE: depin: dropping it breaks the match (64/70)
    register s32 lim asm("$4");
    s32 v;

    v = self->x_speed;
    lim = 0x40000;
    if ((v > lim) || (lim = -0x40000, v < lim)) {
        self->x_speed = lim;
        self->x_accel = 0;
    }
    if (self->unk15 == 0) {
        if (self->collision_flags & 2) {
            goto block_7;
        }
        return;
    }
    if (self->collision_flags & 1) {
    block_7:
        play_sound(2, 5, self);
        ((void (*)(s32))func_80012D9C)(3);
        if (self->collision_flags & 2) {
            func_80027BA0(0, 0x17B0, 0xD0, D_800FB220);
        } else {
            func_80027BA0(0, 0x1930, 0xD0, D_800FB230);
        }
        D_80097244 = 1;
        self->x_speed = 0;
        self->x_accel = 0;
        ((void (*)(s32, s32, s32))func_80029478)(-0x6A, 4, 2);
        self->unk7C = 0;
        self->unk6++;
    }
}
