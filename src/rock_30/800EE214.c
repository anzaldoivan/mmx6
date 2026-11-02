#define func_800484D8 func_800EE214
#define D_80077BA4 D_800F0010
#include "../shared/SLUS_013.95/func_800484D8.c"
#undef func_800484D8
#undef D_80077BA4

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE260(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_EE280 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 random_byte();
extern s8 D_800CD30A;
extern u32* D_80095098;
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_800970AA;
extern s32 D_800F0050;
extern s32 D_8007497C;

#define START(self)                                                            \
    {                                                                          \
        M2C_FIELD(self, s16*, 0x7C) = (random_byte() % 3 + 1) * 100 + 200;   \
        M2C_FIELD(self, u8*, 5) = 1;                                           \
        M2C_FIELD(self, u8*, 3) = 0;                                           \
        flag = 1;                                                              \
    }

void func_800EE280(void* self) {
    s32 flag = 0;
    s32 a;
    s32 b;

    if (D_800CD30A != 7) {
        clear_object_slot(self);
        return;
    }
    M2C_FIELD(self, u8*, 0) = 0x41;
    M2C_FIELD(self, u16*, 0x40) =
        D_80095098[func_8002A47C(M2C_FIELD(self, s8*, 1))] >> 7;
    a = func_8002A47C(M2C_FIELD(self, s8*, 1));
    b = func_8002A47C(M2C_FIELD(self, s8*, 1));
    M2C_FIELD(self, u16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(self, s32*, 0x3C) =
        SPAD20_EE280 +
        ((s32*)SPAD20_EE280)[func_8002A47C(M2C_FIELD(self, s8*, 1))];
    switch (M2C_FIELD(self, s8*, 2)) {
    case 0:
        if ((u32)((u16)D_800970AA - 0x141) < 0x8BF) {
            START(self);
        }
        break;
    case 1:
        if ((u32)((u16)D_800970AA - 0xC81) < 0x3BF) {
            START(self);
        }
        break;
    case 2:
        if ((u32)((u16)D_800970AA - 0x4E1) < 0x17F) {
            START(self);
        }
        break;
    case 3:
        if ((u32)((u16)D_800970AA - 0x1361) < 0x92F) {
            START(self);
        }
        break;
    case 4:
        if ((u32)((u16)D_800970AA - 1) < 0x41F) {
            START(self);
        }
        break;
    case 5:
        if ((u32)((u16)g_Player.x_pos.i.hi - 0x141) < 0x71F &&
            g_Player.y_pos.i.hi < 0x430) {
            START(self);
        }
        break;
    case 10:
        ((void (*)(void*, s32))set_animation)(self, 0);
        flag = 1;
        M2C_FIELD(self, s16*, 0x7C) = 0x28;
        M2C_FIELD(self, s32*, 0x54) = 0;
        M2C_FIELD(self, s32*, 0x50) = 0;
        M2C_FIELD(self, u8*, 5) = 3;
        M2C_FIELD(self, u8*, 3) = flag;
        break;
    case 11:
        M2C_FIELD(self, s16*, 0x7C) = 0x28;
        ((void (*)(void*, s32))set_animation)(self, 2);
        flag = 1;
        M2C_FIELD(self, s32*, 0x54) = 0;
        M2C_FIELD(self, s32*, 0x50) = 0;
        M2C_FIELD(self, u8*, 5) = 3;
        M2C_FIELD(self, u8*, 3) = flag;
        break;
    }
    if (flag) {
        struct X4_PlayerObj* p = &g_Player;
        M2C_FIELD(self, u8*, 0x5C) = 4;
        M2C_FIELD(self, u8*, 0x61) = 0;
        M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(p, u8*, 0x14);
        M2C_FIELD(self, void**, 0x30) = &D_800F0050;
        M2C_FIELD(self, u8*, 0x16) = 4;
        M2C_FIELD(self, s32*, 0x68) = 0;
        M2C_FIELD(self, u8*, 0x67) = 0;
        M2C_FIELD(self, void**, 0x58) = &D_8007497C;
        M2C_FIELD(self, u8*, 0x60) = 6;
        M2C_FIELD(self, u8*, 0x15) = (M2C_FIELD(self, s32*, 8) <= p->x_pos.val)
                                     << 6;
        M2C_FIELD(self, u8*, 4) = 1;
        M2C_FIELD(self, u8*, 6) = 0;
    }
}
#undef g_Player
#undef SPAD20_EE280

#define func_800EECCC func_800EE568
#include "../shared/rock_09/func_800EECCC.c"
#undef func_800EECCC

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EE7A0);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EE8A0);
// clang-format on

#define func_800EFDB4 func_800EE8FC
#define D_800F6DD8 D_800F0070
#include "../shared/rock_04/func_800EFDB4.c"
#undef func_800EFDB4
#undef D_800F6DD8

#define func_800EFE78 func_800EE9C0
#define D_80097420 D_80097420
#include "../shared/rock_04/func_800EFE78.c"
#undef func_800EFE78
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EEA38(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800EEA58(void) {
    ((M2C_UNK(*)())move_object)();
}

#define func_8003744C func_800EEA78
#define D_80073C1C D_800F0080
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EEAB4);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EEB00(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EEB20);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EED10);
// clang-format on

#define func_80046C64 func_800EEF38
#define D_800762A0 D_800F00EC
#include "../shared/d1000/func_80046C64.c"
#undef func_80046C64
#undef D_800762A0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EEF78(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EEF98);
// clang-format on
