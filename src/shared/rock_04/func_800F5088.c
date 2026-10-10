#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();

void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1) {
    struct X4_AnimatedObj* p;

    p = func_8002C458();
    if (p != 0) {
        p->active = 0x41;
        p->id = 0x14;
        p->unk2 = arg1;
        p->unk42 = arg0->unk42 & 0x7FFF;
        p->animation_table = arg0->animation_table;
        p->unk3C = arg0->unk3C;
        p->unk40 = arg0->unk40;
        p->unk15 = arg0->unk15;
        p->bg_offset = arg0->bg_offset;
        p->x_pos.i.hi = arg0->x_pos.i.hi;
        p->x_pos.i.lo = 0;
        p->y_pos.i.hi = arg0->y_pos.i.hi;
        p->y_pos.i.lo = 0;
        M2C_FIELD(p, void**, 0x7C) = arg0;
    }
}
