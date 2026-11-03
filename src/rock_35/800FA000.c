// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", D_800FA000);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FA014);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FA38C);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FA848);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FAB48);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FACA8);
// clang-format on

#define func_800EF6D0 func_800FAE1C
#include "../shared/rock_05/func_800EF6D0.c"
#undef func_800EF6D0

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FAF20);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FB104);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FB220);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FB3F4);
// clang-format on

#define func_800EFE14 func_800FB560
#include "../shared/rock_05/func_800EFE14.c"
#undef func_800EFE14

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FB708);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FB948);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FBA64);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FBB54);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FBC18);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FBE3C);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FC630);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FCAD0);
// clang-format on

#define func_800F13E0 func_800FCB2C
#include "../shared/rock_05/func_800F13E0.c"
#undef func_800F13E0

#define func_8003744C func_800FCC20
#define D_80073C1C D_800FE8BC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800FCC5C(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FCC94);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FCD50);
// clang-format on

#define func_800F1678 func_800FCDC4
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_05/func_800F1678.c"
#undef func_800F1678
#undef g_playthrough_state

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FCE28);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */
s32 func_80040498();                   /* extern */

void func_800FCE78(void* arg0) {
    animate_object();
    if (func_80040498() == 0) {
        set_animation(arg0, 1);
        D_80097240 = 2;
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FCED4);
// clang-format on

#define func_8003744C func_800FCF9C
#define D_80073C1C D_800FE8DC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F188C func_800FCFD8
#include "../shared/rock_05/func_800F188C.c"
#undef func_800F188C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*); /* extern */
M2C_UNK move_object(void*);    /* extern */

void func_800FD024(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 1) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    animate_object(arg0);
    move_object(arg0);
}

#define func_800F1930 func_800FD07C
#include "../shared/rock_05/func_800F1930.c"
#undef func_800F1930

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FD0F4);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FD144);
// clang-format on

#define func_8003744C func_800FD210
#define D_80073C1C D_800FE8F8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F1B00 func_800FD24C
#include "../shared/rock_05/func_800F1B00.c"
#undef func_800F1B00

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FD290);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FD2D4);
// clang-format on

#define func_800F1C48 func_800FD394
#include "../shared/rock_05/func_800F1C48.c"
#undef func_800F1C48

#define func_8003744C func_800FD3F8
#define D_80073C1C D_800FE908
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F2B4C func_800FE298
#define func_800F1CE8 func_800FD434
#include "../shared/rock_05/func_800F1CE8.c"
#undef func_800F1CE8
#undef func_800F2B4C

#define func_800F1D4C func_800FD498
#include "../shared/rock_05/func_800F1D4C.c"
#undef func_800F1D4C

#define func_800F1E60 func_800FD5AC
#include "../shared/rock_05/func_800F1E60.c"
#undef func_800F1E60

#define func_8003744C func_800FD628
#define D_80073C1C D_800FE91C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F1F18 func_800FD664
#include "../shared/rock_05/func_800F1F18.c"
#undef func_800F1F18

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FD6B0);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FD77C);
// clang-format on

#define func_800F20D8 func_800FD824
#include "../shared/rock_05/func_800F20D8.c"
#undef func_800F20D8

#define func_800F213C func_800FD888
#include "../shared/rock_05/func_800F213C.c"
#undef func_800F213C

#define D_800F4480 D_800FE9A8
#define func_800F21AC func_800FD8F8
#include "../shared/rock_05/func_800F21AC.c"
#undef func_800F21AC
#undef D_800F4480

#define D_800F4148 D_800FE670
#define func_800F2218 func_800FD964
#include "../shared/rock_05/func_800F2218.c"
#undef func_800F2218
#undef D_800F4148

#define func_800F2284 func_800FD9D0
#include "../shared/rock_05/func_800F2284.c"
#undef func_800F2284

#define func_8003744C func_800FDA34
#define D_80073C1C D_800FE93C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F2324 func_800FDA70
#include "../shared/rock_05/func_800F2324.c"
#undef func_800F2324

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FDAFC);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FDBC4);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FDCAC);
// clang-format on

#define func_8003744C func_800FDD54
#define D_80073C1C D_800FE958
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
s32 random_byte();                     /* extern */
extern s16 D_800FE9A8;

void func_800FDD90(void* arg0) {
    s32 temp_v0;
    s32 temp_v1;

    M2C_FIELD(arg0, s16*, 0x7E) = (s16)((random_byte() & 1) + 1);
    temp_v1 = M2C_FIELD(arg0, s16*, 0xE) - 0x460;
    temp_v0 = temp_v1 - D_800FE9A8;
    if (temp_v0 >= 0) {
        if (temp_v0 < 0x11) {

        } else {
            // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
            goto block_4;
        }
    } else if ((D_800FE9A8 - temp_v1) >= 0x11) {
    block_4:
        set_animation(arg0, 4);
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFB0000;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define D_800F4480 D_800FE9A8
#define func_800F26D4 func_800FDE20
#include "../shared/rock_05/func_800F26D4.c"
#undef func_800F26D4
#undef D_800F4480

#define func_800F2B4C func_800FE298
#define func_800F272C func_800FDE78
#include "../shared/rock_05/func_800F272C.c"
#undef func_800F272C
#undef func_800F2B4C

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FDEE4);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
void func_800FE298();                  /* extern */

void func_800FDFAC(void* arg0) {
    func_800FE298();
    set_animation(arg0, 3);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0x50000;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FDFF8);

INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FE0BC);
// clang-format on

#define func_8003744C func_800FE158
#define D_80073C1C D_800FE978
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F2A48 func_800FE194
#include "../shared/rock_05/func_800F2A48.c"
#undef func_800F2A48

#define D_800F4148 D_800FE670
#define func_800F2A9C func_800FE1E8
#include "../shared/rock_05/func_800F2A9C.c"
#undef func_800F2A9C
#undef D_800F4148

#define func_800F2AF0 func_800FE23C
#include "../shared/rock_05/func_800F2AF0.c"
#undef func_800F2AF0

#include "common.h"

extern s16 D_800970AA;

void func_800FE298(u8* e) {
    s16 x = *(s16*)(e + 0xA);

    if (D_800970AA < x) {
        e[0x15] = 0;
    } else {
        e[0x15] = 0x40;
    }
}

#include "common.h"

void func_800FE2C8(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FE2D0);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                       /* extern */
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(void*);                     /* extern */
s32 check_enemy_hits(void*);                    /* extern */
M2C_UNK func_80049D90(void*);                   /* extern */

void func_800FE32C(struct ObjectHeader* arg0) {
    ((M2C_UNK(*)())animate_object)();
    move_object(arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_80049D90(arg0);
        arg0->state = 2;
        return;
    }
    if (is_off_screen(arg0, 0x60, 0x60) == 0) {
        func_8002CCB0(arg0, 0x30, 0x30);
        return;
    }
    arg0->state = 2;
}

#define D_800F4480 D_800FE9A8
#define D_800F4484 D_800FE9AC
#define func_800F2C60 func_800FE3AC
#include "../shared/rock_05/func_800F2C60.c"
#undef func_800F2C60
#undef D_800F4480
#undef D_800F4484

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */
M2C_UNK apply_object_motion(void*);    /* extern */
s32 check_enemy_hits(void*);           /* extern */

void func_800FE414(void* arg0) {
    s8 temp_v1_2;
    u8 temp_v1;

    ((M2C_UNK(*)())animate_object)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x95);
    if (temp_v1 < 0x1EU) {
        M2C_FIELD(arg0, u8*, 0x95) = (u8)(temp_v1 + 1);
        return;
    }
    apply_object_motion(arg0);
    if (check_enemy_hits(arg0) < 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        set_animation(arg0, 9);
    }
    temp_v1_2 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1_2 == 2) {
        M2C_FIELD(arg0, s8*, 4) = temp_v1_2;
    }
    M2C_FIELD(arg0, s8*, 3) = 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                       /* extern */
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(void*);                     /* extern */
s32 check_enemy_hits(void*);                    /* extern */
M2C_UNK func_80049E50(void*);                   /* extern */

void func_800FE4B8(struct ObjectHeader* arg0) {
    ((M2C_UNK(*)())animate_object)();
    move_object(arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_80049E50(arg0);
        // !FAKE: goto shares the state = 2 store; a copied store with return moved bytes
        goto block_5;
    }
    if (is_off_screen(arg0, 0x60, 0x60) == 0) {
        func_8002CCB0(arg0, 0x30, 0x30);
        return;
    }
    arg0->on_screen = 0;
block_5:
    arg0->state = 2;
}

#define func_800F2DEC func_800FE538
#include "../shared/rock_05/func_800F2DEC.c"
#undef func_800F2DEC

#define func_800F2E84 func_800FE5D0
#define D_800F4458 D_800FE980
#include "../shared/rock_05/func_800F2E84.c"
#undef func_800F2E84
#undef D_800F4458

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FE64C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_35/nonmatchings/FA000", func_800FE66C);
// clang-format on
