#define func_80041AB8 func_800FBA40
#define D_80075FD8 D_800FEC48
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_800F2F24 func_800FBA7C
#define g_Player g_Player
#include "../shared/rock_04/func_800F2F24.c"
#undef func_800F2F24
#undef g_Player

#define func_800F2FB0 func_800FBB08
#include "../shared/rock_04/func_800F2FB0.c"
#undef func_800F2FB0

#define func_800F30A4 func_800FBBFC
#define D_800F767C D_800FED74
#include "../shared/rock_04/func_800F30A4.c"
#undef func_800F30A4
#undef D_800F767C

#define func_800F311C func_800FBC74
#include "../shared/rock_04/func_800F311C.c"
#undef func_800F311C

#define func_800F3154 func_800FBCAC
#include "../shared/rock_04/func_800F3154.c"
#undef func_800F3154

#define func_800F31A4 func_800FBCFC
#define D_800F7684 D_800FED7C
#include "../shared/rock_04/func_800F31A4.c"
#undef func_800F31A4
#undef D_800F7684

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FBDC4);

INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FBE4C);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FBEC0(void) {
    clear_object_slot();
}

#define func_8003744C func_800FBEE0
#define D_80073C1C D_800FEC54
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F33C4 func_800FBF1C
#include "../shared/rock_04/func_800F33C4.c"
#undef func_800F33C4

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FBF58);
// clang-format on

#define func_8003744C func_800FBF94
#define D_80073C1C D_800FEC5C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FBFD0);
// clang-format on

#define func_800F5488 func_800FDFE0
#define func_800F34B4 func_800FC00C
#include "../shared/rock_04/func_800F34B4.c"
#undef func_800F34B4
#undef func_800F5488

#define func_800F351C func_800FC074
#include "../shared/rock_04/func_800F351C.c"
#undef func_800F351C

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FC158);
// clang-format on

#define func_8003744C func_800FC1A0
#define D_80073C1C D_800FEC6C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FC1DC);
// clang-format on

#define func_800F36C8 func_800FC220
#include "../shared/rock_04/func_800F36C8.c"
#undef func_800F36C8

#define func_800F372C func_800FC284
#include "../shared/rock_04/func_800F372C.c"
#undef func_800F372C

#define func_800F378C func_800FC2E4
#include "../shared/rock_04/func_800F378C.c"
#undef func_800F378C

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FC358);
// clang-format on

#define func_8003744C func_800FC394
#define D_80073C1C D_800FEC84
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F3878 func_800FC3D0
#include "../shared/rock_04/func_800F3878.c"
#undef func_800F3878

#define func_800F38B4 func_800FC40C
#include "../shared/rock_04/func_800F38B4.c"
#undef func_800F38B4

#define func_800F39D8 func_800FC530
#define g_Player g_Player
#include "../shared/rock_04/func_800F39D8.c"
#undef func_800F39D8
#undef g_Player

#define func_800F3A2C func_800FC584
#define g_Player g_Player
#include "../shared/rock_04/func_800F3A2C.c"
#undef func_800F3A2C
#undef g_Player

#define func_800F3B28 func_800FC680
#include "../shared/rock_04/func_800F3B28.c"
#undef func_800F3B28

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FC714(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x1770;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800F3BE0 func_800FC738
#include "../shared/rock_04/func_800F3BE0.c"
#undef func_800F3BE0

#define func_800F3C44 func_800FC79C
#include "../shared/rock_04/func_800F3C44.c"
#undef func_800F3C44

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FC7D8);
// clang-format on

#define func_8003744C func_800FC814
#define D_80073C1C D_800FECAC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5488 func_800FDFE0
#define func_800F3CF8 func_800FC850
#include "../shared/rock_04/func_800F3CF8.c"
#undef func_800F3CF8
#undef func_800F5488

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FC89C);

INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FC984);
// clang-format on

#define func_8003744C func_800FC9CC
#define D_80073C1C D_800FECBC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FCA08);

INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FCA44);
// clang-format on

#define func_800F3F94 func_800FCAEC
#include "../shared/rock_04/func_800F3F94.c"
#undef func_800F3F94

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FCBB0);
// clang-format on

#define func_8003744C func_800FCBEC
#define D_80073C1C D_800FECD4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F40D0 func_800FCC28
#define D_800F75F0 D_800FECE8
#include "../shared/rock_04/func_800F40D0.c"
#undef func_800F40D0
#undef D_800F75F0

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FCC64);
// clang-format on

#define func_800F4150 func_800FCCA8
#include "../shared/rock_04/func_800F4150.c"
#undef func_800F4150

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FCCDC);
// clang-format on

#define func_8003744C func_800FCD18
#define D_80073C1C D_800FECF4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FCD54);
// clang-format on

#define func_800F4238 func_800FCD90
#include "../shared/rock_04/func_800F4238.c"
#undef func_800F4238

#define func_800F5488 func_800FDFE0
#define func_800F4324 func_800FCE7C
#include "../shared/rock_04/func_800F4324.c"
#undef func_800F4324
#undef func_800F5488

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800FB0F8(); /* extern */

void func_800FCEEC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_800FB0F8();
    }
}

#define func_8003744C func_800FCF1C
#define D_80073C1C D_800FED04
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F4400 func_800FCF58
#define D_800F7620 D_800FED18
#include "../shared/rock_04/func_800F4400.c"
#undef func_800F4400
#undef D_800F7620

#define func_800F5488 func_800FDFE0
#define func_800F442C func_800FCF84
#include "../shared/rock_04/func_800F442C.c"
#undef func_800F442C
#undef func_800F5488

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FCFD4);
// clang-format on

#define func_800F4150 func_800FD0A0
#include "../shared/rock_04/func_800F4150.c"
#undef func_800F4150

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FD0D4);
// clang-format on

#define func_8003744C func_800FD110
#define D_80073C1C D_800FED1C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F45F4 func_800FD14C
#include "../shared/rock_04/func_800F45F4.c"
#undef func_800F45F4

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FD1BC);
// clang-format on

#define func_800F3F94 func_800FD264
#include "../shared/rock_04/func_800F3F94.c"
#undef func_800F3F94

#define func_800F47D0 func_800FD328
#include "../shared/rock_04/func_800F47D0.c"
#undef func_800F47D0

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FD3F0);
// clang-format on

#define func_8003744C func_800FD42C
#define D_80073C1C D_800FED34
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800FD468(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800F4948 func_800FD4A0
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_04/func_800F4948.c"
#undef func_800F4948
#undef g_playthrough_state

#define func_800F49E4 func_800FD53C
#include "../shared/rock_04/func_800F49E4.c"
#undef func_800F49E4

#define func_800F4AB4 func_800FD60C
#include "../shared/rock_04/func_800F4AB4.c"
#undef func_800F4AB4

#define func_800F4B2C func_800FD684
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_04/func_800F4B2C.c"
#undef func_800F4B2C
#undef g_playthrough_state

#define func_800F4BA8 func_800FD700
#include "../shared/rock_04/func_800F4BA8.c"
#undef func_800F4BA8

#define func_800F4BEC func_800FD744
#include "../shared/rock_04/func_800F4BEC.c"
#undef func_800F4BEC

#define func_800F4C68 func_800FD7C0
#include "../shared/rock_04/func_800F4C68.c"
#undef func_800F4C68

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FD878(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F4D48 func_800FD8A0
#include "../shared/rock_04/func_800F4D48.c"
#undef func_800F4D48

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();    /* extern */
M2C_UNK func_800FB0F8(s32); /* extern */

void func_800FD924(s32 arg0) {
    func_8003D330();
    func_800FB0F8(arg0);
}

#define func_8003744C func_800FD950
#define D_80073C1C D_800FED64
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F4E34 func_800FD98C
#include "../shared/rock_04/func_800F4E34.c"
#undef func_800F4E34

#define func_800F4EB0 func_800FDA08
#include "../shared/rock_04/func_800F4EB0.c"
#undef func_800F4EB0

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FDA64(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FDA7C);
// clang-format on

#include "common.h"

void func_800FDB28(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FDB30);
// clang-format on

#define func_800F5088 func_800FDBE0
#include "../shared/rock_04/func_800F5088.c"
#undef func_800F5088

#define func_800F513C func_800FDC94
#include "../shared/rock_04/func_800F513C.c"
#undef func_800F513C

#define func_800F51F0 func_800FDD48
#include "../shared/rock_04/func_800F51F0.c"
#undef func_800F51F0

#define func_800F52AC func_800FDE04
#include "../shared/rock_04/func_800F52AC.c"
#undef func_800F52AC

#define func_800F5360 func_800FDEB8
#include "../shared/rock_04/func_800F5360.c"
#undef func_800F5360

#define func_80042C18 func_800FDFE0
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#define func_800F54B8 func_800FE010
#include "../shared/rock_04/func_800F54B8.c"
#undef func_800F54B8

#define func_80048DC8 func_800FE050
#define D_80077BC0 D_800FEDA4
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FE09C(void) {
    clear_object_slot();
}

#define func_8003744C func_800FE0BC
#define D_80073C1C D_800FEDBC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002D230(); /* extern */

void func_800FE0F8(void) {
    func_8002D230();
}

#define func_8003744C func_800FE118
#define D_80073C1C D_800FEDCC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FE154);
// clang-format on

#define func_8003744C func_800FE1E8
#define D_80073C1C D_800FEDC4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F56CC func_800FE224
#include "../shared/rock_04/func_800F56CC.c"
#undef func_800F56CC

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FE264);
// clang-format on

#define func_800F5788 func_800FE2E0
#include "../shared/rock_04/func_800F5788.c"
#undef func_800F5788

#define func_800F5888 func_800FE3E0
#define D_800F76E8 D_800FEDE0
#include "../shared/rock_04/func_800F5888.c"
#undef func_800F5888
#undef D_800F76E8

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FE478(void) {
    clear_object_slot();
}

#define func_800F5940 func_800FE498
#include "../shared/rock_04/func_800F5940.c"
#undef func_800F5940

#define func_80041AB8 func_800FE4F4
#define D_80075FD8 D_800FEDD4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800F59D8 func_800FE530
#include "../shared/rock_04/func_800F59D8.c"
#undef func_800F59D8

#define func_800F5A94 func_800FE5EC
#include "../shared/rock_04/func_800F5A94.c"
#undef func_800F5A94

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FE6A8);
// clang-format on
