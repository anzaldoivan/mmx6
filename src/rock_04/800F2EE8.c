#define func_80041AB8 func_800F2EE8
#define D_80075FD8 D_800F7550
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "../shared/rock_04/func_800F2F24.c"

#include "../shared/rock_04/func_800F2FB0.c"

#include "../shared/rock_04/func_800F30A4.c"

#include "../shared/rock_04/func_800F311C.c"

#include "../shared/rock_04/func_800F3154.c"

#include "../shared/rock_04/func_800F31A4.c"

#include "common.h"
#include "mmx6/x4.h"

extern s32 D_800F70CC;
extern s32 D_800F70D0;
extern s32 D_800F70D4;
extern s32 D_800F70D8;

#include "../shared/rock_04/func_800F326C.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK apply_object_motion();
M2C_UNK func_80049D90(void*);
void func_800F51F0(struct X4_AnimatedObj* arg0, u8 arg1);

#include "../shared/rock_04/func_800F32F4.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F3368(void) {
    clear_object_slot();
}

#define func_8003744C func_800F3388
#define D_80073C1C D_800F755C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_04/func_800F33C4.c"

// clang-format off
#define func_80042214 func_800F3400
#define func_800429D4 func_800F25A0
#include "../shared/main/func_80042214.c"
#undef func_80042214
#undef func_800429D4
// clang-format on

#define func_8003744C func_800F343C
#define D_80073C1C D_800F7564
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5488(struct X4_MainObj* self);

#include "../shared/rock_04/func_800F3478.c"

#include "../shared/rock_04/func_800F34B4.c"

#include "../shared/rock_04/func_800F351C.c"

#include "../shared/rock_04/func_800F3600.c"

#define func_8003744C func_800F3648
#define D_80073C1C D_800F7574
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5488(struct X4_MainObj* self);

void func_800F3684(struct X4_MainObj* arg0) {
    // !FAKE: depin: dropping it breaks the match (12/17)
    register u8 v asm("$2");

    func_800F5488(arg0);
    set_animation(arg0, 4);
    v = arg0->action_phase;
    arg0->unk7C = 0x3C;
    arg0->action_phase = v + 1;
}

#include "../shared/rock_04/func_800F36C8.c"

#include "../shared/rock_04/func_800F372C.c"

#include "../shared/rock_04/func_800F378C.c"

// clang-format off
#define func_80042214 func_800F3800
#define func_800429D4 func_800F25A0
#include "../shared/main/func_80042214.c"
#undef func_80042214
#undef func_800429D4
// clang-format on

#define func_8003744C func_800F383C
#define D_80073C1C D_800F758C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_04/func_800F3878.c"

#include "../shared/rock_04/func_800F38B4.c"

#include "../shared/rock_04/func_800F39D8.c"

#include "../shared/rock_04/func_800F3A2C.c"

#include "../shared/rock_04/func_800F3B28.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3BBC(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x1770;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "../shared/rock_04/func_800F3BE0.c"

#include "../shared/rock_04/func_800F3C44.c"

// clang-format off
#define func_80042214 func_800F3C80
#define func_800429D4 func_800F25A0
#include "../shared/main/func_80042214.c"
#undef func_80042214
#undef func_800429D4
// clang-format on

#define func_8003744C func_800F3CBC
#define D_80073C1C D_800F75B4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_04/func_800F3CF8.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
void func_800F513C(struct X4_AnimatedObj* arg0, u8 arg1);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define SW(p, o) (*(s32*)((u8*)(p) + (o)))

#include "../shared/rock_04/func_800F3D44.c"

#define func_800F3600 func_800F3E2C
#include "../shared/rock_04/func_800F3600.c"
#undef func_800F3600

#define func_8003744C func_800F3E74
#define D_80073C1C D_800F75C4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5488(struct X4_MainObj* self);

#include "../shared/rock_04/func_800F3EB0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void move_object();
void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1);

#include "../shared/rock_04/func_800F3EEC.c"

#include "../shared/rock_04/func_800F3F94.c"

// clang-format off
#define func_80042214 func_800F4058
#define func_800429D4 func_800F25A0
#include "../shared/main/func_80042214.c"
#undef func_80042214
#undef func_800429D4
// clang-format on

#define func_8003744C func_800F4094
#define D_80073C1C D_800F75DC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_04/func_800F40D0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5488(struct X4_MainObj* self);

#include "../shared/rock_04/func_800F410C.c"

#include "../shared/rock_04/func_800F4150.c"

// clang-format off
#define func_80042214 func_800F4184
#define func_800429D4 func_800F25A0
#include "../shared/main/func_80042214.c"
#undef func_80042214
#undef func_800429D4
// clang-format on

#define func_8003744C func_800F41C0
#define D_80073C1C D_800F75FC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5488(struct X4_MainObj* self);

#include "../shared/rock_04/func_800F41FC.c"

#include "../shared/rock_04/func_800F4238.c"

#include "../shared/rock_04/func_800F4324.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F25A0(); /* extern */

void func_800F4394(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_800F25A0();
    }
}

#define func_8003744C func_800F43C4
#define D_80073C1C D_800F760C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_04/func_800F4400.c"

#include "../shared/rock_04/func_800F442C.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F52AC(void* arg0, u8 arg1);

#include "../shared/rock_04/func_800F447C.c"

#define func_800F4150 func_800F4548
#include "../shared/rock_04/func_800F4150.c"
#undef func_800F4150

// clang-format off
#define func_80042214 func_800F457C
#define func_800429D4 func_800F25A0
#include "../shared/main/func_80042214.c"
#undef func_80042214
#undef func_800429D4
// clang-format on

#define func_8003744C func_800F45B8
#define D_80073C1C D_800F7624
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_04/func_800F45F4.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
void func_800F513C(struct X4_AnimatedObj* arg0, u8 arg1);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define SW(p, o) (*(s32*)((u8*)(p) + (o)))

#include "../shared/rock_04/func_800F4664.c"

#define func_800F3F94 func_800F470C
#include "../shared/rock_04/func_800F3F94.c"
#undef func_800F3F94

#include "../shared/rock_04/func_800F47D0.c"

// clang-format off
#define func_80042214 func_800F4898
#define func_800429D4 func_800F25A0
#include "../shared/main/func_80042214.c"
#undef func_80042214
#undef func_800429D4
// clang-format on

#define func_8003744C func_800F48D4
#define D_80073C1C D_800F763C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F4910(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "../shared/rock_04/func_800F4948.c"

#include "../shared/rock_04/func_800F49E4.c"

#include "../shared/rock_04/func_800F4AB4.c"

#include "../shared/rock_04/func_800F4B2C.c"

#include "../shared/rock_04/func_800F4BA8.c"

#include "../shared/rock_04/func_800F4BEC.c"

#include "../shared/rock_04/func_800F4C68.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4D20(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/rock_04/func_800F4D48.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();    /* extern */
M2C_UNK func_800F25A0(s32); /* extern */

void func_800F4DCC(s32 arg0) {
    func_8003D330();
    func_800F25A0(arg0);
}

#define func_8003744C func_800F4DF8
#define D_80073C1C D_800F766C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_04/func_800F4E34.c"

#include "../shared/rock_04/func_800F4EB0.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4F0C(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

s32 random_byte();
extern u8 D_800F6FB0[];
extern u8 D_800F7030[];

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F4F24(void* arg0) {
    s8 kind;
    s8 r;
    // !FAKE: depin: dropping it breaks the match (27/43)
    register u8* tbl asm("$2");

    if (--H(arg0, 0x7C) == 0) {
        H(arg0, 0x88) = 0x28;
        UB(arg0, 6) = 0;
        r = random_byte() & 0xF;
        kind = SB(arg0, 0x8A);
        UB(arg0, 0x8B) = r;
        UB(arg0, 0x8C) = 0;
        switch (kind) {
        case -1:
        case 0:
            tbl = D_800F6FB0;
            // !FAKE: goto shares the set block holding the pinned table load; duplicating it needs a second pin
            goto set;
        case 1:
            tbl = D_800F7030;
        set: {
            // !FAKE: depin: dropping it breaks the match (41/43)
            register s32 b asm("$4") = tbl[r * 8];
            UB(arg0, 5) = b;
        } break;
        }
        UB(arg0, 0x8C)++;
    }
}

#include "common.h"

void func_800F4FD0(void) {
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/rock_04.h"

extern s32 D_800F70BC;
extern s32 D_800F70C0;
extern u8 D_800F70C4[];
extern s32 D_800F70C8;

#include "../shared/rock_04/func_800F4FD8.c"

#include "../shared/rock_04/func_800F5088.c"

#include "../shared/rock_04/func_800F513C.c"

#include "../shared/rock_04/func_800F51F0.c"

#include "../shared/rock_04/func_800F52AC.c"

#include "../shared/rock_04/func_800F5360.c"

#define func_80042C18 func_800F5488
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#include "../shared/rock_04/func_800F54B8.c"

#define func_80048DC8 func_800F54F8
#define D_80077BC0 D_800F76AC
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5544(void) {
    clear_object_slot();
}

#define func_8003744C func_800F5564
#define D_80073C1C D_800F76C4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32

M2C_UNK apply_object_motion(); /* extern */

void func_800F55A0(void) {
    apply_object_motion();
}

#define func_8003744C func_800F55C0
#define D_80073C1C D_800F76D4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK apply_object_motion();
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80049D90(void*);
void func_800F5A94(void* arg0, u8 arg1);

void func_800F55FC(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (35/37)
    register s32 v asm("$2");

    apply_object_motion(arg0);
    if ((v = arg0[0x70]) == 0) {
        func_8002EE10(arg0);
        if (arg0[0x70] == 0) {
            return;
        }
    }
    play_sound(2, 0x17, arg0);
    start_pad_vibration(8);
    func_80049D90(arg0);
    func_800F5A94(arg0, 0x10);
    func_800F5A94(arg0, 0x11);
    func_800F5A94(arg0, 0x12);
    arg0[4] = 2;
}

#define func_8003744C func_800F5690
#define D_80073C1C D_800F76CC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_04/func_800F56CC.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void move_object();
M2C_UNK func_8002EE10(void*);
void func_800F59D8(struct X4_AnimatedObj* arg0, u8 arg1);

#include "../shared/rock_04/func_800F570C.c"

#include "../shared/rock_04/func_800F5788.c"

#include "../shared/rock_04/func_800F5888.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5920(void) {
    clear_object_slot();
}

#include "../shared/rock_04/func_800F5940.c"

#define func_80041AB8 func_800F599C
#define D_80075FD8 D_800F76DC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/rock_04/func_800F59D8.c"

#include "../shared/rock_04/func_800F5A94.c"

// clang-format off
INCLUDE_ASM("rock_04/nonmatchings/E9860", func_800F5B50);

INCLUDE_ASM("rock_04/nonmatchings/E9860", func_800F60F4);

INCLUDE_ASM("rock_04/nonmatchings/E9860", func_800F6F30);

INCLUDE_ASM("rock_04/nonmatchings/E9860", func_800F6F34);

INCLUDE_ASM("rock_04/nonmatchings/E9860", func_800F7060);

INCLUDE_ASM("rock_04/nonmatchings/E9860", func_800F7068);

INCLUDE_ASM("rock_04/nonmatchings/E9860", func_800F7070);

INCLUDE_ASM("rock_04/nonmatchings/E9860", func_800F7078);
// clang-format on
