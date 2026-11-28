// clang-format off
INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FA230);

#define func_800F213C func_800FA3EC
#define D_800F95E0 D_801002E4
#define D_800F9874 D_8010052C
#define func_800F66FC func_800FE9AC
#include "../shared/rock_07/func_800F213C.c"
#undef func_800F213C
#undef D_800F95E0
#undef D_800F9874
#undef func_800F66FC

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FA5F0);

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FA718);
// clang-format on

#define func_800F25F0 func_800FA8A0
#include "../shared/rock_07/func_800F25F0.c"
#undef func_800F25F0

#define func_800F2738 func_800FA9E8
#include "../shared/rock_07/func_800F2738.c"
#undef func_800F2738

// clang-format off
#define func_800F2884 func_800FAB34
#define func_800F6880 func_800FEB30
#define func_800F6E48 func_800FF0F8
#include "../shared/rock_07/func_800F2884.c"
#undef func_800F2884
#undef func_800F6880
#undef func_800F6E48

#define func_800F2A04 func_800FACB4
#define func_800F6880 func_800FEB30
#include "../shared/rock_07/func_800F2A04.c"
#undef func_800F2A04
#undef func_800F6880
// clang-format on

#define func_800F2C38 func_800FAEE8
#include "../shared/rock_07/func_800F2C38.c"
#undef func_800F2C38

// clang-format off
#define func_800F2D98 func_800FB048
#define func_800F6880 func_800FEB30
#include "../shared/rock_07/func_800F2D98.c"
#undef func_800F2D98
#undef func_800F6880
// clang-format on

#define func_800F2EE4 func_800FB194
#define D_800F96F4 D_801003F8
#include "../shared/rock_07/func_800F2EE4.c"
#undef func_800F2EE4
#undef D_800F96F4

// clang-format off
#define func_800F3014 func_800FB2C4
#define func_800F6948 func_800FEBF8
#include "../shared/rock_07/func_800F3014.c"
#undef func_800F3014
#undef func_800F6948

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FB430);

#define func_800F3290 func_800FB540
#define D_800E9A7C D_800FA014
#define D_800F986A D_80100522
#define func_800F6D4C func_800FEFFC
#include "../shared/rock_07/func_800F3290.c"
#undef func_800F3290
#undef D_800E9A7C
#undef D_800F986A
#undef func_800F6D4C

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FB6A8);

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FB858);
// clang-format on

#define func_800F37DC func_800FBA8C
#define D_800F97B0 D_801004B4
#include "../shared/rock_07/func_800F37DC.c"
#undef func_800F37DC
#undef D_800F97B0

#define func_800F3988 func_800FBC38
#include "../shared/rock_07/func_800F3988.c"
#undef func_800F3988

#define func_800F3B9C func_800FBE4C
#include "../shared/rock_07/func_800F3B9C.c"
#undef func_800F3B9C

#include "common.h"

void func_800FEE44(u8* arg0, u8 arg1, s16 arg2, s16 arg3);

void func_800FBF30(u8* self) {
    u8* parent = *(u8**)(self + 0x8C);

    if (*(s8*)(parent + 4) != 3) {
        self[4] = 2;
        self[3] = 0;
        return;
    }
    self[3] = parent[3];
    if (*(u16*)(parent + 0x42) & 0x8000) {
        *(u16*)(self + 0x42) |= 0x8000;
    } else {
        *(u16*)(self + 0x42) &= 0x7FFF;
    }
    if (self[0x15] == 0) {
        switch (*(s8*)(self + 0x45)) {
        case 1:
            func_800FEE44(self, 0x31, *(s16*)(self + 0xA) + 0x70,
                          *(s16*)(self + 0xE) - 0x38);
            break;
        case 2:
            func_800FEE44(self, 0x32, *(s16*)(self + 0xA) + 0x50,
                          *(s16*)(self + 0xE) - 0x28);
            break;
        case 3:
            func_800FEE44(self, 0x33, *(s16*)(self + 0xA) + 0x30,
                          *(s16*)(self + 0xE) - 0x18);
            break;
        case 4:
            func_800FEE44(self, 0x34, *(s16*)(self + 0xA) + 0x10,
                          *(s16*)(self + 0xE) - 0x8);
            break;
        case 5:
            func_800FEE44(self, 0x35, *(s16*)(self + 0xA) - 0x10,
                          *(s16*)(self + 0xE) + 0x8);
            break;
        case 6:
            func_800FEE44(self, 0x36, *(s16*)(self + 0xA) - 0x30,
                          *(s16*)(self + 0xE) + 0x18);
            break;
        case 7:
            func_800FEE44(self, 0x37, *(s16*)(self + 0xA) - 0x50,
                          *(s16*)(self + 0xE) + 0x28);
            break;
        case 16:
            *(s16*)(self + 0x88) = 0x3C;
            self[6]++;
            break;
        }
    } else {
        switch (*(s8*)(self + 0x45)) {
        case 1:
            func_800FEE44(self, 0x31, *(s16*)(self + 0xA) - 0x70,
                          *(s16*)(self + 0xE) - 0x38);
            break;
        case 2:
            func_800FEE44(self, 0x32, *(s16*)(self + 0xA) - 0x50,
                          *(s16*)(self + 0xE) - 0x28);
            break;
        case 3:
            func_800FEE44(self, 0x33, *(s16*)(self + 0xA) - 0x30,
                          *(s16*)(self + 0xE) - 0x18);
            break;
        case 4:
            func_800FEE44(self, 0x34, *(s16*)(self + 0xA) - 0x10,
                          *(s16*)(self + 0xE) - 0x8);
            break;
        case 5:
            func_800FEE44(self, 0x35, *(s16*)(self + 0xA) + 0x10,
                          *(s16*)(self + 0xE) + 0x8);
            break;
        case 6:
            func_800FEE44(self, 0x36, *(s16*)(self + 0xA) + 0x30,
                          *(s16*)(self + 0xE) + 0x18);
            break;
        case 7:
            func_800FEE44(self, 0x37, *(s16*)(self + 0xA) + 0x50,
                          *(s16*)(self + 0xE) + 0x28);
            break;
        case 16:
            *(s16*)(self + 0x88) = 0x3C;
            self[6]++;
            break;
        }
    }
}

// clang-format off
#define func_800F3F94 func_800FC244
#define D_800F97A0 D_801004A4
#include "../shared/rock_07/func_800F3F94.c"
#undef func_800F3F94
#undef D_800F97A0
// clang-format on

#define func_800F4144 func_800FC3F4
#include "../shared/rock_07/func_800F4144.c"
#undef func_800F4144

// clang-format off
#define func_80050DFC func_800FC4E0
#define D_80078DD4 D_801002D0
#define func_8002CB50 func_8002F288
#include "../shared/main/func_80050DFC.c"
#undef func_80050DFC
#undef D_80078DD4
#undef func_8002CB50
// clang-format on

#define func_80041AB8 func_800FC53C
#define D_80075FD8 D_8010030C
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_800F42C8 func_800FC578
#define g_Player g_Player
#include "../shared/rock_07/func_800F42C8.c"
#undef func_800F42C8
#undef g_Player

#define func_800F2FB0 func_800FC610
#include "../shared/rock_04/func_800F2FB0.c"
#undef func_800F2FB0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800FC704(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) != 0) {
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) = 0;
    }
    clear_object_slot();
}

#define func_8003744C func_800FC740
#define D_80073C1C D_801003AC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800FC77C(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800F4948 func_800FC7B4
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_04/func_800F4948.c"
#undef func_800F4948
#undef g_playthrough_state

#define func_800F45A0 func_800FC850
#define D_800E9A6C D_800FA004
#include "../shared/rock_07/func_800F45A0.c"
#undef func_800F45A0
#undef D_800E9A6C

#define func_800F4674 func_800FC924
#define D_800F907C D_800FFD80
#include "../shared/rock_07/func_800F4674.c"
#undef func_800F4674
#undef D_800F907C

#define func_800F46CC func_800FC97C
#include "../shared/rock_07/func_800F46CC.c"
#undef func_800F46CC

#define func_800F472C func_800FC9DC
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_07/func_800F472C.c"
#undef func_800F472C
#undef g_playthrough_state

#define func_800F4BA8 func_800FCA78
#include "../shared/rock_04/func_800F4BA8.c"
#undef func_800F4BA8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80040498(); /* extern */

void func_800FCABC(void* arg0) {
    if (func_80040498() == 0) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F4D48 func_800FCAF8
#include "../shared/rock_04/func_800F4D48.c"
#undef func_800F4D48

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();    /* extern */
M2C_UNK func_800FB6A8(s32); /* extern */

void func_800FCB7C(s32 arg0) {
    func_8003D330();
    func_800FB6A8(arg0);
}

#define func_8003744C func_800FCBA8
#define D_80073C1C D_801003D8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FCBE4);
// clang-format on

#define func_800F49D8 func_800FCC88
#include "../shared/rock_07/func_800F49D8.c"
#undef func_800F49D8

// clang-format off
INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FCCC8);

#include "../shared/rock_36/func_800FCD4C.c"
// clang-format on

#define func_8003744C func_800FCD88
#define D_80073C1C D_801003E8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F4B14 func_800FCDC4
#include "../shared/rock_07/func_800F4B14.c"
#undef func_800F4B14

#define func_800F4BE4 func_800FCE94
#define D_800F907C D_800FFD80
#include "../shared/rock_07/func_800F4BE4.c"
#undef func_800F4BE4
#undef D_800F907C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK apply_object_motion(void*);          /* extern */

void func_800FCED8(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        play_sound(2, 0x5C, arg0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    apply_object_motion(arg0);
}

// clang-format off
#define func_800F4A9C func_800FCF38
#define func_800F33F8 func_800FB6A8
#include "../shared/rock_07/func_800F4A9C.c"
#undef func_800F4A9C
#undef func_800F33F8
// clang-format on

#define func_8003744C func_800FCF74
#define D_80073C1C D_80100318
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FCFB0);
// clang-format on

#define func_800F4DB0 func_800FD060
#include "../shared/rock_07/func_800F4DB0.c"
#undef func_800F4DB0

#define func_800F4DFC func_800FD0AC
#include "../shared/rock_07/func_800F4DFC.c"
#undef func_800F4DFC

// clang-format off
#define func_800F4E4C func_800FD0FC
#define D_800F9080 D_800FFD84
#include "../shared/rock_07/func_800F4E4C.c"
#undef func_800F4E4C
#undef D_800F9080

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FD190);
// clang-format on

#define func_8003744C func_800FD1CC
#define D_80073C1C D_80100330
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
#define func_800F4F58 func_800FD208
#define func_800F6E48 func_800FF0F8
#include "../shared/rock_07/func_800F4F58.c"
#undef func_800F4F58
#undef func_800F6E48
// clang-format on

#define func_800F4FA8 func_800FD258
#include "../shared/rock_07/func_800F4FA8.c"
#undef func_800F4FA8

// clang-format off
#include "../shared/rock_36/func_800FD344.c"

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FD39C);
// clang-format on

#define func_800F51F0 func_800FD4A0
#include "../shared/rock_07/func_800F51F0.c"
#undef func_800F51F0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800FB6A8(); /* extern */

void func_800FD504(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        ((M2C_UNK(*)())func_800FB6A8)();
    }
}

#define func_8003744C func_800FD534
#define D_80073C1C D_80100348
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
#define func_800F52C0 func_800FD570
#define func_800F6E48 func_800FF0F8
#include "../shared/rock_07/func_800F52C0.c"
#undef func_800F52C0
#undef func_800F6E48
// clang-format on

#define func_800F52FC func_800FD5AC
#define g_Player g_Player
#include "../shared/rock_07/func_800F52FC.c"
#undef func_800F52FC
#undef g_Player

#define func_800F53C8 func_800FD678
#include "../shared/rock_07/func_800F53C8.c"
#undef func_800F53C8

// clang-format off
#define func_800F5430 func_800FD6E0
#define func_800F6880 func_800FEB30
#include "../shared/rock_07/func_800F5430.c"
#undef func_800F5430
#undef func_800F6880
// clang-format on

#define func_800F5530 func_800FD7E0
#include "../shared/rock_07/func_800F5530.c"
#undef func_800F5530

// clang-format off
INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FD830);
// clang-format on

#define func_8003744C func_800FD86C
#define D_80073C1C D_80100364
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
#define func_800F55F8 func_800FD8A8
#define func_800F6E48 func_800FF0F8
#include "../shared/rock_07/func_800F55F8.c"
#undef func_800F55F8
#undef func_800F6E48
// clang-format on

#define func_800F5648 func_800FD8F8
#define g_Player g_Player
#include "../shared/rock_07/func_800F5648.c"
#undef func_800F5648
#undef g_Player

#define func_800F56F0 func_800FD9A0
#include "../shared/rock_07/func_800F56F0.c"
#undef func_800F56F0

// clang-format off
#define func_800F5764 func_800FDA14
#define D_80097420 D_80097420
#define func_800F6880 func_800FEB30
#define func_800F9084 func_800FFD88
#include "../shared/rock_07/func_800F5764.c"
#undef func_800F5764
#undef D_80097420
#undef func_800F6880
#undef func_800F9084
// clang-format on

#define func_800F5814 func_800FDAC4
#define D_800F907C D_800FFD80
#include "../shared/rock_07/func_800F5814.c"
#undef func_800F5814
#undef D_800F907C

#define func_800F51F0 func_800FDB34
#include "../shared/rock_07/func_800F51F0.c"
#undef func_800F51F0

#define func_800F58E8 func_800FDB98
#include "../shared/rock_07/func_800F58E8.c"
#undef func_800F58E8

// clang-format off
INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FDBE4);
// clang-format on

#define func_8003744C func_800FDC20
#define D_80073C1C D_80100390
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F59AC func_800FDC5C
#include "../shared/rock_07/func_800F59AC.c"
#undef func_800F59AC

#define func_800F5A1C func_800FDCCC
#define background_objects background_objects
#include "../shared/rock_07/func_800F5A1C.c"
#undef func_800F5A1C
#undef background_objects

// clang-format off
#define func_800F5AA8 func_800FDD58
#define func_800F67D0 func_800FEA80
#include "../shared/rock_07/func_800F5AA8.c"
#undef func_800F5AA8
#undef func_800F67D0
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK silence_sound(M2C_UNK, M2C_UNK); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);   /* extern */

void func_800FDE4C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        silence_sound(2, 0x14);
        set_animation(arg0, 4);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x105D;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F51F0 func_800FDEB0
#include "../shared/rock_07/func_800F51F0.c"
#undef func_800F51F0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800FB6A8(); /* extern */

void func_800FDF14(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        ((M2C_UNK(*)())func_800FB6A8)();
    }
}

#include "common.h"

void func_800FDF44(void) {
}

#define func_8003744C func_800FDF4C
#define D_80073C1C D_8010040C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5CD8 func_800FDF88
#define D_800E9A70 D_800FA008
#include "../shared/rock_07/func_800F5CD8.c"
#undef func_800F5CD8
#undef D_800E9A70

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FDFD8(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
#define func_800F5D3C func_800FDFEC
#define D_800F9868 D_80100520
#define func_800F4144 func_800FC3F4
#include "../shared/rock_07/func_800F5D3C.c"
#undef func_800F5D3C
#undef D_800F9868
#undef func_800F4144

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FE054);
// clang-format on

#define D_800F90B8 D_800FFDBC
#define D_800F90BC D_800FFDC0
#define func_800F6E48 func_800FF0F8
#define func_800F5DF8 func_800FE0A8
#define D_800F90B8 D_800FFDBC
#include "../shared/rock_07/func_800F5DF8.c"
#undef func_800F5DF8
#undef D_800F90B8
#undef D_800F90B8
#undef D_800F90BC
#undef func_800F6E48

// clang-format off
#define func_800F5E48 func_800FE0F8
#define func_800F6AD0 func_800FED80
#include "../shared/rock_07/func_800F5E48.c"
#undef func_800F5E48
#undef func_800F6AD0
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FE16C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F5EEC func_800FE19C
#include "../shared/rock_07/func_800F5EEC.c"
#undef func_800F5EEC

#define func_8003744C func_800FE22C
#define D_80073C1C D_80100430
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5CD8 func_800FE268
#define D_800E9A70 D_800FA008
#include "../shared/rock_07/func_800F5CD8.c"
#undef func_800F5CD8
#undef D_800E9A70

// clang-format off
#define func_800F6008 func_800FE2B8
#define func_800F6948 func_800FEBF8
#include "../shared/rock_07/func_800F6008.c"
#undef func_800F6008
#undef func_800F6948

#define func_800F6118 func_800FE3C8
#define D_800F9868 D_80100520
#define func_800F4144 func_800FC3F4
#include "../shared/rock_07/func_800F6118.c"
#undef func_800F6118
#undef D_800F9868
#undef func_800F4144

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FE430);

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FE484);
// clang-format on

#define func_800F6220 func_800FE4D0
#include "../shared/rock_07/func_800F6220.c"
#undef func_800F6220

#define func_800F62AC func_800FE55C
#include "../shared/rock_07/func_800F62AC.c"
#undef func_800F62AC

#define func_8003744C func_800FE5C8
#define D_80073C1C D_80100450
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F6354 func_800FE604
#define D_800E9A74 D_800FA00C
#include "../shared/rock_07/func_800F6354.c"
#undef func_800F6354
#undef D_800E9A74

// clang-format off
#define func_800F63AC func_800FE65C
#define func_800F6948 func_800FEBF8
#include "../shared/rock_07/func_800F63AC.c"
#undef func_800F63AC
#undef func_800F6948

#define func_800F64BC func_800FE76C
#define D_800F9868 D_80100520
#define func_800F4144 func_800FC3F4
#include "../shared/rock_07/func_800F64BC.c"
#undef func_800F64BC
#undef D_800F9868
#undef func_800F4144

#define func_800F6524 func_800FE7D4
#define func_800F6E78 func_800FF128
#include "../shared/rock_07/func_800F6524.c"
#undef func_800F6524
#undef func_800F6E78

#define func_800F6578 func_800FE828
#define D_800F90C8 D_800FFDCC
#define D_800F90CC D_800FFDD0
#include "../shared/rock_07/func_800F6578.c"
#undef func_800F6578
#undef D_800F90C8
#undef D_800F90CC

INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FE874);
// clang-format on

#define func_800F668C func_800FE93C
#include "../shared/rock_07/func_800F668C.c"
#undef func_800F668C

// clang-format off
INCLUDE_ASM("rock_36/nonmatchings/FA000", func_800FE9AC);
// clang-format on

#define func_800F67D0 func_800FEA80
#include "../shared/rock_07/func_800F67D0.c"
#undef func_800F67D0

#define func_800F6880 func_800FEB30
#include "../shared/rock_07/func_800F6880.c"
#undef func_800F6880

// clang-format off
#define func_800F6948 func_800FEBF8
#define D_800F9868 D_80100520
#include "../shared/rock_07/func_800F6948.c"
#undef func_800F6948
#undef D_800F9868
// clang-format on

#define func_800F6A1C func_800FECCC
#include "../shared/rock_07/func_800F6A1C.c"
#undef func_800F6A1C

#define func_800F6AD0 func_800FED80
#include "../shared/rock_07/func_800F6AD0.c"
#undef func_800F6AD0

#define func_800F6B94 func_800FEE44
#include "../shared/rock_07/func_800F6B94.c"
#undef func_800F6B94

#define func_800F6C70 func_800FEF20
#include "../shared/rock_07/func_800F6C70.c"
#undef func_800F6C70

// clang-format off
#define func_800F6D4C func_800FEFFC
#define D_800F986A D_80100522
#include "../shared/rock_07/func_800F6D4C.c"
#undef func_800F6D4C
#undef D_800F986A
// clang-format on

#define func_80042C18 func_800FF0F8
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002A47C(s32);
extern u16 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)

#define SP_20 (*(s8**)0x1F800020)
#define SP_9C (*(s8**)0x1F80009C)

void func_800FF128(void* arg0) {
    s32 a;
    s32 b;
    s32 c;
    s8* p;

    M2C_FIELD(arg0, s16*, 0x40) = 0x140;
    if (D_800CCEDC != 0xC) {
        a = func_8002A47C(M2C_FIELD(arg0, s8*, 0x1));
        b = func_8002A47C(M2C_FIELD(arg0, s8*, 0x1));
        M2C_FIELD(arg0, s16*, 0x42) =
            ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
        c = func_8002A47C(M2C_FIELD(arg0, s8*, 0x1));
        M2C_FIELD(arg0, s8**, 0x3C) = SP_20 + ((s32*)SP_20)[c];
    } else {
        p = SP_9C;
        c = ((s32*)p)[0];
        M2C_FIELD(arg0, s16*, 0x42) = 0x7948;
        M2C_FIELD(arg0, s8**, 0x3C) = p + c;
    }
}

#undef D_800CCEDC

#define func_800F54B8 func_800FF210
#include "../shared/rock_04/func_800F54B8.c"
#undef func_800F54B8

#define func_800F6FA0 func_800FF250
#define D_800F97A4 D_801004A8
#include "../shared/rock_07/func_800F6FA0.c"
#undef func_800F6FA0
#undef D_800F97A4

// clang-format off
#define func_800F7024 func_800FF2D4
#define D_800F9868 D_80100520
#define D_800F986A D_80100522
#include "../shared/rock_07/func_800F7024.c"
#undef func_800F7024
#undef D_800F9868
#undef D_800F986A
// clang-format on

#define func_8003744C func_800FF348
#define D_80073C1C D_801004D0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32

M2C_UNK apply_object_motion(); /* extern */

void func_800FF384(void) {
    ((M2C_UNK(*)())apply_object_motion)();
}

#define func_8003744C func_800FF3A4
#define D_80073C1C D_801004D8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
#define func_800F7130 func_800FF3E0
#define D_800F977C D_80100480
#define D_800F9780 D_80100484
#define D_800F9784 D_80100488
#include "../shared/rock_07/func_800F7130.c"
#undef func_800F7130
#undef D_800F977C
#undef D_800F9780
#undef D_800F9784
// clang-format on

#define func_800F71D8 func_800FF488
#include "../shared/rock_07/func_800F71D8.c"
#undef func_800F71D8

// clang-format off
#define func_800F7224 func_800FF4D4
#define func_800F6E48 func_800FF0F8
#include "../shared/rock_07/func_800F7224.c"
#undef func_800F7224
#undef func_800F6E48
// clang-format on

#define func_800F72BC func_800FF56C
#include "../shared/rock_07/func_800F72BC.c"
#undef func_800F72BC

#define func_8003744C func_800FF664
#define D_80073C1C D_801004E8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F73F0 func_800FF6A0
#include "../shared/rock_07/func_800F73F0.c"
#undef func_800F73F0

#define func_8003744C func_800FF774
#define D_80073C1C D_801004F0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F7500 func_800FF7B0
#include "../shared/rock_07/func_800F7500.c"
#undef func_800F7500

#define func_800F7554 func_800FF804
#include "../shared/rock_07/func_800F7554.c"
#undef func_800F7554

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void* D_80100530;

void func_800FF888(void* arg0) {
    if ((M2C_FIELD(M2C_FIELD(arg0, void**, 0x8C), s8*, 4) != 3) ||
        (M2C_FIELD(D_80100530, s8*, 0x45) < (M2C_FIELD(arg0, u8*, 2) & 0xF))) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_8003744C func_800FF8D0
#define D_80073C1C D_801004FC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
#define func_800F765C func_800FF90C
#define D_800F978C D_80100490
#define D_800F9790 D_80100494
#include "../shared/rock_07/func_800F765C.c"
#undef func_800F765C
#undef D_800F978C
#undef D_800F9790
// clang-format on

#define func_800F76E0 func_800FF990
#include "../shared/rock_07/func_800F76E0.c"
#undef func_800F76E0

#define func_800F7748 func_800FF9F8
#include "../shared/rock_07/func_800F7748.c"
#undef func_800F7748

#define func_800F777C func_800FFA2C
#include "../shared/rock_07/func_800F777C.c"
#undef func_800F777C

#define func_800F77C8 func_800FFA78
#define D_800F9808 D_8010050C
#include "../shared/rock_07/func_800F77C8.c"
#undef func_800F77C8
#undef D_800F9808

// clang-format off
#define func_800F7820 func_800FFAD0
#define D_800F9794 D_80100498
#define D_800F9798 D_8010049C
#define D_800F979C D_801004A0
#include "../shared/rock_07/func_800F7820.c"
#undef func_800F7820
#undef D_800F9794
#undef D_800F9798
#undef D_800F979C
// clang-format on

#define func_800F78C8 func_800FFB78
#include "../shared/rock_07/func_800F78C8.c"
#undef func_800F78C8

#define func_800F793C func_800FFBEC
#include "../shared/rock_07/func_800F793C.c"
#undef func_800F793C

#define func_800F7970 func_800FFC20
#include "../shared/rock_07/func_800F7970.c"
#undef func_800F7970

// clang-format off
INCLUDE_ASM("rock_36/nonmatchings/FA000", D_800FFC80);
// clang-format on
