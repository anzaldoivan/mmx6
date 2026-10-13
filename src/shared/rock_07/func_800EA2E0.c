#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80029F38();
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800EA2E0(struct X4_MainObj* self) {
    struct X4_MainObj* p;

    p = M2C_FIELD(self, struct X4_MainObj**, 0x88);
    if (p->active != 0) {
        if (p->unk7 == 0) {
            if (--self->unk7E == -1) {
                self->unk7E = 5;
                self->unk42 ^= 0x8000;
            }
        } else {
            self->unk5++;
            {
                s32 t2;
                D_800971F8[0].y_pos.i.hi = 0xE0;
                D_800971F8[1].y_pos.i.hi = 0xE0;
                D_800971F8[2].y_pos.i.hi = 0xE0;
                D_800971F8[0].x_pos.i.hi = 0x1550;
                D_800971F8[2].x_pos.i.hi = 0xAA8;
                D_800971F8[1].x_pos.i.hi = 0x1550;
                D_800971F8[0].unk4C = 1;
                D_800971F8[1].unk4C = 1;
                D_800971F8[2].unk4C = 1;
                t2 = 0x1550;
                D_800971F8[0].unk1E = t2;
                D_800971F8[0].unk26 = t2;
                D_800971F8[0].unk1C = t2;
                D_800971F8[0].unk24 = t2;
                D_800971F8[0].unk22 = 0xE0;
                D_800971F8[0].unk2A = 0xE0;
                D_800971F8[0].unk20 = 0xE0;
                D_800971F8[0].unk28 = 0xE0;
            }
            func_80029F38(0x1520, 0x16C0, 0xB0, 0x200, 0);
            {
                // !FAKE: depin: dropping it breaks the match (62/69)
                register s32 b asm("$2") = 0x18B;
                D_800970A0.x_pos.i.hi = 0x15E4;
                D_800970A0.y_pos.i.hi = b;
                D_800970A0.unk18.i.hi = 0x15E4;
                D_800970A0.unk1C.i.hi = b;
            }
        }
    }
}
