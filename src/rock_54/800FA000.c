// clang-format off
INCLUDE_ASM("asm/rock_54/nonmatchings/FA000", D_800FA000);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80025F34();
void func_800280F4(void);
void init_checkpoint_positions(void);
s32 func_8002B2F8(s32);
M2C_UNK reset_level();
void func_8002C2B8();
struct X4_QuadObj* alloc_class6_slot(void);
void func_800E9ED4(void);
extern s8 D_80090D56;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_8009742C;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 D_800FA72C[];
extern u8 func_800FA728[];

void func_800FA004(u8* arg0) {
    struct X4_QuadObj* q;
    s32 i;
    u8* dst;
    u8* src;

    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    {
        s8* pa;
        s8* pb;
        do {
            pa = &D_80090D56;
        } while (0);
        do {
            do {
                pb = &D_8009742C;
            } while (0);
        } while (0);
        *pa = 0;
        *pb = 0;
        D_800CF850 = 0;
        func_8002B2F8(0);
    }
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = 0xA;
        q->unk36 = 0x11;
        q->unk2 = 1;
    }
    arg0[1]++;
    for (i = 0; i < 4; i++) {
        if ((s8)(s32)g_playthrough_state.controlled_player == 0) {
            D_800EA510[i] = func_800FA728[i];
        } else {
            D_800EA510[i] = D_800FA72C[i];
        }
    }
    if ((s8)(s32)g_playthrough_state.controlled_player == 0) {
        background_objects[2].y_pos.val = 0;
    } else {
        background_objects[2].y_pos.i.hi = 0x200;
    }
    background_objects[2].unk4C = 1;
    func_800E9ED4();
}

// clang-format off
INCLUDE_ASM("asm/rock_54/nonmatchings/FA000", func_800FA13C);
// clang-format on

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA220(u8* arg0) {
    background_objects[2].unk3 = 1;
    background_objects[2].x_pos.val = 0;
    background_objects[2].unk4C = 1;
    *(s16*)(arg0 + 4) = 0;
    play_sound(0, 1, 0);
    ((void (*)(M2C_UNK))SetDispMask)(1);
    arg0[1]++;
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

void func_800FA280(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 4) >= 0x78) {
        background_objects[0].unk3 = 1;
        background_objects[0].x_pos.u.hi = 0;
        background_objects[0].y_pos.u.hi = 0;
        background_objects[0].unk4C = 1;
        M2C_FIELD(arg0, u8*, 1)++;
        return;
    }
    M2C_FIELD(arg0, s16*, 4)++;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA2D0(struct X4_BackgroundObj* arg0) {
    // !FAKE: pin the first store value to the first return register
    register s32 var_v0 asm("$2");
    s32 var_v1;
    s32 temp_v0;
    struct X4_BackgroundObj* p = arg0;

    temp_v0 = background_objects[0].x_pos.u.hi + 0x10;
    background_objects[0].x_pos.u.hi = temp_v0;
    if ((s16)temp_v0 >= 0x100) {
        background_objects[0].x_pos.u.hi = 0x100;
        if (D_800CCF08 == 0) {
            var_v0 = 0x16A;
            var_v1 = 2;
        } else {
            var_v0 = 0x195;
            var_v1 = 1;
        }
        p->x_pos.i.lo = var_v0;
        p->x_pos.i.hi = var_v1;
        do {
        } while (0);
        p->unk1++;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA344(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[1].unk3 = 1;
        background_objects[1].x_pos.u.hi = 0x100;
        background_objects[1].y_pos.u.hi = 0;
        if (D_800CCF08 != 0) {
            background_objects[1].y_pos.u.hi = 0x200;
        }
        background_objects[1].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA3B0(struct X4_BackgroundObj* arg0) {
    // !FAKE: pin the first store value to the first return register
    register s32 var_v0 asm("$2");
    s32 var_v1;
    s32 temp_v0;
    struct X4_BackgroundObj* p = arg0;

    temp_v0 = background_objects[1].x_pos.u.hi - 0x10;
    background_objects[1].x_pos.u.hi = temp_v0;
    if ((s16)temp_v0 <= 0) {
        background_objects[1].x_pos.u.hi = 0;
        if (D_800CCF08 == 0) {
            var_v0 = 0x16C;
            var_v1 = 0x16;
        } else {
            var_v0 = 0x196;
            var_v1 = 3;
        }
        p->x_pos.i.lo = var_v0;
        p->x_pos.i.hi = var_v1;
        do {
        } while (0);
        p->unk1++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800E9F7C(void);
s32 func_800EA480(s8* arg0);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];

void func_800FA418(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        D_8008EAB0 = 1;
        background_objects[0].unk3 = 0;
        background_objects[1].unk3 = 0;
        background_objects[2].x_pos.u.hi = 0;
        background_objects[2].y_pos.u.hi = 0x100;
        background_objects[2].unk4C = 1;
        *(s16*)(arg0 + 4) = 0;
        if (D_800CCF08 != 0) {
            func_800E9F7C();
            play_sound(0, 8, 0);
        }
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA4AC(u8* arg0) {
    if (*(s16*)(arg0 + 4) >= 0x78) {
        background_objects[0].unk3 = 1;
        background_objects[0].x_pos.u.hi = 0;
        background_objects[0].y_pos.u.hi = 0x100;
        background_objects[0].unk4C = 1;
        arg0[1]++;
        return;
    }
    (*(s16*)(arg0 + 4))++;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA500(struct X4_BackgroundObj* arg0) {
    struct X4_BackgroundObj* o = arg0;
    // !FAKE: value register order
    register s32 a asm("$2");
    s16 b;

    background_objects[0].x_pos.u.hi += 0x10;
    if (background_objects[0].x_pos.i.hi >= 0x120) {
        background_objects[0].x_pos.u.hi = 0x120;
        if (D_800CCF08 == 0) {
            a = 0x182;
            b = 9;
        } else {
            a = 0x199;
            b = 6;
        }
        o->x_pos.u.lo = a;
        o->x_pos.u.hi = b;
        do {
        } while (0);
        o->unk1++;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA574(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[1].unk3 = 1;
        background_objects[1].x_pos.u.hi = 0x120;
        background_objects[1].y_pos.u.hi = 0x100;
        if (D_800CCF08 != 0) {
            background_objects[1].y_pos.u.hi = 0x300;
        }
        background_objects[1].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA5E4(struct X4_BackgroundObj* arg0) {
    // !FAKE: pin the first store value to the first return register
    register s32 var_v0 asm("$2");
    s32 var_v1;
    s32 temp_v0;
    struct X4_BackgroundObj* p = arg0;

    temp_v0 = background_objects[1].x_pos.u.hi - 0x10;
    background_objects[1].x_pos.u.hi = temp_v0;
    if ((s16)temp_v0 <= 0) {
        background_objects[1].x_pos.u.hi = 0;
        background_objects[2].unk3 = 0;
        if (D_800CCF08 == 0) {
            var_v0 = 0x18B;
            var_v1 = 0xA;
        } else {
            var_v0 = 0x19F;
            var_v1 = 0x10;
        }
        p->x_pos.i.lo = var_v0;
        p->x_pos.i.hi = var_v1;
        do {
        } while (0);
        p->unk1++;
    }
}

#define func_800FA3A8 func_800FA64C
#include "../shared/rock_49/func_800FA3A8.c"
#undef func_800FA3A8

#define func_800FA73C func_800FA6A0
#include "../shared/rock_50/func_800FA73C.c"
#undef func_800FA73C

// clang-format off
INCLUDE_ASM("asm/rock_54/nonmatchings/FA000", func_800FA728);
// clang-format on
