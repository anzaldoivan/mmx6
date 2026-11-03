#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_PlayerObj g_Player;

void func_800E9A34(u8* arg0) {
    s16* p;
    s16 y;

    if (D_800CCEED == 1) {
        p = *(s16**)(arg0 + 0x18);
    } else {
        p = *(s16**)(arg0 + 0x18);
        y = p[7];
        if (D_80097206 < y) {
            return;
        }
        if (g_Player.x_pos.i.hi < p[6]) {
            return;
        }
        if (g_Player.y_pos.i.hi < y + 0x24) {
            return;
        }
    }
    ((void (*)(s32, s32, s32, u8*))func_80027BA0)(0, p[0], p[1], (u8*)(p + 2));
    arg0[4]++;
}

#define func_80041AB8 func_800E9AE0
#define D_80075FD8 D_800ED0A8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

extern u8 D_800ED098[];

void func_800E9B1C(u8* arg0) {
    arg0[0x14] = 0;
    *(u8**)(arg0 + 0x18) = (((s8*)arg0)[2] << 4) + D_800ED098;
    arg0[4] = arg0[4] + 1;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002C9D4(); /* extern */

void func_800E9B48(void) {
    func_8002C9D4();
}

// clang-format off
INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800E9B68);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern u8 D_800ED718[];
extern M2C_UNK D_800ED6F8;

void func_800E9CA8(struct X4_BaseObj* self) {
    u8 flags;
    s32 dir;

    {
        // !FAKE: depin: dropping it breaks the match (106/108)
        register s32 x asm("$2") = M2C_FIELD(self, s32*, 0x8);
        s32 y = M2C_FIELD(self, s32*, 0xC);
        M2C_FIELD(self, s32*, 0x18) = x;
        M2C_FIELD(self, s32*, 0x1C) = y;
    }
    {
        u8* tbl = D_800ED718;
        void* fn = ((void**)tbl)[self->action];
        ((void (*)(struct X4_BaseObj*))fn)(self);
    }
    animate_object(self);
    func_80030ECC(self);
    if (check_enemy_hits(self) < 0) {
        func_80049E50(self);
        func_800477E4(3, &D_800ED6F8, self);
        func_8004E654(self, 0x12);
        self->state = 2;
        return;
    }
    if (is_off_screen(self, 0xA0, 0x78) == 0) {
        func_8002CCB0(self, 0x20, 0x20);
        if (self->on_screen != 0) {
            if (M2C_FIELD(SPAD, s16*, 0x84) != 0) {
                if (M2C_FIELD(SPAD, u16*, 0x84) & 1) {
                    self->on_screen = 1;
                } else {
                    self->on_screen = 0;
                }
                M2C_FIELD(SPAD, u16*, 0x84) -= 1;
            }
        }
    } else {
        self->state = 3;
        return;
    }
    flags = M2C_FIELD(self, u8*, 0x70);
    if ((flags & 0xC) == 0xC || (flags & 3) == 3) {
        func_80049E50(self);
        M2C_FIELD(self, s32*, 0x20) = 0;
        func_800477E4(3, &D_800ED6F8, self);
        self->state = 2;
        return;
    }
    if (flags & 8) {
        M2C_FIELD(self, s8*, 0x67) = 0;
    } else {
        dir = M2C_FIELD(self, s32*, 0x24);
        if (dir < 0) {
            dir = -1;
        } else {
            dir = 1;
        }
        M2C_FIELD(self, s8*, 0x67) = dir;
    }
    func_8002F288((M2C_UNK*)self);
}

// clang-format off
INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800E9E58);

INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EA080);

INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EA29C);

INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EA4B0);

INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EA6C4);

INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EA8D8);

INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EAAF0);

INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EAD18);

INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EAF30);

INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EB048);
// clang-format on

#define func_80041AB8 func_800EB2C4
#define D_80075FD8 D_800ED708
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EB300
#define D_80075FD8 D_800ED778
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EB33C(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EB35C(void) {
    func_8002CA54();
}

#define func_800EC4B4 func_800EB37C
#include "../shared/rock_11/func_800EC4B4.c"
#undef func_800EC4B4

#define func_8003744C func_800EB404
#define D_80073C1C D_800ED75C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EB440);
// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
void func_800EB6C8(struct X4_MainObj*);
extern struct X4_PlayerObj g_Player;
extern u8 D_800ED700[];
extern u8 D_800ED748[];

void func_800EB480(struct X4_BaseObj* self) {
    s8 state = *(s8*)((u8*)self + 0x45);

    if (state == 1) {
        *(u8**)((u8*)self + 0x54) = D_800ED700;
    } else if (state == 2) {
        if (*(s16*)((u8*)self + 0x7C) == 0) {
            s16 px, py;
            s32 a;
            u8* tbl;
            func_800EB6C8((struct X4_MainObj*)self);
            px = g_Player.x_pos.i.hi;
            py = g_Player.y_pos.i.hi;
            a = ratan2(self->y_pos.i.hi - py, px - self->x_pos.i.hi);
            a += 0x800;
            tbl = D_800ED748;
            SPAD[0x8C] = tbl[a >> 8];
            set_animation(self, SPAD[0x8C]);
        } else {
            set_animation(self, SPAD[0x8C]);
        }
        self->action_phase++;
    }
}

#define func_800EC6AC func_800EB574
#include "../shared/rock_11/func_800EC6AC.c"
#undef func_800EC6AC

#include "common.h"

void func_800EB5E8(void) {
}

#define func_800EC728 func_800EB5F0
#define g_enemies g_enemies
#include "../shared/rock_11/func_800EC728.c"
#undef func_800EC728
#undef g_enemies

#define func_800EC7A0 func_800EB668
#include "../shared/rock_11/func_800EC7A0.c"
#undef func_800EC7A0

#define func_80042C18 func_800EB6C8
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#define func_800EC514 func_800EB6F8
#include "../shared/rock_32/func_800EC514.c"
#undef func_800EC514

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                       /* extern */
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(void*);                     /* extern */
M2C_UNK func_8002EE10(void*);                   /* extern */
M2C_UNK func_80030ECC(void*);                   /* extern */
M2C_UNK func_80049D90(void*);                   /* extern */

void func_800EB7C8(void* arg0) {
    animate_object();
    move_object(arg0);
    func_80030ECC(arg0);
    if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
        (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
        func_80049D90(arg0);
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    if (is_off_screen(arg0, 0x18, 0x18) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB878(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
extern void (*D_800ED784[])(void*);
extern void (*D_800ED78C)(void*);

#define F530_FLD(p, type, off) (*(type*)((u8*)(p) + (off)))
static inline u8 f530_tile(struct X4_PlayerObj* p, s16 x, s16 y) {
    if (p->terrain_box == 0) {
        return 0;
    }
    return func_80030234(p, x, y);
}
#define F530_TILE(dy)                                                          \
    f530_tile(&g_Player, g_Player.x_pos.i.hi,                                  \
              g_Player.terrain_box->unk1 +                                     \
                  (g_Player.y_pos.i.hi + g_Player.terrain_box->unk3) + (dy))
#define F530_MAX(a, b) ((a) > (b) ? (a) : (b))
#define F530_MIN(a, b) ((a) < (b) ? (a) : (b))
#define F530_ABS(x) ((x) >= 0 ? (x) : -(x))
#define F530_NEG()                                                             \
    {                                                                          \
        g_Player.x_pos.val =                                                   \
            F530_FLD(&g_Player, s32, 0x13C) +                                  \
            F530_MAX(dx - 0x38000, -F530_FLD(&g_Player, s32, 0x104));          \
        g_Player.y_pos.val += F530_ABS(                                        \
            F530_MAX(dx - 0x38000, -F530_FLD(&g_Player, s32, 0x104)));         \
    }
#define F530_POS()                                                             \
    {                                                                          \
        g_Player.x_pos.val =                                                   \
            F530_FLD(&g_Player, s32, 0x13C) +                                  \
            F530_MIN(dx + 0x38000, F530_FLD(&g_Player, s32, 0x104));           \
        g_Player.y_pos.val +=                                                  \
            F530_ABS(F530_MIN(dx + 0x38000, F530_FLD(&g_Player, s32, 0x104))); \
    }

void func_800EB898(u8* arg0) {
    s32 dx;

    arg0[0x21] = arg0[0x20];
    arg0[0x20] = F530_TILE(0);
    dx = g_Player.x_pos.val - F530_FLD(&g_Player, s32, 0x13C);
    if (g_Player.state == 1) {
    loop:
        switch (arg0[0x20]) {
        case 17:
        case 18:
        case 19:
        case 20:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && g_Player.facing != 0 &&
                g_Player.action != 0xC) {
                g_Player.x_pos.val = F530_FLD(&g_Player, s32, 0x13C);
            } else {
                F530_NEG();
            }
            // !FAKE: goto enters the retile switch; merging cases moved bytes
            goto tail;
        case 21:
        case 22:
        case 23:
        case 24:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && g_Player.facing == 0 &&
                g_Player.action != 0xC) {
                g_Player.x_pos.val = F530_FLD(&g_Player, s32, 0x13C);
            } else {
                F530_POS();
            }
            // !FAKE: goto enters the retile switch; merging cases moved bytes
            goto tail;
        case 25:
        case 26:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && g_Player.facing != 0 &&
                g_Player.action != 0xC) {
                g_Player.x_pos.val = F530_FLD(&g_Player, s32, 0x13C);
            } else {
                F530_NEG();
            }
            // !FAKE: goto enters the retile switch; merging cases moved bytes
            goto tail;
        case 27:
        case 28:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && g_Player.facing == 0 &&
                g_Player.action != 0xC) {
                g_Player.x_pos.val = F530_FLD(&g_Player, s32, 0x13C);
            } else {
                F530_POS();
            }
            // !FAKE: goto enters the retile switch; merging cases moved bytes
            goto tail;
        case 16:
            arg0[0x20] = F530_TILE(-0x10);
            // !FAKE: goto re-dispatches the outer switch on the retiled value; a loop wrapper would add a test
            goto loop;
        case 0:
            if (g_Player.latched_collision_flags & 8) {
                // !FAKE: goto shares case 60's call; copied call+break moved
                goto call;
            }
            if ((s8)arg0[4] == 2) {
                D_800ED78C(arg0);
            }
            arg0[0x1C] = g_Player.action;
            break;
        default:
            arg0[4] = 1;
            arg0[0x1C] = g_Player.action;
            break;
        tail:
            switch (arg0[0x20] = F530_TILE(0)) {
            case 0:
                if ((s8)arg0[4] != 2) {
                    D_800ED784[(s8)arg0[4]](arg0);
                }
                arg0[0x1C] = g_Player.action;
                break;
            case 0x10 ... 0x1C:
            case 0x38:
                break;
            default:
                // !FAKE: goto shares case 60's call; copied call+break moved
                goto call;
            }
            break;
        case 60:
        call:
            D_800ED784[(s8)arg0[4]](arg0);
            arg0[0x1C] = g_Player.action;
            break;
        }
    }
    if (g_Player.x_pos.val != F530_FLD(&g_Player, s32, 0x13C)) {
        arg0[0x1E] =
            g_Player.x_pos.val < F530_FLD(&g_Player, s32, 0x13C) ? 0 : 0x40;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800EBCFC);
// clang-format on

#define func_800F0CF4 func_800EC05C
#define g_Player g_Player
#include "../shared/rock_07/func_800F0CF4.c"
#undef func_800F0CF4
#undef g_Player

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC410(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x1C) = 0;
    M2C_FIELD(arg0, s8*, 0x1E) = 0;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

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

    if (b->terrain_box == 0) {
        return 0;
    }
    if (b->action != 2 && b->action != 4 && b->action != 0x14 &&
        b->action != 3) {
        return 0;
    }
    ra = a->terrain_box;
    ax = a->x_pos.i.hi;
    rb = b->terrain_box;
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
    return ((volatile struct X4_PlayerObj*)a)->terrain_box->unk3 +
               ((volatile struct X4_PlayerObj*)b)->terrain_box->unk3 >=
           d;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EC53C (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
struct X4_VisualObj* find_free_visual_obj(void);
extern u32* D_80095098;
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800ED7D0;
extern s32 D_800ED7DC;

#define F(type, off) M2C_FIELD(self, type*, off)
#define G(type, off) M2C_FIELD(obj, type*, off)
#define SLOT(i) (g_playthrough_state.character_state.bytes[(i) + 6])

void func_800EC53C(void* self) {
    s32 a;
    s32 b;
    s32 i;
    s32 n;
    s8 t;
    s32 one;
    s32 k;
    s8 v;
    void* obj;

    F(u8, 0) = 0x41;
    F(u8, 0x16) = 4;
    F(u16, 0x40) = D_80095098[func_8002A47C(0x94)] >> 7;
    F(u8*, 0x3C) = (u8*)SPAD20_800EC53C + SPAD20_800EC53C[func_8002A47C(0x94)];
    a = func_8002A47C(0x94);
    b = func_8002A47C(0x94);
    a = a * 4;
    F(s16, 0x42) = ((a + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    F(void*, 0x30) = &D_800ED7D0;
    t = F(s8, 2);
    F(void*, 0x68) = &D_800ED7DC;
    F(u8, 0x75) = 0;
    if (t == 10) {
        i = 8;
        n = 0;
        for (; i < 16; i++) {
            if ((&D_800CCEF6)[i] != 0) {
                n++;
            }
        }
        if (n < 8) {
            F(u8, 4) = 2;
            return;
        }
        F(u8, 4) = 1;
        F(u8, 5) = 0;
        F(u8, 2) &= 0xF;
        set_animation(self, 0);
        k = 1;
        obj = find_free_visual_obj();
        if (obj != 0) {
            G(u8, 0) = 0x51;
            G(u8, 1) = 0x18;
            G(u8, 2) = k;
            G(u8, 0x16) = k;
            G(u8, 0x15) = 0;
            G(u8, 0x14) = F(u8, 0x14);
            G(u16, 0xA) = F(u16, 0xA);
            G(u16, 0xE) = F(u16, 0xE) - 0x1C;
            G(u16, 0x42) = F(u16, 0x42);
            G(u16, 0x40) = F(u16, 0x40);
            G(s32, 0x3C) = F(s32, 0x3C);
            G(void*, 0x30) = F(void*, 0x30);
            G(void*, 0x50) = self;
        }
        return;
    }
    one = 1;
    v = SLOT(t);
    switch (v) {
    case 0:
        F(u8, 2) &= 0xF;
        F(u8, 5) = 0;
        set_animation(self, 0);
        obj = find_free_visual_obj();
        if (obj != 0) {
            G(u8, 0) = 0x51;
            G(u8, 1) = 0x18;
            G(u8, 2) = 0;
            G(u8, 0x16) = one;
            G(u8, 0x15) = 0;
            G(u8, 0x14) = F(u8, 0x14);
            G(u16, 0xA) = F(u16, 0xA);
            G(u16, 0xE) = F(u16, 0xE) - 0x1C;
            G(u16, 0x42) = F(u16, 0x42);
            G(u16, 0x40) = F(u16, 0x40);
            G(s32, 0x3C) = F(s32, 0x3C);
            G(void*, 0x30) = F(void*, 0x30);
            G(void*, 0x50) = self;
        }
        break;
    case 1:
        F(u8, 2) &= 0xF;
        F(s8, 5) = v;
        set_animation(self, 0);
        {
            // !FAKE: depin: dropping it breaks the match (198/201)
            register s32 x asm("$2") = F(s8, 2);
            s32 two = 2;
            SLOT(x) = two;
        }
        break;
    case 2:
    default:
        F(u8, 5) = 2;
        F(u8, 2) &= 0xF;
        set_animation(self, 0);
        break;
    }
    F(u8, 6) = 0;
    F(u8, 7) = 0;
    F(u8, 4)++;
}

#define func_80048DC8 func_800EC860
#define D_80077BC0 D_800ED800
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_80041AB8 func_800EC8AC
#define D_80075FD8 D_800ED80C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
s32 func_800EC430(struct X4_PlayerObj* a, struct X4_PlayerObj* b);
extern struct X4_PlayerObj g_Player;

void func_800EC8E8(struct X4_PlayerObj* arg0) {
    u8 temp_a2;

    if (func_800EC430(arg0, &g_Player) != 0) {
        g_Player.x_pos.i.hi = arg0->x_pos.i.hi;
        temp_a2 = g_Player.terrain_box->unk3;
        g_Player.y_pos.i.hi = arg0->y_pos.i.hi - temp_a2;
        ((s32(*)(s32, s32, s32))func_8003D308)(0x14, g_Player.facing, temp_a2);
        arg0->action_phase = arg0->action_phase + 1;
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC95C(void* arg0) {
    if (D_800970A5 == 0x14) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x2A;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);

void func_800EC98C(void* arg0) {
    ((void (*)())animate_object)();
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        play_sound(1, 1, arg0);
        ((void (*)(M2C_UNK, M2C_UNK))func_8003D308)(0x16, D_800970B5);
        M2C_FIELD(arg0, u16*, 0x7C) = 0x28;
        {
            // !FAKE: pin the increment temp to the register retail uses
            register s32 t asm("$3") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_8003D330();
extern s8 D_80097170;
extern struct X4_EngineObj g_playthrough_state;

void func_800EC9FC(void* arg0) {
    s32 i;
    s8* p;

    ((void (*)())animate_object)();
    if ((M2C_FIELD(arg0, s16*, 0x7C) == 0 ||
         --M2C_FIELD(arg0, s16*, 0x7C) == 0) &&
        D_80097170 < 0) {
        ((void (*)())func_8003D330)();
        if (M2C_FIELD(arg0, s8*, 2) != 0xA) {
            g_playthrough_state.checkpoint = M2C_FIELD(arg0, u8*, 2) & 0xF;
            g_playthrough_state.unkF = -0x40;
        } else {
            g_playthrough_state.unkF = 0x40;
            i = 0xF;
            p = &g_playthrough_state.character_state.bytes[0xF];
            do {
                *p = 0;
                i--;
                p--;
            } while (i >= 0);
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

void func_800ECAC0(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800ECAC8);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CB50();

void func_800ECB14(s8* arg0) {
    if (arg0[7] < 0xA) {
        ((void (*)())animate_object)();
        if (arg0[0x45] & 0x80) {
            ((u8*)arg0)[0x45] &= 0x7F;
            ((u8*)arg0)[7]++;
        }
    }
    func_8002CB50(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CB50(); /* extern */

void func_800ECB7C(void) {
    func_8002CB50();
}

// clang-format off
INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800ECB9C);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECBE8(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800ECC08(s8* arg0) {
    if (arg0[2] == 0) {
        set_animation(arg0, 1);
    } else {
        set_animation(arg0, 2);
    }
    ((u8*)arg0)[4] = ((u8*)arg0)[4] + 1;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object();   /* extern */
M2C_UNK func_8002CB50(s32); /* extern */

void func_800ECC60(s32 arg0) {
    animate_object();
    func_8002CB50(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECC8C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_14/nonmatchings/E9860", func_800ECCAC);
// clang-format on
