// clang-format off
INCLUDE_ASM("asm/rock_51/nonmatchings/FA000", D_800FA000);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800E9F7C(void);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"
extern s8 D_800CCF08;

void func_800FA004(u8* arg0) {
    s16 temp_v1;

    if (D_80097420.transition.active == 0) {
        temp_v1 = *(s16*)(arg0 + 4);
        if (temp_v1 >= 0x78) {
            D_8008EAB0 = 1;
            background_objects[2].x_pos.i.hi = 0;
            background_objects[2].y_pos.i.hi = 0x100;
            background_objects[2].unk4C = 1;
            if (D_800CCF08 == 0) {
                *(s16*)(arg0 + 8) = 0xB5;
                *(s16*)(arg0 + 0xA) = 0x20;
                arg0[1] += 2;
            } else {
                background_objects[1].unk3 = 1;
                background_objects[1].x_pos.i.hi = 0x120;
                background_objects[1].y_pos.i.hi = 0x100;
                background_objects[1].unk4C = 1;
                *(s16*)(arg0 + 8) = 0xFC;
                *(s16*)(arg0 + 0xA) = 7;
                arg0[1] += 1;
            }
            play_sound(0, 4, 0);
            return;
        }
        if (temp_v1 == 0) {
            func_800E9F7C();
        }
        *(s16*)(arg0 + 4) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD28 (*(u8**)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;
extern s16 D_800FCE08;

void func_800FA0F4(void* arg0) {
    if ((s16)M2C_FIELD(arg0, u16*, 4)++ >= 0x3D) {
        D_800FCE08 -= 2;
        ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
            &D_800FBC08, &D_800FAA08, 0x900, D_800FCE08);
        load_palette(0x60, &D_800FBC08, 0x90);
        if (D_800FCE08 == 0) {
            __builtin_memcpy(&D_800FAA08, SPAD28 + 0xC00, 0x1200);
            D_800FCE08 = 0;
            func_8002B54C(&D_800FBC08, &D_800FAA08, 0x900, 0);
            load_palette(0x60, &D_800FBC08, 0x90);
            M2C_FIELD(arg0, u16*, 8) = 0xD5;
            M2C_FIELD(arg0, u16*, 0xA) = 0xB;
            M2C_FIELD(arg0, u16*, 4) = 0;
            M2C_FIELD(arg0, u8*, 1) += 1;
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_51/nonmatchings/FA000", func_800FA2A0);
// clang-format on

#include "common.h"
#define M2C_UNK s32

void func_80025F34();
void func_800280F4(void);
void init_checkpoint_positions(void);
s32 func_8002B2F8(s32);
M2C_UNK reset_level();
void func_8002C2B8();
void func_800E9ED4(void);
extern s8 D_80090D56;
extern s8 D_8009742C;
extern s8 D_800CCF08;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 D_800FA9D4[];
extern u8 func_800FA9D0[];

void func_800FA384(u8* arg0) {
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
            D_800EA510[i] = func_800FA9D0[i];
        } else {
            D_800EA510[i] = D_800FA9D4[i];
        }
        i++;
    } while (i < 4);
    func_800E9ED4();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
struct X4_QuadObj* alloc_class6_slot(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA44C(struct X4_BackgroundObj* arg0) {
    u8* q = (u8*)alloc_class6_slot();
    if (q != 0) {
        q[0] = 1;
        q[1] = 0xA;
        q[0x36] = 0x11;
        q[2] = 1;
    }
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 1;
    ((void (*)(s32))func_800139A0)(8);
    *(s16*)&arg0->unk4 = 0;
    arg0->unk1++;
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA4C4(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[1].x_pos.u.hi -= 0x10;
        if ((s16)background_objects[1].x_pos.u.hi <= 0) {
            background_objects[1].x_pos.u.hi = 0;
            arg0->x_pos.u.lo = 0x103;
            arg0->x_pos.u.hi = 0x19;
            arg0->unk1++;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD28 (*(u8**)0x1F800028)

s32 func_800EA480(s8* arg0);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;
extern s16 D_800FCE08;

void func_800FA52C(void* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        __builtin_memcpy(&D_800FAA08, SPAD28 + 0xC00, 0x1200);
        D_800FCE08 = 0;
        func_8002B54C(&D_800FBC08, &D_800FAA08, 0x900, 0);
        load_palette(0x60, &D_800FBC08, 0x90);
        M2C_FIELD(arg0, u8*, 1) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;
extern s16 D_800FCE08;

void func_800FA64C(void* arg0) {
    D_800FCE08 += 1;
    ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
        &D_800FBC08, &D_800FAA08, 0x900, D_800FCE08);
    load_palette(0x60, &D_800FBC08, 0x90);
    if (D_800FCE08 >= 0x20) {
        s8* bg = (s8*)background_objects;

        M2C_FIELD(bg, s16*, 0xB2) = 0;
        M2C_FIELD(bg, s16*, 0xB6) = 0x200;
        M2C_FIELD(bg, u8*, 0xF4) = 1;
        M2C_FIELD(bg, u8*, 0x57) = 0;
        M2C_FIELD(arg0, u16*, 4) = 0;
        M2C_FIELD(arg0, u8*, 1) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
s32 func_800EA480(s8* arg0);
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;
extern s16 D_800FCE08;

void func_800FA700(void* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        D_800FCE08 += 2;
        ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
            &D_800FBC08, &D_800FAA08, 0x900, D_800FCE08);
        load_palette(0x60, &D_800FBC08, 0x90);
        if (D_800FCE08 >= 0x20) {
            M2C_FIELD(arg0, u16*, 4) = 0;
            M2C_FIELD(arg0, u8*, 1) += 1;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;

void func_800FA7A0(void* arg0) {
    if ((s16)M2C_FIELD(arg0, u16*, 4)++ >= 0x3C) {
        func_8002B54C(&D_800FBC08, &D_800FAA08, 0x900, 0);
        load_palette(0x60, &D_800FBC08, 0x90);
        background_objects[2].x_pos.u.hi = 0;
        background_objects[2].y_pos.u.hi = 0x100;
        background_objects[2].unk4C = 1;
        if (D_800CCF08 == 0) {
            M2C_FIELD(arg0, u16*, 8) = 0xE0;
            M2C_FIELD(arg0, u16*, 0xA) = 0x1C;
            M2C_FIELD(arg0, u8*, 1) += 2;
        } else {
            background_objects[1].unk3 = 1;
            background_objects[1].x_pos.u.hi = 0x120;
            background_objects[1].y_pos.u.hi = 0x100;
            background_objects[1].unk4C = 1;
            M2C_FIELD(arg0, u16*, 8) = 0x127;
            M2C_FIELD(arg0, u16*, 0xA) = 1;
            M2C_FIELD(arg0, u8*, 1) += 1;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA88C(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[1].x_pos.u.hi -= 0x10;
        if ((s16)background_objects[1].x_pos.u.hi <= 0) {
            background_objects[1].x_pos.u.hi = 0;
            arg0->x_pos.u.lo = 0x128;
            arg0->x_pos.u.hi = 0x19;
            arg0->unk1++;
        }
    }
}

#define func_800FA3A8 func_800FA8F4
#include "../shared/rock_49/func_800FA3A8.c"
#undef func_800FA3A8

#define func_800FA73C func_800FA948
#include "../shared/rock_50/func_800FA73C.c"
#undef func_800FA73C

// clang-format off
INCLUDE_ASM("asm/rock_51/nonmatchings/FA000", func_800FA9D0);
// clang-format on
