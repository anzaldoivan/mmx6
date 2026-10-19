#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCF08;

void func_800FA320(struct X4_BackgroundObj* arg0) {
    // !FAKE: pin the first store value to the first return register
    register s32 var_v0 asm("$2");
    s32 var_v1;
    s32 temp_v0;

    if (func_800EA480((s8*)arg0) != 0) {
        temp_v0 = D_800971F8[1].x_pos.u.hi - 0x10;
        D_800971F8[1].x_pos.u.hi = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            D_800971F8[1].x_pos.u.hi = 0;
            if (D_800CCF08 == 0) {
                var_v0 = 0x47;
                var_v1 = 0x1A;
            } else {
                var_v0 = 0x62;
                var_v1 = 0x16;
            }
            arg0->x_pos.i.lo = var_v0;
            arg0->x_pos.i.hi = var_v1;
            do {
            } while (0);
            arg0->unk1++;
        }
    }
}
