// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800E99B8);
// clang-format on

#define func_80048DC8 func_800E9B8C
#define D_80077BC0 D_800F8AB4
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

// clang-format off
#define func_800ECF40 func_800E9BD8
#define D_800F4BF0 D_800F7610
#include "../shared/rock_09/func_800ECF40.c"
#undef func_800ECF40
#undef D_800F4BF0
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */

void func_800E9C84(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    func_8002CA14();
}

#include "common.h"

void func_800E9CA4(void) {
}

#define func_800ED014 func_800E9CAC
#include "common.h"
#define M2C_UNK s32

void move_object();

#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800E9CAC(void* arg0) {
    s32 v;

    v = F32(arg0, 0x20);
    F32(arg0, 0x80) = v;
    if (v > 0) {
        if (F16(arg0, 0xA) >= F16(arg0, 0x7C) + 0x60) {
            F32(arg0, 0x20) = -v;
        }
    } else if (F16(arg0, 0x7C) - 0x60 >= F16(arg0, 0xA)) {
        F32(arg0, 0x20) = -v;
    }
    if (F32(arg0, 0x20) != F32(arg0, 0x80)) {
        F8(arg0, 0x84) = 0x28;
    }
    if (F8(arg0, 0x84) == 0) {
        move_object((s32)arg0);
        return;
    }
    F8(arg0, 0x84)--;
}
#undef func_800ED014

#define func_800ED0B4 func_800E9D4C
#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void move_object();

#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800E9D4C(void* arg0) {
    s32 v;

    v = F32(arg0, 0x24);
    F32(arg0, 0x20) = 0;
    F32(arg0, 0x28) = 0;
    F32(arg0, 0x80) = v;
    if (v > 0) {
        if (F16(arg0, 0x7E) - 0x50 >= F16(arg0, 0xE)) {
            F32(arg0, 0x24) = -v;
        }
    } else if (F16(arg0, 0xE) >= F16(arg0, 0x7E) + 0x50) {
        F32(arg0, 0x24) = -v;
    }
    if (F32(arg0, 0x24) != F32(arg0, 0x80)) {
        F8(arg0, 0x84) = 0x28;
    }
    if (F8(arg0, 0x84) == 0) {
        move_object((s32)arg0);
        return;
    }
    if (--F8(arg0, 0x84) == 0) {
        if (F32(arg0, 0x24) > 0) {
            set_animation(arg0, 0);
            return;
        }
        set_animation(arg0, 1);
    }
}

#undef F32
#undef F16
#undef F8
#undef func_800ED0B4

// clang-format off
#define func_800EF13C func_800E9E24
#define D_800F5CBC D_800F8B34
#define D_800F5D28 D_800F8BA0
#include "../shared/rock_08/func_800EF13C.c"
#undef func_800EF13C
#undef D_800F5CBC
#undef D_800F5D28

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EA028);

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EA21C);
// clang-format on

#define func_80048DC8 func_800EA3A0
#define D_80077BC0 D_800F8BC0
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002CA14(void*);                /* extern */

void func_800EA3EC(struct ObjectHeader* arg0) {
    play_sound(2, 0x54, arg0);
    arg0->on_screen = 0;
    func_8002CA14(arg0);
}

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EA428);

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EA49C);

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EA544);
// clang-format on

#define func_800EF960 func_800EA648
#define g_Player g_Player
#include "../shared/rock_08/func_800EF960.c"
#undef func_800EF960
#undef g_Player

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EA6F8);

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EA778);

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EA8EC);

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EA9F4);
// clang-format on

#define func_800EB950 func_800EAB5C
#define D_800F61F8 D_800F8D7C
#include "../shared/rock_15/func_800EB950.c"
#undef func_800EB950
#undef D_800F61F8

// clang-format off
#define func_800EBAAC func_800EACB8
#define D_800F6224 D_800F8DA8
#define D_800F6228 D_800F8DAC
#include "../shared/rock_15/func_800EBAAC.c"
#undef func_800EBAAC
#undef D_800F6224
#undef D_800F6228
// clang-format on

#define func_800EBC08 func_800EAE14
#include "../shared/rock_15/func_800EBC08.c"
#undef func_800EBC08

#define func_800EA1D8 func_800EAF7C
#define D_800FAA64 D_800F8D18
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#define func_800EBDBC func_800EAFC8
#include "../shared/rock_15/func_800EBDBC.c"
#undef func_800EBDBC

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EB054(struct ObjectHeader* arg0) {
    if (arg0->state == 3) {
        ((M2C_UNK(*)())func_8002CA14)();
        return;
    }
    func_8002CA54();
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EB094(void* arg0) {
    M2C_FIELD(arg0, u8*, 5) = (u8)M2C_FIELD(arg0, u8*, 0x94);
}

#define func_8003744C func_800EB0A0
#define D_80073C1C D_800F8D48
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EBED0 func_800EB0DC
#include "../shared/rock_15/func_800EBED0.c"
#undef func_800EBED0

#define func_800EBF3C func_800EB148
#include "../shared/rock_15/func_800EBF3C.c"
#undef func_800EBF3C

#define func_8003744C func_800EB1B0
#define D_80073C1C D_800F8D50
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
#define func_800EBFE0 func_800EB1EC
#define func_800EC478 func_800EB684
#define func_800EC648 func_800EB854
#include "../shared/rock_15/func_800EBFE0.c"
#undef func_800EBFE0
#undef func_800EC478
#undef func_800EC648
// clang-format on

#define func_800EC0E8 func_800EB2F4
#include "../shared/rock_15/func_800EC0E8.c"
#undef func_800EC0E8

#define func_8003744C func_800EB3C8
#define D_80073C1C D_800F8D58
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EC1F8 func_800EB404
#include "../shared/rock_15/func_800EC1F8.c"
#undef func_800EC1F8

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EB460);
// clang-format on

#define func_800EC2B0 func_800EB4BC
#include "../shared/rock_15/func_800EC2B0.c"
#undef func_800EC2B0

#define func_8003744C func_800EB504
#define D_80073C1C D_800F8D64
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EC334 func_800EB540
#include "../shared/rock_15/func_800EC334.c"
#undef func_800EC334

#define func_800EC378 func_800EB584
#include "../shared/rock_15/func_800EC378.c"
#undef func_800EC378

#define func_800EC3C8 func_800EB5D4
#include "../shared/rock_15/func_800EC3C8.c"
#undef func_800EC3C8

#define func_800EC428 func_800EB634
#include "../shared/rock_15/func_800EC428.c"
#undef func_800EC428

// clang-format off
#define func_800EC478 func_800EB684
#define D_800F606C D_800F8BF0
#define D_800F6154 D_800F8CD8
#include "../shared/rock_15/func_800EC478.c"
#undef func_800EC478
#undef D_800F606C
#undef D_800F6154
// clang-format on

#define func_800EC574 func_800EB780
#define D_800F6154 D_800F8CD8
#include "../shared/rock_15/func_800EC574.c"
#undef func_800EC574
#undef D_800F6154

#define func_800EC648 func_800EB854
#define D_800F6154 D_800F8CD8
#include "../shared/rock_15/func_800EC648.c"
#undef func_800EC648
#undef D_800F6154

#define func_80041AB8 func_800EB91C
#define D_80075FD8 D_800F8D8C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB958(void) {
    clear_object_slot();
}

#include "common.h"

void func_800EB978(void) {
}

#define func_800EC774 func_800EB980
#include "../shared/rock_15/func_800EC774.c"
#undef func_800EC774

#define func_80041AB8 func_800EBA28
#define D_80075FD8 D_800F8D9C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EC858 func_800EBA64
#include "../shared/rock_15/func_800EC858.c"
#undef func_800EC858

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                       /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800EBAB4(void* arg0) {
    void* temp_v1;

    animate_object();
    temp_v1 = M2C_FIELD(arg0, void**, 0x50);
    if ((M2C_FIELD(temp_v1, s8*, 0) == 0) ||
        (M2C_FIELD(temp_v1, s32*, 0x8C) != 0)) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_v1, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_v1, u16*, 0xE);
    func_8002CCB0(arg0, 0x30, 0x30);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EBB24(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800EBB44
#define D_80075FD8 D_800F8DC8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EC974 func_800EBB80
#define D_800F6254 D_800F8DD8
#include "../shared/rock_15/func_800EC974.c"
#undef func_800EC974
#undef D_800F6254

// clang-format off
#define func_800ECA98 func_800EBCA4
#define D_800F622C D_800F8DB0
#define D_800F6234 D_800F8DB8
#include "../shared/rock_15/func_800ECA98.c"
#undef func_800ECA98
#undef D_800F622C
#undef D_800F6234
// clang-format on

#define func_800ECB50 func_800EBD5C
#include "../shared/rock_15/func_800ECB50.c"
#undef func_800ECB50

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EBE1C(void) {
    clear_object_slot();
}

#include "common.h"

void func_800EBE3C(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EBE84(void*); /* extern */
M2C_UNK func_800EBF34();   /* extern */

void func_800EBE44(struct ObjectHeader* arg0) {
    if (arg0->state == 0) {
        func_800EBE84(arg0);
        return;
    }
    func_800EBF34();
}

#define func_800ECC78 func_800EBE84
#include "../shared/rock_15/func_800ECC78.c"
#undef func_800ECC78

#define func_800ECD28 func_800EBF34
#define D_80097420 D_80097420
#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK clear_object_slot();
s32 func_8002CB50();
void move_object();
#include "mmx6/state.h"

M2C_UNK func_800EBF34(u8* arg0) {
    u8 temp_v1;

    move_object(arg0);
    ((void (*)())animate_object)(arg0);
    if (*(s8*)(arg0 + 0x46) == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        arg0[0x54] = 0;
        clear_object_slot(arg0);
        return;
    }
    temp_v1 = arg0[0x54];
    arg0[3] = 0;
    if (!(temp_v1 & 3) || (temp_v1 & 1)) {
        if ((D_80097420.frame_counter & 1) == *(s8*)(arg0 + 7)) {
            func_8002CB50(arg0);
        }
    } else {
        func_8002CB50(arg0);
    }
}
#undef func_800ECD28
#undef D_80097420

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EBFD8);

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EC118);

#define func_800EAF90 func_800EC2C8
#define D_800FB26C D_800F8230
#define func_800EC7A0 func_800EDAD8
#include "../shared/rock_11/func_800EAF90.c"
#undef func_800EAF90
#undef D_800FB26C
#undef func_800EC7A0

#define func_800EB1B8 func_800EC4F0
#define D_800FB26C D_800F8230
#define func_800EC7A0 func_800EDAD8
#include "../shared/rock_11/func_800EB1B8.c"
#undef func_800EB1B8
#undef D_800FB26C
#undef func_800EC7A0

#define func_800EB3D4 func_800EC70C
#define D_800FB26C D_800F8230
#define func_800EC7A0 func_800EDAD8
#include "../shared/rock_11/func_800EB3D4.c"
#undef func_800EB3D4
#undef D_800FB26C
#undef func_800EC7A0

#define func_800EB5E8 func_800EC920
#define D_800FB26C D_800F8230
#define func_800EC7A0 func_800EDAD8
#include "../shared/rock_11/func_800EB5E8.c"
#undef func_800EB5E8
#undef D_800FB26C
#undef func_800EC7A0

#define func_800EB7FC func_800ECB34
#define D_800FB26C D_800F8230
#define func_800EC7A0 func_800EDAD8
#include "../shared/rock_11/func_800EB7FC.c"
#undef func_800EB7FC
#undef D_800FB26C
#undef func_800EC7A0

#define func_800EBA10 func_800ECD48
#define D_800FB26C D_800F8230
#define func_800EC7A0 func_800EDAD8
#include "../shared/rock_11/func_800EBA10.c"
#undef func_800EBA10
#undef D_800FB26C
#undef func_800EC7A0

#define func_800EBC28 func_800ECF60
#define D_800FB26C D_800F8230
#define func_800EC7A0 func_800EDAD8
#include "../shared/rock_11/func_800EBC28.c"
#undef func_800EBC28
#undef D_800FB26C
#undef func_800EC7A0

#define func_800EBE50 func_800ED188
#define D_800FB26C D_800F8230
#define func_800EC7A0 func_800EDAD8
#include "../shared/rock_11/func_800EBE50.c"
#undef func_800EBE50
#undef D_800FB26C
#undef func_800EC7A0

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800ED3A0);

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800ED4B8);
// clang-format on

#define func_80041AB8 func_800ED734
#define D_80075FD8 D_800F8EFC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800ED770
#define D_80075FD8 D_800F8F6C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800ED7AC(void) {
    ((M2C_UNK(*)())func_8002CA14)();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800ED7CC(void) {
    func_8002CA54();
}

#define func_800EC4B4 func_800ED7EC
#include "../shared/rock_11/func_800EC4B4.c"
#undef func_800EC4B4

#define func_8003744C func_800ED874
#define D_80073C1C D_800F8F50
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
#define func_800EC578 func_800ED8B0
#define func_800EC800 func_800EDB38
#include "../shared/rock_11/func_800EC578.c"
#undef func_800EC578
#undef func_800EC800

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800ED8F0);
// clang-format on

#define func_800EC6AC func_800ED9E4
#include "../shared/rock_11/func_800EC6AC.c"
#undef func_800EC6AC

#include "common.h"

void func_800EDA58(void) {
}

#define func_800EC728 func_800EDA60
#define g_enemies g_enemies
#include "../shared/rock_11/func_800EC728.c"
#undef func_800EC728
#undef g_enemies

#define func_800EC7A0 func_800EDAD8
#include "../shared/rock_11/func_800EC7A0.c"
#undef func_800EC7A0

#define func_80042C18 func_800EDB38
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#define func_800EC514 func_800EDB68
#include "../shared/rock_32/func_800EC514.c"
#undef func_800EC514

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                       /* extern */
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
void move_object();                             /* extern */
M2C_UNK func_8002EE10(void*);                   /* extern */
s32 func_80030ECC();                            /* extern */
M2C_UNK func_80049D90(void*);                   /* extern */

void func_800EDC38(void* arg0) {
    animate_object();
    move_object(arg0);
    func_80030ECC(arg0);
    if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
        (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
        func_80049D90(arg0);
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    if (is_off_screen(arg0, 0x18, 0x18) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EDCE8(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EDD08);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 set_animation(void*, s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK collide_solid_object();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK D_8007433C;
extern s32 D_800970A8;
extern s16 D_800970AA;
extern M2C_UNK D_800F914C;
extern M2C_UNK D_800F916C;
extern void (*D_800F9180[])(void*);

void func_800EE178(void* arg0) {
    void* parent;
    s8 saved;
    s32 d;

    parent = FX(arg0, void*, 0x7C);
    saved = FX(arg0, s8, 0x5C);
    FX(arg0, u16, 0x42) &= 0x7FFF;
    if (FX(arg0, s8, 0x2) >= 10) {
        FX(arg0, u8, 0x15) = (FX(arg0, s32, 0x8) <= D_800970A8) << 6;
    }
    if (FX(arg0, s8, 0x45) & 0xF0) {
        FX(arg0, void*, 0x58) = &D_8007433C;
    } else {
        FX(arg0, void*, 0x58) = &D_800743DC;
    }
    if (check_enemy_hits(arg0) < 0 && FX(arg0, s8, 0x2) != 0) {
        FX(parent, u8, 0x5C)--;
        func_80049E50(arg0);
        func_800477E4(3, &D_800F914C, arg0);
        FX(arg0, void*, 0x54) = &D_800F916C;
        FX(arg0, s32, 0x50) = 0;
        FX(arg0, void*, 0x58) = &D_8007433C;
        FX(arg0, s8, 0x4) = 2;
        switch (FX(arg0, s8, 0x2)) {
        case 10:
            set_animation(arg0, 0x14);
            func_800477E4(3, &D_800F914C, arg0);
            break;
        case 11:
            set_animation(arg0, 0x14);
            func_800477E4(3, &D_800F914C, arg0);
            break;
        case 12:
            FX(arg0, s8, 0x3) = 0;
            FX(arg0, s8, 0x4) = 3;
            func_800477E4(5, &D_800F914C, arg0);
            play_sound(2, 0x14, arg0);
            break;
        case 13:
            set_animation(arg0, 0x14);
            func_800477E4(3, &D_800F914C, arg0);
            break;
        case 14:
            set_animation(arg0, 0x15);
            func_800477E4(3, &D_800F914C, arg0);
            break;
        }
        return;
    }
    if (FX(arg0, s8, 0x5C) != saved) {
        FX(arg0, u16, 0x42) |= 0x8000;
    }
    D_800F9180[FX(arg0, s8, 0x6)](arg0);
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x60, 0x80);
    d = D_800970AA - FX(arg0, s16, 0xA);
    if (d >= 0) {
        if (d < 0x30) {
            // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
            goto near;
        }
    } else if (FX(arg0, s16, 0xA) - D_800970AA < 0x30) {
    near:
        collide_solid_object(arg0);
    }
    if (FX(arg0, s8, 0x6) != 2) {
        func_80030ECC(arg0);
    }
}
#undef FX

#define func_800EAEF8 func_800EE3E0
#define D_800F55DC D_800F914C
#include "../shared/rock_08/func_800EAEF8.c"
#undef func_800EAEF8
#undef D_800F55DC

#define func_800EB098 func_800EE580
#define D_80097420 D_80097420
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK apply_object_motion();

void func_800EE580(struct X4_MainObj* self) {
    s32 v;
    s32 q;

    animate_object();
    apply_object_motion(self);
    if (*(s16*)((u8*)self + 0x82) < self->x_pos.i.hi + 8 &&
        self->x_pos.i.hi - 8 < *(s16*)((u8*)self + 0x82)) {
        if (*(s16*)((u8*)self + 0x84) < self->y_pos.i.hi + 8 &&
            self->y_pos.i.hi - 8 < *(s16*)((u8*)self + 0x84)) {
            if (self->unk15 != 0) {
                v = -self->x_speed;
            } else {
                v = self->x_speed;
            }
            q = v >> 4;
            if (v < 0) {
                q = (v + 0xF) >> 4;
            }
            self->x_accel = q;
            self->gravity = self->y_speed / 16;
            *(s16*)((u8*)self + 0x80) = 0x10;
            self->unk7++;
        }
    }
    if (self->on_screen != 0 && !(D_80097420.frame_counter & 0x1F)) {
        play_sound(2, 0xD, self);
    }
}
#undef func_800EB098
#undef D_80097420

#define func_800EB1A0 func_800EE688
#define g_Player g_Player
#include "../shared/rock_08/func_800EB1A0.c"
#undef func_800EB1A0
#undef g_Player

#define func_800EB298 func_800EE780
#define g_Player g_Player
#include "../shared/rock_08/func_800EB298.c"
#undef func_800EB298
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_800139F4(M2C_UNK);
s32 random_byte();
M2C_UNK func_80027BA0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK*);

extern s16 D_800970AA;
extern s8 D_80097244;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F91B4[][4];
extern M2C_UNK D_800F9214;
extern M2C_UNK D_800F921C;
extern M2C_UNK D_800F9224;
extern M2C_UNK D_800F922C;
extern M2C_UNK D_800F9234;
extern M2C_UNK D_800F923C;
extern M2C_UNK D_800F9244;
extern M2C_UNK D_800F924C;
extern M2C_UNK D_800F9254;
extern M2C_UNK D_800F925C;
extern M2C_UNK D_800F9264;
extern M2C_UNK D_800F926C;
extern M2C_UNK D_800F9274;
extern M2C_UNK D_800F927C;
extern M2C_UNK D_800F9284;
extern M2C_UNK D_800F928C;
extern M2C_UNK D_800F9294;
extern M2C_UNK D_800F929C;
extern M2C_UNK D_800F92A4;
extern M2C_UNK D_800F92AC;
extern M2C_UNK D_800F92B4;
extern M2C_UNK D_800F92BC;

#define SPAWN(x, y, p)                                                         \
    if (!(random_byte() & 1)) {                                                \
        func_80027BA0(0, (x), (y), &(p));                                      \
    }

void func_800EE880(void* arg0) {
    M2C_FIELD(arg0, u16*, 0x80) += 1;
    M2C_FIELD(arg0, u16*, 0x82) += 1;
    M2C_FIELD(arg0, u16*, 0x84) -= 1;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = M2C_FIELD(arg0, u16*, 0x82);
    } else {
        D_800970AA = M2C_FIELD(arg0, u16*, 0x84);
    }
    if (M2C_FIELD(arg0, s16*, 0x80) >= 0x1D) {
        if (M2C_FIELD(arg0, s8*, 2) == 1) {
            if (g_playthrough_state.character_state.bytes[0xB] == 0) {
                g_playthrough_state.character_state.bytes[0xA] =
                    (u32)random_byte() % 12;
                g_playthrough_state.character_state.bytes[0xB] = 1;
            }
        } else if (M2C_FIELD(arg0, s8*, 2) == 3) {
            if (g_playthrough_state.character_state.bytes[0xB] == 1) {
                g_playthrough_state.character_state.bytes[0xA] =
                    (u32)random_byte() % 12;
                g_playthrough_state.character_state.bytes[0xB] = 2;
            }
        }
        func_800139F4(8);
        M2C_FIELD(arg0, u8*, 7) += 1;
        switch (D_800F91B4[g_playthrough_state.character_state.bytes[0xA]]
                          [M2C_FIELD(arg0, s8*, 2) - 1]) {
        case 0:
            SPAWN(0x200, 0x6B0, D_800F925C);
            SPAWN(0x280, 0x670, D_800F925C);
            SPAWN(0x440, 0x6B0, D_800F925C);
            SPAWN(0x480, 0x690, D_800F925C);
            SPAWN(0x360, 0x600, D_800F9264);
            SPAWN(0x400, 0x630, D_800F926C);
            SPAWN(0x540, 0x640, D_800F9274);
            break;
        case 1:
            SPAWN(0x140, 0x9E0, D_800F925C);
            SPAWN(0x260, 0x9E0, D_800F925C);
            SPAWN(0xC0, 0x9A0, D_800F926C);
            SPAWN(0x300, 0x9A0, D_800F926C);
            SPAWN(0x520, 0x9E0, D_800F926C);
            SPAWN(0x380, 0x970, D_800F9274);
            SPAWN(0x220, 0x9B0, D_800F927C);
            SPAWN(0x520, 0x950, D_800F927C);
            SPAWN(0x5C0, 0x9B0, D_800F927C);
            SPAWN(0x660, 0x950, D_800F927C);
            break;
        case 2:
            SPAWN(0x6E0, 0x30, D_800F9214);
            SPAWN(0x760, 0xF0, D_800F9214);
            SPAWN(0x680, 0x110, D_800F9214);
            SPAWN(0x6A0, 0x1D0, D_800F9214);
            SPAWN(0x760, 0x1F0, D_800F9214);
            SPAWN(0x680, 0x250, D_800F9214);
            break;
        case 3:
            SPAWN(0x9C0, 0x1D0, D_800F9214);
            SPAWN(0x8E0, 0x250, D_800F9214);
            SPAWN(0x920, 0x140, D_800F921C);
            break;
        case 4:
            SPAWN(0x200, 0xB80, D_800F9284);
            SPAWN(0x2C0, 0xBB0, D_800F928C);
            SPAWN(0x420, 0xC60, D_800F928C);
            SPAWN(0x380, 0xC10, D_800F9294);
            SPAWN(0x290, 0xC20, D_800F929C);
            SPAWN(0x410, 0xCD0, D_800F92A4);
            break;
        case 5:
            SPAWN(0xB60, 0xB80, D_800F9284);
            SPAWN(0xD10, 0xAD0, D_800F9284);
            SPAWN(0x8C0, 0xCB0, D_800F92AC);
            SPAWN(0x960, 0xC50, D_800F92B4);
            SPAWN(0x9C0, 0xC20, D_800F92B4);
            SPAWN(0xA60, 0xBD0, D_800F92B4);
            SPAWN(0xC00, 0xB00, D_800F92B4);
            SPAWN(0xDC0, 0xA40, D_800F92BC);
            break;
        case 6:
            SPAWN(0xBE0, 0x90, D_800F9224);
            SPAWN(0xD00, 0x90, D_800F9224);
            SPAWN(0xBE0, 0x1B0, D_800F9224);
            SPAWN(0xD00, 0x1B0, D_800F9224);
            SPAWN(0xB60, 0xC0, D_800F922C);
            SPAWN(0xD60, 0xC0, D_800F922C);
            SPAWN(0xC00, 0x140, D_800F922C);
            SPAWN(0xD60, 0x140, D_800F922C);
            SPAWN(0xC20, 0x220, D_800F922C);
            SPAWN(0xCA0, 0x220, D_800F922C);
            SPAWN(0xC60, 0x110, D_800F9234);
            break;
        case 7:
            SPAWN(0xC60, 0x420, D_800F923C);
            SPAWN(0xDA0, 0x420, D_800F923C);
            SPAWN(0xCA0, 0x600, D_800F923C);
            SPAWN(0xD00, 0x460, D_800F9244);
            SPAWN(0xDE0, 0x440, D_800F9244);
            SPAWN(0xDE0, 0x5D0, D_800F924C);
            SPAWN(0xD00, 0x3D0, D_800F9254);
            break;
        }
        D_80097244 = 1;
    }
}

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EF388);

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800EF7D8);

#define func_800EC41C func_800EF904
#define D_800F586C D_800F93DC
#define D_800F5870 D_800F93E0
#define D_800F5874 D_800F93E4
#define D_800F5878 D_800F93E8
#include "../shared/rock_08/func_800EC41C.c"
#undef func_800EC41C
#undef D_800F586C
#undef D_800F5870
#undef D_800F5874
#undef D_800F5878
// clang-format on

#define D_800F5600 D_800F9170
#define func_800EC5AC func_800EFA94
#include "../shared/rock_08/func_800EC5AC.c"
#undef func_800EC5AC
#undef D_800F5600

#define func_800EC614 func_800EFAFC
#define D_800F55DC D_800F914C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_8002F288();
s32 check_enemy_hits(void*);
M2C_UNK collide_solid_object();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800F914C;

void func_800EFAFC(void* arg0) {
    void* parent;
    s32 i;

    parent = FX(arg0, void*, 0x7C);
    FX(arg0, u16, 0x42) &= 0x7FFF;
    collide_solid_object();
    check_enemy_hits(arg0);
    func_8002F288(arg0);
    func_8002CCB0(arg0, 0x40, 0x20);
    if (FX(parent, s8, 0x4) == 3) {
        for (i = 4; i >= 0; i--) {
            func_80049EBC(arg0, 1, 0x10, 0x10);
        }
        func_800477E4(4, &D_800F914C, arg0);
        FX(arg0, u8, 0x3) = 0;
        clear_object_slot(arg0);
    }
}
#undef func_800EC614
#undef D_800F55DC

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EFBA4(void) {
    clear_object_slot();
}

#define D_800F5620 D_800F9190
#define func_800EC6DC func_800EFBC4
#include "../shared/rock_08/func_800EC6DC.c"
#undef func_800EC6DC
#undef D_800F5620

#define func_800EC724 func_800EFC0C
#include "../shared/rock_08/func_800EC724.c"
#undef func_800EC724

#define func_800EC7F0 func_800EFCD8
#include "../shared/rock_08/func_800EC7F0.c"
#undef func_800EC7F0

#define func_800EC8BC func_800EFDA4
#include "../shared/rock_08/func_800EC8BC.c"
#undef func_800EC8BC

#define func_800EC9B4 func_800EFE9C
#include "../shared/rock_08/func_800EC9B4.c"
#undef func_800EC9B4

#define func_80041AB8 func_800EFF9C
#define D_80075FD8 D_800F93C4
#define FAMILY_FIELD 7
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_80041AB8 func_800EFFD8
#define D_80075FD8 D_800F91A0
#define FAMILY_FIELD 7
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800F0014(void* arg0) {
    s32 var_a0;

    var_a0 = 0xFFFE0000;
    if ((M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x5C) < 4) ||
        ((u8)D_800CCF38 >= 2U)) {
        M2C_FIELD(arg0, s16*, 0x80) = 0xA;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            var_a0 = 0x20000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = var_a0;
        if (M2C_FIELD(arg0, s8*, 3) != 0) {
            play_sound(2, 0xC, arg0);
        }
        M2C_FIELD(arg0, u8*, 7) = (u8)(M2C_FIELD(arg0, u8*, 7) + 1);
    }
}

#define func_800ECBC4 func_800F00AC
#define g_Player g_Player
#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))

s32 set_animation(void*, s32);
M2C_UNK animate_object();
M2C_UNK apply_object_motion();
extern struct X4_PlayerObj g_Player;

void func_800F00AC(struct X4_MainObj* self) {
    s32 a;

    animate_object();
    {
        // !FAKE: inherited from src/shared/rock_08/func_800ECBC4.c
        register s32 t asm("$2") = OH(self, 0x80);
        if (t == 0) {
            // !FAKE: inherited from src/shared/rock_08/func_800ECBC4.c
            goto ready;
        }
    }
    {
        OH(self, 0x80)--;
        apply_object_motion((s32)self);
        return;
    }
ready:
    OH(self, 0x82) = g_Player.x_pos.i.hi;
    OH(self, 0x84) = g_Player.y_pos.i.hi;
    set_animation(self, 0x11);
    {
        u16 x = g_Player.x_pos.i.hi;
        u16 y;
        OH(self, 0x82) = x;
        y = g_Player.y_pos.i.hi;
        OH(self, 0x84) = y;
        a = ratan2((s16)y - self->y_pos.i.hi, (s16)x - self->x_pos.i.hi);
    }
    OW(self, 0x20) = rcos(a) << 5;
    OW(self, 0x24) = -rsin(a) << 5;
    self->unk7++;
}
#undef func_800ECBC4
#undef g_Player

#define func_800ECCA0 func_800F0188
#define D_80097420 D_80097420
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK apply_object_motion();

void func_800F0188(struct X4_MainObj* arg0) {
    animate_object();
    ((void (*)(void*))apply_object_motion)(arg0);
    if (--M2C_FIELD(arg0, s16*, 0x80) == -1) {
        arg0->x_speed = 0;
        arg0->y_speed = 0;
        arg0->x_accel = 0;
        arg0->gravity = 0;
        M2C_FIELD(arg0, s16*, 0x80) = 0x28;
        arg0->unk7++;
    }
    if (arg0->on_screen != 0 && !(D_80097420.frame_counter & 0x1F)) {
        play_sound(2, 0xD, arg0);
    }
}
#undef func_800ECCA0
#undef D_80097420

#define func_800ECD3C func_800F0224
#define D_80097420 D_80097420
#include "../shared/rock_08/func_800ECD3C.c"
#undef func_800ECD3C
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F028C(void) {
    clear_object_slot();
}

#define func_800ECDC4 func_800F02AC
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void move_object();
#define move_object ((void (*)(void*))move_object)
M2C_UNK func_8002EE10(void*);
s32 func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);

void func_800F02AC(struct X4_PlayerObj* self) {
    animate_object();
    move_object(self);
    self->unk42 &= 0x7FFF;

    if (func_80030ECC(self) != 0) {
        if (self->character != 0) {
            func_80049E50(self);
        } else {
            func_80049D90(self);
        }
        self->state = 2;
        return;
    }
    if (self->character != 0 && check_enemy_hits(self) < 0) {
        func_80049E50(self);
        self->state = 2;
        return;
    }
    if (self->collision_flags != 0 ||
        (func_8002EE10(self), self->collision_flags != 0)) {
        if (self->character != 0) {
            func_80049E50(self);
        } else {
            func_80049D90(self);
        }
        self->state = 2;
        return;
    }
    if (is_off_screen(self, 0x20, 0x20) == 0) {
        func_8002CCB0((struct X4_BaseObj*)self, 0x10, 0x10);
        return;
    }
    self->state = 2;
}
#undef move_object
#undef func_800ECDC4

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800F03D0(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    clear_object_slot();
}

#define func_80041AB8 func_800F03F0
#define D_80075FD8 D_800F93EC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
#define init_high_max_intro func_800F042C
#define D_8007433C D_8007433C
#define D_800FB2F0 D_800F9400
#define D_800FB2F8 D_800F9408
#define D_800FB7B4 D_800F98C4
#include "../rock_02/high_max.c"
#undef init_high_max_intro
#undef D_8007433C
#undef D_800FB2F0
#undef D_800FB2F8
#undef D_800FB7B4

#define func_800F1980 func_800F0688
#define D_800FB850 D_800F9960
#include "../shared/rock_02/func_800F1980.c"
#undef func_800F1980
#undef D_800FB850
// clang-format on

#define func_800F1F50 func_800F0C58
#include "../shared/rock_02/func_800F1F50.c"
#undef func_800F1F50

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800F0D64);
// clang-format on

#define func_800F21B0 func_800F0EB8
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;

void func_800F0EB8(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0 &&
        ((g_Player.facing == 0 && D_8009721E + 0x48 >= g_Player.x_pos.i.hi) ||
         (g_Player.facing == 0x40 &&
          g_Player.x_pos.i.hi >= D_8009721E + 0x18))) {
        func_8003D308(0x14, 0x40);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
    if (*M2C_FIELD(SPAD4C, s8**, 0x80) == 0) {
        g_playthrough_state.enable_boss = 1;
        g_playthrough_state.unk25 = 0;
        g_playthrough_state.boss_ptr = arg0;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x20;
        } else {
            M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x30;
            if (M2C_FIELD(&g_playthrough_state, u8*, 0x8F) != 0) {
                if (M2C_FIELD(&g_playthrough_state, u8*, 0x8F) == 1) {
                    M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x34;
                } else if (M2C_FIELD(&g_playthrough_state, u8*, 0x8F) == 2) {
                    M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x38;
                } else {
                    M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x40;
                }
            }
        }
        set_boss_level();
        {
            s32 k = 0xFFFF0000;
            M2C_FIELD(arg0, s32*, 0x24) = k;
            k = 1;
            M2C_FIELD(arg0, s8*, 3) = k;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
#undef g_Player
#undef func_800F21B0
#undef g_Player

#define func_800F22E8 func_800F0FF0
#define background_objects background_objects
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK animate_object();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002C458();
void move_object();
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800F0FF0(void* arg0) {
    void* p;
    s8 k;

    move_object((s32)arg0);
    ((void (*)(void*))animate_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) > background_objects[0].unk2A + 0x60) {
        p = func_8002C458();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 0x41;
            M2C_FIELD(p, u8*, 1) = 0x15;
            M2C_FIELD(p, u8*, 2) = 3;
            M2C_FIELD(p, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(p, s16*, 0xE) = background_objects[0].unk22 + 0xC0;
            M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(p, s32*, 0x3C) =
                SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 +
                                 SPAD20 + 4);
            M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
            M2C_FIELD(p, void**, 0x7C) = arg0;
        }
        k = M2C_FIELD(arg0, s8*, 2);
        if (k == 0) {
            open_text_box(4, 0xFF, 0);
        } else {
            if (k == 1) {
                u8* e = (u8*)&g_playthrough_state;
                open_text_box(1, 0xFF, e[0x2E]);
                e[0x2E] = 1;
            } else {
                u8* e = (u8*)&g_playthrough_state;
                open_text_box(0, 0xFF, e[0x2E]);
                e[0x2E] = 1;
            }
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800F22E8
#undef background_objects

#define func_800F2438 func_800F1140
#include "../shared/rock_02/func_800F2438.c"
#undef func_800F2438

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800F128C);

// clang-format off
#define func_800F2864 func_800F156C
#define D_800FB2E8 D_800F93F8
#include "../shared/rock_02/func_800F2864.c"
#undef func_800F2864
#undef D_800FB2E8
// clang-format on

#define func_800F2984 func_800F168C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK animate_object();
void move_object();
extern struct X4_BackgroundObj background_objects[3];

void func_800F168C(void* arg0) {
    u8* sp;
    u8 t;

    sp = SPAD4C;
    t = sp[0x8B];
    if (t != 0) {
        sp[0x8B] = t - 1;
        if (!(SPAD4C[0x8B] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) | 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        }
        sp = SPAD4C;
        if (sp[0x8B] == 0) {
            sp[0x8B] = 0x78;
        }
    }
    ((void (*)(void*))animate_object)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        ((void (*)(void*))move_object)(arg0);
        if (background_objects[0].unk22 - 0x40 >= M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk22 - 0x40;
            if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s16*, 0xA) =
                    background_objects[0].unk1C + 0x100;
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            } else {
                M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk1E + 0x40;
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            SPAD4C[0x8B] = 0x78;
        }
    }
}
#undef func_800F2984

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800F17D0);
// clang-format on

#define func_800F2BE4 func_800F18EC
#define g_Player g_Player
#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];

void func_800F18EC(void* arg0) {
    s32 ang;

    g_Player.spike_immune = 1;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    if (g_Player.action == 0x14) {
        set_animation(arg0, 2);
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        if (background_objects[0].unk1E + 0x50 < g_Player.x_pos.i.hi) {
            func_8003D308(0x1D, 0);
        } else {
            func_8003D308(0x1D, 0x40);
        }
        ang = ratan2((s16)(background_objects[0].unk22 + 0x60) -
                         M2C_FIELD(arg0, s16*, 0xE),
                     (s16)(background_objects[0].unk1E + 0x100) -
                         M2C_FIELD(arg0, s16*, 0xA));
        M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) * 0x10;
        M2C_FIELD(arg0, s32*, 0x24) = -rsin(ang) * 0x10;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        SPAD4C[0x88] = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef g_Player
#undef func_800F2BE4
#undef g_Player

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800F1A10);

INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800F1BC4);
// clang-format on

#define func_800F303C func_800F1D44
#include "../shared/rock_02/func_800F303C.c"
#undef func_800F303C

#define func_800F3164 func_800F1E6C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD4C (*(s8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void move_object();
extern struct X4_BackgroundObj background_objects[3];

void func_800F1E6C(void* arg0) {
    struct X4_MainObj* self = arg0;
    s8* p = SPAD4C;

    if (p[0x89] == 0) {
        p[0x89] = 0x78;
    }
    ((void (*)(void*))move_object)(arg0);
    if (self->x_speed < 0) {
        if (background_objects[0].unk1E + 0x70 >= self->x_pos.i.hi &&
            self->unk15 == 0) {
            self->unk15 = 0x40;
        }
        if (background_objects[0].unk1E + 0x40 >= self->x_pos.i.hi) {
            self->x_pos.i.hi = background_objects[0].unk1E + 0x40;
            self->unk15 = 0x40;
            ((void (*)(s32, s32, void*))play_sound)(2, 0x23, self);
            ((void (*)(void*, s32))set_animation)(self, 0x12);
            self->action_phase++;
        }
    } else {
        if (self->x_pos.i.hi >= background_objects[0].unk1C + 0xD0 &&
            self->unk15 != 0) {
            self->unk15 = 0;
        }
        if (self->x_pos.i.hi >= background_objects[0].unk1C + 0x100) {
            self->x_pos.i.hi = background_objects[0].unk1C + 0x100;
            self->unk15 = 0;
            ((void (*)(s32, s32, void*))play_sound)(2, 0x23, self);
            ((void (*)(void*, s32))set_animation)(self, 0x12);
            self->action_phase++;
        }
    }
}
#undef func_800F3164

#define func_800F32B8 func_800F1FC0
#include "../shared/rock_02/func_800F32B8.c"
#undef func_800F32B8

#define func_800F33C0 func_800F20C8
#define background_objects background_objects
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void move_object();
extern struct X4_BackgroundObj background_objects[3];

void func_800F20C8(void* arg0) {
    // !FAKE: inherited from src/shared/rock_02/func_800F33C0.c
    register s32 x asm("$5");
    // !FAKE: inherited from src/shared/rock_02/func_800F33C0.c
    register s32 l asm("$4");

    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        x = background_objects[0].unk1E;
        l = x - 0x140;
        if (M2C_FIELD(arg0, s16*, 0xA) >=
            x + (background_objects[0].unk1C - l) / 2) {
            return;
        }
    } else {
        x = background_objects[0].unk1E;
        l = x - 0x140;
        if (x + (background_objects[0].unk1C - l) / 2 >=
            M2C_FIELD(arg0, s16*, 0xA)) {
            return;
        }
    }
    play_sound(2, 0x23, arg0);
    set_animation(arg0, 7);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    {
        // !FAKE: inherited from src/shared/rock_02/func_800F33C0.c
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, u8*, 6) = t;
    }
}
#undef func_800F33C0
#undef background_objects

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800F2194);

#define func_800F3604 func_800F230C
#define D_800FB810 D_800F9920
#include "../shared/rock_02/func_800F3604.c"
#undef func_800F3604
#undef D_800FB810
// clang-format on

#define func_800F370C func_800F2414
#include "../shared/rock_02/func_800F370C.c"
#undef func_800F370C

// clang-format off
#include "../shared/rock_23/func_800F25FC.c"

#define func_800F3EE0 func_800F2BE8
#define D_800FBA40 D_800F9B50
#include "../shared/rock_02/func_800F3EE0.c"
#undef func_800F3EE0
#undef D_800FBA40
// clang-format on

#define func_800F4194 func_800F2E9C
#include "../shared/rock_02/func_800F4194.c"
#undef func_800F4194

#define func_800F4480 func_800F3188
#include "../shared/rock_02/func_800F4480.c"
#undef func_800F4480

#define func_800F4620 func_800F3328
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_8009721A;

void move_object();
void func_800F3328(void* arg0) {
    void* parent;
    u8 t;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())animate_object)();
    ((M2C_UNK(*)())move_object)(arg0);
    t = M2C_FIELD(arg0, u8*, 0x8D);
    if (t == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        if (M2C_FIELD(parent, s8*, 5) == 0xF) {
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, u8*, 0x8D) = 0x3C;
            M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x68;
            M2C_FIELD(arg0, u8*, 6) += 1;
            return;
        }
        if (M2C_FIELD(parent, s8*, 5) == 0x10) {
            if (M2C_FIELD(arg0, s8*, 2) == 9) {
                if (M2C_FIELD(parent, u8*, 0x15) != 0) {
                    {
                        s16 v = background_objects[0].unk1E - 0x16;
                        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
                        M2C_FIELD(arg0, s16*, 0xA) = v;
                    }
                } else {
                    // !FAKE: inherited from src/shared/rock_02/func_800F4620.c
                    goto right;
                }
            } else if (M2C_FIELD(parent, u8*, 0x15) == 0) {
                {
                    s16 v = background_objects[0].unk1E - 0x16;
                    M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
                    M2C_FIELD(arg0, s16*, 0xA) = v;
                }
            } else {
            right: {
                s16 v = background_objects[0].unk1C + 0x157;
                M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
                M2C_FIELD(arg0, s16*, 0xA) = v;
            }
            }
            {
                s16 e = background_objects[0].unk22 + 0x68;
                M2C_FIELD(arg0, u8*, 0x8D) = 0x3A;
                M2C_FIELD(arg0, u8*, 6) = 3;
                M2C_FIELD(arg0, s16*, 0xE) = e;
            }
            return;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        if (M2C_FIELD(parent, s8*, 6) >= 3) {
            {
                // !FAKE: inherited from src/shared/rock_02/func_800F4620.c
                register s32 vel2 asm("$2");
                // !FAKE: inherited from src/shared/rock_02/func_800F4620.c
                register s32 c asm("$2") = M2C_FIELD(parent, u8*, 0x15);
                if (c != 0) {
                    vel2 = 0x30000;
                } else {
                    vel2 = 0xFFFD0000;
                }
                M2C_FIELD(arg0, s32*, 0x20) = vel2;
            }
            M2C_FIELD(arg0, u8*, 0x8D) = 0;
            M2C_FIELD(arg0, u8*, 6) = 3;
        }
    } else {
        if (--M2C_FIELD(arg0, u8*, 0x8D) == 0 &&
            M2C_FIELD(parent, s8*, 5) == 0x11) {
            play_sound(2, 0x7F, arg0);
        }
    }
}
#undef func_800F4620

// clang-format off
INCLUDE_ASM("rock_23/nonmatchings/E9860", func_800F34D4);
// clang-format on

#define func_800F48EC func_800F35F4
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
s32 func_8002A47C(s32);
void* func_8002C458();
void move_object();

void func_800F35F4(void* arg0) {
    void* parent;
    void* p;
    s32 base;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())animate_object)();
    move_object((s32)arg0);
    if (M2C_FIELD(parent, s8*, 5) == 0x11) {
        if (M2C_FIELD(arg0, s8*, 2) == 9) {
            p = func_8002C458();
            if (p != 0 && (u8)(M2C_FIELD(arg0, u8*, 0x8D) % 20) == 0) {
                M2C_FIELD(p, s8*, 0) = 0x41;
                M2C_FIELD(p, s8*, 1) = 0x15;
                M2C_FIELD(p, s8*, 2) = 0;
                if (M2C_FIELD(parent, u8*, 0x15) == 0) {
                    M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x18;
                } else {
                    M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x18;
                }
                M2C_FIELD(p, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                base = func_8002A47C(0x37);
                M2C_FIELD(p, s32*, 0x3C) =
                    SPAD20 + *(s32*)(base * 4 + SPAD20 + 4);
                M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
                M2C_FIELD(p, void**, 0x7C) = parent;
                play_sound(2, 0x1C, parent);
            }
        }
        if ((u8)++M2C_FIELD(arg0, u8*, 0x8D) >= 0x4D) {
            M2C_FIELD(arg0, u8*, 0x8D) = 0x28;
            play_sound(2, 0x80, arg0);
            M2C_FIELD(arg0, u8*, 6) = 6;
        }
    } else {
        if ((u8)--M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            play_sound(2, 0x7F, arg0);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
            M2C_FIELD(arg0, u8*, 6)++;
        }
    }
}
#undef func_800F48EC

// clang-format off
#define func_800F4AB8 func_800F37C0
#define D_800FBA70 func_800F9B80
#include "../shared/rock_02/func_800F4AB8.c"
#undef func_800F4AB8
#undef D_800FBA70

#define func_800F4C44 func_800F394C
#define D_800FBA98 D_800F9BA8
#include "../shared/rock_02/func_800F4C44.c"
#undef func_800F4C44
#undef D_800FBA98

#define func_800F4F44 func_800F3C4C
#define D_800FBAA4 D_800F9BB4
#include "../shared/rock_02/func_800F4F44.c"
#undef func_800F4F44
#undef D_800FBAA4
// clang-format on
