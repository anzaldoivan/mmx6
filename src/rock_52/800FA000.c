// clang-format off
INCLUDE_ASM("asm/rock_52/nonmatchings/FA000", D_800FA000);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
void stop_cd_audio();
void func_8002048C(void);
void func_800206C0(void);
void func_800207D4(void);
void run_text_box(void);
void func_8002ACA8();
void func_80025FB0();
#include "mmx6/state.h"
extern u16 D_800C4570;
extern void (*D_800FA430[])(void*);

void func_800FA004(s8* arg0) {
    if ((D_800C4570 & 0x800) && D_80097420.transition.active == 0 &&
        arg0[1] >= 2 && arg0[1] != 7) {
        func_800139F4(8);
        stop_cd_audio();
        arg0[1] = 7;
    }
    D_800FA430[arg0[1]](arg0);
    func_8002048C();
    func_800206C0();
    func_800207D4();
    run_text_box();
    func_8002ACA8();
    func_80025FB0();
}

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
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 func_800FA42C[];

void func_800FA0D8(u8* arg0) {
    struct X4_QuadObj* q;
    s32 i;

    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    {
        s8* p;
        s8* q;
        do {
            p = &D_80090D56;
            do {
                q = &D_8009742C;
            } while (0);
        } while (0);
        *p = 0;
        *q = 0;
        D_800CF850 = 0;
        ((void (*)(s32))func_8002B2F8)(0);
    }
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 1;
    background_objects[2].y_pos.i.hi = 0x100;
    background_objects[2].unk4C = 1;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = 0xA;
        q->unk36 = 0x11;
        q->unk2 = 1;
    }
    arg0[1]++;
    for (i = 0; i < 4; i++) {
        D_800EA510[i] = func_800FA42C[i];
    }
    func_800E9ED4();
}

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

void func_800E9F7C(void);

void func_800FA1CC(u8* arg0) {
    ((void (*)(s32))SetDispMask)(1);
    func_800E9F7C();
    {
        s32 v = arg0[1];
        s32 c = 0x141;
        *(s16*)(arg0 + 8) = c;
        c = 2;
        *(s16*)(arg0 + 0xA) = c;
        arg0[1] = v + 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA218(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        background_objects[0].unk3 = 1;
        background_objects[0].y_pos.i.hi = 0x100;
        background_objects[0].unk4C = 1;
        ((u8*)arg0)[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA26C(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    temp_v0 = background_objects[0].y_pos.u.hi + 0x10;
    background_objects[0].y_pos.u.hi = temp_v0;
    if ((s16)temp_v0 >= 0x1A0) {
        background_objects[0].y_pos.u.hi = 0x1A0;
        arg0->x_pos.i.lo = 0x143;
        arg0->x_pos.i.hi = 1;
        arg0->unk1++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA2C0(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        background_objects[1].unk3 = 1;
        background_objects[1].y_pos.i.hi = 0x100;
        background_objects[1].unk4C = 1;
        ((u8*)arg0)[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA314(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    temp_v0 = background_objects[1].y_pos.u.hi - 0x10;
    background_objects[1].y_pos.u.hi = temp_v0;
    if ((s16)temp_v0 < 0x61) {
        background_objects[2].unk3 = 0;
        background_objects[1].y_pos.u.hi = 0x60;
        arg0->x_pos.u.lo = 0x144;
        arg0->x_pos.u.hi = 0xE;
        arg0->unk1++;
    }
}

#define func_800FA4D0 func_800FA36C
#include "../shared/rock_48/func_800FA4D0.c"
#undef func_800FA4D0

#define func_800FA63C func_800FA3B0
#include "../shared/rock_47/func_800FA63C.c"
#undef func_800FA63C

// clang-format off
INCLUDE_ASM("asm/rock_52/nonmatchings/FA000", func_800FA42C);
// clang-format on
