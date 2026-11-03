// clang-format off
INCLUDE_ASM("asm/rock_17/nonmatchings/E9860", D_800E9860);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_17.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

void func_800E986C(void* arg0) {
    s16* p;
    s32 v;
    s32 x;
    s16* t;
    struct X4_BackgroundObj* b;
    s32 i;
    // !FAKE: register pin, local-alloc order differs from retail
    register s32 one asm("$2");
    t = &D_800EA2C8[0x120];
    i = D_800CCEF6 - 1;
    p = t + i;
    v = *p;
    b = background_objects;
    one = 1;
    b[1].unk4C = one;
    M2C_FIELD(&b[1], s32*, 0xC) = 0;
    x = v << 16;
    b[1].x_pos.val += x / 120;
    if (b[1].x_pos.i.hi >= v) {
        b[1].x_pos.i.hi = *p;
        M2C_FIELD(arg0, s16*, 4) = 0x1E;
        M2C_FIELD(arg0, u8*, 1) += 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_17.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

void func_800E9900(void* arg0) {
    s16* p;
    s32 v;
    s32 x;
    s16* t;
    struct X4_BackgroundObj* b;
    s32 i;
    // !FAKE: register pin, local-alloc order differs from retail
    register s32 one asm("$2");
    t = &D_800EA2C8[0x128];
    i = D_800CCEF6 - 1;
    p = t + i;
    v = *p;
    b = background_objects;
    one = 1;
    b->unk4C = one;
    M2C_FIELD(b, s32*, 0xC) = 0;
    x = v << 16;
    b->x_pos.val += x / 30;
    if (b->x_pos.i.hi >= v) {
        b->x_pos.i.hi = *p;
        M2C_FIELD(arg0, u8*, 1) += 1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800E9994(void* arg0) {
    u8 idx;
    s8 i;
    s32 t;
    s32 w;
    u8 v;

    v = M2C_FIELD(arg0, u8*, 2);
    M2C_FIELD(arg0, u8*, 0) = 1;
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 0x37) = -1;
    M2C_FIELD(arg0, s16*, 0xA) = 0;
    M2C_FIELD(arg0, s16*, 0xE) = 0;
    if (!(v & 0x80)) {
        M2C_FIELD(arg0, s16*, 0x34) = 0x7FFF;
        M2C_FIELD(arg0, s16*, 0x4A) = 8;
        M2C_FIELD(arg0, s16*, 0x42) = 0x60;
        M2C_FIELD(arg0, s16*, 0x3A) = 0x60;
        M2C_FIELD(arg0, s16*, 0x46) = 0;
        M2C_FIELD(arg0, s16*, 0x3E) = 0;
        M2C_FIELD(arg0, u8*, 0x36) = 0x20;
        M2C_FIELD(arg0, u8*, 5) = 0;
    } else {
        idx = v & 0x7F;
        i = idx;
        M2C_FIELD(arg0, s16*, 0x34) = 0x2208;
        t = i * 6;
        M2C_FIELD(arg0, u8*, 2) = idx;
        M2C_FIELD(arg0, s16*, 0x4A) = 0x100;
        M2C_FIELD(arg0, s16*, 0x46) = t + 0xF0;
        M2C_FIELD(arg0, s16*, 0x42) = 0x100;
        M2C_FIELD(arg0, s16*, 0x3A) = 0x100;
        M2C_FIELD(arg0, s16*, 0x3E) = t + 0xF2;
        if (i >= 0x14) {
            switch (i - 0x14) {
            case 0:
            case 1:
            case 2:
                M2C_FIELD(arg0, u8*, 2) = idx + 1;
                break;
            default:
                w = M2C_FIELD(arg0, u8*, 2);
                M2C_FIELD(arg0, u8*, 2) = w + (w - 0x15);
                break;
            }
        }
        M2C_FIELD(arg0, u8*, 0x36) = 0;
        M2C_FIELD(arg0, u8*, 5) = 1;
    }
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 4)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_17.h"

void func_80020378(void);
void func_8002048C(void);
void func_800206C0(void);
void func_800207D4(void);
void func_80025FB0();
void func_8002ACA8();
extern struct X4_BackgroundObj background_objects[3];

void func_800E9A88(struct X4_MainObj* arg0) {
    background_objects[0].unk14 = background_objects[0].x_pos;
    background_objects[0].unk18 = background_objects[0].y_pos;
    ((void (**)(struct X4_MainObj*)) & D_800EA2C8[0x130])[arg0->id](arg0);
    func_8002048C();
    func_80020378();
    func_800206C0();
    func_800207D4();
    func_8002ACA8();
    func_80025FB0();
}

#include "common.h"
#include "mmx6/rock_17.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80025F34();             /* extern */
M2C_UNK func_800280F4();             /* extern */
M2C_UNK init_checkpoint_positions(); /* extern */
M2C_UNK reset_level();               /* extern */
M2C_UNK func_8002C2B8();             /* extern */

void func_800E9B0C(void* arg0) {
    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    D_800EAACC = 1;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}

#include "common.h"

#ifndef M2C_UNK
#define M2C_UNK s32
#endif

M2C_UNK func_800139A0(M2C_UNK); /* extern */

void func_800E9B68(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (10/13)
    register s32 temp asm("$2");

    func_800139A0(8);
    temp = arg0[1] + 1;
    arg0[1] = temp;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK); /* extern */
#include "mmx6/state.h"

void func_800E9B9C(void* arg0) {
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, s16*, 4) = 0;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
        play_bgm_xa_track(3, 0x7F);
    }
}

#include "common.h"

void func_800EA278(u8* arg0, s32 arg1);
extern u8 D_800CD40C;

void func_800E9BDC(u8* arg0) {
    if (D_800CD40C == 2) {
        func_800EA278(arg0, 0);
        arg0[1] = arg0[1] + 1;
    }
}

#include "common.h"

void func_800EA278(u8* arg0, s32 arg1);

void func_800E9C28(u8* arg0) {
    s32 t;
    s16 i;

    t = *(u16*)(arg0 + 4) - 1;
    *(u16*)(arg0 + 4) = t;
    if ((t << 16) == 0) {
        for (i = 0; i < 0x18; i++) {
            func_800EA278(arg0, (u8)(i - 0x80));
        }
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800E9CB0(void* arg0) {
    background_objects[2].x_pos.val += 0xFFFAE148;
    background_objects[2].y_pos.val = 0;
    background_objects[2].unk4C = 1;
    if (background_objects[2].x_pos.i.hi <= 0) {
        background_objects[2].x_pos.i.hi = 0;
        *(s16*)((u8*)arg0 + 4) = 0xA;
        *((u8*)arg0 + 1) += 1;
    }
}

#include "../shared/rock_17/func_800E9D04.c"

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_17.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002B36C(M2C_UNK); /* extern */
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_800E9D38(void* arg0) {
    func_8002B36C(0);
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    D_800CF854 = 0x1F;
    D_80097430 = 0x3E0;
    D_80090D5C = 0x7C00;
    D_800EAACC = 0;
    D_800C4560 |= 1;
    M2C_FIELD(arg0, s16*, 4) = 4;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}

#include "common.h"
#include "mmx6/rock_17.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002B2F8(s32);

void func_800E9DC8(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 4) == 0) {
        func_8002B2F8(0);
        D_800EAACC = 1;
        M2C_FIELD(arg0, s16*, 4) = 0x1E;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
