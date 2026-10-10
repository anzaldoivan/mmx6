#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80097186;

void func_8002E1A0(struct X4_PlayerObj* a, struct X4_PlayerObj* b, s32 mode) {
    s16 ax, ay, bx, by;
    u8 r;
    s16 y;
    s32 w1;
    s32 w2;
    s32 d;
    s32 dx;
    s16 t;

    r = 0;
    if (a->unk15 == 0x40) {
        ax = a->x_pos.i.hi - a->unk68->unk0;
    } else {
        ax = a->x_pos.i.hi + a->unk68->unk0;
    }
    ay = a->y_pos.i.hi + a->unk68->unk1;
    if (b->unk15 == 0x40) {
        bx = b->x_pos.i.hi - b->unk68->unk0;
    } else {
        bx = b->x_pos.i.hi + b->unk68->unk0;
    }
    by = b->y_pos.i.hi + b->unk68->unk1;

    d = ay - by;
    if (d >= 0) {
        t = d;
    } else {
        t = by - ay;
    }
    dx = ax - bx;
    w1 = a->unk68->unk3;
    if (t == b->unk68->unk3 + w1) {
        if (dx >= 0) {
            t = dx;
        } else {
            t = bx - ax;
        }
        y = a->unk68->unk2 + b->unk68->unk2;
        if (t < y) {
            r = 8;
            if (ay < by) {
                r = 4;
            }
        }
    }
    if (dx >= 0) {
        t = dx;
    } else {
        t = bx - ax;
    }
    w2 = a->unk68->unk2;
    if (t == b->unk68->unk2 + w2) {
        d = ay - by;
        if (d >= 0) {
            t = d;
        } else {
            t = by - ay;
        }
        y = a->unk68->unk3 + b->unk68->unk3;
        if (t < y) {
            if (ax < bx) {
                r |= 2;
            } else {
                r |= 1;
            }
            b->wall_climbable = a->unk75;
        }
    }
    switch ((u32)mode) {
    case 0:
        a->unk72 = r;
        break;
    case 1:
        a->unk73 = r;
        break;
    case 2:
        a->unk74 = r;
        break;
    }
    b->unk71 |= r;
    if (r & 0xB) {
        switch ((u32)mode) {
        case 0:
            a->unk76 = 1;
            break;
        case 1:
            a->unk77 = mode;
            break;
        case 2:
            a->unk78 = 1;
            break;
        }
    } else {
        switch ((u32)mode) {
        case 0:
            if ((r & 4) && (b->unk5 == 0x1F || b->unk5 == 0x3F)) {
                a->unk76 = 1;
            } else {
                a->unk76 = 0;
            }
            break;
        case 1:
            a->unk77 = 0;
            break;
        case 2:
            a->unk78 = 0;
            break;
        }
    }
    if (r != 0) {
        D_80097186 = a->unk60;
    }
}
