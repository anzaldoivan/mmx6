#include "common.h"
#include "mmx6/x4.h"

void func_800EBC8C(struct X4_ShotObj* arg0) {
    s32 t;

    if (!(arg0->unk70 & 8) && (arg0->unk67 == 0)) {
        t = 3;
        arg0->unk5 = t;
        t = 0x4200;
        arg0->unk2C = t;
        t = 1;
        arg0->y_vel.val = 0;
        arg0->unk28 = 0;
        arg0->unk67 = t;
    }
}
