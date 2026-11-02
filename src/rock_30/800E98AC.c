// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800E98AC);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800E9A38);
// clang-format on

#define func_800EA178 func_800E9CC0
#include "../shared/rock_09/func_800EA178.c"
#undef func_800EA178

#define func_800EA1D8 func_800E9F18
#define D_800FAA64 D_800EF844
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800E9F64);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EA05C(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EA554 func_800EA09C
#include "../shared/rock_09/func_800EA554.c"
#undef func_800EA554

#define func_800EA5FC func_800EA144
#include "../shared/rock_09/func_800EA5FC.c"
#undef func_800EA5FC

#define func_800EA708 func_800EA250
#include "../shared/rock_09/func_800EA708.c"
#undef func_800EA708

#define func_800EA750 func_800EA298
#include "../shared/rock_09/func_800EA750.c"
#undef func_800EA750

#define func_800EA7CC func_800EA314
#include "../shared/rock_09/func_800EA7CC.c"
#undef func_800EA7CC

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EA35C(void) {
    clear_object_slot();
}

#define func_80048DC8 func_800EA37C
#define D_80077BC0 D_800EF88C
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s32 D_8007429C;
extern s32 g_Player;
extern s32 D_800EF998;
extern s32 D_800EF99C;
extern s32 D_800EF9A0;

void func_800EA3C8(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32**, 0x58) = &D_8007429C;
    M2C_FIELD(arg0, u8*, 0x16) = 5;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    set_animation(arg0, 2);
    {
        // !FAKE: depin: dropping it breaks the match (71/76)
        register s32* a asm("$2") = &D_800EF998;
        // !FAKE: depin: dropping it breaks the match (67/76)
        register s32* b asm("$3") = &D_800EF99C;
        M2C_FIELD(arg0, s32**, 0x68) = a;
        M2C_FIELD(arg0, s32**, 0x50) = b;
    }
    M2C_FIELD(arg0, s32**, 0x54) = &D_800EF9A0;
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) += 6;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x14;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) -= 6;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x14;
    }
    {
        struct X4_PlayerObj* p = &g_Player;
        s32 px = p->x_pos.i.hi;
        s32 py = p->y_pos.i.hi;
        ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
               px - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) += 1;
}

#define func_800EA9B0 func_800EA4F8
#include "../shared/rock_09/func_800EA9B0.c"
#undef func_800EA9B0

#define func_80041AB8 func_800EA69C
#define D_80075FD8 D_800EF958
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EA6D8
#define D_80075FD8 D_800EF9A4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EA714);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EA818);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EA8E8(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EA908(void) {
    func_8002CA54();
}

#define func_8003744C func_800EA928
#define D_80073C1C D_800EF978
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EA964);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EA9E0);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EAA54);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EAAD0);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EAB1C);
// clang-format on

#define func_800EB284 func_800EADCC
#define func_800EB048 func_800EAB90
#include "../shared/rock_09/func_800EB048.c"
#undef func_800EB048
#undef func_800EB284

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EAC00);
// clang-format on

#define func_800EB16C func_800EACB4
#define D_800970A8 D_800970A8
#include "../shared/rock_09/func_800EB16C.c"
#undef func_800EB16C
#undef D_800970A8

#include "common.h"

void func_800EAD1C(void) {
}

#include "common.h"

void func_800EAD24(void) {
}

#define func_800EB1E4 func_800EAD2C
#include "../shared/rock_09/func_800EB1E4.c"
#undef func_800EB1E4

#define func_80042C18 func_800EADCC
/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_65_magma_dragoon.c:magma_dragoon_face_player, AGPL-3.0; proven shared with X6 by exact signature 3d82c3af21bb (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EADCC(struct X4_MainObj* self) {
    if (g_Player.x_pos.i.hi > self->x_pos.i.hi) {
        self->unk15 = PLAYER_FACING_RIGHT;
    } else {
        self->unk15 = 0;
    }
}
#undef g_Player
#undef func_80042C18

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EADFC(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EAE1C);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EB01C);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EB140);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EB208);
// clang-format on

#include "common.h"

void func_800EB320(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EB328);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
extern s8 D_800CCEF8;
extern u8 D_800F00F8;

void func_800EB3E4(void* arg0) {
    if (D_800F00F8 == 3) {
        D_800CCEF8 = 1;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    func_8002CCB0(arg0, 0x28, 0x40);
}

#define func_800EB8F0 func_800EB438
#include "../shared/rock_09/func_800EB8F0.c"
#undef func_800EB8F0

#define func_800EB5A0 func_800EB45C
#define D_800F6A84 D_800EFBC8
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(void*);
extern void (*D_800EFBC8[])(void*);

void func_800EB45C(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800EFBC8[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    func_8002F288(arg0);
}
#undef func_800EB5A0
#undef D_800F6A84

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EB4BC);
// clang-format on

#include "common.h"

void func_800EB588(void) {
}

#include "common.h"

void func_800EB590(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EB598(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EB5A0 func_800EB5D8
#define D_800F6A84 D_800EFBE4
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(void*);
extern void (*D_800EFBE4[])(void*);

void func_800EB5D8(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800EFBE4[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    func_8002F288(arg0);
}
#undef func_800EB5A0
#undef D_800F6A84

#define func_800EBAF0 func_800EB638
#include "../shared/rock_09/func_800EBAF0.c"
#undef func_800EBAF0

#define func_800EBBD4 func_800EB71C
#include "../shared/rock_09/func_800EBBD4.c"
#undef func_800EBBD4

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EB81C(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EB5A0 func_800EB85C
#define D_800F6A84 D_800EFBF4
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(void*);
extern void (*D_800EFBF4[])(void*);

void func_800EB85C(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800EFBF4[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    func_8002F288(arg0);
}
#undef func_800EB5A0
#undef D_800F6A84

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EB8BC);
// clang-format on

#define func_800EBE60 func_800EB9A8
#include "../shared/rock_09/func_800EBE60.c"
#undef func_800EBE60

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EBAAC(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EBAEC);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EBC50);
// clang-format on

#define func_80041AB8 func_800EBDE4
#define D_80075FD8 D_800EFCB0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*, void*); /* extern */
M2C_UNK func_8002CA54(void*, void*); /* extern */
extern u16 D_800CCEDC;

void func_800EBE20(struct ObjectHeader* arg0) {
    if ((D_800CCEDC == 2) || (arg0->state == 3)) {
        func_8002CA54(arg0, arg0);
        return;
    }
    func_8002CA14(arg0, arg0);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EBE74(void* arg0) {
    M2C_FIELD(arg0, u8*, 5) = (u8)M2C_FIELD(arg0, u8*, 0x94);
}

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EBE80);
// clang-format on

#define func_800EC380 func_800EBEC8
#include "../shared/rock_09/func_800EC380.c"
#undef func_800EC380

#define func_800EC3B8 func_800EBF00
#define g_Player g_Player
#include "../shared/rock_09/func_800EC3B8.c"
#undef func_800EC3B8
#undef g_Player

#define func_8003744C func_800EBFD4
#define D_80073C1C D_800EFCF4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EC010);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EC060);
// clang-format on

#define func_800EC574 func_800EC0BC
#include "../shared/rock_09/func_800EC574.c"
#undef func_800EC574

#define func_8003744C func_800EC10C
#define D_80073C1C D_800EFD00
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EC148);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();  /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800EC1A4(s32 arg0) {
    func_80017A04();
    move_object(arg0);
}

#define func_8003744C func_800EC1D0
#define D_80073C1C D_800EFD08
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EC20C);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();  /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800EC278(s32 arg0) {
    func_80017A04();
    move_object(arg0);
}

#define func_8003744C func_800EC2A4
#define D_80073C1C D_800EFD10
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EC2E0);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC3DC(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
}

#define func_800EC8C0 func_800EC408
#include "../shared/rock_09/func_800EC8C0.c"
#undef func_800EC8C0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*); /* extern */
M2C_UNK move_object();        /* extern */

void func_800EC440(struct MainObj* arg0) {
    arg0->x_speed = 0;
    arg0->y_speed = 0x20000;
    ((M2C_UNK(*)())move_object)();
    func_80017A04(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EC478);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EC4C0);
// clang-format on

#define func_800EC9D0 func_800EC518
#define g_Player g_Player
#include "../shared/rock_09/func_800EC9D0.c"
#undef func_800EC9D0
#undef g_Player

#define func_800F32A8 func_800EC5B8
/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_13_heavy_mech.c:heavy_mech_face_player, AGPL-3.0; proven shared with X6 by exact signature d7798d86256f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EC5B8(struct X4_AnimatedObj* self) {
    if (self->x_pos.val > g_Player.x_pos.val) {
        self->unk15 = 0;
    } else {
        self->unk15 = PLAYER_FACING_RIGHT;
    }
}
#undef g_Player
#undef func_800F32A8

#define func_800ECAA0 func_800EC5E8
#include "../shared/rock_09/func_800ECAA0.c"
#undef func_800ECAA0

#define func_80041AB8 func_800EC690
#define D_80075FD8 D_800EFD2C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EC6CC);
// clang-format on

#define func_800ECC10 func_800EC758
#include "../shared/rock_09/func_800ECC10.c"
#undef func_800ECC10

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EC840(void) {
    clear_object_slot();
}

#include "common.h"

void func_800EC860(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EC868);
// clang-format on

#define func_80048DC8 func_800ECA3C
#define D_80077BC0 D_800EFD94
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800ECA88);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */

void func_800ECB34(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    ((M2C_UNK(*)())func_8002CA14)();
}

#include "common.h"

void func_800ECB54(void) {
}

#define func_800ED014 func_800ECB5C
#include "../shared/rock_09/func_800ED014.c"
#undef func_800ED014

#define func_800ED0B4 func_800ECBFC
#include "../shared/rock_09/func_800ED0B4.c"
#undef func_800ED0B4

#define func_800ED3E4 func_800ECCD4
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern u8 D_8008EAFC;
extern s32 g_Player;
extern s8 D_800CCEF6;

#define PL ((u8*)&g_Player)
#define F_S8(p, o) (*(s8*)((p) + (o)))
#define F_S16(p, o) (*(s16*)((p) + (o)))

void func_800ECCD4(u8* arg0) {
    u8* pl;
    s8 hp;
    s8 v;

    if (D_800CCEF6 == 0) {
        arg0[4]++;
        return;
    }
    pl = PL;
    if (F_S16(pl, 0x14C) != 0) {
        play_sound(5, 4, 0);
    }
    if (F_S8(pl, 0x5C) != 0 && F_S8(pl, 0xE0) == 0) {
        if (++*(u16*)(arg0 + 0x16) >= 0xB4) {
            *(u16*)(arg0 + 0x16) = 0;
            hp = F_S8(pl, 0x5C);
            v = F_S8(pl, 0x5C) & 0x7F;
            F_S8(pl, 0x5C) = v;
            if (D_8008EAFC == 0) {
                if (v < 2) {
                    F_S8(pl, 0x5C) = -0x80;
                } else {
                    F_S8(pl, 0x5C) = v - 1;
                }
            }
            if (hp < 0) {
                u8* q = PL;
                F_S8(q, 0x5C) |= 0x80;
            }
        }
        if (++*(u16*)(arg0 + 0x18) >= 0x33) {
            u8* q = PL;
            *(u16*)(arg0 + 0x18) = 0;
            F_S8(q, 0xE8) = 1;
        }
    }
}
#undef PL
#undef F_S8
#undef F_S16
#undef func_800ED3E4

#define func_800EE300 func_800ECE00
#define D_800F6DF0 D_800EFDAC
#include "../shared/rock_24/func_800EE300.c"
#undef func_800EE300
#undef D_800F6DF0

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800ECEA0);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800ECF78);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800ED038);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK load_palette(s32, M2C_UNK*, M2C_UNK);                 /* extern */
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32); /* extern */
extern s8 D_800CCEF6;
extern M2C_UNK D_800F00FC;
extern M2C_UNK D_800F011C;

void func_800ED104(void* arg0) {
    u16 temp_v0;

    if (D_800CCEF6 != 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) - 2);
        return;
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 0x1A);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u16*, 0x1A) = (u16)(temp_v0 - 1);
    }
    func_8002B410(&D_800F011C, &D_800F00FC, 0x10,
                  0x3C - M2C_FIELD(arg0, u16*, 0x1A), 0x3C);
    load_palette(M2C_FIELD(arg0, u16*, 0x20) + 0x60, &D_800F011C, 1);
    if (M2C_FIELD(arg0, u16*, 0x1A) == 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) - 3);
        play_sound(5, 3, 0);
    }
}

#define func_800ED92C func_800ED1C8
#include "../shared/rock_09/func_800ED92C.c"
#undef func_800ED92C

#define func_80041AB8 func_800ED2D0
#define D_80075FD8 D_800EFDC0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EDA70 func_800ED30C
#include "../shared/rock_09/func_800EDA70.c"
#undef func_800EDA70

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800ED358(void) {
    ((M2C_UNK(*)())func_8002CA14)();
}

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800ED378);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800ED500);

INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800ED698);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800ED714(void) {
    ((M2C_UNK(*)())func_8002CA54)();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

M2C_UNK func_8002CA14();
void func_800ED734(void* arg0) {
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
    ((M2C_UNK(*)())func_8002CA14)(arg0);
}

#define func_800EAA18 func_800ED7C8
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ED7C8(void* self) {
    if (F(s8, 0x45) == 2) {
        ((void (*)(void*))move_object)(self);
        if (F(u8, 0x70) & 8) {
            play_sound(2, 0x52, self);
            ((void (*)(s32))func_80012D9C)(5);
            F(s16, 0x7C) = 0xB4;
            F(s8, 5)++;
            if (F(s8, 3) != 0) {
                func_8002943C(0x5A, 2, 2);
            }
        }
    }
}

#undef F
#undef func_800EAA18

#define func_800EAAA4 func_800ED854
#include "../shared/rock_05/func_800EAAA4.c"
#undef func_800EAAA4

#define func_800EAADC func_800ED88C
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ED88C(void* self) {
    ((void (*)(void*))move_object)(self);
    if (F(s16, 0xE) <= F(s16, 0x7E)) {
        F(s32, 0x24) = 0xFFFC0000;
        F(s16, 0xE) = F(s16, 0x7E);
        F(s8, 5) = 0;
    }
}

#undef F
#undef func_800EAADC

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800ED8D8);
// clang-format on

#define func_800EE150 func_800ED9EC
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
struct X4_VisualObj* func_8002C398(void);
M2C_UNK func_8004E78C(M2C_UNK);
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;

void func_800ED9EC(void* self) {
    struct X4_VisualObj* obj;

    if (g_Player.unk5 == 0x14) {
        ((void (*)(s32))func_8004E78C)(1);
        M2C_FIELD(self, s8*, 0) |= 8;
        if ((g_Player.hp & 0x7F) >=
            ((struct X4_EngineObj*)((s8*)&g_playthrough_state - -g_Player.unk2))
                ->sub_tanks[-1]) {
            ((void (*)(void*, s32))set_animation)(self, 2);
            M2C_FIELD(self, s8*, 6) += 1;
            return;
        }
        ((void (*)(s32, s32, void*))play_sound)(2, 0x55, self);
        ((void (*)(void*, s32))set_animation)(self, 1);
        M2C_FIELD(self, s16*, 0x7C) = 0x1F;
        M2C_FIELD(self, s8*, 6) += 2;
        obj = func_8002C398();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0xE;
            obj->unk2 = 0;
            obj->unk16 = 1;
            obj->unk15 = 0;
            obj->unk50 = self;
        }
        obj = func_8002C398();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0xE;
            obj->unk2 = 1;
            obj->unk16 = 6;
            obj->unk15 = 0;
            obj->unk50 = self;
        }
    }
}
#undef g_Player
#undef func_800EE150
#undef g_Player

#define func_800EE27C func_800EDB18
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;

void func_800EDB18(void* self) {
    s8 hi;
    struct X4_EngineObj* e;

    if (--M2C_FIELD(self, s16*, 0x7C) == 0) {
        M2C_FIELD(self, s16*, 0x7C) = 2;
        hi = g_Player.hp & 0x80;
        e = (struct X4_EngineObj*)((s8*)&g_playthrough_state - -g_Player.unk2);
        if ((g_Player.hp & 0x7F) >= e->sub_tanks[-1]) {
            g_Player.hp = hi | e->sub_tanks[-1];
            M2C_FIELD(self, s16*, 0x7C) = 0x1B;
            M2C_FIELD(self, s8*, 6) += 1;
        } else {
            g_Player.hp = hi | (g_Player.hp + 1);
        }
        ((void (*)(s32, s32, s32, void*))play_sound)(0, 0xD, 0, self);
    }
}
#undef g_Player
#undef func_800EE27C
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EDBCC);
// clang-format on

#define func_80048DC8 func_800EDCD8
#define D_80077BC0 D_800EFFE4
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_80041AB8 func_800EDD24
#define D_80075FD8 D_800F001C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EE4C4 func_800EDD60
#define D_800F62F0 D_800EFFF0
#include "../shared/rock_09/func_800EE4C4.c"
#undef func_800EE4C4
#undef D_800F62F0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EDDD0(void) {
    clear_object_slot();
}

#define func_800EE554 func_800EDDF0
#define D_800F62F8 D_800EFFF8
#include "../shared/rock_09/func_800EE554.c"
#undef func_800EE554
#undef D_800F62F8

// clang-format off
INCLUDE_ASM("asm/rock_30/nonmatchings/E9860", func_800EDE44);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_8003D330();               /* extern */
M2C_UNK func_8004E78C(M2C_UNK);        /* extern */
extern s8 D_800CCEF7;

void func_800EDEC4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        func_8003D330();
        D_800CCEF7 = 0;
        set_animation(arg0, 0);
        func_8004E78C(0);
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 0) = (u8)(M2C_FIELD(arg0, u8*, 0) & 0xF7);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#define func_800EE698 func_800EDF34
#include "../shared/rock_09/func_800EE698.c"
#undef func_800EE698

#define func_800EE6CC func_800EDF68
#include "../shared/rock_09/func_800EE6CC.c"
#undef func_800EE6CC

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50();                         /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*); /* extern */
s32 func_800EDBCC(void*, M2C_UNK*);              /* extern */
extern M2C_UNK g_Player;
extern M2C_UNK D_800EFFE0;

void func_800EDFE4(void* arg0) {
    func_8002CB50();
    if (M2C_FIELD(arg0, s8*, 2) == 1) {
        func_800477E4(3, &D_800EFFE0, arg0);
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    if (func_800EDBCC(arg0, &g_Player) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) - 1);
    }
}

#define func_800EE7C8 func_800EE064
#include "../shared/rock_09/func_800EE7C8.c"
#undef func_800EE7C8

#define func_800EE880 func_800EE11C
#include "../shared/rock_09/func_800EE880.c"
#undef func_800EE880

#define func_800EE8D4 func_800EE170
#include "../shared/rock_09/func_800EE8D4.c"
#undef func_800EE8D4
