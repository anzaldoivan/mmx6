#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)
#define SPAD_SLOT ((u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
void func_800EAA5C(void*, s32, void*);
void func_800EABD0(struct X4_MainObj* self);
extern s32 D_800EF330;
extern s32 D_800EF334;
extern s32 D_800EF6D8;

void func_800E98F4(struct X4_MainObj* self) {
    u8** sp = SPAD_SLOT;
    s32 seven;
    s8 kind;
    u8 b;
    s32 x;
    s32 y;
    u8* p;

    self->contact_damage = 4;
    self->hp = 0x10;
    self->invincibility_timer = 0;
    self->on_screen = 0;
    self->animation_table = (const u8* const*)&D_800EF6D8;
    M2C_FIELD(*sp, u8*, 0x87) = 0;
    self->terrain_box = 0;
    self->hurt_box = 0;
    self->attack_box = 0;
    b = D_800970B4;
    x = self->x_pos.val;
    y = self->y_pos.val;
    seven = 7;
    self->unk15 = 0;
    self->unk16 = seven;
    self->air_state = 0;
    self->collision_data = &D_800743DC;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->bg_offset = b;
    self->unk18.val = x;
    self->unk1C.val = y;
    func_800EABD0(self);
    self->state = 1;
    self->action_phase = 0;
    __builtin_memcpy(*sp + 0x80, &D_800EF334, 4);
    kind = self->unk2;
    if (kind == 0) {
        set_animation(self, 0);
        {
            s32 two = 2;
            // !FAKE: depin: dropping it breaks the match (58/107)
            register s32 h asm("$2") = self->y_pos.u.hi;
            self->action = two;
            self->y_pos.u.hi = h - 0x20;
        }
    } else if (kind == 1) {
        set_animation(self, 0xE);
        {
            s32 two = 2;
            // !FAKE: depin: dropping it breaks the match (70/107)
            register s32 h asm("$2") = self->y_pos.u.hi;
            self->action = two;
            self->y_pos.u.hi = h + 0x20;
        }
    } else if (kind == 2) {
        set_animation(self, 7);
        M2C_FIELD(SPAD, u8*, 0x86) = 3;
        p = SPAD;
        M2C_FIELD(p, u16*, 0x84) = self->y_pos.u.hi;
        func_800EAA5C(self, 0x10, p);
        self->action = seven;
        self->terrain_box = 0;
        self->attack_box = &D_800EF330;
        self->hurt_box = &D_800EF334;
        self->y_pos.u.hi += 0x1A;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800E9AA0);

INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800E9BB8);

INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800E9CEC);
// clang-format on

#define func_800E9EF4 func_800E9E14
#include "../shared/commander_yammark/func_800E9EF4.c"
#undef func_800E9EF4

#define func_800EA0B0 func_800E9FD0
#include "../shared/commander_yammark/func_800EA0B0.c"
#undef func_800EA0B0

#define func_80041AB8 func_800EA184
#define D_80075FD8 D_800EF754
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EA1C0
#define D_80075FD8 D_800EF7D4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EA1FC
#define D_80075FD8 D_800EF7E0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EA318 func_800EA238
#define D_800F70F0 D_800EF764
#include "../shared/commander_yammark/func_800EA318.c"
#undef func_800EA318
#undef D_800F70F0

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EA324(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EA344(void) {
    func_8002CA54();
}

#define func_8003744C func_800EA364
#define D_80073C1C D_800EF784
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EA480 func_800EA3A0
#include "../shared/commander_yammark/func_800EA480.c"
#undef func_800EA480

#define func_800EA4DC func_800EA3FC
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EA4DC.c"
#undef func_800EA4DC
#undef g_Player

#define func_8003744C func_800EA484
#define D_80073C1C D_800EF78C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EA5A0 func_800EA4C0
#include "../shared/commander_yammark/func_800EA5A0.c"
#undef func_800EA5A0

#define func_8003744C func_800EA4EC
#define D_80073C1C D_800EF798
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EA608 func_800EA528
#include "../shared/commander_yammark/func_800EA608.c"
#undef func_800EA608

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EA58C);
// clang-format on

#define func_800EA6FC func_800EA61C
#include "../shared/commander_yammark/func_800EA6FC.c"
#undef func_800EA6FC

#define func_8003744C func_800EA648
#define D_80073C1C D_800EF7A4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EA764 func_800EA684
#include "../shared/commander_yammark/func_800EA764.c"
#undef func_800EA764

#define func_800EA7E4 func_800EA704
#include "../shared/commander_yammark/func_800EA7E4.c"
#undef func_800EA7E4

#define func_8003744C func_800EA754
#define D_80073C1C D_800EF7AC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */

void func_800EA790(void* arg0) {
    s8 temp_v1;

    play_sound(2, 6, arg0);
    temp_v1 = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    if (temp_v1 == 0) {
        set_animation(arg0, 0x16);
    } else if (temp_v1 == 1) {
        set_animation(arg0, 0x17);
    }
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA808(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x78;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800EA910 func_800EA830
#include "../shared/commander_yammark/func_800EA910.c"
#undef func_800EA910

#define func_8003744C func_800EA85C
#define D_80073C1C D_800EF7B8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EA898);
// clang-format on

#define func_800EAA04 func_800EA924
#include "../shared/commander_yammark/func_800EAA04.c"
#undef func_800EAA04

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EA998);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK apply_object_motion(); /* extern */

void func_800EAA34(void) {
    apply_object_motion();
}

#include "common.h"

void func_800EAA54(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EAA5C);
// clang-format on

#define func_800EABF0 func_800EAB10
#include "../shared/commander_yammark/func_800EABF0.c"
#undef func_800EABF0

#define func_80042C18 func_800EABD0
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#define func_800EACE0 func_800EAC00
#include "../shared/commander_yammark/func_800EACE0.c"
#undef func_800EACE0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EACEC(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EAD0C(void) {
    clear_object_slot();
}

#define func_800EAE0C func_800EAD2C
#include "../shared/commander_yammark/func_800EAE0C.c"
#undef func_800EAE0C

#define func_800EAE94 func_800EADB4
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EAE94.c"
#undef func_800EAE94
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EAFC0);
// clang-format on

#define func_800EB170 func_800EB090
#include "../shared/commander_yammark/func_800EB170.c"
#undef func_800EB170

#define func_80041AB8 func_800EB1E8
#define D_80075FD8 D_800EF8C8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EB224
#define D_80075FD8 D_800EF974
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EB260
#define D_80075FD8 D_800EF980
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
#define func_800EB37C func_800EB29C
#define D_800F7180 D_800EF7F4
#define D_800F7184 D_800EF7F8
#define D_800F7234 D_800EF8A8
#define func_800EBABC func_800EB9DC
#include "../shared/rock_03/func_800EB37C.c"
#undef func_800EB37C
#undef D_800F7180
#undef D_800F7184
#undef D_800F7234
#undef func_800EBABC

INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EB3B0);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EB49C(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EB4BC(void) {
    func_8002CA54();
}

#define func_8003744C func_800EB4DC
#define D_80073C1C D_800EF8F0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EB5F8 func_800EB518
#include "../shared/commander_yammark/func_800EB5F8.c"
#undef func_800EB5F8

#define func_800EB644 func_800EB564
#include "../shared/commander_yammark/func_800EB644.c"
#undef func_800EB644

#define func_800EB6C4 func_800EB5E4
#include "../shared/commander_yammark/func_800EB6C4.c"
#undef func_800EB6C4

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EB628(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800EB648
#define D_80073C1C D_800EF900
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EB764 func_800EB684
#include "../shared/commander_yammark/func_800EB764.c"
#undef func_800EB764

#define func_8003744C func_800EB6C8
#define D_80073C1C D_800EF908
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EB7E4 func_800EB704
#include "../shared/commander_yammark/func_800EB7E4.c"
#undef func_800EB7E4

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EB790);
// clang-format on

#include "common.h"

void func_800EB8A4(void) {
}

#define func_8003744C func_800EB8AC
#define D_80073C1C D_800EF960
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EB8E8);
// clang-format on

#define func_800EBABC func_800EB9DC
#include "../shared/commander_yammark/func_800EBABC.c"
#undef func_800EBABC

#define func_800EBB70 func_800EBA90
#include "../shared/commander_yammark/func_800EBB70.c"
#undef func_800EBB70

#define func_80042C18 func_800EBB40
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EBB70);
// clang-format on

#define func_800EBCEC func_800EBC0C
#include "../shared/commander_yammark/func_800EBCEC.c"
#undef func_800EBCEC

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EBCA0(void) {
    clear_object_slot();
}

#define func_800EBDA0 func_800EBCC0
#include "../shared/commander_yammark/func_800EBDA0.c"
#undef func_800EBDA0

#define func_800EBE14 func_800EBD34
#include "../shared/commander_yammark/func_800EBE14.c"
#undef func_800EBE14

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EBE6C(void) {
    clear_object_slot();
}

#define func_800EBF6C func_800EBE8C
#define D_800F7414 D_800EFA88
#include "../shared/commander_yammark/func_800EBF6C.c"
#undef func_800EBF6C
#undef D_800F7414

#define func_800EC144 func_800EC064
#include "../shared/commander_yammark/func_800EC144.c"
#undef func_800EC144

#define func_800EC25C func_800EC17C
#include "../shared/commander_yammark/func_800EC25C.c"
#undef func_800EC25C

#define func_800EC300 func_800EC220
#define D_800F7404 D_800EFA78
#include "../shared/commander_yammark/func_800EC300.c"
#undef func_800EC300
#undef D_800F7404

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EC288);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EC354(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EC374(void) {
    func_8002CA14();
}

#include "../shared/commander_yammark/func_800EC394.c"

#define D_800F73F0 D_800EFA64
#define D_800F73F8 D_800EFA6C
#define D_800F7400 D_800EFA74
#define func_800EC4BC func_800EC3DC
#define D_800F73F0 D_800EFA64
#include "../shared/commander_yammark/func_800EC4BC.c"
#undef func_800EC4BC
#undef D_800F73F0
#undef D_800F73F0
#undef D_800F73F8
#undef D_800F7400

#define func_800EC520 func_800EC440
#include "../shared/commander_yammark/func_800EC520.c"
#undef func_800EC520

#define func_800EC564 func_800EC484
#include "../shared/commander_yammark/func_800EC564.c"
#undef func_800EC564

#define func_800EC5F4 func_800EC514
#include "../shared/commander_yammark/func_800EC5F4.c"
#undef func_800EC5F4

#define func_800EC66C func_800EC58C
#include "../shared/commander_yammark/func_800EC66C.c"
#undef func_800EC66C

#define func_80041AB8 func_800EC61C
#define D_80075FD8 D_800EFAA8
#define FAMILY_FIELD 7
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_800EC738 func_800EC658
#include "../shared/commander_yammark/func_800EC738.c"
#undef func_800EC738

#define func_800EC7A4 func_800EC6C4
#include "../shared/commander_yammark/func_800EC7A4.c"
#undef func_800EC7A4

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EC720);
// clang-format on

#define func_800EC8A0 func_800EC7C0
#include "../shared/commander_yammark/func_800EC8A0.c"
#undef func_800EC8A0

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EC810);
// clang-format on

#define func_800ECA2C func_800EC94C
#define g_Player g_Player
#include "../shared/commander_yammark/func_800ECA2C.c"
#undef func_800ECA2C
#undef g_Player

#define func_800ECC38 func_800ECB58
#define g_projectiles g_projectiles
#include "../shared/commander_yammark/func_800ECC38.c"
#undef func_800ECC38
#undef g_projectiles

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800ECCF4);
// clang-format on

#define func_800ED020 func_800ECF40
#define g_Player g_Player
#include "../shared/commander_yammark/func_800ED020.c"
#undef func_800ED020
#undef g_Player

#define func_800ED0F4 func_800ED014
#define g_Player g_Player
#include "../shared/commander_yammark/func_800ED0F4.c"
#undef func_800ED0F4
#undef g_Player

#define func_800ED220 func_800ED140
#define g_Player g_Player
#include "../shared/commander_yammark/func_800ED220.c"
#undef func_800ED220
#undef g_Player

#define func_800ED2F4 func_800ED214
#include "../shared/commander_yammark/func_800ED2F4.c"
#undef func_800ED2F4

#define func_800ED428 func_800ED348
#include "../shared/commander_yammark/func_800ED428.c"
#undef func_800ED428

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800ED4A4);

INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800ED624);

INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800ED680);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800ED750(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_8003744C func_800ED790
#define D_80073C1C D_800EFD34
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800ED7CC
#define D_80073C1C D_800EFD40
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800ED808
#define D_80073C1C D_800EFD50
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define D_800F7448 D_800EFABC
#define D_800F744C D_800EFAC0
#define func_800ED924 func_800ED844
#define D_800F744C D_800EFAC0
#include "../shared/commander_yammark/func_800ED924.c"
#undef func_800ED924
#undef D_800F744C
#undef D_800F7448
#undef D_800F744C

#define func_800ED984 func_800ED8A4
#include "../shared/commander_yammark/func_800ED984.c"
#undef func_800ED984

#define func_800ED9B8 func_800ED8D8
#include "../shared/commander_yammark/func_800ED9B8.c"
#undef func_800ED9B8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */

void func_800ED9A4(void* arg0) {
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        set_animation(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
    }
}

#define func_800EDACC func_800ED9EC
#include "../shared/commander_yammark/func_800EDACC.c"
#undef func_800EDACC

#define func_800EDB00 func_800EDA20
#include "../shared/commander_yammark/func_800EDB00.c"
#undef func_800EDB00

#define func_800EDBD4 func_800EDAF4
#include "../shared/commander_yammark/func_800EDBD4.c"
#undef func_800EDBD4

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */

void func_800EDB44(void* arg0) {
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        set_animation(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
    }
}

#define func_800EDC6C func_800EDB8C
#include "../shared/commander_yammark/func_800EDC6C.c"
#undef func_800EDC6C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */

void func_800EDBC4(void* arg0) {
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        set_animation(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */

void func_800EDC0C(void) {
    animate_object();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EDC2C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EDC4C);
// clang-format on

#define func_800EDD88 func_800EDCA8
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EDD88.c"
#undef func_800EDD88
#undef g_Player

#define func_800EDE78 func_800EDD98
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EDE78.c"
#undef func_800EDE78
#undef g_Player

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object();                 /* extern */
M2C_UNK clear_object_slot(s32);           /* extern */
s32 is_off_screen(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(s32);                 /* extern */

void func_800EDE50(s32 arg0) {
    animate_object();
    move_object(arg0);
    if (is_off_screen(arg0, 0x40, 0x40) == 1) {
        clear_object_slot(arg0);
    }
}

#define func_8003744C func_800EDEA0
#define D_80073C1C D_800EFD84
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EDEDC
#define D_80073C1C D_800EFD98
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EDFF8 func_800EDF18
#include "../shared/commander_yammark/func_800EDFF8.c"
#undef func_800EDFF8

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EDFA0);
// clang-format on

#define func_8003744C func_800EE038
#define D_80073C1C D_800EFDA0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EE074);

INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EE244);
// clang-format on

#define func_80048DC8 func_800EE2E8
#define D_80077BC0 D_800EFDD0
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_80041AB8 func_800EE334
#define D_80075FD8 D_800EFDDC
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE370(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EE390);
// clang-format on

#define func_800EF6D4 func_800EE444
#define background_objects background_objects
#include "../shared/commander_yammark/func_800EF6D4.c"
#undef func_800EF6D4
#undef background_objects

#define func_800EFEF8 func_800EE4DC
#include "../shared/commander_yammark/func_800EFEF8.c"
#undef func_800EFEF8

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EE580);

INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EE770);
// clang-format on

#define func_80046C64 func_800EE998
#define D_800762A0 D_800EFE94
#include "../shared/d1000/func_80046C64.c"
#undef func_80046C64
#undef D_800762A0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE9D8(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

// clang-format off
INCLUDE_ASM("asm/rock_25/nonmatchings/E9860", func_800EE9F8);
// clang-format on
