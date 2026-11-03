// clang-format off
INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", D_800E9860);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800E98D4);
// clang-format on

#define func_800ED148 func_800E9AD8
#define g_Player g_Player
#include "../shared/rock_08/func_800ED148.c"
#undef func_800ED148
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800E9BE8);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800E9E40);
// clang-format on

#define func_800EA1D8 func_800E9F54
#define D_800FAA64 D_800EC3E0
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800E9FA0);
// clang-format on

#define func_800ED704 func_800EA094
#define D_800F5900 D_800EC3F0
#include "../shared/rock_08/func_800ED704.c"
#undef func_800ED704
#undef D_800F5900

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EA13C(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object();         /* extern */
M2C_UNK apply_object_motion(s32); /* extern */

void func_800EA17C(s32 arg0) {
    animate_object();
    apply_object_motion(arg0);
}

#define func_8003744C func_800EA1A8
#define D_80073C1C D_800EC490
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EF1E8 func_800EA1E4
#include "../shared/commander_yammark/func_800EF1E8.c"
#undef func_800EF1E8

#define func_800EF27C func_800EA278
#define D_80097420 D_80097420
#include "../shared/commander_yammark/func_800EF27C.c"
#undef func_800EF27C
#undef D_80097420

// clang-format off
INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EA2E0);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EA36C);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EA5CC);
// clang-format on

#define func_80048DC8 func_800EA7C0
#define D_80077BC0 D_800EC59C
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800EA80C(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    clear_object_slot();
}

#include "common.h"

void func_800EA82C(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EA834);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EA9BC);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EAB54);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EABD0(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*);                            /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800EABF0(void* arg0) {
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
    func_8002CA14(arg0);
}

#define func_800EAA18 func_800EAC84
#include "../shared/rock_05/func_800EAA18.c"
#undef func_800EAA18

#define func_800EAAA4 func_800EAD10
#include "../shared/rock_05/func_800EAAA4.c"
#undef func_800EAAA4

#define func_800EAADC func_800EAD48
#include "../shared/rock_05/func_800EAADC.c"
#undef func_800EAADC

// clang-format off
INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EAD94);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EAF64);
// clang-format on

#define func_80048DC8 func_800EB008
#define D_80077BC0 D_800EC638
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_80041AB8 func_800EB054
#define D_80075FD8 D_800EC644
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB090(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EB0B0);
// clang-format on

#define func_800EF6D4 func_800EB164
#define background_objects background_objects
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(s32, M2C_UNK, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK move_object(void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800EB164(void* arg0) {
    animate_object();
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xA) >= background_objects[0].x_pos.i.hi - 0x10 &&
        background_objects[0].y_pos.i.hi + 0x100 >=
            M2C_FIELD(arg0, s16*, 0xE) &&
        is_off_screen(arg0, 0x150, 0x30) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 2;
}
#undef func_800EF6D4
#undef background_objects

#define func_800EFEF8 func_800EB1FC
#include "../shared/commander_yammark/func_800EFEF8.c"
#undef func_800EFEF8

// clang-format off
INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EB2A0);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EB4A4);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EB698);
// clang-format on

#define func_80048DC8 func_800EB81C
#define D_80077BC0 D_800EC790
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002CA14(void*);                /* extern */

void func_800EB868(struct ObjectHeader* arg0) {
    play_sound(2, 0x54, arg0);
    arg0->on_screen = 0;
    func_8002CA14(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EB8A4);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EB918);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EB9C0);
// clang-format on

#define func_800EF960 func_800EBAC4
#define g_Player g_Player
#include "../shared/rock_08/func_800EF960.c"
#undef func_800EF960
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EBB74);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EBBF4);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EC418);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EC438);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EC458);

INCLUDE_ASM("asm/rock_29/nonmatchings/E9860", func_800EC478);
// clang-format on
