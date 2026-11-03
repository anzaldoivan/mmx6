#include "../shared/rock_07/func_800E9C98.c"

#include "common.h"

#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800E9CF8(void* arg0) {
    if (D_800CCEED == 1) {
        background_objects[1].unk4 = 5;
        *(s16*)((u8*)arg0 + 0x14) = background_objects[0].unk1C;
        ((u8*)arg0)[4]++;
    }
}

#include "common.h"

#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;

void func_800E9D38(void* arg0) {
    u8* pl = (u8*)&g_Player;

    if (g_Player.action == 2) {
        *(s32*)(pl + 0xF4) += 0x8000;
        ((u8*)arg0)[4]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_800E9D78(void* arg0) {
    if (D_800CCEF6 != 0) {
        u8* pl = (u8*)&g_Player;
        *(s32*)(pl + 0xF4) -= 0x8000;
        clear_object_slot();
        return;
    }
    if (background_objects[0].x_pos.i.hi < *(s16*)((u8*)arg0 + 0x14)) {
        background_objects[0].x_pos.val += 0x8000;
        background_objects[0].unk1C = background_objects[0].x_pos.i.hi;
        background_objects[0].unk1E = background_objects[0].x_pos.i.hi;
        background_objects[0].unk24 = background_objects[0].x_pos.i.hi;
        background_objects[0].unk26 = background_objects[0].x_pos.i.hi;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_07.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void func_800ECC44(void*, s32);
void func_800ECCD8(void*, s32);
extern M2C_UNK D_8007433C;

void func_800E9E08(void* arg0) {
    void* p = arg0;
    s32 kind;
    s32 t;
    s32 v;

    t = M2C_FIELD(p, s8*, 0x2);
    if (t == 0) {
        M2C_FIELD(p, u8*, 0x60) = 8;
        M2C_FIELD(p, u8*, 0x5C) = 0;
        M2C_FIELD(p, u8*, 0x61) = 0;
        M2C_FIELD(p, void**, 0x30) = D_800F79D0 + 0xC68;
        M2C_FIELD(p, u8*, 0x14) = D_800970B4;
        M2C_FIELD(p, u8*, 0x15) = 0;
        M2C_FIELD(p, u8*, 0x16) = 0x22;
        M2C_FIELD(p, u8*, 0x67) = 0;
        M2C_FIELD(p, void**, 0x58) = &D_800743DC;
        M2C_FIELD(p, s32*, 0x20) = 0;
        M2C_FIELD(p, s32*, 0x24) = 0;
        M2C_FIELD(p, s32*, 0x28) = 0;
        M2C_FIELD(p, s32*, 0x2C) = 0;
        M2C_FIELD(p, s16*, 0x82) = 0xA0;
        M2C_FIELD(p, s16*, 0x86) = -0x40;
        M2C_FIELD(p, u8*, 0x3) = 0;
        M2C_FIELD(p, u8*, 0x8F) = 0;
        M2C_FIELD(p, u8*, 0x90) = 0;
        M2C_FIELD(p, u8*, 0x91) = 0;
        M2C_FIELD(p, u8*, 0x92) = 0;
        M2C_FIELD(p, s32*, 0x68) = 0;
        M2C_FIELD(p, s32*, 0x50) = 0;
        M2C_FIELD(p, s32*, 0x54) = 0;
        set_animation(arg0, 0);
        M2C_FIELD(p, u8*, 0x8C) = 0;
        M2C_FIELD(p, u8*, 0x8D) = 0;
        M2C_FIELD(p, u8*, 0x8E) = 0;
        func_800ECC44(p, 0x10);
        func_800ECC44(p, 0x11);
        func_800ECC44(p, 0x12);
        func_800ECC44(p, 0x20);
        func_800ECC44(p, 0x21);
        func_800ECC44(p, 0x22);
        func_800ECCD8(p, 0);
        func_800ECCD8(p, 1);
        func_800ECCD8(p, 0x10);
        func_800ECCD8(p, 0x11);
        func_800ECCD8(p, 0x20);
        M2C_FIELD(p, u8*, 0x4) = 1;
        M2C_FIELD(p, u8*, 0x5) = 2;
        M2C_FIELD(p, u8*, 0x6) = 0;
        return;
    } else {
        u8 b;
        M2C_FIELD(p, u8*, 0x60) = 0;
        M2C_FIELD(p, u8*, 0x5C) = 0x10;
        M2C_FIELD(p, void**, 0x30) = D_800F79D0 + 0xC68;
        b = D_800970B4;
        kind = t & 0xF0;
        M2C_FIELD(p, u8*, 0x16) = 0x21;
        M2C_FIELD(p, s16*, 0x84) = 0;
        M2C_FIELD(p, u8*, 0x67) = 0;
        M2C_FIELD(p, u8*, 0x14) = b;
        if (kind == 0x10) {
            ((void (*)(void*, s32))set_animation)(p, 5);
            M2C_FIELD(p, void**, 0x58) = &D_800743DC;
            switch (M2C_FIELD(p, s8*, 0x2)) {
            case 0x11:
                M2C_FIELD(p, u8*, 0x15) = 0x40;
                break;
            case 0x10:
            case 0x12:
                M2C_FIELD(p, u8*, 0x15) = 0;
                break;
            default:
                break;
            }
            v = 3;
        } else {
            ((void (*)(void*, s32))set_animation)(p, 1);
            M2C_FIELD(p, void**, 0x58) = &D_8007433C;
            switch (M2C_FIELD(p, s8*, 0x2)) {
            case 0x21:
                M2C_FIELD(p, u8*, 0x15) = 0;
                break;
            case 0x20:
            case 0x22:
                M2C_FIELD(p, u8*, 0x15) = 0x40;
                break;
            default:
                break;
            }
            v = 2;
        }
        M2C_FIELD(p, u8*, 0x5) = v;
        M2C_FIELD(p, s32*, 0x20) = 0;
        M2C_FIELD(p, s32*, 0x24) = 0;
        M2C_FIELD(p, s32*, 0x28) = 0;
        M2C_FIELD(p, s32*, 0x2C) = 0;
        M2C_FIELD(p, u8*, 0x3) = 0;
        M2C_FIELD(p, s32*, 0x68) = 0;
        M2C_FIELD(p, s32*, 0x50) = 0;
        M2C_FIELD(p, void**, 0x54) = D_800F79D0 + 0xB5C;
        M2C_FIELD(p, u8*, 0x4) = 3;
    }
    M2C_FIELD(p, u8*, 0x6) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_80030ECC();
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_800F86A4[])(void*);

void func_800EA0B4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x5) != 2 && M2C_FIELD(arg0, s8*, 0x5C) <= 0) {
        M2C_FIELD(arg0, u8*, 0x5C) = 0;
        M2C_FIELD(arg0, u8*, 0x4) = 2;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        return;
    }
    if (background_objects[0].x_pos.i.hi >= 0x1540 &&
        M2C_FIELD(arg0, s8*, 0x5) != 9) {
        M2C_FIELD(arg0, u8*, 0x5) = 9;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    animate_object(arg0);
    D_800F86A4[M2C_FIELD(arg0, s8*, 0x5)](arg0);
    M2C_FIELD(arg0, s16*, 0xA) =
        M2C_FIELD(arg0, s16*, 0x82) +
        (background_objects[0].x_pos.i.hi + background_objects[1].x_pos.i.hi);
    {
        s32 t = background_objects[0].y_pos.u.hi + 0x3B8;
        t -= background_objects[1].y_pos.u.hi;
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0x86) + t;
    }
    if (M2C_FIELD(arg0, s8*, 0x8F) >= 2) {
        func_80030ECC(arg0);
    }
}

#include "common.h"
#include "mmx6/x4.h"
struct X4_EffectObj* alloc_class3_slot(void);
extern struct X4_BackgroundObj background_objects[3];

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(void**)((u8*)(p) + (o)))

void func_800EA1CC(void* arg0) {
    void* obj;
    s32 v;
    // !FAKE: depin: dropping it breaks the match (58/69)
    register s32 w asm("$2");

    if (--F16(arg0, 0x7C) == 0) {
        obj = alloc_class3_slot();
        if (obj != 0) {
            F8(obj, 0) = 1;
            F8(obj, 1) = 0x1A;
            F8(obj, 2) = 1;
            F16(obj, 0xA) = background_objects[0].x_pos.i.hi +
                            background_objects[1].x_pos.i.hi + 0xA0;
            F16(obj, 0xE) = background_objects[0].y_pos.i.hi -
                            background_objects[1].y_pos.i.hi + 0x390;
            F32(arg0, 0x88) = obj;
        }
        F8(arg0, 5)++;
    }
    if (--F16(arg0, 0x7E) == -1) {
        U16(arg0, 0x42) ^= 0x8000;
        S8(arg0, 0x61) -= 5;
        if (S8(arg0, 0x61) >= 0x1A) {
            S8(arg0, 0x61) = 0;
        }
        v = S8(arg0, 0x61);
        if ((w = v < 6) != 0) {
            w = 5;
        } else {
            w = v;
        }
        F16(arg0, 0x7E) = w;
    }
}
#undef F8
#undef S8
#undef F16
#undef U16
#undef F32

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80029F38();
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_800EA2E0(struct X4_MainObj* self) {
    struct X4_MainObj* p;

    p = M2C_FIELD(self, struct X4_MainObj**, 0x88);
    if (p->active != 0) {
        if (p->unk7 == 0) {
            if (--self->unk7E == -1) {
                self->unk7E = 5;
                self->unk42 ^= 0x8000;
            }
        } else {
            self->action++;
            {
                s32 t2;
                background_objects[0].y_pos.i.hi = 0xE0;
                background_objects[1].y_pos.i.hi = 0xE0;
                background_objects[2].y_pos.i.hi = 0xE0;
                background_objects[0].x_pos.i.hi = 0x1550;
                background_objects[2].x_pos.i.hi = 0xAA8;
                background_objects[1].x_pos.i.hi = 0x1550;
                background_objects[0].unk4C = 1;
                background_objects[1].unk4C = 1;
                background_objects[2].unk4C = 1;
                t2 = 0x1550;
                background_objects[0].unk1E = t2;
                background_objects[0].unk26 = t2;
                background_objects[0].unk1C = t2;
                background_objects[0].unk24 = t2;
                background_objects[0].unk22 = 0xE0;
                background_objects[0].unk2A = 0xE0;
                background_objects[0].unk20 = 0xE0;
                background_objects[0].unk28 = 0xE0;
            }
            func_80029F38(0x1520, 0x16C0, 0xB0, 0x200, 0);
            {
                // !FAKE: depin: dropping it breaks the match (62/69)
                register s32 b asm("$2") = 0x18B;
                g_Player.x_pos.i.hi = 0x15E4;
                g_Player.y_pos.i.hi = b;
                g_Player.unk18.i.hi = 0x15E4;
                g_Player.unk1C.i.hi = b;
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;

void func_800EA3F4(struct X4_MainObj* self) {
    // !FAKE: the result lives in the first return register across every arm
    register s32 dir asm("$2");

    if (g_Player.character == 0) {
        s32 px;
        s32 x;
        s32 py;
        s32 y;
        s32 dx;
        s32 ya;
        s32 xb;
        s32 yc;
        s32 ye;
        s32 d_up;
        s32 d_side;
        s32 d_down;

        px = g_Player.x_pos.i.hi;
        x = self->x_pos.i.hi;
        dx = px - 0x10;
        dx -= x;
        dx = dx * dx;
        py = g_Player.y_pos.i.hi;
        y = self->y_pos.i.hi;
        ya = py + 0x20;
        ya -= y;
        ya = ya * ya;
        xb = px + 0x10;
        xb -= x;
        xb = xb * xb;
        yc = py - y;
        yc = yc * yc;
        ye = py - 0x20;
        ye -= y;
        ye = ye * ye;
        d_up = dx + ya;
        d_side = xb + yc;
        d_down = dx + ye;
        if (d_side >= d_up) {
            if (d_down < d_up) {
                // !FAKE: shared result block keeps each arm's compare ahead of the result store
                goto three;
            }
            {
                // !FAKE: a byte-mode view of the result register stops this arm cross-jumping
                register s8 one asm("$2");
                one = 1;
            }
            // !FAKE: explicit join keeps the arm out of the shared result block
            goto end;
        }
        if (d_down < d_side) {
            // !FAKE: shared result block keeps each arm's compare ahead of the result store
            goto three;
        }
        dir = 2;
        // !FAKE: explicit join keeps the arm out of the shared result block
        goto end;
    }
    if (self->x_pos.i.hi >= g_Player.x_pos.i.hi) {
        dir = 2;
        // !FAKE: explicit join keeps the arm out of the shared result block
        goto end;
    }
    if (self->y_pos.i.hi < g_Player.y_pos.i.hi) {
        // !FAKE: shared result block keeps each arm's compare ahead of the result store
        goto three;
    }
    dir = 1;
end:
    self->unk7 = dir;
    // !FAKE: barrier keeps the result store ahead of the counter load
    do {
    } while (0);
    self->action_phase++;
    return;
three:
    dir = 3;
    // !FAKE: shared result block rejoins the store
    goto end;
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EA4F4);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)

s32 random_byte();
extern s8 D_800CCF5C;
extern u8 D_800F87B0[];
extern u8 D_800F87F8[];

M2C_UNK func_800EA860(void* arg0) {
    u8 v;
    s8 n;
    u8 c;
    // !FAKE: depin: dropping it breaks the match (104/115)
    register u8* t asm("$4");
    u8* p;

    B(arg0, 0x6) = 0;
    if (SB(arg0, 0x8C) == 0 && (s8)D_800CCF5C / 2 >= SB(arg0, 0x5C)) {
        n = random_byte() & 7;
        B(arg0, 0x8D) = n;
        B(arg0, 0x8E) = 0;
        B(arg0, 0x8C) = 1;
        B(arg0, 0x5) = D_800F87F8[n * 8];
        B(arg0, 0x8E)++;
        return;
    }
    switch (SB(arg0, 0x8C)) {
    case 0:
        t = D_800F87B0;
        p = t + (SB(arg0, 0x8E) + SB(arg0, 0x8D) * 8);
        v = *p;
        if (v == 0xFF) {
            c = B(arg0, 0x92);
            B(arg0, 0x92) = c + 1;
            if ((s8)c >= 3) {
                B(arg0, 0x92) = 0;
                B(arg0, 0x8D) = 8;
            } else {
                B(arg0, 0x8D) = random_byte() & 7;
            }
            t = D_800F87B0;
            B(arg0, 0x8E) = 0;
            v = t[SB(arg0, 0x8D) * 8];
        }
        break;
    case 1:
        t = D_800F87F8;
        p = t + (SB(arg0, 0x8E) + SB(arg0, 0x8D) * 8);
        v = *p;
        if (v == 0xFF) {
            c = B(arg0, 0x92);
            B(arg0, 0x92) = c + 1;
            if ((s8)c >= 3) {
                B(arg0, 0x92) = 0;
                B(arg0, 0x8D) = 8;
            } else {
                B(arg0, 0x8D) = random_byte() & 7;
            }
            t = D_800F87F8;
            B(arg0, 0x8E) = 0;
            v = t[SB(arg0, 0x8D) * 8];
        }
        break;
    default:
        return;
    }
    do {
        B(arg0, 0x5) = v;
    } while (0);
    B(arg0, 0x8E)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();
s32 random_byte();
extern struct X4_BackgroundObj background_objects[3];

void func_800EAA2C(struct X4_MainObj* arg0, M2C_UNK arg1) {
    u8 sub;
    struct X4_MainObj* o;
    s8 t;

    sub = arg1;
    o = func_8002C458();
    if (o != 0) {
        o->active = 0x41;
        o->id = 0xD;
        o->unk15 = arg0->unk15;
        o->unk2 = sub;
        o->x_pos.i.hi = arg0->x_pos.i.hi;
        o->x_pos.i.lo = 0;
        o->y_pos.i.hi = arg0->y_pos.i.hi;
        o->y_pos.i.lo = 0;
        o->unk42 = arg0->unk42 & 0x7FFF;
        o->animation_table = arg0->animation_table;
        o->sprite_frames = arg0->sprite_frames;
        o->unk40 = arg0->unk40;
        o->bg_offset = arg0->bg_offset;
        M2C_FIELD(o, void**, 0x7C) = arg0;
        t = sub;
        if (t == 0) {
            o->x_pos.i.hi = background_objects[0].x_pos.i.hi +
                            M2C_FIELD(background_objects, u16*, 0x5E) + 0xA0;
            o->y_pos.i.hi = background_objects[0].y_pos.i.hi -
                            M2C_FIELD(background_objects, u16*, 0x62) + 0x3A8;
            o->x_pos.i.hi = o->x_pos.i.hi + (random_byte() & 0x7F);
        } else if (t == 0x30) {
            M2C_FIELD(o, s32*, 0x84) = arg0->action_phase;
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)
#define P(p, o) M2C_FIELD(p, void**, o)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object();
extern s32 D_800741FC[];
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F8840;
extern M2C_UNK D_800F8844;
extern M2C_UNK D_800F884C;
extern M2C_UNK D_800F8850;
extern M2C_UNK D_800F8854;
extern M2C_UNK D_800F8858;

void func_800EAB50(void* arg0) {
    void* parent;
    s32 ang;
    s32 t;
    s32 dx;
    s32 dy;
    void* g;
    s32 sel;
    s32 a;
    s32 b;
    s32 v;

    parent = P(arg0, 0x7C);
    B(arg0, 0x60) = 0;
    B(arg0, 0x5C) = 1;
    B(arg0, 0x16) = 0x20;
    B(arg0, 0x67) = 1;
    P(arg0, 0x58) = D_800741FC;
    P(arg0, 0x68) = 0;
    P(arg0, 0x50) = 0;
    P(arg0, 0x54) = 0;
    B(arg0, 0x4) = 1;
    B(arg0, 0x5) = 0;
    B(arg0, 0x6) = 0;
    B(arg0, 0x7) = 0;
    W(arg0, 0x20) = 0;
    W(arg0, 0x24) = 0;
    W(arg0, 0x28) = 0;
    W(arg0, 0x2C) = 0;
    B(arg0, 0x91) = 0;
    B(arg0, 0x90) = 0;
    B(arg0, 0x92) = 0;
    sel = SB(arg0, 0x2) & 0xF0;
    if (sel == 0) {
        set_animation(arg0, 8);
        B(arg0, 0x60) = 2;
        P(arg0, 0x68) = &D_800F8840;
        P(arg0, 0x50) = &D_800F8844;
        W(arg0, 0x20) = 0;
        W(arg0, 0x24) = 0xFFFE0000;
        W(arg0, 0x2C) = 0x1800;
        move_object(arg0);
        B(arg0, 0x6) = 0;
        // !FAKE: goto skips the v store; v = 0 fall-through moved bytes
        goto recheck;
    } else if (sel == 0x10) {
        play_sound(2, 0x4A, arg0);
        set_animation(arg0, 0xA);
        B(arg0, 0x60) = 4;
        P(arg0, 0x68) = &D_800F884C;
        P(arg0, 0x50) = &D_800F8850;
        g = &g_Player;
        dx = H(g, 0xA);
        dy = H(g, 0xE);
        ang = ratan2(H(arg0, 0xE) - dy, dx - H(arg0, 0xA));
        a = rcos(ang) << 4;
        W(arg0, 0x20) = (a << 2) + a;
        b = rsin(ang) << 4;
        W(arg0, 0x24) = (b << 2) + b;
        if (W(arg0, 0x20) != 0) {
            B(arg0, 0x15) = 0x40;
        } else {
            B(arg0, 0x15) = 0;
        }
        move_object(arg0);
        v = 1;
    } else if (sel == 0x20) {
        play_sound(2, 0x4B, arg0);
        set_animation(arg0, 9);
        {
            // !FAKE: depin: dropping it breaks the match (206/208)
            register s32 c4 asm("$2") = 4;
            // !FAKE: depin: dropping it breaks the match (205/208)
            register s32 c2 asm("$3") = 2;
            B(arg0, 0x60) = c4;
            B(arg0, 0x5C) = c2;
            P(arg0, 0x50) = &D_800F8854;
            P(arg0, 0x54) = &D_800F8858;
            B(arg0, 0x90) = 1;
            H(arg0, 0x88) = 0x3C;
        }
        if ((B(arg0, 0x2) & 0xF) == 1) {
            W(arg0, 0x20) = 0xFFFE8000;
            B(arg0, 0x15) = 0;
            H(arg0, 0xA) = H(arg0, 0xA) - 0x2C;
        } else {
            W(arg0, 0x20) = 0x18000;
            B(arg0, 0x15) = 0x40;
            H(arg0, 0xA) = H(arg0, 0xA) + 0x2C;
        }
        move_object(arg0);
        v = 2;
    } else if (sel == 0x30) {
        play_sound(2, 0x4C, arg0);
        set_animation(arg0, 0xB);
        {
            // !FAKE: depin: dropping it breaks the match (198/208)
            register s32 c6 asm("$2") = 6;
            // !FAKE: depin: dropping it breaks the match (194/208)
            register s32 cm asm("$3") = -0xC;
            B(arg0, 0x60) = c6;
            B(arg0, 0x8F) = 0x18;
            SB(arg0, 0x8D) = cm;
            P(arg0, 0x50) = (u8*)arg0 + 0x8C;
            t = SB(arg0, 0x45) << 4;
            B(arg0, 0x8C) = 0x7F - t;
            B(arg0, 0x8E) = t;
        }
        if (B(arg0, 0x15) == 0) {
            H(arg0, 0xA) = H(parent, 0xA) - 0xA4;
        } else {
            H(arg0, 0xA) = H(parent, 0xA) + 0xA4;
        }
        v = 3;
    } else {
        // !FAKE: goto skips recheck; copied check block+return moved bytes
        goto check;
    }
    B(arg0, 0x6) = v;
recheck:
    if ((SB(arg0, 0x2) & 0xF0) == 0x30) {
        return;
    }
check:
    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        v = B(arg0, 0x92);
        if (v != 0) {
            B(arg0, 0x3) = 0;
        }
    } else {
        B(arg0, 0x4) = 2;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);
extern void (*D_800F8868[])(void*);

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EAE90(void* arg0) {
    W(arg0, 0x18) = W(arg0, 0x8);
    W(arg0, 0x1C) = W(arg0, 0xC);
    if (UB(arg0, 0x91) == 0) {
        animate_object(arg0);
    }
    D_800F8868[B(arg0, 6)](arg0);
    if (UB(arg0, 0x90) != 0 && check_enemy_hits(arg0) < 0) {
        {
            // !FAKE: depin: dropping it breaks the match (26/91)
            register void* a asm("$4");
            a = arg0;
            B(arg0, 3) = 0;
            ((void (*)())func_80049E50)(a);
        }
        B(arg0, 4) = 2;
        return;
    }
    if (func_80030ECC(arg0) != 0) {
        switch (B(arg0, 2) & 0xF0) {
        case 0x10:
            B(arg0, 3) = 0;
            if (D_800970A2 == 0) {
                func_80049D90(arg0);
            } else {
                func_80049E50(arg0);
            }
            B(arg0, 4) = 2;
            return;
        case 0:
        case 0x20:
            B(arg0, 3) = 0;
            ((void (*)())func_80049E50)(arg0);
            B(arg0, 4) = 2;
            return;
        }
    }
    if ((B(arg0, 2) & 0xF0) != 0x30) {
        if (is_off_screen(arg0, 0x20, 0x20) == 0) {
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x10, 0x10);
            if (UB(arg0, 0x92) != 0) {
                B(arg0, 3) = 0;
            }
            return;
        }
        B(arg0, 4) = 2;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK move_object();
extern struct X4_PlayerObj g_Player;

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EAFFC(void* arg0) {
    s32 d;
    // !FAKE: depin: dropping it breaks the match (65/70)
    register s32 v asm("$3");
    // !FAKE: depin: dropping it breaks the match (53/70)
    register s32 c asm("$2");

    if (--H(arg0, 0x88) == 0) {
        W(arg0, 0x24) = 0;
        ((void (*)(void*))move_object)(arg0);
        UB(arg0, 7)++;
        return;
    }
    d = g_Player.y_pos.i.hi - H(arg0, 0xE);
    if (d >= 0) {
        if (d < 3) {
            W(arg0, 0x24) = 0;
        } else {
            // !FAKE: goto shares the far block holding the pinned player pointer; duplicating it needs a second pin
            goto far;
        }
    } else if (H(arg0, 0xE) - g_Player.y_pos.i.hi >= 3) {
    far: {
        // !FAKE: depin: dropping it breaks the match (55/70)
        register struct X4_PlayerObj* pb asm("$2") = &g_Player;
        if (pb->y_pos.i.hi >= H(arg0, 0xE)) {
            c = 0xFFFE0000;
        } else {
            c = 0x10000;
        }
        W(arg0, 0x24) = c | 0x8000;
    }
    } else {
        W(arg0, 0x24) = 0;
    }
    if ((B(arg0, 2) & 0xF) == 1) {
        v = g_Player.x_pos.i.hi > H(arg0, 0xA);
    } else {
        v = g_Player.x_pos.i.hi;
        v = v < H(arg0, 0xA);
    }
    if (v) {
        W(arg0, 0x24) = 0;
        UB(arg0, 7)++;
    }
    move_object(arg0);
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F88A4;
extern s32 D_800F88A8;
extern s32 D_800F88AC;
extern s32 D_800F88B4;
extern s32 D_800F88B8;
extern s32 D_800F88BC;

void func_800EB114(void* arg0) {
    s32 kind;
    s32 x;
    s32 y;
    s8 sub;

    B(arg0, 0x75) = 1;
    B(arg0, 0xA2) = 1;
    B(arg0, 0x76) = 0;
    kind = SB(arg0, 0x2) & 0xF0;
    B(arg0, 0x67) = 0;
    if (kind == 0) {
        B(arg0, 0x16) = 0x23;
        B(arg0, 0x60) = 8;
        W(arg0, 0x58) = (s32)&D_80075B9C;
        W(arg0, 0x50) = (s32)&D_800F88A4;
        B(arg0, 0x5C) = 0;
        B(arg0, 0x61) = 0;
        B(arg0, 0x65) = 0;
        W(arg0, 0x54) = (s32)&D_800F88A8;
        W(arg0, 0x68) = (s32)&D_800F88AC;
        set_animation(arg0, 0x10);
        sub = SB(arg0, 0x2);
        B(arg0, 0x3) = 0;
        B(arg0, 0x5) = 0;
        if (sub == 0) {
            x = 0x10;
            y = -0x40;
            H(arg0, 0x82) = x;
            H(arg0, 0x86) = y;
            B(arg0, 0x15) = 0x40;
        } else if (sub == 1) {
            x = 0x130;
            y = -0x40;
            H(arg0, 0x82) = x;
            H(arg0, 0x86) = y;
            B(arg0, 0x15) = 0;
        }
    } else if (kind == 0x10) {
        void* a = arg0;
        B(arg0, 0x60) = 0x7F;
        B(arg0, 0x5C) = 0;
        W(arg0, 0x58) = (s32)&D_80075B9C;
        B(arg0, 0x61) = 0;
        B(arg0, 0x65) = 0;
        W(arg0, 0x50) = 0;
        W(arg0, 0x54) = (s32)&D_800F88B4;
        W(arg0, 0x68) = (s32)&D_800F88B8;
        set_animation(a, 0x10);
        sub = SB(arg0, 0x2);
        B(arg0, 0x3) = 0;
        B(arg0, 0x5) = 1;
        if (sub == 0x10) {
            x = 0x50;
            y = -0x50;
            H(arg0, 0x82) = x;
            H(arg0, 0x86) = y;
            B(arg0, 0x15) = 0;
        } else if (sub == 0x11) {
            x = 0xF0;
            y = -0x50;
            H(arg0, 0x82) = x;
            H(arg0, 0x86) = y;
            B(arg0, 0x15) = 0x40;
        }
    } else if (kind == 0x20) {
        void* a = arg0;
        B(arg0, 0x60) = 8;
        B(arg0, 0x5C) = 0;
        W(arg0, 0x58) = (s32)&D_80075B9C;
        B(arg0, 0x61) = 0;
        B(arg0, 0x65) = 0;
        W(arg0, 0x50) = 0;
        W(arg0, 0x54) = 0;
        W(arg0, 0x68) = (s32)&D_800F88BC;
        set_animation(a, 0x10);
        B(arg0, 0x3) = 0;
        B(arg0, 0x5) = 2;
    }
    B(arg0, 0x6) = 0;
    B(arg0, 0x4)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80030ECC();
void collide_solid_object(void*);
void func_8003208C(void*);
s32 func_80032B34(struct X4_PlayerObj*);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_800F88CC[])(void*);

#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define BG ((u8*)&background_objects[0])
#define PL ((u8*)&g_Player)

void func_800EB2E8(u8* self) {
    u8* parent;
    s8 st;
    s32 y;

    parent = *(u8**)(self + 0x7C);
    S32(self, 0x18) = S32(self, 0x8);
    S32(self, 0x1C) = S32(self, 0xC);
    st = S8(parent, 0x4);
    if (st != 1) {
        S8(self, 0x3) = 0;
        S8(self, 0x5) = 0;
        U8(self, 0x4)++;
        return;
    }
    if ((S8(self, 0x2) & 0xF0) != 0x20) {
        u8* bg = BG;
        s32 t;
        U16(self, 0xA) = U16(self, 0x82) + (U16(bg, 0xA) + U16(bg, 0x5E));
        t = U16(bg, 0xE) + 0x3B8;
        t -= U16(bg, 0x62);
        y = U16(self, 0x86) + t;
        U16(self, 0xE) = y;
        if (S8(parent, 0x5) == 9) {
            U16(self, 0xE) = y + 0x10;
        }
    } else {
        U16(self, 0xA) = U16(parent, 0xA);
        U16(self, 0xE) = U16(parent, 0xE);
        if (S8(parent, 0x8F) == 0 || S8(parent, 0x8F) == st) {
            return;
        }
    }
    if (S8(parent, 0x5) != 2) {
        // !FAKE: depin: dropping it breaks the match (114/120)
        register s32 k asm("$3");
        D_800F88CC[S8(self, 0x5)](self);
        func_80030ECC(self);
        k = S8(self, 0x2) & 0xF0;
        if (k == 0x10) {
            collide_solid_object(self);
        } else {
            u8* pl = PL;
            if (U8(pl, 0xE5) == 0) {
                collide_solid_object(self);
                k = S8(self, 0x2) & 0xF0;
                if (k == 0x20 && S8(parent, 0x91) == 1 &&
                    (U8(self, 0x72) & 4) && (U8(pl, 0x89) & 8)) {
                    S8(pl, 0x71) = 0;
                }
            }
        }
        func_80032B34((struct X4_PlayerObj*)self);
        func_8003208C(self);
    }
}

#undef S8
#undef U8
#undef U16
#undef S32
#undef BG
#undef PL
