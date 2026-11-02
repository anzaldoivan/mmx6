// clang-format off
INCLUDE_ASM("asm/rock_47/nonmatchings/FA000", D_800FA000);
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
extern void (*D_800FA6BC[])(void*);

void func_800FA004(s8* arg0) {
    if ((D_800C4570 & 0x800) && D_80097420.transition.active == 0 &&
        arg0[1] >= 2 && arg0[1] != 0xF) {
        func_800139F4(8);
        stop_cd_audio();
        arg0[1] = 0xF;
    }
    D_800FA6BC[arg0[1]](arg0);
    func_8002048C();
    func_800206C0();
    func_800207D4();
    run_text_box();
    func_8002ACA8();
    func_80025FB0();
}

// clang-format off
INCLUDE_ASM("asm/rock_47/nonmatchings/FA000", func_800FA0D8);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
struct X4_QuadObj* alloc_class6_slot(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA180(struct X4_BackgroundObj* arg0) {
    u8* q = (u8*)alloc_class6_slot();
    if (q != 0) {
        q[0] = 1;
        q[1] = 0xA;
        q[0x36] = 0x11;
        q[2] = 1;
    }
    ((void (*)(s32))func_800139A0)(8);
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 1;
    background_objects[2].x_pos.u.hi = 0;
    background_objects[2].y_pos.u.hi = 0;
    background_objects[2].unk4C = 1;
    arg0->unk1++;
}

#include "common.h"

void func_800FA200(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        *(s16*)(arg0 + 8) = 0x17;
        *(s16*)(arg0 + 0xA) = 0xF;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA234(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[2].x_pos.i.hi = 0;
        background_objects[2].y_pos.i.hi = 0x100;
        background_objects[2].unk4C = 1;
        *(s16*)(arg0 + 8) = 0x26;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA294(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[1].unk3 = 1;
        background_objects[1].x_pos.u.hi = 0x120;
        background_objects[1].y_pos.u.hi = 0x100;
        background_objects[1].unk4C = 1;
        arg0->unk1++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA2F0(struct X4_MainObj* self) {
    background_objects[1].x_pos.u.hi -= 0x10;
    if ((s16)background_objects[1].x_pos.u.hi <= 0) {
        background_objects[1].x_pos.u.hi = 0;
        self->x_pos.i.lo = 0x27;
        self->x_pos.i.hi = 2;
        self->id++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA338(struct X4_MainObj* self) {
    if (func_800EA480((s8*)self) != 0) {
        background_objects[2].y_pos.i.hi = 0;
        background_objects[2].unk4C = 1;
        background_objects[1].unk3 = 0;
        self->x_pos.i.lo = 0x29;
        self->x_pos.i.hi = 0xA;
        self->id++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

void func_800E9F7C(void);
s32 func_800EA480(s8* arg0);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];

void func_800FA394(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        D_8008EAB0 = 1;
        func_800E9F7C();
        {
            // !FAKE: table base in the second return register
            register struct X4_BackgroundObj* bg asm("$3") = background_objects;
            bg[2].y_pos.u.hi = 0x200;
            bg[2].unk4C = 1;
        }
        *(s16*)(arg0 + 8) = 0x33;
        *(s16*)(arg0 + 0xA) = 2;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA404(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[1].unk3 = 1;
        background_objects[1].x_pos.i.hi = 0x120;
        background_objects[1].y_pos.i.hi = 0x200;
        background_objects[1].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA460(struct X4_BackgroundObj* arg0) {
    background_objects[1].x_pos.u.hi -= 0x10;
    if ((s16)background_objects[1].x_pos.u.hi <= 0) {
        background_objects[1].x_pos.u.hi = 0;
        arg0->x_pos.u.lo = 0x35;
        arg0->x_pos.u.hi = 4;
        arg0->unk1++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA4A8(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[0].unk3 = 1;
        background_objects[0].x_pos.i.hi = 0;
        background_objects[0].y_pos.i.hi = 0x200;
        background_objects[0].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA500(struct X4_BackgroundObj* arg0) {
    background_objects[0].x_pos.u.hi += 0x10;
    if (background_objects[0].x_pos.i.hi >= 0x120) {
        background_objects[0].x_pos.u.hi = 0x120;
        background_objects[2].unk3 = 0;
        arg0->x_pos.u.lo = 0x39;
        arg0->x_pos.u.hi = 7;
        arg0->unk1++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA558(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[2].unk3 = 1;
        background_objects[2].x_pos.i.hi = 0x120;
        background_objects[2].y_pos.i.hi = 0x300;
        background_objects[2].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA5B4(struct X4_BackgroundObj* arg0) {
    background_objects[2].x_pos.u.hi -= 0x10;
    if (background_objects[2].x_pos.i.hi <= 0) {
        background_objects[2].x_pos.u.hi = 0;
        arg0->x_pos.u.lo = 0x40;
        arg0->x_pos.u.hi = 6;
        arg0->unk1++;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
s32 func_800EA480(s8* arg0);

void func_800FA5FC(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        arg0[1]++;
        func_800139F4(8);
    }
}

#include "../shared/rock_47/func_800FA63C.c"

// clang-format off
INCLUDE_ASM("asm/rock_47/nonmatchings/FA000", func_800FA6B8);
// clang-format on
