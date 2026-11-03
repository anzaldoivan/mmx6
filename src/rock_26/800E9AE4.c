#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj g_Player;
extern s32 D_800EF6F0;
extern s32 D_800EF6F4;
extern s32 D_800EF6F8;
extern s32 D_800EF9D0;

void func_800E9AE4(void* self) {
    u8 t;
    s32 v;

    M2C_FIELD(self, void**, 0x30) = &D_800EF9D0;
    t = g_Player.bg_offset;
    M2C_FIELD(self, u8*, 0x16) = 5;
    M2C_FIELD(self, void**, 0x68) = &D_800EF6F0;
    M2C_FIELD(self, void**, 0x50) = &D_800EF6F4;
    M2C_FIELD(self, void**, 0x54) = &D_800EF6F8;
    M2C_FIELD(self, void**, 0x58) = &D_800743DC;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0x40000;
    M2C_FIELD(self, u8*, 0x5C) = 12;
    M2C_FIELD(self, u8*, 3) = 0;
    M2C_FIELD(self, u8*, 0x61) = 0;
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, u8*, 0x60) = 4;
    M2C_FIELD(self, u8*, 0x14) = t;
    switch (M2C_FIELD(self, s8*, 2)) {
    case 0:
        if (g_Player.character == 0) {
            M2C_FIELD(self, u8*, 5) = 6;
        } else {
            M2C_FIELD(self, u8*, 5) = 4;
        }
        break;
    case 1:
        if (g_Player.character == 0) {
            M2C_FIELD(self, u8*, 5) = 7;
        } else {
            M2C_FIELD(self, u8*, 5) = 5;
        }
        break;
    case 2:
        M2C_FIELD(self, u8*, 5) = 2;
        break;
    case 3:
        M2C_FIELD(self, u8*, 5) = 3;
        break;
    case 4:
        v = 2;
        M2C_FIELD(self, u8*, 5) = v;
        M2C_FIELD(self, u8*, 7) = 0;
        M2C_FIELD(self, s32*, 0x68) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x2C) = 0;
        break;
    case 5:
        v = 3;
        M2C_FIELD(self, u8*, 5) = v;
        M2C_FIELD(self, u8*, 7) = 0;
        M2C_FIELD(self, s32*, 0x68) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x2C) = 0;
        break;
    }
    M2C_FIELD(self, u8*, 6) = 0;
    M2C_FIELD(self, u8*, 4)++;
}

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800E9C38);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj g_Player;
extern s32 D_800EF6F0;

#define E9DB0_U8(s, o) M2C_FIELD(s, u8*, o)
#define E9DB0_S8(s, o) M2C_FIELD(s, s8*, o)
#define E9DB0_S16(s, o) M2C_FIELD(s, s16*, o)
#define E9DB0_ABS(v) ((v) < 0 ? -(v) : (v))

void func_800E9DB0(void* self) {
    void* parent;
    void* p;

    parent = M2C_FIELD(self, void**, 0x80);
    if (E9DB0_S8(self, 2) == 4 && E9DB0_S8(self, 7) == 0) {
        E9DB0_S16(self, 0xE) = E9DB0_S16(parent, 0xE) - 0x27;
        if (E9DB0_S16(self, 0xE) >= 0x521 && E9DB0_S8(parent, 6) == 6) {
            M2C_FIELD(self, void**, 0x68) = &D_800EF6F0;
        }
    }
    if (g_Player.x_pos.i.hi > E9DB0_S16(self, 0xA)) {
        E9DB0_U8(self, 0x15) = 0x40;
    } else {
        E9DB0_U8(self, 0x15) = 0;
    }
    E9DB0_S16(self, 0x7C)++;
    switch (E9DB0_S8(self, 6)) {
    case 1:
        if (E9DB0_ABS(g_Player.x_pos.i.hi - E9DB0_S16(self, 0xA)) <= 0x80) {
            // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
            goto spawn;
        }
        if ((s16)(E9DB0_S16(self, 0x7C) % 200) == 0) {
            ((void (*)(void*, s32))set_animation)(self, 1);
            E9DB0_S8(self, 6)++;
        }
        break;
    case 2:
        if (g_Player.x_pos.i.hi - E9DB0_S16(self, 0xA) >= 0) {
            if (g_Player.x_pos.i.hi - E9DB0_S16(self, 0xA) <= 0x80) {
                // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
                goto spawn;
            }
        } else if (E9DB0_S16(self, 0xA) - g_Player.x_pos.i.hi <= 0x80) {
        spawn:
            p = func_8002C458();
            if (p != NULL) {
                M2C_FIELD(p, u8*, 0) = E9DB0_U8(self, 0);
                M2C_FIELD(p, u8*, 1) = 5;
                M2C_FIELD(p, u8*, 2) = 0;
                M2C_FIELD(p, void**, 0x7C) = self;
            }
            ((void (*)(void*, s32))set_animation)(self, 2);
            E9DB0_S16(self, 0x7C) = 0;
            E9DB0_U8(self, 6) = 3;
            break;
        }
        if (E9DB0_S8(self, 0x46) == 0) {
            E9DB0_U8(self, 6) = 0;
        }
        break;
    case 3:
        if (E9DB0_S16(self, 0x7C) != 0x5A) {
            break;
        }
    case 0:
        ((void (*)(void*, s32))set_animation)(self, 0);
        E9DB0_S16(self, 0x7C) = 0;
        E9DB0_S8(self, 6)++;
        break;
    case 4:
        if (E9DB0_S16(self, 0x7C) == 0x28) {
            E9DB0_U8(self, 6) = 0;
        }
        break;
    }
}

#undef E9DB0_U8
#undef E9DB0_S8
#undef E9DB0_S16
#undef E9DB0_ABS

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800E9FFC);
// clang-format on

#define func_800EA2A8 func_800EA25C
#include "../shared/rock_04/func_800EA2A8.c"
#undef func_800EA2A8

#define func_800ED14C func_800EA5C0
#include "../shared/rock_22/func_800ED14C.c"
#undef func_800ED14C

#define func_800EA970 func_800EA924
#include "../shared/rock_04/func_800EA970.c"
#undef func_800EA970

#define func_800EAC6C func_800EAC20
#include "../shared/rock_04/func_800EAC6C.c"
#undef func_800EAC6C

#define func_800EAF68 func_800EAF1C
#define D_800F6AB4 D_800EFA84
#include "../shared/rock_04/func_800EAF68.c"
#undef func_800EAF68
#undef D_800F6AB4

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EB0C4);
// clang-format on

#define func_800EB29C func_800EB250
#include "../shared/rock_04/func_800EB29C.c"
#undef func_800EB29C

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EB37C);
// clang-format on

#define func_800EB5A0 func_800EB554
#define D_800F6A84 D_800EFA54
#include "../shared/rock_04/func_800EB5A0.c"
#undef func_800EB5A0
#undef D_800F6A84

#include "common.h"

void func_800EB5B4(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
M2C_UNK func_8002CA14();     /* extern */
M2C_UNK func_8002CA54();     /* extern */

void func_800EB5BC(void* arg0) {
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 4) < 2U) {
        clear_object_slot();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 4) == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EB624);
// clang-format on

#define func_800EB750 func_800EB704
#include "../shared/rock_04/func_800EB750.c"
#undef func_800EB750

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB7D4(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB7F4(void) {
    clear_object_slot();
}

#define func_800EB860 func_800EB814
#include "../shared/rock_04/func_800EB860.c"
#undef func_800EB860

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB900(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EB920);

INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EBD84);
// clang-format on

#define func_800F0CF4 func_800EC0E4
#define g_Player g_Player
#include "../shared/rock_07/func_800F0CF4.c"
#undef func_800F0CF4
#undef g_Player

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC498(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x1C) = 0;
    M2C_FIELD(arg0, s8*, 0x1E) = 0;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EC4B8);
// clang-format on

#define func_800EE038 func_800EC5B4
#define g_Player g_Player
#include "../shared/rock_04/func_800EE038.c"
#undef func_800EE038
#undef g_Player

#define D_800F6C34 D_800EFACC
#define func_800EE208 func_800EC784
#include "../shared/rock_04/func_800EE208.c"
#undef func_800EE208
#undef D_800F6C34

#define func_800EE258 func_800EC7D4
#include "../shared/rock_04/func_800EE258.c"
#undef func_800EE258

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern s32 D_80075CDC;
extern s32 D_800EFB54;
extern s32 D_800EFAE0[];
extern s32 D_800EFAE8[];
extern s32 D_800EFAF0[];
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

void func_800EC8B0(void* arg0) {
    s16 v;

    FLD(arg0, u8, 0x5C) = 8;
    FLD(arg0, u8, 0x60) = 8;
    FLD(arg0, u8, 0x61) = 0;
    FLD(arg0, s32*, 0x58) = &D_80075CDC;
    FLD(arg0, u8, 0x14) = g_Player.bg_offset;
    FLD(arg0, s32, 0x18) = FLD(arg0, s32, 0x8);
    FLD(arg0, s32, 0x1C) = FLD(arg0, s32, 0xC);
    FLD(arg0, s32, 0x20) = 0;
    FLD(arg0, s32*, 0x30) = &D_800EFB54;
    FLD(arg0, s32, 0x24) = 0;
    FLD(arg0, s32, 0x28) = 0;
    FLD(arg0, s32, 0x2C) = 0;
    FLD(arg0, u8, 0x67) = 0;
    FLD(arg0, u8, 0x70) = 0;
    FLD(arg0, u8, 0x15) = 0;
    FLD(arg0, u8, 0x16) = 6;
    FLD(arg0, u8, 0x80) = random_byte() & 1;
    FLD(arg0, s32*, 0x68) = &D_800EFAE0[FLD(arg0, u8, 0x80)];
    FLD(arg0, u8, 0x81) = 0;
    FLD(arg0, s32*, 0x54) = &D_800EFAF0[FLD(arg0, u8, 0x80)];
    FLD(arg0, s32*, 0x50) = &D_800EFAE8[FLD(arg0, u8, 0x80)];
    switch (FLD(arg0, s8, 0x2)) {
    case 0:
        v = 0x78;
        FLD(arg0, s16, 0x7C) = v;
        FLD(arg0, s32, 0x54) = 0;
        FLD(arg0, s32, 0x50) = 0;
        FLD(arg0, u8, 0x3) = 0;
        FLD(arg0, u8, 0x5) = 3;
        break;
    case 1:
        v = 0xC;
        FLD(arg0, s16, 0x7C) = v;
        FLD(arg0, s32, 0x54) = 0;
        FLD(arg0, s32, 0x50) = 0;
        FLD(arg0, u8, 0x3) = 0;
        FLD(arg0, u8, 0x5) = 3;
        break;
    case 2:
        FLD(arg0, s32, 0x54) = 0;
        FLD(arg0, s32, 0x50) = 0;
        FLD(arg0, s16, 0x7C) = 0;
        FLD(arg0, u8, 0x5) = 3;
        break;
    case 3:
        FLD(arg0, s32, 0x54) = 0;
        FLD(arg0, s32, 0x50) = 0;
        FLD(arg0, s16, 0x7C) = 0;
        FLD(arg0, s16, 0x7E) = 0;
        FLD(arg0, u8, 0x5) = 3;
        break;
    case 4:
        FLD(arg0, u8, 0x3) = 1;
        FLD(arg0, s32, 0x20) = 0xFFF80000;
        FLD(arg0, s32, 0x24) = 0xFFFC0000;
        FLD(arg0, s32, 0x54) = 0;
        FLD(arg0, s32, 0x50) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, FLD(arg0, u8, 0x80));
        FLD(arg0, u8, 0x5) = 4;
        FLD(arg0, s32, 0x68) = 0;
        FLD(arg0, s16, 0x7C) = 0x32;
        break;
    case 5:
        FLD(arg0, u8, 0x3) = 1;
        FLD(arg0, s32, 0x20) = 0x80000;
        FLD(arg0, s32, 0x24) = 0xFFFC0000;
        ((void (*)(void*, s32))set_animation)(arg0, FLD(arg0, u8, 0x80));
        FLD(arg0, u8, 0x5) = 4;
        FLD(arg0, s32, 0x68) = 0;
        FLD(arg0, s16, 0x7C) = 0x32;
        break;
    case 6:
        FLD(arg0, u8, 0x3) = 1;
        FLD(arg0, s32, 0x24) = 0xFFF70000;
        ((void (*)(void*, s32))set_animation)(arg0, FLD(arg0, u8, 0x80) + 2);
        FLD(arg0, u8, 0x5) = 1;
        break;
    case 7:
        FLD(arg0, u8, 0x3) = 1;
        if (FLD(arg0, s16, 0xA) > g_Player.x_pos.i.hi) {
            FLD(arg0, s32, 0x20) = 0xFFFEE000;
            FLD(arg0, u8, 0x15) = 0;
        } else {
            FLD(arg0, s32, 0x20) = 0x12000;
            FLD(arg0, u8, 0x15) = 0x40;
        }
        FLD(arg0, s32, 0x24) = 0x21000;
        FLD(arg0, s32, 0x2C) = 0x1080;
        ((void (*)(void*, s32))set_animation)(arg0, FLD(arg0, u8, 0x80));
        FLD(arg0, u8, 0x5) = 2;
        FLD(arg0, s16, 0x7C) = 0x14;
        break;
    }
    FLD(arg0, u8, 0x4) = 1;
    FLD(arg0, u8, 0x6) = 0;
    FLD(arg0, u8, 0x7) = 0;
}

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800ECB40);

INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800ECD08);
// clang-format on

#define func_800EE8D8 func_800ECE54
#include "../shared/rock_04/func_800EE8D8.c"
#undef func_800EE8D8

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800ED2BC);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ED334(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();   /* extern */
M2C_UNK move_object(void*); /* extern */

void func_800ED354(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = (u8)(M2C_FIELD(arg0, u8*, 7) + 1);
    animate_object();
    move_object(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800ED390);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_80027BA0(s32, s32, s32, void*);
s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 random_byte();
extern s32 D_8007465C;
extern u32* D_80095098;
extern s8 D_80097244;
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800EFBA0;
extern s32 D_800EFBA8;
extern s32 D_800EFBB0;
extern s32 D_800EFBF0;
extern s32 D_800EFC04[];
extern s32 D_800EFC14;

void func_800ED41C(struct X4_MainObj* self) {
    struct X4_EngineObj* e = &g_playthrough_state;
    s32* p;
    s32 i;
    s8 t;
    s32 r;
    s32 v;

    if (M2C_FIELD(e, s8*, 0x43A) != 3) {
        clear_object_slot();
        return;
    }
    self->hp = 8;
    self->contact_damage = 4;
    self->collision_data = &D_8007465C;
    self->invincibility_timer = 0;
    self->active = 0x41;
    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    self->unk40 = D_80095098[func_8002A47C(self->id)] >> 7;
    self->unk42 = ((func_8002A47C(self->id) * 4 + 0x20) % 16) |
                  (((func_8002A47C(self->id) + 8) / 4 + 0x1E0) << 6);
    i = func_8002A47C(self->id);
    p = SPAD20;
    v = p[i];
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->air_state = 0;
    self->collision_flags = 0;
    self->sprite_frames = (const u8*)p + v;
    self->bg_offset = D_800970B4;
    self->unk15 = 0;
    self->animation_table = (const u8* const*)&D_800EFBF0;
    self->unk16 = 5;
    self->unk7C = 0;
    self->unk7E = 0;
    self->terrain_box = (struct X4_Unk_unk68*)&D_800EFBA0;
    self->hurt_box = &D_800EFBB0;
    self->attack_box = &D_800EFBA8;
    self->ext.main_0.background_relative = 2;
    self->ext.main_0.flags[0] = 0;
    r = random_byte();
    t = self->unk2;
    self->ext.main_0.index = (r % 3) * 10 + 0x14;
    if (t == 0) {
        self->on_screen = 1;
        self->x_speed = 0;
        self->y_speed = -0x30000;
        ((void (*)(void*, s32))set_animation)(self, 0);
        self->action = 1;
        self->terrain_box = NULL;
        play_sound(2, 0x50, self);
    } else if (t == 1) {
        if (e->stage == 2) {
            func_80027BA0(0, 0x1390, 0x210, D_800EFC04);
            func_80027BA0(0, 0x1390, 0x2E0, D_800EFC04 + 2);
            D_80097244 = t;
        } else if (*(u16*)&e->stage == 0x113) {
            func_80027BA0(0, 0x840, 0x430, &D_800EFC14);
            D_80097244 = t;
        }
        self->action = 2;
    }
    self->state = 1;
    self->action_phase = 0;
}

#define func_800EF160 func_800ED6DC
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_04/func_800EF160.c"
#undef func_800EF160
#undef g_playthrough_state

#define func_80041AB8 func_800EDB10
#define D_80075FD8 D_800EFBF4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EF5D0 func_800EDB4C
#define D_800F6D84 D_800EFC1C
#include "../shared/rock_04/func_800EF5D0.c"
#undef func_800EF5D0
#undef D_800F6D84

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EDC14(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800EDC34(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object();   /* extern */
M2C_UNK move_object(void*); /* extern */

void func_800EDC88(s32 arg0) {
    animate_object();
    move_object(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 random_byte();
extern u32* D_80095098;
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;
extern s32 D_800EFC50;

#define START(self)                                                            \
    {                                                                          \
        M2C_FIELD(self, s16*, 0x7C) = (random_byte() % 3 + 1) * 100 + 200;     \
        M2C_FIELD(self, u8*, 5) = 1;                                           \
        M2C_FIELD(self, u8*, 3) = 0;                                           \
        flag = 1;                                                              \
    }

void func_800EDCB4(void* self) {
    s32 flag = 0;
    s32 a;
    s32 b;

    if (D_800CD30A != 7) {
        clear_object_slot(self);
        return;
    }
    M2C_FIELD(self, u8*, 0) = 0x41;
    M2C_FIELD(self, u16*, 0x40) =
        D_80095098[func_8002A47C(M2C_FIELD(self, s8*, 1))] >> 7;
    a = func_8002A47C(M2C_FIELD(self, s8*, 1));
    b = func_8002A47C(M2C_FIELD(self, s8*, 1));
    M2C_FIELD(self, u16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(self, s32*, 0x3C) =
        SPAD20 + ((s32*)SPAD20)[func_8002A47C(M2C_FIELD(self, s8*, 1))];
    switch (M2C_FIELD(self, s8*, 2)) {
    case 0:
        if ((u32)((u16)D_800970AA - 0x141) < 0x8BF) {
            START(self);
        }
        break;
    case 1:
        if ((u32)((u16)D_800970AA - 0xC81) < 0x3BF) {
            START(self);
        }
        break;
    case 2:
        if ((u32)((u16)D_800970AA - 0x4E1) < 0x17F) {
            START(self);
        }
        break;
    case 3:
        if ((u32)((u16)D_800970AA - 0x1361) < 0x92F) {
            START(self);
        }
        break;
    case 4:
        if ((u32)((u16)D_800970AA - 1) < 0x41F) {
            START(self);
        }
        break;
    case 5:
        if ((u32)((u16)g_Player.x_pos.i.hi - 0x141) < 0x71F &&
            g_Player.y_pos.i.hi < 0x430) {
            START(self);
        }
        break;
    case 10:
        ((void (*)(void*, s32))set_animation)(self, 0);
        flag = 1;
        M2C_FIELD(self, s16*, 0x7C) = 0x28;
        M2C_FIELD(self, s32*, 0x54) = 0;
        M2C_FIELD(self, s32*, 0x50) = 0;
        M2C_FIELD(self, u8*, 5) = 3;
        M2C_FIELD(self, u8*, 3) = flag;
        break;
    case 11:
        M2C_FIELD(self, s16*, 0x7C) = 0x28;
        ((void (*)(void*, s32))set_animation)(self, 2);
        flag = 1;
        M2C_FIELD(self, s32*, 0x54) = 0;
        M2C_FIELD(self, s32*, 0x50) = 0;
        M2C_FIELD(self, u8*, 5) = 3;
        M2C_FIELD(self, u8*, 3) = flag;
        break;
    }
    if (flag) {
        struct X4_PlayerObj* p = &g_Player;
        M2C_FIELD(self, u8*, 0x5C) = 4;
        M2C_FIELD(self, u8*, 0x61) = 0;
        M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(p, u8*, 0x14);
        M2C_FIELD(self, void**, 0x30) = &D_800EFC50;
        M2C_FIELD(self, u8*, 0x16) = 4;
        M2C_FIELD(self, s32*, 0x68) = 0;
        M2C_FIELD(self, u8*, 0x67) = 0;
        M2C_FIELD(self, void**, 0x58) = &D_8007497C;
        M2C_FIELD(self, u8*, 0x60) = 6;
        M2C_FIELD(self, u8*, 0x15) = (M2C_FIELD(self, s32*, 8) <= p->x_pos.val)
                                     << 6;
        M2C_FIELD(self, u8*, 4) = 1;
        M2C_FIELD(self, u8*, 6) = 0;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EDF9C);

INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EE1D4);

INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EE2D4);
// clang-format on

#define func_800EFDB4 func_800EE330
#define D_800F6DD8 D_800EFC70
#include "../shared/rock_04/func_800EFDB4.c"
#undef func_800EFDB4
#undef D_800F6DD8

#define func_800EFE78 func_800EE3F4
#define D_80097420 D_80097420
#include "../shared/rock_04/func_800EFE78.c"
#undef func_800EFE78
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE46C(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800EE48C(void) {
    ((M2C_UNK(*)())move_object)();
}

#define func_8003744C func_800EE4AC
#define D_80073C1C D_800EFC80
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EE4E8);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EE534(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EE554);

INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EEA18);
// clang-format on

#define func_800F058C func_800EEB08
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_04/func_800F058C.c"
#undef func_800F058C
#undef g_playthrough_state

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EEB4C(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800EEB6C
#define D_80075FD8 D_800EFD18
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800F062C func_800EEBA8
#define D_80095098 D_80095098
#include "../shared/rock_04/func_800F062C.c"
#undef func_800F062C
#undef D_80095098

#define func_800F0718 func_800EEC94
#include "../shared/rock_04/func_800F0718.c"
#undef func_800F0718

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EECD4(void) {
    func_8002CA14();
}

// clang-format off
INCLUDE_ASM("asm/rock_26/nonmatchings/E9860", func_800EECF4);
// clang-format on
