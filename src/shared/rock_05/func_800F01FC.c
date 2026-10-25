#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002D2D4();
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
extern s16 D_800F4480;

void func_800F01FC(struct X4_MainObj* self) {
    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (!(D_80097420 & 1)) {
        background_objects[0].y_pos.u.hi += 2;
    } else {
        background_objects[0].y_pos.u.hi -= 2;
    }
    if (self->unk7E != 0) {
        if (self->unk7E == 3) {
            func_80016C48(2, 0x24, self);
        }
        self->unk7E--;
        self->unk6++;
        func_80016C48(2, 0xF, self);
        func_80012D9C(3);
        if (func_8002D2D4() & 1) {
            self->y_pos.u.hi = D_800F4480 + 0x450;
            return;
        }
        self->y_pos.u.hi = D_800F4480 + 0x3F0;
        return;
    }
    self->unk6 = 5;
    func_80029478(1, 4, 2);
}
