// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FA15C);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
void func_800FE2FC(void* arg0);
void func_800FE4A8(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern s8 D_800CCF5C;
extern void (*D_800FFC1C[])(void*);
extern s32 D_800FFE28;

void func_800FA34C(void* arg0) {
    s32 r;
    u16 t;
    u8 n;

    animate_object(arg0);
    D_800FFC1C[M2C_FIELD(arg0, s8*, 5)](arg0);
    func_800FE2FC(arg0);
    if (M2C_FIELD(arg0, s8*, 5) != 2 && M2C_FIELD(arg0, s8*, 2) == 0) {
        D_800FFE28++;
    }
    r = check_enemy_hits(arg0);
    if (r < 0) {
        D_8009711A = 1;
        M2C_FIELD(arg0, s8*, 4) = 3;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, s16*, 0x84) = 0x1E;
        switch (r) {
        case 8:
        case 17:
        case 54:
            M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 3;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        case 1:
            play_sound(2, 0x24, arg0);
            if (D_800CCF38 >= 2) {
                M2C_FIELD(arg0, s8*, 0x8B) += 2;
            } else {
                M2C_FIELD(arg0, s8*, 0x8B) += 1;
            }
            if (M2C_FIELD(arg0, s8*, 0x8B) >= 9) {
                M2C_FIELD(arg0, s8*, 0x8B) = 8;
            }
            if (M2C_FIELD(arg0, s8*, 0x8B) >= 6) {
                func_800FE4A8(arg0, 0x11, 0);
            } else if (M2C_FIELD(arg0, s8*, 0x8B) >= 3) {
                func_800FE4A8(arg0, 0x10, 0);
            }
            break;
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 32:
        case 38:
        case 40:
        case 51:
        case 52:
            M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 0xC;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        n = M2C_FIELD(arg0, u8*, 0x8E);
        switch (M2C_FIELD(arg0, s8*, 0x8E)) {
        case 0:
            if (M2C_FIELD(arg0, s8*, 0x5C) > D_800CCF5C * 3 / 4) {
                break;
            }
            M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 0xC;
            M2C_FIELD(arg0, s8*, 6) = 3;
            M2C_FIELD(arg0, u8*, 0x8E) = n + 1;
            return;
        case 1:
            if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
                break;
            }
            M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 0xC;
            M2C_FIELD(arg0, s8*, 6) = 3;
            M2C_FIELD(arg0, u8*, 0x8E) = n + 1;
            return;
        case 2:
            if (D_800CCF5C / 4 < M2C_FIELD(arg0, s8*, 0x5C)) {
                break;
            }
            M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 0xC;
            M2C_FIELD(arg0, s8*, 6) = 3;
            M2C_FIELD(arg0, u8*, 0x8E) = n + 1;
            return;
        }
    }
    t = M2C_FIELD(arg0, u16*, 0x84);
    if (M2C_FIELD(arg0, s16*, 0x84) != 0) {
        M2C_FIELD(arg0, u16*, 0x84) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007569C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
void func_800FE2FC(void* arg0);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800FF668;

void func_800FA638(void* arg0) {
    s32 r;

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 4) != 1) {
        M2C_FIELD(arg0, u8*, 4) = 6;
        M2C_FIELD(arg0, u8*, 3) = 0;
        return;
    }
    animate_object(arg0);
    (*(void (**)(void*))((s8*)&D_800FF668 + 0x5EC +
                         (M2C_FIELD(arg0, s8*, 5) << 2)))(arg0);
    func_800FE2FC(arg0);
    r = check_enemy_hits(arg0);
    if (r < 0) {
        // !FAKE: shared kill block inside the switch arm, as retail's one copy
        goto block_kill;
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, s16*, 0x84) = 0x14;
        switch (r) {
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 38:
        case 40:
        case 51:
        case 52:
            if (M2C_FIELD(&D_800FF668, s16*, 0x7B8) >= 2) {
                if (++M2C_FIELD(arg0, s8*, 0x8D) == 4) {
                block_kill:
                    func_80049E50(arg0);
                    M2C_FIELD(arg0, u8*, 4) = 6;
                    M2C_FIELD(arg0, u8*, 3) = 0;
                    return;
                }
            }
            break;
        }
    }
    if (M2C_FIELD(arg0, s16*, 0x84) != 0) {
        if (M2C_FIELD(arg0, s16*, 0x84)-- & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007569C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FA7C4);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FA8F8);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FAA1C);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FAB04);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FAC04);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FAD14);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FAEC4);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FB088);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FB1DC);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FB378);
// clang-format on

#define func_800F70B8 func_800FB5E4
#define D_8007433C D_8007433C
#include "../shared/rock_11/func_800F70B8.c"
#undef func_800F70B8
#undef D_8007433C

#define func_800F7284 func_800FB7B0
#define D_800FD49C D_800FFDAC
#include "../shared/rock_11/func_800F7284.c"
#undef func_800F7284
#undef D_800FD49C

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FB8DC);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FBA78);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FBB9C);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FBCD4);
// clang-format on

#define func_800F79D0 func_800FBEFC
#include "../shared/rock_11/func_800F79D0.c"
#undef func_800F79D0

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FC110);
// clang-format on

#define func_800F7E38 func_800FC364
#define D_800FD2F0 D_800FFC00
#include "../shared/rock_11/func_800F7E38.c"
#undef func_800F7E38
#undef D_800FD2F0

#define func_80041AB8 func_800FC3D4
#define D_80075FD8 D_800FFC68
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_800F7EE4 func_800FC410
#define g_Player g_Player
#include "../shared/rock_11/func_800F7EE4.c"
#undef func_800F7EE4
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FC49C);
// clang-format on

#define func_800F8064 func_800FC590
#define D_800FD438 D_800FFD48
#include "../shared/rock_11/func_800F8064.c"
#undef func_800F8064
#undef D_800FD438

#define func_800F8130 func_800FC65C
#include "../shared/rock_11/func_800F8130.c"
#undef func_800F8130

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
s32 random_byte();
extern M2C_UNK D_800FF804;
extern M2C_UNK D_800FF808;

void func_800FC724(u8* self) {
    u32 r;

    if (*(s8*)(self + 0x45) == 1) {
        set_animation_frame(self, 0x13, random_byte() & 3);
        {
            // !FAKE: depin: dropping it breaks the match (40/45)
            register void* a asm("$2") = &D_800FF804;
            // !FAKE: depin: dropping it breaks the match (41/45)
            register void* b asm("$3") = &D_800FF808;
            *(void**)(self + 0x50) = a;
            *(void**)(self + 0x54) = b;
        }
        r = random_byte();
        *(u16*)(self + 0x7E) = 8;
        self[5]++;
        *(u16*)(self + 0x7C) = (u8)(r % 70) + 20;
    }
}

#define func_800F82AC func_800FC7D8
#include "../shared/rock_11/func_800F82AC.c"
#undef func_800F82AC

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FC89C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 6;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FC8BC);
// clang-format on

#define func_800F8454 func_800FC980
#define D_800FCEFC D_800FF80C
#include "../shared/rock_11/func_800F8454.c"
#undef func_800F8454
#undef D_800FCEFC

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FC9D4);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FCA98);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
extern M2C_UNK D_800FF668;

void func_800FCB64(void* arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    if (temp_v1 == 0) {
        M2C_FIELD(&D_800FF668, u16*, 0x7B8) =
            (u16)(M2C_FIELD(&D_800FF668, u16*, 0x7B8) - 1);
    } else if (temp_v1 == 0x10) {
        M2C_FIELD(&D_800FF668, u16*, 0x7BA) =
            (u16)(M2C_FIELD(&D_800FF668, u16*, 0x7BA) - 1);
    }
    clear_object_slot();
}

#define func_8003744C func_800FCBC8
#define D_80073C1C D_800FFC74
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F86D8 func_800FCC04
#include "../shared/rock_11/func_800F86D8.c"
#undef func_800F86D8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800FB378(); /* extern */

void func_800FCCA4(void* arg0) {
    M2C_FIELD(arg0, s8*, 7) = 0;
    func_800FB378();
}

#define func_8003744C func_800FCCC4
#define D_80073C1C D_800FFC80
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FCD00);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FCDC0);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FCEC8(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 4;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_8003744C func_800FCED8
#define D_80073C1C D_800FFC90
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800FA4C8 func_800FE9F4
#define func_800F89E8 func_800FCF14
#include "../shared/rock_11/func_800F89E8.c"
#undef func_800F89E8
#undef func_800FA4C8

#define func_800F8A28 func_800FCF54
#include "../shared/rock_11/func_800F8A28.c"
#undef func_800F8A28

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FCFA8);
// clang-format on

#define func_800F8AF0 func_800FD01C
#include "../shared/rock_11/func_800F8AF0.c"
#undef func_800F8AF0

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FD070);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FD0EC);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FD1B0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 4;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_800F8CA4 func_800FD1D0
#include "../shared/rock_11/func_800F8CA4.c"
#undef func_800F8CA4

#define func_8003744C func_800FD204
#define D_80073C1C D_800FFCAC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F9F7C func_800FE4A8
#define func_800F8D14 func_800FD240
#include "../shared/rock_11/func_800F8D14.c"
#undef func_800F8D14
#undef func_800F9F7C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FD2AC(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 4;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_8003744C func_800FD2BC
#define D_80073C1C D_800FFCB4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F8DCC func_800FD2F8
#include "../shared/rock_11/func_800F8DCC.c"
#undef func_800F8DCC

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FD340);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FD37C);
// clang-format on

#define func_8003744C func_800FD4A4
#define D_80073C1C D_800FFCC4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800FA4C8 func_800FE9F4
#define func_800F8FB4 func_800FD4E0
#define D_8007433C D_8007433C
#include "../shared/rock_11/func_800F8FB4.c"
#undef func_800F8FB4
#undef D_8007433C
#undef func_800FA4C8

#define func_800F900C func_800FD538
#include "../shared/rock_11/func_800F900C.c"
#undef func_800F900C

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FD5CC);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FD674);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FD6B0);
// clang-format on

#define func_8003744C func_800FD7CC
#define D_80073C1C D_800FFCD8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800FA4C8 func_800FE9F4
#define D_800FDA7E D_800FFE22
#define func_800F92DC func_800FD808
#include "../shared/rock_11/func_800F92DC.c"
#undef func_800F92DC
#undef func_800FA4C8
#undef D_800FDA7E

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FD86C);
// clang-format on

#define func_800F948C func_800FD9B8
#include "../shared/rock_11/func_800F948C.c"
#undef func_800F948C

#define func_8003744C func_800FD9CC
#define D_80073C1C D_800FFD0C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F94DC func_800FDA08
#include "../shared/rock_11/func_800F94DC.c"
#undef func_800F94DC

#define func_800FA4C8 func_800FE9F4
#define func_800F6E4C func_800FB378
#define func_800F9524 func_800FDA50
#include "../shared/rock_11/func_800F9524.c"
#undef func_800F9524
#undef func_800FA4C8
#undef func_800F6E4C

#define func_8003744C func_800FDAB4
#define D_80073C1C D_800FFCE4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FDAF0);
// clang-format on

#define func_800F96E0 func_800FDC0C
#include "../shared/rock_11/func_800F96E0.c"
#undef func_800F96E0

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FDCAC);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FDCE8);
// clang-format on

#define func_8003744C func_800FDD90
#define D_80073C1C D_800FFCF4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F98A0 func_800FDDCC
#include "../shared/rock_11/func_800F98A0.c"
#undef func_800F98A0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800FB378(); /* extern */

void func_800FDE0C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 0x8A) = 0;
        func_800FB378();
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FDE3C(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FDE50(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FDE64(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800FB378(); /* extern */

void func_800FDE78(void) {
    func_800FB378();
}

#define func_8003744C func_800FDE98
#define D_80073C1C D_800FFD14
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800FDED4(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FDF0C);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FDFAC);
// clang-format on

#define func_800F9B24 func_800FE050
#include "../shared/rock_11/func_800F9B24.c"
#undef func_800F9B24

#define func_800F4BA8 func_800FE0AC
#include "../shared/rock_04/func_800F4BA8.c"
#undef func_800F4BA8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80040498(); /* extern */

void func_800FE0F0(void* arg0) {
    if (func_80040498() == 0) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F4D48 func_800FE12C
#include "../shared/rock_04/func_800F4D48.c"
#undef func_800F4D48

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();    /* extern */
M2C_UNK func_800FB378(s32); /* extern */

void func_800FE1B0(s32 arg0) {
    func_8003D330();
    func_800FB378(arg0);
}

#define func_8003744C func_800FE1DC
#define D_80073C1C D_800FFD3C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F9CEC func_800FE218
#include "../shared/rock_11/func_800F9CEC.c"
#undef func_800F9CEC

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FE2B8);
// clang-format on

#include "common.h"

void func_800FE2F4(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FE2FC);
// clang-format on

#define func_800F9E00 func_800FE32C
#include "../shared/rock_11/func_800F9E00.c"
#undef func_800F9E00

#define func_800F9EB4 func_800FE3E0
#include "../shared/rock_11/func_800F9EB4.c"
#undef func_800F9EB4

#define func_800F9F7C func_800FE4A8
#include "../shared/rock_11/func_800F9F7C.c"
#undef func_800F9F7C

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FE598);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FE67C);
// clang-format on

#define func_800FA234 func_800FE760
#define D_800FDA78 D_800FFE1C
#include "../shared/rock_11/func_800FA234.c"
#undef func_800FA234
#undef D_800FDA78

#define func_800FA31C func_800FE848
#include "../shared/rock_11/func_800FA31C.c"
#undef func_800FA31C

#define func_800FA418 func_800FE944
#include "../shared/rock_11/func_800FA418.c"
#undef func_800FA418

#define func_80042C18 func_800FE9F4
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#define func_800FA4F8 func_800FEA24
#include "../shared/rock_11/func_800FA4F8.c"
#undef func_800FA4F8

#define func_800FA584 func_800FEAB0
#define D_80097420 D_80097420
#include "../shared/rock_11/func_800FA584.c"
#undef func_800FA584
#undef D_80097420

#define func_800FA630 func_800FEB5C
#include "../shared/rock_11/func_800FA630.c"
#undef func_800FA630

#define func_800FA664 func_800FEB90
#define g_projectiles g_projectiles
#include "../shared/rock_11/func_800FA664.c"
#undef func_800FA664
#undef g_projectiles

#define func_800F54B8 func_800FEC58
#include "../shared/rock_04/func_800F54B8.c"
#undef func_800F54B8

#define func_800FA76C func_800FEC98
#define D_800FD490 D_800FFDA0
#include "../shared/rock_11/func_800FA76C.c"
#undef func_800FA76C
#undef D_800FD490

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800FED0C(void* arg0) {
    void* temp_v1;

    if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x20) {
        temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
        M2C_FIELD(temp_v1, u8*, 7) = (u8)(M2C_FIELD(temp_v1, u8*, 7) - 1);
    }
    clear_object_slot();
}

#define func_8003744C func_800FED58
#define D_80073C1C D_800FFDBC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FED94);

INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FEE08);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FEEF0(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_8003744C func_800FEF10
#define D_80073C1C D_800FFDD0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FEF4C);
// clang-format on

#define func_800FB068 func_800FF594
#define func_800FAA98 func_800FEFC4
#include "../shared/rock_11/func_800FAA98.c"
#undef func_800FAA98
#undef func_800FB068

#define func_8003744C func_800FF028
#define D_80073C1C D_800FFDD8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800FAB38 func_800FF064
#define D_800FD48C D_800FFD9C
#include "../shared/rock_11/func_800FAB38.c"
#undef func_800FAB38
#undef D_800FD48C

#define func_800FABA0 func_800FF0CC
#include "../shared/rock_11/func_800FABA0.c"
#undef func_800FABA0

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FF124(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_8003744C func_800FF140
#define D_80073C1C D_800FFDE4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FF17C);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800FF204(void) {
    move_object();
}

#define func_800FACF8 func_800FF224
#define D_800FD4E8 D_800FFDF8
#include "../shared/rock_11/func_800FACF8.c"
#undef func_800FACF8
#undef D_800FD4E8

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FF2BC(void) {
    clear_object_slot();
}

#define func_800FADB0 func_800FF2DC
#define D_800FD4F4 D_800FFE04
#include "../shared/rock_11/func_800FADB0.c"
#undef func_800FADB0
#undef D_800FD4F4

#define func_800FAE34 func_800FF360
#include "../shared/rock_11/func_800FAE34.c"
#undef func_800FAE34

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FF438(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s8*, 3) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FF46C(void* arg0) {
    void* temp_a0;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, u8*, 3) = 0U;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    temp_a0 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a0, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a0, u16*, 0xE);
    M2C_FIELD(arg0, u8*, 3) = (u8)M2C_FIELD(temp_a0, u8*, 3);
}

#define func_8003744C func_800FF4C0
#define D_80073C1C D_800FFE10
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 is_off_screen(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object();                      /* extern */

void func_800FF4FC(void* arg0) {
    move_object();
    if (is_off_screen(arg0, 0x20, 0x20) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", func_800FF54C);
// clang-format on

#define func_800FB068 func_800FF594
#include "../shared/rock_11/func_800FB068.c"
#undef func_800FB068

// clang-format off
INCLUDE_ASM("asm/rock_40/nonmatchings/FA000", D_800FF668);
// clang-format on
