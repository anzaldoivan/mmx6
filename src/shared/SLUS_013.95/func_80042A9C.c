#include "common.h"
#include "mmx6/x4.h"

void* func_8002C530(); /* extern */

void func_80042A9C(struct X4_MainObj* self, s32 arg1) {
    u8 kind;
    struct X4_MainObj* obj;

    kind = arg1;
    obj = func_8002C530();
    if (obj != 0) {
        obj->active = 0x41;
        obj->id = 0xB;
        obj->unk2 = kind;
        obj->unk15 = self->unk15;
        obj->unk40 = self->unk40;
        obj->unk42 = self->unk42 & 0x7FFF;
        obj->animation_table = self->animation_table;
        obj->sprite_frames = self->sprite_frames;
        obj->bg_offset = self->bg_offset;
        obj->x_pos.u.hi = self->x_pos.u.hi;
        obj->x_pos.u.lo = 0;
        obj->y_pos.u.hi = self->y_pos.u.hi;
        obj->y_pos.u.lo = 0;
        obj->attack_box = self;
        if (!(kind & 0xF0)) {
            self->unk7++;
        }
    }
}
