// clang-format off
INCLUDE_ASM("asm/rock_58/nonmatchings/FA000", D_800FA000);

INCLUDE_ASM("asm/rock_58/nonmatchings/FA000", func_800FA004);
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
extern s8 D_80090D56;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_8009742C;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 func_800FA450[];

void func_800FA0E8(u8* arg0) {
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
    i = 0;
    arg0[1]++;
    do {
        D_800EA510[i] = func_800FA450[i];
        i++;
    } while (i < 4);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
#include "mmx6/state.h"

void func_800FA1C8(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        *(s16*)(arg0 + 8) = 0x20C;
        *(s16*)(arg0 + 0xA) = 0xB;
        play_sound(0, 7, 0);
        arg0[1] += 1;
    }
}

#include "common.h"

s32 func_8002B2F8(s32);
s32 func_800EA480(s8* arg0);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s8 D_8009742C;
extern s8 D_800CF850;

void func_800FA224(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        func_8002B2F8(0);
        D_8009742C = 1;
        D_80090D56 = 1;
        D_800CF850 = 1;
        D_80090C90[0] = 0;
        D_80090C90[1] = -1;
        D_80090C90[2] = -1;
        D_80090C90[3] = -1;
        D_80090C90[4] = -1;
        D_80090C90[5] = -1;
        D_80090C90[6] = -1;
        D_80090C90[7] = -1;
        D_80090C90[8] = -1;
        D_80090C90[9] = -1;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern s16 D_80090D5C;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800FA2B8(u8* arg0) {
    s32 temp_a1;

    temp_a1 = (u16)D_800CF854 + 1;
    D_800CF854 = temp_a1;
    D_80097430 += 0x20;
    D_80090D5C += 0x400;
    if ((temp_a1 & 0xFFFF) == 0x1F) {
        background_objects[2].y_pos.u.hi = 0x100;
        background_objects[2].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"

extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800FA328(u8* arg0) {
    s32 t;

    t = (u16)D_800CF854 - 1;
    D_800CF854 = t;
    D_80097430 -= 0x20;
    D_80090D5C -= 0x400;
    if (!(t & 0xFFFF)) {
        *(s16*)(arg0 + 8) = 0x217;
        *(s16*)(arg0 + 0xA) = 6;
        arg0[1] += 1;
    }
}

#define func_800FA3A8 func_800FA384
#include "../shared/rock_49/func_800FA3A8.c"
#undef func_800FA3A8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001D218();
M2C_UNK reset_level();
extern struct X4_BackgroundObj background_objects[3];

void func_800FA3D8(u8* arg0) {
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
        arg0[0] = 0x10;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_58/nonmatchings/FA000", func_800FA450);
// clang-format on
