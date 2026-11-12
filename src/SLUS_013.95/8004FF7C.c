#include "common.h"

void* enemy_slot_alloc();

void func_8004FF7C(void* arg0, s32 arg1) {
    u8 t;
    u8* p;

    t = arg1;
    p = enemy_slot_alloc();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xF;
        p[2] = t;
        p[0x14] = ((u8*)arg0)[0x14];
        if ((t & 0xF0) == 0x30) {
            s32 a = *(u16*)((u8*)arg0 + 0xA);
            *(u16*)(p + 8) = 0;
            *(u16*)(p + 0xA) = a;
            {
                s32 b = *(u16*)((u8*)arg0 + 0xE);
                *(u16*)(p + 0xC) = 0;
                *(u16*)(p + 0xE) = b;
            }
        }
    }
}

// clang-format off
#include "../shared/SLUS_013.95/func_8004FFF8.c"
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800500C0(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#define func_80041AB8 func_800500E0
#define D_80075FD8 D_80078CCC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_20 (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern s32 D_80078DC8;
extern s32 D_80078DCC;

void func_8005011C(void* arg0) {
    s32 a;
    s32 b;
    u8 t;

    M2C_FIELD(arg0, u8*, 0x0) = 0x49;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, u16*, 0x40) = D_80095098[func_8002A47C(0x80)] >> 7;
    M2C_FIELD(arg0, s32*, 0x3C) =
        (s32)SCRATCH_20 + SCRATCH_20[func_8002A47C(0x80)];
    a = func_8002A47C(0x80);
    b = func_8002A47C(0x80);
    M2C_FIELD(arg0, s16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    {
        s32* p = &D_80078DCC;
        u8* q;
        // !FAKE: depin: dropping it breaks the match (60/77)
        register s32 one asm("$3");
        do {
        } while (0);
        q = &D_800970B4;
        M2C_FIELD(arg0, s32**, 0x30) = p;
        one = 1;
        t = *q;
        M2C_FIELD(arg0, u8*, 0x75) = one;
        M2C_FIELD(arg0, u8*, 0x4) = one;
    }
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, s32*, 0x7C) = 0;
    M2C_FIELD(arg0, s32*, 0x88) = 0;
    M2C_FIELD(arg0, s32**, 0x68) = &D_80078DC8;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = t;
    M2C_FIELD(arg0, u8*, 0x2) &= 0x3F;
    set_animation(arg0, 0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void start_pad_vibration(s32);
s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
void func_8002B79C();
void* enemy_slot_alloc();
void collide_solid_object(struct X4_MainObj*);
s32 func_80050C88(void*);
void func_80051104(struct X4_ItemObj* arg0);
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"
#include "mmx6/globals.h"
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCEF8;

#define I84 (*(u32*)((u8*)arg0 + 0x84))
#define I88 (*(s32*)((u8*)arg0 + 0x88))

void func_80050250(struct X4_ItemObj* arg0, s32 arg1, u8* arg2) {
    u8* p;
    s8 t;

    ((void (*)())collide_solid_object)();
    func_80051104(arg0);
    t = arg0->unk2;
    if (t == 7 && D_800CCEF6 == 0) {
        return;
    }
    if (t == 8 && D_800CCEF6 == 0) {
        return;
    }
    if (t == 0xC && D_800CCEF6 == 0) {
        return;
    }
    if (t == 0xA && D_800CCEF6 == 0) {
        return;
    }
    if (t == 0xE && D_800CCEF6 == 0) {
        return;
    }
    if (t == 0xF && D_800CCEF6 == 0) {
        return;
    }
    if (t == 0x22 && D_800CCEF8 == 0) {
        return;
    }
    if (t == 0x2C && D_800CCEF6 != 0) {
        return;
    }
    if (func_80050C88(arg0) == 0) {
        return;
    }
    if (g_playthrough_state.gameplay_locked == 0) {
        if (arg0->unk2 == 0x19 || arg0->unk2 == 0x27) {
            play_sound(5, 1, 0);
            start_pad_vibration(4);
        }
    }
    g_playthrough_state.gameplay_locked = 1;
    arg2[0xD4] = 1;
    if (arg0->unk2 == 0x19) {
        if ((s16)background_objects[1].unk42 >= -0x4F) {
            if (!(D_80097420.frame_counter & 1)) {
                background_objects[1].unk42--;
            }
            if (I88 == 0) {
                func_8002943C(0xA, 2, 2);
                I88 = 0xA;
            } else {
                I88--;
            }
            return;
        }
        play_sound(5, 3, p);
        background_objects[1].unk3 = 0;
    } else if (arg0->unk2 == 0x27) {
        if (I84++ < 0x70) {
            background_objects[1].unk42--;
            if (I88 == 0) {
                func_8002943C(0xA, 2, 2);
                I88 = 0xA;
            } else {
                I88--;
            }
            return;
        }
        background_objects[1].unk3 = 0;
        play_sound(5, 3, p);
    }
    if (arg0->unk7C.timer == 0) {
        func_8002B79C();
    }
    if (arg0->unk2 == 7) {
        p = enemy_slot_alloc();
        p[0] = 0x41;
        p[1] = 0x19;
        p[2] = 4;
    }
    background_objects[0].unk34 &= 0xF;
    arg0->unk5 = 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2);
s32 func_8002B2F8(s32);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_8009742C;
extern s8 D_800CF850;

void func_80050540(void* arg0, void* arg1, void* arg2) {
    s16 i;

    if (M2C_FIELD(arg2, s8*, 0xD4) < 0) {
        M2C_FIELD(arg2, s8*, 0xD4) = -2;
        M2C_FIELD(arg1, s8*, 0x10) = 1;
        M2C_FIELD(arg1, s8*, 0x12) = 1;
        M2C_FIELD(arg2, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s32*, 0x80) = background_objects[0].unk47;
        background_objects[0].unk47 = 2;
        if (M2C_FIELD(arg0, s8*, 2) == 0x1F) {
            func_8002B2F8(0);
            D_80090D56 = 1;
            D_8009742C = 1;
            D_800CF850 = 1;
            D_80090C90[2] = 0xF;
            for (i = 3; i < 0xF; i++) {
                D_80090C90[i] = -1;
            }
            D_800C4560 |= 1;
            M2C_FIELD(arg0, s16*, 0xA0) = 2;
            background_objects[0].unk34 &= 0xF;
            M2C_FIELD(arg0, s8*, 5) = 5;
            return;
        }
        M2C_FIELD(arg0, s8*, 5) = 2;
        play_sound(0, 0x10, arg0);
    }
    background_objects[0].unk34 &= 0xF;
}

// clang-format off
#include "../shared/SLUS_013.95/func_80050670.c"
// clang-format on

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

    if (PA4 != 0 || (p->hp & 0x80) || p->action == 3) {
        // !FAKE: goto web orders ret0/spike_immune; if-else form moved bytes
        goto ret0;
    }
    if (p->character == 0) {
        // !FAKE: goto web orders ret0/spike_immune; if-else form moved bytes
        goto arm7a;
    }
    t = p->attacking;
join:
    if (t != 0) {
    ret0:
        return 0;
    arm7a:
        t = p->spike_immune;
        // !FAKE: goto web orders ret0/spike_immune; if-else form moved bytes
        goto join;
    }
    if (p->x_pos.i.hi > o->x_pos.i.hi) {
        return 0;
    }
    oy = o->x_pos.u.hi + o->terrain_box->unk0;
    py = p->x_pos.u.hi + p->terrain_box->unk0;
    d = (oy - py < 0) ? py - oy : oy - py;
    a = o->terrain_box;
    b = p->terrain_box;
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

/* Adapted from sozud/mmx4 @4e16dfc src/main/items/item_08_boss_door.c:boss_door_update, AGPL-3.0; proven shared with X6 by exact signature 3841861bc21e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_80078DD4[])(struct X4_ItemObj*);

#define M2C_UNK s32
s32 func_8002CB50(struct X4_BaseObj*);
void func_80050DFC(struct X4_ItemObj* arg0) {
    arg0->unk18.val = arg0->x_pos.val;
    arg0->unk1C.val = arg0->y_pos.val;
    D_80078DD4[arg0->state](arg0);
    func_8002CB50(BASE_OBJECT(arg0));
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern struct X4_PlayerObj g_Player;
extern void (*D_80078DE0[])(struct X4_PlayerObj*, struct X4_EngineObj*,
                            struct X4_PlayerObj*);

void func_80050E58(struct X4_PlayerObj* arg0) {
    struct X4_EngineObj* e = &g_playthrough_state;
    struct X4_PlayerObj* p = &g_Player;
    D_80078DE0[arg0->action](arg0, e, p);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void set_pose_size();

void func_80050EA0(u8* arg0, s32 arg1, u8* arg2) {
    *(s32*)(arg2 + 8) += *(s32*)(arg0 + 0x84);
    if (background_objects[0].x_pos.i.hi == background_objects[0].unk26) {
        *(s8*)(arg2 + 0xD4) = 0;
        set_pose_size(arg2);
        *(s8*)(arg0 + 5) = 4;
        set_animation(arg0, 1);
        play_sound(0, 0x11, arg0);
        if (*(s8*)(arg0 + 2) == 0x12) {
            D_8008EAB0 = 1;
            background_objects[0].unk26 = 0xD70;
        }
        background_objects[0].unk47 = *(u8*)(arg0 + 0x80);
        background_objects[0].unk34 &= 0xF;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_80050F58(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) < 2) {
        ((M2C_UNK(*)())animate_object)();
        if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
            play_sound(0, 0x10, arg0);
            M2C_FIELD(arg0, s8*, 0x45) = 0;
        }
    } else {
        struct X4_PlayerObj* pl = &g_Player;

        M2C_FIELD(arg0, s8*, 0x4) = 2;
        M2C_FIELD(arg0, s8*, 0x5) = 0;
        if (M2C_FIELD(pl, s8*, 0xD0) == 0 && pl->ride_animation == 0 &&
            pl->nova_strike_active == 0) {
            D_800CCEEC = 0;
        }
    }
    background_objects[0].unk34 &= 0xF;
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_80051018(u8* arg0) {
    s32 two;
    s32 n;

    if ((s16)-- * (u16*)(arg0 + 0xA0) == -1) {
        two = 2;
        *(u16*)(arg0 + 0xA0) = two;
        D_800CF854++;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
        D_800C4560 |= 1;
        n = D_800CF854;
        if ((u16)n >= 0x1F) {
            play_sound(0, 0x10, arg0);
            arg0[5] = two;
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void collide_solid_object(struct X4_MainObj*); /* extern */
void func_80051104(struct X4_ItemObj* arg0);   /* extern */

void func_800510C4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) != 0x14) {
        ((void (*)())collide_solid_object)();
        func_80051104(arg0);
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/items/item_08_boss_door.c:boss_door_block_player, AGPL-3.0; proven shared with X6 by exact signature 37a985cf43c2 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_PlayerObj g_Player;

void func_80051104(struct X4_ItemObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;

    if (arg0->unk72 & 4) {
        player->unk71 &= 0xB;
    }
    if (arg0->unk72 & 8) {
        player->unk71 &= 7;
    }
}
