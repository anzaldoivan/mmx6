#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;

#define PA4 (*(s8*)((u8*)p + 0xA4))

s32 func_80050C88(void* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    struct X4_PlayerObj* o = arg0;
    struct X4_Unk_unk68* a;
    struct X4_Unk_unk68* b;
    s8 t;
    s16 oy;
    s16 py;
    s16 d;

    if (PA4 != 0 || (p->hp & 0x80) || p->unk5 == 3) {
        goto ret0;
    }
    if (p->unk2 == 0) {
        goto arm7a;
    }
    t = p->attacking;
join:
    if (t != 0) {
    ret0:
        return 0;
    arm7a:
        t = p->spike_immune;
        goto join;
    }
    if (p->x_pos.i.hi > o->x_pos.i.hi) {
        return 0;
    }
    oy = o->x_pos.u.hi + o->unk68->unk0;
    py = p->x_pos.u.hi + p->unk68->unk0;
    d = (oy - py < 0) ? py - oy : oy - py;
    a = o->unk68;
    b = p->unk68;
    if (a->unk2 + b->unk2 < d) {
        return 0;
    }
    {
        s16 at = a->unk1 + (o->y_pos.u.hi - a->unk3);
        s16 bt = b->unk1 + (p->y_pos.u.hi - b->unk3);
        if (at > bt) {
            return 0;
        }
    }
    {
        s16 at = a->unk1 + (o->y_pos.u.hi + a->unk3);
        s16 bt = b->unk1 + (p->y_pos.u.hi + b->unk3);
        return at >= bt;
    }
}
#undef PA4
