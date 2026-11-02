#include "common.h"

void func_800FEA04(void) {
}

#define func_8003744C func_800FEA0C
#define D_80073C1C D_80100A48
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();               /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */
extern s8 D_800970A5;
extern s8 D_8009723F;

void func_800FEA48(void* arg0) {
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

#define func_800F4220 func_800FEAE0
#include "../shared/commander_yammark/func_800F4220.c"
#undef func_800F4220

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FEB98);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FECB4);
// clang-format on

#define func_800F44A4 func_800FED64
#include "../shared/commander_yammark/func_800F44A4.c"
#undef func_800F44A4

#define func_800F4508 func_800FEDC8
#include "../shared/commander_yammark/func_800F4508.c"
#undef func_800F4508

#define func_800F4588 func_800FEE48
#include "../shared/commander_yammark/func_800F4588.c"
#undef func_800F4588

#define func_800F4674 func_800FEF34
#define D_800F7C30 D_80100A64
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#include "common.h"

void func_800FEF98(void) {
}

#define func_800F4674 func_800FEFA0
#define D_800F7C30 D_80100A68
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FF004);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_80100C40;
extern s16 D_80100C44;

void func_800FF0E4(void* arg0) {
    if (D_80100C40 == D_80100C44) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FF118);
// clang-format on

#define D_800F7E0E D_80100C42
#define func_800F48A8 func_800FF168
#include "../shared/commander_yammark/func_800F48A8.c"
#undef func_800F48A8
#undef D_800F7E0E

#define func_800F48EC func_800FF1AC
#define D_800F7BA0 D_801009D4
#include "../shared/commander_yammark/func_800F48EC.c"
#undef func_800F48EC
#undef D_800F7BA0

#define func_800F4674 func_800FF240
#define D_800F7C30 D_80100A84
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FF2A4);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_80100C40;
extern s16 D_80100C44;

void func_800FF384(void* arg0) {
    if (D_80100C40 == D_80100C44) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FF3B8);
// clang-format on

#define D_800F7E0E D_80100C42
#define func_800F4B48 func_800FF408
#include "../shared/commander_yammark/func_800F4B48.c"
#undef func_800F4B48
#undef D_800F7E0E

#define func_800F4674 func_800FF458
#define D_800F7C30 D_80100AA0
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FF4BC);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_80100C40;
extern s16 D_80100C44;

void func_800FF59C(void* arg0) {
    if (D_80100C40 == D_80100C44) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FF5D0);
// clang-format on

#define D_800F7BA0 D_801009D4
#define D_800F7E0E D_80100C42
#define func_800F4D70 func_800FF630
#define D_800F7BA0 D_801009D4
#include "../shared/commander_yammark/func_800F4D70.c"
#undef func_800F4D70
#undef D_800F7BA0
#undef D_800F7BA0
#undef D_800F7E0E

#define func_800F4674 func_800FF6A0
#define D_800F7C30 D_80100ABC
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FF704);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_80100C40;
extern s16 D_80100C44;

void func_800FF7E4(void* arg0) {
    if (D_80100C40 == D_80100C44) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FF818);
// clang-format on

#define func_800F4FB8 func_800FF878
#include "../shared/commander_yammark/func_800F4FB8.c"
#undef func_800F4FB8

#define func_800F5048 func_800FF908
#define D_800F7BA0 D_801009D4
#include "../shared/commander_yammark/func_800F5048.c"
#undef func_800F5048
#undef D_800F7BA0

#define func_800F5108 func_800FF9C8
#include "../shared/commander_yammark/func_800F5108.c"
#undef func_800F5108

#define func_800F4674 func_800FFA3C
#define D_800F7C30 D_80100ADC
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FFAA0);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_80100C40;
extern s16 D_80100C44;

void func_800FFB80(void* arg0) {
    if (D_80100C40 == D_80100C44) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define D_800F7E0C D_80100C40
#define D_800F7E0E D_80100C42
#define func_800F52F4 func_800FFBB4
#include "../shared/commander_yammark/func_800F52F4.c"
#undef func_800F52F4
#undef D_800F7E0C
#undef D_800F7E0E

#define func_800F5358 func_800FFC18
#define D_800F7CC0 D_80100AF4
#include "../shared/commander_yammark/func_800F5358.c"
#undef func_800F5358
#undef D_800F7CC0

#define func_800F53D4 func_800FFC94
#include "../shared/commander_yammark/func_800F53D4.c"
#undef func_800F53D4

#define D_800F7954 D_80100788
#define D_800F7DE8 D_80100C1C
#define func_800F5434 func_800FFCF4
#define D_800F7954 D_80100788
#include "../shared/commander_yammark/func_800F5434.c"
#undef func_800F5434
#undef D_800F7954
#undef D_800F7954
#undef D_800F7DE8

#define func_80041AB8 func_800FFD64
#define D_80075FD8 D_80100AFC
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_800F54E0 func_800FFDA0
#include "../shared/commander_yammark/func_800F54E0.c"
#undef func_800F54E0

#define func_800F5564 func_800FFE24
#include "../shared/commander_yammark/func_800F5564.c"
#undef func_800F5564

#define step_commander_yammark func_800FFF24
#define D_800F7D54 D_80100B88
#include "../shared/commander_yammark/step_commander_yammark.c"
#undef step_commander_yammark
#undef D_800F7D54

#define D_800F7E10 D_80100C44
#define func_800F56B4 func_800FFF74
#define D_800F7E20 D_80100C54
#include "../shared/commander_yammark/func_800F56B4.c"
#undef func_800F56B4
#undef D_800F7E20
#undef D_800F7E10

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FFFB8);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8010007C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_8010009C);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80100188(void) {
    clear_object_slot();
}

#define func_800F58E8 func_801001A8
#define D_800F7D74 D_80100BA8
#include "../shared/commander_yammark/func_800F58E8.c"
#undef func_800F58E8
#undef D_800F7D74

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_80100268);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80100358(void) {
    clear_object_slot();
}

#define func_800F5AB8 func_80100378
#include "../shared/commander_yammark/func_800F5AB8.c"
#undef func_800F5AB8

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80100430(void) {
    clear_object_slot();
}

#define func_800F5B90 func_80100450
#define D_800F7DEC D_80100C20
#include "../shared/commander_yammark/func_800F5B90.c"
#undef func_800F5B90
#undef D_800F7DEC

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_80100538);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_801005F8(void) {
    clear_object_slot();
}

#define func_800F5D58 func_80100618
#include "../shared/commander_yammark/func_800F5D58.c"
#undef func_800F5D58

#define func_800F5E0C func_801006CC
#define D_800F7DE4 D_80100C18
#include "../shared/commander_yammark/func_800F5E0C.c"
#undef func_800F5E0C
#undef D_800F7DE4

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80100764(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_80100784);
// clang-format on
