#include "common.h"
#include "mmx6/x4.h"

void func_800ED1CC(u8* arg0);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FBEC0[];
extern u8 D_800FBEC8[];
extern u8 D_800FBED0[];
extern u8 D_800FBED8[];
extern u8 D_800FBEE0[];
extern u8 D_800FBEE8[];
extern u8 D_800FBEF0[];

void func_800EA7C8(struct X4_AnimatedObj* self) {
    struct X4_BackgroundObj* bg;

    switch (self->unk2 & 0xF) {
    case 0: {
        bg = &background_objects[0];
        if (bg->x_pos.i.hi < self->x_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBEC8);
        bg->unk26 = self->x_pos.u.hi + 0x10;
        self->unk6++;
        return;
    }
    case 1: {
        bg = &background_objects[0];
        if (bg->x_pos.i.hi < self->x_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBED0);
        bg->unk26 = self->x_pos.u.hi + 0x10;
        self->unk6++;
        return;
    }
    case 2: {
        bg = &background_objects[0];
        if (bg->x_pos.i.hi < self->x_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBED8);
        bg->unk26 = self->x_pos.u.hi + 0x10;
        self->unk6++;
        return;
    }
    case 3: {
        bg = &background_objects[0];
        if (bg->x_pos.i.hi < self->x_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBEE0);
        bg->unk26 = self->x_pos.u.hi + 0x10;
        self->unk6++;
        return;
    }
    case 4: {
        bg = &background_objects[0];
        if (bg->y_pos.i.hi < self->y_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBEE8);
        func_80027BA0(0, 0x1250, 0x1C0, D_800FBEC0);
        bg->unk26 = 0xF00;
        bg->unk2A = self->y_pos.u.hi + 0x20;
        bg->unk28 = self->y_pos.u.hi + 0x20;
        self->unk6++;
        return;
    }
    case 5: {
        bg = &background_objects[0];
        if (bg->y_pos.i.hi < self->y_pos.i.hi + 0x10) {
            return;
        }
        func_800ED1CC(D_800FBEF0);
        func_80027BA0(0, 0xF30, 0x2C0, D_800FBEC0);
        bg->unk2A = self->y_pos.u.hi + 0x20;
        bg->unk28 = self->y_pos.u.hi + 0x20;
        self->unk6++;
        return;
    }
    }
}
