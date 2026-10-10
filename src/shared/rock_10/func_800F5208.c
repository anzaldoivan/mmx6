#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;
void func_800F5208(struct X4_AnimatedObj* self) {
    s8 mode = ((s8*)self)[0x45];
    s16 x;

    if (mode == 1) {
        if (D_800970A0.x_pos.i.hi <= D_800971F8[0].x_pos.i.hi + 0xA0) {
            self->unk15 = 0;
            x = D_800970A0.x_pos.i.hi - 0x30;
            if (x - D_800971F8[0].x_pos.i.hi < 0x28) {
                x = D_800971F8[0].x_pos.i.hi + 0x28;
            }
            self->x_pos.i.hi = D_800971F8[0].x_pos.i.hi + 0x140 -
                               (x - D_800971F8[0].x_pos.i.hi);
        } else {
            self->unk15 = 0x40;
            x = D_800970A0.x_pos.i.hi + 0x30;
            if (x - D_800971F8[0].x_pos.i.hi > 0x108) {
                x = D_800971F8[0].x_pos.i.hi + 0x108;
            }
            self->x_pos.i.hi = D_800971F8[0].x_pos.i.hi + 0x140 -
                               (x - D_800971F8[0].x_pos.i.hi);
        }
        self->y_pos.i.hi = D_800971F8[0].y_pos.i.hi + 0x30;
        if (func_8002D2D4() & 1) {
            self->y_pos.i.hi = D_800971F8[0].y_pos.i.hi + 0x30;
        } else {
            self->y_pos.i.hi = D_800971F8[0].y_pos.i.hi + 0xA0;
        }
        func_800179A4(self, 0xE);
        {
            register s32* a asm("$2") = &D_800FC734;
            register s32* b asm("$3") = &D_800FC738;
            *(s32**)((u8*)self + 0x50) = a;
            *(s32**)((u8*)self + 0x54) = b;
        }
        self->unk7 = 3;
        self->unk6++;
    } else if (mode == 2) {
        func_80016C48(2, 0x59, self);
    }
}
