#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

void func_800F7E24(struct X4_AnimatedObj* self) {
    struct X4_BackgroundObj* bg;
    // !FAKE: depin: dropping it breaks the match (43/55)
    register s32 x asm("$3");
    s32 u;
    s32 c;
    s32 d;
    s32 lim;
    s8 ev = self->animation_step.fields.event;

    if (ev == 1) {
        func_80016C48(2, 0x59, self);
        func_800179A4(self, 0xC);
        d = D_800970AA;
        bg = background_objects;
        lim = bg->x_pos.i.hi + 0xA0;
        c = d < lim;
        u = bg->x_pos.u.hi;
        if (c) {
            x = u + 0x100;
        } else {
            x = u + 0x40;
        }
        self->x_pos.i.hi = x;
        self->y_pos.i.hi = bg->y_pos.i.hi + 0x50;
        do {
            func_800F9E04(self);
        } while (0);
        self->unk6++;
    } else if (ev == 2) {
        func_80016C48(2, 0x59, self);
    } else if (ev == 3) {
        func_80016C48(2, 0x51, self);
    }
}
