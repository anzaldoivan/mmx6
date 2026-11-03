// clang-format off
INCLUDE_ASM("asm/rock_49/nonmatchings/FA000", D_800FA000);

INCLUDE_ASM("asm/rock_49/nonmatchings/FA000", func_800FA004);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

void func_80025F34();
void func_800280F4(void);
void init_checkpoint_positions(void);
s32 func_8002B2F8(s32);
M2C_UNK reset_level();
void func_8002C2B8();
extern s8 D_80090D56;
extern s8 D_8009742C;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 D_800FA46C[];
extern u8 func_800FA468[];

void func_800FA0E8(u8* arg0) {
    s32 i;

    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    {
        s8* p;
        s8* r;
        do {
            p = &D_80090D56;
            do {
                r = &D_8009742C;
            } while (0);
        } while (0);
        *p = 0;
        *r = 0;
        D_800CF850 = 0;
        ((void (*)(s32))func_8002B2F8)(0);
    }
    i = 0;
    arg0[1]++;
    do {
        if (D_800CCF08 == 0) {
            D_800EA510[i] = func_800FA468[i];
        } else {
            D_800EA510[i] = D_800FA46C[i];
        }
        i++;
    } while (i < 4);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
struct X4_QuadObj* alloc_class6_slot(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA1A8(struct X4_BackgroundObj* arg0) {
    u8* q = (u8*)alloc_class6_slot();
    if (q != 0) {
        q[0] = 1;
        q[1] = 0xA;
        q[0x36] = 0x11;
        q[2] = 1;
    }
    background_objects[2].unk3 = 1;
    background_objects[1].unk3 = 0;
    background_objects[0].unk3 = 0;
    ((void (*)())func_800139A0)(8, q);
    arg0->unk1++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"

void func_800FA21C(struct X4_BackgroundObj* arg0) {
    if (D_80097420.transition.active == 0) {
        *(s16*)&arg0->unk4 = 0;
        background_objects[1].x_pos.u.hi = 0x120;
        background_objects[1].y_pos.u.hi = 0;
        background_objects[1].unk4C = 1;
        background_objects[1].unk3 = 1;
        background_objects[0].x_pos.u.hi = 0;
        background_objects[0].y_pos.u.hi = 0;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 1;
        play_sound(0, 1, 0);
        arg0->unk1++;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA29C(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    if (*(s16*)&arg0->unk4 >= 0x79) {
        temp_v0 = background_objects[0].x_pos.u.hi + 0x10;
        background_objects[0].x_pos.u.hi = temp_v0;
        if ((s16)temp_v0 >= 0x120) {
            background_objects[0].x_pos.u.hi = 0x120;
            if (D_800CCF08 == 0) {
                arg0->x_pos.i.lo = 0x46;
            } else {
                arg0->x_pos.i.lo = 0x61;
            }
            arg0->x_pos.i.hi = 1;
            arg0->unk1++;
        }
    } else {
        (*(s16*)&arg0->unk4)++;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA320(struct X4_BackgroundObj* arg0) {
    // !FAKE: pin the first store value to the first return register
    register s32 var_v0 asm("$2");
    s32 var_v1;
    s32 temp_v0;

    if (func_800EA480((s8*)arg0) != 0) {
        temp_v0 = background_objects[1].x_pos.u.hi - 0x10;
        background_objects[1].x_pos.u.hi = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            background_objects[1].x_pos.u.hi = 0;
            if (D_800CCF08 == 0) {
                var_v0 = 0x47;
                var_v1 = 0x1A;
            } else {
                var_v0 = 0x62;
                var_v1 = 0x16;
            }
            arg0->x_pos.i.lo = var_v0;
            arg0->x_pos.i.hi = var_v1;
            do {
            } while (0);
            arg0->unk1++;
        }
    }
}

#include "../shared/rock_49/func_800FA3A8.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001D218();
M2C_UNK reset_level();
extern struct X4_BackgroundObj background_objects[3];

void func_800FA3FC(u8* arg0) {
    s32 i;
    u8* p;

    if (D_80097420.transition.active == 0) {
        func_8001D218();
        background_objects[0].unk3 = 0;
        background_objects[1].unk3 = 0;
        background_objects[2].unk3 = 0;
        reset_level();
        i = 0xF;
        p = arg0 + 0x35;
        do {
            *p = 0;
            i--;
            p--;
        } while (i >= 0);
        arg0[0] = 0x15;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_49/nonmatchings/FA000", func_800FA468);
// clang-format on
