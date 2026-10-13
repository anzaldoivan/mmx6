#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);

void func_80051924(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* p = &D_800970A0;
    s16 d;
    register s32 dx asm("$2");

    d = p->x_pos.i.hi - arg0->x_pos.i.hi;
    if (d < 0) {
        d = -d;
    }
    if (d < 0x41) {
        d = p->y_pos.i.hi - arg0->y_pos.i.hi;
        if (d > 0) {
            if (d >= 0x11) {
                return;
            }
        } else {
            d = -d;
            if (d >= 0x69) {
                return;
            }
        }
        func_800179A4(arg0, 0xA);
        dx = p->x_pos.val;
        dx -= arg0->x_pos.val;
        if (dx > 0) {
            func_8003D308(0x14, 0);
            dx = 0x40;
            arg0->unk15 = dx;
        } else {
            func_8003D308(0x14, 0x40);
            arg0->unk15 = 0;
        }
        D_800CCED0.unk16 = 1;
        D_800CCED0.unk12 = 1;
        D_800CCED0.unk13 = 1;
        D_800CCED0.unk17 = 1;
        arg0->unk6 = 0;
        arg0->unk5++;
    }
}
