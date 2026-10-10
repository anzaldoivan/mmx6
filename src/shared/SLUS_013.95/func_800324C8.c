#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
#define PL_138 (*(s32*)((u8*)pl + 0x138))
#define OBJ_E7(o) (*(u8*)((u8*)(o) + 0xE7))
#define OBJ_13E(o) (*(s16*)((u8*)(o) + 0x13E))
#define SHIFT_X()                                                              \
    {                                                                          \
        rel = b->x_pos.i.hi - b->unk18.i.hi;                                   \
        ao = a->unk18.i.hi - b->unk18.i.hi;                                    \
        old = b->x_pos.i.hi;                                                   \
        b->x_pos.i.hi = rel + (a->x_pos.i.hi - ao);                            \
        dd = old;                                                              \
        dd = b->x_pos.i.hi - dd;                                               \
        OBJ_13E(b) += dd;                                                      \
    }

void func_800324C8(struct X4_MainObj* a, struct X4_MainObj* b, u8 flags) {
    s16 d;
    s16 old;
    s16 t;
    s16 v;
    s16 rel;
    s16 ao;
    struct X4_PlayerObj* pl;
    s16 dd;
    struct X4_Unk_unk68* ta;
    struct X4_Unk_unk68* tb;

    if (flags & 8) {
        d = a->x_pos.i.hi - a->unk18.i.hi;
        if (d != 0 && (pl = &D_800970A0, PL_138 == 0)) {
            PL_138 = d;
            SHIFT_X();
        }
        d = a->y_pos.i.hi - a->unk1C.i.hi;
        if (d > 0) {
            rel = b->y_pos.i.hi - b->unk1C.i.hi;
            ao = a->unk1C.i.hi - b->unk1C.i.hi;
            b->y_pos.i.hi = rel + (a->y_pos.i.hi - ao);
        } else if (d < 0) {
            register struct X4_Unk_unk68* ta5 asm("$5");
            register struct X4_Unk_unk68* tb6 asm("$6");
            tb6 = b->terrain_box;
            ta5 = a->terrain_box;
            v = b->y_pos.i.hi + tb6->unk1;
            t = a->y_pos.i.hi + ta5->unk1;
            if (v + tb6->unk3 > t - ta5->unk3) {
                v = t - ta5->unk3 - tb6->unk3;
                b->y_pos.i.hi = v - tb6->unk1;
            }
        }
    } else if (flags & 4) {
        if ((b->unk5 == 0x1F && b->unk6 < 4) || b->unk5 == 0x3F) {
            d = a->x_pos.i.hi - a->unk18.i.hi;
            if (d != 0 && (pl = &D_800970A0, PL_138 == 0)) {
                PL_138 = d;
                SHIFT_X();
            }
            ta = a->terrain_box;
            tb = b->terrain_box;
            b->y_pos.i.hi =
                tb->unk3 + (ta->unk3 + (a->y_pos.i.hi + ta->unk1)) - tb->unk1;
        }
    } else if (b->unk5 == 0xB || b->unk5 == 0x34 || b->unk5 == 9 ||
               b->unk5 == 0x2F) {
        d = a->x_pos.i.hi - a->unk18.i.hi;
        if (d != 0) {
            if (flags & 2) {
                if (a->unk15 == 0x40) {
                    b->x_pos.i.hi = b->terrain_box->unk2 +
                                    (a->terrain_box->unk2 +
                                     (a->x_pos.i.hi - a->terrain_box->unk0));
                } else {
                    b->x_pos.i.hi = b->terrain_box->unk2 +
                                    (a->terrain_box->unk2 +
                                     (a->x_pos.i.hi + a->terrain_box->unk0));
                }
            } else {
                if (a->unk15 == 0x40) {
                    b->x_pos.i.hi = a->x_pos.i.hi - a->terrain_box->unk0 -
                                    a->terrain_box->unk2 - b->terrain_box->unk2;
                } else {
                    b->x_pos.i.hi = a->x_pos.i.hi + a->terrain_box->unk0 -
                                    a->terrain_box->unk2 - b->terrain_box->unk2;
                }
            }
        }
        if ((s16)(a->y_pos.i.hi - a->unk1C.i.hi) > 0 || OBJ_E7(b) == 2) {
            rel = b->y_pos.i.hi - b->unk1C.i.hi;
            ao = a->unk1C.i.hi - b->unk1C.i.hi;
            b->y_pos.i.hi = rel + (a->y_pos.i.hi - ao);
        }
    }
}
