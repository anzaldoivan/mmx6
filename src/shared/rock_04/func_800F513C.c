#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* enemy_slot_alloc();

void func_800F513C(struct X4_AnimatedObj* arg0, u8 arg1) {
    struct X4_AnimatedObj* obj;

    obj = enemy_slot_alloc();
    if (obj != 0) {
        obj->active = 0x41;
        obj->id = 0x36;
        obj->unk2 = arg1;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->animation_table = arg0->animation_table;
        obj->unk3C = arg0->unk3C;
        obj->unk40 = arg0->unk40;
        obj->unk15 = arg0->unk15;
        obj->bg_offset = arg0->bg_offset;
        obj->x_pos.i.hi = arg0->x_pos.i.hi;
        obj->x_pos.i.lo = 0;
        obj->y_pos.i.hi = arg0->y_pos.i.hi;
        obj->y_pos.i.lo = 0;
        M2C_FIELD(obj, void**, 0x80) = arg0;
    }
}
