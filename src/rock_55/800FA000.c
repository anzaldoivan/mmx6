// clang-format off
INCLUDE_ASM("asm/rock_55/nonmatchings/FA000", D_800FA000);

INCLUDE_ASM("asm/rock_55/nonmatchings/FA000", func_800FA004);
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
extern s8 D_800CCF08;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 D_800FA930[];
extern u8 func_800FA92C[];

void func_800FA0E8(u8* arg0) {
    struct X4_QuadObj* q;
    s32 i;
    s32 ta;
    s32 tb;
    u8* dst;

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
    ta = (s32)func_800FA92C;
    tb = (s32)D_800FA930;
    dst = D_800EA510;
    arg0[1]++;
    do {
        if (D_800CCF08 == 0) {
            *dst = *(u8*)(i + ta);
        } else {
            *dst = *(u8*)(i + tb);
        }
        i++;
        dst++;
    } while (i < 4);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"
extern s8 D_800CCF08;

void func_800FA1E8(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        background_objects[2].unk3 = 1;
        background_objects[2].x_pos.val = 0;
        background_objects[2].y_pos.val = 0;
        if (D_800CCF08 == 0) {
            *(s16*)(arg0 + 8) = 0x1AF;
            *(s16*)(arg0 + 0xA) = 9;
        } else {
            *(s16*)(arg0 + 8) = 0x1C4;
            *(s16*)(arg0 + 0xA) = 9;
        }
        *(s16*)(arg0 + 4) = 0;
        play_sound(0, 5, 0);
        arg0[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA270(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        background_objects[1].unk3 = 1;
        background_objects[1].x_pos.i.hi = 0;
        background_objects[1].y_pos.i.hi = 0;
        background_objects[1].unk4C = 1;
        ((u8*)arg0)[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

void func_800FA2C4(s8* arg0) {
    s8* p = arg0;
    s8* bg = (s8*)background_objects;
    s32 t;

    t = *(u16*)(bg + 0x5E) + 0x10;
    *(u16*)(bg + 0x5E) = t;
    if ((s16)t >= 0x120) {
        *(u16*)(bg + 0x5E) = 0x120;
        if (D_800CCF08 == 0) {
            *(s16*)(p + 8) = 0x1B8;
            *(s16*)(p + 0xA) = 2;
        } else {
            *(s16*)(p + 8) = 0x1CD;
            *(s16*)(p + 0xA) = 2;
        }
        do {
        } while (0);
        p[1] = (u8)p[1] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_8002B2F8(s32);
s32 func_800EA480(s8* arg0);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s8 D_8009742C;
extern s8 D_800CF850;

void func_800FA330(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        func_8002B2F8(0);
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
        play_sound(0, 8, 0);
        play_sound(0, 6, 0);
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s16 D_80090D5C;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800FA3E0(u8* arg0) {
    if (!(D_80097420.frame_counter & 1)) {
        D_800CF854++;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
    }
    if ((u16)D_800CF854 >= 0x1F) {
        background_objects[1].x_pos.i.hi = 0;
        background_objects[1].y_pos.i.hi = 0x100;
        background_objects[1].unk4C = 1;
        background_objects[2].x_pos.i.hi = 0;
        background_objects[2].y_pos.i.hi = 0x100;
        background_objects[2].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"

extern s16 D_80090D5C;
extern s16 D_80097430;
extern s8 D_800CCF08;
extern s16 D_800CF854;

void func_800FA478(u8* arg0) {
    s16 v;
    s32 t;

    t = (u16)D_800CF854 - 1;
    D_800CF854 = t;
    D_80097430 -= 0x20;
    D_80090D5C -= 0x400;
    if (!(t & 0xFFFF)) {
        v = 0x1CF;
        if (D_800CCF08 == 0) {
            v = 0x1BA;
        }
        *(s16*)(arg0 + 8) = v;
        *(s16*)(arg0 + 0xA) = 1;
        do {
        } while (0);
        arg0[1]++;
    }
}

#define func_800FA9E0 func_800FA4EC
#define D_80090C90 D_80090C90
#include "../shared/rock_46/func_800FA9E0.c"
#undef func_800FA9E0
#undef D_80090C90

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s16 D_80090D5C;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_80097430;
extern s8 D_800CCF08;
extern s16 D_800CF854;

void func_800FA57C(u8* arg0) {
    u8* q;

    D_800CF854++;
    D_80097430 += 0x20;
    D_80090D5C += 0x400;
    if ((u16)D_800CF854 == 0x1F) {
        q = (u8*)background_objects;
        *(s16*)(q + 0xB2) = 1;
        *(s16*)(q + 0xB6) = 0x200;
        q[0xF4] = 1;
        if (D_800CCF08 != 0) {
            *(s16*)(q + 0xB6) = 0x400;
        }
        q[0x57] = 1;
        *(s16*)(q + 0x5E) = 0x120;
        *(s16*)(q + 0x62) = 0;
        q[0xA0] = 1;
        arg0[1]++;
    }
}

#include "common.h"

s32 func_8002B2F8(s32);
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CCF08;
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_800FA618(u8* arg0) {
    D_800CF854--;
    D_80097430 -= 0x20;
    D_80090D5C -= 0x400;
    if (!(D_800CF854 & 0xFFFF)) {
        D_80090D56 = 0;
        D_8009742C = 0;
        D_800CF850 = 0;
        ((void (*)(s32))func_8002B2F8)(0);
        if (D_800CCF08 == 0) {
            *(s16*)(arg0 + 8) = 0x1BB;
        } else {
            *(s16*)(arg0 + 8) = 0x1D0;
        }
        *(s16*)(arg0 + 0xA) = 4;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_800EA480(s8* arg0);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

#define BG(t, off) (*(t*)(bg + (off)))

void func_800FA6C0(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        if (D_800CCF08 == 0) {
            s8* bg = (s8*)background_objects;

            BG(s16, 0xB6) = 0x300;
            *(s16*)(arg0 + 0xA) = 0;
        } else {
            s8* bg = (s8*)background_objects;

            BG(s16, 0xB6) = 0x500;
        }
        D_8008EAB0 = 1;
        {
            s8* bg = (s8*)background_objects;

            BG(s8, 0xF4) = 1;
            BG(s8, 0x57) = 0;
            BG(s16, 0xB2) = 0;
        }
        *(s16*)(arg0 + 4) = 0;
        play_sound(0, 1, 0);
        arg0[1] = (u8)arg0[1] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

void func_800FA768(u8* arg0) {
    if (*(s16*)(arg0 + 4) >= 0x78) {
        u8* q = (u8*)background_objects;

        q[0x57] = 1;
        *(s16*)(q + 0x5E) = 0x120;
        *(s16*)(q + 0x62) = 0x300;
        q[0xA0] = 1;
        if (D_800CCF08 != 0) {
            *(s16*)(arg0 + 8) = 0x1D4;
            *(s16*)(arg0 + 0xA) = 2;
        }
        arg0[1]++;
        return;
    }
    *(s16*)(arg0 + 4) += 1;
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

void func_800FA7DC(struct X4_BackgroundObj* arg0) {
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
                var_v0 = 0x1BF;
                var_v1 = 5;
            } else {
                var_v0 = 0x1D6;
                var_v1 = 2;
            }
            arg0->x_pos.i.lo = var_v0;
            arg0->x_pos.i.hi = var_v1;
            do {
            } while (0);
            arg0->unk1++;
        }
    }
}

#define func_800FABEC func_800FA864
#include "../shared/rock_46/func_800FABEC.c"
#undef func_800FABEC

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001D218();
M2C_UNK reset_level();
extern struct X4_BackgroundObj background_objects[3];

void func_800FA8B4(u8* arg0) {
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
        arg0[0] = 0xB;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_55/nonmatchings/FA000", func_800FA92C);
// clang-format on
