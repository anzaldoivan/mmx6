#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800328B0() {
    // !FAKE: depin: dropping it breaks the match (1/161)
    register struct X4_BackgroundObj* a0 asm("$4");
    // !FAKE: depin: dropping it breaks the match (123/161)
    register struct X4_BackgroundObj* o asm("$8") = a0;
    s16 dx;
    s16 dy;

    o->unk3 = 0;
    if (o->unk37 < 0) {
        dx = o->unk14.i.hi + o->x_pos.i.hi;
        dy = o->unk18.i.hi + o->y_pos.i.hi;
    } else {
        dx = o->unk14.i.hi + o->x_pos.i.hi -
             background_objects[o->unk37].x_pos.i.hi;
        dy = o->unk18.i.hi + o->y_pos.i.hi -
             background_objects[o->unk37].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        o->unk3 = 1;
        return;
    }
    if (o->unk37 < 0) {
        dx = o->unk1E + o->x_pos.i.hi;
        dy = o->unk22 + o->y_pos.i.hi;
    } else {
        dx = o->unk1E + o->x_pos.i.hi - background_objects[o->unk37].x_pos.i.hi;
        dy = o->unk22 + o->y_pos.i.hi - background_objects[o->unk37].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        o->unk3 = 1;
        return;
    }
    if (o->unk37 < 0) {
        dx = o->unk26 + o->x_pos.i.hi;
        dy = o->unk2A + o->y_pos.i.hi;
    } else {
        dx = o->unk26 + o->x_pos.i.hi - background_objects[o->unk37].x_pos.i.hi;
        dy = o->unk2A + o->y_pos.i.hi - background_objects[o->unk37].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        o->unk3 = 1;
        return;
    }
    if (o->unk37 < 0) {
        dx = o->unk2E + o->x_pos.i.hi;
        dy = o->unk32 + o->y_pos.i.hi;
    } else {
        dx = o->unk2E + o->x_pos.i.hi - background_objects[o->unk37].x_pos.i.hi;
        dy = o->unk32 + o->y_pos.i.hi - background_objects[o->unk37].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        o->unk3 = 1;
        return;
    }
}
