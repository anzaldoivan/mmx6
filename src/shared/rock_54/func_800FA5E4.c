#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCF08;

void func_800FA5E4(struct X4_BackgroundObj* arg0) {
    // !FAKE: pin the first store value to the first return register
    register s32 var_v0 asm("$2");
    s32 var_v1;
    s32 temp_v0;
    struct X4_BackgroundObj* p = arg0;

    temp_v0 = D_800971F8[1].x_pos.u.hi - 0x10;
    D_800971F8[1].x_pos.u.hi = temp_v0;
    if ((s16)temp_v0 <= 0) {
        D_800971F8[1].x_pos.u.hi = 0;
        D_800971F8[2].unk3 = 0;
        if (D_800CCF08 == 0) {
            var_v0 = 0x18B;
            var_v1 = 0xA;
        } else {
            var_v0 = 0x19F;
            var_v1 = 0x10;
        }
        p->x_pos.i.lo = var_v0;
        p->x_pos.i.hi = var_v1;
        do {
        } while (0);
        p->unk1++;
    }
}
