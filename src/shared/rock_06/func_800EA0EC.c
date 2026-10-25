#include "common.h"
#include "mmx6/x4.h"

extern s32 D_800C1220[];

static inline u8 EA0EC_hit(struct X4_PlayerObj* o, struct X4_Unk_unk68* h,
                           s16 x, s16 y) {
    // !FAKE: depin: dropping it breaks the match (76/81)
    register struct X4_Unk_unk68* q asm("$9") = h;
    s16 cx;
    s16 cy;

    if (o->unk15 == 0x40) {
        // !FAKE: depin: dropping it breaks the match (24/81)
        register s8 d asm("$3") = h->unk0;
        cx = o->x_pos.i.hi - d;
    } else {
        // !FAKE: depin: dropping it breaks the match (31/81)
        register s8 d asm("$3") = h->unk0;
        cx = o->x_pos.i.hi + d;
    }
    cy = o->y_pos.i.hi + q->unk1;
    if (x < cx - q->unk2) {
        return 0;
    }
    if (cx + q->unk2 - 1 < x) {
        return 0;
    }
    if (y < cy - q->unk3) {
        return 0;
    }
    if (cy + q->unk3 - 1 < y) {
        return 0;
    }
    return 0x38;
}

s32 func_800EA0EC(struct X4_PlayerObj* arg0, s16 arg1, s16 arg2) {
    struct X4_PlayerObj* p;
    struct X4_Unk_unk68* h;
    s32 i;
    u8 r;

    i = 0;
    p = (struct X4_PlayerObj*)D_800C1220;
    for (; i < 0x50; i++, p = (struct X4_PlayerObj*)((u8*)p + 0xA4)) {
        if (p != arg0 && p->active != 0 && *((s8*)p + 0xA2) != 0 &&
            (h = p->unk68) != 0 && *((s8*)p + 1) == 0xB) {
            r = EA0EC_hit(p, h, arg1, arg2);
            if (r != 0) {
                return r;
            }
        }
    }
    return 0;
}
