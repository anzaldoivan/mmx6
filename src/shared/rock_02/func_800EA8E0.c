#include "common.h"
#include "mmx6/x4.h"

void* alloc_sprite_slot();

void func_800EA8E0(void* arg0, s32 arg1) {
    struct X4_MainObj* self = arg0;
    struct X4_MainObj* child;
    u8 v = arg1;

    child = alloc_sprite_slot();
    if (child != 0) {
        child->active = 0x41;
        child->id = 0;
        child->unk2 = v;
        child->unk15 = self->unk15;
        child->unk40 = self->unk40;
        child->unk42 = self->unk42 & 0x7FFF;
        child->animation_table = self->animation_table;
        child->sprite_frames = self->sprite_frames;
        child->bg_offset = self->bg_offset;
        do {
        } while (0);
        {
            s32 t = self->x_pos.u.hi;
            child->x_pos.u.lo = 0;
            child->x_pos.u.hi = t;
        }
        {
            s32 t = self->y_pos.u.hi;
            child->y_pos.u.lo = 0;
            child->attack_box = arg0;
            child->y_pos.u.hi = t;
        }
    }
}
