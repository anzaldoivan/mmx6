// clang-format off
INCLUDE_ASM("asm/rock_46/nonmatchings/FA000", D_800FA000);

#include "../shared/rock_46/func_800FA004.c"
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
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 func_800FACCC[];

void func_800FA0E8(u8* arg0) {
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
    arg0[1]++;
    for (i = 0; i < 4; i++) {
        D_800EA510[i] = func_800FACCC[i];
    }
    func_800E9ED4();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
struct X4_QuadObj* alloc_class6_slot(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA190(struct X4_BackgroundObj* arg0) {
    u8* q = (u8*)alloc_class6_slot();
    if (q != 0) {
        q[0] = 1;
        q[1] = 0xA;
        q[0x36] = 0x11;
        q[2] = 1;
    }
    background_objects[2].unk3 = 1;
    background_objects[1].unk3 = 0;
    ((void (*)())func_800139A0)(8, q);
    arg0->unk1++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"

void func_800FA200(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        background_objects[2].unk3 = 1;
        background_objects[1].unk3 = 1;
        play_sound(0, 0, 0);
        *(s16*)(arg0 + 8) = 0;
        *(s16*)(arg0 + 0xA) = 5;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA268(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[2].y_pos.i.hi = 0x100;
        background_objects[2].unk4C = 1;
        background_objects[1].x_pos.i.hi = 0;
        background_objects[1].y_pos.i.hi = 0x100;
        background_objects[1].unk4C = 1;
        *(s16*)(arg0 + 8) = 5;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA2D0(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[1].x_pos.u.hi += 0x10;
        if ((s16)background_objects[1].x_pos.u.hi >= 0x120) {
            background_objects[1].x_pos.u.hi = 0x120;
            arg0->x_pos.u.lo = 6;
            arg0->x_pos.u.hi = 3;
            arg0->unk1++;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
s32 func_800EA480(s8* arg0);
extern M2C_UNK D_800FAD20;
extern M2C_UNK D_800FBF20;
extern s16 D_800FD120;

void func_800FA344(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        __builtin_memcpy((u8*)&D_800FAD20, (u8*)(SPAD28 + 0xE00), 0x600);
        D_800FD120 = 0;
        func_8002B54C(&D_800FBF20, &D_800FAD20, 0x300, 0);
        load_palette(0x70, &D_800FBF20, 0x30);
        play_sound(0, 8, 0);
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern M2C_UNK D_800FAD20;
extern M2C_UNK D_800FBF20;
extern s16 D_800FD120;

void func_800FA474(u8* arg0) {
    s32 count;

    count = (u16)D_800FD120 + 1;
    D_800FD120 = count;
    ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
        &D_800FBF20, &D_800FAD20, 0x300, (s16)count);
    load_palette(0x70, &D_800FBF20, 0x30);
    if (D_800FD120 >= 0x20) {
        ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))open_text_box)(*(u16*)(arg0 + 8),
                                                             4, 0);
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_46/nonmatchings/FA000", func_800FA518);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern M2C_UNK D_800FAD20;
extern M2C_UNK D_800FBF20;
extern s16 D_800FD120;

void func_800FA5EC(u8* arg0) {
    s32 count;

    count = (u16)D_800FD120 - 1;
    D_800FD120 = count;
    ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
        &D_800FBF20, &D_800FAD20, 0x300, (s16)count);
    load_palette(0x70, &D_800FBF20, 0x30);
    if (D_800FD120 == 0) {
        *(s16*)(arg0 + 8) = 0xA;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/globals.h"

s32 func_800EA480(s8* arg0);

void func_800FA688(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        D_8009724F = 1;
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA6CC(u8* arg0) {
    u8* bg = (u8*)background_objects;
    s32 t;

    t = *(u16*)(bg + 0x62) + 0x10;
    *(u16*)(bg + 0x62) = t;
    if ((s16)t >= 0x2A0) {
        *(u16*)(bg + 0x62) = 0x2A0;
        *(s16*)(arg0 + 8) = 0xB;
        *(s16*)(arg0 + 0xA) = 7;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#define SPAD28 (*(u8**)0x1F800028)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
s32 func_800EA480(s8* arg0);
extern M2C_UNK D_800FAD20;
extern M2C_UNK D_800FBF20;
extern s16 D_800FD120;

void func_800FA720(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        __builtin_memcpy(&D_800FAD20, SPAD28 + 0x1200, 0x600);
        D_800FD120 = 0;
        func_8002B54C(&D_800FBF20, &D_800FAD20, 0x300, 0);
        load_palette(0x90, &D_800FBF20, 0x30);
        play_sound(0, 8, 0);
        ((u8*)arg0)[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800FAD20;
extern M2C_UNK D_800FBF20;
extern s16 D_800FD120;

void func_800FA850(u8* arg0) {
    D_800FD120++;
    ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
        &D_800FBF20, &D_800FAD20, 0x300, D_800FD120);
    load_palette(0x90, &D_800FBF20, 0x30);
    if (D_800FD120 >= 0x20) {
        D_8008EAB0 = 1;
        background_objects[1].unk3 = 0;
        background_objects[2].x_pos.i.hi = 0;
        background_objects[2].y_pos.i.hi = 0x300;
        background_objects[2].unk4C = 1;
        {
            s32 t;
            t = arg0[1];
            *(u16*)(arg0 + 8) = 0x12;
            *(u16*)(arg0 + 4) = 0;
            *(u16*)(arg0 + 0xA) = 1;
            t++;
            arg0[1] = t;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
s32 func_800EA480(s8* arg0);
extern M2C_UNK D_800FAD20;
extern M2C_UNK D_800FBF20;
extern s16 D_800FD120;

void func_800FA91C(u8* arg0) {
    if (*(s16*)(arg0 + 4) >= 0x79) {
        if (func_800EA480((s8*)arg0) != 0) {
            s32 t = (u16)D_800FD120 - 1;
            D_800FD120 = t;
            ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
                &D_800FBF20, &D_800FAD20, 0x300, (s16)t);
            load_palette(0x90, &D_800FBF20, 0x30);
            if (D_800FD120 == 0) {
                *(s16*)(arg0 + 8) = 0x13;
                *(s16*)(arg0 + 0xA) = 2;
                arg0[1]++;
            }
        }
    } else {
        *(s16*)(arg0 + 4) += 1;
    }
}

#include "../shared/rock_46/func_800FA9E0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s16 D_80090D5C;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800FAA70(u8* arg0) {
    if (!(D_80097420.frame_counter & 1)) {
        D_800CF854++;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
    }
    if ((u16)D_800CF854 >= 0x1F) {
        background_objects[2].unk3 = 1;
        background_objects[2].x_pos.i.hi = 0;
        background_objects[2].y_pos.i.hi = 0x400;
        background_objects[2].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800E9F7C(void);
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800FAB00(s8* p) {
    s32 t;

    t = (u16)D_800CF854 - 1;
    D_800CF854 = t;
    D_80097430 -= 0x20;
    D_80090D5C -= 0x400;
    if ((u16)t == 0) {
        func_800E9F7C();
        play_sound(0, 2, 0);
        *(s16*)(p + 8) = 0x15;
        *(s16*)(p + 0xA) = 1;
        p[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FAB8C(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        background_objects[2].x_pos.u.hi = 0;
        background_objects[2].y_pos.u.hi = 0x500;
        background_objects[2].unk4C = 1;
        ((s16*)arg0)[4] = 0x16;
        ((s16*)arg0)[5] = 1;
        ((u8*)arg0)[1]++;
    }
}

#include "../shared/rock_46/func_800FABEC.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001D218();
M2C_UNK reset_level();
void func_800E9FB4();
void func_800E9FDC(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FAC3C(u8* arg0) {
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
        arg0[0xC] = 0;
        arg0[0xD] = 0;
        arg0[0] = 7;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
        do {
            *p = 0;
            i--;
            p--;
        } while (i >= 0);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_46/nonmatchings/FA000", func_800FACCC);
// clang-format on
