#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK move_object(s32);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_BackgroundObj background_objects[3];

#define ABS_LT5(d) (((d) < 0 ? -(d) : (d)) < 5)

void func_800F65DC(struct X4_ShotObj* arg0) {
    struct X4_WeaponObj* w = arg0->unk7C;
    s32 angle;

    if (arg0->unk15 == 0) {
        s32 dy = arg0->y_pos.i.hi - 0x40;
        s32 dx = arg0->x_pos.i.hi - 0x40;
        angle = func_80065B74(dy - background_objects[0].y_pos.i.hi,
                              background_objects[0].x_pos.i.hi - dx);
    } else {
        s32 dy = arg0->y_pos.i.hi - 0x40;
        s32 dx = arg0->x_pos.i.hi - 0x110;
        angle = func_80065B74(dy - background_objects[0].y_pos.i.hi,
                              background_objects[0].x_pos.i.hi - dx);
    }
    arg0->x_vel.val = func_80065A14(angle) << 6;
    arg0->y_vel.val = func_80065944(angle) << 6;
    do {
        ((void (*)(struct X4_ShotObj*))move_object)(arg0);
    } while (0);
    if (arg0->unk15 == 0) {
        s32 dx = arg0->x_pos.i.hi - 0x40;
        if (ABS_LT5(background_objects[0].x_pos.i.hi - dx)) {
            s32 dy = arg0->y_pos.i.hi - 0x40;
            if (ABS_LT5(background_objects[0].y_pos.i.hi - dy)) {
                w->unk7 = 4;
                arg0->unk50.data = 0;
                arg0->unk54 = 0;
                arg0->on_screen = 0;
                arg0->state = 3;
            }
        }
    } else {
        s32 dx = arg0->x_pos.i.hi - 0x110;
        if (ABS_LT5(background_objects[0].x_pos.i.hi - dx)) {
            s32 dy = arg0->y_pos.i.hi - 0x40;
            if (ABS_LT5(background_objects[0].y_pos.i.hi - dy)) {
                w->unk7 = 4;
                arg0->unk50.data = 0;
                arg0->unk54 = 0;
                arg0->on_screen = 0;
                arg0->state = 3;
            }
        }
    }
}
