#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern s32 g_Player;

void func_800E9970(s8* self, s8* parent);
void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1);

void func_800E992C(s8* arg0) {
    u8* p = (u8*)&g_Player;

    if (arg0[4] == 0) {
        func_800E9970(arg0, (s8*)p);
    } else {
        func_800E9A60((struct X4_VisualObj*)arg0, (struct X4_PlayerObj*)p);
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
extern u32* D_80095098;

void func_800E9970(s8* self, s8* parent) {
    u8 b = M2C_FIELD(parent, u8*, 0x14);

    M2C_FIELD(self, u8*, 0x16) = 0x11;
    M2C_FIELD(self, u32***, 0x30) = g_visual_animation_tables;
    M2C_FIELD(self, u8*, 0x14) = b;
    M2C_FIELD(self, s32*, 0x3C) = (s32)SPAD20 + SPAD20[func_8002A47C(0x8B)];
    M2C_FIELD(self, s16*, 0x40) = D_80095098[func_8002A47C(0x8B)] >> 7;
    M2C_FIELD(self, s16*, 0x42) =
        ((func_8002A47C(0x8B) * 4 + 0x20) % 16) |
        (((func_8002A47C(0x8B) + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(self, u8*, 4)++;
}

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_07_water_wake.c:water_wake_main, AGPL-3.0; proven shared with X6 by exact signature b82c7ed308c9 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern void (*D_800F5500[])(struct X4_VisualObj*, struct X4_PlayerObj*);
M2C_UNK clear_object_slot();
M2C_UNK func_8002CB50();
u8 get_tile_attr_bottom(struct X4_PlayerObj*);

void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1) {
    if (arg1->hp == 0 || arg1->state == 3) {
        clear_object_slot(arg0);
        return;
    }
    arg0->unk15 = arg1->facing;
    if (arg0->unk2 & 1) {
        arg0->x_pos.val = arg1->x_pos.val + FIXED(8);
    } else {
        arg0->x_pos.val = arg1->x_pos.val + FIXED(-8);
    }
    arg0->y_pos.val = arg1->y_pos.val;
    D_800F5500[arg0->unk5](arg0, arg1);
    if (arg1->active == 0) {
        arg0->on_screen = 0;
    }
    if (get_tile_attr_bottom(arg1) != 0x24) {
        arg0->on_screen = 0;
    }
    if (arg0->on_screen != 0) {
        func_8002CB50(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_800E9CDC();
s32 func_800E9D20(struct X4_PlayerObj* arg0);

void func_800E9B5C(u8* arg0, struct X4_PlayerObj* arg1) {
    if (func_800E9CDC(arg1) != 0) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0x13);
        arg0[3] = 1;
        arg0[5] = 1;
        return;
    }
    if (func_800E9D20(arg1) != 0) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0x14);
        arg0[3] = 1;
        arg0[5] = 2;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 func_800E9CDC();
s32 func_800E9D20(struct X4_PlayerObj* arg0);

void func_800E9BD8(u8* arg0, struct X4_PlayerObj* arg1) {
    if (func_800E9CDC(arg1) != 0) {
        ((void (*)())animate_object)(arg0);
        arg0[3] = 1;
        return;
    }
    if (func_800E9D20(arg1) != 0) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0x14);
        arg0[3] = 1;
        arg0[5] = 2;
        return;
    }
    arg0[3] = 0;
    arg0[5] = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 func_800E9CDC();
s32 func_800E9D20(struct X4_PlayerObj* arg0);

void func_800E9C5C(u8* arg0, struct X4_PlayerObj* arg1) {
    if (func_800E9D20(arg1) != 0) {
        ((void (*)())animate_object)(arg0);
        arg0[3] = 1;
        return;
    }
    if (func_800E9CDC(arg1) != 0) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0x13);
        arg0[3] = 1;
        arg0[5] = 1;
        return;
    }
    arg0[3] = 0;
    arg0[5] = 0;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F4BF0[];

s32 func_800E9CDC(void* arg0) {
    s32 t;
    s32 i;
    s32 r;

    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        t = (s32)(D_800F4BF0 + 0x7F0);
        i = M2C_FIELD(arg0, u8*, 0x17);
        r = *(u8*)(i + t);
    } else {
        t = (s32)(D_800F4BF0 + 0x880);
        i = M2C_FIELD(arg0, u8*, 0x17);
        r = *(u8*)(i + t);
    }
    return r == 1;
}

/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_07_water_wake.c:water_wake_player_moving, AGPL-3.0; proven shared with X6 by exact signature 98768ef976bc (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800F53E0[9][16];
extern u8 D_800F5470[9][16];

s32 func_800E9D20(struct X4_PlayerObj* arg0) {
    u8 state;

    if (arg0->character == 0) {
        state = D_800F53E0[0][arg0->unk17];
    } else {
        state = D_800F5470[0][arg0->unk17];
    }

    return state == 2;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
void func_800EA7CC(void*);
extern M2C_UNK D_8007433C;
extern s32 D_800970A8;
extern u8 D_800F4BF0[];

void func_800E9D64(void* arg0) {
    s32 r;

    if (M2C_FIELD(arg0, u8*, 0x47) == 0) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    } else {
        M2C_FIELD(arg0, void**, 0x58) = &D_800743DC;
    }
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    ((void (**)(void*))(D_800F4BF0 + 0xF64))[M2C_FIELD(arg0, s8*, 5)](arg0);
    if ((u32)(M2C_FIELD(arg0, u8*, 5) - 2) >= 2U) {
        if (M2C_FIELD(arg0, s32*, 8) > D_800970A8) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
    }
    func_800EA7CC(arg0);
    r = check_enemy_hits(arg0);
    if (r < 0) {
        func_80049E50(arg0);
        func_800477E4(4, (M2C_UNK*)(D_800F4BF0 + 0xF50), arg0);
        func_8004E654((struct X4_BaseObj*)arg0, 0x15);
        M2C_FIELD(arg0, u8*, 4) = 2;
        return;
    }
    if (r == 0x7F) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
    if ((M2C_FIELD(arg0, u8*, 0x70) & 0xC) == 0xC) {
        func_80049E50(arg0);
        func_800477E4(4, (M2C_UNK*)(D_800F4BF0 + 0xF50), arg0);
        func_8004E654((struct X4_BaseObj*)arg0, 0x15);
        M2C_FIELD(arg0, u8*, 4) = 2;
    } else {
        func_80030ECC(arg0);
        if (is_off_screen(arg0, 0x40, 0x40) == 0) {
            func_8002CCB0(arg0, 0x20, 0x20);
            return;
        }
        M2C_FIELD(arg0, u8*, 4) = 3;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800E9EF0);
// clang-format on

#include "../shared/rock_09/func_800EA178.c"

#define func_800EA1D8 func_800EA3D0
#define D_800FAA64 D_800F5B44
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EA41C);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EA514(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#include "../shared/rock_09/func_800EA554.c"

#include "../shared/rock_09/func_800EA5FC.c"

#include "../shared/rock_09/func_800EA708.c"

#include "../shared/rock_09/func_800EA750.c"

#include "../shared/rock_09/func_800EA7CC.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EA814(void) {
    clear_object_slot();
}

#define func_80048DC8 func_800EA834
#define D_80077BC0 D_800F5B8C
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EA880);
// clang-format on

#include "../shared/rock_09/func_800EA9B0.c"

#define func_80041AB8 func_800EAB54
#define D_80075FD8 D_800F5C58
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EAB90
#define D_80075FD8 D_800F5CA4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

s32 set_animation(void*, s32);
void func_800EB284();
extern s32 D_800F5C28;
extern s32 D_800F5B98;
extern s32 D_800F5B9C;

void func_800EABCC(void* arg0) {
    s8 v;
    // !FAKE: depin: dropping it breaks the match (36/65)
    register s32 c asm("$5");
    u8 b;
    // !FAKE: depin: dropping it breaks the match (61/65)
    register s32 e asm("$2");

    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x5C) = 6;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, void**, 0x30) = &D_800F5C28;
    b = D_800970B4;
    do {
        M2C_FIELD(arg0, u8*, 0x16) = 7;
    } while (0);
    {
        // !FAKE: depin: dropping it breaks the match (60/65)
        register void* q58 asm("$2") = &D_800743DC;
        M2C_FIELD(arg0, void**, 0x58) = q58;
    }
    {
        // !FAKE: depin: dropping it breaks the match (61/65)
        register void* q50 asm("$2") = &D_800F5B98;
        M2C_FIELD(arg0, void**, 0x50) = q50;
    }
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    e = M2C_FIELD(arg0, s32*, 0x8);
    c = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    {
        void* q54 = &D_800F5B9C;
        M2C_FIELD(arg0, void**, 0x54) = q54;
    }
    M2C_FIELD(arg0, u8*, 0x14) = b;
    M2C_FIELD(arg0, s32*, 0x18) = e;
    M2C_FIELD(arg0, s32*, 0x1C) = c;
    M2C_FIELD(SPAD, s16*, 0x80) = 0x1E;
    func_800EB284(arg0, c, b);
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        set_animation(arg0, 0);
        v = 2;
    } else {
        set_animation(arg0, 3);
        v = 3;
    }
    M2C_FIELD(arg0, s8*, 5) = v;
    do {
        func_800EB284(arg0);
        M2C_FIELD(arg0, u8*, 4) = 1;
        M2C_FIELD(arg0, u8*, 6) = 0;
    } while (0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern u8 D_800F4BF0[];
extern M2C_UNK D_800F5C50;

void func_800EACD0(s8* arg0) {
    s8 v;

    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    animate_object();
    ((void (**)(s8*))(D_800F4BF0 + 0x1078))[arg0[5]](arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_800477E4(5, &D_800F5C50, arg0);
        func_80049E50(arg0);
        func_8004E654((struct X4_BaseObj*)arg0, 0x13);
        v = 2;
        arg0[4] = v;
        return;
    }
    func_80030ECC(arg0);
    if (is_off_screen(arg0, 0x40, 0x40) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    v = 3;
    arg0[4] = v;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EADA0(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EADC0(void) {
    func_8002CA54();
}

#define func_8003744C func_800EADE0
#define D_80073C1C D_800F5C78
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void func_800EB284();
extern s16 D_800970AA;

#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800EAE1C(void* arg0) {
    s32 d;

    d = D_800970AA - H(arg0, 0xA);
    if (d >= 0) {
        if (d < 0x61) {
            // !FAKE: keeps the two range tests as separate branches
            goto body;
        }
    } else if (H(arg0, 0xA) - D_800970AA < 0x61) {
    body:
        func_800EB284(arg0);
        UB(arg0, 6)++;
        set_animation(arg0, 1);
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800EB1E4(void* arg0);

void func_800EAE98(void* arg0) {
    s8 state = M2C_FIELD(arg0, s8*, 0x45);

    if (state == 1) {
        play_sound(2, 0x1A, arg0);
        func_800EB1E4(arg0);
    } else if (state == 2) {
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x14;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

void func_800EB284();

void func_800EAF0C(void* arg0) {
    if (--M2C_FIELD(SPAD, s16*, 0x80) == 0) {
        func_800EB284();
        M2C_FIELD(SPAD, s16*, 0x80) = 0x1E;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EAF88);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

s32 random_byte();
extern u8 D_800F4BF0[];

void func_800EAFD4(void* arg0) {
    // !FAKE: keeps the speed constant in the argument register for the store and the call
    register s32 speed asm("$4");
    u8* p;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        speed = 0x3C000;
        p = D_800F4BF0 + 0xFB0;
        M2C_FIELD(arg0, void**, 0x50) = p;
        p = 0;
        M2C_FIELD(arg0, void**, 0x54) = D_800F4BF0 + 0xFB4;
        M2C_FIELD(arg0, s32*, 0x24) = speed;
        do {
            M2C_FIELD(SPAD, s16*, 0x82) = random_byte(speed) & 0x1F;
        } while (0);
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}

#include "../shared/rock_09/func_800EB048.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

void func_800EB284();

void func_800EB0B8(void* arg0) {
    if (--M2C_FIELD(SPAD, s16*, 0x80) == 0) {
        func_800EB284();
        M2C_FIELD(SPAD, s16*, 0x80) = 0x1E;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_800EB284(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x3C000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x3C000;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}

#include "../shared/rock_09/func_800EB16C.c"

#include "common.h"

void func_800EB1D4(void) {
}

#include "common.h"

void func_800EB1DC(void) {
}

#include "../shared/rock_09/func_800EB1E4.c"

#define func_80042C18 func_800EB284
/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_65_magma_dragoon.c:magma_dragoon_face_player, AGPL-3.0; proven shared with X6 by exact signature 3d82c3af21bb (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EB284(struct X4_MainObj* self) {
    if (g_Player.x_pos.i.hi > self->x_pos.i.hi) {
        self->unk15 = PLAYER_FACING_RIGHT;
    } else {
        self->unk15 = 0;
    }
}
#undef g_Player
#undef func_80042C18

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB2B4(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EB2D4);

INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EB4D4);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(void*);
void func_800EB914(void*);
void func_800EBA90(void*);
void func_800EBD14(void*);
extern u8 D_800F4BF0[];

void func_800EB5F8(void* arg0) {
    switch (M2C_FIELD(arg0, s8*, 2)) {
    case 1:
    case 2:
    case 3:
    case 4:
        func_800EB914(arg0);
        return;
    case 5:
        func_800EBA90(arg0);
        return;
    case 6:
        func_800EBD14(arg0);
        return;
    }
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    ((void (**)(void*))(D_800F4BF0 + 0x11F4))[M2C_FIELD(arg0, s8*, 4)](arg0);
    func_8002F288(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EB6C0);
// clang-format on

#include "common.h"

void func_800EB7D8(void) {
}

#include "common.h"

void* enemy_slot_alloc();
extern u8 D_800F4BF0[];

void func_800EB7E0(u8* arg0) {
    s32 i;
    u8* p;

    if ((arg0[0x70] & 8) && (*(s8*)(arg0 + 7) == 5)) {
        i = 1;
        do {
            p = enemy_slot_alloc();
            if (p != 0) {
                p[0] = arg0[0];
                p[1] = arg0[1];
                p[2] = i;
                *(u8**)(p + 0x80) = arg0;
            }
            i++;
        } while (i < 7);
        arg0[7] = 4;
    }
    if (*(s8*)(arg0 + 7) == 0 && *(void**)(arg0 + 0x54) == 0) {
        *(void**)(arg0 + 0x54) = D_800F4BF0 + 0x10C4;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
extern s8 D_800CCEF8;
extern u8 D_800F6BA0;

void func_800EB89C(void* arg0) {
    if (D_800F6BA0 == 3) {
        D_800CCEF8 = 1;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    func_8002CCB0(arg0, 0x28, 0x40);
}

#include "../shared/rock_09/func_800EB8F0.c"

#define func_800EB5A0 func_800EB914
#define D_800F6A84 D_800F5EC8
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(void*);
extern void (*D_800F5EC8[])(void*);

void func_800EB914(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800F5EC8[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    func_8002F288(arg0);
}
#undef func_800EB5A0
#undef D_800F6A84

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EB974);
// clang-format on

#include "common.h"

void func_800EBA40(void) {
}

#include "common.h"

void func_800EBA48(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EBA50(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EB5A0 func_800EBA90
#define D_800F6A84 D_800F5EE4
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(void*);
extern void (*D_800F5EE4[])(void*);

void func_800EBA90(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800F5EE4[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    func_8002F288(arg0);
}
#undef func_800EB5A0
#undef D_800F6A84

#include "../shared/rock_09/func_800EBAF0.c"

#include "../shared/rock_09/func_800EBBD4.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EBCD4(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EB5A0 func_800EBD14
#define D_800F6A84 D_800F5EF4
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(void*);
extern void (*D_800F5EF4[])(void*);

void func_800EBD14(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800F5EF4[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    func_8002F288(arg0);
}
#undef func_800EB5A0
#undef D_800F6A84

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800F4BF0[];

void func_800EBD74(void* arg0) {
    void* p;
    // !FAKE: depin: dropping it breaks the match (12/59)
    register s32 b asm("$5");
    // !FAKE: depin: dropping it breaks the match (12/59)
    register s32 h asm("$2");

    p = M2C_FIELD(arg0, void**, 0x80);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(arg0, s32*, 0x3C) = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42);
    b = D_800970B4;
    h = (s32)(D_800F4BF0 + 0x10D0);
    M2C_FIELD(arg0, void**, 0x50) = (void*)h;
    {
        // !FAKE: depin: dropping it breaks the match (56/59)
        register s32 five asm("$3") = 5;
        M2C_FIELD(arg0, u8*, 0x16) = five;
    }
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = b;
    M2C_FIELD(arg0, u16*, 0xA) += M2C_FIELD(p, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) += M2C_FIELD(p, u16*, 0xE);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    ((void (*)(void*, s32))set_animation)(arg0, 5);
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x4) += 1;
}

#include "../shared/rock_09/func_800EBE60.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EBF64(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 set_animation(void*, s32);
extern struct X4_Unk_unk68 D_800F5F04;
extern M2C_UNK D_800F5F0C;
extern M2C_UNK D_800F5F8C;

void func_800EBFA4(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (78/89)
    register void* p743 asm("$2");
    M2C_FIELD(arg0, u8*, 0x0) = 0x41;
    M2C_FIELD(arg0, u8*, 0x5C) = 3;
    M2C_FIELD(arg0, u8*, 0x60) = 3;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    p743 = &D_800743DC;
    M2C_FIELD(arg0, void**, 0x58) = p743;
    M2C_FIELD(arg0, void**, 0x30) = &D_800F5F8C;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F5F04;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F5F0C;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x80) = 0;
    M2C_FIELD(arg0, s32*, 0x84) = 0;
    M2C_FIELD(arg0, s32*, 0x88) = 0;
    M2C_FIELD(arg0, s32*, 0x8C) = 0;
    M2C_FIELD(arg0, s32*, 0x90) = 0;
    M2C_FIELD(arg0, s32*, 0x94) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(arg0, u8*, 0x4)++;
    switch (M2C_FIELD(arg0, s8*, 0x2)) {
    case 0:
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, u8*, 5) = 2;
        break;
    case 1:
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        M2C_FIELD(arg0, u8*, 5) = 5;
        M2C_FIELD(arg0, s32*, 0x88) = 1;
        break;
    case 4:
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, s32*, 0x88) = 1;
        break;
    default:
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        M2C_FIELD(arg0, u8*, 5) = 6;
        M2C_FIELD(arg0, s32*, 0x88) = 1;
        break;
    }
    M2C_FIELD(arg0, u8*, 6) = 0;
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
void func_800ECAA0(struct X4_MainObj*);
extern u8 D_800F4BF0[];

void func_800EC108(void* arg0) {
    u8 i;
    s32 r;
    u8 t;
    s32 v;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    ((void (**)(void*))(D_800F4BF0 + 0x13D8))[M2C_FIELD(arg0, s8*, 5)](arg0);
    t = func_80030ECC(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 4 && t == 1) {
        M2C_FIELD(arg0, s8*, 5) = 8;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 5) != 0) {
        M2C_FIELD(arg0, s32*, 0x94) = M2C_FIELD(arg0, s8*, 5);
    }
    for (i = 0; i < 2 - M2C_FIELD(arg0, s32*, 0x88); i++) {
        M2C_FIELD(arg0, s32*, 0x54) = ((s32*)(D_800F4BF0 + 0x13D0))[i];
        r = check_enemy_hits(arg0);
        if (r < 0) {
            if (i == 0 && M2C_FIELD(arg0, s32*, 0x88) == 0) {
                func_800ECAA0((struct X4_MainObj*)arg0);
            }
            func_80049E50(arg0);
            func_800477E4(4, (M2C_UNK*)(D_800F4BF0 + 0x13BC), arg0);
            func_8004E654((struct X4_BaseObj*)arg0, 0x14);
            v = M2C_FIELD(arg0, u8*, 4) + 1;
            M2C_FIELD(arg0, u8*, 4) = v;
            return;
        }
        if (r != 0) {
            break;
        }
    }
    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    v = 3;
    M2C_FIELD(arg0, u8*, 4) = v;
}

#define func_80041AB8 func_800EC29C
#define D_80075FD8 D_800F5FB0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*, void*); /* extern */
M2C_UNK func_8002CA54(void*, void*); /* extern */
extern u16 D_800CCEDC;

void func_800EC2D8(struct ObjectHeader* arg0) {
    if ((D_800CCEDC == 2) || (arg0->state == 3)) {
        func_8002CA54(arg0, arg0);
        return;
    }
    func_8002CA14(arg0, arg0);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC32C(void* arg0) {
    M2C_FIELD(arg0, u8*, 5) = (u8)M2C_FIELD(arg0, u8*, 0x94);
}

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EC338);
// clang-format on

#include "../shared/rock_09/func_800EC380.c"

#include "../shared/rock_09/func_800EC3B8.c"

#define func_8003744C func_800EC48C
#define D_80073C1C D_800F5FF4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_32_bomb_bat.c:bomb_bat_drop_start, AGPL-3.0; proven shared with X6 by exact signature 32f9f02b5c88 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_Unk_unk68 D_800F5F04;
s32 set_animation(void*, s32);

void func_800EC4C8(struct X4_MainObj* self) {
    set_animation(self, 1);
    self->x_speed = 0;
    self->ext.main_32.unk80 = 5;
    self->hurt_box = (const u8*)&D_800F5F04;
    self->attack_box = (const u8*)&D_800F5F04;
    self->action_phase++;
}

/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_32_bomb_bat.c:bomb_bat_drop_release, AGPL-3.0; proven shared with X6 by exact signature b8c90aca8278 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_800ECAA0(struct X4_MainObj*);

#define M2C_UNK s32
M2C_UNK animate_object();
void func_800EC518(struct X4_MainObj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    if (--self->ext.main_32.unk80 == 0) {
        self->ext.main_32.unk88 = 1;
        func_800ECAA0(self);
        self->ext.main_32.unk80 = 13;
        self->action_phase++;
    }
}

#include "../shared/rock_09/func_800EC574.c"

#define func_8003744C func_800EC5C4
#define D_80073C1C D_800F6000
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

extern u8 D_800F4BF0[];

void func_800EC600(void* self) {
    s32 v;
    u8* t;

    set_animation(self, 3);
    t = D_800F4BF0 + 0x1324;
    v = *(s32*)(((M2C_FIELD(self, u8*, 0x15) >> 4) & 4) + t);
    M2C_FIELD(self, s32*, 0x24) = 0x5000;
    M2C_FIELD(self, u8*, 6) = M2C_FIELD(self, u8*, 6) + 1;
    M2C_FIELD(self, s32*, 0x20) = v;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800EC65C(s32 arg0) {
    animate_object();
    move_object(arg0);
}

#define func_8003744C func_800EC688
#define D_80073C1C D_800F6008
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800F4BF0[];
extern struct X4_Unk_unk68 D_800F5F04;

void func_800EC6C4(void* arg0) {
    s32 tbl;
    // !FAKE: depin: dropping it breaks the match (18/27)
    register s32 v asm("$4");

    set_animation(arg0, 3);
    tbl = (s32)(D_800F4BF0 + 0x1324);
    v = *(s32*)((M2C_FIELD(arg0, u8*, 0x15) >> 4 & 4) + tbl);
    {
        // !FAKE: depin: dropping it breaks the match (22/27)
        register void* a asm("$2") = &D_800F5F04;
        M2C_FIELD(arg0, void**, 0x50) = a;
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x88) = 1;
    {
        // !FAKE: depin: dropping it breaks the match (20/27)
        register s32 b asm("$3") = M2C_FIELD(arg0, u8*, 0x6);
        M2C_FIELD(arg0, u8*, 0x6) = b + 1;
    }
    M2C_FIELD(arg0, s32*, 0x20) = v;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800EC730(s32 arg0) {
    animate_object();
    move_object(arg0);
}

#define func_8003744C func_800EC75C
#define D_80073C1C D_800F6010
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern u8 D_800F4BF0[];

void func_800EC798(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (35/63)
    register s32 r asm("$16");
    s32 t;
    // !FAKE: depin: dropping it breaks the match (60/63)
    register s32 tbl asm("$5");
    // !FAKE: depin: dropping it breaks the match (58/63)
    register s32 v asm("$4");

    set_animation(arg0, 3);
    r = random_byte();
    t = random_byte();
    tbl = (s32)(D_800F4BF0 + 0x132C);
    v = ((s32*)tbl)[(M2C_FIELD(arg0, u8*, 0x15) >> 6) & 1];
    M2C_FIELD(arg0, s32*, 0x20) = v;
    r = ((r << 8) + t) & 0xFFFF;
    if (random_byte() & 1) {
        M2C_FIELD(arg0, s32*, 0x20) += r;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) -= r;
    }
    M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
    M2C_FIELD(arg0, s32*, 0x24) = 0x18000;
    M2C_FIELD(arg0, void**, 0x50) = D_800F4BF0 + 0x1314;
    M2C_FIELD(arg0, s32*, 0x88) = 1;
    if (M2C_FIELD(arg0, s8*, 0x2) == 2) {
        M2C_FIELD(arg0, s16*, 0x7C) = random_byte() & 0x3F;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    } else {
        M2C_FIELD(arg0, u8*, 0x6) += 2;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC894(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
}

#include "../shared/rock_09/func_800EC8C0.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*); /* extern */
M2C_UNK move_object();         /* extern */

void func_800EC8F8(struct MainObj* arg0) {
    arg0->x_speed = 0;
    arg0->y_speed = 0x20000;
    ((M2C_UNK(*)())move_object)();
    animate_object(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EC930);
// clang-format on

#include "common.h"

#define M2C_UNK s32
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
extern u8 D_800F4BF0[];

void func_800EC978(void* arg0) {
    *(u8**)((u8*)arg0 + 0x50) = D_800F4BF0 + 0x1314;
    set_animation(arg0, 3);
    ((void (*)())animate_object)(arg0);
    *(s32*)((u8*)arg0 + 0x88) = 1;
    *(s16*)((u8*)arg0 + 0x7C) = 0x12C;
    *((u8*)arg0 + 6) += 1;
}

#include "../shared/rock_09/func_800EC9D0.c"

#define func_800F32A8 func_800ECA70
/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_13_heavy_mech.c:heavy_mech_face_player, AGPL-3.0; proven shared with X6 by exact signature d7798d86256f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800ECA70(struct X4_AnimatedObj* self) {
    if (self->x_pos.val > g_Player.x_pos.val) {
        self->unk15 = 0;
    } else {
        self->unk15 = PLAYER_FACING_RIGHT;
    }
}
#undef g_Player
#undef func_800F32A8

#include "../shared/rock_09/func_800ECAA0.c"

#define func_80041AB8 func_800ECB48
#define D_80075FD8 D_800F602C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800ECB84);
// clang-format on

#include "../shared/rock_09/func_800ECC10.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECCF8(void) {
    clear_object_slot();
}

#include "common.h"

void func_800ECD18(void) {
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 set_animation(void*, s32);
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_800F6084;
extern s32 D_800F608C;
extern s32 D_800F6090;

void func_800ECD20(s8* self) {
    struct X4_PlayerObj* pl = &g_Player;
    s32 a;
    s32 b;
    s32 k;

    M2C_FIELD(self, s8*, 0x5) = 2;
    M2C_FIELD(self, s8*, 0x0) = 0x41;
    M2C_FIELD(self, s8*, 0x4)++;
    M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(pl, u8*, 0x14);
    M2C_FIELD(self, u16*, 0x40) = D_80095098[func_8002A47C(0x83)] >> 7;
    M2C_FIELD(self, u8**, 0x3C) = (u8*)SPAD20 + SPAD20[func_8002A47C(0x83)];
    a = func_8002A47C(0x83);
    b = func_8002A47C(0x83);
    M2C_FIELD(self, u16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    k = 7;
    do {
        M2C_FIELD(self, void**, 0x68) = &D_800F6090;
        M2C_FIELD(self, u8*, 0x16) = k;
        M2C_FIELD(self, void**, 0x54) = &D_800F608C;
        M2C_FIELD(self, void**, 0x58) = &D_80075B9C;
        M2C_FIELD(self, void**, 0x30) = &D_800F6084;
        M2C_FIELD(self, s8*, 0x61) = 0;
        M2C_FIELD(self, u8*, 0x15) = 0;
        M2C_FIELD(self, s8*, 0x65) = 0;
        M2C_FIELD(self, s8*, 0x75) = 1;
        M2C_FIELD(self, s8*, 0x76) = 0;
        M2C_FIELD(self, s8*, 0x60) = 0xA;
        M2C_FIELD(self, s8*, 0xA2) = 1;
        M2C_FIELD(self, s8*, 0x84) = 0;
        M2C_FIELD(self, s16*, 0x7C) = M2C_FIELD(self, s16*, 0xA);
        M2C_FIELD(self, s16*, 0x7E) = M2C_FIELD(self, s16*, 0xE);
        if (M2C_FIELD(self, s8*, 0x2) != 0) {
            set_animation(self, 0);
            M2C_FIELD(self, s8*, 0x6) = 1;
            M2C_FIELD(self, s32*, 0x20) = 0;
            M2C_FIELD(self, s32*, 0x24) = 0x10000;
        } else {
            set_animation(self, 1);
            M2C_FIELD(self, s8*, 0x6) = 2;
            M2C_FIELD(self, s32*, 0x20) = 0x10000;
            M2C_FIELD(self, s32*, 0x24) = 0;
            if (pl->x_pos.val < M2C_FIELD(self, s32*, 0x8)) {
                M2C_FIELD(self, s32*, 0x20) = 0xFFFF0000;
            }
        }
    } while (0);
}
#undef g_Player

#define func_80048DC8 func_800ECEF4
#define D_80077BC0 D_800F6094
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK collide_solid_object();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
s32 func_80032B34(struct X4_PlayerObj*);
void func_80032BE8(struct X4_PlayerObj*);
extern s32 g_Player;
extern u8 D_800F4BF0[];

void func_800ECF40(void* arg0) {
    struct X4_PlayerObj* p;

    func_80032B34(arg0);
    func_80032BE8(arg0);
    p = &g_Player;
    if (p->nova_strike_active != 2) {
        ((void (**)(void*))(D_800F4BF0 + 0x14B0))[M2C_FIELD(arg0, s8*, 6)](
            arg0);
    }
    animate_object(arg0);
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x40);
    if (((u8*)p)[0xE5] == 0) {
        collide_solid_object(arg0);
    }
    func_8003208C(arg0);
    func_80031F4C(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */

void func_800ECFEC(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    ((M2C_UNK(*)())func_8002CA14)();
}

#include "common.h"

void func_800ED00C(void) {
}

#include "../shared/rock_09/func_800ED014.c"

#include "../shared/rock_09/func_800ED0B4.c"

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
extern s16 D_800F6BC4[16];

void func_800ED18C(s32 arg0, s32 arg1, u8* arg2) {
    u16* p;
    s32 n;
    s32 i;
    s32 base;
    s32 j;
    u16* src;
    u16* dst;
    s32 t;
    u32 c;
    s32 r;
    s32 g;
    s32 b;
    s32 dr;
    s32 dg;
    s32 db;
    u16 v;

    p = *(u16**)(arg2 + 0x20);
    n = *p;
    base = arg0;
    i = base % 15;
    base = (base / 15) * 15;
    p++;
    if (base == arg1) {
        for (i = 0; i < n; i++) {
            src = &p[n + (i << 5)];
            dst = (u16*)(SPAD28 + ((p[i] + 0x60) << 5));
            for (j = 0; j < 16; j++) {
                *dst++ = *src++;
            }
        }
        D_800C4560 |= 1;
        return;
    }
    for (; i < n; i += 15) {
        src = &p[n + (i << 5)];
        for (j = 0; j < 16; j++) {
            dst = src + 16;
            c = *src++;
            r = c & 0x1F;
            g = (c & 0x3E0) >> 5;
            b = (c & 0x7C00) >> 10;
            c = *dst;
            dr = c & 0x1F;
            dg = (c & 0x3E0) >> 5;
            db = (c & 0x7C00) >> 10;
            dr -= r;
            dg -= g;
            db -= b;
            t = ((arg1 - base) << 8) / arg1;
            v = (((t * dr) >> 8) + r) | ((((t * dg) >> 8) + g) << 5) |
                ((((t * db) >> 8) + b) << 10) | (c & 0x8000);
            if (v == 0 && c != 0) {
                v = 0x8000;
            }
            D_800F6BC4[j] = v;
        }
        load_palette(p[i] + 0x60, (M2C_UNK*)D_800F6BC4, 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
extern s32 g_Player;

#define PL ((u8*)&g_Player)
#define F_S8(p, o) (*(s8*)((p) + (o)))
#define F_S16(p, o) (*(s16*)((p) + (o)))

void func_800ED3E4(u8* arg0) {
    u8* pl;
    s8 hp;
    s8 v;

    if (D_800CCEF6 == 0) {
        arg0[4]++;
        return;
    }
    pl = PL;
    if (F_S16(pl, 0x14C) != 0) {
        play_sound(5, 4, 0);
    }
    if (F_S8(pl, 0x5C) != 0 && F_S8(pl, 0xE0) == 0) {
        if (++*(u16*)(arg0 + 0x16) >= 0xB4) {
            *(u16*)(arg0 + 0x16) = 0;
            hp = F_S8(pl, 0x5C);
            v = F_S8(pl, 0x5C) & 0x7F;
            F_S8(pl, 0x5C) = v;
            if (D_8008EAFC == 0) {
                if (v < 2) {
                    F_S8(pl, 0x5C) = -0x80;
                } else {
                    F_S8(pl, 0x5C) = v - 1;
                }
            }
            if (hp < 0) {
                u8* q = PL;
                F_S8(q, 0x5C) |= 0x80;
            }
        }
        if (++*(u16*)(arg0 + 0x18) >= 0x33) {
            u8* q = PL;
            *(u16*)(arg0 + 0x18) = 0;
            F_S8(q, 0xE8) = 1;
        }
    }
}
#undef PL
#undef F_S8
#undef F_S16

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F4BF0[];

void func_800ED510(void* arg0) {
    u32 v;

    if (D_800CCEF7 != 0) {
        M2C_FIELD(arg0, u16*, 0x16) = 0;
        M2C_FIELD(arg0, u16*, 0x18) = 0;
    }
    ((void (**)(void*))(D_800F4BF0 + 0x14BC))[M2C_FIELD(arg0, s8*, 4)](arg0);
    if (M2C_FIELD(arg0, u16*, 0x1E) != 0) {
        M2C_FIELD(arg0, u16*, 0x14)++;
        v = M2C_FIELD(arg0, u16*, 0x14);
        if (!(v & 3)) {
            if ((v >> 2) >= 5) {
                M2C_FIELD(arg0, u16*, 0x14) = 0;
            }
            {
                u8* p = (u8*)background_objects;
                u32 t = M2C_FIELD(arg0, u16*, 0x14);
                M2C_FIELD(p, u8*, 0xA0) = 1;
                M2C_FIELD(p, s16*, 0x62) = (t >> 2) << 8;
            }
        }
    }
}

#include "common.h"
#include "mmx6/globals.h"

extern s8 D_8008EAB0;
extern s32 D_800F6BA4;

#define SCRATCH_30 (*(u8**)0x1F800030)

void func_800ED5C4(u8* arg0) {
    u8* p;

    if (D_800CCEED == 3) {
        D_8008EAB0 = 1;
    }
    arg0[0] |= 8;
    p = SCRATCH_30;
    __builtin_memcpy(&D_800F6BA4, p + 0x200, 0x20);
    *(u8**)(arg0 + 0x20) = p + 0x460;
    arg0[4]++;
}

#undef SCRATCH_30

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
void func_800ED18C(s32 arg0, s32 arg1, u8* arg2);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800F6BA4;
extern s16 D_800F6BC4[16];

void func_800ED69C(u8* arg0) {
    u8* bg;

    if (D_800CCEF6 != 0) {
        bg = (u8*)background_objects;
        *(u16*)(arg0 + 0x14) = 0;
        *(u16*)(arg0 + 0x16) = 0;
        *(u16*)(arg0 + 0x18) = 0;
        *(s16*)(bg + 0x5E) = 0;
        *(s16*)(bg + 0x62) = 0;
        bg[0xA0] = 1;
        *(u16*)(arg0 + 0x1E) = 1;
        *(u16*)(arg0 + 0x1A) = 0;
        func_8002B410((s32*)D_800F6BC4, &D_800F6BA4, 0x10, 0x1E, 0x1E);
        load_palette(0x63, (s32*)D_800F6BC4, 1);
        func_800ED18C(0x1E - *(u16*)(arg0 + 0x1A), 0x1E, arg0);
        play_sound(5, 4, 0);
        arg0[4]++;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
void func_800ED18C(s32 arg0, s32 arg1, u8* arg2);
extern s32 D_800F6BA4;
extern s16 D_800F6BC4[16];

void func_800ED774(u8* arg0) {
    if (D_800CCEF6 == 0) {
        arg0[4] += 2;
        return;
    }
    if (++*(u16*)(arg0 + 0x1A) >= 0x1E) {
        *(u16*)(arg0 + 0x1A) = 0x1E;
    }
    func_8002B410((M2C_UNK*)D_800F6BC4, &D_800F6BA4, 0x10,
                  0x1E - *(u16*)(arg0 + 0x1A), 0x1E);
    load_palette(0x63, (M2C_UNK*)D_800F6BC4, 1);
    func_800ED18C(0x1E - *(u16*)(arg0 + 0x1A), 0x1E, arg0);
    if (*(u16*)(arg0 + 0x1A) == 0x1E) {
        arg0[4]++;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
void func_800ED18C(s32 arg0, s32 arg1, u8* arg2);
extern s32 D_800F6BA4;
extern s16 D_800F6BC4[16];

void func_800ED850(u8* arg0) {
    if (D_800CCEF6 != 0) {
        arg0[4] -= 2;
        return;
    }
    if (*(u16*)(arg0 + 0x1A) != 0) {
        (*(u16*)(arg0 + 0x1A))--;
    }
    func_8002B410((M2C_UNK*)D_800F6BC4, &D_800F6BA4, 0x10,
                  0x1E - *(u16*)(arg0 + 0x1A), 0x1E);
    load_palette(0x63, (M2C_UNK*)D_800F6BC4, 1);
    func_800ED18C(0x1E - *(u16*)(arg0 + 0x1A), 0x1E, arg0);
    if (*(u16*)(arg0 + 0x1A) == 0) {
        arg0[4] -= 3;
        play_sound(5, 3, 0);
    }
}

#include "../shared/rock_09/func_800ED92C.c"

#define func_80041AB8 func_800EDA34
#define D_80075FD8 D_800F60C0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/rock_09/func_800EDA70.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EDABC(void) {
    ((M2C_UNK(*)())func_8002CA14)();
}

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EDADC);

INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EDC64);

INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EDDFC);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EDE78(void) {
    ((M2C_UNK(*)())func_8002CA54)();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

M2C_UNK func_8002CA14();
void func_800EDE98(void* arg0) {
    s32 var_s0;
    u16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x42) = (u16)(M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v1 + 1);
    if ((s16)temp_v1 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0U;
    var_s0 = 3;
    do {
        func_80049EBC(arg0, 1, 0x10, 0x10);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    ((M2C_UNK(*)())func_8002CA14)(arg0);
}

#define func_800EAA18 func_800EDF2C
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EDF2C(void* self) {
    if (F(s8, 0x45) == 2) {
        ((void (*)(void*))move_object)(self);
        if (F(u8, 0x70) & 8) {
            play_sound(2, 0x52, self);
            ((void (*)(s32))start_pad_vibration)(5);
            F(s16, 0x7C) = 0xB4;
            F(s8, 5)++;
            if (F(s8, 3) != 0) {
                func_8002943C(0x5A, 2, 2);
            }
        }
    }
}

#undef F
#undef func_800EAA18

#define func_800EAAA4 func_800EDFB8
#include "../shared/rock_05/func_800EAAA4.c"
#undef func_800EAAA4

#define func_800EAADC func_800EDFF0
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EDFF0(void* self) {
    ((void (*)(void*))move_object)(self);
    if (F(s16, 0xE) <= F(s16, 0x7E)) {
        F(s32, 0x24) = 0xFFFC0000;
        F(s16, 0xE) = F(s16, 0x7E);
        F(s8, 5) = 0;
    }
}

#undef F
#undef func_800EAADC

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern s32 D_800F62B0;
extern s32 D_800F62D8;

void func_800EE03C(s8* self) {
    s32 a;
    s32 b;

    M2C_FIELD(self, s8*, 0x0) = 0x41;
    M2C_FIELD(self, s8*, 0x16) = 7;
    M2C_FIELD(self, s8*, 0x15) = 0;
    M2C_FIELD(self, u16*, 0x40) = D_80095098[func_8002A47C(0x8F)] >> 7;
    M2C_FIELD(self, u8**, 0x3C) = (u8*)SPAD20 + SPAD20[func_8002A47C(0x8F)];
    a = func_8002A47C(0x8F);
    b = func_8002A47C(0x8F);
    M2C_FIELD(self, u16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(self, void**, 0x30) = &D_800F62B0;
    M2C_FIELD(self, void**, 0x68) = &D_800F62D8;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, s8*, 0x75) = 0;
    ((void (*)(void*, s32))set_animation)(self, 0);
    M2C_FIELD(self, s8*, 0x4)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
struct X4_VisualObj* find_free_visual_obj(void);
M2C_UNK func_8004E78C(M2C_UNK);
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;

void func_800EE150(void* self) {
    struct X4_VisualObj* obj;

    if (g_Player.action == 0x14) {
        ((void (*)(s32))func_8004E78C)(1);
        M2C_FIELD(self, s8*, 0) |= 8;
        if ((g_Player.hp & 0x7F) >=
            ((struct X4_EngineObj*)((s8*)&g_playthrough_state -
                                    -g_Player.character))
                ->sub_tanks[-1]) {
            ((void (*)(void*, s32))set_animation)(self, 2);
            M2C_FIELD(self, s8*, 6) += 1;
            return;
        }
        ((void (*)(s32, s32, void*))play_sound)(2, 0x55, self);
        ((void (*)(void*, s32))set_animation)(self, 1);
        M2C_FIELD(self, s16*, 0x7C) = 0x1F;
        M2C_FIELD(self, s8*, 6) += 2;
        obj = find_free_visual_obj();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0xE;
            obj->unk2 = 0;
            obj->unk16 = 1;
            obj->unk15 = 0;
            obj->unk50 = self;
        }
        obj = find_free_visual_obj();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0xE;
            obj->unk2 = 1;
            obj->unk16 = 6;
            obj->unk15 = 0;
            obj->unk50 = self;
        }
    }
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;

void func_800EE27C(void* self) {
    s8 hi;
    struct X4_EngineObj* e;

    if (--M2C_FIELD(self, s16*, 0x7C) == 0) {
        M2C_FIELD(self, s16*, 0x7C) = 2;
        hi = g_Player.hp & 0x80;
        e = (struct X4_EngineObj*)((s8*)&g_playthrough_state -
                                   -g_Player.character);
        if ((g_Player.hp & 0x7F) >= e->sub_tanks[-1]) {
            g_Player.hp = hi | e->sub_tanks[-1];
            M2C_FIELD(self, s16*, 0x7C) = 0x1B;
            M2C_FIELD(self, s8*, 6) += 1;
        } else {
            g_Player.hp = hi | (g_Player.hp + 1);
        }
        ((void (*)(s32, s32, s32, void*))play_sound)(0, 0xD, 0, self);
    }
}
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_09/nonmatchings/E9860", func_800EE330);
// clang-format on

#define func_80048DC8 func_800EE43C
#define D_80077BC0 D_800F62E4
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_80041AB8 func_800EE488
#define D_80075FD8 D_800F631C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/rock_09/func_800EE4C4.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE534(void) {
    clear_object_slot();
}

#include "../shared/rock_09/func_800EE554.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
s32 func_800EE330(void*, M2C_UNK*);
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EE5A8(struct X4_MainObj* self) {
    if (func_800EE330(self, (M2C_UNK*)&g_Player) != 0) {
        D_800CCEF7 = 1;
        g_Player.x_pos.i.hi = self->x_pos.i.hi;
        g_Player.y_pos.i.hi = self->y_pos.i.hi - g_Player.terrain_box->unk3;
        func_8003D308(0x14, g_Player.facing);
        self->action_phase++;
    }
}
#undef g_Player

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_8003D330();               /* extern */
M2C_UNK func_8004E78C(M2C_UNK);        /* extern */

void func_800EE628(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        func_8003D330();
        D_800CCEF7 = 0;
        set_animation(arg0, 0);
        func_8004E78C(0);
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 0) = (u8)(M2C_FIELD(arg0, u8*, 0) & 0xF7);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "../shared/rock_09/func_800EE698.c"

#include "../shared/rock_09/func_800EE6CC.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50();                         /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*); /* extern */
s32 func_800EE330(void*, M2C_UNK*);              /* extern */
extern M2C_UNK g_Player;
extern M2C_UNK D_800F62E0;

void func_800EE748(void* arg0) {
    func_8002CB50();
    if (M2C_FIELD(arg0, s8*, 2) == 1) {
        func_800477E4(3, &D_800F62E0, arg0);
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    if (func_800EE330(arg0, &g_Player) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) - 1);
    }
}

#include "../shared/rock_09/func_800EE7C8.c"

#include "../shared/rock_09/func_800EE880.c"

#include "../shared/rock_09/func_800EE8D4.c"
