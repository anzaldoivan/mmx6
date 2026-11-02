// clang-format off
INCLUDE_ASM("asm/rock_45/nonmatchings/FA000", D_800FA000);

INCLUDE_ASM("asm/rock_45/nonmatchings/FA000", D_800FA014);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

void set_boss_level();
s32 func_8002A47C(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_80075A5C;
extern u8 D_800970B4;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800FA000[];
extern s32 D_800FCA88;
extern s32 D_800FCA94;
extern s32 D_800FCCD4;
extern u16 D_800FCE48;
extern u16 D_800FCE4A;
extern s16 D_800FCE4C;
extern s16 D_800FCE4E;
extern s16 D_800FCE50;
extern s16 D_800FCE52;
extern s16 D_800FCE54;
extern s32 D_800FCE58;
extern s32 D_800FCE5C;
extern void* D_800FCE60;

void func_800FA028(struct X4_MainObj* self) {
    u8 tbl[4][2];
    u16 yv;
    u16 xv;
    u8 bg;

    __builtin_memcpy(tbl, D_800FA000 + 4, 8);
    D_800FCE48 = background_objects[0].unk26 + 0x100;
    D_800FCE4A = background_objects[0].unk2A - 0x10;
    D_800FCE4C = background_objects[0].unk26 + 0x30;
    D_800FCE4E = background_objects[0].unk26 + 0x130;
    D_800FCE50 = background_objects[0].unk26 + 0xB0;
    D_800FCE52 = background_objects[0].unk2A + 0x10;
    D_800FCE54 = background_objects[0].unk2A + 0xB0;
    self->animation_table = (void*)&D_800FCCD4;
    self->unk40 = 0x140;
    self->unk42 = 0x7948;
    self->sprite_frames = (u8*)SPAD20 + SPAD20[func_8002A47C(self->id)];
    bg = D_800970B4;
    self->unk16 = 5;
    self->unk15 = 0;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = &D_800FCA88;
    self->hurt_box = &D_800FCA94;
    self->unk62 = 0;
    self->invincibility_timer = 0;
    self->bg_offset = bg;
    self->collision_data = &D_80075A5C;
    xv = D_800FCE48;
    yv = D_800FCE4A;
    self->x_speed = 0;
    self->contact_damage = 4;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 0;
    self->x_pos.i.hi = xv;
    self->y_pos.i.hi = yv;
    g_playthrough_state.unk25 = 0;
    g_playthrough_state.boss_ptr = self;
    M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x3A;
    set_boss_level(1);
    {
        // !FAKE: depin: dropping it breaks the match (126/133)
        register s32 i asm("$3") = M2C_FIELD(&g_playthrough_state, u8*, 0x8F);
        M2C_FIELD(&g_playthrough_state, u8*, 0x8C) += tbl[i][0];
    }
    M2C_FIELD(self, u8*, 0x88) = 0;
    func_8003D308(0x14, 0x40);
    M2C_FIELD(self, s32*, 0x90) = background_objects[0].unk48;
    background_objects[0].unk48 = 1;
    D_800FCE58 = 0;
    D_800FCE5C = 0;
    D_800FCE60 = self;
    self->unk5 = 2;
    self->state++;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern M2C_UNK D_8007433C;
extern s32 D_80075A5C;
extern s8 D_8009711A;
extern s32 D_800FCA84;

#define TBL(off) ((s32*)((s32) & D_800FCA84 + (off)))

void func_800FA23C(void* arg0) {
    s32 r;
    u8 t;
    u8 k;
    s32* a;

    if ((u32)(M2C_FIELD(arg0, u8*, 0x47) - 0x2D) < 0xB) {
        a = TBL(0x14);
    } else {
        a = TBL(0x10);
    }
    M2C_FIELD(arg0, s32**, 0x54) = a;
    r = check_enemy_hits(arg0);
    if (r < 0) {
        *TBL(0x3D4) = 1;
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        D_8009711A = 1;
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    k = M2C_FIELD(arg0, u8*, 0x47);
    if ((u32)(k - 0x2D) < 0xB) {
        if (k == 0x34) {
            a = TBL(0xC);
        } else {
            a = TBL(8);
        }
    } else {
        a = TBL(4);
    }
    M2C_FIELD(arg0, s32**, 0x50) = a;
    func_80030ECC(arg0);
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, u8*, 0x88) = ((u32)(r - 0x19) < 2) ? 2 : 0x1E;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if (M2C_FIELD(arg0, s8*, 5) == 9) {
            M2C_FIELD(arg0, s32*, 0x84) = 1;
        }
    }
    if (M2C_FIELD(arg0, s8*, 5) != 9) {
        if (r == 7 || r == 0x10 || r == 0x2B || r == 0x2F) {
            M2C_FIELD(arg0, s32*, 0x84) = 0;
            *TBL(0x3D8) = 1;
            M2C_FIELD(arg0, s8*, 5) = 9;
            M2C_FIELD(arg0, s8*, 6) = 0;
            M2C_FIELD(arg0, u8*, 0x88) = 0x14;
        }
    }
    t = M2C_FIELD(arg0, u8*, 0x88);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x88) = t + 0xFF;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, u8*, 0x88) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_80075A5C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    ((void (**)(void*))TBL(0x2F8))[M2C_FIELD(arg0, s8*, 5)](arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj g_Player;
extern u8 D_800CCF5F;
extern u8 D_800FA000[];

void func_800FA454(void* arg0) {
    u8 tbl[4];

    __builtin_memcpy(tbl, D_800FA000 + 0x10, 4);
    if (M2C_FIELD(arg0, s8*, 0x7) == 0 &&
        M2C_FIELD(arg0, s16*, 0x7E) == tbl[D_800CCF5F]) {
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
    if ((s16)++M2C_FIELD(arg0, u16*, 0x7C) == 0x32) {
        if (M2C_FIELD(arg0, s16*, 0x7E) < tbl[D_800CCF5F]) {
            void* e;
            if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            e = func_8002C458();
            if (e != 0) {
                s8 v;
                M2C_FIELD(e, u8*, 0) = 0x41;
                M2C_FIELD(e, u8*, 1) = 0x22;
                v = 3;
                if (g_Player.unk2 == 0) {
                    v = 2;
                }
                M2C_FIELD(e, s8*, 2) = v;
                M2C_FIELD(e, void**, 0x7C) = arg0;
            }
            M2C_FIELD(arg0, s16*, 0x7E)++;
        }
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;
extern s16 D_800FCE4C;
extern s16 D_800FCE4E;
extern s16 D_800FCE50;

void func_800FA5A0(void* arg0) {
    s16 d;
    s32 a;

    set_animation(arg0, 5);
    if (D_800970AA < D_800FCE50) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (78/83)
            register s32 t asm("$3") = (u16)D_800FCE4E;
            d = t - M2C_FIELD(arg0, s16*, 0xA);
        }
        a = (d < 0) ? -d : d;
        if (a < 0x20) {
            goto near;
        }
        goto far;
    }
    M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    {
        // !FAKE: depin: dropping it breaks the match (77/83)
        register s32 t asm("$3") = (u16)D_800FCE4C;
        d = t - M2C_FIELD(arg0, s16*, 0xA);
    }
    a = (d < 0) ? -d : d;
    if (a < 0x20) {
    near:
        set_animation(arg0, 6);
        play_sound(2, 0x44, arg0);
        func_80012D9C(6);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (53/83)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 2;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
        return;
    }
far:
    play_sound(2, 0x35, arg0);
    {
        s32 q = (d << 16) / 42;
        do {
        } while (0);
        M2C_FIELD(arg0, s32*, 0x20) = q;
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x2666;
    M2C_FIELD(arg0, u8*, 6) += 1;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern s32 D_800FCA84;

void func_800FA6EC(void* arg0) {
    s32 i;
    void* e;

    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        play_sound(2, 0x45, arg0);
        func_80012D9C(5);
    }
    if ((s16)++M2C_FIELD(arg0, u16*, 0x7C) == 0x50) {
        set_animation(arg0, 7);
        play_sound(2, 0x3B, arg0);
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        play_sound(2, 0x46, arg0);
        i = 0;
    loop: {
        s32 n;
        e = func_8002C458();
        n = i + 1;
        if (e != 0) {
            M2C_FIELD(e, u8*, 0) = 0x41;
            M2C_FIELD(e, u8*, 1) = 0x22;
            M2C_FIELD(e, u8*, 2) = 4;
            M2C_FIELD(e, void**, 0x7C) = arg0;
            if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                M2C_FIELD(e, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - n * 0x24;
            } else {
                M2C_FIELD(e, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + n * 0x24;
            }
        }
        i = n;
    }
        if (i < 8) {
            goto loop;
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        set_animation(arg0, 1);
        {
            u8* tb = ((u8*)&D_800FCA84 + 0x28C);
            u8* q = M2C_FIELD(arg0, u8*, 0x8B)++ +
                    M2C_FIELD(arg0, u8*, 0x8A) * 6 + tb;
            u8 v = *q;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
            M2C_FIELD(arg0, u8*, 0x5) = v;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* enemy_slot_alloc();
extern M2C_UNK D_8007433C;
extern struct X4_EngineObj g_playthrough_state;

void func_800FA864(void* arg0) {
    void* e;

    if (M2C_FIELD(arg0, u16*, 0x7C) & 4) {
        M2C_FIELD(arg0, u16*, 0xE) -= 2;
    } else {
        M2C_FIELD(arg0, u16*, 0xE) += 2;
    }
    if (M2C_FIELD(arg0, s32*, 0x84) != 0) {
        struct X4_EngineObj* g = &g_playthrough_state;
        u8 n = M2C_FIELD(g, u8*, 0x33);
        if (M2C_FIELD(g, s8*, 0x33) < 3) {
            M2C_FIELD(g, u8*, 0x33) = n + 1;
            e = enemy_slot_alloc(n);
            if (e != 0) {
                M2C_FIELD(e, u8*, 0) = 0x41;
                M2C_FIELD(e, u8*, 1) = 0xF;
                M2C_FIELD(e, u8*, 2) = 0x32;
                M2C_FIELD(e, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
                M2C_FIELD(e, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
            }
            goto block_8;
        }
    }
    if ((s16)++M2C_FIELD(arg0, u16*, 0x7C) == 0x50) {
    block_8:
        if (M2C_FIELD(arg0, u8*, 0x88) < 0xF) {
            M2C_FIELD(arg0, u8*, 0x88) = 0x1E;
        }
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x80000;
        }
        M2C_FIELD(arg0, s32*, 0x2C) = 0x10000;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_80075AFC;
extern struct X4_PlayerObj g_Player;
extern s32 D_800FCA84;
extern s32 D_800FCE24;
extern s32 D_800FCE28;

#define PARENT (*(u8**)((s32) & D_800FCA84 + 0x3DC))

void func_800FA984(void* arg0) {
    s32 ang;
    // !FAKE: depin: dropping it breaks the match (136/143)
    register u8* r asm("$3");
    // !FAKE: depin: dropping it breaks the match (136/143)
    register u8* p asm("$5");
    // !FAKE: depin: dropping it breaks the match (116/143)
    register u8* q asm("$6");
    u16 y;
    s32 t3c;
    u8 t15;

    p = PARENT;
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    t3c = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(arg0, u8*, 0x16) = 1;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    r = PARENT;
    M2C_FIELD(arg0, s32*, 0x3C) = t3c;
    t15 = M2C_FIELD(r, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FCE24;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FCE28;
    M2C_FIELD(arg0, void**, 0x58) = &D_80075AFC;
    M2C_FIELD(arg0, u8*, 0x15) = t15;
    ((void (*)(void*, s32, s32, s32))set_animation)(arg0, 0xD, t3c, t15);
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(PARENT, s16*, 0xA) - 0x10;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(PARENT, s16*, 0xA) + 0x10;
    }
    y = M2C_FIELD(PARENT, u16*, 0xE);
    M2C_FIELD(arg0, u16*, 0xE) = y;
    if (M2C_FIELD(arg0, s8*, 0x2) >= 2) {
        M2C_FIELD(arg0, u16*, 0xE) = y - 8;
    }
    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x30000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    } else {
        ang = (s16)ratan2(g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                          g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
        M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) * 0x30;
        M2C_FIELD(arg0, s32*, 0x24) = -rsin(ang) * 0x30;
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
    }
    {
        // !FAKE: depin: dropping it breaks the match (126/143)
        register s32 vx asm("$5") = M2C_FIELD(arg0, s32*, 0x20);
        M2C_FIELD(arg0, u8*, 0x5C) = 0x64;
        M2C_FIELD(arg0, u8*, 0x60) = 6;
        q = PARENT;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        {
            s32 t = vx * 3;
            M2C_FIELD(arg0, s32*, 0x20) = t / 2;
        }
    }
    {
        // !FAKE: depin: dropping it breaks the match (128/143)
        register s32 vy asm("$5") = M2C_FIELD(arg0, s32*, 0x24);
        // !FAKE: depin: dropping it breaks the match (131/143)
        register s32 u asm("$3") = vy * 3;
        M2C_FIELD(arg0, s32*, 0x24) = u / 2;
    }
    {
        u8 c = M2C_FIELD(q, u8*, 0x7) + 1;
        M2C_FIELD(q, u8*, 0x7) = c;
    }
    play_sound(2, 0x43, arg0);
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    M2C_FIELD(arg0, u8*, 0x5) = M2C_FIELD(arg0, u8*, 0x2);
}

// clang-format off
INCLUDE_ASM("asm/rock_45/nonmatchings/FA000", func_800FABC0);
// clang-format on

#define func_800EB5A0 func_800FB214
#define D_800F6A84 D_800FCD70
#include "../shared/rock_04/func_800EB5A0.c"
#undef func_800EB5A0
#undef D_800F6A84

#include "common.h"

void func_800FB274(void) {
}

#define func_8003744C func_800FB27C
#define D_80073C1C D_800FCDA4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();               /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */
extern s8 D_800970A5;
extern s8 D_8009723F;

void func_800FB2B8(void* arg0) {
    void* temp_v0;

    if (D_800970A5 == 0x14) {
        D_8009723F = 2;
        func_8003D308(0x1D, 0x40);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x18;
            M2C_FIELD(temp_v0, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);     /* extern */
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEDF;

void func_800FB350(void* arg0) {
    if (D_800CCEDF == 0) {
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0x28) {
            M2C_FIELD(arg0, s32*, 0x94) = background_objects[0].unk26;
            background_objects[0].unk26 = background_objects[0].unk24 - 0x10;
        }
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_8003D308(0x14, 0x40);
        }
        if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
            play_sound(2, 0x47, arg0);
            set_animation(arg0, 0);
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFF80000;
            {
                // !FAKE: puts the byte increment in the first return register
                register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
                M2C_FIELD(arg0, u8*, 6) = t;
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);
extern s32 D_800FCA84;

void func_800FB414(void* arg0) {
    if ((M2C_FIELD(arg0, void**, 0x68) == 0) &&
        (M2C_FIELD(arg0, s16*, 0xE) >= 0x12C)) {
        M2C_FIELD(arg0, void**, 0x68) = &D_800FCA84;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (is_text_box_seen(2) == 0) {
            open_text_box(2, 0xFF, 0);
            set_text_box_seen(2);
        }
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        {
            // !FAKE: puts the byte increment in the first return register
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
    func_80017A04(arg0);
    move_object(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80040488(M2C_UNK);                 /* extern */
extern u8 D_8008EAFC;
extern s8 D_800CCEF4;

void func_800FB4E8(void* arg0) {
    if (D_8008EAFC == 0) {
        ((void (*)(M2C_UNK))func_80040488)(0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        D_800CCEF4 = 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 1;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);    /* extern */
M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
M2C_UNK func_8003D330();                        /* extern */
s32 func_80040498();                            /* extern */
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF5C;
extern u16 D_800FCE64;

void func_800FB54C(void* arg0) {
    if (func_80040498() != 0) {
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    background_objects[0].unk26 = M2C_FIELD(arg0, u16*, 0x94);
    if (M2C_FIELD(arg0, s8*, 0x5C) < D_800CCF5C) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            play_sound(0, 0xE, 0);
            M2C_FIELD(arg0, s16*, 0x7C) = 3;
        }
        M2C_FIELD(arg0, s8*, 0x5C)++;
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    background_objects[0].unk48 = 8;
    func_8003D330();
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
    D_800FCE64 = M2C_FIELD(arg0, u16*, 0xE);
    M2C_FIELD(arg0, u8*, 5) = 4;
    M2C_FIELD(arg0, u8*, 6) = 0;
}

#define func_800F4674 func_800FB650
#define D_800F7C30 D_800FCDB8
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

void func_800FB6B4(void* arg0) {
    ((void (*)(void*, M2C_UNK))set_animation)(arg0, 1);
    M2C_FIELD(arg0, u8*, 0x89) = 0x3C;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800FCA84;

void func_800FB6F0(void* arg0) {
    u8 t;
    u8* p;
    s32 i;

    if (M2C_FIELD(arg0, u8*, 0x89) == 0) {
        p = (u8*)&D_800FCA84 + 0x28C;
        i = M2C_FIELD(arg0, u8*, 0x8B) + M2C_FIELD(arg0, u8*, 0x8A) * 6;
        t = p[i];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 0x8B)++;
        M2C_FIELD(arg0, u8*, 5) = t;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x89)--;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
s32 random_byte();                            /* extern */
extern s8 D_800CCF5C;
extern s32 D_800FCA84;

void func_800FB74C(void* arg0) {
    u32 r;
    u8* p;
    s32 t;
    s32 x;
    u8 v;

    r = random_byte() & 0xF;
    M2C_FIELD(arg0, u8*, 0x8B) = 0;
    if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
        if (r < 0xA) {
            M2C_FIELD(arg0, u8*, 0x8A) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x8A) = 1;
        }
    } else if (r < 6) {
        M2C_FIELD(arg0, u8*, 0x8A) = 2;
    } else {
        M2C_FIELD(arg0, u8*, 0x8A) = 3;
    }
    p = ((u8*)&D_800FCA84 + 0x28C);
    t = (u8)M2C_FIELD(arg0, u8*, 0x8B)++;
    x = M2C_FIELD(arg0, u8*, 0x8A) * 6;
    v = p[t + x];
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = v;
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}

// clang-format off
INCLUDE_ASM("asm/rock_45/nonmatchings/FA000", func_800FB824);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;

void func_800FB888(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 2);
    {
        s32 g = D_800970AA;
        if (M2C_FIELD(arg0, s16*, 0xA) < g) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    M2C_FIELD(arg0, u8*, 0x7) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern s16 D_800970AA;
extern u8 D_800CCF5F;
extern u8 D_800FA000[];

void func_800FB8EC(void* arg0) {
    u8 tbl[4];

    __builtin_memcpy(tbl, D_800FA000 + 0xC, 4);
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        void* e = func_8002C458();
        if (e != 0) {
            M2C_FIELD(e, u8*, 0) = 0x41;
            M2C_FIELD(e, u8*, 1) = 0x22;
            if (M2C_FIELD(arg0, s16*, 0x7E) == 0) {
                M2C_FIELD(e, u8*, 2) = 0;
            } else {
                M2C_FIELD(e, u8*, 2) = 1;
            }
            M2C_FIELD(e, void**, 0x7C) = arg0;
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        if ((s16)++M2C_FIELD(arg0, u16*, 0x7E) == tbl[D_800CCF5F]) {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
            M2C_FIELD(arg0, u8*, 0x6)++;
            return;
        }
        ((void (*)(void*, s32))set_animation)(arg0, 2);
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800FCA84;

void func_800FB9F8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x7) == 0) {
        u8* p;
        s32 t;
        s32 x;
        set_animation(arg0, 1);
        p = ((u8*)&D_800FCA84 + 0x28C);
        t = (u8)M2C_FIELD(arg0, u8*, 0x8B)++;
        x = M2C_FIELD(arg0, u8*, 0x8A) * 6;
        M2C_FIELD(arg0, u8*, 0x5) = p[t + x];
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_45/nonmatchings/FA000", func_800FBA6C);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;
extern s32 D_800FCA84;

void func_800FBAD0(void* arg0) {
    s16 d;

    ((void (*)(void*, s32))set_animation)(arg0, 5);
    {
        // !FAKE: depin: dropping it breaks the match (59/64)
        register s32 f asm("$3") = M2C_FIELD(arg0, s16*, 0xA);
        // !FAKE: depin: dropping it breaks the match (62/64)
        register s32 g asm("$4") = D_800970AA;
        if (g > f) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    d = *(u16*)((u8*)&D_800FCA84 + 0x3CC) - M2C_FIELD(arg0, u16*, 0xA);
    if ((d < 0 ? -d : d) < 0x20) {
        set_animation(arg0, 8);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (61/64)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 0x6) + 2;
            M2C_FIELD(arg0, u8*, 0x6) = t;
        }
        return;
    }
    play_sound(2, 0x35, arg0);
    M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x2666;
    M2C_FIELD(arg0, u8*, 0x6) += 1;
    M2C_FIELD(arg0, s32*, 0x20) = (d << 16) / 42;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;

void func_800FBBD0(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        if (M2C_FIELD(arg0, s32*, 0x24) != 0) {
            play_sound(2, 0x42, arg0);
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        ((void (*)(void*, s32))set_animation)(arg0, 8);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
extern s32 D_800FCA84;

void func_800FBC84(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        u8* p;
        s32 t;
        s32 x;
        u8 v;
        set_animation(arg0, 1);
        p = ((u8*)&D_800FCA84 + 0x28C);
        t = (u8)M2C_FIELD(arg0, u8*, 0x8B)++;
        x = M2C_FIELD(arg0, u8*, 0x8A) * 6;
        v = p[t + x];
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = v;
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_65_magma_dragoon.c:magma_dragoon_breath, AGPL-3.0; proven shared with X6 by exact signature 98a46ba8d11d (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern void (*D_800FCDDC[])(struct X4_MainObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800FBCF8(struct X4_MainObj* self) {
    D_800FCDDC[self->unk6](self);
    func_8002CCB0((struct X4_BaseObj*)self, 0x40, 0x40);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;

void func_800FBD4C(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 4);
    if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, u8*, 0x6)++;
    func_80017A04(arg0);
    func_8002D230(arg0);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;

void func_800FBDB8(void* arg0) {
    s16 d;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x35, arg0);
        d = D_800970AA - M2C_FIELD(arg0, s16*, 0xA);
        if (d < 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = (d << 16) / 40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s32*, 0x20) = (d << 16) / 40;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x1999;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04(void*);                /* extern */
M2C_UNK func_8002D230(void*);                /* extern */

void func_800FBE94(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        play_sound(2, 0x38, arg0);
        play_sound(2, 0x5C, arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_800FBF00(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 3) {
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            M2C_FIELD(arg0, s8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s32*, 0x20) = -0x10000;
        } else {
            M2C_FIELD(arg0, s8*, 0x15) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0x10000;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x2222;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
    ((M2C_UNK(*)())func_80017A04)();
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_80017A04(void*);                /* extern */
M2C_UNK func_8002D230(void*);                /* extern */
extern s32 D_800FCA84;

void func_800FBF78(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        if (M2C_FIELD(arg0, s32*, 0x24) != 0) {
            play_sound(2, 0x42, arg0);
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        u8* p;
        s32 t;
        s32 x;
        u8 v;
        set_animation(arg0, 1);
        p = ((u8*)&D_800FCA84 + 0x28C);
        t = (u8)M2C_FIELD(arg0, u8*, 0x8B)++;
        x = M2C_FIELD(arg0, u8*, 0x8A) * 6;
        v = p[t + x];
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = v;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_45/nonmatchings/FA000", func_800FC038);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800FC09C(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        if (M2C_FIELD(arg0, s32*, 0x24) != 0) {
            ((void (*)(s32, s32, void*))play_sound)(2, 0x42, arg0);
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 6);
        ((void (*)(s32, s32, void*))play_sound)(2, 0x44, arg0);
        ((void (*)(s32))func_80012D9C)(6);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_45/nonmatchings/FA000", func_800FC13C);
// clang-format on

#include "common.h"
#define M2C_UNK s32
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800FC1A0(void* arg0) {
    play_sound(2, 0x3E, arg0);
    ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xA);
    F32(arg0, 0x20) = 0;
    F32(arg0, 0x24) = 0;
    F32(arg0, 0x28) = 0;
    F32(arg0, 0x2C) = 0;
    F16(arg0, 0x7C) = 0;
    F8(arg0, 6)++;
}
#undef F8
#undef F16
#undef F32

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800FCA84;

void func_800FC1FC(void* arg0) {
    s16 d;
    u16 x;

    if (M2C_FIELD(arg0, u8*, 0x88) < 0xF) {
        M2C_FIELD(arg0, u8*, 0x88) = 0x1E;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        set_animation(arg0, 5);
        play_sound(2, 0x35, arg0);
        x = M2C_FIELD(arg0, u16*, 0xA);
        if (M2C_FIELD(arg0, s16*, 0xA) < *(s16*)((u8*)&D_800FCA84 + 0x3CC)) {
            do {
            } while (0);
            {
                s32 t = *(u16*)((u8*)&D_800FCA84 + 0x3CA);
                d = t - x;
            }
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else {
            do {
            } while (0);
            {
                s32 t = *(u16*)((u8*)&D_800FCA84 + 0x3C8);
                d = t - x;
            }
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x2666;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
        M2C_FIELD(arg0, s32*, 0x20) = (d << 16) / 42;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;
extern s32 D_800FCA84;

void func_800FC2F0(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x88) < 0xF) {
        M2C_FIELD(arg0, u8*, 0x88) = 0x1E;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        if (M2C_FIELD(arg0, s32*, 0x24) != 0) {
            play_sound(2, 0x42, arg0);
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        *(s32*)((u8*)&D_800FCA84 + 0x3D8) = 0;
        M2C_FIELD(arg0, u8*, 0x88) = 0x1E;
        {
            s32 g = D_800970AA;
            if (M2C_FIELD(arg0, s16*, 0xA) < g) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
        }
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        M2C_FIELD(arg0, u8*, 0x5) = 4;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}

#define func_80041AB8 func_800FC3C0
#define D_80075FD8 D_800FCE0C
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern u8 D_800970B5;

void func_800FC3FC(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0xA);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
    M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
    M2C_FIELD(arg0, u8*, 0x61) = 0x19;
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x5) += 1;
    func_8003D308(0x14, D_800970B5);
    func_8002CCB0(arg0, 0x40, 0x40);
}

#define func_800F5564 func_800FC470
#include "../shared/commander_yammark/func_800F5564.c"
#undef func_800F5564

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern u16 D_800FCE64;

void func_800FC570(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 0x7) != 0) {
        if (g_Player.x_pos.i.hi < M2C_FIELD(arg0, s16*, 0xA)) {
            g_Player.unk15 = 0x40;
        } else {
            g_Player.unk15 = 0;
        }
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        ((void (*)(void*, s32))set_animation)(arg0, 0xB);
        {
            s32 t = D_800FCE64;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x68) = 0;
            M2C_FIELD(arg0, u16*, 0xE) = t;
            M2C_FIELD(arg0, u8*, 0x5)++;
        }
        return;
    }
    if ((s16)--M2C_FIELD(arg0, u16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x7E) = 5;
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);   /* extern */

void func_800FC67C(void* arg0) {
    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        open_text_box(3, 0xFF, 0);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
    func_8002CCB0(arg0, 0x40, 0x40);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern u8 D_8008EAFC;

void func_800FC6E4(void* arg0) {
    if (D_8008EAFC == 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x40, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0xC);
        M2C_FIELD(arg0, u8*, 0x5) = (u8)(M2C_FIELD(arg0, u8*, 0x5) + 1);
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x40, 0x40);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);    /* extern */
M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK clear_object_slot();                        /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(void*);                     /* extern */
extern s8 D_800CCEDF;

void func_800FC74C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        D_800CCEDF = 0x10;
        clear_object_slot();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x48, arg0);
        M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
    func_80017A04(arg0);
    move_object(arg0);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002EE10(void*);
extern s32 D_800FCA84;

void func_800FC7D8(void* arg0) {
    s8 s;

    if (M2C_FIELD(arg0, s32*, 0x84) == 0 && M2C_FIELD(arg0, u8*, 0x70) == 0) {
        func_8002EE10(arg0);
    }
    s = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, u8*, 3) = 0;
    switch (s) {
    case 0 ... 3:
        ((void (**)(void*))((u8*)&D_800FCA84 + 0x3AC))[M2C_FIELD(arg0, s8*, 4)](
            arg0);
        break;
    case 4:
        ((void (**)(void*))((u8*)&D_800FCA84 + 0x3B8))[M2C_FIELD(arg0, s8*, 4)](
            arg0);
        break;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
extern s32 D_800FCA84;

void func_800FC898(s32 arg0) {
    u8* p = *(u8**)((u8*)&D_800FCA84 + 0x3DC);

    p[7]--;
    clear_object_slot(arg0, p);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800FCA84;

#define CUR (*(u8**)((u8*)&D_800FCA84 + 0x3DC))

void func_800FC8CC(void* arg0) {
    u8* p = CUR;
    s32 x;
    u8 t;
    // !FAKE: pin keeps the reloaded base in the first return register
    register u8* q asm("$2");
    u16 e;
    u8 b;

    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    x = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 1;
    q = CUR;
    M2C_FIELD(arg0, s32*, 0x3C) = x;
    t = M2C_FIELD(q, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = t;
    set_animation(arg0, 0xE);
    q = CUR;
    b = M2C_FIELD(arg0, u8*, 0x4) + 1;
    e = M2C_FIELD(q, u16*, 0xE);
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 8;
    M2C_FIELD(arg0, s32*, 0x8C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = b;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, s16*, 0xE) = e - 0x36;
}
#undef CUR

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*);
extern s32 D_800FCA84;
extern s32 D_800FCE58;
extern s32 D_800FCE5C;

void func_800FC9AC(void* arg0) {
    s32 t;

    if (D_800FCE5C != 0 || D_800FCE58 != 0) {
        M2C_FIELD(arg0, u8*, 0x4) = 2;
        return;
    }
    func_80030ECC(arg0);
    if (M2C_FIELD(arg0, s8*, 0x5) == 0) {
        if (M2C_FIELD(arg0, s32*, 0x8C) == 0x14) {
            M2C_FIELD(arg0, void**, 0x50) = (u8*)&D_800FCA84 + 0x3A8;
        }
        t = M2C_FIELD(arg0, s32*, 0x8C) + 1;
        M2C_FIELD(arg0, s32*, 0x8C) = t;
        if (t == 0x3C) {
            M2C_FIELD(arg0, u8*, 0x4) = 2;
        }
    }
    func_8002CCB0(arg0, 0x20, 0x100);
    func_80017A04(arg0);
    move_object(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FCA64(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_45/nonmatchings/FA000", D_800FCA84);
// clang-format on
