// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FA0D0);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FA45C);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FA5F8);

#define func_800EFF18 func_800FA7D8
#define D_800F7DC0 D_80100BF4
#define D_800F7DC2 D_80100BF6
#define D_800F7DCA D_80100BFE
#define D_800F7DCC D_80100C00
#define D_800F7DCE D_80100C02
#define D_800F7DD0 D_80100C04
#include "../shared/commander_yammark/func_800EFF18.c"
#undef func_800EFF18
#undef D_800F7DC0
#undef D_800F7DC2
#undef D_800F7DCA
#undef D_800F7DCC
#undef D_800F7DCE
#undef D_800F7DD0

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FA94C);

#define func_800EFF18 func_800FAC20
#define D_800F7DC0 D_80100BF4
#define D_800F7DC2 D_80100BF6
#define D_800F7DCA D_80100BFE
#define D_800F7DCC D_80100C00
#define D_800F7DCE D_80100C02
#define D_800F7DD0 D_80100C04
#include "../shared/commander_yammark/func_800EFF18.c"
#undef func_800EFF18
#undef D_800F7DC0
#undef D_800F7DC2
#undef D_800F7DCA
#undef D_800F7DCC
#undef D_800F7DCE
#undef D_800F7DD0

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FAD94);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FB068);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FB288);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FB3CC);
// clang-format on

#define func_800F0DE0 func_800FB6A0
#define g_Player g_Player
#include "../shared/commander_yammark/func_800F0DE0.c"
#undef func_800F0DE0
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FB7DC);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FB920);

#define func_800F1334 func_800FBBF4
#define D_800F7DC0 D_80100BF4
#define D_800F7DC2 D_80100BF6
#define D_800F7DCA D_80100BFE
#define D_800F7DCC D_80100C00
#define D_800F7DD0 D_80100C04
#include "../shared/rock_03/func_800F1334.c"
#undef func_800F1334
#undef D_800F7DC0
#undef D_800F7DC2
#undef D_800F7DCA
#undef D_800F7DCC
#undef D_800F7DD0

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FBD38);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FC00C);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FC1C4);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FC2FC);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FC414);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002EE10(void*);

extern void (*D_80100BAC[])(void*);
extern void (*D_80100BB8[])(void*);
extern void (*D_80100BC4[])(void*);
extern void (*D_80100BD0[])(void*);
extern void (*D_80100BDC[])(void*);
extern void (*D_80100BE8[])(void*);

void func_800FE398(u8* self) {
    if (*(s32*)(self + 0x84) == 0 && self[0x70] == 0) {
        func_8002EE10(self);
    }
    self[3] = 0;
    switch ((s8)self[2]) {
    case 0:
    case 1:
        D_80100BAC[(s8)self[4]](self);
        break;
    case 2:
        D_80100BB8[(s8)self[4]](self);
        break;
    case 3:
        D_80100BC4[(s8)self[4]](self);
        break;
    case 4:
        D_80100BD0[(s8)self[4]](self);
        break;
    case 5:
        D_80100BDC[(s8)self[4]](self);
        break;
    case 6:
        D_80100BE8[(s8)self[4]](self);
        break;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FE4A4);

INCLUDE_ASM("asm/rock_33/nonmatchings/FA000", func_800FE6A4);
// clang-format on

#define func_800F3FB0 func_800FE870
#define D_800F7DEC D_80100C20
#include "../shared/commander_yammark/func_800F3FB0.c"
#undef func_800F3FB0
#undef D_800F7DEC
