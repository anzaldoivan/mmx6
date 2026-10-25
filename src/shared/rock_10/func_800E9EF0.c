#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800E9EF0(void) {
    background_objects[2].x_pos.i.hi = background_objects[1].x_pos.i.hi / 4;
}
