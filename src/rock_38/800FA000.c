// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FA000);
// clang-format on

#define func_800F0434 func_800FA070
#include "../shared/rock_09/func_800F0434.c"
#undef func_800F0434

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD9C (*(s32**)0x1F80009C)

void set_boss_level();
void* func_8002C458();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800FA004[];
extern s32 D_800FE830;
extern s32 D_800FE838;
extern s32 D_800FEBAC;
extern s16 D_800FEEB0;
extern s16 D_800FEEB2;
extern s16 D_800FEEB4;
extern s16 D_800FEEB6;
extern u16 D_800FEEB8;
extern u16 D_800FEEBA;
extern s16 D_800FEEBC;
extern s16 D_800FEEBE;
extern s16 D_800FEEC0;
extern s32 D_800FEEC4;
extern s32 D_800FEEC8;
extern s16 D_800FEED0;
extern void* D_800FEED4;
extern s32 D_800FEED8;

void func_800FA2F0(struct X4_MainObj* self) {
    u8 tbl[4];
    u8* child;
    u16 yv;
    u16 xv;
    u8 bg;

    __builtin_memcpy(tbl, D_800FA004, 4);
    D_800FEEB0 = background_objects[0].unk26 + 0x10;
    D_800FEEB2 = background_objects[0].unk26 + 0x190;
    D_800FEEB4 = background_objects[0].unk26 + 0xD0;
    D_800FEEB6 = background_objects[0].unk2A + 0xF0;
    D_800FEEB8 = background_objects[0].unk26 + 0xF0;
    D_800FEEBA = background_objects[0].unk2A - 0x30;
    D_800FEEBC = background_objects[0].unk2A + 0x10;
    D_800FEEBE = background_objects[0].unk26 + 0x150;
    D_800FEEC0 = background_objects[0].unk26 + 0x50;
    if (g_playthrough_state.stage == 0xC) {
        self->sprite_frames = (u8*)SPAD9C + SPAD9C[0];
        self->unk42 = 0x7948;
    }
    self->animation_table = (void*)&D_800FEBAC;
    bg = D_800970B4;
    self->terrain_box = 0;
    self->unk16 = 5;
    self->unk15 = 0;
    self->air_state = 0;
    self->on_screen = 0;
    self->attack_box = &D_800FE830;
    self->hurt_box = &D_800FE838;
    self->unk62 = 0;
    self->invincibility_timer = 0;
    self->bg_offset = bg;
    self->collision_data = &D_800755FC;
    xv = D_800FEEB8;
    yv = D_800FEEBA;
    self->x_speed = 0;
    self->contact_damage = 6;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 0;
    self->x_pos.i.hi = xv;
    self->y_pos.i.hi = yv;
    g_playthrough_state.unk25 = 0;
    g_playthrough_state.boss_ptr = self;
    M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x38;
    set_boss_level();
    {
        // !FAKE: depin: dropping it breaks the match (149/151)
        register s32 e asm("$2") = M2C_FIELD(&g_playthrough_state, u8*, 0x8C);
        M2C_FIELD(&g_playthrough_state, u8*, 0x8C) =
            e + tbl[M2C_FIELD(&g_playthrough_state, u8*, 0x8F)];
    }
    M2C_FIELD(self, u8*, 0x87) = 0;
    M2C_FIELD(self, u8*, 0x86) = 0;
    M2C_FIELD(self, u8*, 0x84) = 0;
    D_800FEED8 = 0;
    func_8003D308(0x14, 0x40);
    D_800FEEC4 = 0;
    D_800FEEC8 = 0;
    D_800FEED4 = self;
    child = func_8002C458();
    if (child != 0) {
        child[0] = self->active;
        child[1] = 0x17;
        child[2] = 0;
        *(void**)(child + 0x7C) = self;
    }
    child = func_8002C458();
    if (child != 0) {
        child[0] = self->active;
        child[1] = 0x17;
        child[2] = 1;
        *(void**)(child + 0x7C) = self;
    }
    D_800FEED0 = 0;
    self->action = 2;
    self->state++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);

extern M2C_UNK D_8007433C;
extern s32 D_800FE830;
extern s32 D_800FE834;
extern s32 D_800FE838;
extern s32 D_800FE83C;
extern s32 D_800FE840;
extern void (*D_800FECC0[])(struct X4_MainObj*);
extern s32 D_800FEEC4;
extern s32 D_800FEEC8;
extern u16 D_800FEECC;
extern s16 D_800FEED0;
extern s32 D_800FEED8;

#define TIMER M2C_FIELD(self, u8*, 0x84)

void func_800FA54C(struct X4_MainObj* self) {
    s32 r;
    u8 t;

    if (self->action == 9) {
        self->hurt_box = &D_800FE840;
        self->collision_data = &D_8007433C;
        r = check_enemy_hits(self);
    } else if (D_800FEED0 == 3) {
        self->hurt_box = &D_800FE840;
        if (TIMER == 0) {
            self->collision_data = &D_800755FC;
        }
        r = check_enemy_hits(self);
    } else if ((t = self->unk17) == 0x1E || t == 0x1C || t == 0x1D ||
               t == 0xD || t == 0x10) {
        self->hurt_box = &D_800FE840;
        self->collision_data = &D_8007433C;
        r = check_enemy_hits(self);
    } else {
        self->hurt_box = &D_800FE838;
        self->collision_data = &D_8007433C;
        r = check_enemy_hits(self);
        if (r == 0) {
            if (TIMER != 0) {
                self->collision_data = &D_8007433C;
            } else {
                self->collision_data = &D_800755FC;
            }
            self->hurt_box = &D_800FE83C;
            r = check_enemy_hits(self);
        } else {
            TIMER = 1;
        }
    }
    if (r < 0) {
        play_sound(2, 0x14, self);
        play_sound(2, 0x20, self);
        self->state = 2;
        self->x_speed = 0;
        self->y_speed = 0;
        self->x_accel = 0;
        self->gravity = 0;
        self->action = 0;
        self->action_phase = 0;
        self->unk42 &= 0x7FFF;
        {
            // !FAKE: depin: dropping it breaks the match (216/223)
            register s32 one asm("$3");
            D_800FEEC4 = one = 1;
            D_8009711A = one;
        }
        func_8002CCB0(self, 0x80, 0x80);
        return;
    }
    if (self->action != 9) {
        if (self->unk17 == 0x1E) {
            self->attack_box = &D_800FE834;
        } else {
            self->attack_box = &D_800FE830;
        }
        func_80030ECC(self);
    }
    if (r > 0 && r != 0x7F) {
        if ((u32)(r - 0x19) < 2) {
            TIMER = 2;
        } else {
            TIMER = 0x1E;
        }
        self->collision_data = &D_8007433C;
    }
    if (r == 3 || r == 0xC || r == 0x22) {
        play_sound(2, 0x14, self);
        play_sound(2, 0x21, self);
        play_sound(2, 0x78, self);
        D_800FEEC8 = 1;
        self->action = 9;
        self->action_phase = 0;
    }
    t = TIMER;
    if (t != 0) {
        TIMER = t + 0xFF;
        if (t & 2) {
            self->unk42 |= 0x8000;
        } else {
            self->unk42 &= 0x7FFF;
        }
        if (TIMER == 0) {
            self->collision_data = &D_800755FC;
            self->unk42 &= 0x7FFF;
        }
    }
    D_800FEECC = self->unk42 & 0x8000;
    D_800FECC0[self->action](self);
    if (self->action != 2) {
        D_800FEED8++;
    }
    if (D_800FEECC != 0) {
        self->unk42 |= D_800FEECC;
    } else {
        self->unk42 &= 0x7FFF;
    }
}
#undef TIMER

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FA8C8);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FA9F0);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FAB14);
// clang-format on

#define func_800F0F9C func_800FABD8
#define g_Player g_Player
#include "../shared/rock_09/func_800F0F9C.c"
#undef func_800F0F9C
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FACA0);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FAD80);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FAEC0);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FAFD8);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FB110);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FB3E8);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FB53C);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FBDB8);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FBF84);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FC1B8);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FC3D8);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FC5A4);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FC758);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FC8B8);
// clang-format on

#define func_800EB5A0 func_800FCA5C
#define D_800F6A84 D_800FECB4
#include "../shared/rock_04/func_800EB5A0.c"
#undef func_800EB5A0
#undef D_800F6A84

#include "common.h"

void func_800FCABC(void) {
}

#define func_8003744C func_800FCAC4
#define D_80073C1C D_800FECE8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/globals.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();               /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800FCB00(void* arg0) {
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

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FCB98);
// clang-format on

#define func_800F3014 func_800FCC50
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_09/func_800F3014.c"
#undef func_800F3014
#undef g_playthrough_state

#define func_800F0434 func_800FA070
#define func_800F30F8 func_800FCD34
#include "../shared/rock_09/func_800F30F8.c"
#undef func_800F30F8
#undef func_800F0434

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FCD98);
// clang-format on

#define func_800F3220 func_800FCE5C
#include "../shared/rock_09/func_800F3220.c"
#undef func_800F3220

#define func_800F32B0 func_800FCEEC
#include "../shared/rock_09/func_800F32B0.c"
#undef func_800F32B0

#define func_800F3380 func_800FCFBC
#define D_800F69F8 D_800FED08
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

#include "common.h"

void func_800FD020(void) {
}

#define func_800F3380 func_800FD028
#define D_800F69F8 D_800FED0C
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

#define func_800F3450 func_800FD08C
#include "../shared/rock_09/func_800F3450.c"
#undef func_800F3450

// clang-format off
#define func_800F3498 func_800FD0D4
#define D_800E98C4 D_800FA008
#define func_800F0434 func_800FA070
#include "../shared/rock_09/func_800F3498.c"
#undef func_800F3498
#undef D_800E98C4
#undef func_800F0434
// clang-format on

#define func_800F3578 func_800FD1B4
#define D_800F6924 D_800FEC34
#include "../shared/rock_09/func_800F3578.c"
#undef func_800F3578
#undef D_800F6924

#define func_800F3380 func_800FD218
#define D_800F69F8 D_800FED1C
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FD27C);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FD2E8);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FD358);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800FD408(void* arg0) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
        if (var_v0 != 0) {
            play_sound(2, 0x3F, arg0);
            start_pad_vibration(3);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
        }
    } else if (temp_v0 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
        if (var_v0 != 0) {
            play_sound(2, 0x3F, arg0);
            start_pad_vibration(3);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
        }
    }
    if (M2C_FIELD(arg0, s32*, 0x20) == 0) {
        func_80029478(0x5A, 2, 3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 6) = 5;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) + 1);
    }
}

#define func_800F3870 func_800FD4AC
#include "../shared/rock_09/func_800F3870.c"
#undef func_800F3870

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800FD4D8(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 4) {
        play_sound(2, 0x3F, arg0);
        start_pad_vibration(3);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        func_80029478(0x5A, 2, 3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 6) = 7;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800FD54C(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        play_sound(2, 0x3F, arg0);
        start_pad_vibration(3);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        func_80029478(0x5A, 2, 3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 6) = 5;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FD5C8);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FD650);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FD694);
// clang-format on

#define func_800F3AE8 func_800FD724
#include "../shared/rock_09/func_800F3AE8.c"
#undef func_800F3AE8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800FD78C(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        play_sound(2, 0x3F, arg0);
        start_pad_vibration(3);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        func_80029478(0x5A, 2, 3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0xE;
    }
}

#define func_800F3BC0 func_800FD7FC
#define g_Player g_Player
#include "../shared/rock_09/func_800F3BC0.c"
#undef func_800F3BC0
#undef g_Player

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);        /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800FD880(void* arg0) {
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
    if ((temp_v1 & 2) || (temp_v1 & 1)) {
        play_sound(2, 0x3F, arg0);
        start_pad_vibration(3);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0xC;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) + 1);
    }
}

#define func_800F3380 func_800FD8EC
#define D_800F69F8 D_800FED5C
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FD950);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FD9BC);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FDA2C);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800FE82C;

void func_800FDAC8(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7E) >= 4) {
        M2C_FIELD(arg0, s8*, 6) = 6;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(&D_800FE82C, s16*, 0x688)) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, s8*, 6) = 4;
}

#define func_800F3EE0 func_800FDB1C
#define D_800F698C D_800FEC9C
#include "../shared/rock_09/func_800F3EE0.c"
#undef func_800F3EE0
#undef D_800F698C

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FDB98);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FDC20);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FDC64);
// clang-format on

#define func_800F3380 func_800FDCF4
#define D_800F69F8 D_800FED80
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FDD58);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FDDC4);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FDE34);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800FE82C;

void func_800FDED0(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7E) >= 4) {
        M2C_FIELD(arg0, s8*, 6) = 6;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(&D_800FE82C, s16*, 0x688)) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, s8*, 6) = 4;
}

#define func_800F3EE0 func_800FDF24
#define D_800F698C D_800FEC9C
#include "../shared/rock_09/func_800F3EE0.c"
#undef func_800F3EE0
#undef D_800F698C

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FDFA0);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FE028);

INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FE06C);
// clang-format on

#define func_800F3380 func_800FE0FC
#define D_800F69F8 D_800FEDA4
#include "../shared/rock_09/func_800F3380.c"
#undef func_800F3380
#undef D_800F69F8

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
void func_800FA070(s8* self, u32 arg1);
extern M2C_UNK D_800FE82C;

void func_800FE160(void* arg0) {
    u8* p;

    p = (u8*)&D_800FE82C + 0x470;
    func_80027BA0(0, 0x22F0, 0x290, p);
    func_80027BA0(0, 0x2480, 0x290, p + 0x10);
    func_800FA070(arg0, 0x21);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x6)++;
    func_8002CCB0(arg0, 0x80, 0x80);
    apply_object_motion(arg0);
}

#define func_800F45C0 func_800FE1FC
#include "../shared/rock_09/func_800F45C0.c"
#undef func_800F45C0

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FE234(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F0434 func_800FA070
#define D_800F6BFC D_800FEEC8
#define func_800F462C func_800FE268
#include "../shared/rock_09/func_800F462C.c"
#undef func_800F462C
#undef func_800F0434
#undef D_800F6BFC

#define func_800F468C func_800FE2C8
#define D_800F6924 D_800FEC34
#include "../shared/rock_09/func_800F468C.c"
#undef func_800F468C
#undef D_800F6924

#define func_80041AB8 func_800FE32C
#define D_80075FD8 D_800FEDB8
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FE368);
// clang-format on

#define func_800F47A0 func_800FE3DC
#include "../shared/rock_09/func_800F47A0.c"
#undef func_800F47A0

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FE4DC);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FE5C4(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FE5E4(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FE604);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FE6AC(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FE6CC);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FE74C(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FE76C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", func_800FE78C);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FE80C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_38/nonmatchings/FA000", D_800FE82C);
// clang-format on
