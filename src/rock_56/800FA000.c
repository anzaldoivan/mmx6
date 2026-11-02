// clang-format off
INCLUDE_ASM("asm/rock_56/nonmatchings/FA000", D_800FA000);

INCLUDE_ASM("asm/rock_56/nonmatchings/FA000", func_800FA004);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
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
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 func_800FA54C[];

void func_800FA0D8(u8* arg0) {
    struct X4_QuadObj* q;
    s32 i;

    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    ((void (*)(s32))func_8002B2F8)(0);
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = 0xA;
        q->unk36 = 0x11;
        q->unk2 = 1;
    }
    func_800139A0(8);
    arg0[1]++;
    for (i = 0; i < 4; i++) {
        D_800EA510[i] = func_800FA54C[i];
    }
    func_800E9ED4();
}

#include "common.h"
#include "mmx6/x4.h"

void func_800E9F7C(void);
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"

void func_800FA1C0(struct X4_BackgroundObj* arg0) {
    if (D_80097420.transition.active == 0) {
        background_objects[2].unk3 = 1;
        background_objects[2].x_pos.val = 0;
        background_objects[2].y_pos.val = 0;
        *(s16*)&arg0->unk4 = 0;
        func_800E9F7C();
        {
            s32 t = arg0->unk1;
            s32 c;
            c = 0x1D8;
            arg0->x_pos.i.lo = c;
            c = 7;
            arg0->x_pos.i.hi = c;
            arg0->unk1 = t + 1;
        }
    }
}

#define func_800FA318 func_800FA228
#define background_objects background_objects
#include "../shared/rock_48/func_800FA318.c"
#undef func_800FA318
#undef background_objects

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA280(struct X4_BackgroundObj* arg0) {
    background_objects[1].x_pos.u.hi -= 0x10;
    if (background_objects[1].x_pos.i.hi <= 0) {
        background_objects[1].x_pos.u.hi = 0;
        arg0->x_pos.u.lo = 0x1DF;
        arg0->x_pos.u.hi = 2;
        arg0->unk1++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA2C8(u8* arg0) {
    s32 v;

    if (func_800EA480((s8*)arg0) != 0) {
        u8* p = (u8*)background_objects;
        v = *(u16*)(p + 0x5E) + 0x10;
        *(u16*)(p + 0x5E) = v;
        if ((s16)v >= 0x120) {
            *(u16*)(p + 0x5E) = 0x120;
            *(s16*)(arg0 + 8) = 0x1E1;
            *(s16*)(arg0 + 0xA) = 6;
            arg0[1]++;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA33C(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        background_objects[1].x_pos.i.hi -= 0x10;
        if (background_objects[1].x_pos.i.hi <= 0) {
            background_objects[1].x_pos.i.hi = 0;
            *(s16*)(arg0 + 8) = 0x1E7;
            *(s16*)(arg0 + 0xA) = 5;
            ((u8*)arg0)[1]++;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA3A4(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    if (func_800EA480((s8*)arg0) != 0) {
        temp_v0 = background_objects[1].x_pos.u.hi + 0x10;
        background_objects[1].x_pos.u.hi = temp_v0;
        if ((s16)temp_v0 >= 0x120) {
            background_objects[1].x_pos.u.hi = 0x120;
            background_objects[2].y_pos.u.hi = 0x100;
            background_objects[2].unk4C = 1;
            arg0->x_pos.i.lo = 0x1EC;
            arg0->x_pos.i.hi = 5;
            arg0->unk1++;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA428(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[2].y_pos.val = 0;
        background_objects[2].unk4C = 1;
        arg0->x_pos.i.lo = 0x1F1;
        arg0->x_pos.i.hi = 4;
        arg0->unk1++;
    }
}

#define func_800FA4D0 func_800FA480
#include "../shared/rock_48/func_800FA4D0.c"
#undef func_800FA4D0

#include "../shared/rock_56/func_800FA4C4.c"

// clang-format off
INCLUDE_ASM("asm/rock_56/nonmatchings/FA000", func_800FA54C);
// clang-format on
