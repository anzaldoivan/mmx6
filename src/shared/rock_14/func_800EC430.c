#include "common.h"
#include "mmx6/x4.h"

s32 func_800EC430(struct X4_PlayerObj* a, struct X4_PlayerObj* b) {
    struct X4_Unk_unk68* ra;
    struct X4_Unk_unk68* rb;
    u16 ax;
    u16 bx;
    u8 aw;
    u8 bw;
    s16 ay;
    s16 by;
    s16 d;
    s32 t;
    s16 l;
    s16 r;

    if (b->unk68 == 0) {
        return 0;
    }
    if (b->unk5 != 2 && b->unk5 != 4 && b->unk5 != 0x14 && b->unk5 != 3) {
        return 0;
    }
    ra = a->unk68;
    ax = a->x_pos.i.hi;
    rb = b->unk68;
    aw = ra->unk2;
    bw = rb->unk2;
    l = ax - (aw - 8);
    r = b->x_pos.i.hi - bw;
    if (l > r) {
        return 0;
    }
    l = ax + (aw - 8);
    r = b->x_pos.i.hi + bw;
    if (l < r) {
        return 0;
    }
    ay = a->y_pos.i.hi + ra->unk1;
    by = b->y_pos.i.hi + rb->unk1;
    d = (ay - by) >= 0 ? (ay - by) : (by - ay);
    return ((volatile struct X4_PlayerObj*)a)->unk68->unk3 +
               ((volatile struct X4_PlayerObj*)b)->unk68->unk3 >=
           d;
}
