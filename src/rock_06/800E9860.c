// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", D_800E9860);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F(expr, type, offset) (*(type*)((u8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

extern s32 D_80075B9C;
extern s8 D_800970A5;
extern s32 D_800F35A0;
extern s32 D_800F35A8[];
extern s32 D_800F35D0;
extern s32 D_800F35D4[];
extern struct X4_Unk_unk68 D_800F4018;
extern struct X4_Unk_unk68 D_800F401C;

void func_800E9878(struct X4_PlayerObj* self) {
    u8 raw;
    s32 sh;
    s32 kind;
    s32 hi;
    s32 lo;

    if (D_800970A5 != 0) {
        self->unk5 = 2;
        self->active = 0x41;
        self->invincibility_timer = 0;
        self->unk68 = (struct X4_Unk_unk68*)((s8*)self + 0x7C);
        self->state++;
        F(self, struct X4_Unk_unk68, 0x7C) = D_800F4018;
        self->unk54 = (const u32*)((s8*)self + 0x80);
        F(self, struct X4_Unk_unk68, 0x7C) = D_800F401C;
        raw = F(self, u8, 0x2);
        sh = raw << 24;
        kind = sh >> 24;
        if (kind < 0xA) {
            F(self, void*, 0x68) = &D_800F35D4[kind];
            F(self, void*, 0x54) = &D_800F35A8[kind];
        } else if (kind == 0x70) {
            F(self, s8, 0x7E) = 0x20;
            F(self, s8, 0x7F) = 8;
            F(self, s8, 0x80) = -0x20;
            F(self, s8, 0x81) = -8;
            F(self, s8, 0x82) = 0x40;
            F(self, s8, 0x7C) = 0;
            F(self, s8, 0x7D) = 0;
            F(self, s8, 0x83) = 0x10;
            F(self, void*, 0x50) = &D_800F35D0;
        } else {
            hi = (u32)sh >> 28;
            lo = raw & 0xF;
            F(self, s8, 0x7E) = hi * 8;
            F(self, s8, 0x7F) = lo * 8;
            F(self, s8, 0x7C) = 0;
            F(self, s8, 0x7D) = 0;
            F(self, s8, 0x80) = -(hi * 8);
            F(self, s8, 0x81) = -(lo * 8);
            F(self, s8, 0x82) = hi * 16;
            F(self, s8, 0x83) = lo * 16;
        }
        F(self, void*, 0x58) = &D_80075B9C;
        F(self, void*, 0x30) = &D_800F35A0;
        F(self, s8, 0x60) = 0x7F;
        F(self, s8, 0x15) = 0;
        F(self, s8, 0x65) = 0;
        F(self, s8, 0x76) = 0;
        F(self, s8, 0xA2) = 1;
        F(self, s8, 0x88) = 0;
        F(self, s8, 0x75) = 1;
        F(self, s16, 0x86) = F(self, s16, 0xE);
        set_animation(self, 0);
        F(self, s8, 0x6) = 0;
    }
}

#undef F

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK collide_solid_object();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
s32 func_80032B34(struct X4_PlayerObj*);
void func_80032BE8(struct X4_PlayerObj*);

extern M2C_UNK g_Player;
#define PLAYER (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;
extern void (*D_800F3608[])(struct X4_PlayerObj*);

#define ABS(v) ((v) < 0 ? -(v) : (v))
#define PL_E5 M2C_FIELD(&PLAYER, u8*, 0xE5)

#define GROUND(self)                                                           \
    {                                                                          \
        struct X4_PlayerObj* pl = &PLAYER;                                     \
        if (M2C_FIELD(pl, u8*, 0xE5) == 0) {                                   \
            collide_solid_object(self);                                               \
            if (g_playthrough_state.character_state.fields.flags != 0 &&       \
                (self->unk72 & 4) && (pl->unk70 & 8)) {                        \
                pl->unk71 = 0;                                                 \
            }                                                                  \
            if (self->unk76 != 0 && (self->unk72 & 3)) {                       \
                y = PLAYER.y_pos.val;                                          \
                PLAYER.y_pos.val = y - PLAYER.y_vel.val;                       \
                collide_solid_object(self);                                           \
                if (self->unk76 == 0) {                                        \
                    PLAYER.y_pos.val -= PLAYER.y_vel.val;                      \
                } else {                                                       \
                    PLAYER.y_pos.val = y;                                      \
                }                                                              \
            }                                                                  \
        }                                                                      \
    }

void func_800E9A30(struct X4_PlayerObj* self) {
    s32 y;

    if (g_playthrough_state.stage == 4) {
        if (self->y_pos.i.hi >= 0x2A0 && g_playthrough_state.checkpoint == 0 &&
            g_playthrough_state.substage == 0) {
            return;
        }
    } else if (g_playthrough_state.stage < 0x13 &&
               g_playthrough_state.checkpoint != 2) {
        return;
    }
    {
        func_80032B34(self);
        if (PLAYER.nova_strike_active != 2) {
            D_800F3608[self->unk6](self);
        }
        func_8002CCB0(self, 0xA0, 0xA0);
        if (g_playthrough_state.substage == 0 && self->unk2 == 0) {
            GROUND(self)
            func_80032BE8(self);
            func_8003208C(self);
            ((void (*)())func_80031F4C)(self);
            self->on_screen = 0;
            return;
        }
        if (ABS(PLAYER.x_pos.i.hi - self->x_pos.i.hi) < 0xA0 &&
            self->on_screen == 1) {
            GROUND(self)
        }
        func_80032BE8(self);
        func_8003208C(self);
        ((M2C_UNK(*)())func_80031F4C)(self);
        self->on_screen = 0;
    }
}

#include "../shared/rock_06/func_800E9D5C.c"

#define func_80048DC8 func_800E9E98
#define D_80077BC0 D_800F35FC
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800E9EE4(void) {
    func_8002CA14();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);

extern M2C_UNK D_800743DC;
extern u32* D_80095098;
extern u8 D_800970B4;
extern s32 D_800F362C;
extern s32 D_800F3654[];
extern struct X4_Unk_unk68 D_800F365C;
extern struct X4_Unk_unk68 D_800F3660;

void func_800E9F04(struct X4_PlayerObj* self) {
    s32 t;

    if (self->unk2 & 0x80) {
        self->unk7 = 1;
        self->unk16 = 0x22;
    } else {
        self->unk7 = 0;
        self->unk16 = 0x23;
    }
    self->unk5 = 2;
    self->active = 0x41;
    self->unk6 = 0;
    self->unk2 &= 0x7F;
    self->state++;
    self->bg_offset = D_800970B4;
    self->unk40 = D_80095098[func_8002A47C(0x8A)] >> 7;
    self->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(0x8A)];
    self->unk42 = ((func_8002A47C(0x8A) * 4 + 0x20) % 16) |
                  (((func_8002A47C(0x8A) + 8) / 4 + 0x1E0) << 6);
    self->unk68 = (struct X4_Unk_unk68*)((s8*)self + 0x80);
    if (self->unk2 == 0) {
        M2C_FIELD(self, struct X4_Unk_unk68*, 0x80) = D_800F365C;
    } else {
        M2C_FIELD(self, struct X4_Unk_unk68*, 0x80) = D_800F3660;
    }
    t = (s32)&D_800F362C;
    self->animation_table = (u32**)t;
    t = 0x10;
    self->hp = t;
    M2C_FIELD(self, u8*, 0xA2) = 1;
    self->unk60 = 0x7F;
    self->unk75 = 1;
    self->unk58 = &D_800743DC;
    self->unk50 = 0;
    self->invincibility_timer = 0;
    self->unk76 = 0;
    self->unk15 = 0;
    self->unk65 = 0;
    self->unk54 = (const u32*)&D_800F3654[self->unk2];
    M2C_FIELD(self, u8*, 0x47) = self->unk2;
}

#include "../shared/rock_06/func_800EA0EC.c"

// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EA230);
// clang-format on

#define func_80048DC8 func_800EA530
#define D_80077BC0 D_800F3664
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EA57C(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002C9D4(); /* extern */

void func_800EA59C(void) {
    func_8002C9D4();
}

#define func_80041AB8 func_800EA5BC
#define D_80075FD8 D_800F3674
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_12_ride_dust.c:ride_dust_init, AGPL-3.0; proven shared with X6 by exact signature 6eac507027d5 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800F3680[];
extern u8 D_800F368C[];
s32 set_animation(void*, s32);

void func_800EA5F8(struct X4_VisualObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    arg0->unk16 = VISUAL_SATURN_LAYER(D_800F368C[arg0->unk2]);
    set_animation(arg0, D_800F3680[arg0->unk2]);
}

#include "../shared/rock_06/func_800EA64C.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EA6E4(void) {
    clear_object_slot();
}

#include "../shared/rock_06/func_800EA704.c"

#include "../shared/rock_06/func_800EA840.c"

#include "../shared/rock_06/func_800EA9E0.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800743DC;
extern M2C_UNK D_800F369C;
extern M2C_UNK D_800F36A0;
extern M2C_UNK D_800F36A4;

void func_800EABCC(void* arg0) {
    switch (M2C_FIELD(arg0, s8*, 6)) {
    case 0:
        M2C_FIELD(arg0, s8*, 6)++;
        set_animation(arg0, 5);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
    case 1:
        if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
            M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_8007433C;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F36A0;
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F36A0;
        }
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, s8*, 6)++;
            set_animation(arg0, 6);
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
            M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800743DC;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F36A4;
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F369C;
            M2C_FIELD(arg0, s8*, 5) = 1;
            M2C_FIELD(arg0, s8*, 6) = 0;
            {
                // !FAKE: depin: dropping it breaks the match (68/79)
                register s32 l asm("$3") = M2C_FIELD(arg0, u8*, 0x80);
                M2C_FIELD(arg0, u8*, 0x82) = 0x78;
                M2C_FIELD(arg0, u8*, 0x80) = l & 0xFE;
            }
        }
        break;
    }
    func_80017A04(arg0);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800743DC;
extern M2C_UNK g_Player;
extern M2C_UNK D_800F3698;
extern M2C_UNK D_800F369C;
extern M2C_UNK D_800F36A4;
extern M2C_UNK D_800F379C;

void func_800EAD08(void* arg0) {
    struct X4_AnimatedObj* self = arg0;
    s32 x;
    s32 f;
    s32 m;
    self->state++;
    self->unk5 = 1;
    x = self->x_pos.val;
    self->bg_offset = (*(struct X4_PlayerObj*)&g_Player).bg_offset;
    self->unk18.val = x;
    self->unk1C.val = self->y_pos.val;
    f = ((*(struct X4_PlayerObj*)&g_Player).x_pos.val >= x) << 6;
    self->animation_table = (u32**)&D_800F379C;
    self->unk16 = 6;
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_800F3698;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F36A4;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F369C;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800743DC;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x70) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 3;
    M2C_FIELD(arg0, u8*, 0x60) = 1;
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = 0;
    self->unk2C = 0;
    M2C_FIELD(arg0, u8*, 0x80) = 0;
    M2C_FIELD(arg0, u8*, 0x82) = 0;
    M2C_FIELD(arg0, u8*, 0x81) = 0;
    M2C_FIELD(arg0, u8*, 0x83) = 0;
    self->unk15 = f;
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 2) < 2U) {
        self->state = 3;
        M2C_FIELD(arg0, void**, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = 0;
        m = -0x10;
        self->x_pos.u.hi = (self->x_pos.u.hi & m) + 8;
        self->y_pos.u.hi = (self->y_pos.u.hi & m) + 0x14;
        set_animation(arg0, 0);
    } else {
        set_animation(arg0, 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
void func_800EA704(struct X4_BaseObj* self);
void func_800EA840(struct X4_BaseObj* self);
void func_800EA9E0(struct X4_BaseObj* self);

extern M2C_UNK D_800F37D4;
extern void (*D_800F37D8[])(struct X4_BaseObj*);

void func_800EAE48(struct X4_BaseObj* self) {
    s32 r;
    u8 f;
    s32 v;

    M2C_FIELD(self, s32*, 0x18) = M2C_FIELD(self, s32*, 0x8);
    M2C_FIELD(self, s32*, 0x1C) = M2C_FIELD(self, s32*, 0xC);
    func_800EA840(self);
    func_800EA704(self);
    func_800EA9E0(self);
    D_800F37D8[self->unk5](self);
    ((void (*)(void*))func_80030ECC)(self);
    r = check_enemy_hits(self);
    if (r < 0) {
        ((void (*)(void*))func_80049E50)(self);
        ((void (*)(s32, s32*, void*))func_800477E4)(4, &D_800F37D4, self);
        if (r != -0x38) {
            func_8004E654(self, 0x12);
        }
        v = M2C_FIELD(self, u8*, 4) + 1;
        goto set_state;
    }
    if (func_8002CBFC(self, 0x40, 0x40) != 0) {
        self->state = 4;
        return;
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(self, 0x25, 0x25);
    f = M2C_FIELD(self, u8*, 0x70);
    if ((f & 0xC) == 0xC || (f & 3) == 3) {
        ((void (*)(void*))func_80049E50)(self);
        ((void (*)(s32, s32*, void*))func_800477E4)(4, &D_800F37D4, self);
        self->on_screen = 0;
        v = M2C_FIELD(self, u8*, 4) + 1;
    set_state:
        self->state = v;
        return;
    }
    ((void (*)(void*))func_8002F288)(self);
}

#define func_80041AB8 func_800EAF94
#define D_80075FD8 D_800F37F0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80030CCC(void*, s16, s16);
extern M2C_UNK D_800F369C;
extern M2C_UNK D_800F36A4;

void func_800EAFD0(void* arg0) {
    if (!(func_80030CCC(arg0, M2C_FIELD(arg0, s16*, 0xA),
                        M2C_FIELD(arg0, s16*, 0xE)) &
          0xFF)) {
        M2C_FIELD(arg0, u8*, 4) = 1;
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 2) = 0;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F36A4;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F369C;
    }
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 2) {
            func_8002CCB0(arg0, 0x25, 0x25);
        }
    } else {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}

#include "../shared/rock_06/func_800EB070.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D230();               /* extern */
extern M2C_UNK D_800743DC;

void func_800EB10C(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800743DC;
        func_8002D230(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            set_animation(arg0, 4);
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = 0;
    }
}

#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_80017A04();                     /* extern */
void* func_8002C458();                       /* extern */

void func_800EB1B4(void* arg0) {
    void* temp_v0;

    ((M2C_UNK(*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        temp_v0 = func_8002C458();
        if (temp_v0 != NULL) {
            play_sound(2, 0x2E, arg0);
            M2C_FIELD(temp_v0, s8*, 0) = 0x41;
            M2C_FIELD(temp_v0, s8*, 1) = 0x20;
            M2C_FIELD(temp_v0, s32*, 8) = (s32)M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(temp_v0, s32*, 0xC) = (s32)M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(temp_v0, s32*, 0x3C) = (s32)M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(temp_v0, u16*, 0x40) = (u16)M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(temp_v0, u16*, 0x42) = (u16)M2C_FIELD(arg0, u16*, 0x42);
            M2C_FIELD(temp_v0, u8*, 0x14) = (u8)M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(temp_v0, s32*, 0x30) = (s32)M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(temp_v0, u8*, 0x15) = (u8)M2C_FIELD(arg0, u8*, 0x15);
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s8*, 0x83) = 0x78;
        M2C_FIELD(arg0, u8*, 0x80) = (u8)(M2C_FIELD(arg0, u8*, 0x80) & 0xFD);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
M2C_UNK move_object(void*);            /* extern */
extern M2C_UNK D_800743DC;
extern M2C_UNK D_800F369C;
extern M2C_UNK D_800F36A4;

void func_800EB2B8(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800743DC;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F36A4;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F369C;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        set_animation(arg0, 1);
        var_v0 = -0x6000;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            var_v0 = 0x6000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = var_v0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    func_80017A04(arg0);
    move_object(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if (M2C_FIELD(arg0, u8*, 0x70) & 1) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
        }
    } else if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EB3A0(struct ObjectHeader* arg0) {
    if (arg0->state == 4) {
        func_8002CA54();
        return;
    }
    func_8002CA14();
}

#define func_80041AB8 func_800EB3E0
#define D_80075FD8 D_800F380C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_8007429C;
extern s32 D_800F3804;
extern s32 D_800F3808;

void func_800EB41C(void* arg0) {
    s32 var_a1;
    u8 temp_v1;
    s32 temp_v0;

    var_a1 = 0xFFFD8000;
    M2C_FIELD(arg0, u8*, 3) = 1;
    temp_v1 = M2C_FIELD(arg0, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
    if (temp_v1 != 0) {
        var_a1 = 0x28000;
    }
    temp_v0 = M2C_FIELD(arg0, s16*, 0xA);
    M2C_FIELD(arg0, s32*, 0x20) = var_a1;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (temp_v1 != 0) {
        temp_v0 += 0x10;
    } else {
        temp_v0 -= 0x10;
    }
    M2C_FIELD(arg0, s16*, 0xA) = temp_v0;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, s32**, 0x68) = &D_800F3808;
    M2C_FIELD(arg0, s32**, 0x54) = &D_800F3804;
    M2C_FIELD(arg0, s32**, 0x50) = &D_800F3804;
    M2C_FIELD(arg0, s32**, 0x58) = &D_8007429C;
    M2C_FIELD(arg0, u8*, 0x60) = 2;
    M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) + 3;
    set_animation(arg0, 8);
}

#include "../shared/rock_06/func_800EB4D4.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB59C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EB5BC);
// clang-format on

#define func_800EAE0C func_800EB73C
#include "../shared/rock_02/func_800EAE0C.c"
#undef func_800EAE0C

#define func_800EA1D8 func_800EB8E0
#define D_800FAA64 D_800F3884
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EB92C);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EBA3C(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EB14C func_800EBA7C
#include "../shared/rock_02/func_800EB14C.c"
#undef func_800EB14C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(); /* extern */

void func_800EBAD0(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = 0;
        return;
    }
    func_8002D230();
}

#define func_800EBC8C func_800EBB24
#include "../shared/rock_28/func_800EBC8C.c"
#undef func_800EBC8C

// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EBB6C);

INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EBC70);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EBD24(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800EBD44
#define D_80075FD8 D_800F38AC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EBD80);
// clang-format on

#define func_800EE70C func_800EBEC0
#define g_Player g_Player
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002B6B0();
M2C_UNK func_8003C4EC(void*);
M2C_UNK func_8003CDF0(void*);
M2C_UNK func_8003CE30(void*);
M2C_UNK func_8003F3DC(void*);
extern M2C_UNK g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EBEC0(u8* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    u8* q;
    u16 a;
    s32 two;

    if (F8(p, 0x5C) != 0) {
        background_objects[0].unk44 = 0;
        background_objects[1].unk44 = 0;
        background_objects[2].unk44 = 0;
        two = 2;
        q = (u8*)&g_playthrough_state;
        q[0x10] = two;
        q[0x11] = two;
        q[0x12] = two;
        q[0x13] = two;
        q[0x14] = two;
        q[0x15] = two;
        q[0x16] = two;
        q[0x17] = two;
        q[0x19] = two;
        arg0[0] |= 8;
        F32(arg0, 0x88) = F32(p, 0x68);
        F32(p, 0x68) = 0;
        FU8(p, 0x5) = 2;
        func_8003F3DC(p);
        func_8003CDF0(p);
        func_8003CE30(p);
        func_8003C4EC(p);
        func_8002B6B0();
        F16(arg0, 0x7C) = 0;
        a = FU16(p, 0xA);
        FU16(arg0, 0x80) = a;
        FU16(arg0, 0x82) = a;
        arg0[6]++;
        play_sound(1, 1, arg0);
    }
}
#undef func_800EE70C
#undef g_Player

#define func_800EE800 func_800EBFB4
#define D_80097420 D_80097420
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"
extern struct X4_EngineObj g_playthrough_state;

#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EBFB4(u8* arg0) {
    s32 a;
    s32 b;
    void* t;

    a = FU16(arg0, 0x80) + 1;
    b = FU16(arg0, 0x82) - 1;
    FU16(arg0, 0x80) = a;
    FU16(arg0, 0x82) = b;
    if (!(D_80097420.frame_counter & 1)) {
        g_Player.x_pos.i.hi = a;
    } else {
        g_Player.x_pos.i.hi = b;
    }
    if (D_80097420.transition.active == 0) {
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        g_Player.x_pos.i.hi = FU16(arg0, 0x84);
        t = *(void**)(arg0 + 0x88);
        g_playthrough_state.unk10 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk19 = 0;
        g_Player.unk68 = t;
    }
}
#undef g_Player
#undef func_800EE800
#undef D_80097420

#define func_800EE8C4 func_800EC078
#define background_objects background_objects
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002B6B0();
M2C_UNK func_8003C4EC();
M2C_UNK func_8003CDF0();
M2C_UNK func_8003CE30(void*);
M2C_UNK func_8003F3DC(void*);
extern M2C_UNK g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800EC078(void* arg0) {
    void* p;
    s32 v;

    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
        return;
    }
    play_sound(1, 1, arg0);
    p = &g_Player;
    background_objects[0].unk44 = 0;
    background_objects[1].unk44 = 0;
    background_objects[2].unk44 = 0;
    v = 2;
    g_playthrough_state.unk10 = v;
    g_playthrough_state.unk11 = v;
    g_playthrough_state.unk12 = v;
    g_playthrough_state.unk13 = v;
    g_playthrough_state.unk14 = v;
    g_playthrough_state.unk15 = v;
    g_playthrough_state.unk16 = v;
    g_playthrough_state.unk17 = v;
    g_playthrough_state.unk19 = v;
    M2C_FIELD(arg0, u8*, 0) |= 8;
    M2C_FIELD(arg0, s32*, 0x88) = M2C_FIELD(p, s32*, 0x68);
    M2C_FIELD(p, s32*, 0x68) = 0;
    M2C_FIELD(p, s8*, 5) = 2;
    func_8003F3DC(p);
    func_8003CDF0(p);
    func_8003CE30(p);
    func_8003C4EC(p);
    func_8002B6B0();
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s16*, 0x82) = M2C_FIELD(arg0, s16*, 0x80) =
        M2C_FIELD(p, s16*, 0xA);
    M2C_FIELD(arg0, u8*, 6) += 1;
}
#undef func_800EE8C4
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EC178);

INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EC56C);
// clang-format on

#define func_800EA1D8 func_800EC678
#define D_800FAA64 D_800F3900
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EC6C4);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EC740(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EEFCC func_800EC780
#define g_Player g_Player
#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D654(s8*, u8*);
#define M2C_UNK s32
extern M2C_UNK g_Player;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EC780(s8* arg0) {
    u8* p = (u8*)&g_Player;
    u16 v;
    u16 w;

    if (func_8002D654(arg0, p) != 0) {
        if (arg0[2] == 2) {
            v = FU16(p, 0xA);
            FU16(arg0, 0x7C) = 0;
            arg0[5] = 3;
            arg0[6] = 0;
            FU16(arg0, 0x84) = v;
            return;
        }
        w = FU16(p, 0xA);
        arg0[5] = 2;
        arg0[6] = 0;
        FU16(arg0, 0x84) = w;
    }
}
#undef func_800EEFCC
#undef g_Player

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;
extern s8 D_800CCEF6;

void func_800EC7F8(void* arg0) {
    if ((D_800CCEF6 == 0) && (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA))) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EC844(void* arg0) {
    if (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800EC880
#define D_80073C1C D_800F3928
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EC8BC
#define D_80073C1C D_800F39C4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EF144 func_800EC8F8
#include "../shared/commander_yammark/func_800EF144.c"
#undef func_800EF144

#define func_800EF1E8 func_800EC99C
#include "../shared/commander_yammark/func_800EF1E8.c"
#undef func_800EF1E8

#define func_800EF27C func_800ECA30
#define D_80097420 D_80097420
#include "../shared/commander_yammark/func_800EF27C.c"
#undef func_800EF27C
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECA98(void) {
    clear_object_slot();
}

#include "../shared/rock_06/func_800ECAB8.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 func_800ECAB8(struct X4_PlayerObj*, s16, s16);

extern s32 D_80075B9C;
extern s32 D_80075D7C;
extern u32* D_80095098;
extern u8 D_800970B4;
extern s32 D_800C1220[];
extern s8 D_800CD30A;
extern s32 D_800F39F4;
extern struct X4_Unk_unk68 D_800F3A14;
extern s32 D_800F3A18;

void func_800ECBEC(struct X4_PlayerObj* self) {
    s8 mode;
    s8 kind;

    mode = D_800CD30A;
    if (mode != 5) {
        clear_object_slot();
        return;
    }
    self->state = 1;
    self->unk5 = 2;
    self->active = 0x41;
    self->unk6 = 2;
    self->unk15 = 0;
    self->bg_offset = D_800970B4;
    self->unk40 = D_80095098[func_8002A47C(0x93)] >> 7;
    self->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(0x93)];
    self->unk42 = ((func_8002A47C(0x93) * 4 + 0x20) % 16) |
                  (((func_8002A47C(0x93) + 8) / 4 + 0x1E0) << 6);
    self->unk16 = 0x20;
    kind = self->unk2;
    self->unk58 = &D_80075B9C;
    if (kind == 3) {
        self->unk58 = &D_80075D7C;
        M2C_FIELD(self, u8*, 0x47) = 0;
    } else if (kind == 2) {
        self->unk58 = &D_80075D7C;
        M2C_FIELD(self, u8*, 0x47) = 4;
    } else if (kind == 1) {
        M2C_FIELD(self, u8*, 0x47) = mode;
    } else if (kind == 0) {
        M2C_FIELD(self, u8*, 0x47) = 6;
    }
    self->animation_table = (u32**)&D_800F39F4;
    self->hp = 8;
    self->unk68 = (struct X4_Unk_unk68*)((s8*)self + 0x80);
    M2C_FIELD(self, struct X4_Unk_unk68*, 0x80) = D_800F3A14;
    self->unk54 = (const u32*)&D_800F3A18;
    self->unk50 = 0;
    self->invincibility_timer = 0;
    self->unk75 = 1;
    self->unk60 = 0x10;
    self->unk65 = 0;
    M2C_FIELD(self, u8*, 0xA2) = 1;
    self->x_vel.val = 0;
    self->y_vel.val = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    M2C_FIELD(self, u8*, 0x85) = 0;
    if (func_800ECAB8(self, self->x_pos.i.hi, self->y_pos.i.hi) != 0) {
        self->state = 2;
    }
    if (self->unk2 == 0x11) {
        {
            s32* d = D_800C1220;
            __builtin_memcpy(d + 0xCA7, self, 0xA4);
        }
        clear_object_slot(self);
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54();
M2C_UNK func_8002CB50();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030234();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C(struct X4_PlayerObj*);
s32 func_80032B34(struct X4_PlayerObj*);
void func_80032BE8(struct X4_PlayerObj*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800ECAB8(struct X4_PlayerObj*, s16, s16);

extern struct X4_EngineObj g_playthrough_state;
extern M2C_UNK D_800F3A0C;
extern M2C_UNK D_800F3A10;
extern M2C_UNK D_800F3A1C;
extern void (*D_800F3A2C[])(struct X4_PlayerObj*);

void func_800ECE74(struct X4_PlayerObj* self) {
    s32 x;
    s8 dir;
    s32 r;
    u8 tile;
    struct X4_Unk_unk68* p;

    self->unk42 &= 0x7FFF;
    if (g_playthrough_state.stage >= 0x13) {
        x = (s16)(self->x_pos.i.hi - *(u8*)&self->double_tap_direction) - 1;
        r = func_800ECAB8(self, x, self->y_pos.i.hi);
        tile = func_80030234(self, x, self->y_pos.i.hi) & 0xFF;
        if (r == 0 && tile == 0) {
            p = self->unk68;
            if ((func_80030234(self, self->x_pos.i.hi,
                               self->y_pos.i.hi + p->unk3 + p->unk1) &
                 0xFF) == 0x3A) {
                self->x_pos.i.hi--;
            }
        }
    }
    D_800F3A2C[self->unk6](self);
    if ((s8)func_80032B34(self) < 0) {
        if (self->unk2 == 3) {
            self->dash_timer = 0x1E;
            self->unk50 = &D_800F3A1C;
            func_800477E4(3, &D_800F3A10, self);
        } else {
            func_800477E4(3, &D_800F3A0C, self);
        }
        func_80049EBC(self, 1, 0x1F, 0xF);
        self->state = 2;
        return;
    }
    if (func_8002CBFC(self, 0x80, 0x80) == 0) {
        func_8002CB50(self);
    } else if (g_playthrough_state.stage != 7 ||
               g_playthrough_state.checkpoint != 1) {
        func_8002CA54(self);
    }
    func_80031F4C(self);
    func_80032BE8(self);
    func_8003208C(self);
    if (self->unk70 & 8) {
        self->air_state = 0;
        return;
    }
    if (self->y_vel.val < 0) {
        self->air_state = -1;
    } else {
        self->air_state = 1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(void*);    /* extern */
M2C_UNK func_8002F288(M2C_UNK*); /* extern */
M2C_UNK collide_solid_object();         /* extern */
s32 func_800ECAB8(struct X4_PlayerObj*, s16, s16);
extern M2C_UNK g_Player;

#define F_2(p) M2C_FIELD(p, s8*, 0x2)
#define F_6(p) M2C_FIELD(p, u8*, 0x6)
#define F_8(p) M2C_FIELD(p, s16*, 0x8)
#define F_A(p) M2C_FIELD(p, s16*, 0xA)
#define F_E(p) M2C_FIELD(p, s16*, 0xE)
#define F_20(p) M2C_FIELD(p, s32*, 0x20)
#define F_24(p) M2C_FIELD(p, s32*, 0x24)
#define F_28(p) M2C_FIELD(p, s32*, 0x28)
#define F_2C(p) M2C_FIELD(p, s32*, 0x2C)
#define F_70(p) M2C_FIELD(p, u8*, 0x70)
#define F_7C(p) M2C_FIELD(p, s16*, 0x7C)
#define F_80(p) M2C_FIELD(p, s8*, 0x80)
#define F_81(p) M2C_FIELD(p, s8*, 0x81)
#define F_82(p) M2C_FIELD(p, u8*, 0x82)
#define F_83(p) M2C_FIELD(p, u8*, 0x83)
#define F_85(p) M2C_FIELD(p, u8*, 0x85)
#define F_E5(p) M2C_FIELD(p, u8*, 0xE5)

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define RX(p) (F_A(p) + F_80(p) + F_82(p))
#define LX(p) (F_A(p) + F_80(p) - F_82(p))
#define FY(p) (F_E(p) + F_81(p) + F_83(p))
#define CHECK(p)                                                               \
    {                                                                          \
        void* pl = &g_Player;                                                  \
        if (F_E5(pl) == 0 && ABS(F_A(pl) - F_A(p)) < 0x30) {                   \
            collide_solid_object(p);                                                  \
        }                                                                      \
    }

void func_800ED09C(void* arg0) {
    s32 a;
    s32 b;
    s32 c;
    s16 i;
    s16 t;

    func_8002D230(arg0);
    ((void (*)(void*))func_8002F288)(arg0);
    if (F_20(arg0) > 0) {
        b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), FY(arg0));
        c = func_800ECAB8(arg0, (t = LX(arg0), t - 1), FY(arg0));
        if (b == 0 && c == 0 && !(F_70(arg0) & 8)) {
            for (i = 0; i < 5; i++) {
                b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), FY(arg0));
                c = func_800ECAB8(arg0, (t = LX(arg0), t - 1), FY(arg0));
                if (b == 0 && c == 0 && !(F_70(arg0) & 8)) {
                    F_A(arg0)--;
                }
                ((void (*)(void*))func_8002F288)(arg0);
            }
            if (F_70(arg0) & 8) {
                F_A(arg0)++;
            }
            F_20(arg0) = 0;
            F_28(arg0) = 0;
            F_2C(arg0) = 0xD00;
            F_6(arg0) = 1;
            F_85(arg0) = 0;
            CHECK(arg0);
            return;
        }
    }
    if (F_20(arg0) < 0) {
        b = func_800ECAB8(arg0, RX(arg0), FY(arg0));
        c = func_800ECAB8(arg0, LX(arg0), FY(arg0));
        if (b == 0 && c == 0 && !(F_70(arg0) & 8)) {
            for (i = 0; i < 5; i++) {
                b = func_800ECAB8(arg0, RX(arg0), FY(arg0));
                c = func_800ECAB8(arg0, LX(arg0), FY(arg0));
                if (b == 0 && c == 0 && !(F_70(arg0) & 8)) {
                    F_A(arg0)++;
                }
                ((void (*)(void*))func_8002F288)(arg0);
            }
            if (F_70(arg0) & 8) {
                F_A(arg0)--;
            }
            F_20(arg0) = 0;
            F_28(arg0) = 0;
            F_2C(arg0) = 0xD00;
            F_6(arg0) = 1;
            F_85(arg0) = 0;
            CHECK(arg0);
            return;
        }
    }
    a = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0) + 0x10);
    b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0));
    c = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0) - 0x10);
    if (F_20(arg0) > 0 && (a != 0 || b != 0 || c != 0 || (F_70(arg0) & 1))) {
        for (i = 0; i < 5; i++) {
            a = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0) + 0x10);
            b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0));
            c = func_800ECAB8(arg0, (t = RX(arg0), t - 1), F_E(arg0) - 0x10);
            if (a != 0 || b != 0 || c != 0) {
                F_A(arg0)--;
            }
        }
        F_20(arg0) = 0;
        F_28(arg0) = 0;
        F_6(arg0) = 2;
        CHECK(arg0);
        return;
    }
    a = func_800ECAB8(arg0, LX(arg0), F_E(arg0) + 0x10);
    b = func_800ECAB8(arg0, LX(arg0), F_E(arg0));
    c = func_800ECAB8(arg0, LX(arg0), F_E(arg0) - 0x10);
    if (F_20(arg0) < 0 && (a != 0 || b != 0 || c != 0 || (F_70(arg0) & 2))) {
        for (i = 0; i < 5; i++) {
            a = func_800ECAB8(arg0, LX(arg0), F_E(arg0) + 0x10);
            b = func_800ECAB8(arg0, LX(arg0), F_E(arg0));
            c = func_800ECAB8(arg0, LX(arg0), F_E(arg0) - 0x10);
            if (a != 0 || b != 0 || c != 0) {
                F_A(arg0)++;
            }
        }
        F_20(arg0) = 0;
        F_28(arg0) = 0;
        F_6(arg0) = 2;
        CHECK(arg0);
        return;
    }
    if (F_20(arg0) > 0x42000) {
        F_20(arg0) = 0x42000;
    } else if (F_20(arg0) < -0x42000) {
        F_20(arg0) = -0x42000;
    }
    if (F_2(arg0) == 0 && ABS(F_7C(arg0) - F_A(arg0)) >= 0x30) {
        if (F_20(arg0) > 0) {
            F_A(arg0) = F_7C(arg0) + 0x30;
        } else {
            F_A(arg0) = F_7C(arg0) - 0x30;
        }
        F_8(arg0) = 0;
        F_20(arg0) = 0;
        F_28(arg0) = 0;
        F_24(arg0) = 0;
        F_2C(arg0) = 0;
        F_6(arg0) = 2;
    }
    CHECK(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK collide_solid_object();
s32 func_800ECAB8(struct X4_PlayerObj*, s16, s16);
extern M2C_UNK g_Player;

#define F_3(p) M2C_FIELD(p, s8*, 0x3)
#define F_6(p) M2C_FIELD(p, u8*, 0x6)
#define F_8(p) M2C_FIELD(p, s16*, 0x8)
#define F_A(p) M2C_FIELD(p, s16*, 0xA)
#define F_C(p) M2C_FIELD(p, s16*, 0xC)
#define F_E(p) M2C_FIELD(p, s16*, 0xE)
#define F_20(p) M2C_FIELD(p, s32*, 0x20)
#define F_24(p) M2C_FIELD(p, s32*, 0x24)
#define F_28(p) M2C_FIELD(p, s32*, 0x28)
#define F_2C(p) M2C_FIELD(p, s32*, 0x2C)
#define F_70(p) M2C_FIELD(p, u8*, 0x70)
#define F_80(p) M2C_FIELD(p, s8*, 0x80)
#define F_81(p) M2C_FIELD(p, s8*, 0x81)
#define F_82(p) M2C_FIELD(p, u8*, 0x82)
#define F_83(p) M2C_FIELD(p, u8*, 0x83)
#define F_85(p) M2C_FIELD(p, u8*, 0x85)

#define PL_E5(p) M2C_FIELD(p, u8*, 0xE5)

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define RX(p) (F_A(p) + F_80(p) + F_82(p))
#define LX(p) (F_A(p) + F_80(p) - F_82(p))
#define FY(p) (F_E(p) + F_81(p) + F_83(p))
#define CHECK(p)                                                               \
    {                                                                          \
        void* pl_ = &g_Player;                                                 \
        if (PL_E5(pl_) == 0 && ABS(F_A(pl_) - F_A(p)) < 0x30) {                \
            collide_solid_object(p);                                                  \
        }                                                                      \
    }

void func_800EDAB0(void* arg0) {
    s32 b;
    s32 c;
    s16 t;

    b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), FY(arg0));
    c = func_800ECAB8(arg0, LX(arg0), FY(arg0));
    if ((F_70(arg0) & 8) || b != 0 || c != 0) {
        F_C(arg0) = 0;
        F_E(arg0) = (F_E(arg0) & 0xFFF0) | 8;
        play_sound(2, 0x52, 0);
        if (F_85(arg0) >= 0x11 && F_3(arg0) != 0) {
            func_8002943C(0x10, 2, 1);
        }
        F_8(arg0) = 0;
        F_20(arg0) = 0;
        F_28(arg0) = 0;
        F_24(arg0) = 0;
        F_2C(arg0) = 0;
        F_6(arg0) = 2;
    }
    if (F_24(arg0) <= -0x20000) {
        F_24(arg0) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(arg0);
    F_85(arg0)++;
    CHECK(arg0);
    ((void (*)(void*))func_8002F288)(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK collide_solid_object();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800ECAB8(struct X4_PlayerObj*, s16, s16);
extern M2C_UNK g_Player;
extern M2C_UNK D_800F3A0C;
extern M2C_UNK D_800F3A10;
extern M2C_UNK D_800F3A1C;

#define F_2(p) M2C_FIELD(p, u8*, 0x2)
#define F_4(p) M2C_FIELD(p, u8*, 0x4)
#define F_6(p) M2C_FIELD(p, u8*, 0x6)
#define F_A(p) M2C_FIELD(p, s16*, 0xA)
#define F_E(p) M2C_FIELD(p, s16*, 0xE)
#define F_20(p) M2C_FIELD(p, s32*, 0x20)
#define F_24(p) M2C_FIELD(p, s32*, 0x24)
#define F_28(p) M2C_FIELD(p, s32*, 0x28)
#define F_2C(p) M2C_FIELD(p, s32*, 0x2C)
#define F_50(p) M2C_FIELD(p, void**, 0x50)
#define F_70(p) M2C_FIELD(p, u8*, 0x70)
#define F_7C(p) M2C_FIELD(p, s16*, 0x7C)
#define F_80(p) M2C_FIELD(p, s8*, 0x80)
#define F_81(p) M2C_FIELD(p, s8*, 0x81)
#define F_82(p) M2C_FIELD(p, u8*, 0x82)
#define F_83(p) M2C_FIELD(p, u8*, 0x83)
#define F_84(p) M2C_FIELD(p, u8*, 0x84)
#define F_85(p) M2C_FIELD(p, u8*, 0x85)

#define PL_2(p) M2C_FIELD(p, s8*, 0x2)
#define PL_4(p) M2C_FIELD(p, s32*, 0x4)
#define PL_5(p) M2C_FIELD(p, s8*, 0x5)
#define PL_15(p) M2C_FIELD(p, u8*, 0x15)
#define PL_71(p) M2C_FIELD(p, u8*, 0x71)
#define PL_E5(p) M2C_FIELD(p, u8*, 0xE5)

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define RX(p) (F_A(p) + F_80(p) + F_82(p))
#define LX(p) (F_A(p) + F_80(p) - F_82(p))
#define FY(p) (F_E(p) + F_81(p) + F_83(p))
#define CHECK(p)                                                               \
    {                                                                          \
        void* pl_ = &g_Player;                                                 \
        if (PL_E5(pl_) == 0 && ABS(F_A(pl_) - F_A(p)) < 0x30) {                \
            collide_solid_object(p);                                                  \
        }                                                                      \
    }

void func_800EDC9C(void* arg0) {
    void* pl;
    s32 b;
    s32 c;
    s32 f;
    s8 k;
    s16 t;

    pl = &g_Player;
    ((void (*)(void*))func_8002F288)(arg0);
    b = func_800ECAB8(arg0, (t = RX(arg0), t - 1), FY(arg0));
    c = func_800ECAB8(arg0, LX(arg0), FY(arg0));
    if (!(F_70(arg0) & 8) && b == 0 && c == 0) {
        F_2C(arg0) = 0xD00;
        F_6(arg0) = 1;
        F_85(arg0) = 0;
        CHECK(arg0);
        return;
    }
    F_84(arg0) = PL_71(pl);
    CHECK(arg0);
    F_84(arg0) ^= PL_71(pl);
    f = 0;
    if (PL_2(pl) != 0) {
        f = PL_5(pl) == 0x39;
    } else if ((PL_4(pl) & 0xFFFF00) == 0x22C00) {
        f = 1;
    }
    if (f == 0) {
        return;
    }
    if (F_2(arg0) < 2) {
        if ((F_84(arg0) & 2) && PL_15(pl) == 0) {
            F_20(arg0) = -0x40000;
            if ((s8)F_2(arg0) == 1) {
                F_28(arg0) = 0x2400;
            } else {
                F_28(arg0) = -0x2400;
            }
        } else if ((F_84(arg0) & 1) && PL_15(pl) == 0x40) {
            F_20(arg0) = 0x40000;
            if ((s8)F_2(arg0) == 1) {
                F_28(arg0) = -0x2400;
            } else {
                F_28(arg0) = 0x2400;
            }
        } else {
            return;
        }
        F_24(arg0) = 0;
        F_2C(arg0) = 0;
        F_6(arg0) = 0;
        F_7C(arg0) = F_A(arg0);
    }
    f = 0;
    if ((F_84(arg0) & 2) && PL_15(pl) == 0) {
        f = 1;
    } else if ((F_84(arg0) & 1) && PL_15(pl) == 0x40) {
        f = 1;
    }
    if (f != 0 && PL_2(pl) == 0) {
        k = F_2(arg0);
        if (k == 3) {
            F_85(arg0) = 0x1E;
            F_50(arg0) = &D_800F3A1C;
            func_800477E4(3, &D_800F3A10, arg0);
            F_4(arg0) = 2;
        } else if (k == 2) {
            func_800477E4(3, &D_800F3A0C, arg0);
            func_80049EBC(arg0, 1, 0x1F, 0xF);
            F_4(arg0) = k;
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EE050);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*);                            /* extern */
M2C_UNK func_80030ECC();                                 /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);         /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_800F3A10;

void func_800EE0B0(void* arg0) {
    u8 temp_v0;

    M2C_FIELD(arg0, s8*, 3) = 0;
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        func_80030ECC();
        if (!(M2C_FIELD(arg0, u8*, 0x85) & 3)) {
            func_80049EBC(arg0, 1, 0x20, 0x20);
        }
        if (!(M2C_FIELD(arg0, u8*, 0x85) & 7)) {
            func_800477E4(3, &D_800F3A10, arg0);
        }
        temp_v0 = M2C_FIELD(arg0, u8*, 0x85);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8*, 0x85) = (u8)(temp_v0 - 1);
            return;
        }
        goto block_7;
    }
block_7:
    func_8002CA14(arg0);
}

#include "common.h"

void func_800EE150(void) {
}

#include "../shared/rock_06/func_800EE158.c"

// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", func_800EE1D4);
// clang-format on

#include "../shared/rock_06/func_800EE344.c"

#include "../shared/rock_06/func_800EE6C0.c"

#include "../shared/rock_06/func_800EE828.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002DCF4(void*, void*);

extern M2C_UNK g_Player;
#define PLAYER (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_RideArmorObj D_800CD340;
extern s32 D_800F3A44;
extern s32 D_800F3A48;

void func_800EE924(struct X4_BaseObj* self) {
    struct X4_PlayerObj* pl;
    struct X4_EngineObj* en;
    // !FAKE: depin: dropping it breaks the match (101/106)
    register void* saved asm("$19");
    s8 v;

    if (M2C_FIELD(self, s8*, 0x6) == 0) {
        M2C_FIELD(self, s8*, 0x6) = 1;
        M2C_FIELD(self, void**, 0x68) = &D_800F3A44;
        M2C_FIELD(self, u8*, 0x8C) = 0;
        set_animation(self, 0x11);
        return;
    }
    if (!(M2C_FIELD(self, u8*, 0xA8) & 8)) {
        M2C_FIELD(self, u8*, 0x5) = 0xC;
        M2C_FIELD(self, u8*, 0x6) = 0;
        return;
    }
    pl = &PLAYER;
    if (M2C_FIELD(pl, s8*, 0xD0) != 0) {
        return;
    }
    en = &g_playthrough_state;
    if (M2C_FIELD(en, s8*, 0xF) == 0 &&
        (M2C_FIELD(pl, s8*, 0x2) == 0 || pl->attacking == 0) &&
        pl->spike_immune == 0 && pl->nova_strike_active == 0 &&
        !(M2C_FIELD(self, u16*, 0x96) & 0x8200)) {
        saved = M2C_FIELD(self, void**, 0x68);
        M2C_FIELD(self, void**, 0x68) = &D_800F3A48;
        if (func_8002DCF4(pl, self) != 0 && M2C_FIELD(en, s8*, 0xF) == 0 &&
            pl->hp > 0 && pl->hurt_phase == 0 &&
            pl->touching_spikes == 0) {
            M2C_FIELD(self, u8*, 0x5) = 0xA;
            M2C_FIELD(self, u8*, 0x6) = 0;
            set_animation(self, 0x12);
            {
                struct X4_BaseObj* r;
                do {
                    r = (struct X4_BaseObj*)&D_800CD340;
                    M2C_FIELD(self, u8*, 0x97) |= 0x40;
                } while (0);
                v = 2;
                if (self == r) {
                    v = 1;
                }
            }
            M2C_FIELD(pl, s8*, 0xD5) = v;
        }
        M2C_FIELD(self, void**, 0x68) = saved;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_80017A04();                     /* extern */
struct X4_VisualObj* func_8002C398(void);    /* extern */
extern M2C_UNK g_Player;
extern s32 D_800F3A44;
extern s32 D_800F3A4C;

void func_800EEACC(void* arg0) {
    void* o;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, u16*, 0xA6) = 0;
        M2C_FIELD(arg0, s32**, 0x68) = &D_800F3A44;
        ((void (*)(void*, s32))set_animation)(arg0, 0x12);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            u8* p = (u8*)&g_Player;
            M2C_FIELD(p, u8*, 0xD8) = 0x39;
            M2C_FIELD(p, u8*, 6) = 0;
        }
        play_sound(2, 0x24, 0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x8C) == 0) {
            M2C_FIELD(arg0, u8*, 0x61) = 0;
        }
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, u16*, 0xA6) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800F3A4C;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x45) & 1) {
        o = func_8002C398();
        if (o != 0) {
            M2C_FIELD(o, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(o, u8*, 1) = 0xC;
            M2C_FIELD(o, u8*, 2) = 7;
            M2C_FIELD(o, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
            M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(o, void**, 0x50) = arg0;
        }
        play_sound(2, 0x26, 0);
        M2C_FIELD(arg0, u8*, 0x45) = 0;
        return;
    }
    func_80017A04(arg0);
}

#include "../shared/rock_06/func_800EEC50.c"

#include "../shared/rock_06/func_800EEE00.c"

#include "../shared/rock_06/func_800EEFF0.c"

#include "../shared/rock_06/func_800EF288.c"

#include "../shared/rock_06/func_800EF524.c"

#include "../shared/rock_06/func_800EF758.c"

#include "../shared/rock_06/func_800EF950.c"

#include "../shared/rock_06/func_800EFC4C.c"

#include "../shared/rock_06/func_800EFDB0.c"

#include "../shared/rock_06/func_800EFFCC.c"

#include "../shared/rock_06/func_800F011C.c"

#include "../shared/rock_06/func_800F036C.c"

#include "../shared/rock_06/func_800F04E8.c"

#include "../shared/rock_06/func_800F071C.c"

#include "../shared/rock_06/func_800F097C.c"

#include "../shared/rock_06/func_800F0B5C.c"

#include "../shared/rock_06/func_800F0EA4.c"

#include "../shared/rock_06/func_800F10C0.c"

#include "../shared/rock_06/func_800F1494.c"

#include "../shared/rock_06/func_800F1670.c"

#include "../shared/rock_06/func_800F1C80.c"

#include "../shared/rock_06/func_800F1DA8.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK silence_sound(M2C_UNK, M2C_UNK);
struct X4_VisualObj* func_8002C398(void);
M2C_UNK clear_object_slot();
s32 func_8002CAB4(void*);
M2C_UNK func_8002CD6C(void*);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_8003CCBC();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
void func_800EE344(void*);
void func_800EE6C0(void* self);
void func_800EE828(void* self);
void func_800F1C80(void* arg0);
s32 func_800F1DA8(void*, s32, s32);

extern M2C_UNK g_Player;
#define F1EC4_PL (*(struct X4_PlayerObj*)&g_Player)
extern u16 D_80097202;
extern s8 D_800CCEDF;
extern s8 D_800CCEF6;
extern M2C_UNK D_800F3A3C;
extern void (*D_800F3A74[])(void*);
extern void (*D_800F3AAC[])(void*);

#define U8(o) M2C_FIELD(self, u8*, o)
#define S8(o) M2C_FIELD(self, s8*, o)
#define U16(o) M2C_FIELD(self, u16*, o)
#define S16(o) M2C_FIELD(self, s16*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PL_D5 M2C_FIELD(pl, s8*, 0xD5)

void func_800F1EC4(void* self) {
    struct X4_VisualObj* v;
    u8* p;

    S8(0x3) = 0;
    if (func_8002CAB4(self) != 0) {
        return;
    }
    {
        struct X4_PlayerObj* pl = &F1EC4_PL;
        if (PL_D5 != 0 && (U8(0xA8) & 1) &&
            (S16(0xA) - (s16)D_80097202) < 0x20) {
            pl->hp = -0x80;
            S8(0x5C) = -0x80;
            S8(0x3) = 0;
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            clear_object_slot(self);
            D_800CCEF6 = 0;
            U8(0xA8) = 0;
            return;
        }
    }
    if (S8(0x5C) < 0) {
        if (S8(0x5C) == -0x80) {
            if (!(U8(0x97) & 0x80)) {
                U8(0x97) |= 0x80;
                U8(0x92) = 0x1E;
                U8(0x91) = 0x1E;
                U8(0x8C) = 0;
            }
            S8(0x5C) = 0x20;
        }
        S16(0xA4) = 0x400;
        U8(0x8C) = 0x79;
        v = func_8002C398();
        if (v != NULL) {
            v->active = S8(0x0);
            v->id = 0xC;
            v->unk2 = 8;
            v->x_pos.val = S32(0x8);
            v->y_pos.val = S32(0xC);
            v->animation_table = M2C_FIELD(self, u32***, 0x30);
            v->unk40 = U16(0x40);
            v->unk3C = M2C_FIELD(self, void**, 0x3C);
            v->unk42 = U16(0x42) & 0x7FFF;
            v->unk16 = U8(0x16);
            v->unk15 = U8(0x15);
            v->unk50 = self;
        }
        U8(0x93) = 1;
        U8(0x85) = 1;
        U8(0x97) |= 2;
    }
    if (U8(0x8C) != 0) {
        if (--U8(0x8C) == 0 && (U8(0x97) & 1)) {
            F1EC4_PL.on_screen = 1;
        }
    }
    if ((U8(0x97) & 0x41) == 0x41 || (D_800CCEDF != 0 && (U8(0x97) & 0x40))) {
        U8(0x97) ^= 1;
        S8(0x5) = 0xB;
        S8(0x6) = 0;
    }
    func_800EE6C0(self);
    func_800EE828(self);
    func_800EE344(self);
    if (U8(0x8D) == 0) {
        if (S8(0x2) == 0) {
            D_800F3A74[S8(0x5)](self);
        } else {
            if (U8(0x7E) != 0) {
                U8(0x7E)--;
            }
            D_800F3AAC[S8(0x5)](self);
        }
        func_800F1C80(self);
        func_8002F288(self);
        if (U8(0x97) & 0x40) {
            F1EC4_PL.x_pos.val = S32(0x8);
            F1EC4_PL.y_pos.val = S32(0xC);
            F1EC4_PL.unk15 = U8(0x15);
            if ((U8(0x97) & 0x40) && U8(0x8C) != 0) {
                if (!(U8(0x8C) & 3)) {
                    U16(0x42) |= 0x8000;
                } else {
                    U16(0x42) &= 0x7FFF;
                }
            }
        }
        p = &U8(0x88);
        if (U8(0x97) & 0x80) {
            U16(0x42) &= 0x7FFF;
            if ((p[0xA] = U8(0x92) - 1) == 0) {
                U8(0x92) = U8(0x91);
                U16(0x42) |= 0x8000;
                if ((p[0x9] = U8(0x91) - 1) == 0) {
                    U8(0x8D) = 1;
                    U16(0x42) &= 0x7FFF;
                }
            }
        }
        func_8002CD6C(self);
    }
    switch (U8(0x8D)) {
    case 1: {
        struct X4_PlayerObj* pl = &F1EC4_PL;
        U8(0x8D) = 2;
        U8(0x8C) = 0xFF;
        PL_D5 = 0;
        U8(0x97) ^= 0x40;
        func_8003CCBC(pl);
        U8(0x90) = 0x1E;
        U8(0x97) |= 4;
        func_800477E4(7, &D_800F3A3C, self);
        break;
    }
    case 2:
        if (--S8(0x90) == 0) {
            S8(0x4) = 2;
            S8(0x3) = 0;
            func_80049E50(self);
            silence_sound(2, 8);
        } else {
            func_80049EBC(self, 0, 0x1F, 0x1F);
        }
        break;
    default:
        if (U8(0x8C) == 0) {
            U8(0x85) = 0;
            U16(0x42) &= 0x7FFF;
        }
        break;
    }
    ((s32(*)())func_800F1DA8)(self);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CD6C(void*);

extern M2C_UNK g_Player;
extern s8 D_800CCEF6;
extern void (*D_800F3A50[])(void*);

void func_800F2414(void* self) {
    {
        void* pl = &g_Player;
        if (M2C_FIELD(pl, s8*, 0xD0) == 0) {
            M2C_FIELD(self, u16*, 0x88) = M2C_FIELD(pl, u16*, 0x7C);
            M2C_FIELD(self, u16*, 0x8A) = M2C_FIELD(pl, u16*, 0x80);
        } else {
            M2C_FIELD(self, u16*, 0x88) = 0;
            M2C_FIELD(self, u16*, 0x8A) = 0;
        }
    }
    {
        void* pl = &g_Player;
        if (M2C_FIELD(pl, s8*, 0xCC) != 0) {
            func_8002CD6C(self);
            return;
        }
    }
    M2C_FIELD(self, s32*, 0x18) = M2C_FIELD(self, s32*, 0x8);
    M2C_FIELD(self, s32*, 0x1C) = M2C_FIELD(self, s32*, 0xC);
    M2C_FIELD(self, u8*, 0xA8) =
        M2C_FIELD(self, u8*, 0x70) | M2C_FIELD(self, u8*, 0x71);
    M2C_FIELD(self, u8*, 0x71) = 0;
    D_800F3A50[M2C_FIELD(self, s8*, 0x4)](self);
    M2C_FIELD(self, u8*, 0x5C) &= 0x7F;
    if ((M2C_FIELD(self, u8*, 0xA8) & 0xC) == 0xC) {
        D_800CCEF6 = 1;
    } else {
        D_800CCEF6 = 0;
    }
}

#include "../shared/rock_06/func_800F250C.c"

#include "../shared/rock_06/func_800F254C.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);    /* extern */
struct X4_VisualObj* func_8002C398(void); /* extern */
void func_800F04E8(void* arg0);
void func_800F071C(void* arg0);
extern M2C_UNK g_Player;

void func_800F2588(void* arg0) {
    void* o;

    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        ((void (*)(void*, s32))set_animation)(arg0, 0xC);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            u8* p = (u8*)&g_Player;
            M2C_FIELD(p, u8*, 0xD8) = 0x34;
            M2C_FIELD(p, u8*, 6) = 0;
        }
        func_800F04E8(arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 6) = 4;
    o = func_8002C398();
    if (o != 0) {
        M2C_FIELD(o, u8*, 0) = 0x41;
        M2C_FIELD(o, u8*, 1) = 0x16;
        M2C_FIELD(o, u8*, 2) = 0x10;
        M2C_FIELD(o, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(o, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
        M2C_FIELD(o, void**, 0x50) = arg0;
        M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
    }
    ((void (*)(void*, s32))set_animation)(arg0, 0xE);
    if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
        u8* p = (u8*)&g_Player;
        M2C_FIELD(p, u8*, 0xD8) = 0x40;
        M2C_FIELD(p, u8*, 6) = 0;
    }
    M2C_FIELD(arg0, u8*, 0x7E) = 8;
    func_800F071C(arg0);
}

#include "../shared/rock_06/func_800F26C4.c"

#include "../shared/rock_06/func_800F26E4.c"

// clang-format off
INCLUDE_ASM("asm/rock_06/nonmatchings/E9860", D_800F2730);
// clang-format on
