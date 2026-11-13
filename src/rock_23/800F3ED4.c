#define func_80041AB8 func_800F3ED4
#define D_80075FD8 D_800F99A8
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_800F5208 func_800F3F10
#include "../shared/rock_02/func_800F5208.c"
#undef func_800F5208

#define func_800F527C func_800F3F84
#include "../shared/rock_02/func_800F527C.c"
#undef func_800F527C

#define func_8003744C func_800F4088
#define D_80073C1C D_800F99B4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F40C4(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F40D8);

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F4128);

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F41A4);
// clang-format on

#define func_800F5568 func_800F4270
#include "../shared/rock_02/func_800F5568.c"
#undef func_800F5568

#define func_800F55EC func_800F42F4
#include "../shared/rock_02/func_800F55EC.c"
#undef func_800F55EC

// clang-format off
#include "../shared/rock_23/func_800F4400.c"
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*); /* extern */
M2C_UNK func_8003D330();       /* extern */
void func_800F6FC8();          /* extern */

void func_800F4468(void* arg0) {
    func_800F6FC8();
    animate_object(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_8003D330();
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
        M2C_FIELD(arg0, s32*, 0x2C) = -0x1000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F57C8 func_800F44D0
#define background_objects background_objects
#include "../shared/rock_02/func_800F57C8.c"
#undef func_800F57C8
#undef background_objects

#define func_8003744C func_800F453C
#define D_80073C1C D_800F99E4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4578(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFC0000;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800F588C func_800F4594
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
extern s16 D_80097222;

void func_800F4594(void* arg0) {
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
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F4614);
// clang-format on

#define func_800F5950 func_800F4658
#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(void*);

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F4658(void* arg0) {
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

#define func_800F59C0 func_800F46C8
#include "../shared/rock_02/func_800F59C0.c"
#undef func_800F59C0

#define func_800F5A60 func_800F4768
#define background_objects background_objects
#include "../shared/rock_02/func_800F5A60.c"
#undef func_800F5A60
#undef background_objects

#define func_800F5AFC func_800F4804
#include "../shared/rock_02/func_800F5AFC.c"
#undef func_800F5AFC

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F4838);
// clang-format on

#define func_8003744C func_800F48C8
#define D_80073C1C D_800F9A04
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5BFC func_800F4904
#include "../shared/rock_02/func_800F5BFC.c"
#undef func_800F5BFC

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F4948);
// clang-format on

#define func_8003744C func_800F49CC
#define D_80073C1C D_800F9A0C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5D00 func_800F4A08
#include "../shared/rock_02/func_800F5D00.c"
#undef func_800F5D00

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F4A4C);
// clang-format on

#define func_8003744C func_800F4ADC
#define D_80073C1C D_800F9A18
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5E10 func_800F4B18
#include "../shared/rock_02/func_800F5E10.c"
#undef func_800F5E10

#define func_800F5E5C func_800F4B64
#include "../shared/rock_02/func_800F5E5C.c"
#undef func_800F5E5C

#define func_800F5EE8 func_800F4BF0
#include "../shared/rock_02/func_800F5EE8.c"
#undef func_800F5EE8

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F4CDC);

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F4D60);
// clang-format on

#define func_8003744C func_800F4DF8
#define D_80073C1C D_800F9A2C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F612C func_800F4E34
#define D_800E9B48 D_800E9970
#include "../shared/rock_02/func_800F612C.c"
#undef func_800F612C
#undef D_800E9B48

#define func_800F6268 func_800F4F70
#include "../shared/rock_02/func_800F6268.c"
#undef func_800F6268

#define func_800F6328 func_800F5030
#include "../shared/rock_02/func_800F6328.c"
#undef func_800F6328

#define func_800F6400 func_800F5108
#include "../shared/rock_02/func_800F6400.c"
#undef func_800F6400

#define func_8003744C func_800F51C8
#define D_80073C1C D_800F9A48
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F82C0 func_800F6FC8_s32
#define func_800F64FC func_800F5204
#include "../shared/rock_02/func_800F64FC.c"
#undef func_800F64FC
#undef func_800F82C0

#define func_800F6548 func_800F5250
#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
extern u16 D_8009721A;
#define D_8009721A (*(s16*)&D_8009721A)

void func_800F5250(u8* arg0) {
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

void func_800F52AC(struct ObjectHeader* arg0) {
    if (D_8008EAFC == 0) {
        D_800CCEDF = 0x40;
        arg0->on_screen = 0;
        clear_object_slot();
    }
}

#define func_8003744C func_800F52E4
#define D_80073C1C D_800F9A60
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F6618 func_800F5320
#include "../shared/rock_02/func_800F6618.c"
#undef func_800F6618

#define func_800F6684 func_800F538C
#include "../shared/rock_02/func_800F6684.c"
#undef func_800F6684

#define func_800F6708 func_800F5410
#include "../shared/rock_02/func_800F6708.c"
#undef func_800F6708

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F5518);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*); /* extern */
void func_800F6FC8();          /* extern */

void func_800F5580(void* arg0) {
    func_800F6FC8();
    animate_object(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFC0000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F68CC func_800F55D4
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object(void*);
extern s16 D_80097222;

void func_800F55D4(void* arg0) {
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
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F565C);
// clang-format on

#define func_800F59C0 func_800F56AC
#include "../shared/rock_02/func_800F59C0.c"
#undef func_800F59C0

#define func_800F5A60 func_800F574C
#define background_objects background_objects
#include "../shared/rock_02/func_800F5A60.c"
#undef func_800F5A60
#undef background_objects

#define func_800F6AE0 func_800F57E8
#define D_8007523C D_8007523C
#include "../shared/rock_02/func_800F6AE0.c"
#undef func_800F6AE0
#undef D_8007523C

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F5828);
// clang-format on

#define func_8003744C func_800F58E8
#define D_80073C1C D_800F9A8C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F6C1C func_800F5924
#include "../shared/rock_02/func_800F6C1C.c"
#undef func_800F6C1C

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F5A20);
// clang-format on

#define func_800F6DA8 func_800F5AB0
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK animate_object();
M2C_UNK move_object(void*);
extern s16 D_80097222;

void func_800F5AB0(void* arg0) {
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
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F5B58);

#include "../shared/rock_23/func_800F5BE8.c"

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F5C48);

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F5CE8);
// clang-format on

#define func_8003744C func_800F5D7C
#define D_80073C1C D_800F9AB4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F70B0 func_800F5DB8
#define background_objects background_objects
#include "../shared/rock_02/func_800F70B0.c"
#undef func_800F70B0
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F5E34);

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F5EAC);
// clang-format on

#define func_8003744C func_800F5F44
#define D_80073C1C D_800F9AC8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_23/func_800F5F80.c"

#define func_800F72F4 func_800F5FFC
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
extern s16 D_80097222;

void func_800F5FFC(void* arg0) {
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
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F607C);
// clang-format on

#define func_800F59C0 func_800F60CC
#include "../shared/rock_02/func_800F59C0.c"
#undef func_800F59C0

#define func_800F5A60 func_800F616C
#define background_objects background_objects
#include "../shared/rock_02/func_800F5A60.c"
#undef func_800F5A60
#undef background_objects

#define func_800F7500 func_800F6208
#include "../shared/rock_02/func_800F7500.c"
#undef func_800F7500

#define func_8003744C func_800F623C
#define D_80073C1C D_800F9AE4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F7570 func_800F6278
#include "../shared/rock_02/func_800F7570.c"
#undef func_800F7570

#define func_800F7624 func_800F632C
#include "../shared/rock_02/func_800F7624.c"
#undef func_800F7624

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F63B0);

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F6418);
// clang-format on

#define func_8003744C func_800F6484
#define D_80073C1C D_800F9AF8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F77B8 func_800F64C0
#include "../shared/rock_02/func_800F77B8.c"
#undef func_800F77B8

#define func_800F7818 func_800F6520
#include "../shared/rock_02/func_800F7818.c"
#undef func_800F7818

#define func_800F78DC func_800F65E4
#include "../shared/rock_02/func_800F78DC.c"
#undef func_800F78DC

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F6678);

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F670C);

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F6764);
// clang-format on

#define func_8003744C func_800F67F8
#define D_80073C1C D_800F9B10
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F7B2C func_800F6834
#include "../shared/rock_02/func_800F7B2C.c"
#undef func_800F7B2C

#define func_800F7B9C func_800F68A4
#include "../shared/rock_02/func_800F7B9C.c"
#undef func_800F7B9C

#define func_800F7C64 func_800F696C
#include "../shared/rock_02/func_800F7C64.c"
#undef func_800F7C64

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F6A04);

#include "../shared/rock_23/func_800F6AA4.c"

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F6B70);
// clang-format on

#define func_8003744C func_800F6BC8
#define D_80073C1C D_800F9B28
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F7B2C func_800F6C04
#include "../shared/rock_02/func_800F7B2C.c"
#undef func_800F7B2C

#define func_800F7F6C func_800F6C74
#include "../shared/rock_02/func_800F7F6C.c"
#undef func_800F7F6C

#define func_800F8044 func_800F6D4C
#include "../shared/rock_02/func_800F8044.c"
#undef func_800F8044

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F6DCC);

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F6E68);

INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F6F34);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif
#define SPAD (*(u8**)0x1F80004C)

#include "mmx6/state.h"
extern u8 D_800F9B40[];

void func_800F6FC8(void* arg0) {
    if (!(*(u8*)&D_80097420 & 1)) {
        M2C_FIELD(arg0, u16*, 0xE) +=
            (s8)D_800F9B40[M2C_FIELD(SPAD, s8*, 0x8C)];
        M2C_FIELD(SPAD, u8*, 0x8C) = (M2C_FIELD(SPAD, u8*, 0x8C) + 1) & 0xF;
    }
}

#include "common.h"

void func_800F7038(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F7040);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();     /* extern */
M2C_UNK move_object(void*);   /* extern */
M2C_UNK func_8002EE10(void*); /* extern */
s32 check_enemy_hits(void*);  /* extern */
M2C_UNK func_80049D90(void*); /* extern */

void func_800F709C(struct MainObj* arg0) {
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
extern M2C_UNK D_800F9414;
extern M2C_UNK D_800F9420;
extern M2C_UNK D_800F942C;

void func_800F7110(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F9414;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F9420;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_800F942C;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800F8468 func_800F7170
#define D_800754BC D_800754BC
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object(void*);
extern s32 D_800754BC;

void func_800F7170(void* arg0) {
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

#define func_800F84F4 func_800F71FC
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK animate_object();
M2C_UNK move_object(void*);

void func_800F71FC(struct X4_MainObj* self) {
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

void func_800F7288(void* arg0) {
    u8 temp_v0;

    ((M2C_UNK(*)())animate_object)();
    temp_v0 = M2C_FIELD(arg0, u8*, 0x8E);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = (u8)(temp_v0 - 1);
        return;
    }
    move_object(arg0);
}

#define func_800F85C4 func_800F72CC
#include "../shared/rock_02/func_800F85C4.c"
#undef func_800F85C4

#define func_800F8684 func_800F738C
#include "../shared/rock_02/func_800F8684.c"
#undef func_800F8684

#define func_800F86D0 func_800F73D8
#include "../shared/rock_02/func_800F86D0.c"
#undef func_800F86D0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800F741C(struct ObjectHeader* arg0) {
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

void func_800F7494(void* arg0) {
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

#define func_800F87FC func_800F7504
#define D_800FB310 D_800F9420
#include "../shared/rock_02/func_800F87FC.c"
#undef func_800F87FC
#undef D_800FB310

#define func_800F88FC func_800F7604
#include "../shared/rock_02/func_800F88FC.c"
#undef func_800F88FC

#define func_8003744C func_800F767C
#define D_80073C1C D_800F9B64
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F88FC func_800F76B8
#include "../shared/rock_02/func_800F88FC.c"
#undef func_800F88FC

#define func_800F8A28 func_800F7730
#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object();

void func_800F7730(u8* arg0) {
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

#define func_800F8A80 func_800F7788
#define g_Player g_Player
#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK move_object();
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800F7788(void* arg0) {
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

void func_800F784C(void) {
    ((M2C_UNK(*)())animate_object)();
}

#define func_8003744C func_800F786C
#define D_80073C1C D_800F9B6C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F8BA0 func_800F78A8
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object();
extern u16 D_8009721A;

void func_800F78A8(void* arg0) {
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

#define func_800F8C24 func_800F792C
#include "../shared/rock_02/func_800F8C24.c"
#undef func_800F8C24

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800F7988(void* arg0) {
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

void func_800F7A1C(void* arg0) {
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

#define func_800F8DB8 func_800F7AC0
#include "../shared/rock_02/func_800F8DB8.c"
#undef func_800F8DB8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800F7B30(void* arg0) {
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
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", func_800F7BBC);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                   /* extern */
s32 is_off_screen(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(void*);                 /* extern */

void func_800F7C6C(void* arg0) {
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

#define func_800F85C4 func_800F7CF8
#include "../shared/rock_02/func_800F85C4.c"
#undef func_800F85C4

#define func_800F90B0 func_800F7DB8
#include "../shared/rock_02/func_800F90B0.c"
#undef func_800F90B0

// clang-format off
INCLUDE_ASM("asm/rock_23/nonmatchings/E9860", D_800F7E04);
// clang-format on
