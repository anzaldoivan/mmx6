#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
extern u8 D_80093C98[];
extern struct X4_PlayerObj D_800970A0;

void func_800ECA2C(struct X4_AnimatedObj* self) {
    s32 d;
    s8 v;
    u8* p;
    u32 n;
    register u16 t asm("$2");

    if (self->x_pos.val > D_800970A0.x_pos.val) {
        self->unk15 = 0;
    } else {
        self->unk15 = 0x40;
    }
    func_80017A04(self);
    t = *(u16*)((u8*)self + 0x7C);
    *(u16*)((u8*)self + 0x7C) = t + 1;
    if ((s16)t >= 0x3D) {
        if (self->on_screen != 0) {
            if (D_800970A0.unk2 != 0) {
                d = D_800970A0.x_pos.i.hi - self->x_pos.i.hi;
                if ((d >= 0)
                        ? (d < 0x40)
                        : ((self->x_pos.i.hi - D_800970A0.x_pos.i.hi) < 0x40)) {
                    v = 4;
                } else {
                    v = 3;
                }
                self->unk5 = v;
                n = 0;
                for (p = D_80093C98; p < D_80093C98 + 0x1400; p += 0xA0) {
                    if (*(s8*)p != 0 && (*(s32*)p & 0xFFFF00) == 0x21B00) {
                        n++;
                    }
                }
                if (n >= 4) {
                    self->unk5 = 3;
                }
            } else {
                d = D_800970A0.x_pos.i.hi - self->x_pos.i.hi;
                if ((d >= 0)
                        ? (d < 0x40)
                        : ((self->x_pos.i.hi - D_800970A0.x_pos.i.hi) < 0x40)) {
                    v = 2;
                } else {
                    v = 4;
                }
                self->unk5 = v;
                n = 0;
                for (p = D_80093C98; p < D_80093C98 + 0x1400; p += 0xA0) {
                    if (*(s8*)p != 0 && (*(s32*)p & 0xFFFF00) == 0x21B00) {
                        n++;
                    }
                }
                if (n >= 4) {
                    self->unk5 = 2;
                }
            }
        }
        self->unk6 = 0;
    }
}
