/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_fade, AGPL-3.0; proven shared with X6 by exact signature 246e79a6823b (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK animate_object();
M2C_UNK clear_object_slot(void*, void*);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_80049670(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1) {
    ((void (*)())animate_object)(arg0);
    if (arg0->animation_step.fields.relative_step < 0) {
        ((void (*)())clear_object_slot)(arg0);
        return;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
}

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_attach, AGPL-3.0; proven shared with X6 by exact signature 3cea93403e4f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_VisualAttachmentOffset D_80077BF4[2];

void func_800496C0(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1) {
    arg0->unk15 = arg1->facing;
    if (arg0->unk15 == 0) {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi + D_80077BF4[arg1->character].x;
    } else {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi - D_80077BF4[arg1->character].x;
    }
    arg0->y_pos.i.hi = arg1->y_pos.i.hi + D_80077BF4[arg1->character].y;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s16 D_80077BFC[][2];

void func_80049748(struct X4_BaseObj* arg0, struct X4_BaseObj* arg1) {
    s32 idx;
    u8 t;

    idx = arg1->unk2;
    if (idx == 0) {
        if (arg1->action == 0x23) {
            idx = 2;
        }
    }
    if (arg1->action == 0x1F) {
        idx = 3;
    }
    t = arg1->unk15;
    arg0->unk15 = t;
    if (t == 0) {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi + D_80077BFC[idx][0];
    } else {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi - D_80077BFC[idx][0];
    }
    arg0->y_pos.i.hi = arg1->y_pos.i.hi + D_80077BFC[idx][1];
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
void func_80049854(struct X4_ShotObj* arg0);
void func_80049950(struct X4_VisualObj* arg0);
void func_800499A0(void* arg0);

M2C_UNK func_80049800(void* arg0, void* arg1) {
    ((M2C_UNK(*)())animate_object)();
    func_800499A0(arg0);
    if (((s8*)arg0)[5] == 0) {
        func_80049854(arg0);
    } else {
        func_80049950(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002C32C();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
extern struct X4_PlayerObj g_Player;

void func_80049854(struct X4_ShotObj* arg0) {
    struct X4_ShotObj* p;
    s8 v;

    if (arg0->animation_step.fields.event != 0) {
        v = arg0->unk2;
        if (v != 0 && v != 0x2D) {
            p = func_8002C32C();
            if (p != 0) {
                p->active = 0x21;
                p->id = arg0->unk2;
                p->unk2 = 0;
                p->x_pos = arg0->x_pos;
                p->y_pos = arg0->y_pos;
                p->unk15 = arg0->unk15;
                p->unk3C = arg0->unk3C;
                p->animation_table = arg0->animation_table;
                p->unk40 = arg0->unk40;
                p->unk42 = arg0->unk42;
                p->unk16 = arg0->unk16;
                {
                    u8* pl = (u8*)&g_Player;
                    pl[0x98]++;
                }
            }
        }
        arg0->action++;
    }
    func_8002CCB0(arg0, 0x40, 0x20);
}

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_02_charge_muzzle_flash.c:charge_muzzle_flash_fade, AGPL-3.0; proven shared with X6 by exact signature eb3a6db008dc (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK clear_object_slot(void*, void*);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_80049950(struct X4_VisualObj* arg0) {
    if (arg0->animation_step.fields.relative_step == 0 ||
        arg0->unk5C.value != 0) {
        ((void (*)())clear_object_slot)(arg0);
    } else {
        func_8002CCB0(arg0, 0x40, 0x20);
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
s32 func_801EE34C();

void func_800499A0(void* arg0) {
    s8* p = (s8*)arg0;

    if (p[0x5C] == 0) {
        u8* pl = (u8*)&g_Player;

        if (((s8*)pl)[0x8E] == 0) {
            p[0x5C] = 1;
        }
        if (pl[0x15] != ((u8*)p)[0x15]) {
            p[0x5C] = 1;
        }
        if (p[0x5C] == 0) {
            func_801EE34C(arg0, pl, p[2]);
        }
    }
}

// clang-format off
#include "../shared/SLUS_013.95/func_80049A14.c"
// clang-format on

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

struct X4_VisualObj* find_free_visual_obj(void);

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_80049D90(void* arg0) {
    struct X4_VisualObj* self = arg0;
    struct X4_VisualObj* obj;
    u8* tbl;
    s32 off;
    u8 bg;

    obj = find_free_visual_obj();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        obj->unk2 = 1;
        bg = D_800970B4;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->unk38 = 0;
        obj->bg_offset = bg;
        tbl = SCRATCH_1C;
        off = *(s32*)(tbl + 4);
        obj->animation_table = g_visual_animation_tables;
        obj->unk40 = 0;
        obj->unk42 = 0x7802;
        obj->unk16 = 0;
        obj->unk15 = 0;
        obj->unk3C = tbl + off;
        if (self->x_vel.val > 0) {
            obj->unk15 = 0x40;
        }
        obj->x_pos.i.hi = self->x_pos.i.hi;
        obj->y_pos.i.hi = self->y_pos.i.hi;
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_42_homing_orb.c:homing_orb_start_idle, AGPL-3.0; proven shared with X6 by exact signature 260a65053a4e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_80049E70(void* arg0, s8 arg1);

void func_80049E50(struct X4_MainObj* self) {
    func_80049E70(self, 0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();                        /* extern */
M2C_UNK func_8004A0C0(s8, s16, s16, s32); /* extern */

void func_80049E70(void* arg0, s8 arg1) {
    func_8004A0C0(arg1, M2C_FIELD(arg0, s16*, 0xA), M2C_FIELD(arg0, s16*, 0xE),
                  (random_byte() & 1) ^ 1);
}

#include "common.h"

s32 random_byte();
extern u8 D_800E4470[];
#define D_800E4470 (*(u8*)&D_800E4470)

#define M2C_UNK s32
M2C_UNK func_8004A0C0(s8, s16, s16, s32);
void func_80049EBC(void* arg0, s8 arg1, u8 arg2, u8 arg3) {
    s16 x;
    s16 y;
    s32 n;

    arg2 &= random_byte();
    if (random_byte() & 1) {
        x = ((s16*)arg0)[5] + arg2;
    } else {
        x = ((s16*)arg0)[5] - arg2;
    }
    arg3 &= random_byte();
    if (random_byte() & 1) {
        y = ((s16*)arg0)[7] + arg3;
    } else {
        y = ((s16*)arg0)[7] - arg3;
    }
    n = D_800E4470 + 1;
    D_800E4470 = n;
    ((void (*)())func_8004A0C0)(arg1, x, y, (n & 1) ^ 1);
}
#undef D_800E4470

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 random_byte();
s32 func_8002D30C();
M2C_UNK func_8004A0C0(s8, s16, s16, s32);
extern u8 D_800E4470[];

void func_80049F98(struct X4_BaseObj* self, s8 arg1, u8 arg2, u8 arg3,
                   u8 arg4) {
    s16 x;
    s16 y;
    s32 r;
    s32 a3;
    s32 t;

    arg2 &= random_byte();
    if (random_byte() & 1) {
        x = self->x_pos.u.hi + arg2;
    } else {
        x = self->x_pos.u.hi - arg2;
    }
    arg3 &= random_byte();
    if (random_byte() & 1) {
        y = self->y_pos.u.hi + arg3;
    } else {
        y = self->y_pos.u.hi - arg3;
    }
    r = func_8002D30C();
    if (arg4 == 0 || r % arg4 == 0) {
        u8* p = &D_800E4470[1];
        t = *p + 1;
        *p = t;
        a3 = 3;
        if (t & 1) {
            a3 = 2;
        }
    } else {
        a3 = 0xFF;
    }
    func_8004A0C0(arg1, x, y, a3);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

struct X4_VisualObj* find_free_visual_obj(void);

M2C_UNK func_8004A0C0(s8 arg0, s16 arg1, s16 arg2, s32 arg3) {
    struct X4_VisualObj* obj;
    u8 v = arg3;

    obj = find_free_visual_obj();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 4;
        obj->unk2 = 0;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->unk5C.value = v;
        obj->x_pos.i.hi = arg1;
        obj->x_pos.i.lo = 0;
        obj->y_pos.i.hi = arg2;
        obj->y_pos.i.lo = 0;
        obj->unk15 = 0;
        obj->bg_offset = 0;
        obj->unk16 = 1;
    }
    return (M2C_UNK)obj;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004A194();    /* extern */
M2C_UNK func_8004A250(); /* extern */

void func_8004A154(struct ObjectHeader* arg0) {
    if (arg0->state == 0) {
        func_8004A194();
        return;
    }
    func_8004A250();
}

// clang-format off
#include "../shared/SLUS_013.95/func_8004A194.c"
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK clear_object_slot();
M2C_UNK func_8002CB50();
M2C_UNK move_object(void*);

M2C_UNK func_8004A250(void* arg0) {
    ((void (*)())animate_object)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
        ((M2C_UNK(*)())clear_object_slot)(arg0);
    } else {
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            move_object(arg0);
        }
        func_8002CB50(arg0);
    }
}

// clang-format off
#include "../shared/SLUS_013.95/func_8004A2B4.c"

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/4228C", func_8004A768);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* find_free_visual_obj(void);
s32 random_byte();

extern s32 D_80077D58[];
extern s32 D_80077D78[];

#define U8(o) M2C_FIELD(v, u8*, o)
#define S16(o) M2C_FIELD(v, s16*, o)
#define S32(o) M2C_FIELD(v, s32*, o)

void func_8004A998(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    struct X4_VisualObj* v;
    s16 i;
    u32 kind;
    s32 t;
    s32 u;
    s32 rx;
    s32 ry;
    s16 d;

    i = 0;
    kind = arg0;
    for (; i < arg5; i++) {
        v = find_free_visual_obj();
        if (v != 0) {
            U8(0x0) = 0x21;
            U8(0x1) = 9;
            U8(0x2) = 0;
            t = random_byte();
            u = random_byte();
            t <<= 8;
            t += u;
            t += 1;
            rx = t & 0xFFFF;
            do {
                t = random_byte();
            } while (0);
            u = random_byte();
            t <<= 8;
            t += u;
            t += 1;
            t &= 0xFFFF;
            {
                // !FAKE: depin: dropping it breaks the match (140/185)
                register s32 a asm("$4") = arg3;
                // !FAKE: depin: dropping it breaks the match (179/185)
                register s32 e asm("$3") = (s16)(a - arg1);
                if (e == 0) {
                    S16(0xA) = arg1;
                } else {
                    S16(0xA) = arg1 + rx % e;
                }
            }
            d = arg4 - arg2;
            if (d == 0) {
                S16(0xE) = arg2;
            } else {
                S16(0xE) = arg2 + t % d;
            }
            S16(0x8) = 0;
            S16(0xC) = 0;
            switch ((s32)(kind & 0xF)) {
            case 1:
                S32(0x20) = D_80077D78[random_byte() & 7] * 4;
                S32(0x24) = D_80077D58[random_byte() & 3] * 4;
                break;
            case 2:
                S32(0x20) = -(D_80077D78[random_byte() & 7] * 4);
                S32(0x24) = D_80077D58[random_byte() & 3] * 4;
                break;
            case 4:
                S32(0x20) = -(D_80077D78[random_byte() & 7] * 4);
                S32(0x24) = -(D_80077D58[random_byte() & 3] * 4);
                break;
            case 8:
                S32(0x20) = D_80077D78[random_byte() & 7] * 4;
                S32(0x24) = -(D_80077D58[random_byte() & 3] * 4);
                break;
            default:
                S32(0x20) = 0;
                S32(0x24) = 0;
                break;
            }
            U8(0x15) = 0;
            U8(0x5C) = kind >> 4;
            U8(0x4) = 0;
            U8(0x5) = 0;
            U8(0x6) = 0;
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004ACBC(void*); /* extern */
void func_8004AD78();      /* extern; was M2C_UNK (W15 regate of 4AD78) */

void func_8004AC7C(struct ObjectHeader* arg0) {
    if (arg0->state == 0) {
        func_8004ACBC(arg0);
        return;
    }
    func_8004AD78();
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CB50();
s32 random_byte();
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_8004ACBC(void* arg0) {
    u8* sp;

    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s32*, 0x38) = 0;
    sp = SCRATCH_1C;
    {
        s32 off = *(s32*)(sp + 8);
        M2C_FIELD(arg0, void**, 0x30) = &D_80077E34;
        M2C_FIELD(arg0, u8**, 0x3C) = sp + off;
    }
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    M2C_FIELD(arg0, s16*, 0x40) = 0;
    if (M2C_FIELD(arg0, s8*, 0x5C) != 2) {
        M2C_FIELD(arg0, s16*, 0x42) = 0x7805;
    } else {
        M2C_FIELD(arg0, s16*, 0x42) = 0x7806;
    }
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, s8*, 0x16) = 1;
    }
    set_animation(arg0, M2C_FIELD(arg0, s8*, 0x5C));
    {
        // !FAKE: pin the incremented byte to the first return register
        register s32 n asm("$2") = M2C_FIELD(arg0, u8*, 4) + 1;
        M2C_FIELD(arg0, u8*, 4) = n;
    }
    M2C_FIELD(arg0, s8*, 7) = random_byte() & 1;
    func_8002CB50(arg0);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK clear_object_slot();
s32 func_8002CB50(struct X4_BaseObj*);
#define clear_object_slot ((M2C_UNK(*)(u8*))clear_object_slot)
#define func_8002CB50 func_8002CB50
M2C_UNK move_object(void*);
#include "mmx6/state.h"

void func_8004AD78() {
    // !FAKE: depin: dropping it breaks the match (39/41)
    register u8* a0 asm("$4");
    u8* arg0 = a0;
    u8 temp_v1;

    move_object(arg0);
    ((void (*)(u8*))animate_object)(arg0);
    if (*(s8*)(arg0 + 0x46) == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        arg0[0x5C] = 0;
        clear_object_slot(arg0);
        return;
    }
    temp_v1 = arg0[0x5C];
    arg0[3] = 0;
    if (!(temp_v1 & 3) || (temp_v1 & 1)) {
        if ((D_80097420.frame_counter & 1) == *(s8*)(arg0 + 7)) {
            func_8002CB50(arg0);
        }
    } else {
        func_8002CB50(arg0);
    }
}

#undef clear_object_slot
#undef func_8002CB50

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */
extern u16 D_800CF856;

#define SCRATCH_3C (*(u8**)0x1F80003C)
#define F8(o) (*(s8*)(p + (o)))
#define F16(o) (*(s16*)(p + (o)))
#define FPTR(o) (*(u8**)(p + (o)))

void func_8004AE1C(u8* p, s32 arg1) {
    u8* t;
    s32 off;

    if (D_800970A5 != F8(5) || D_800CF856 != 0x1F) {
        clear_object_slot(p, arg1);
        return;
    }
    if (F8(4) == 0) {
        F8(0x14) = -1;
        t = SCRATCH_3C;
        off = *(s32*)t;
        F16(0x40) = 0x1E00;
        F16(0x42) = 0x7E50;
        F8(0x16) = 0x37;
        F8(4)++;
        FPTR(0x3C) = t + off;
        return;
    }
    F8(3) = 1;
    switch (F8(2)) {
    case 0:
        F16(0xE) -= 8;
        if (F16(0xE) <= 0) {
            F16(0xE) = 0x140;
        }
        if (F16(0xE) >= 0x130) {
            F8(3) = 0;
        }
        break;
    case 1:
        F16(0xA) -= 8;
        if (F16(0xA) < -0x3F) {
            F16(0xA) = 0x140;
            F8(3) = 0;
        }
        break;
    case 2:
        F16(0xA) += 8;
        if (F16(0xA) >= 0x140) {
            F16(0xA) = -0x40;
            F8(3) = 0;
        }
        break;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_80017B04(u8*, s16, s16);
#define func_80017B04 func_80017B04
M2C_UNK clear_object_slot();

#define SCRATCH_14 (*(u8**)0x1F800014)
#define OFS(o) (SCRATCH_14 + *(s32*)(SCRATCH_14 + (o)))

void func_8004AF94(struct X4_VisualObj* arg0) {
    s32 big;

    big = 0;
    if (arg0->unk2 == 0) {
        arg0->unk38 = OFS(0x8);
    } else if (arg0->unk2 == 1) {
        arg0->unk38 = OFS(0x40);
    } else if (arg0->unk2 == 2) {
        if (D_800970A2 != 0) {
            arg0->unk38 = OFS(0xC);
        } else {
            arg0->unk38 = OFS(0x14);
        }
    } else if (arg0->unk2 == 3) {
        arg0->unk38 = OFS(0x44);
    } else if (arg0->unk2 == 4) {
        arg0->unk38 = OFS(0x20);
    } else if (arg0->unk2 == 5) {
        arg0->unk38 = OFS(0x8);
    } else if (arg0->unk2 == 6) {
        arg0->unk38 = OFS(0xC);
        big = 1;
    } else if (arg0->unk2 == 7) {
        arg0->unk38 = OFS(0x10);
        big = 1;
    } else if (arg0->unk2 == 8) {
        arg0->unk38 = OFS(0x3C);
        big = 1;
    } else if (arg0->unk2 == 9) {
        arg0->unk38 = OFS(0x34);
    } else if (arg0->unk2 == 10) {
        arg0->unk38 = OFS(0x1C);
    } else if (arg0->unk2 == 11) {
        arg0->unk38 = OFS(0x2C);
    } else if (arg0->unk2 == 12) {
        arg0->unk38 = OFS(0x24);
    }
    arg0->previous_animation_index = 0xFF;
    arg0->animation_step.fields.frame_index = 0;
    if (big == 0) {
        arg0->unk40 = 0x520;
        arg0->unk49 = 0;
        func_80017B04(arg0, 0x140, 0x20);
    } else {
        arg0->unk40 = 0x540;
        arg0->unk49 = 1;
        func_80017B04(arg0, 0x140, 0x40);
    }
    ((M2C_UNK(*)())clear_object_slot)(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;
s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK set_animation(void* arg0, M2C_UNK arg1);
M2C_UNK animate_object();
M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);

void func_8004B1F4(struct X4_VisualObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    s32 idx;
    u8 f;

    if (arg0->state == 0) {
        s32* frames;
        s32 off;

        arg0->on_screen = 1;
        arg0->unk2 = -1;
        frames = SP_SPRITE_FRAMES;
        off = frames[12];
        arg0->unk40 = 0;
        arg0->animation_table = &g_visual_animation_tables;
        arg0->unk16 = 3;
        arg0->unk42 = 0x7802;
        arg0->unk5C.value = 0;
        arg0->state++;
        arg0->unk3C = (void*)((s8*)frames + off);
    }
    f = player->animation_step.fields.frame_index;
    idx = -1;
    if ((u8)(f + 0x35) < 2) {
        idx = 0;
    }
    if ((u8)(f + 0x3D) < 2) {
        idx = 1;
    }
    if ((u8)(f + 0x3B) < 2) {
        idx = 2;
    }
    if ((u8)(f + 0x39) < 2) {
        idx = 3;
    }
    if ((u8)(f + 0x37) < 2) {
        idx = 4;
    }
    if (idx == -1) {
        ((M2C_UNK(*)())clear_object_slot)(arg0);
        return;
    }
    if (idx != arg0->unk2) {
        set_animation(arg0, idx + 0x20);
        arg0->unk2 = idx;
    } else {
        animate_object(arg0);
    }
    arg0->unk15 = player->facing;
    arg0->x_pos = player->x_pos;
    arg0->y_pos = player->y_pos;
    if (arg0->unk5C.value == 0) {
        arg0->unk5C.value = 8;
        play_sound(0, 0x1F, arg0);
    } else {
        arg0->unk5C.value--;
    }
    func_8002CCB0(arg0, 0x28, 0x28);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
extern struct X4_PlayerObj g_Player;
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_8004B3A0(struct X4_VisualObj* arg0) {
    u8* sp;

    if (g_Player.action != 0x23) {
        ((M2C_UNK(*)())clear_object_slot)();
        return;
    }
    if (arg0->state == 0) {
        sp = SCRATCH_1C;
        arg0->unk3C = sp + *(s32*)(sp + 0x1C);
        arg0->unk40 = 0x500;
        arg0->unk42 = 0x7802;
        arg0->unk16 = 3;
        arg0->unk5C.value = 0;
        arg0->state++;
    }
    arg0->animation_step.fields.frame_index =
        g_Player.animation_step.fields.frame_index - 0x42;
    arg0->unk15 = g_Player.facing;
    arg0->x_pos = g_Player.x_pos;
    arg0->y_pos = g_Player.y_pos;
    if (arg0->unk5C.value == 0) {
        arg0->unk5C.value = 8;
    } else {
        arg0->unk5C.value--;
    }
    func_8002CCB0(arg0, 0x28, 0x28);
}

#define func_80041AB8 func_8004B480
#define D_80075FD8 D_80077E44
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_22_missile_smoke.c:missile_smoke_init, AGPL-3.0; proven shared with X6 by exact signature 350f949ca2ac (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_8004B50C(struct X4_VisualObj*);
#define M2C_UNK s32
M2C_UNK set_animation(void* arg0, M2C_UNK arg1);

void func_8004B4BC(struct X4_VisualObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    if (arg0->unk2 != 0x10) {
        arg0->unk15 = 0;
        func_8004B50C(arg0);
    } else {
        arg0->unk16 = VISUAL_SATURN_LAYER(2);
        set_animation(arg0, 0x25);
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_22_missile_smoke.c:missile_smoke_main, AGPL-3.0; proven shared with X6 by exact signature c82f771f5c19 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK set_animation(void* arg0, M2C_UNK arg1);

M2C_UNK animate_object();
M2C_UNK clear_object_slot(void*, void*);
s32 func_8002CB50(struct X4_BaseObj*);
void func_8004B50C(struct X4_VisualObj* arg0) {
    struct X4_PlayerObj* temp_a0;

    if (arg0->unk2 != 0x10) {
        if (arg0->unk2 <= 6) {
            if (arg0->unk2 == 0) {
                set_animation(arg0, 0x21);
            } else {
                set_animation(arg0, ((arg0->unk2 - 1) >> 1) + 0x21);
            }
            arg0->unk2++;
            ((void (*)())func_8002CB50)(arg0);
        } else {
            arg0->on_screen = 0;
            arg0->state = 2;
        }
    } else {
        temp_a0 = arg0->unk50;
        if (((u8)temp_a0->shot_types[0] == 2) && (temp_a0->active != 0) &&
            (temp_a0->last_shot_type & 0x40)) {
            arg0->unk15 = temp_a0->facing;
            arg0->x_pos.i.hi = temp_a0->x_pos.i.hi;
            arg0->y_pos.i.hi = temp_a0->y_pos.i.hi;
            ((void (*)())animate_object)(arg0);
            ((void (*)())func_8002CB50)(arg0);
            return;
        }
        arg0->on_screen = 0;
        ((void (*)())clear_object_slot)(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004B614(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/4228C", func_8004B634);
// clang-format on

#include "common.h"

#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_8004B788(void* arg0) {
    s16 a;
    s16 b;
    u16 step;
    s32 t;

    t = FU16(arg0, 0x42) + (step = FU16(arg0, 0x40));
    FU16(arg0, 0x42) = t;
    if ((s16)t >= 0x100) {
        FU16(arg0, 0x26) = FU16(arg0, 0x3C);
        FU16(arg0, 0x2A) = FU16(arg0, 0x3E);
        FU8(arg0, 5) = FU8(arg0, 5) + 1;
        return;
    }
    a = F16(arg0, 0x2E);
    b = F16(arg0, 0x32);
    FU16(arg0, 0x40) = step + 1;
    FU16(arg0, 0x26) = a + (((F16(arg0, 0x3C) - a) * (s16)t) >> 8);
    FU16(arg0, 0x2A) = b + (((F16(arg0, 0x3E) - b) * (s16)t) >> 8);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_8004B824(struct X4_UnkObj* arg0) {
    struct X4_AbcObj* abc = &D_8008EAF0;
    s32 d = abc->unkD;

    if (d == 4 && (s16)abc->unkA < 0x1E) {
        arg0->unk40 = d;
        arg0->unk42 = 0;
        arg0->unk5++;
    }
}

#include "common.h"

void func_8004B86C(u8* arg0) {
    s16 temp_a1;
    s16 temp_a2;
    u16 temp_a0;
    u16 temp_v0;

    temp_v0 = *(u16*)(arg0 + 0x42);
    temp_a0 = *(u16*)(arg0 + 0x40);
    temp_v0 = *(u16*)(arg0 + 0x42) = temp_v0 + temp_a0;
    if ((s16)temp_v0 >= 0x100) {
        *(u16*)(arg0 + 0x26) = *(u16*)(arg0 + 0x2E);
        *(u16*)(arg0 + 0x2A) = *(u16*)(arg0 + 0x32);
        arg0[4]++;
        return;
    }
    temp_a2 = *(s16*)(arg0 + 0x3C);
    temp_a1 = *(s16*)(arg0 + 0x3E);
    *(u16*)(arg0 + 0x40) = temp_a0 + 1;
    *(u16*)(arg0 + 0x26) =
        temp_a2 + ((((*(s16*)(arg0 + 0x2E)) - temp_a2) * (s16)temp_v0) >> 8);
    *(u16*)(arg0 + 0x2A) =
        temp_a1 + ((((*(s16*)(arg0 + 0x32)) - temp_a1) * (s16)temp_v0) >> 8);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern void (*D_80077E80[])();

void func_8004B908(struct X4_WeaponObj* arg0) {
    if (D_8008EAFC == 0) {
        arg0->state++;
        return;
    }
    D_80077E80[arg0->unk5](arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004B964(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#define func_80041AB8 func_8004B984
#define D_80075FD8 D_80077E8C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/x4.h"
extern s16 D_80077E98[][16];
extern struct X4_QuadMotionData D_80078138[22];
extern u8 D_800E4478[0x10];

void func_8004B9C0(struct X4_QuadObj* arg0) {
    s32 idx;

    arg0->bg_offset = -1;
    idx = arg0->unk2;
    arg0->unk34 = 4;
    arg0->unk36 = 0x10;
    arg0->on_screen = 1;
    arg0->x_pos.val = 0;
    arg0->y_pos.val = 0;
    arg0->ext.quad_2.x_scale.bytes.fraction = 0;
    arg0->state++;
    if (idx < 0x15) {
        arg0->active |= 0x10;
        arg0->vertices[0].x.i.hi = D_80077E98[idx][0];
        arg0->vertices[0].y.i.hi = D_80077E98[idx][1];
        arg0->vertices[1].x.i.hi = D_80077E98[idx][2];
        arg0->vertices[1].y.i.hi = D_80077E98[idx][3];
        arg0->vertices[2].x.i.hi = D_80077E98[idx][4];
        arg0->vertices[2].y.i.hi = D_80077E98[idx][5];
        arg0->vertices[3].x.i.hi = D_80077E98[idx][6];
        arg0->vertices[3].y.i.hi = D_80077E98[idx][7];
    } else {
        arg0->vertices[0].x.val = D_80078138[idx].vertex[0] << 16;
        arg0->vertices[1].x.val = D_80078138[idx].vertex[2] << 16;
        arg0->vertices[2].x.val = D_80078138[idx].vertex[2] << 16;
        arg0->vertices[3].x.val = D_80078138[idx].vertex[0] << 16;
        arg0->vertices[0].y.val = D_80078138[idx].vertex[1] << 16;
        arg0->vertices[1].y.val = D_80078138[idx].vertex[3] << 16;
        arg0->vertices[2].y.val = D_80078138[idx].vertex[3] << 16;
        arg0->vertices[3].y.val = D_80078138[idx].vertex[1] << 16;
    }
    if (arg0->unk2 == 0x15) {
        arg0->ext.quad_2.x_scale.bytes.integer = 0xF;
    } else {
        arg0->ext.quad_2.x_scale.bytes.integer = 0xA;
    }
    arg0->ext.quad_2.y_scale.bytes.fraction = 0;
    if (arg0->unk2 == 0) {
        D_800E4478[0] = 0;
    }
}

#include "common.h"
#include "mmx6/x4.h"
extern s16 D_80077E98[][16];
extern struct X4_QuadMotionData D_80078138[22];
extern u8 D_800E4478[0x10];

void func_8004BB5C(struct X4_QuadObj* arg0) {
    u8 integer = arg0->ext.quad_2.x_scale.bytes.integer;

    if (integer == 0) {
        arg0->unk5++;
        if (arg0->unk2 == 0x15) {
            D_800E4478[0] = 1;
        } else {
            arg0->active &= ~0x10;
            arg0->vertices[0].x.i.hi = D_80077E98[arg0->unk2][8];
            arg0->vertices[0].y.i.hi = D_80077E98[arg0->unk2][9];
            arg0->vertices[1].x.i.hi = D_80077E98[arg0->unk2][10];
            arg0->vertices[1].y.i.hi = D_80077E98[arg0->unk2][11];
            arg0->vertices[2].x.i.hi = D_80077E98[arg0->unk2][12];
            arg0->vertices[2].y.i.hi = D_80077E98[arg0->unk2][13];
            arg0->vertices[3].x.i.hi = D_80077E98[arg0->unk2][14];
            arg0->vertices[3].y.i.hi = D_80077E98[arg0->unk2][15];
        }
    } else {
        arg0->ext.quad_2.x_scale.bytes.integer = integer - 1;
        if (arg0->unk2 == 0x15) {
            arg0->vertices[0].x.val += FIXED(D_80078138[arg0->unk2].speed[0]);
            arg0->vertices[1].x.val += FIXED(D_80078138[arg0->unk2].speed[0]);
            arg0->vertices[2].x.val += FIXED(D_80078138[arg0->unk2].speed[2]);
            arg0->vertices[3].x.val += FIXED(D_80078138[arg0->unk2].speed[2]);
        } else {
            {
                s32 start = D_80077E98[arg0->unk2][0];
                s32 end = D_80077E98[arg0->unk2][8];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[0].x.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][1];
                s32 end = D_80077E98[arg0->unk2][9];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[0].y.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][2];
                s32 end = D_80077E98[arg0->unk2][10];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[1].x.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][3];
                s32 end = D_80077E98[arg0->unk2][11];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[1].y.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][4];
                s32 end = D_80077E98[arg0->unk2][12];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[2].x.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][5];
                s32 end = D_80077E98[arg0->unk2][13];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[2].y.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][6];
                s32 end = D_80077E98[arg0->unk2][14];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[3].x.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][7];
                s32 end = D_80077E98[arg0->unk2][15];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[3].y.i.hi = (end - start) * t / d + start;
            }
        }
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/quads/quad_03_boss_warning_quad.c:boss_warning_quad_close, AGPL-3.0; proven shared with X6 by exact signature f3f6620a97d2 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_QuadMotionData D_80078138[22];
extern u8 D_800E4478[0x10]; /* sibling TU type; upstream names the first byte */
#define D_800E4478 (*D_800E4478)

void func_8004BEC8(struct X4_QuadObj* arg0) {
    u8 integer = arg0->ext.quad_2.x_scale.bytes.integer;

    if (integer == 0) {
        arg0->state++;
        if (arg0->unk2 == 0x15) {
            D_800E4478 = 0;
        }
    } else {
        arg0->ext.quad_2.x_scale.bytes.integer = integer - 1;
        if (arg0->unk2 == 0x15) {
            arg0->vertices[0].x.val += FIXED(D_80078138[arg0->unk2].speed[2]);
            arg0->vertices[1].x.val += FIXED(D_80078138[arg0->unk2].speed[2]);
            arg0->vertices[2].x.val += FIXED(D_80078138[arg0->unk2].speed[0]);
            arg0->vertices[3].x.val += FIXED(D_80078138[arg0->unk2].speed[0]);
        } else {
            arg0->vertices[1].x.u.hi += D_80078138[arg0->unk2].speed[0] * 2;
            arg0->vertices[0].x.u.hi += D_80078138[arg0->unk2].speed[2] * 2;
            arg0->vertices[1].y.u.hi += D_80078138[arg0->unk2].speed[1] * 2;
            arg0->vertices[0].y.u.hi += D_80078138[arg0->unk2].speed[3] * 2;
        }
    }
}
#undef D_800E4478

#define func_80041AB8 func_8004BFE0
#define D_80075FD8 D_8007825C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004C01C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 0x15) {
        M2C_FIELD(arg0, s8*, 0x3D) = 0xF;
        return;
    }
    M2C_FIELD(arg0, s8*, 0x3D) = 2;
}

#include "common.h"
#include "mmx6/x4.h"

extern void (*D_80078250[])(struct X4_QuadObj*);
extern u8 D_80078240[];
extern u8 D_800E4478[0x10];

#define QUAD_FRAME(p) (*(u8*)((u8*)(p) + 0x3C))

void func_8004C040(struct X4_QuadObj* arg0) {
    D_80078250[arg0->unk5](arg0);
    if (arg0->unk5 != 0 && D_800E4478[0] != 0 &&
        (u32)D_80097420.frame_counter % 3 == 0) {
        arg0->unk34 = D_80078240[QUAD_FRAME(arg0)];
        QUAD_FRAME(arg0)++;
        if (QUAD_FRAME(arg0) == 0xE) {
            QUAD_FRAME(arg0) = 0;
        }
    }
}

#undef QUAD_FRAME

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004C100(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#include "psyq/libgte.h"

s32 func_8002D30C();
void func_800328B0();
extern s32 D_80078268[];
extern s32 D_80078278[];

#define C120_W(p, o) (*(s32*)((u8*)(p) + (o)))
#define C120_B(p, o) (*(u8*)((u8*)(p) + (o)))
#define C120_H(p, o) (*(u16*)((u8*)(p) + (o)))

void func_8004C120(void* arg0) {
    s32 r;

    C120_W(arg0, 0x1C) =
        rcos(C120_H(arg0, 0x38)) * D_80078268[C120_B(arg0, 0x3A) + 1] * 0x10;
    C120_W(arg0, 0x20) =
        rsin(C120_H(arg0, 0x38)) * D_80078268[C120_B(arg0, 0x3A) + 1] * 0x10;
    C120_W(arg0, 0x24) =
        rcos((C120_H(arg0, 0x38) + D_80078278[func_8002D30C() % 3]) & 0xFFF) *
        D_80078268[C120_B(arg0, 0x3A)] * 0x10;
    C120_W(arg0, 0x28) =
        rsin((C120_H(arg0, 0x38) + D_80078278[func_8002D30C() % 3]) & 0xFFF) *
        D_80078268[C120_B(arg0, 0x3A)] * 0x10;
    C120_W(arg0, 0x2C) = 0;
    C120_W(arg0, 0x30) = 0;
    r = func_8002D30C();
    C120_B(arg0, 0x4)++;
    C120_B(arg0, 0x3B) = r % 7;
    func_800328B0(arg0);
}

#undef C120_W
#undef C120_B
#undef C120_H

#define func_80041AB8 func_8004C2F4
#define D_80075FD8 D_80078288
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

s32 func_8002D30C();

void func_8004C330(u8* arg0) {
    *(s16*)(arg0 + 0x34) = 2;
    arg0[0x36] = 0;
    arg0[0x37] = 0;
    arg0[0] |= 0x82;
    *(u16*)(arg0 + 0x38) = *(u16*)(arg0 + 8);
    {
        s32 r = func_8002D30C();
        *(s32*)(arg0 + 0x14) = 0;
        *(s32*)(arg0 + 0x18) = 0;
        arg0[4]++;
        arg0[0x3A] = r % 3;
    }
}

#include "common.h"

#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800328B0();

void func_8004C3B4(void* arg0) {
    s32 t;

    t = FU8(arg0, 0x3B) - 1;
    FU8(arg0, 0x3B) = t;
    if ((t & 0xFF) == 0xFF) {
        FU8(arg0, 4) = FU8(arg0, 4) + 1;
        func_800328B0(arg0);
    }
}

#undef FU8

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004C3FC(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();

void func_8004C41C(void* arg0) {
    s32 sy;
    s32 sx;
    s32 i;
    s32 vx;
    s32 vy;

    M2C_FIELD(arg0, u8*, 0x36) = 0;
    M2C_FIELD(arg0, s16*, 0x34) = 1;
    M2C_FIELD(arg0, u8*, 0x37) = 0;
    M2C_FIELD(arg0, u8*, 0) |= 0x82;
    M2C_FIELD(arg0, u8*, 0x38) = random_byte() & 0x1F;
    if (M2C_FIELD(arg0, u8*, 0x38) < 0x10) {
        sy = -1;
        if (M2C_FIELD(arg0, u8*, 0x38) < 8) {
            sx = 1;
            i = 8 - M2C_FIELD(arg0, u8*, 0x38);
        } else {
            sx = -1;
            i = M2C_FIELD(arg0, u8*, 0x38) - 8;
        }
    } else {
        sy = 1;
        if (M2C_FIELD(arg0, u8*, 0x38) < 0x18) {
            sx = -1;
            i = 0x18 - M2C_FIELD(arg0, u8*, 0x38);
        } else {
            sx = 1;
            i = M2C_FIELD(arg0, u8*, 0x38) - 0x18;
        }
    }
    vx = (g_angle_x_speeds[i] * sx << 4) >> 4;
    M2C_FIELD(arg0, s32*, 0x3C) = vx;
    vy = g_angle_y_speeds[i] * sy << 4;
    M2C_FIELD(arg0, s32*, 0x44) = vx;
    M2C_FIELD(arg0, s32*, 0x4C) = vx;
    M2C_FIELD(arg0, s32*, 0x54) = vx / 2;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x30) = 0;
    M2C_FIELD(arg0, u8*, 0x39) = 4;
    M2C_FIELD(arg0, u8*, 0x3A) = 0;
    M2C_FIELD(arg0, u8*, 4) += 1;
    M2C_FIELD(arg0, s32*, 0x40) = vy >> 4;
    M2C_FIELD(arg0, s32*, 0x48) = vy >> 4;
    M2C_FIELD(arg0, s32*, 0x50) = vy >> 4;
    M2C_FIELD(arg0, s32*, 0x58) = (vy >> 4) / 2;
}

#include "common.h"

void func_800328B0();

#define W(o) (*(s32*)((u8*)arg0 + (o)))
#define B(o) (*(u8*)((u8*)arg0 + (o)))
#define SB(o) (*(s8*)((u8*)arg0 + (o)))

void func_8004C584(void* arg0) {
    if (++B(0x3A) == 0) {
        B(0x3A) = 0xFE;
    }
    W(0x14) += W(0x3C);
    W(0x18) += W(0x40);
    W(0x24) += W(0x44);
    W(0x28) += W(0x48);
    W(0x1C) = W(0x14) + 0x10000;
    W(0x20) = W(0x18) + 0x10000;
    W(0x2C) = W(0x24) - 0x10000;
    W(0x30) = W(0x28) - 0x10000;
    W(0x3C) += W(0x4C);
    W(0x40) += W(0x50);
    W(0x44) += W(0x54);
    W(0x48) += W(0x58);
    if (B(0x39) != 0) {
        B(0x39)--;
        return;
    }
    func_800328B0(arg0);
    if (SB(0x3) == 0 && B(0x3A) >= 0x3D) {
        B(0x4)++;
    }
}

#undef W
#undef B
#undef SB

#define func_80041AB8 func_8004C6AC
#define D_80075FD8 D_80078298
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004C6E8(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#define func_80041AB8 func_8004C708
#define D_80075FD8 D_800782A4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800328B0(); /* extern; was M2C_UNK (W15 regate of 328B0) */

void func_8004C744(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x34) = 3;
    M2C_FIELD(arg0, s32*, 0x38) = 0x40000;
    M2C_FIELD(arg0, s8*, 0x36) = 0;
    M2C_FIELD(arg0, s8*, 0x37) = 0;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x30) = 0;
    M2C_FIELD(arg0, u8*, 0) = (u8)(M2C_FIELD(arg0, u8*, 0) | 0x82);
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    func_800328B0();
}

/* Adapted from sozud/mmx4 @807a01b src/main/quads/quad_08_flash_band.c:flash_band_widen, AGPL-3.0; proven shared with X6 by exact signature f8c67d3d4451 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
void func_800328B0(); /* was M2C_UNK (W15 regate of 328B0) */
void func_8004C7B0(struct X4_QuadObj* arg0) {
    arg0->vertices[0].x.val += arg0->ext.ready_line.x_vel.val;
    arg0->vertices[3].x.val -= arg0->ext.ready_line.x_vel.val;
    arg0->ext.ready_line.x_vel.val += FIXED(4);
    func_800328B0(arg0);
    if (arg0->vertices[0].x.i.hi > 0x14A) {
        arg0->state++;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004C824(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

/* Adapted from sozud/mmx4 @807a01b src/main/quads/quad_07_ready_line.c:ready_line_sweep, AGPL-3.0; proven shared with X6 by exact signature 5aa466ee5359 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void* alloc_sprite_slot();
extern u16 D_800782B0[8];

void func_8004C844(struct X4_QuadObj* arg0) {
    u16* verts;
    struct X4_EffectObj* temp_s1;
    struct X4_MiscObj* misc_obj;
    switch (arg0->unk5) {
    case 0:
        arg0->unk5 = 1;
        // set position of blue line that goes left to right before
        // ready text appears
        arg0->x_pos.i.hi = -320;
        arg0->y_pos.i.hi = 112;
        verts = D_800782B0;
        arg0->vertices[0].x.i.hi = *verts++;
        arg0->vertices[0].y.i.hi = *verts++;
        arg0->vertices[1].x.i.hi = *verts++;
        arg0->vertices[1].y.i.hi = *verts++;
        arg0->vertices[2].x.i.hi = *verts++;
        arg0->vertices[2].y.i.hi = *verts++;
        arg0->vertices[3].x.i.hi = *verts++;
        arg0->vertices[3].y.i.hi = *verts;
        arg0->ext.ready_line.x_vel.val = FIXED(32);
        arg0->ext.ready_line.y_vel.val = 0;
        arg0->ext.ready_line.x_accel.val = 0;
        arg0->ext.ready_line.y_accel.val = 0;
        func_8004D074(arg0);
        return;
    case 1:
        temp_s1 = arg0->link.owner;
        // spawn "READY" text and shadow when blue line reaches center of screen
        if ((arg0->x_pos.i.hi >= 0 && arg0->x_pos.i.hi <= 2) &&
            (temp_s1->ext.unk_effect.unk15 == 0)) {
            misc_obj = alloc_sprite_slot();
            if (misc_obj != NULL) {
                misc_obj->active = 1;
                misc_obj->id = 0x12;
                misc_obj->unk2 = 0;
                temp_s1->ext.unk_effect.unk15 = 0;
                misc_obj->ext.ready_text.owner = arg0->link.owner;
            }
            misc_obj = alloc_sprite_slot();
            if (misc_obj != NULL) {
                misc_obj->active = 1;
                misc_obj->id = 0x12;
                misc_obj->unk2 = 1;
                temp_s1->ext.unk_effect.unk15 = 0;
                misc_obj->ext.ready_text.owner = arg0->link.owner;
            }
        }
        if (arg0->x_pos.i.hi >= 320) {
            arg0->unk5 = 2;
            return;
        }
        func_8004D074(arg0);
        return;
    case 2:
        temp_s1 = arg0->link.owner;
        temp_s1->ext.unk_effect.unk14 = 0;
        arg0->state = 2;
        arg0->unk5 = 0;
        return;
    }
}

#include "common.h"

extern u16 D_800782C0[];
extern u16 D_800782D4[][8];
extern u16 D_80078374[][8];
extern u16 D_80078444;
void func_8004D0B0(u8*, u8, u8, u16*);

#define B(o) (*(s8*)(p + (o)))
#define UB(o) (*(u8*)(p + (o)))
#define H(o) (*(u16*)(p + (o)))

void func_8004CA08(u8* p) {
    u8* q;
    u32 i;
    s32 c;
    u16 d;
    u16 x;
    u16* t;

    switch (B(5)) {
    case 0:
        B(5) = 1;
        H(0xA) = 0;
        H(0x16) = D_800782C0[B(7)];
        H(0x2E) = D_800782C0[B(7)];
        H(0x1E) = D_800782C0[B(7)] + 0x3F;
        H(0x26) = D_800782C0[B(7)] + 0x3F;
        H(0xE) = 0;
        if (B(7) < 5) {
            H(0x1A) = 0;
            H(0x22) = 0;
            H(0x2A) = 0;
            H(0x32) = 0;
        } else {
            H(0x1A) = 0xF0;
            H(0x22) = 0xF0;
            H(0x2A) = 0xF0;
            H(0x32) = 0xF0;
        }
        B(0x55) = 1;
        B(0x54) = 1;
        B(0x4C) = 0;
        B(0x4D) = 0;
        B(0x4E) = 0;
        B(0x4F) = 0;
        H(0x50) = 8;
        break;
    case 1:
        i = 0;
        q = p + 0x38;
        for (; i < 4; i++) {
            func_8004D0B0(p, UB(7), i, &D_800782D4[B(7)][i * 2]);
        }
        c = H(0x50) - 1;
        *(u16*)(q + 0x18) = c;
        if (!(c & 0xFFFF)) {
            t = D_800782D4[B(7)];
            H(0x16) = *t++;
            H(0x1A) = *t++;
            H(0x1E) = *t++;
            H(0x22) = *t++;
            H(0x26) = *t++;
            H(0x2A) = *t++;
            H(0x2E) = *t++;
            H(0x32) = *t++;
            B(5) = 2;
            B(0x55) = 1;
            B(0x54) = 1;
            B(0x4C) = 0;
            B(0x4D) = 0;
            B(0x4E) = 0;
            B(0x4F) = 0;
            H(0x50) = 8;
        }
        break;
    case 2:
        i = 0;
        q = p + 0x38;
        for (; i < 4; i++) {
            func_8004D0B0(p, UB(7), i, &D_80078374[B(7)][i * 2]);
        }
        c = H(0x50) - 1;
        *(u16*)(q + 0x18) = c;
        if (!(c & 0xFFFF)) {
            t = D_80078374[B(7)];
            H(0x16) = *t++;
            H(0x1A) = *t++;
            H(0x1E) = *t++;
            H(0x22) = *t++;
            H(0x26) = *t++;
            H(0x2A) = *t++;
            H(0x2E) = *t++;
            x = *t;
            B(5) = 3;
            B(0x55) = 1;
            B(0x54) = 1;
            B(0x4C) = 0;
            B(0x4D) = 0;
            B(0x4E) = 0;
            B(0x4F) = 0;
            d = D_80078444;
            H(0x50) = 0x10;
            H(0x32) = x;
            if (d != 0) {
                D_80078444 = d - 1;
            }
        }
        break;
    case 3:
        *(u8*)(*(u8**)(p + 0x58) + 0x14) = 0;
        B(4) = 2;
        B(5) = 0;
        break;
    }
}

#undef B
#undef UB
#undef H

#include "common.h"
#include "mmx6/x4.h"

s32 random_byte();
void func_8004D074(struct X4_QuadObj* arg0);
extern u16 D_80078414[];
extern u8 D_80078460[];

void func_8004CD3C(struct X4_QuadObj* arg0) {
    u16* p;
    s32 n;
    u8* t;

    switch (arg0->unk5) {
    case 0:
        t = D_80078460;
        arg0->unk5 = 1;
        p = &D_80078414[t[random_byte() & 0xF] * 8];
        arg0->vertices[0].x.u.hi = *p++;
        arg0->vertices[0].y.u.hi = *p++;
        arg0->vertices[1].x.u.hi = *p++;
        arg0->vertices[1].y.u.hi = *p++;
        arg0->vertices[2].x.u.hi = *p++;
        arg0->vertices[2].y.u.hi = *p++;
        arg0->vertices[3].x.u.hi = *p++;
        arg0->vertices[3].y.u.hi = *p++;
        n = 1;
        if (random_byte() & 1) {
            n = 2;
        }
        if (random_byte() & 1) {
            arg0->x_pos.i.hi = -0xB0;
            arg0->ext.ready_line.x_vel.val = n * 0x180000;
            arg0->ext.ready_line.y_vel.val = 0;
            arg0->ext.ready_line.x_accel.val = 0;
            arg0->ext.ready_line.y_accel.val = 0;
            arg0->runtime.legacy.unk48 = 0;
        } else {
            arg0->x_pos.i.hi = 0x1F0;
            arg0->ext.ready_line.x_vel.val = -(n * 0x180000);
            arg0->ext.ready_line.y_vel.val = 0;
            arg0->ext.ready_line.x_accel.val = 0;
            arg0->ext.ready_line.y_accel.val = 0;
            arg0->runtime.legacy.unk48 = 1;
        }
        arg0->y_pos.i.hi = (random_byte() & 7) * 4 + 0x68;
        arg0->runtime.legacy.unk52 = arg0->unk7 << 3;
        break;
    case 1:
        if (*(u16*)&arg0->runtime.legacy.unk52 != 0) {
            (*(u16*)&arg0->runtime.legacy.unk52)--;
            break;
        }
        if (arg0->runtime.legacy.unk48 == 0) {
            if (arg0->x_pos.i.hi >= 0x140) {
                arg0->unk5 = 2;
                break;
            }
            func_8004D074(arg0);
            break;
        }
        if (arg0->x_pos.i.hi < -0xB0) {
            arg0->unk5 = 2;
            break;
        }
        func_8004D074(arg0);
        break;
    case 2:
        ((u8*)arg0->link.owner)[0x14]--;
        arg0->state = 2;
        arg0->unk5 = 0;
        break;
    }
}

#define func_80041AB8 func_8004CF68
#define D_80075FD8 D_80078448
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

/* Adapted from sozud/mmx4 @807a01b src/main/quads/quad_07_ready_line.c:ready_line_init, AGPL-3.0; proven shared with X6 by exact signature 2100185f1445 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_8004CFA4(struct X4_QuadObj* arg0) {
    arg0->active |= SATURN_ALT(0x92, 0x82);
    if (arg0->unk2 == 0) {
        arg0->unk36 = 0x10;
    } else {
        arg0->unk36 = 0x13;
    }
    arg0->unk34 = 5;
    arg0->state = 1;
    arg0->bg_offset = -1;
    arg0->x_pos.val = 0;
    arg0->y_pos.val = 0;
    arg0->vertices[0].x.val = 0;
    arg0->vertices[0].y.val = 0;
    arg0->vertices[1].x.val = 0;
    arg0->vertices[1].y.val = 0;
    arg0->vertices[2].x.val = 0;
    arg0->vertices[2].y.val = 0;
    arg0->vertices[3].x.val = 0;
    arg0->vertices[3].y.val = 0;
}

#include "common.h"

extern s32 D_80078454[];

void func_8004D008(u8* arg0) {
    ((void (**)(u8*))D_80078454)[(s8)arg0[2]](arg0);
    arg0[3] = 1;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004D054(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

/* Adapted from sozud/mmx4 @807a01b src/main/quads/quad_07_ready_line.c:ready_line_move, AGPL-3.0; proven shared with X6 by exact signature 067862c5794d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_8004D074(struct X4_QuadObj* arg0) {
    arg0->x_pos.val += arg0->ext.ready_line.x_vel.val;
    arg0->y_pos.val += arg0->ext.ready_line.y_vel.val;
    arg0->ext.ready_line.x_vel.val += arg0->ext.ready_line.x_accel.val;
    arg0->ext.ready_line.y_vel.val += arg0->ext.ready_line.y_accel.val;
}

#include "common.h"
#define M2C_UNK s32

s32 func_8002D0D8(s32, s32);

void func_8004D0B0(u8* arg0, u8 arg1, u8 arg2, u16* arg3) {
    s32* p;
    s32 i;
    s32 n;
    s32 dx;
    s32 dy;
    s32 r;
    u8* a;
    u8* b;

    p = (s32*)(arg0 + 0x14);
    i = arg2;
    if (i != 0) {
        n = i;
        do {
            n--;
            p += 2;
        } while (n != 0);
    }
    dx = p[0] - (((s16*)arg3)[0] << 16);
    dy = p[1] - (((s16*)arg3)[1] << 16);
    r = func_8002D0D8(dx, dy);
    a = arg0 + 0x48;
    b = arg0 + 0x4C;
    if ((((r ^ a[i]) & 0x10) || b[i] != 0) && arg0[0x54] == 0) {
        *(s16*)(arg0 + 8) = 0;
        *(s16*)(arg0 + 0xC) = 0;
        b[i] = 1;
    } else {
        p[0] -= dx / *(u16*)(arg0 + 0x50);
        p[1] -= dy / *(u16*)(arg0 + 0x50);
        {
            u8* q = arg0 + 0x4C;
            q[i] = 0;
        }
        if (i == 3) {
            arg0[0x54] = 0;
        }
    }
    {
        u8* e = arg0 + 0x48;
        e[i] = r;
    }
}

#include "common.h"

extern u16 D_80078470[][4];

#define F8(o) (*(s8*)((u8*)self + (o)))
#define F16(o) (*(s16*)((u8*)self + (o)))

void func_8004D204(u8* self) {
    s32 t;
    u16 w;
    u16 h;

    F8(0x37) = -1;
    F8(0) = -0x6D;
    F8(0x36) = 0x22;
    F16(0x34) = 0x11;
    t = F8(2);
    F16(0xA) = D_80078470[t][0];
    F16(0xE) = D_80078470[t][1];
    w = D_80078470[t][2];
    F16(0x38) = w;
    h = D_80078470[t][3];
    F16(0x1E) = w;
    F16(0x26) = w;
    F16(0x16) = -w;
    F16(0x2E) = -w;
    F8(4)++;
    F16(0x3A) = h;
    F16(0x1A) = -h;
    F16(0x22) = -h;
    F16(0x2A) = h;
    F16(0x32) = h;
}

#undef F8
#undef F16

#define func_80041AB8 func_8004D29C
#define D_80075FD8 D_80078480
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32

void func_800328B0(); /* extern; was M2C_UNK (W15 regate of 328B0) */

void func_8004D2D8(void) {
    func_800328B0();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004D2F8(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define F32(p, off) (*(s32*)((u8*)(p) + (off)))

extern struct X4_BackgroundObj background_objects[3];
struct X4_QuadObj* alloc_class6_slot(void);
M2C_UNK clear_object_slot();
void func_8004D598(void* arg0);

void func_8004D318(struct X4_QuadObj* self) {
    struct X4_QuadObj* q;
    s16 dx;
    s16 dy;

    if (self->unk2 == 0) {
        dx = self->x_pos.i.hi - background_objects[self->bg_offset].x_pos.i.hi;
        dy = self->y_pos.i.hi - background_objects[self->bg_offset].y_pos.i.hi;
        if (dx < 0 || g_screen_width < dx || dy < 0 || dy >= 0xF1) {
            ((M2C_UNK(*)())clear_object_slot)(self);
            return;
        }
        if (F32(self, 0x38) == 0) {
            if (0xF0 - dy < dy) {
                F32(self, 0x3C) = dy;
            } else {
                F32(self, 0x3C) = 0xF0 - dy;
            }
        } else if (F32(self, 0x38) == 0x400) {
            if (g_screen_width - dx < dx) {
                F32(self, 0x3C) = dx;
            } else {
                F32(self, 0x3C) = g_screen_width - dx;
            }
        } else {
            F32(self, 0x3C) = dx;
            if (dx < dy) {
                F32(self, 0x3C) = dy;
            }
            if (F32(self, 0x3C) < g_screen_width - dx) {
                F32(self, 0x3C) = g_screen_width - dx;
            }
            if (F32(self, 0x3C) < 0xF0 - dy) {
                F32(self, 0x3C) = 0xF0 - dy;
            }
            F32(self, 0x3C) = (F32(self, 0x3C) * 0x16A0) >> 12;
        }
        F32(self, 0x50) = rcos(F32(self, 0x38));
        F32(self, 0x4C) = rsin(F32(self, 0x38));
        F32(self, 0x54) = -rsin(F32(self, 0x38));
        q = alloc_class6_slot();
        if (q != 0) {
            q->active = self->active;
            q->id = self->id;
            q->x_pos.i.hi = self->x_pos.i.hi;
            q->y_pos.i.hi = self->y_pos.i.hi;
            q->unk36 = self->unk36;
            q->bg_offset = self->bg_offset;
            q->unk34 = self->unk34;
            q->unk2 = 1;
            F32(q, 0x38) = F32(self, 0x38);
            F32(q, 0x50) = F32(self, 0x50);
            F32(q, 0x4C) = F32(self, 0x4C);
            F32(q, 0x54) = F32(self, 0x54);
            F32(q, 0x3C) = F32(self, 0x3C);
        }
    }
    self->on_screen = 1;
    F32(self, 0x44) = 4;
    F32(self, 0x40) = 4;
    F32(self, 0x48) = 0x30;
    ((void (*)(void*, void*))func_8004D598)(self, q);
    self->state++;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004D598(void* arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;

    temp_a0 = M2C_FIELD(arg0, s32*, 0x3C);
    temp_t1 = M2C_FIELD(arg0, s32*, 0x54);
    temp_a1 = -temp_a0;
    temp_v1 = M2C_FIELD(arg0, s32*, 0x50);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x40);
    temp_t2 = M2C_FIELD(arg0, s32*, 0x4C);
    temp_v0_2 = -temp_v0;
    temp_a2 = (s32)(temp_t1 * temp_a1 * 0x10) >> 0x10;
    temp_a1_2 = (s32)(temp_v1 * temp_a1 * 0x10) >> 0x10;
    temp_a3 = (s32)(temp_v1 * temp_v0 * 0x10) >> 0x10;
    temp_t0 = (s32)(temp_t2 * temp_v0 * 0x10) >> 0x10;
    temp_t1_2 = (s32)(temp_t1 * temp_a0 * 0x10) >> 0x10;
    temp_a0_2 = (s32)(temp_v1 * temp_a0 * 0x10) >> 0x10;
    temp_v1_2 = (s32)(temp_v1 * temp_v0_2 * 0x10) >> 0x10;
    temp_t2_2 = (s32)(temp_t2 * temp_v0_2 * 0x10) >> 0x10;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, s16*, 0x16) = (s16)temp_v1_2;
        M2C_FIELD(arg0, s16*, 0x1A) = (s16)temp_t2_2;
        M2C_FIELD(arg0, s16*, 0x1E) = (s16)temp_a2;
        M2C_FIELD(arg0, s16*, 0x22) = (s16)temp_a1_2;
        M2C_FIELD(arg0, s16*, 0x26) = (s16)temp_a2;
        M2C_FIELD(arg0, s16*, 0x2A) = (s16)temp_a1_2;
        M2C_FIELD(arg0, s16*, 0x2E) = (s16)temp_a3;
        M2C_FIELD(arg0, s16*, 0x32) = (s16)temp_t0;
        return;
    }
    M2C_FIELD(arg0, s16*, 0x16) = (s16)temp_a3;
    M2C_FIELD(arg0, s16*, 0x1A) = (s16)temp_t0;
    M2C_FIELD(arg0, s16*, 0x1E) = (s16)temp_t1_2;
    M2C_FIELD(arg0, s16*, 0x22) = (s16)temp_a0_2;
    M2C_FIELD(arg0, s16*, 0x26) = (s16)temp_t1_2;
    M2C_FIELD(arg0, s16*, 0x2A) = (s16)temp_a0_2;
    M2C_FIELD(arg0, s16*, 0x2E) = (s16)temp_v1_2;
    M2C_FIELD(arg0, s16*, 0x32) = (s16)temp_t2_2;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004D6A8(void* arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32*, 0x44) - 1;
    M2C_FIELD(arg0, s32*, 0x44) = temp_v0;
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004D598(void* arg0);
void func_8004D6D4(void* arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32*, 0x3C) - M2C_FIELD(arg0, s32*, 0x48);
    M2C_FIELD(arg0, s32*, 0x3C) = temp_v0;
    if (temp_v0 <= 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    ((M2C_UNK(*)())func_8004D598)();
}

#define func_80041AB8 func_8004D720
#define D_80075FD8 D_8007848C
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004D75C(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#define func_80041AB8 func_8004D77C
#define D_80075FD8 D_80078494
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/4228C", func_8004D7B8);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F(T, o) (*(T*)((u8*)arg0 + (o)))

M2C_UNK animate_object();
M2C_UNK func_8002CA54();
s32 func_8002CAB4(struct X4_BaseObj*);
s32 func_8002CB50(struct X4_BaseObj*);
M2C_UNK apply_object_motion(struct X4_MainObj* self);
void func_8002F288(struct X4_PlayerObj*);
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_8004E26C(void*);

void func_8004DA7C(void* arg0) {
    s32 var_v1;
    u8 temp_a0;
    u8* temp_a1;

    temp_a0 = F(u8, 0x70);
    if (((temp_a0 & 0xC) == 0xC) || ((temp_a0 & 3) == 3)) {
        F(u8, 0x85) = 1;
        F(s8, 0x67) = 0;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
        func_8002F288(arg0);
        F(void*, 0x68) = 0;
        if (F(u16, 0x80) >= 0x3D) {
            F(u16, 0x80) = 0x3C;
        }
    }
    if (F(u8, 0x85) == 0) {
        if (F(s8, 0x67) != 0) {
            if (F(u8, 0x70) & 8) {
                if (F(s8, 0x6) == 0) {
                    var_v1 = F(s32, 0x24);
                    F(s8, 0x6) = 1;
                    F(s32, 0x2C) = 0x8000;
                    F(s32, 0x24) = (var_v1 < 0 ? -var_v1 : var_v1) >> 1;
                    ((void (*)(void*))apply_object_motion)(arg0);
                } else {
                    F(s8, 0x6) = 0;
                    F(s8, 0x67) = 0;
                }
            } else {
                apply_object_motion(arg0);
            }
        } else {
            if (!(F(u8, 0x70) & 8)) {
                F(s8, 0x6) = 0;
                F(s32, 0x24) = 0;
                F(s32, 0x2C) = 0x8000;
                F(s8, 0x67) = 1;
            }
            animate_object(arg0);
        }
    } else {
        animate_object(arg0);
    }
    if (F(s32, 0x10) == 0) {
        if (--F(u16, 0x80) == 0) {
            F(u8, 0x4) = 3;
            return;
        }
    }
    func_8004E26C(arg0);
    if (func_8002CAB4(arg0) != 0) {
        if (F(s32, 0x10) != 0) {
            func_8002CA54(arg0);
        } else {
            F(u8, 0x4) = 3;
            F(u8, 0x5) = 0;
        }
    } else {
        F(u8, 0x3) = 0;
        if ((F(u16, 0x80) < 0x3C) && (D_80097420.frame_counter & 1)) {
            return;
        }
        ((s32(*)())func_8002CB50)(arg0);
    }
    temp_a1 = F(u8*, 0x68);
    // !FAKE: s8 cast of the u8 func_80030234 keeps retail's andi 0xff after the call (u8/s32 casts drop or refuse it)
    if ((((s8(*)())func_80030234)(arg0, F(s16, 0xA),
                                  F(s16, 0xE) + temp_a1[3] + (s8)temp_a1[1]) &
         0xFF) == 0x3A) {
        F(s16, 0xA)--;
    }
}

#undef F

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_8004E78C(M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;

void func_8004DCB8(u8* arg0) {
    u8* p = arg0 + 0x80;
    u8* q;
    u8 t;

    if (((s8*)arg0)[6] == 0) {
        p[4] = t = arg0[0x84] - 1;
        q = p;
        if (t == 0) {
            u8* pl;
            // !FAKE: depin: dropping it breaks the match (68/71)
            register u8* e asm("$3");
            s8* tbl;
            s8 sign;
            // !FAKE: depin: dropping it breaks the match (67/71)
            register s32 x asm("$4");

            pl = (u8*)&g_Player;
            e = (u8*)&g_playthrough_state;
            tbl = (s8*)(e + 0x5B);
            arg0[0x84] = 2;
            sign = pl[0x5C] & 0x80;
            x = (s8)pl[2];
            if ((pl[0x5C] & 0x7F) >= tbl[x]) {
                arg0[6] = 1;
                pl[0x5C] = sign | tbl[(s8)pl[2]];
            } else {
                pl[0x5C] = sign | (pl[0x5C] + 1);
            }
            play_sound(0, 0xD, 0);
            p = 0;
            if ((u8)(q[3] = arg0[0x83] - 1) == 0) {
                arg0[6] = 1;
                arg0[3] = 0;
            }
        }
    } else {
        func_8004E78C(0);
        arg0[4] = 3;
        arg0[5] = 0;
        arg0[0] &= 0xF7;
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/4228C", func_8004DDD4);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_8004E78C(M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;

void func_8004E0A8(u8* arg0, u8 arg1, s32 arg2) {
    u8 n;
    u8 hi;
    s32 b;
    s32 x;
    s8 i;
    s8 v;
    u8* p;
    u8* pl;
    u8* e;

    {
        u8* pl0 = (u8*)&g_Player;
        u8* e0;
        n = arg2;
        e0 = (u8*)&g_playthrough_state;
        hi = pl0[0x5C] & 0x80;
        x = (s8)pl0[2];
        b = (pl0[0x5C] & 0x7F) < ((s8*)(e0 - -x))[0x5B];
    }
    if (b) {
        func_8004E78C(1);
        arg0[0x83] = arg1;
        arg0[0x84] = 2;
        arg0[4] = 2;
        arg0[5] = 0;
        arg0[6] = 0;
        arg0[0] |= 8;
    } else {
        arg0[4] = 3;
    }
    pl = (u8*)&g_Player;
    e = (u8*)&g_playthrough_state;
    {
        s32 y = (s8)pl[2];
        if ((pl[0x5C] & 0x7F) >= ((s8*)(e - -y))[0x5B]) {
            pl[0x5C] = hi | (e - -y)[0x5B];
        }
    }
    *(u16*)(pl + 0xA8) += arg1 * 6;
    if (*(s16*)(pl + 0x14A) < *(s16*)(pl + 0xA8)) {
        *(u16*)(pl + 0xA8) = *(s16*)(pl + 0x14A);
    }
    for (i = 0; i < 2; i++) {
        p = &e[i + 0x63];
        if (*(volatile u16*)(e + 0x6A) & (0x1000 << i)) {
            v = *p & 0x7F;
            if (v < 0x20) {
                v = v + n * 2;
                if (v >= 0x20) {
                    v = 0x20;
                    play_sound(0, 0x18, 0);
                } else {
                    play_sound(0, 0x17, 0);
                }
                *p = v | 0x80;
                return;
            }
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/4228C", func_8004E26C);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define F(T, o) (*(T*)((u8*)arg0 + (o)))

void func_8002F288(struct X4_PlayerObj*);
extern void (*D_800788F8[])(void*);

void func_8004E5D8(void* arg0) {
    if (D_80097180 != 2 || F(s8, 0x4) <= 0) {
        F(s32, 0x18) = F(s32, 0x8);
        F(s32, 0x1C) = F(s32, 0xC);
        D_800788F8[F(s8, 0x4)](arg0);
        func_8002F288(arg0);
    }
}

#undef F

/* Adapted from sozud/mmx4 @807a01b src/main/items/item_01_stage_block.c:drop_item, AGPL-3.0; proven shared with X6 by exact signature 806a7421f0d6 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void drop_item(struct X4_BaseObj* arg0, s8 arg1, s16 arg2, s16 arg3);

void func_8004E654(struct X4_BaseObj* arg0, s8 arg1) {
    drop_item(arg0, arg1, arg0->x_pos.i.hi, arg0->y_pos.i.hi);
}
