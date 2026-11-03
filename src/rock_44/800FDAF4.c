#define func_80041AB8 func_800FDAF4
#define D_80075FD8 D_80101FD4
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_800F5208 func_800FDB30
#include "../shared/rock_02/func_800F5208.c"
#undef func_800F5208

#define func_800F527C func_800FDBA4
#include "../shared/rock_02/func_800F527C.c"
#undef func_800F527C

#define func_8003744C func_800FDCA8
#define D_80073C1C D_80101FE0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FDCE4(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FDCF8);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FDD48);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FDDC4);
// clang-format on

#define func_800F5568 func_800FDE90
#include "../shared/rock_02/func_800F5568.c"
#undef func_800F5568

#define func_800F55EC func_800FDF14
#include "../shared/rock_02/func_800F55EC.c"
#undef func_800F55EC

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FE020);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*); /* extern */
M2C_UNK func_8003D330();       /* extern */
M2C_UNK func_80100BE8();       /* extern */

void func_800FE088(void* arg0) {
    func_80100BE8();
    animate_object(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_8003D330();
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
        M2C_FIELD(arg0, s32*, 0x2C) = -0x1000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F57C8 func_800FE0F0
#define background_objects background_objects
#include "../shared/rock_02/func_800F57C8.c"
#undef func_800F57C8
#undef background_objects

#define func_8003744C func_800FE15C
#define D_80073C1C D_80102010
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FE198(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFC0000;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800F588C func_800FE1B4
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
extern s16 D_80097222;

void func_800FE1B4(void* arg0) {
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x70) {
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x70;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x40000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFC0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x100;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800F588C

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FE234);
// clang-format on

#define func_800F5950 func_800FE278
#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(void*);

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800FE278(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    move_object((s32)arg0);
    if (F(s8, arg0, 0x45) == 1) {
        if (F(u8, arg0, 0x15) != 0) {
            F(s32, arg0, 0x20) = 0x40000;
        } else {
            F(s32, arg0, 0x20) = 0xFFFC0000;
        }
        F(s32, arg0, 0x28) = 0x100;
        F(s32, arg0, 0x24) = 0;
        F(s32, arg0, 0x2C) = 0;
        F(u8, arg0, 6) = F(u8, arg0, 6) + 1;
    }
}
#undef func_800F5950

#define func_800F59C0 func_800FE2E8
#include "../shared/rock_02/func_800F59C0.c"
#undef func_800F59C0

#define func_800F5A60 func_800FE388
#define background_objects background_objects
#include "../shared/rock_02/func_800F5A60.c"
#undef func_800F5A60
#undef background_objects

#define func_800F5AFC func_800FE424
#include "../shared/rock_02/func_800F5AFC.c"
#undef func_800F5AFC

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FE458);
// clang-format on

#define func_8003744C func_800FE4E8
#define D_80073C1C D_80102030
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5BFC func_800FE524
#include "../shared/rock_02/func_800F5BFC.c"
#undef func_800F5BFC

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FE568);
// clang-format on

#define func_8003744C func_800FE5EC
#define D_80073C1C D_80102038
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5D00 func_800FE628
#include "../shared/rock_02/func_800F5D00.c"
#undef func_800F5D00

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FE66C);
// clang-format on

#define func_8003744C func_800FE6FC
#define D_80073C1C D_80102044
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5E10 func_800FE738
#include "../shared/rock_02/func_800F5E10.c"
#undef func_800F5E10

#define func_800F5E5C func_800FE784
#include "../shared/rock_02/func_800F5E5C.c"
#undef func_800F5E5C

#define func_800F5EE8 func_800FE810
#include "../shared/rock_02/func_800F5EE8.c"
#undef func_800F5EE8

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FE8FC);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FE980);
// clang-format on

#define func_8003744C func_800FEA18
#define D_80073C1C D_80102058
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F612C func_800FEA54
#define D_800E9B48 D_800FA004
#include "../shared/rock_02/func_800F612C.c"
#undef func_800F612C
#undef D_800E9B48

#define func_800F6268 func_800FEB90
#include "../shared/rock_02/func_800F6268.c"
#undef func_800F6268

#define func_800F6328 func_800FEC50
#include "../shared/rock_02/func_800F6328.c"
#undef func_800F6328

#define func_800F6400 func_800FED28
#include "../shared/rock_02/func_800F6400.c"
#undef func_800F6400

#define func_8003744C func_800FEDE8
#define D_80073C1C D_80102074
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F82C0 func_80100BE8
#define func_800F64FC func_800FEE24
#include "../shared/rock_02/func_800F64FC.c"
#undef func_800F64FC
#undef func_800F82C0

#define func_800F6548 func_800FEE70
#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
extern u16 D_8009721A;
#define D_8009721A (*(s16*)&D_8009721A)

void func_800FEE70(u8* arg0) {
    s32 lim;
    s32 y;
    ((void (*)(s32))move_object)((s32)arg0);
    lim = D_8009721A - 0x60;
    y = *(s16*)(arg0 + 0xE);
    y = y < lim;
    if (y) {
        // !FAKE: inherited from src/shared/rock_02/func_800F6548.c
        // !FAKE: depin: dropping it breaks the match (20/23)
        register s32 c asm("$2");
        open_text_box(6, 0xFF, 0);
        c = arg0[6];
        arg0[3] = 0;
        arg0[6] = c + 1;
    }
}
#undef D_8009721A
#undef func_800F6548

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800FEECC(struct ObjectHeader* arg0) {
    if (D_8008EAFC == 0) {
        D_800CCEDF = 0x40;
        arg0->on_screen = 0;
        clear_object_slot();
    }
}

#define func_8003744C func_800FEF04
#define D_80073C1C D_8010208C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F6618 func_800FEF40
#include "../shared/rock_02/func_800F6618.c"
#undef func_800F6618

#define func_800F6684 func_800FEFAC
#include "../shared/rock_02/func_800F6684.c"
#undef func_800F6684

#define func_800F6708 func_800FF030
#include "../shared/rock_02/func_800F6708.c"
#undef func_800F6708

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FF138);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*); /* extern */
M2C_UNK func_80100BE8();       /* extern */

void func_800FF1A0(void* arg0) {
    func_80100BE8();
    animate_object(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFC0000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F68CC func_800FF1F4
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object(void*);
extern s16 D_80097222;

void func_800FF1F4(void* arg0) {
    animate_object(arg0);
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x70) {
        M2C_FIELD(arg0, s16*, 0xE) = (u16)D_80097222 + 0x70;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFA0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x100;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
#undef func_800F68CC

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FF27C);
// clang-format on

#define func_800F59C0 func_800FF2CC
#include "../shared/rock_02/func_800F59C0.c"
#undef func_800F59C0

#define func_800F5A60 func_800FF36C
#define background_objects background_objects
#include "../shared/rock_02/func_800F5A60.c"
#undef func_800F5A60
#undef background_objects

#define func_800F6AE0 func_800FF408
#define D_8007523C D_8007523C
#include "../shared/rock_02/func_800F6AE0.c"
#undef func_800F6AE0
#undef D_8007523C

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FF448);
// clang-format on

#define func_8003744C func_800FF508
#define D_80073C1C D_801020B8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F6C1C func_800FF544
#include "../shared/rock_02/func_800F6C1C.c"
#undef func_800F6C1C

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FF640);
// clang-format on

#define func_800F6DA8 func_800FF6D0
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK animate_object();
M2C_UNK move_object(void*);
extern s16 D_80097222;

void func_800FF6D0(void* arg0) {
    u8* sp;

    sp = SPAD4C;
    if (M2C_FIELD(sp, s8*, 0x89) == 0) {
        M2C_FIELD(sp, s8*, 0x89) = 0x78;
    }
    animate_object(arg0);
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x74) {
        M2C_FIELD(arg0, s16*, 0xE) = (u16)D_80097222 + 0x74;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFA0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x1000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
#undef func_800F6DA8

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FF778);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FF808);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FF868);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FF908);
// clang-format on

#define func_8003744C func_800FF99C
#define D_80073C1C D_801020E0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F70B0 func_800FF9D8
#define background_objects background_objects
#include "../shared/rock_02/func_800F70B0.c"
#undef func_800F70B0
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FFA54);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FFACC);
// clang-format on

#define func_8003744C func_800FFB64
#define D_80073C1C D_801020F4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5F80 func_800FFBA0
#include "../shared/rock_23/func_800F5F80.c"
#undef func_800F5F80

#define func_800F72F4 func_800FFC1C
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
extern s16 D_80097222;

void func_800FFC1C(void* arg0) {
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x70) {
        M2C_FIELD(arg0, s16*, 0xE) = (u16)D_80097222 + 0x70;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFA0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x100;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800F72F4

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FFC9C);
// clang-format on

#define func_800F59C0 func_800FFCEC
#include "../shared/rock_02/func_800F59C0.c"
#undef func_800F59C0

#define func_800F5A60 func_800FFD8C
#define background_objects background_objects
#include "../shared/rock_02/func_800F5A60.c"
#undef func_800F5A60
#undef background_objects

#define func_800F7500 func_800FFE28
#include "../shared/rock_02/func_800F7500.c"
#undef func_800F7500

#define func_8003744C func_800FFE5C
#define D_80073C1C D_80102110
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F7570 func_800FFE98
#include "../shared/rock_02/func_800F7570.c"
#undef func_800F7570

#define func_800F7624 func_800FFF4C
#include "../shared/rock_02/func_800F7624.c"
#undef func_800F7624

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_800FFFD0);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_80100038);
// clang-format on

#define func_8003744C func_801000A4
#define D_80073C1C D_80102124
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F77B8 func_801000E0
#include "../shared/rock_02/func_800F77B8.c"
#undef func_800F77B8

#define func_800F7818 func_80100140
#include "../shared/rock_02/func_800F7818.c"
#undef func_800F7818

#define func_800F78DC func_80100204
#include "../shared/rock_02/func_800F78DC.c"
#undef func_800F78DC

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_80100298);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_8010032C);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_80100384);
// clang-format on

#define func_8003744C func_80100418
#define D_80073C1C D_8010213C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F7B2C func_80100454
#include "../shared/rock_02/func_800F7B2C.c"
#undef func_800F7B2C

#define func_800F7B9C func_801004C4
#include "../shared/rock_02/func_800F7B9C.c"
#undef func_800F7B9C

#define func_800F7C64 func_8010058C
#include "../shared/rock_02/func_800F7C64.c"
#undef func_800F7C64

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_80100624);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_801006C4);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_80100790);
// clang-format on

#define func_8003744C func_801007E8
#define D_80073C1C D_80102154
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F7B2C func_80100824
#include "../shared/rock_02/func_800F7B2C.c"
#undef func_800F7B2C

#define func_800F7F6C func_80100894
#include "../shared/rock_02/func_800F7F6C.c"
#undef func_800F7F6C

#define func_800F8044 func_8010096C
#include "../shared/rock_02/func_800F8044.c"
#undef func_800F8044

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_801009EC);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_80100A88);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_80100B54);

INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_80100BE8);
// clang-format on

#include "common.h"

void func_80100C58(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_80100C60);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();     /* extern */
M2C_UNK move_object(void*);   /* extern */
M2C_UNK func_8002EE10(void*); /* extern */
s32 check_enemy_hits(void*);  /* extern */
M2C_UNK func_80049D90(void*); /* extern */

void func_80100CBC(struct MainObj* arg0) {
    ((M2C_UNK(*)())animate_object)();
    move_object(arg0);
    if ((check_enemy_hits(arg0) < 0) || (arg0->collision_flags != 0) ||
        (func_8002EE10(arg0), (arg0->collision_flags != 0))) {
        func_80049D90(arg0);
        arg0->state = 2;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
extern M2C_UNK D_80101A40;
extern M2C_UNK D_80101A4C;
extern M2C_UNK D_80101A58;

void func_80100D30(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_80101A40;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_80101A4C;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_80101A58;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800F8468 func_80100D90
#define D_800754BC D_800754BC
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object(void*);
extern s32 D_800754BC;

void func_80100D90(void* arg0) {
    // !FAKE: inherited from src/shared/rock_02/func_800F8468.c
    register s32 v asm("$2");

    animate_object(arg0);
    if (M2C_FIELD(arg0, u8*, 0x8E) != 0) {
        M2C_FIELD(arg0, u8*, 0x8E)--;
        return;
    }
    M2C_FIELD(arg0, s32**, 0x58) = &D_800754BC;
    move_object(arg0);
    v = M2C_FIELD(arg0, u8*, 0x70) & 8;
    if (v) {
        v = M2C_FIELD(arg0, u8*, 0x15);
        if (v == 0) {
            v = 0xFFFD0000;
        } else {
            v = 0x30000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = v;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        v = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = v + 1;
    }
}
#undef func_800F8468
#undef D_800754BC

#define func_800F84F4 func_80100E1C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK animate_object();
M2C_UNK move_object(void*);

void func_80100E1C(struct X4_MainObj* self) {
    u8 t;
    s32 v;

    animate_object(self);
    t = ((u8*)self)[0x8E];
    if (t != 0) {
        ((u8*)self)[0x8E] = t - 1;
        return;
    }
    move_object((s32)self);
    v = self->unk15;
    if (v == 0) {
        v = self->collision_flags & 2;
    } else {
        v = self->collision_flags & 1;
    }
    if (v != 0) {
        self->x_speed = 0;
        self->y_speed = 0x30000;
        self->terrain_box = 0;
        self->action_phase++;
    }
}
#undef func_800F84F4

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();   /* extern */
M2C_UNK move_object(void*); /* extern */

void func_80100EA8(void* arg0) {
    u8 temp_v0;

    ((M2C_UNK(*)())animate_object)();
    temp_v0 = M2C_FIELD(arg0, u8*, 0x8E);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = (u8)(temp_v0 - 1);
        return;
    }
    move_object(arg0);
}

#define func_800F85C4 func_80100EEC
#include "../shared/rock_02/func_800F85C4.c"
#undef func_800F85C4

#define func_800F8684 func_80100FAC
#include "../shared/rock_02/func_800F8684.c"
#undef func_800F8684

#define func_800F86D0 func_80100FF8
#include "../shared/rock_02/func_800F86D0.c"
#undef func_800F86D0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_8010103C(struct ObjectHeader* arg0) {
    void* temp_a1;

    ((M2C_UNK(*)())animate_object)();
    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    if (((M2C_FIELD(temp_a1, s32*, 4) & 0xFFFF00) == 0xB0200) ||
        ((M2C_FIELD(temp_a1, s8*, 5) == 9) &&
         (M2C_FIELD(temp_a1, s8*, 6) >= 4))) {
        arg0->on_screen = 0;
        arg0->state = 2;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_801010B4(void* arg0) {
    void* temp_a1;

    ((M2C_UNK(*)())animate_object)();
    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
    if ((M2C_FIELD(temp_a1, s8*, 5) == 0xA) &&
        (M2C_FIELD(temp_a1, s8*, 6) >= 9)) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_800F87FC func_80101124
#define D_800FB310 D_80101A4C
#include "../shared/rock_02/func_800F87FC.c"
#undef func_800F87FC
#undef D_800FB310

#define func_800F88FC func_80101224
#include "../shared/rock_02/func_800F88FC.c"
#undef func_800F88FC

#define func_8003744C func_8010129C
#define D_80073C1C D_80102190
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F88FC func_801012D8
#include "../shared/rock_02/func_800F88FC.c"
#undef func_800F88FC

#define func_800F8A28 func_80101350
#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object();

void func_80101350(u8* arg0) {
    ((M2C_UNK(*)())animate_object)();
    move_object((s32)arg0);
    {
        // !FAKE: decrement temp lands in the first return register as retail
        register s32 temp_v0 asm("$2") = arg0[0x8D] - 1;
        arg0[0x8D] = temp_v0;
        if (!(temp_v0 & 0xFF)) {
            arg0[6]++;
        }
    }
}
#undef func_800F8A28

#define func_800F8A80 func_801013A8
#define g_Player g_Player
#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK move_object();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_801013A8(void* arg0) {
    s32 ang;

    ((M2C_UNK(*)())animate_object)();
    {
        s32 u = M2C_FIELD(arg0, u8*, 7);
        // !FAKE: inherited from src/shared/rock_02/func_800F8A80.c
        register s32 t asm("$2") = M2C_FIELD(arg0, s8*, 7);
        if (t != 0) {
            s32 c = u - 1;
            M2C_FIELD(arg0, s8*, 7) = c;
            if ((s8)c == 0) {
                ang = ratan2(g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                             g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
                {
                    s32 t;
                    s32 w;
                    s32 u;
                    s32 x;
                    t = rcos(ang);
                    w = t << 4;
                    M2C_FIELD(arg0, s32*, 0x20) = (t << 6) + w;
                    u = -rsin(ang);
                    x = u << 4;
                    M2C_FIELD(arg0, s32*, 0x24) = (u << 6) + x;
                }
                play_sound(2, 0x7D, arg0);
            }
        } else {
            move_object((s32)arg0);
        }
    }
}
#undef g_Player
#undef func_800F8A80
#undef g_Player

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */

void func_8010146C(void) {
    ((M2C_UNK(*)())animate_object)();
}

#define func_8003744C func_8010148C
#define D_80073C1C D_80102198
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F8BA0 func_801014C8
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object();
extern u16 D_8009721A;

void func_801014C8(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (s16)D_8009721A + 0x88) {
        M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x88;
        play_sound(2, 0x80, arg0);
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        func_80029478(0x1E, 2, 2);
        {
            // !FAKE: inherited from src/shared/rock_02/func_800F8BA0.c
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}
#undef func_800F8BA0

#define func_800F8C24 func_8010154C
#include "../shared/rock_02/func_800F8C24.c"
#undef func_800F8C24

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_801015A8(void* arg0) {
    u8 temp_v1;
    u8 var_v0;
    void* temp_s0;

    temp_s0 = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())animate_object)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(temp_v1 - 1);
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    M2C_FIELD(temp_s0, s8*, 0x88) = 1;
    if (M2C_FIELD(arg0, s8*, 2) == 9) {
        var_v0 = M2C_FIELD(temp_s0, u8*, 0x8A) & 0xF0;
    } else {
        var_v0 = M2C_FIELD(temp_s0, u8*, 0x8A) & 0xF;
    }
    M2C_FIELD(temp_s0, u8*, 0x8A) = var_v0;
    M2C_FIELD(arg0, s8*, 4) = 2;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                                /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_8010163C(void* arg0) {
    s32 var_s0;
    u8 temp_v1;

    ((M2C_UNK(*)())animate_object)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        if (!(temp_v1 & 7)) {
            func_80049EBC(arg0, 1, 0x20, 0x40);
        }
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(M2C_FIELD(arg0, u8*, 0x8D) - 1);
        return;
    }
    var_s0 = 3;
    do {
        func_80049EBC(arg0, 1, 0x20, 0x40);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    M2C_FIELD(arg0, s8*, 4) = 2;
}

#define func_800F8DB8 func_801016E0
#include "../shared/rock_02/func_800F8DB8.c"
#undef func_800F8DB8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_80101750(void* arg0) {
    u8 temp_v1;
    u8 var_v0;
    void* temp_s0;

    temp_s0 = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())animate_object)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(temp_v1 - 1);
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 9) {
        var_v0 = M2C_FIELD(temp_s0, u8*, 0x8A) & 0xF0;
    } else {
        var_v0 = M2C_FIELD(temp_s0, u8*, 0x8A) & 0xF;
    }
    M2C_FIELD(temp_s0, u8*, 0x8A) = var_v0;
    M2C_FIELD(arg0, s8*, 4) = 2;
}

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_801017DC);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                   /* extern */
s32 is_off_screen(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(void*);                 /* extern */

void func_8010188C(void* arg0) {
    M2C_UNK* var_v0;
    u8 temp_v0;

    ((M2C_UNK(*)())animate_object)();
    temp_v0 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(temp_v0 - 1);
        return;
    }
    if (D_80097187 == 2) {
        var_v0 = &D_8007537C;
    } else {
        var_v0 = &D_800752DC;
    }
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = var_v0;
    move_object(arg0);
    if (is_off_screen(arg0, 0x30, 0x30) == 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_800F85C4 func_80101918
#include "../shared/rock_02/func_800F85C4.c"
#undef func_800F85C4

#define func_800F90B0 func_801019D8
#include "../shared/rock_02/func_800F90B0.c"
#undef func_800F90B0

// clang-format off
INCLUDE_ASM("asm/rock_44/nonmatchings/FA000", func_80101A24);
// clang-format on
