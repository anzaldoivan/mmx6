// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", D_800E9860);
// clang-format on

#define g_Player D_800970A0_x4
#define D_800F79D0 D_800F2068
#define func_800E9C98 func_800E9864
#include "../shared/rock_07/func_800E9C98.c"
#undef func_800E9C98
#undef g_Player
#undef D_800F79D0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(void*, void*); /* extern */
extern u16 D_80097214;
extern s8 D_800CCEED;

void func_800E98C4(void* arg0) {
    if (D_800CCEED == 1) {
        clear_object_slot(arg0, arg0);
        return;
    }
    M2C_FIELD(arg0, u16*, 0x14) = (u16)D_80097214;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK g_Player;

void func_800E9918(void* arg0) {
    struct X4_PlayerObj* pl = &g_Player;

    if (M2C_FIELD(pl, s16*, 0xA) >= 0x80) {
        M2C_FIELD(pl, s32*, 0xF4) += 0x8000;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern M2C_UNK g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_800E995C(void* arg0) {
    struct X4_BackgroundObj* bg = &background_objects[0];

    if (bg->x_pos.i.hi >= M2C_FIELD(arg0, s16*, 0x14)) {
        struct X4_PlayerObj* pl = &g_Player;

        M2C_FIELD(pl, s32*, 0xF4) -= 0x8000;
        ((M2C_UNK(*)())clear_object_slot)();
        return;
    }
    bg->x_pos.val += 0x8000;
    bg->unk1C = bg->x_pos.i.hi;
    bg->unk1E = bg->x_pos.i.hi;
    bg->unk24 = bg->x_pos.i.hi;
    bg->unk26 = bg->x_pos.i.hi;
}

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800E99E0);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800E9B98);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800E9EC4);
// clang-format on

#define func_80048DC8 func_800EA000
#define D_80077BC0 D_800F2C64
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_800EA5F0 func_800EA04C
#include "../shared/rock_11/func_800EA5F0.c"
#undef func_800EA5F0

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EA06C);
// clang-format on

#define func_800EA0EC func_800EA254
#define D_800C1220 D_800C1220
#include "../shared/rock_06/func_800EA0EC.c"
#undef func_800EA0EC
#undef D_800C1220

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EA398);
// clang-format on

#define func_80048DC8 func_800EA698
#define D_80077BC0 D_800F2CCC
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EA6E4);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EA704);
// clang-format on

#define func_80041AB8 func_800EA724
#define D_80075FD8 D_800F2CDC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EA760);
// clang-format on

#define func_800EA64C func_800EA7B4
#include "../shared/rock_06/func_800EA64C.c"
#undef func_800EA64C

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EA84C);
// clang-format on

#define func_800EA704 func_800EA86C
#define g_Player g_Player
#include "../shared/rock_06/func_800EA704.c"
#undef func_800EA704
#undef g_Player

#define func_800EA840 func_800EA9A8
#include "../shared/rock_06/func_800EA840.c"
#undef func_800EA840

#define func_800EA9E0 func_800EAB48
#define D_800950A0 D_800950A0
#include "../shared/rock_06/func_800EA9E0.c"
#undef func_800EA9E0
#undef D_800950A0

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EAD34);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EAE70);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EAFB0);
// clang-format on

#define func_80041AB8 func_800EB0FC
#define D_80075FD8 D_800F2E58
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EB138);
// clang-format on

#define func_800EB070 func_800EB1D8
#include "../shared/rock_06/func_800EB070.c"
#undef func_800EB070

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EB274);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EB31C);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EB420);
// clang-format on

#define func_800F23E4 func_800EB508
#include "../shared/rock_10/func_800F23E4.c"
#undef func_800F23E4

#define func_80041AB8 func_800EB548
#define D_80075FD8 D_800F2E74
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EB584);
// clang-format on

#define func_800EB4D4 func_800EB63C
#include "../shared/rock_06/func_800EB4D4.c"
#undef func_800EB4D4

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EB704);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EB724);
// clang-format on

#define func_800EAE0C func_800EB8A4
#include "../shared/rock_02/func_800EAE0C.c"
#undef func_800EAE0C

#define func_800EA1D8 func_800EBA48
#define D_800FAA64 D_800F2EEC
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EBA94);
// clang-format on

#define func_800EB10C func_800EBBA4
#include "../shared/rock_02/func_800EB10C.c"
#undef func_800EB10C

#define func_800EB14C func_800EBBE4
#include "../shared/rock_02/func_800EB14C.c"
#undef func_800EB14C

#define func_800EB1A0 func_800EBC38
#include "../shared/rock_02/func_800EB1A0.c"
#undef func_800EB1A0

#include "../shared/rock_28/func_800EBC8C.c"

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EBCD4);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EBDD8);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EBE8C);
// clang-format on

#define func_80041AB8 func_800EBEAC
#define D_80075FD8 D_800F2F14
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EE158 func_800EBEE8
#include "../shared/rock_06/func_800EE158.c"
#undef func_800EE158

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EBF64);
// clang-format on

#define func_800EE344 func_800EC0D4
#include "../shared/rock_06/func_800EE344.c"
#undef func_800EE344

#define func_800EE6C0 func_800EC450
#include "../shared/rock_06/func_800EE6C0.c"
#undef func_800EE6C0

#define func_800EE828 func_800EC5B8
#include "../shared/rock_06/func_800EE828.c"
#undef func_800EE828

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EC6B4);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EC85C);
// clang-format on

#define func_800EEC50 func_800EC9E0
#define g_Player g_Player
#include "../shared/rock_06/func_800EEC50.c"
#undef func_800EEC50
#undef g_Player

#define func_800EEE00 func_800ECB90
#define g_Player g_Player
#include "../shared/rock_06/func_800EEE00.c"
#undef func_800EEE00
#undef g_Player

#define func_800EEFF0 func_800ECD80
#define g_Player g_Player
#include "../shared/rock_06/func_800EEFF0.c"
#undef func_800EEFF0
#undef g_Player

#define func_800EF288 func_800ED018
#include "../shared/rock_06/func_800EF288.c"
#undef func_800EF288

#define func_800EF524 func_800ED2B4
#define g_Player g_Player
#include "../shared/rock_06/func_800EF524.c"
#undef func_800EF524
#undef g_Player

#define func_800EF758 func_800ED4E8
#define g_Player g_Player
#include "../shared/rock_06/func_800EF758.c"
#undef func_800EF758
#undef g_Player

#define func_800EF950 func_800ED6E0
#define D_80097420 D_80097420
#include "../shared/rock_06/func_800EF950.c"
#undef func_800EF950
#undef D_80097420

#define func_800EFC4C func_800ED9DC
#define g_Player g_Player
#include "../shared/rock_06/func_800EFC4C.c"
#undef func_800EFC4C
#undef g_Player

#define func_800EFDB0 func_800EDB40
#define D_80097420 D_80097420
#include "../shared/rock_06/func_800EFDB0.c"
#undef func_800EFDB0
#undef D_80097420

#define func_800EFFCC func_800EDD5C
#define D_800F3A44 D_800F2F28
#include "../shared/rock_06/func_800EFFCC.c"
#undef func_800EFFCC
#undef D_800F3A44

#define func_800F011C func_800EDEAC
#define g_Player g_Player
#include "../shared/rock_06/func_800F011C.c"
#undef func_800F011C
#undef g_Player

#define func_800F036C func_800EE0FC
#define D_80097420 D_80097420
#include "../shared/rock_06/func_800F036C.c"
#undef func_800F036C
#undef D_80097420

#define func_800F04E8 func_800EE278
#include "../shared/rock_06/func_800F04E8.c"
#undef func_800F04E8

#define func_800F071C func_800EE4AC
#include "../shared/rock_06/func_800F071C.c"
#undef func_800F071C

#define func_800F097C func_800EE70C
#define g_Player g_Player
#include "../shared/rock_06/func_800F097C.c"
#undef func_800F097C
#undef g_Player

#define func_800F0B5C func_800EE8EC
#define g_Player g_Player
#include "../shared/rock_06/func_800F0B5C.c"
#undef func_800F0B5C
#undef g_Player

#define func_800F0EA4 func_800EEC34
#include "../shared/rock_06/func_800F0EA4.c"
#undef func_800F0EA4

#define func_800F10C0 func_800EEE50
#define g_Player g_Player
#include "../shared/rock_06/func_800F10C0.c"
#undef func_800F10C0
#undef g_Player

#define func_800F1494 func_800EF224
#define g_Player g_Player
#include "../shared/rock_06/func_800F1494.c"
#undef func_800F1494
#undef g_Player

#define func_800F1670 func_800EF400
#define g_Player g_Player
#include "../shared/rock_06/func_800F1670.c"
#undef func_800F1670
#undef g_Player

#define func_800F1C80 func_800EFA10
#include "../shared/rock_06/func_800F1C80.c"
#undef func_800F1C80

#define func_800F1DA8 func_800EFB38
#define background_objects background_objects
#include "../shared/rock_06/func_800F1DA8.c"
#undef func_800F1DA8
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800EFC54);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F01A4);
// clang-format on

#define func_800F250C func_800F029C
#include "../shared/rock_06/func_800F250C.c"
#undef func_800F250C

#define func_800F254C func_800F02DC
#include "../shared/rock_06/func_800F254C.c"
#undef func_800F254C

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F0318);
// clang-format on

#define func_800F26C4 func_800F0454
#include "../shared/rock_06/func_800F26C4.c"
#undef func_800F26C4

#define func_800F26E4 func_800F0474
#define D_800F3A5C D_800F2F40
#include "../shared/rock_06/func_800F26E4.c"
#undef func_800F26E4
#undef D_800F3A5C

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F04C0);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F0754);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800F34FC[][4];
extern u16 D_800F3504[][8][2];
extern u16 D_800F35EC;

void func_800F089C() {
    u16 buf[4];
    s32 i;

    i = 0;
    D_800F35EC &= 7;
    do {
        buf[0] = D_800F3504[i][(s16)D_800F35EC][0];
        buf[1] = D_800F3504[i][(s16)D_800F35EC][1];
        buf[2] = D_800F34FC[i][2];
        buf[3] = D_800F34FC[i][3];
        func_80027BA0(0, D_800F34FC[i][0], D_800F34FC[i][1], (u8*)buf);
        i++;
    } while (i < 1);
    background_objects[0].unk4C = 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK clear_object_slot();
s32 func_80030234();
void func_800F04C0();
void func_800F0754(void);
void func_800F089C();

extern M2C_UNK g_Player;
extern s16 D_80097202;
#include "mmx6/state.h"
#define P ((struct X4_PlayerObj*)&g_Player)
extern struct X4_RideArmorObj D_800CD340;
extern u16 D_800E3142;
extern u16 D_800F35EC;

void func_800F0984(struct X4_PlayerObj* self) {
    struct X4_PlayerObj* pl;
    struct X4_RideArmorObj* ra;

    if (self->state == 0) {
        // !FAKE: depin: dropping it breaks the match (10/155)
        register s32 t asm("$4") = D_800E3142;
        D_800F35EC = t;
        func_800F04C0(t);
        func_800F089C();
        self->state++;
    }
    pl = (struct X4_PlayerObj*)&g_Player;
    if (pl->nova_strike_active == 2) {
        return;
    }
    if (pl->unk5 == 0x14) {
        if (self->bg_offset != 0) {
            play_sound(5, 3, 0);
            self->bg_offset = 0;
        }
        return;
    }
    if (D_80097202 >= 0xAC0) {
        play_sound(5, 3, 0);
        ((M2C_UNK(*)())clear_object_slot)(self);
        return;
    }
    if (self->bg_offset == 0 || *(s16*)((u8*)pl + 0x14C) != 0) {
        play_sound(5, 6, 0);
        self->bg_offset = 1;
    }
    func_800F0754();
    // u32 view on the head (docs/types/state.md): frame_counter (s32) signs the divide and moves bytes
    if (*(u32*)&D_80097420 == *(u32*)&D_80097420 / 5 * 5) {
        D_800F35EC++;
        func_800F089C(P);
    }
    if (P->unk5 != 0x14 && pl->state == 1 && pl->hp != 0) {
        if (P->unk68 != 0) {
            if (func_80030234(
                    pl, pl->x_pos.i.hi,
                    (s16)(pl->unk68->unk1 + (pl->y_pos.i.hi + pl->unk68->unk3)),
                    pl->unk68) == 0x3A) {
                pl->x_pos.i.hi--;
            }
        }
        ra = &D_800CD340;
        if (ra->unk68 != 0 && !(ra->unk70 & 2) &&
            func_80030234(ra, ra->x_pos.i.hi,
                          (s16)(ra->unk68->unk1 +
                                (ra->y_pos.i.hi + ra->unk68->unk3))) == 0x3A) {
            ra->x_pos.i.hi--;
        }
    }
}
#undef P

#define func_800ECAB8 func_800F0BF0
#define D_800C1220 D_800C1220
#include "../shared/rock_06/func_800ECAB8.c"
#undef func_800ECAB8
#undef D_800C1220

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F0D24);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F0FAC);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F11D4);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F1BE8);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F1DD4);

INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F2188);
// clang-format on

#define func_800F3BF8 func_800F21E8
#define D_800FC6A8 D_800F3578
#include "../shared/rock_10/func_800F3BF8.c"
#undef func_800F3BF8
#undef D_800FC6A8

#define func_800EA750 func_800F2288
#include "../shared/rock_11/func_800EA750.c"
#undef func_800EA750

// clang-format off
INCLUDE_ASM("asm/rock_28/nonmatchings/E9860", func_800F2290);
// clang-format on
