// prog SLUS_013.95 | system collision | range 0x800397F8-0x80039980
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"

// 0x800397F8 snap_to_tile_slope: sets y from the slope profile of overhead tile 0x25-0x2D at x (0x2F probes 16 px up, then down); returns the tile.
// basis: code via=y_pos; derived.tsv:93
// callers: none known
s32 snap_to_tile_slope(void* arg0, s32 arg1) {
    struct X4_PlayerObj* self = arg0;
    s32 v;
    s16 a;
    s16 r;

    v = arg1 & 0xFF;
    if (v == 0x2F) {
        self->y_pos.u.hi -= 0x10;
        v = get_tile_attr_above(arg0);
        if (v == 0 || v == 0x38) {
            self->y_pos.u.hi += 0x20;
            v = get_tile_attr_above(arg0);
        }
    }
    switch (v) {
    case 0x25 ... 0x2C:
        a = self->x_pos.u.hi & 0xF;
        if (v == 0x26) {
            a |= 0x10;
        }
        if (v == 0x2A) {
            a += 0x10;
        }
        if (v == 0x27) {
            a += 0x20;
        }
        if (v == 0x2B) {
            a += 0x20;
        }
        if (v == 0x28) {
            a += 0x30;
        }
        if (v == 0x2C) {
            a += 0x30;
        }
        if ((u32)v >= 0x29) {
            r = a / 4;
        } else {
            r = 0xF - a / 4;
        }
        break;
    case 0x2D:
        r = 0;
        break;
    default:
        break;
    }
    self->y_pos.u.lo = 0;
    self->y_pos.u.hi = r + self->y_pos.i.hi - *(u16*)&self->unk6E;
    return v;
}
