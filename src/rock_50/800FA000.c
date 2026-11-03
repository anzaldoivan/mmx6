// clang-format off
INCLUDE_ASM("asm/rock_50/nonmatchings/FA000", D_800FA000);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

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
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 D_800FA7C8[];
extern u8 func_800FA7C4[];

void func_800FA004(u8* arg0) {
    struct X4_QuadObj* q;
    s32 i;

    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    D_800970A2 = 1;
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    func_8002B2F8(0);
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 1;
    if ((s8)(s32)g_playthrough_state.controlled_player != 0) {
        background_objects[1].y_pos.i.hi = 0x100;
        background_objects[0].y_pos.i.hi = 0x100;
    }
    background_objects[1].x_pos.i.hi = 0x120;
    background_objects[1].unk4C = 1;
    background_objects[1].unk3 = 1;
    background_objects[0].x_pos.i.hi = 0;
    background_objects[0].unk4C = 1;
    background_objects[0].unk3 = 1;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = 0xA;
        q->unk36 = 0x11;
        q->unk2 = 1;
    }
    arg0[1]++;
    for (i = 0; i < 4; i++) {
        if ((s8)(s32)g_playthrough_state.controlled_player == 0) {
            D_800EA510[i] = func_800FA7C4[i];
        } else {
            D_800EA510[i] = D_800FA7C8[i];
        }
    }
    func_800E9ED4();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_800EA480(s8* arg0);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];

void func_800FA14C(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        if (D_800CCF08 == 0) {
            background_objects[2].unk3 = 1;
            background_objects[2].x_pos.u.hi -= 0x10;
            if ((s16)background_objects[2].x_pos.u.hi <= 0) {
                background_objects[2].x_pos.u.hi = 0;
                arg0->x_pos.u.lo = 0x93;
                arg0->x_pos.u.hi = 5;
                arg0->unk1++;
            }
        } else {
            D_8008EAB0 = 1;
            background_objects[2].y_pos.u.hi = 0x200;
            background_objects[0].y_pos.u.hi = 0x200;
            background_objects[2].unk3 = 1;
            background_objects[2].x_pos.u.hi = 0;
            background_objects[2].unk4C = 1;
            background_objects[1].unk3 = 0;
            background_objects[0].x_pos.u.hi = 0;
            background_objects[0].unk4C = 1;
            background_objects[0].unk3 = 1;
            arg0->x_pos.u.lo = 0xA0;
            arg0->x_pos.u.hi = 1;
            play_sound(0, 3, 0);
            arg0->unk1++;
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_50/nonmatchings/FA000", func_800FA230);
// clang-format on

#include "common.h"
#include "psyq/libgpu.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

void func_800E9F7C(void);

void func_800FA314(u8* arg0) {
    SetDispMask(1);
    func_800E9F7C();
    {
        // !FAKE: flag read lands in the first return register
        register s32 c asm("$2") = D_800CCF08;
        if (c == 0) {
            *(s16*)(arg0 + 8) = 0x8A;
            *(s16*)(arg0 + 0xA) = 4;
            *(s16*)(arg0 + 4) = 0;
        } else {
            *(s16*)(arg0 + 4) = 0xB4;
            *(s16*)(arg0 + 0xA) = 0;
        }
    }
    arg0[1]++;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

#define TIMER(p) (*(s16*)&(p)->unk4)

void func_800FA384(struct X4_BackgroundObj* arg0) {
    s32 var_v0;
    s32 var_v1;
    s32 temp_v0;

    if (TIMER(arg0) != 0) {
        TIMER(arg0)--;
    }
    if (func_800EA480((s8*)arg0) != 0 && TIMER(arg0) == 0) {
        temp_v0 = background_objects[1].x_pos.u.hi - 0x10;
        background_objects[1].x_pos.u.hi = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            s32 c = D_800CCF08;
            do {
            } while (0);
            background_objects[1].x_pos.u.hi = 0;
            var_v0 = 0x98;
            if (c == 0) {
                var_v0 = 0x8E;
            }
            var_v1 = 1;
            arg0->x_pos.i.lo = var_v0;
            arg0->x_pos.i.hi = var_v1;
            do {
            } while (0);
            arg0->unk1++;
        }
    }
}

#undef TIMER

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA428(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[0].x_pos.u.hi += 0x10;
        if ((s16)background_objects[0].x_pos.u.hi >= 0x120) {
            {
                // !FAKE: retail keeps the shared 0x120 in the second return register
                register s32 k asm("$3") = 0x120;
                background_objects[0].x_pos.u.hi = k;
                background_objects[2].x_pos.u.hi = k;
            }
            background_objects[2].unk3 = 0;
            background_objects[2].y_pos.u.hi = 0x300;
            background_objects[2].unk4C = 1;
            if (D_800CCF08 == 0) {
                arg0->x_pos.u.lo = 0x8F;
                arg0->x_pos.u.hi = 4;
            } else {
                arg0->x_pos.u.lo = 0x99;
                arg0->x_pos.u.hi = 7;
            }
            arg0->unk1++;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA4D0(u8* arg0) {
    s32 temp;

    if (func_800EA480((s8*)arg0) != 0) {
        if (D_800CCF08 != 0) {
            temp = (u16)background_objects[0].x_pos.i.hi + 0x10;
            background_objects[0].x_pos.i.hi = temp;
            if ((s16)temp >= 0x120) {
                background_objects[0].x_pos.i.hi = 0x120;
                background_objects[0].unk4C = 1;
                background_objects[1].x_pos.i.hi = 0x120;
                background_objects[1].y_pos.i.hi = 0x100;
                background_objects[1].unk4C = 1;
                background_objects[1].unk3 = 1;
                *(s16*)(arg0 + 8) = 0xA1;
                *(s16*)(arg0 + 0xA) = 2;
                arg0[1]++;
            }
        } else {
            arg0[1] = 9;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA57C(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    if (func_800EA480((s8*)arg0) != 0) {
        temp_v0 = background_objects[1].x_pos.u.hi - 0x10;
        background_objects[1].x_pos.u.hi = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            background_objects[2].x_pos.u.hi = 0x120;
            background_objects[2].y_pos.u.hi = 0x300;
            background_objects[1].x_pos.u.hi = 0;
            background_objects[2].unk4C = 1;
            arg0->x_pos.i.lo = 0xA3;
            arg0->x_pos.i.hi = 6;
            *(s16*)&arg0->unk4 = 0;
            arg0->unk1++;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA600(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    if (func_800EA480((s8*)arg0) != 0) {
        temp_v0 = background_objects[2].x_pos.u.hi - 0x10;
        background_objects[2].x_pos.u.hi = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            background_objects[2].x_pos.u.hi = 0;
            arg0->x_pos.i.lo = 0xA9;
            arg0->x_pos.i.hi = 4;
            background_objects[1].x_pos.u.hi = 0x120;
            background_objects[1].y_pos.u.hi = 0x400;
            background_objects[1].unk4C = 1;
            background_objects[1].unk3 = 1;
            arg0->unk1++;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA688(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        background_objects[1].x_pos.i.hi -= 0x10;
        if (background_objects[1].x_pos.i.hi <= 0) {
            *(s16*)(arg0 + 8) = 0xAD;
            *(s16*)(arg0 + 0xA) = 8;
            ((u8*)arg0)[1]++;
        }
    }
}

#define func_800FABEC func_800FA6EC
#include "../shared/rock_46/func_800FABEC.c"
#undef func_800FABEC

#include "../shared/rock_50/func_800FA73C.c"

// clang-format off
INCLUDE_ASM("asm/rock_50/nonmatchings/FA000", func_800FA7C4);
// clang-format on
