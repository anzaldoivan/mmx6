// clang-format off
INCLUDE_ASM("asm/rock_48/nonmatchings/FA000", D_800FA000);
// clang-format on

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80025F34();
void func_800280F4(void);
void init_checkpoint_positions(void);
s32 func_8002B2F8(s32);
M2C_UNK reset_level();
void func_8002C2B8();
void func_800E9ED4(void);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;
extern u8 D_800EA510[];
extern u8 func_800FA5F4[];

void func_800FA004(u8* arg0) {
    s32 i;

    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    func_8002B2F8(0);
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 0;
    SetDispMask(1);
    D_8009742C = 0;
    D_80090D56 = 0;
    D_800CF850 = 0;
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
    D_800CF854 = 0x1F;
    D_80097430 = 0x3E0;
    D_80090D5C = 0x7C00;
    arg0[1]++;
    for (i = 0; i < 4; i++) {
        D_800EA510[i] = func_800FA5F4[i];
    }
    func_800E9ED4();
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
void stop_cd_audio();
void func_8002048C(void);
void func_800206C0(void);
void func_800207D4(void);
void run_text_box(void);
void func_80025FB0();
void func_8002ACA8();
#include "mmx6/state.h"
extern u16 D_800C4570;
extern void (*D_800FA5F8[])(void*);

void func_800FA120(s8* arg0) {
    if ((D_800C4570 & 0x800) && D_80097420.transition.active == 0 &&
        arg0[1] >= 2 && arg0[1] != 9) {
        func_800139F4(8);
        stop_cd_audio();
        arg0[1] = 9;
    }
    D_800FA5F8[arg0[1]](arg0);
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

struct X4_QuadObj* alloc_class6_slot(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA1F4(struct X4_BackgroundObj* arg0) {
    u8* q = (u8*)alloc_class6_slot();
    if (q != 0) {
        q[0] = 1;
        q[1] = 0xA;
        q[0x36] = 0x11;
        q[2] = 1;
    }
    background_objects[2].unk3 = 1;
    background_objects[2].x_pos.i.hi = 0;
    background_objects[2].y_pos.i.hi = 0;
    *(s16*)&arg0->unk4 = 0x3C;
    arg0->unk1++;
}

#include "common.h"

void func_800E9F7C(void);
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;
#define D_80090D5C (*(u16*)&D_80090D5C)
#define D_80097430 (*(u16*)&D_80097430)
#define D_800CF854 (*(u16*)&D_800CF854)

void func_800FA268(u8* arg0) {
    if (*(s16*)(arg0 + 4) != 0) {
        *(s16*)(arg0 + 4) -= 1;
        return;
    }
    if (!(D_80097420.frame_counter & 3)) {
        D_800CF854 -= 1;
        D_80097430 -= 0x20;
        D_80090D5C -= 0x400;
    }
    if (D_800CF854 == 0) {
        func_800E9F7C();
        {
            s32 t = arg0[1] + 1;
            // !FAKE: constant in the second return register
            register s32 k asm("$3") = 0x78;
            *(s16*)(arg0 + 8) = k;
            *(s16*)(arg0 + 0xA) = 2;
            arg0[1] = t;
        }
    }
}
#undef D_80090D5C
#undef D_80097430
#undef D_800CF854

#include "../shared/rock_48/func_800FA318.c"

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA370(struct X4_BackgroundObj* arg0) {
    background_objects[1].x_pos.u.hi -= 0x10;
    if (background_objects[1].x_pos.i.hi <= 0) {
        arg0->x_pos.u.lo = 0x7A;
        arg0->x_pos.u.hi = 1;
        arg0->unk1++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA3B4(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        background_objects[1].x_pos.i.hi = 0;
        background_objects[0].unk3 = 1;
        background_objects[0].x_pos.i.hi = 0;
        background_objects[0].y_pos.i.hi = 0;
        background_objects[0].unk4C = 1;
        ((u8*)arg0)[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern struct X4_BackgroundObj background_objects[3];
void func_800FA40C(void* arg0) {
    s32 v;

    v = background_objects[0].x_pos.u.hi + 0x10;
    background_objects[0].x_pos.u.hi = v;
    if ((s16)v >= 0x120) {
        background_objects[0].x_pos.u.hi = 0x120;
        background_objects[2].unk3 = 0;
        M2C_FIELD(arg0, s16*, 8) = 0x7B;
        M2C_FIELD(arg0, s16*, 0xA) = 0xB;
        M2C_FIELD(arg0, u8*, 1) = M2C_FIELD(arg0, u8*, 1) + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA464(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[0].unk3 = 0;
        background_objects[1].unk3 = 0;
        background_objects[2].unk3 = 1;
        background_objects[2].x_pos.i.hi = 0;
        background_objects[2].y_pos.i.hi = 0x100;
        background_objects[2].unk4C = 1;
        *(s16*)(arg0 + 8) = 0x86;
        *(s16*)(arg0 + 0xA) = 4;
        arg0[1]++;
    }
}

#include "../shared/rock_48/func_800FA4D0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001D218();
M2C_UNK reset_level();
void func_800E9FB4();
void func_800E9FDC(void);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEF7;

void func_800FA514(u8* arg0) {
    s32 i;
    u8* p;

    if (D_80097420.transition.active == 0) {
        func_800E9FB4();
        func_800E9FDC();
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
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
        if (arg0[0x66] < 3) {
            if (*(s16*)(arg0 + 0xD2) >= 0xBB8 ||
                *(s16*)(arg0 + 0xD4) >= 0xBB8) {
                arg0[0] = 0x13;
                arg0[0x1D] = 5;
                return;
            }
        }
        arg0[0xC] = 0x13;
        arg0[0xD] = 0;
        D_800CCEF7 = 0;
        arg0[0] = 0xB;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_48/nonmatchings/FA000", func_800FA5F4);
// clang-format on
