#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

void func_800FA500(struct X4_BackgroundObj* arg0) {
    struct X4_BackgroundObj* o = arg0;
    // !FAKE: value register order
    register s32 a asm("$2");
    s16 b;

    background_objects[0].x_pos.u.hi += 0x10;
    if (background_objects[0].x_pos.i.hi >= 0x120) {
        background_objects[0].x_pos.u.hi = 0x120;
        if (D_800CCF08 == 0) {
            a = 0x182;
            b = 9;
        } else {
            a = 0x199;
            b = 6;
        }
        o->x_pos.u.lo = a;
        o->x_pos.u.hi = b;
        do {
        } while (0);
        o->unk1++;
    }
}
