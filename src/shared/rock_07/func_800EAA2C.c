#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();
s32 func_8002D2D4();
extern struct X4_BackgroundObj background_objects[3];

void func_800EAA2C(struct X4_MainObj* arg0, M2C_UNK arg1) {
    u8 sub;
    struct X4_MainObj* o;
    s8 t;

    sub = arg1;
    o = func_8002C458();
    if (o != 0) {
        o->active = 0x41;
        o->id = 0xD;
        o->unk15 = arg0->unk15;
        o->unk2 = sub;
        o->x_pos.i.hi = arg0->x_pos.i.hi;
        o->x_pos.i.lo = 0;
        o->y_pos.i.hi = arg0->y_pos.i.hi;
        o->y_pos.i.lo = 0;
        o->unk42 = arg0->unk42 & 0x7FFF;
        o->animation_table = arg0->animation_table;
        o->sprite_frames = arg0->sprite_frames;
        o->unk40 = arg0->unk40;
        o->bg_offset = arg0->bg_offset;
        M2C_FIELD(o, void**, 0x7C) = arg0;
        t = sub;
        if (t == 0) {
            o->x_pos.i.hi = background_objects[0].x_pos.i.hi +
                            M2C_FIELD(background_objects, u16*, 0x5E) + 0xA0;
            o->y_pos.i.hi = background_objects[0].y_pos.i.hi -
                            M2C_FIELD(background_objects, u16*, 0x62) + 0x3A8;
            o->x_pos.i.hi = o->x_pos.i.hi + (func_8002D2D4() & 0x7F);
        } else if (t == 0x30) {
            M2C_FIELD(o, s32*, 0x84) = arg0->unk6;
        }
    }
}
