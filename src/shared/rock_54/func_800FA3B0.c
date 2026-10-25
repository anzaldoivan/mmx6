#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

void func_800FA3B0(struct X4_BackgroundObj* arg0) {
    // !FAKE: pin the first store value to the first return register
    register s32 var_v0 asm("$2");
    s32 var_v1;
    s32 temp_v0;
    struct X4_BackgroundObj* p = arg0;

    temp_v0 = background_objects[1].x_pos.u.hi - 0x10;
    background_objects[1].x_pos.u.hi = temp_v0;
    if ((s16)temp_v0 <= 0) {
        background_objects[1].x_pos.u.hi = 0;
        if (D_800CCF08 == 0) {
            var_v0 = 0x16C;
            var_v1 = 0x16;
        } else {
            var_v0 = 0x196;
            var_v1 = 3;
        }
        p->x_pos.i.lo = var_v0;
        p->x_pos.i.hi = var_v1;
        do {
        } while (0);
        p->unk1++;
    }
}
