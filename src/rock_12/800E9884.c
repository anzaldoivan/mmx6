#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C850(void*, s32);
extern u16 D_800EA774[][10];

void func_800E9884(void* arg0) {
    void* child;
    s32 idx;

    M2C_FIELD(arg0, s8*, 0x37) = -1;
    M2C_FIELD(arg0, s8*, 0x3) = 1;
    M2C_FIELD(arg0, s32*, 0x8) = 0;
    M2C_FIELD(arg0, s32*, 0xC) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    idx = M2C_FIELD(arg0, s8*, 0x2);
    M2C_FIELD(arg0, u16*, 0x16) = D_800EA774[idx][0];
    M2C_FIELD(arg0, u16*, 0x1A) = D_800EA774[idx][1];
    M2C_FIELD(arg0, u16*, 0x1E) = D_800EA774[idx][2];
    M2C_FIELD(arg0, u16*, 0x22) = D_800EA774[idx][3];
    M2C_FIELD(arg0, u16*, 0x26) = D_800EA774[idx][4];
    M2C_FIELD(arg0, u16*, 0x2A) = D_800EA774[idx][5];
    M2C_FIELD(arg0, u16*, 0x2E) = D_800EA774[idx][6];
    M2C_FIELD(arg0, u16*, 0x32) = D_800EA774[idx][7];
    switch (idx) {
    case 0:
        child = func_8002C850(arg0, 0);
        if (child != 0) {
            M2C_FIELD(child, u8*, 0x0) = 1;
            M2C_FIELD(child, u8*, 0x1) = 9;
            M2C_FIELD(child, u8*, 0x36) = M2C_FIELD(arg0, u8*, 0x36);
            M2C_FIELD(child, u8*, 0x2) = 4;
            M2C_FIELD(child, u16*, 0x34) = M2C_FIELD(arg0, u16*, 0x34);
            M2C_FIELD(child, s32*, 0x38) = M2C_FIELD(arg0, s32*, 0x38);
        }
    case 4:
        M2C_FIELD(arg0, s32*, 0x40) = 0xA00000 / M2C_FIELD(arg0, s32*, 0x38);
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        break;
    case 1:
        child = func_8002C850(arg0, 0);
        if (child != 0) {
            M2C_FIELD(child, u8*, 0x0) = 1;
            M2C_FIELD(child, u8*, 0x1) = 9;
            M2C_FIELD(child, u8*, 0x36) = M2C_FIELD(arg0, u8*, 0x36);
            M2C_FIELD(child, u8*, 0x2) = 5;
            M2C_FIELD(child, s32*, 0x38) = M2C_FIELD(arg0, s32*, 0x38);
            M2C_FIELD(child, u16*, 0x34) = M2C_FIELD(arg0, u16*, 0x34);
        }
    case 5:
        M2C_FIELD(arg0, s32*, 0x44) = 0x400000 / M2C_FIELD(arg0, s32*, 0x38);
        M2C_FIELD(arg0, u8*, 0x5) = 1;
        break;
    case 2:
    case 6:
        M2C_FIELD(arg0, s32*, 0x40) = 0x1400000 / M2C_FIELD(arg0, s32*, 0x38);
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        break;
    case 3:
    case 7:
        M2C_FIELD(arg0, s32*, 0x44) = 0x800000 / M2C_FIELD(arg0, s32*, 0x38);
        M2C_FIELD(arg0, u8*, 0x5) = 3;
        break;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define F(p, T, o) (*(T*)((u8*)(p) + (o)))

struct X4_QuadObj* alloc_class6_slot(void);
extern u16 D_800EA814[][8];
extern u16 D_800EA844[];

void func_800E9A98(void* arg0) {
    struct X4_QuadObj* child;
    s32 idx;

    F(arg0, s8, 0x37) = -1;
    F(arg0, u8, 0x3) = 1;
    F(arg0, s32, 0x8) = 0;
    F(arg0, s32, 0xC) = 0;
    F(arg0, u8, 0x4)++;
    if (F(arg0, s8, 0x2) == 0) {
        child = alloc_class6_slot();
        F(arg0, void*, 0x38) = child;
        if (child != 0) {
            F(child, u8, 0x0) = 1;
            F(F(arg0, void*, 0x38), u8, 0x1) = 0xA;
            F(F(arg0, void*, 0x38), u8, 0x36) = F(arg0, u8, 0x36);
            F(F(arg0, void*, 0x38), u8, 0x2) = 1;
        }
    }
    idx = F(arg0, s8, 0x2);
    F(arg0, u16, 0x16) = D_800EA814[idx][0];
    F(arg0, u16, 0x1A) = D_800EA814[idx][1];
    F(arg0, u16, 0x1E) = D_800EA814[idx][2];
    F(arg0, u16, 0x22) = D_800EA814[idx][3];
    F(arg0, u16, 0x26) = D_800EA814[idx][4];
    F(arg0, u16, 0x2A) = D_800EA814[idx][5];
    F(arg0, u16, 0x2E) = D_800EA814[idx][6];
    F(arg0, u16, 0x32) = D_800EA814[idx][7];
    F(arg0, u16, 0x34) = D_800EA844[idx];
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800EA858[];
extern s16 D_800EA874[][2];
extern u8 D_800EA8A8[][8];
extern u8 D_800EA9AC[];

#define SCR20 (*(s32**)0x1F800020)
#define F(T, o) (*(T*)((u8*)arg0 + (o)))

void func_800E9BAC(void* arg0) {
    s32* p;
    s8 kind;
    s8 idx;
    s32 off;

    F(u8, 0x0) = 1;
    F(u16, 0x42) = 0x7800;
    F(u16, 0x40) = 0x1880;
    p = SCR20;
    kind = F(s8, 0x2);
    off = *p;
    F(void*, 0x30) = D_800EA9AC;
    F(s8, 0x14) = -1;
    F(u8, 0x3) = 1;
    F(s32, 0x3C) = (s32)p + off;
    if (kind == 0) {
        set_animation(arg0, 0);
        play_sound(2, 0x49, 0);
    } else if (kind == 1) {
        set_animation(arg0, 1);
        play_sound(2, 0x4A, 0);
        idx = F(s8, 0x54);
        func_80027BA0(D_800EA858[idx], D_800EA874[idx][0], D_800EA874[idx][1],
                      D_800EA8A8[idx]);
        background_objects[D_800EA858[idx]].unk4C = kind;
    } else {
        set_animation(arg0, 2);
        play_sound(2, 0x49, 0);
    }
    F(u8, 0x4) = F(u8, 0x4) + 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800CCED4;
extern s16 D_800EA858[];
extern s16 D_800EA874[][2];
extern u8 D_800EA8A8[][8];

#define F(T, o) (*(T*)((u8*)arg0 + (o)))

void func_800E9D08(void* arg0) {
    s8 idx;
    s16* p;
    u8(*r)[8];
    u8* q;
    // !FAKE: pin the table offset in the first result register as retail allocates it
    register s32 off asm("$3");

    ((void (*)())func_80017A04)();
    if (F(s8, 0x46) == 0) {
        if (F(s8, 0x2) == 0) {
            idx = F(s8, 0x54);
            p = &D_800EA858[idx];
            r = D_800EA8A8;
            do {
                q = (u8*)D_800EA874;
            } while (0);
            off = idx * 4;
            func_80027BA0(*p, *(s16*)(off + q),
                          ((s16*)((u8*)D_800EA874 + off))[1], r[idx]);
            background_objects[*p].unk4C = 1;
            F(u8, 0x3) = 0;
        }
        D_800CCED4 = 0;
        F(u8, 0x4) = F(u8, 0x4) + 1;
    }
}

#undef F

#define func_80041AB8 func_800E9DE4
#define D_80075FD8 D_800EA4DC
#define FAMILY_FIELD 29
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_80041AB8 func_800E9E20
#define D_80075FD8 D_800EA808
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800E9E5C
#define D_80075FD8 D_800EA84C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800E9E98
#define D_80075FD8 D_800EA9B8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "psyq/libspu.h"

#include "psyq/libsnd.h"
void func_8005BA24(void);
extern s8 D_80090D55;
extern s8 D_80090D64[];
extern s32 D_800E0D38;

void func_800E9ED4(void) {
    s32 t;

    if (D_80090D64[5] != -1) {
        SsSepClose(D_80090D64[5]);
    }
    t = SsSepOpen((void*)D_800E0D38, D_80090D55, 1);
    D_80090D64[5] = t;
    SsSepSetVol(t, 0, 0x7F, 0x7F);
    SsUtSetReverbType(3);
    while (SpuClearReverbWorkArea(3) == -1) {
    }
    func_8005BA24();
    SsUtSetReverbDepth(0x40, 0x40);
}

#include "common.h"

#define M2C_UNK s32

#include "psyq/libsnd.h"
extern s8 D_80090D69;

void func_800E9F7C(void) {
    if (D_80090D69 != -1) {
        SsSepPlay(D_80090D69, 0, 1, 0);
    }
}

#include "common.h"

#include "psyq/libsnd.h"
extern s8 D_80090D69;

void func_800E9FB4(void) {
    SsSepStop(D_80090D69, 0);
}

#include "common.h"

#include "psyq/libsnd.h"
void func_8005BA04(void);
extern s8 D_80090D64[];

void func_800E9FDC(void) {
    SsSepClose(D_80090D64[5]);
    D_80090D64[5] = -1;
    func_8005BA04();
    SsUtSetReverbType(0);
    SsUtSetReverbDepth(0, 0);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA02C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) != 0) {
        M2C_FIELD(arg0, s32*, 0x14) += M2C_FIELD(arg0, s32*, 0x40);
        M2C_FIELD(arg0, s32*, 0x2C) += M2C_FIELD(arg0, s32*, 0x40);
    } else {
        M2C_FIELD(arg0, s32*, 0x1C) -= M2C_FIELD(arg0, s32*, 0x40);
        M2C_FIELD(arg0, s32*, 0x24) -= M2C_FIELD(arg0, s32*, 0x40);
    }
    if (--M2C_FIELD(arg0, s32*, 0x38) == 0) {
        M2C_FIELD(arg0, u8*, 4) += 1;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA0A8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 1) {
        M2C_FIELD(arg0, s32*, 0x28) -= M2C_FIELD(arg0, s32*, 0x44);
        M2C_FIELD(arg0, s32*, 0x30) -= M2C_FIELD(arg0, s32*, 0x44);
    } else {
        M2C_FIELD(arg0, s32*, 0x18) += M2C_FIELD(arg0, s32*, 0x44);
        M2C_FIELD(arg0, s32*, 0x20) += M2C_FIELD(arg0, s32*, 0x44);
    }
    if (--M2C_FIELD(arg0, s32*, 0x38) == 0) {
        M2C_FIELD(arg0, u8*, 4)++;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA124(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x2) == 2) {
        M2C_FIELD(arg0, s32*, 0x14) += M2C_FIELD(arg0, s32*, 0x40);
        M2C_FIELD(arg0, s32*, 0x2C) += M2C_FIELD(arg0, s32*, 0x40);
    } else {
        M2C_FIELD(arg0, s32*, 0x1C) -= M2C_FIELD(arg0, s32*, 0x40);
        M2C_FIELD(arg0, s32*, 0x24) -= M2C_FIELD(arg0, s32*, 0x40);
    }
    if (--M2C_FIELD(arg0, s32*, 0x38) == 0) {
        M2C_FIELD(arg0, u8*, 0x4) += 1;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA1A0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        M2C_FIELD(arg0, s32*, 0x28) -= M2C_FIELD(arg0, s32*, 0x44);
        M2C_FIELD(arg0, s32*, 0x30) -= M2C_FIELD(arg0, s32*, 0x44);
    } else {
        M2C_FIELD(arg0, s32*, 0x18) += M2C_FIELD(arg0, s32*, 0x44);
        M2C_FIELD(arg0, s32*, 0x20) += M2C_FIELD(arg0, s32*, 0x44);
    }
    if (--M2C_FIELD(arg0, s32*, 0x38) == 0) {
        M2C_FIELD(arg0, u8*, 4)++;
    }
}

#define func_800EA750 func_800EA21C
#include "../shared/rock_11/func_800EA750.c"
#undef func_800EA750

#define func_800EA750 func_800EA224
#include "../shared/rock_11/func_800EA750.c"
#undef func_800EA750

#define func_800EA750 func_800EA22C
#include "../shared/rock_11/func_800EA750.c"
#undef func_800EA750

#define func_80041AB8 func_800EA234
#define D_80075FD8 D_800EA7EC
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
extern s16 D_800CCED4;

void func_800EA270(struct ObjectHeader* arg0) {
    clear_object_slot();
    arg0->on_screen = 0;
    D_800CCED4 = 0;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA2A0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x38), u8*, 0x36) =
            (u8)M2C_FIELD(arg0, u8*, 0x36);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800EA2C8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x38), s8*, 4) = 2;
    }
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_12/nonmatchings/E9860", func_800EA304);
// clang-format on
