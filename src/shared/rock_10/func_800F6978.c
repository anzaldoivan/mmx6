#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

#define ABS_LT5(d) (((d) < 0 ? -(d) : (d)) < 5)

void func_800F6978(struct X4_AnimatedObj* arg0) {
    s32 angle;

    if (arg0->unk15 == 0) {
        s32 dy = arg0->y_pos.i.hi - 0x90;
        s32 dx = arg0->x_pos.i.hi - 0x30;
        angle = ratan2(dy - background_objects[0].y_pos.i.hi,
                       background_objects[0].x_pos.i.hi - dx);
    } else {
        s32 dy = arg0->y_pos.i.hi - 0x90;
        s32 dx = arg0->x_pos.i.hi - 0x110;
        angle = ratan2(dy - background_objects[0].y_pos.i.hi,
                       background_objects[0].x_pos.i.hi - dx);
    }
    arg0->x_vel.val = rcos(angle) << 6;
    arg0->y_vel.val = rsin(angle) << 6;
    do {
        ((void (*)(struct X4_AnimatedObj*))move_object)(arg0);
    } while (0);
    if (arg0->unk15 == 0) {
        s32 dx = arg0->x_pos.i.hi - 0x30;
        if (ABS_LT5(background_objects[0].x_pos.i.hi - dx)) {
            s32 dy = arg0->y_pos.i.hi - 0x90;
            if (ABS_LT5(background_objects[0].y_pos.i.hi - dy)) {
                arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x30;
                arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x90;
                arg0->unk6++;
            }
        }
    } else {
        s32 dx = arg0->x_pos.i.hi - 0x110;
        if (ABS_LT5(background_objects[0].x_pos.i.hi - dx)) {
            s32 dy = arg0->y_pos.i.hi - 0x90;
            if (ABS_LT5(background_objects[0].y_pos.i.hi - dy)) {
                arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x110;
                arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x90;
                arg0->unk6++;
            }
        }
    }
}
