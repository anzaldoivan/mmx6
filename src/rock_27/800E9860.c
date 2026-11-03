// clang-format off
INCLUDE_ASM("asm/rock_27/nonmatchings/E9860", D_800E9860);
// clang-format on

#define func_800E98C0 func_800E987C
#define D_800F3CF8 D_800EB40C
#include "../shared/rock_05/func_800E98C0.c"
#undef func_800E98C0
#undef D_800F3CF8

// clang-format off
INCLUDE_ASM("asm/rock_27/nonmatchings/E9860", func_800E99C0);

INCLUDE_ASM("asm/rock_27/nonmatchings/E9860", func_800E9B28);
// clang-format on

#define func_80041AB8 func_800E9C78
#define D_80075FD8 D_800EB400
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_27/nonmatchings/E9860", func_800E9CB4);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800E9D7C(void) {
    func_8002CA54();
}

#include "common.h"

void func_800E9D9C(void) {
}

#define func_8003744C func_800E9DA4
#define D_80073C1C D_800EB42C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800E9E24 func_800E9DE0
#include "../shared/rock_05/func_800E9E24.c"
#undef func_800E9E24

#define func_800E9E80 func_800E9E3C
#include "../shared/rock_05/func_800E9E80.c"
#undef func_800E9E80

#define func_8003744C func_800E9E68
#define D_80073C1C D_800EB41C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800E9EE8 func_800E9EA4
#include "../shared/rock_05/func_800E9EE8.c"
#undef func_800E9EE8

// clang-format off
INCLUDE_ASM("asm/rock_27/nonmatchings/E9860", func_800E9F90);

INCLUDE_ASM("asm/rock_27/nonmatchings/E9860", func_800EA038);
// clang-format on

#define func_800EA224 func_800EA1E0
#define g_Player g_Player
#include "../shared/rock_05/func_800EA224.c"
#undef func_800EA224
#undef g_Player

#define func_80048DC8 func_800EA390
#define D_80077BC0 D_800EB45C
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_800EA420 func_800EA3DC
#define D_800F3D58 D_800EB46C
#include "../shared/rock_05/func_800EA420.c"
#undef func_800EA420
#undef D_800F3D58

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EA4D8(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800EA4F8(void* arg0) {
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
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();   /* extern */
M2C_UNK move_object(void*); /* extern */

void func_800EA54C(struct MainObj* arg0) {
    arg0->x_speed = 0;
    arg0->y_speed = 0x50000;
    animate_object();
    move_object(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_27/nonmatchings/E9860", func_800EA584);

INCLUDE_ASM("asm/rock_27/nonmatchings/E9860", func_800EA70C);

INCLUDE_ASM("asm/rock_27/nonmatchings/E9860", func_800EA8A4);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EA920(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*);                            /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800EA940(void* arg0) {
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

#define func_800EAA18 func_800EA9D4
#include "../shared/rock_05/func_800EAA18.c"
#undef func_800EAA18

#define func_800EAAA4 func_800EAA60
#include "../shared/rock_05/func_800EAAA4.c"
#undef func_800EAAA4

#define func_800EAADC func_800EAA98
#include "../shared/rock_05/func_800EAADC.c"
#undef func_800EAADC

// clang-format off
INCLUDE_ASM("asm/rock_27/nonmatchings/E9860", D_800EAAE4);
// clang-format on
