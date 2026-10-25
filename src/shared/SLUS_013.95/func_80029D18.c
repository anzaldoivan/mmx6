#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
void func_80029F38(s16, s16, s16, s16, u8);

void func_80029D18(void) {
    struct X4_BackgroundObj* bg = background_objects;

    if (bg->unk14.i.hi != bg->x_pos.i.hi) {
        if (bg->unk14.i.hi < bg->x_pos.i.hi) {
            func_80029F38(bg->x_pos.i.hi + 0x150, bg->x_pos.i.hi + 0x170,
                          bg->y_pos.i.hi - 0x30, bg->y_pos.i.hi + 0x120, 1);
        } else {
            func_80029F38(bg->x_pos.i.hi - 0x30, bg->x_pos.i.hi - 0x10,
                          bg->y_pos.i.hi - 0x30, bg->y_pos.i.hi + 0x120, 2);
        }
    }
    if (bg->unk18.i.hi != bg->y_pos.i.hi) {
        if (bg->unk18.i.hi < bg->y_pos.i.hi) {
            func_80029F38(bg->x_pos.i.hi - 0x30, bg->x_pos.i.hi + 0x170,
                          bg->y_pos.i.hi + 0x100, bg->y_pos.i.hi + 0x120, 3);
        } else {
            func_80029F38(bg->x_pos.i.hi - 0x30, bg->x_pos.i.hi + 0x170,
                          bg->y_pos.i.hi - 0x30, bg->y_pos.i.hi - 0x10, 4);
        }
    }
}
