#include "common.h"
#include "mmx6/x4.h"

s32 func_8002DCF4(void*, void*);
s32 func_8002DE54(void*, void*);
void func_8002DFA0(void*, void*);
void func_8002E0DC(void*, void*);
extern struct X4_PlayerObj g_Player;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))

s32 func_80032208(struct X4_MainObj* self, struct X4_PlayerObj* tgt) {
    s8 saved;
    s32 dx;
    s32 dy;

    if (tgt->unk68 == 0) {
        return 1;
    }
    if (self->unk66 == 0) {
        if (func_8002DE54(self, tgt) != 0) {
            tgt->unk71 = 0xF;
            if (tgt == &g_Player) {
                F8(tgt, 0xE6) = F8(self, 0x60);
            }
            return 1;
        }
    }
    saved = self->unk66;
    if (func_8002DCF4(self, tgt) != 0) {
        if (self->unk66 < -3 || self->unk66 > 3) {
            if (func_8002DE54(self, tgt) == 0) {
                self->unk66 = 0;
            } else if (self->unk66 > 0) {
                self->unk66 = self->unk66 - 2;
            } else {
                self->unk66 = self->unk66 + 2;
            }
        } else if (self->unk66 < -1 || self->unk66 > 1) {
            if (func_8002DE54(self, tgt) == 0) {
                if (self->unk66 > 0) {
                    self->unk66 = 1;
                } else {
                    self->unk66 = -1;
                }
            }
        }
        func_8002DFA0(self, tgt);
        func_8002E0DC(self, tgt);
        if (tgt->unk6C < 0) {
            dx = (s16)-tgt->unk6C;
        } else {
            dx = tgt->unk6C;
        }
        dy = tgt->unk6E;
        if (dy < 0) {
            dy = (s16)-tgt->unk6E;
        }
        if (self->unk66 == 0) {
            if (dx < dy) {
                tgt->x_pos.i.hi += tgt->unk6C;
            } else {
                tgt->y_pos.i.hi += tgt->unk6E;
            }
        } else if (self->unk66 > 0) {
            tgt->x_pos.i.hi += tgt->unk6C;
        } else {
            tgt->y_pos.i.hi += tgt->unk6E;
        }
    }
    self->unk66 = saved;
    return 0;
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_8002DCF4(void*, void*);
void func_8002DFA0(void*, void*);
void func_8002E0DC(void*, void*);

s32 func_800323D4(struct X4_MainObj* self, struct X4_PlayerObj* tgt) {
    s32 dx;
    s32 dy;

    if (tgt->unk68 == 0) {
        return 0;
    }
    if (func_8002DCF4(self, tgt) != 0) {
        func_8002DFA0(self, tgt);
        func_8002E0DC(self, tgt);
        if (tgt->unk6C < 0) {
            dx = (s16)-tgt->unk6C;
        } else {
            dx = tgt->unk6C;
        }
        dy = tgt->unk6E;
        if (dy < 0) {
            dy = (s16)-tgt->unk6E;
        }
        if (self->unk66 == 0) {
            if (dx < dy) {
                tgt->x_pos.i.hi += tgt->unk6C;
            } else {
                tgt->y_pos.i.hi += tgt->unk6E;
            }
        } else if (self->unk66 > 0) {
            tgt->x_pos.i.hi += tgt->unk6C;
        } else {
            tgt->y_pos.i.hi += tgt->unk6E;
        }
        return 1;
    }
    return 0;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
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
        if (d != 0 && (pl = &g_Player, PL_138 == 0)) {
            PL_138 = d;
            SHIFT_X();
        }
        d = a->y_pos.i.hi - a->unk1C.i.hi;
        if (d > 0) {
            rel = b->y_pos.i.hi - b->unk1C.i.hi;
            ao = a->unk1C.i.hi - b->unk1C.i.hi;
            b->y_pos.i.hi = rel + (a->y_pos.i.hi - ao);
        } else if (d < 0) {
            struct X4_Unk_unk68* ta5;
            struct X4_Unk_unk68* tb6;
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
            if (d != 0 && (pl = &g_Player, PL_138 == 0)) {
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

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800328B0() {
    // !FAKE: depin: dropping it breaks the match (1/161)
    register struct X4_BackgroundObj* a0 asm("$4");
    // !FAKE: depin: dropping it breaks the match (123/161)
    register struct X4_BackgroundObj* o asm("$8") = a0;
    s16 dx;
    s16 dy;

    o->unk3 = 0;
    if (o->unk37 < 0) {
        dx = o->unk14.i.hi + o->x_pos.i.hi;
        dy = o->unk18.i.hi + o->y_pos.i.hi;
    } else {
        dx = o->unk14.i.hi + o->x_pos.i.hi -
             background_objects[o->unk37].x_pos.i.hi;
        dy = o->unk18.i.hi + o->y_pos.i.hi -
             background_objects[o->unk37].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        o->unk3 = 1;
        return;
    }
    if (o->unk37 < 0) {
        dx = o->unk1E + o->x_pos.i.hi;
        dy = o->unk22 + o->y_pos.i.hi;
    } else {
        dx = o->unk1E + o->x_pos.i.hi - background_objects[o->unk37].x_pos.i.hi;
        dy = o->unk22 + o->y_pos.i.hi - background_objects[o->unk37].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        o->unk3 = 1;
        return;
    }
    if (o->unk37 < 0) {
        dx = o->unk26 + o->x_pos.i.hi;
        dy = o->unk2A + o->y_pos.i.hi;
    } else {
        dx = o->unk26 + o->x_pos.i.hi - background_objects[o->unk37].x_pos.i.hi;
        dy = o->unk2A + o->y_pos.i.hi - background_objects[o->unk37].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        o->unk3 = 1;
        return;
    }
    if (o->unk37 < 0) {
        dx = o->unk2E + o->x_pos.i.hi;
        dy = o->unk32 + o->y_pos.i.hi;
    } else {
        dx = o->unk2E + o->x_pos.i.hi - background_objects[o->unk37].x_pos.i.hi;
        dy = o->unk32 + o->y_pos.i.hi - background_objects[o->unk37].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        o->unk3 = 1;
        return;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern s8 D_800950A0[];

s32 func_8002DCF4(void*, void*);
void func_800312DC(struct X4_MainObj* arg0, struct X4_MainObj* arg1, s16* arg2,
                   s16* arg3);
s32 func_800315CC(void* arg0, void* arg1);

s32 func_80032B34(struct X4_PlayerObj* arg0) {
    s8* p;
    s32 r;

    for (p = D_800950A0; p < D_800950A0 + 0x1400; p += 0xA0) {
        if (p[0] == 0) {
            continue;
        }
        if (func_8002DCF4(p, arg0) == 0) {
            continue;
        }
        func_800312DC((struct X4_MainObj*)arg0, (struct X4_MainObj*)p,
                      (s16*)(p + 0x80), (s16*)(p + 0x82));
        r = func_800315CC(arg0, p);
        if (r == 0x7E) {
            return 0;
        }
        if (r != 0) {
            return r;
        }
    }
    arg0->unk65 = 0;
    return 0;
}

#include "common.h"
#include "mmx6/x4.h"

#include "mmx6/projectile.h"

s32 check_attack_hit(void* arg0, void* arg1, s16* arg2, s16* arg3);

s8 func_80032BE8(struct X4_PlayerObj* arg0) {
    s8* p;
    s8 r;

    r = 0;
    for (p = (s8*)g_projectiles; p < (s8*)g_projectiles + 0x1400; p += 0xA0) {
        if (p[0] != 0 && check_attack_hit(p, arg0, (s16*)(p + 0x80),
                                          (s16*)(p + 0x82)) != 0) {
            r = p[1];
            p[0x70] |= 0xF;
        }
    }
    return r;
}

#include "common.h"
#include "mmx6/x4.h"

void func_80032C88(void* arg0, void* arg1) {
    struct X4_AnimatedObj* a = arg0;
    struct X4_AnimatedObj* b = arg1;
    s16 d1;
    s16 d2;

    if (a->x_pos.i.hi != a->unk18.i.hi) {
        d1 = b->x_pos.i.hi - b->unk18.i.hi;
        d2 = a->unk18.i.hi - b->unk18.i.hi;
        b->x_pos.i.hi = d1 + (a->x_pos.i.hi - d2);
    }
    if (a->y_pos.i.hi - a->unk1C.i.hi > 0) {
        d1 = b->y_pos.i.hi - b->unk1C.i.hi;
        d2 = a->unk1C.i.hi - b->unk1C.i.hi;
        b->y_pos.i.hi = d1 + (a->y_pos.i.hi - d2);
    }
}

#include "common.h"

#define H(p, o) (*(s16*)((u8*)(p) + (o)))

void func_80032D24(void* arg0, struct MainObj* arg1) {
    s32 d;
    s32 f;
    s16 r;
    s16 s;

    d = H(arg0, 0xA) - H(arg0, 0x1A);
    if (d != 0) {
        if (d > 0) {
            f = arg1->collision_flags & 1;
        } else {
            f = arg1->collision_flags & 2;
        }
        if (f == 0) {
            r = H(arg1, 0xA) - H(arg1, 0x1A);
            s = H(arg0, 0x1A) - H(arg1, 0x1A);
            H(arg1, 0xA) = r + (H(arg0, 0xA) - s);
        }
    }
    if (H(arg0, 0xE) - H(arg0, 0x1E) > 0) {
        r = H(arg1, 0xE) - H(arg1, 0x1E);
        s = H(arg0, 0x1E) - H(arg1, 0x1E);
        H(arg1, 0xE) = r + (H(arg0, 0xE) - s);
    }
}

#undef H
