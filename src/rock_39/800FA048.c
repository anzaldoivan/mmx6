// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FA048);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FA45C);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FA61C);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FA744);
// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object();
void func_800FBAAC(void*, M2C_UNK);
void func_800FF9AC(struct X4_AnimatedObj*);
extern struct X4_BackgroundObj background_objects[3];

#define OFS_X M2C_FIELD(arg0, s16*, 0x84)
#define OFS_Y M2C_FIELD(arg0, s16*, 0x86)
#define U6 M2C_FIELD(arg0, u8*, 6)
#define U7 M2C_FIELD(arg0, u8*, 7)
#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800FA924(struct X4_AnimatedObj* arg0) {
    s32 angle;
    s32 cnt;
    // !FAKE: depin: dropping it breaks the match (116/136)
    register s32 st asm("$2");

    angle =
        ratan2(arg0->y_pos.i.hi - (background_objects[0].y_pos.i.hi + OFS_Y),
               (background_objects[0].x_pos.i.hi + OFS_X) - arg0->x_pos.i.hi);
    arg0->x_vel.val = (rcos(angle) << 4) * (arg0->unk7 / 2 + 6);
    arg0->y_vel.val = (rsin(angle) << 4) * (arg0->unk7 / 2 + 6);
    if (arg0->x_vel.val >= 0) {
        arg0->unk15 = 0x40;
    } else {
        arg0->unk15 = 0;
    }
    ((void (*)(struct X4_AnimatedObj*))move_object)(arg0);
    if (ABS(OFS_X - (arg0->x_pos.i.hi - background_objects[0].x_pos.i.hi)) <
        6) {
        if (ABS(OFS_Y - (arg0->y_pos.i.hi - background_objects[0].y_pos.i.hi)) <
            6) {
            play_sound(2, 0x55, arg0);
            func_80012D9C(6);
            arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + OFS_X;
            arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + OFS_Y;
            cnt = U7 + 1;
            arg0->unk7 = cnt;
            if ((s8)cnt >= 8) {
                func_800FBAAC(arg0, 0);
                func_800FF9AC(arg0);
                set_animation(arg0, 0x14);
                arg0->unk7 = 0;
                st = U6 + 1;
            } else {
                if ((s8)cnt == 3) {
                    set_animation(arg0, 0);
                }
                st = U6 - 1;
            }
            arg0->unk6 = st;
        }
    }
}

#undef OFS_X
#undef OFS_Y
#undef U6
#undef U7
#undef ABS

#define func_800F4F9C func_800FAB44
#define background_objects background_objects
#include "../shared/rock_10/func_800F4F9C.c"
#undef func_800F4F9C
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FAC48);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FADB0);
// clang-format on

#define func_800F5378 func_800FAF20
#include "../shared/rock_10/func_800F5378.c"
#undef func_800F5378

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FB148);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FB428);
// clang-format on

#define func_800F5990 func_800FB538
#define D_800FCDE4 D_80100B58
#include "../shared/rock_10/func_800F5990.c"
#undef func_800F5990
#undef D_800FCDE4

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FB698);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FB900);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FBAAC);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FBC54);
// clang-format on

#define func_800F6484 func_800FC02C
#define D_800FCF50 D_80100CC4
#include "../shared/rock_10/func_800F6484.c"
#undef func_800F6484
#undef D_800FCF50

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FC184);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FC33C);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FC520);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_80097202;
extern u8 D_80100D18[][7];
extern u16 D_80100D28[][2];

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

void func_800FC704(struct X4_AnimatedObj* arg0) {
    s32 sw;
    s32 d;

    sw = D_80100D18[F(s8, 0x94)][arg0->unk7];
    switch (sw) {
    case 1:
        if ((F(s32, 0x84) & 0xF) == 0) {
            F(u16, 0x90) = D_80100D28[sw][0];
        } else {
            F(u16, 0x92) = D_80100D28[sw][1];
            d = D_800970AA - (s16)D_80097202;
            if (d < 0x21) {
                F(u16, 0x90) = 0x20;
            } else if (d >= 0x90) {
                F(u16, 0x90) = 0x90;
            } else {
                F(u16, 0x90) = (D_800970AA - D_80097202) & 0xFF0;
            }
        }
        F(u16, 0x92) = D_80100D28[sw][1];
        break;
    case 4:
        if ((F(s32, 0x84) & 0xF0) == 0) {
            F(u16, 0x90) = D_80100D28[sw][0];
        } else {
            F(u16, 0x92) = D_80100D28[sw][1];
            d = D_800970AA - (s16)D_80097202;
            if (d < 0xB1) {
                F(u16, 0x90) = 0xB0;
            } else if (d >= 0x110) {
                F(u16, 0x90) = 0x110;
            } else {
                F(u16, 0x90) = (D_800970AA - D_80097202) & 0xFF0;
            }
        }
        F(u16, 0x92) = D_80100D28[sw][1];
        break;
    case 2:
    case 3:
    case 5:
    case 6:
        F(u16, 0x90) = D_80100D28[sw][0];
        F(u16, 0x92) = D_80100D28[sw][1];
        break;
    case 0:
        F(u16, 0x90) = F(u16, 0x88) - background_objects[0].x_pos.i.hi;
        F(u16, 0x92) = F(u16, 0x8A) - background_objects[0].y_pos.i.hi;
        break;
    }
    arg0->unk6++;
}

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FC900);
// clang-format on

#define func_800F6F44 func_800FCAEC
#include "../shared/rock_10/func_800F6F44.c"
#undef func_800F6F44

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FCD9C);
// clang-format on

#define func_800F74D8 func_800FD080
#include "../shared/rock_10/func_800F74D8.c"
#undef func_800F74D8

#define func_800F765C func_800FD204
#include "../shared/rock_10/func_800F765C.c"
#undef func_800F765C

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FD348);
// clang-format on

#define func_800F78AC func_800FD454
#define D_800FCC60 D_801009D4
#include "../shared/rock_10/func_800F78AC.c"
#undef func_800F78AC
#undef D_800FCC60

#define func_80041AB8 func_800FD4D4
#define D_80075FD8 D_80100A1C
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_800F7968 func_800FD510
#define g_Player g_Player
#include "../shared/rock_10/func_800F7968.c"
#undef func_800F7968
#undef g_Player

#define func_800F2FB0 func_800FD59C
#include "../shared/rock_04/func_800F2FB0.c"
#undef func_800F2FB0

#define func_800F7AE8 func_800FD690
#define D_800FCDFC D_80100B70
#include "../shared/rock_10/func_800F7AE8.c"
#undef func_800F7AE8
#undef D_800FCDFC

#define func_800F7BF0 func_800FD798
#define D_800FCE10 D_80100B84
#include "../shared/rock_10/func_800F7BF0.c"
#undef func_800F7BF0
#undef D_800FCE10

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);               /* extern */

void func_800FD87C(void* arg0) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, s8*, 5) == 0) {
        M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x4200;
    }
    func_8002D230(arg0);
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
        M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
        if (temp_v0 & 1) {
            M2C_FIELD(arg0, s8*, 3) = 1;
            return;
        }
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 7;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FD918(void) {
    clear_object_slot();
}

#define func_8003744C func_800FD938
#define D_80073C1C D_80100A28
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F7DCC func_800FD974
#include "../shared/rock_10/func_800F7DCC.c"
#undef func_800F7DCC

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FD9CC);
// clang-format on

#define D_800FC734 func_801004A8
#define D_800FC738 D_801004AC
#define func_800F5D58 func_800FB900
#define func_800F7F00 func_800FDAA8
#define D_800FC734 D_801004A8
#include "../shared/rock_10/func_800F7F00.c"
#undef func_800F7F00
#undef D_800FC734
#undef D_800FC734
#undef D_800FC738
#undef func_800F5D58

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FDB18);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FDBA4);
// clang-format on

#define func_8003744C func_800FDC7C
#define D_80073C1C D_80100A3C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F9E04 func_800FF9AC
#define func_800F8110 func_800FDCB8
#include "../shared/rock_10/func_800F8110.c"
#undef func_800F8110
#undef func_800F9E04

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FDD04);
// clang-format on

#define D_800FC734 D_801004A8
#define D_800FC738 D_801004AC
#define func_800F821C func_800FDDC4
#define D_800FC734 D_801004A8
#include "../shared/rock_10/func_800F821C.c"
#undef func_800F821C
#undef D_800FC734
#undef D_800FC734
#undef D_800FC738

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FDE20);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800FB900(); /* extern */

void func_800FDF04(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_800FB900();
    }
}

#define func_8003744C func_800FDF34
#define D_80073C1C D_80100A88
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F83C8 func_800FDF70
#include "../shared/rock_10/func_800F83C8.c"
#undef func_800F83C8

#define D_800FC734 D_801004A8
#define D_800FC738 D_801004AC
#define func_800F8404 func_800FDFAC
#define D_800FC734 D_801004A8
#include "../shared/rock_10/func_800F8404.c"
#undef func_800F8404
#undef D_800FC734
#undef D_800FC734
#undef D_800FC738

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FE00C);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FE0B4);
// clang-format on

#define func_800F85C0 func_800FE168
#include "../shared/rock_10/func_800F85C0.c"
#undef func_800F85C0

#define func_800F862C func_800FE1D4
#include "../shared/rock_10/func_800F862C.c"
#undef func_800F862C

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FE2A0);
// clang-format on

#define func_800F8794 func_800FE33C
#define D_8007433C D_8007433C
#include "../shared/rock_10/func_800F8794.c"
#undef func_800F8794
#undef D_8007433C

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FE3F0);
// clang-format on

#define func_8003744C func_800FE42C
#define D_80073C1C D_80100AB0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F83C8 func_800FE468
#include "../shared/rock_10/func_800F83C8.c"
#undef func_800F83C8

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FE4A4);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FE564);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FE5D8);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800FB900(); /* extern */

void func_800FE6C4(void) {
    func_800FB900();
}

#define func_8003744C func_800FE6E4
#define D_80073C1C D_80100AC8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F83C8 func_800FE720
#include "../shared/rock_10/func_800F83C8.c"
#undef func_800F83C8

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FE75C);
// clang-format on

#define func_800F9E04 func_800FF9AC
#define D_800FC734 func_801004A8
#define D_800FC738 D_801004AC
#define func_800F8C74 func_800FE81C
#define D_800FC734 D_801004A8
#include "../shared/rock_10/func_800F8C74.c"
#undef func_800F8C74
#undef D_800FC734
#undef func_800F9E04
#undef D_800FC734
#undef D_800FC738

#define func_800F9EE4 func_800FFA8C
#define func_800F8CE0 func_800FE888
#include "../shared/rock_10/func_800F8CE0.c"
#undef func_800F8CE0
#undef func_800F9EE4

#define func_800F8D4C func_800FE8F4
#include "../shared/rock_10/func_800F8D4C.c"
#undef func_800F8D4C

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FE954);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FEA58);
// clang-format on

#define func_800F8F60 func_800FEB08
#define D_8007433C D_8007433C
#include "../shared/rock_10/func_800F8F60.c"
#undef func_800F8F60
#undef D_8007433C

#define func_800F8FD0 func_800FEB78
#include "../shared/rock_10/func_800F8FD0.c"
#undef func_800F8FD0

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FEBE4);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_8007433C;
extern M2C_UNK D_801004AC;
extern M2C_UNK func_801004A8;

void func_800FEC20(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1 == 1) {
        M2C_FIELD(arg0, s8*, 0x8E) = temp_v1;
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, s8*, 0x60) = 0xA;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &func_801004A8;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_801004AC;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, s8*, 6) = 9;
    }
}

#define func_8003744C func_800FEC74
#define D_80073C1C D_80100AF8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F83C8 func_800FECB0
#include "../shared/rock_10/func_800F83C8.c"
#undef func_800F83C8

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FECEC);
// clang-format on

#define func_800F9E04 func_800FF9AC
#define D_800FC738 D_801004AC
#define func_800F9204 func_800FEDAC
#define D_800FC734 D_801004A8
#include "../shared/rock_10/func_800F9204.c"
#undef func_800F9204
#undef D_800FC734
#undef func_800F9E04
#undef D_800FC738

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FEE1C);
// clang-format on

#define func_800F9370 func_800FEF18
#include "../shared/rock_10/func_800F9370.c"
#undef func_800F9370

#define D_800FC734 func_801004A8
#define D_800FC738 D_801004AC
#define func_800F93C4 func_800FEF6C
#define D_800FC734 D_801004A8
#include "../shared/rock_10/func_800F93C4.c"
#undef func_800F93C4
#undef D_800FC734
#undef D_800FC734
#undef D_800FC738

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800FB900(); /* extern */

void func_800FEFD4(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x16) = 5;
    func_800FB900();
}

#define func_8003744C func_800FEFF8
#define D_80073C1C D_80100B1C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800FF034(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800F94C4 func_800FF06C
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_10/func_800F94C4.c"
#undef func_800F94C4
#undef g_playthrough_state

#define func_800F5F04 func_800FBAAC
#define func_800F955C func_800FF104
#include "../shared/rock_10/func_800F955C.c"
#undef func_800F955C
#undef func_800F5F04

#define func_800F95CC func_800FF174
#include "../shared/rock_10/func_800F95CC.c"
#undef func_800F95CC

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FF1BC);
// clang-format on

#define func_800F9668 func_800FF210
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_10/func_800F9668.c"
#undef func_800F9668
#undef g_playthrough_state

#define func_800F4BA8 func_800FF284
#include "../shared/rock_04/func_800F4BA8.c"
#undef func_800F4BA8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80040498(); /* extern */

void func_800FF2C8(void* arg0) {
    if (func_80040498() == 0) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F4D48 func_800FF304
#include "../shared/rock_04/func_800F4D48.c"
#undef func_800F4D48

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();    /* extern */
M2C_UNK func_800FB900(s32); /* extern */

void func_800FF388(s32 arg0) {
    func_8003D330();
    func_800FB900(arg0);
}

#define func_8003744C func_800FF3B4
#define D_80073C1C D_80100B48
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FF3F0);
// clang-format on

#define func_800F990C func_800FF4B4
#include "../shared/rock_10/func_800F990C.c"
#undef func_800F990C

#define func_80041FB0 func_800FF570
#include "../shared/SLUS_013.95/func_80041FB0.c"
#undef func_80041FB0

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800FB900(); /* extern */

void func_800FF5A4(void) {
    ((M2C_UNK(*)())func_800FB900)();
}

#define D_800FC758 D_801004CC
#define D_800FC75C D_801004D0
#define func_800F9A1C func_800FF5C4
#define D_800FC758 D_801004CC
#include "../shared/rock_10/func_800F9A1C.c"
#undef func_800F9A1C
#undef D_800FC758
#undef D_800FC758
#undef D_800FC75C

#define D_800FD004 D_80100D64
#define func_800F9A80 func_800FF628
#include "../shared/rock_10/func_800F9A80.c"
#undef func_800F9A80
#undef D_800FD004

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FCAEC(void* arg0, s32 arg1); /* extern */

void func_800FF684(void* arg0) {
    s8 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        temp_v1 = M2C_FIELD(arg0, s8*, 2);
        switch (temp_v1) { /* irregular */
        case 16:
            func_800FCAEC(arg0, 0x10);
            break;
        case 17:
            func_800FCAEC(arg0, 0x11);
            break;
        case 18:
            func_800FCAEC(arg0, 0x12);
            break;
        case 19:
            func_800FCAEC(arg0, 0x13);
            break;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FF74C);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FF838(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) == 2) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#define D_80097202 D_80097202_s16
#define func_800F9CC4 func_800FF86C
#include "../shared/rock_10/func_800F9CC4.c"
#undef func_800F9CC4
#undef D_80097202

#define func_800F9D18 func_800FF8C0
#include "common.h"

extern u16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)

void func_800FF8C0(u8* arg0) {
    u8* p = *(u8**)(arg0 + 0x80);
    u16 g = D_80097202;
    s32 t = *(u16*)(p + 0xA) - g;

    t -= 0x140;
    *(s16*)(arg0 + 0xA) = g - t;
    *(u16*)(arg0 + 0xE) = *(u16*)(p + 0xE);
}
#undef D_80097202
#undef func_800F9D18

#define func_800F74D8 func_800FD080
#define func_800F9D48 func_800FF8F0
#include "../shared/rock_10/func_800F9D48.c"
#undef func_800F9D48
#undef func_800F74D8

#define func_800F6F44 func_800FCAEC
#define func_800F9DA8 func_800FF950
#include "../shared/rock_10/func_800F9DA8.c"
#undef func_800F9DA8
#undef func_800F6F44

#define func_800F32A8 func_800FF9AC
#include "../shared/rock_08/func_800F32A8.c"
#undef func_800F32A8

#include "common.h"

void func_800FF9DC(void) {
}

#define func_800F9E3C func_800FF9E4
#include "../shared/rock_10/func_800F9E3C.c"
#undef func_800F9E3C

#define func_800F9EE4 func_800FFA8C
#include "../shared/rock_10/func_800F9EE4.c"
#undef func_800F9EE4

#define func_800F54B8 func_800FFB4C
#include "../shared/rock_04/func_800F54B8.c"
#undef func_800F54B8

#define func_80048DC8 func_800FFB8C
#define D_80077BC0 D_80100CB4
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);               /* extern */

void func_800FFBD8(void* arg0) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, s8*, 5) == 0) {
        M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        M2C_FIELD(arg0, u16*, 0x88) = 0U;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x4200;
    }
    func_8002D230(arg0);
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        temp_v0 = M2C_FIELD(arg0, u16*, 0x88);
        M2C_FIELD(arg0, u16*, 0x88) = (u16)(temp_v0 + 1);
        if (temp_v0 & 1) {
            M2C_FIELD(arg0, s8*, 3) = 1;
            return;
        }
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 3;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FFC74(void) {
    clear_object_slot();
}

#define func_8003744C func_800FFC94
#define D_80073C1C D_80100CE0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FFCD0);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FFD5C);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FFDD8);

INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_800FFE58);
// clang-format on

#define func_8003744C func_800FFEE8
#define D_80073C1C D_80100CF4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800FA37C func_800FFF24
#include "../shared/rock_10/func_800FA37C.c"
#undef func_800FA37C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FFF7C(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 6) == 8) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FFFB0(void* arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 7) = 4;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = 3;
}

#define func_8003744C func_800FFFD4
#define D_80073C1C D_80100D08
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800FA468 func_80100010
#include "common.h"

s32 random_byte();
extern u16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)

void func_80100010(u8* arg0) {
    u16 temp_a0;

    if (arg0[0x15] == 0) {
        arg0[0x94] = 0;
    } else {
        arg0[0x94] = 1;
    }
    {
        s32 a = *(u16*)(arg0 + 0xA);
        s32 g = D_80097202;
        // !FAKE: inherited from src/shared/rock_10/func_800FA468.c
        register s32 d asm("$2");
        temp_a0 = *(u16*)(arg0 + 0xE);
        *(s32*)(arg0 + 0x84) = 0;
        d = (a - g) - 0x140;
        *(s16*)(arg0 + 0x88) = g - d;
    }
    *(u16*)(arg0 + 0x8A) = temp_a0;
    if (random_byte(temp_a0) & 1) {
        *(s32*)(arg0 + 0x84) = 0;
    } else {
        *(s32*)(arg0 + 0x84) = 0xF;
    }
    if (!(random_byte() & 1)) {
        *(s32*)(arg0 + 0x84) |= 0xF0;
    }
    arg0[7] = 0;
    arg0[6]++;
}
#undef D_80097202
#undef func_800FA468

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_801000C4(struct ObjectHeader* arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 7) = 4;
    arg0->on_screen = 0;
    arg0->state = 3;
}

#define func_800FA538 func_801000E0
#include "common.h"
#include "mmx6/x4.h"

extern u16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)

void func_801000E0(struct X4_MainObj* self) {
    struct X4_MainObj* p;

    p = *(struct X4_MainObj**)((u8*)self + 0x8C);
    {
        s32 d = (p->x_pos.u.hi - D_80097202) - 0x140;
        self->x_pos.i.hi = D_80097202 - d;
    }
    self->y_pos.i.hi = p->y_pos.i.hi;
    self->animation_step.fields.frame_index =
        p->animation_step.fields.frame_index;
    self->on_screen = p->on_screen;
    if (p->unk15 == 0) {
        self->unk15 = 0x40;
    } else {
        self->unk15 = 0;
    }
    if (p->state != 1) {
        self->state = 3;
    }
}
#undef D_80097202
#undef func_800FA538

#define func_800FA5BC func_80100164
#include "../shared/rock_10/func_800FA5BC.c"
#undef func_800FA5BC

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_801001C4(void) {
    move_object();
}

#include "common.h"

void func_801001E4(void) {
}

#define func_800FA644 func_801001EC
#include "../shared/rock_10/func_800FA644.c"
#undef func_800FA644

#define func_800FA710 func_801002B8
#define D_800FCFE0 D_80100D54
#include "../shared/rock_10/func_800FA710.c"
#undef func_800FA710
#undef D_800FCFE0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80100340(void) {
    clear_object_slot();
}

#define func_800FA7B8 func_80100360
#include "../shared/rock_10/func_800FA7B8.c"
#undef func_800FA7B8

#define func_800FA81C func_801003C4
#include "../shared/rock_10/func_800FA81C.c"
#undef func_800FA81C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80100444(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

#define func_80041AB8 func_8010046C
#define D_80075FD8 D_80100D48
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_39/nonmatchings/FA000", func_801004A8);
// clang-format on
