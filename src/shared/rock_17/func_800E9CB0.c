#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800E9CB0(void* arg0) {
    background_objects[2].x_pos.val += 0xFFFAE148;
    background_objects[2].y_pos.val = 0;
    background_objects[2].unk4C = 1;
    if (background_objects[2].x_pos.i.hi <= 0) {
        background_objects[2].x_pos.i.hi = 0;
        *(s16*)((u8*)arg0 + 4) = 0xA;
        *((u8*)arg0 + 1) += 1;
    }
}
