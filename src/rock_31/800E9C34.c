// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800E9C34);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800E9FC8);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EA14C);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EA2C4);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EA4FC);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EA6D4);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EA8A4);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EAA24);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EABEC);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EB230);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EB7D4);
// clang-format on

#define func_80041AB8 func_800EC3F4
#define D_80075FD8 D_800F3320
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EC430
#define D_80075FD8 D_800F33A0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EC46C);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EC4B4);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EC558);
// clang-format on

#define func_800ECB00 func_800EC5FC
#include "../shared/rock_10/func_800ECB00.c"
#undef func_800ECB00

#define func_8003744C func_800EC638
#define D_80073C1C D_800F3368
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC674(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 3;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800EABD8 func_800EA6D4
#define func_800ECB90 func_800EC68C
#include "../shared/rock_10/func_800ECB90.c"
#undef func_800ECB90
#undef func_800EABD8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC6E0(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x89) == 2) {
        M2C_FIELD(arg0, u8*, 0x89) = 0U;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x78;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800ECC10 func_800EC70C
#include "../shared/rock_10/func_800ECC10.c"
#undef func_800ECC10

#define func_8003744C func_800EC734
#define D_80073C1C D_800F3378
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EC770);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EA6D4(void*, M2C_UNK); /* extern */

void func_800EC83C(void* arg0) {
    s32 temp_v1;
    u8 temp_a0;
    u8 temp_v0;

    temp_a0 = M2C_FIELD(arg0, u8*, 0x86);
    temp_v0 = M2C_FIELD(arg0, u8*, 0x88);
    temp_v1 = temp_a0 - temp_v0;
    if (temp_v1 >= 0) {
        if (temp_v1 == 4) {

        } else {
            // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
            goto block_4;
        }
    } else if (temp_a0 != (temp_v0 - 4)) {
    block_4:
        func_800EA6D4(arg0, 0);
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0x12E;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800ECDB0 func_800EC8AC
#include "../shared/rock_10/func_800ECDB0.c"
#undef func_800ECDB0

#include "common.h"

void func_800EC8E8(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EC8F0);
// clang-format on

#define func_8003744C func_800EC950
#define D_80073C1C D_800F3384
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC98C(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 4;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_8003744C func_800EC99C
#define D_80073C1C D_800F338C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

void func_800EC9D8(void) {
}

// clang-format off
#define func_800F1FD0 func_800EC9E0
#define D_800FBFD4 D_800F3090
#include "../shared/rock_22/func_800F1FD0.c"
#undef func_800F1FD0
#undef D_800FBFD4
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECACC(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x8C);
    M2C_FIELD(arg0, u8*, 0x98) = (u8)M2C_FIELD(temp_a1, u8*, 0x98);
    if ((s8)M2C_FIELD(temp_a1, u8*, 0x98) == 2) {
        M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
    }
    M2C_FIELD(temp_a1, u8*, 0x98) = 0U;
}

#define func_800ED014 func_800ECB10
#include "../shared/rock_10/func_800ED014.c"
#undef func_800ED014

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ECB68(void* arg0) {
    u8 temp_v1;
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_a0, s8*, 4) == 4) {
        return 0;
    }
    temp_v1 = M2C_FIELD(temp_a0, u8*, 0x89);
    if (temp_v1 == 1) {
        return 1;
    }
    return temp_v1 != 0;
}

#define func_800ED0AC func_800ECBA8
#define D_800E987C D_800E987C
#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D380(void*, void*);
#define M2C_UNK s32
extern M2C_UNK g_Player;
extern u8 D_800E987C[];

s32 func_800ECBA8(u8* arg0) {
    u8 tbl[33];
    u8 cur;
    u32 d;

    __builtin_memcpy(tbl, D_800E987C, 33);
    d = (u8)(tbl[func_8002D380(arg0, &g_Player)] - arg0[0x88]) & 7;
    cur = arg0[0x88];
    if (d != 0) {
        if (d < 4) {
            cur = (cur + 1) & 7;
        } else {
            cur = (cur - 1) & 7;
        }
    }
    return cur;
}
#undef func_800ED0AC
#undef D_800E987C

#define func_800F22B8 func_800ECCC8
#define g_enemies g_enemies
#include "../shared/rock_22/func_800F22B8.c"
#undef func_800F22B8
#undef g_enemies

#include "common.h"

void func_800ECD84(void) {
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECD8C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800ECDAC);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECE00(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800ECE20
#define D_80075FD8 D_800F33B8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800ED360 func_800ECE5C
#include "../shared/rock_10/func_800ED360.c"
#undef func_800ED360

#define func_800ED460 func_800ECF5C
#include "../shared/rock_10/func_800ED460.c"
#undef func_800ED460

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECFA8(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800ECFC8);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002D380(void*, void*);
extern M2C_UNK g_Player;
extern u8 D_800F3484[];

void func_800ED164(void* arg0) {
    void* g;

    if (--((s8*)SPAD4C)[0x80] != 0) {
        return;
    }
    g = &g_Player;
    if (M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA) > 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    SPAD4C[0x85] = func_8002D380(arg0, g);
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        SPAD4C[0x85] = D_800F3484[(s8)SPAD4C[0x85]];
    }
    switch ((s8)SPAD4C[0x85] & 0xFE) {
    case 2:
    case 4:
    case 6:
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    case 10:
    case 12:
    case 14:
        if ((s8)SPAD4C[0x85] >= 10) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        set_animation(arg0, 4);
        break;
    case 8:
        set_animation(arg0, 2);
        break;
    case 18:
    case 20:
    case 22:
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    case 26:
    case 28:
    case 30:
        if ((s8)SPAD4C[0x85] >= 0x1A) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
        set_animation(arg0, 5);
        break;
    case 24:
        set_animation(arg0, 3);
        break;
    case 0:
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        break;
    case 16:
        set_animation(arg0, 1);
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        break;
    }
    M2C_FIELD(arg0, u8*, 6)++;
}

#define func_800EC484 func_800ED330
#include "../shared/rock_02/func_800EC484.c"
#undef func_800EC484

#define func_800EC640 func_800ED4EC
#include "../shared/rock_02/func_800EC640.c"
#undef func_800EC640

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800ED630);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800ED6F4);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800ED874);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern s32 D_800F3530[];
extern s32 D_800F3538[];
extern s8 D_800F353C[];

void func_800ED90C(void* self) {
    void* parent;

    M2C_FIELD(self, s8*, 3) = 1;
    M2C_FIELD(self, void**, 0x68) = D_800F3538;
    M2C_FIELD(self, void**, 0x54) = D_800F3530;
    M2C_FIELD(self, void**, 0x50) = D_800F3530;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, s8*, 0x67) = 0;
    M2C_FIELD(self, s8*, 0x16) = 1;
    M2C_FIELD(self, void**, 0x58) = D_800741FC;
    M2C_FIELD(self, u8*, 4)++;
    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, u8*, 0x15) = M2C_FIELD(parent, u8*, 0x15);
    M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(parent, u8*, 0x14);
    M2C_FIELD(self, s8*, 0x60) = 3;
    M2C_FIELD(self, s8*, 0x5C) = 1;
    M2C_FIELD(self, s32*, 0x20) *= 2;
    M2C_FIELD(self, s32*, 0x24) *= 2;
    switch (M2C_FIELD(self, s8*, 2) & 0xFE) {
    case 2:
    case 4:
    case 6:
        M2C_FIELD(self, s16*, 0xA) += D_800F353C[6];
        M2C_FIELD(self, s16*, 0xE) += D_800F353C[7];
        break;
    case 10:
    case 12:
    case 14:
        M2C_FIELD(self, s16*, 0xA) += D_800F353C[4];
        M2C_FIELD(self, s16*, 0xE) += D_800F353C[5];
        break;
    case 8:
        M2C_FIELD(self, s16*, 0xA) += D_800F353C[8];
        M2C_FIELD(self, s16*, 0xE) += D_800F353C[9];
        break;
    case 18:
    case 20:
    case 22:
        M2C_FIELD(self, s16*, 0xA) += D_800F353C[12];
        M2C_FIELD(self, s16*, 0xE) += D_800F353C[13];
        break;
    case 26:
    case 28:
    case 30:
        M2C_FIELD(self, s16*, 0xA) += D_800F353C[14];
        M2C_FIELD(self, s16*, 0xE) += D_800F353C[15];
        break;
    case 24:
        M2C_FIELD(self, s16*, 0xA) += D_800F353C[10];
        M2C_FIELD(self, s16*, 0xE) += D_800F353C[11];
        break;
    default:
        if (M2C_FIELD(self, u8*, 0x15) & 0x40) {
            M2C_FIELD(self, s16*, 0xA) += D_800F353C[2];
            M2C_FIELD(self, s16*, 0xE) += D_800F353C[3];
        } else {
            M2C_FIELD(self, s16*, 0xA) += D_800F353C[0];
            M2C_FIELD(self, s16*, 0xE) += D_800F353C[1];
        }
        break;
    }
    set_animation(self, 6);
}

#include "common.h"
#include "mmx6/x4.h"

s32 set_animation(void*, s32);
extern u8 D_800F355C[];

void func_800EDB9C(struct X4_MainObj* self) {
    struct X4_MainObj* parent;

    parent = (struct X4_MainObj*)self->attack_box;
    self->on_screen = 1;
    self->x_speed = 0;
    self->x_accel = 0;
    self->y_speed = 0;
    self->gravity = 0;
    self->unk16 = 0;
    self->unk40 = parent->unk40;
    self->unk42 = parent->unk42 & 0x7FFF;
    self->animation_table = parent->animation_table;
    self->sprite_frames = parent->sprite_frames;
    self->unk15 = parent->unk15;
    self->bg_offset = parent->bg_offset;
    ((void (*)(void*, s32))set_animation)(self, 7);
    switch (self->unk2 & 0xFE) {
    case 2:
    case 4:
    case 6:
        self->x_pos.i.hi += (s8)D_800F355C[6];
        self->y_pos.i.hi += (s8)D_800F355C[7];
        break;
    case 10:
    case 12:
    case 14:
        self->x_pos.i.hi += (s8)D_800F355C[4];
        self->y_pos.i.hi += (s8)D_800F355C[5];
        break;
    case 8:
        self->x_pos.i.hi += (s8)D_800F355C[8];
        self->y_pos.i.hi += (s8)D_800F355C[9];
        break;
    case 18:
    case 20:
    case 22:
        self->x_pos.i.hi += (s8)D_800F355C[12];
        self->y_pos.i.hi += (s8)D_800F355C[13];
        break;
    case 26:
    case 28:
    case 30:
        self->x_pos.i.hi += (s8)D_800F355C[14];
        self->y_pos.i.hi += (s8)D_800F355C[15];
        break;
    case 24:
        self->x_pos.i.hi += (s8)D_800F355C[10];
        self->y_pos.i.hi += (s8)D_800F355C[11];
        break;
    default:
        if (self->unk15 & 0x40) {
            self->x_pos.i.hi += (s8)D_800F355C[2];
            self->y_pos.i.hi += (s8)D_800F355C[3];
        } else {
            self->x_pos.i.hi += (s8)D_800F355C[0];
            self->y_pos.i.hi += (s8)D_800F355C[1];
        }
        break;
    }
    self->state++;
}

#define func_80041AB8 func_800EDDE8
#define D_80075FD8 D_800F34A4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EDE24);
// clang-format on

#define func_800ED09C func_800EDF48
#include "../shared/rock_02/func_800ED09C.c"
#undef func_800ED09C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EE020(void* arg0) {
    if ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) >= 0xB0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s8*, 4) = 1;
        M2C_FIELD(arg0, s8*, 5) = 3;
    }
}

#include "common.h"

void func_800EE060(void) {
}

#define func_8003744C func_800EE068
#define D_80073C1C D_800F34D8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800ED1F8 func_800EE0A4
#include "../shared/rock_02/func_800ED1F8.c"
#undef func_800ED1F8

#define func_800ED25C func_800EE108
#include "../shared/rock_02/func_800ED25C.c"
#undef func_800ED25C

#define func_8003744C func_800EE164
#define D_80073C1C D_800F34E0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800ED2F4 func_800EE1A0
#include "../shared/rock_02/func_800ED2F4.c"
#undef func_800ED2F4

#define func_800ED370 func_800EE21C
#include "../shared/rock_02/func_800ED370.c"
#undef func_800ED370

#define func_800ED3D4 func_800EE280
#define D_800FAE78 D_800F34E8
#include "../shared/rock_02/func_800ED3D4.c"
#undef func_800ED3D4
#undef D_800FAE78

#define func_800ED420 func_800EE2CC
#include "../shared/rock_02/func_800ED420.c"
#undef func_800ED420

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EE31C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800ED498 func_800EE344
#include "../shared/rock_02/func_800ED498.c"
#undef func_800ED498

#define func_800ED520 func_800EE3CC
#include "../shared/rock_02/func_800ED520.c"
#undef func_800ED520

#define func_800ED3D4 func_800EE43C
#define D_800FAE78 D_800F3500
#include "../shared/rock_02/func_800ED3D4.c"
#undef func_800ED3D4
#undef D_800FAE78

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EE488);
// clang-format on

#define func_800ED67C func_800EE528
#include "../shared/rock_02/func_800ED67C.c"
#undef func_800ED67C

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EE664);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EE6C4(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EE6D8(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x67) = -1;
    M2C_FIELD(arg0, s8*, 5) = 6;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_8003744C func_800EE6F0
#define D_80073C1C D_800F3518
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800ED880 func_800EE72C
#include "../shared/rock_02/func_800ED880.c"
#undef func_800ED880

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800EE76C(s32 arg0) {
    animate_object();
    move_object(arg0);
}

#define func_800ED8EC func_800EE798
#define D_800FAEB0 D_800F3520
#include "../shared/rock_02/func_800ED8EC.c"
#undef func_800ED8EC
#undef D_800FAEB0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object(void*);         /* extern */
extern s16 D_800970AA;

void func_800EE82C(void* arg0) {
    if ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) > 0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    }
    set_animation(arg0, 1);
    animate_object(arg0);
    M2C_FIELD(arg0, s16*, 0x7E) = 0x20;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFE0000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800EDA04 func_800EE8B0
#include "../shared/rock_02/func_800EDA04.c"
#undef func_800EDA04

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();           /* extern */
M2C_UNK apply_object_motion(void*); /* extern */

void func_800EE928(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    apply_object_motion(arg0);
    if (M2C_FIELD(arg0, s32*, 0x24) == 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = -0x1000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800EDAD4 func_800EE980
#include "../shared/rock_02/func_800EDAD4.c"
#undef func_800EDAD4

#define func_800EDB48 func_800EE9F4
#define D_800FAEDC D_800F354C
#include "../shared/rock_02/func_800EDB48.c"
#undef func_800EDB48
#undef D_800FAEDC

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EEA60);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EEB18(void) {
    clear_object_slot();
}

#include "common.h"

void func_800EEB38(void) {
}

#define func_80048DC8 func_800EEB40
#define D_80077BC0 D_800F356C
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_800EDCE0 func_800EEB8C
#include "../shared/rock_02/func_800EDCE0.c"
#undef func_800EDCE0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EEBEC(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EEC0C);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EEE30);
// clang-format on

#define func_800F0258 func_800EF01C
#include "../shared/rock_10/func_800F0258.c"
#undef func_800F0258

#define func_80041AB8 func_800EF1BC
#define D_80075FD8 D_800F373C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800F0434 func_800EF1F8
#include "../shared/rock_10/func_800F0434.c"
#undef func_800F0434

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EF264(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x80) = 0;
    M2C_FIELD(arg0, s32*, 0x84) = 0;
    M2C_FIELD(arg0, s32*, 0x88) = 0;
    M2C_FIELD(arg0, s32*, 0x8C) = 0;
    M2C_FIELD(arg0, s32*, 0x94) = 0;
    if (M2C_FIELD(arg0, s8*, 4) == 4) {
        func_8002CA54();
        return;
    }
    func_8002CA14();
}

#include "common.h"

void func_800EF2B4(void) {
}

#define func_8003744C func_800EF2BC
#define D_80073C1C D_800F3770
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F33C4 func_800EF2F8
#include "../shared/rock_04/func_800F33C4.c"
#undef func_800F33C4

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EF334);
// clang-format on

#define func_800F09A0 func_800EF764
#define func_800F05EC func_800EF3B0
#include "../shared/rock_10/func_800F05EC.c"
#undef func_800F05EC
#undef func_800F09A0

#define func_8003744C func_800EF40C
#define D_80073C1C D_800F377C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F0684 func_800EF448
#include "../shared/rock_10/func_800F0684.c"
#undef func_800F0684

#define func_800F06B8 func_800EF47C
#include "../shared/rock_10/func_800F06B8.c"
#undef func_800F06B8

#define func_800EA6FC func_800EF4D4
#include "../shared/commander_yammark/func_800EA6FC.c"
#undef func_800EA6FC

#define func_8003744C func_800EF500
#define D_80073C1C D_800F3788
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F0778 func_800EF53C
#include "../shared/rock_10/func_800F0778.c"
#undef func_800F0778

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF570(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        M2C_FIELD(arg0, s8*, 0x8B) = 1;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 4;
        M2C_FIELD(arg0, s16*, 0x7E) = 0x1E;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F07F4 func_800EF5B8
#define g_Player g_Player
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_8002D380(void*, void*);
#define M2C_UNK s32
extern M2C_UNK g_Player;

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

void func_800EF5B8(void* arg0) {
    if (--F(s16, 0x7E) == 0) {
        if (F(u8, 0x15) == 0) {
            F(s16, 0xA) -= 6;
        } else {
            F(s16, 0xA) += 6;
        }
        F(u8, 0x81) = func_8002D380(arg0, &g_Player);
        if (F(u8, 0x15) == 0) {
            F(s16, 0xA) += 6;
        } else {
            F(s16, 0xA) -= 6;
        }
        F(u8, 0x6)++;
    }
}
#undef F
#undef func_800F07F4
#undef g_Player

#define func_800F08A8 func_800EF66C
#include "../shared/rock_10/func_800F08A8.c"
#undef func_800F08A8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF6C0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        M2C_FIELD(arg0, s8*, 0x8B) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

void func_800EF6F4(void) {
}

#define func_8003744C func_800EF6FC
#define D_80073C1C D_800F37A0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

void func_800EF738(void) {
}

#include "common.h"

void func_800EF740(void) {
}

#include "common.h"

void func_800EF748(void) {
}

#include "common.h"

void func_800EF750(void) {
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF758(void* arg0) {
    M2C_FIELD(arg0, u8*, 5) = (u8)M2C_FIELD(arg0, u8*, 0x94);
}

#include "../shared/rock_31/func_800EF764.c"

#define func_80041AB8 func_800EF788
#define D_80075FD8 D_800F37B8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EF7C4);
// clang-format on

#define func_800F0AB4 func_800EF878
#include "../shared/rock_10/func_800F0AB4.c"
#undef func_800F0AB4

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF954(void) {
    clear_object_slot();
}

#define func_800EA704 func_800EF974
#define g_Player g_Player
#include "../shared/rock_06/func_800EA704.c"
#undef func_800EA704
#undef g_Player

#define func_800EA840 func_800EFAB0
#include "../shared/rock_06/func_800EA840.c"
#undef func_800EA840

#define func_800EA9E0 func_800EFC50
#define D_800950A0 D_800950A0
#include "../shared/rock_06/func_800EA9E0.c"
#undef func_800EA9E0
#undef D_800950A0

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EFE3C);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800EFF78);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F00B8);
// clang-format on

#define func_80041AB8 func_800F0204
#define D_80075FD8 D_800F391C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F0240);
// clang-format on

#define func_800EB070 func_800F02E0
#include "../shared/rock_06/func_800EB070.c"
#undef func_800EB070

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */
M2C_UNK apply_object_motion(void*);    /* extern */

void func_800F037C(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800743DC;
        apply_object_motion(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            set_animation(arg0, 4);
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = 0;
    }
}

#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK animate_object();                    /* extern */
void* func_8002C458();                       /* extern */

void func_800F0424(void* arg0) {
    void* temp_v0;

    ((M2C_UNK(*)())animate_object)();
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        temp_v0 = func_8002C458();
        if (temp_v0 != NULL) {
            play_sound(2, 0x2E, arg0);
            M2C_FIELD(temp_v0, s8*, 0) = 0x41;
            M2C_FIELD(temp_v0, s8*, 1) = 0x20;
            M2C_FIELD(temp_v0, s32*, 8) = (s32)M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(temp_v0, s32*, 0xC) = (s32)M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(temp_v0, s32*, 0x3C) = (s32)M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(temp_v0, u16*, 0x40) = (u16)M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(temp_v0, u16*, 0x42) = (u16)M2C_FIELD(arg0, u16*, 0x42);
            M2C_FIELD(temp_v0, u8*, 0x14) = (u8)M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(temp_v0, s32*, 0x30) = (s32)M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(temp_v0, u8*, 0x15) = (u8)M2C_FIELD(arg0, u8*, 0x15);
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s8*, 0x83) = 0x78;
        M2C_FIELD(arg0, u8*, 0x80) = (u8)(M2C_FIELD(arg0, u8*, 0x80) & 0xFD);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F0528);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800F0610(struct ObjectHeader* arg0) {
    if (arg0->state == 4) {
        func_8002CA54();
        return;
    }
    func_8002CA14();
}

#define func_80041AB8 func_800F0650
#define D_80075FD8 D_800F3938
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F068C);
// clang-format on

#define func_800EB4D4 func_800F0744
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
M2C_UNK func_8002EE10(void*);
s32 func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90(void*);

void func_800F0744(void* arg0) {
    s32 st;

    ((M2C_UNK(*)())animate_object)();
    move_object(arg0);
    if (func_80030ECC(arg0) != 0) {
        st = 2;
        // !FAKE: inherited from src/shared/rock_06/func_800EB4D4.c
        goto store;
    }
    if (check_enemy_hits(arg0) < 0) {
        st = 2;
        // !FAKE: inherited from src/shared/rock_06/func_800EB4D4.c
        goto store;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) != 0 ||
        (func_8002EE10(arg0), M2C_FIELD(arg0, u8*, 0x70) != 0)) {
        func_80049D90(arg0);
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        return;
    }
    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    st = M2C_FIELD(arg0, u8*, 4) + 1;
store:
    M2C_FIELD(arg0, u8*, 4) = st;
}
#undef func_800EB4D4

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F080C(void) {
    clear_object_slot();
}

#define func_800ECAB8 func_800F082C
#define g_class4_slots g_class4_slots
#include "../shared/rock_06/func_800ECAB8.c"
#undef func_800ECAB8
#undef g_class4_slots

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F0960);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F0BE8);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F0E10);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F1824);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F1A10);

INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F1DC4);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*);                            /* extern */
M2C_UNK func_80030ECC();                                 /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);         /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_800F3978;

void func_800F1E24(void* arg0) {
    u8 temp_v0;

    M2C_FIELD(arg0, s8*, 3) = 0;
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        func_80030ECC();
        if (!(M2C_FIELD(arg0, u8*, 0x85) & 3)) {
            func_80049EBC(arg0, 1, 0x20, 0x20);
        }
        if (!(M2C_FIELD(arg0, u8*, 0x85) & 7)) {
            func_800477E4(3, &D_800F3978, arg0);
        }
        temp_v0 = M2C_FIELD(arg0, u8*, 0x85);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8*, 0x85) = (u8)(temp_v0 - 1);
            return;
        }
    }
    func_8002CA14(arg0);
}

#include "common.h"

void func_800F1EC4(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F1ECC);
// clang-format on

#define func_800EA224 func_800F2074
#define g_Player g_Player
#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK move_object(s32);
#define move_object ((M2C_UNK(*)(void*))move_object)
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
#include "mmx6/state.h"

#define EA_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define EA_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define EA_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F2074(void* arg0) {
    struct X4_PlayerObj* p;
    s16 y;
    s16 x;
    s32 ang;
    s32 c;
    s32 t;
    s32 v;

    if (g_Player.x_pos.i.hi > EA_S16(arg0, 0xA)) {
        EA_U8(arg0, 0x15) = 0x40;
    } else {
        EA_U8(arg0, 0x15) = 0;
    }
    p = &g_Player;
    y = p->y_pos.i.hi + EA_S16(arg0, 0x82);
    x = p->x_pos.i.hi + EA_S16(arg0, 0x80);
    ang = ratan2(y - EA_S16(arg0, 0xE), x - EA_S16(arg0, 0xA));
    c = rcos(ang);
    v = c * 16;
    EA_S32(arg0, 0x20) = c * 64 + v;
    c = -rsin(ang);
    v = c * 16;
    EA_S32(arg0, 0x24) = c * 64 + v;
    if (((EA_S16(arg0, 0xA) - x >= 0) ? (EA_S16(arg0, 0xA) - x)
                                      : (x - EA_S16(arg0, 0xA))) < 0x10 &&
        ((EA_S16(arg0, 0xE) - y >= 0) ? (EA_S16(arg0, 0xE) - y)
                                      : (y - EA_S16(arg0, 0xE))) < 0x20) {
        EA_S32(arg0, 0x20) = 0;
        EA_S32(arg0, 0x24) = 0;
        if (!(*(u8*)&D_80097420 & 1)) {
            t = (EA_U8(arg0, 0x84) + 1) & 0x3F;
            EA_U8(arg0, 0x84) = t;
            EA_S16(arg0, 0xE) += rsin(t << 7) / 2096;
        }
    }
    animate_object(arg0);
    move_object(arg0);
}
#undef g_Player
#undef move_object
#undef func_800EA224
#undef g_Player

#define func_80048DC8 func_800F2224
#define D_80077BC0 D_800F39CC
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_800EA420 func_800F2270
#define D_800F3D58 D_800F39DC
#include "../shared/rock_05/func_800EA420.c"
#undef func_800EA420
#undef D_800F3D58

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F236C(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800F238C(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

M2C_UNK move_object(s32);
void func_800F23E0(struct MainObj* arg0) {
    arg0->x_speed = 0;
    arg0->y_speed = 0x50000;
    ((M2C_UNK(*)())animate_object)();
    ((M2C_UNK(*)())move_object)(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_31/nonmatchings/E9860", func_800F2418);
// clang-format on
