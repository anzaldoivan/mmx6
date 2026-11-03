// clang-format off
INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800EFF4C);
// clang-format on

#include "common.h"

void func_800F0058(void) {
}

#define func_8003744C func_800F0060
#define D_80073C1C D_800FB1D0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/globals.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();               /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F009C(void* arg0) {
    void* temp_v0;

    if (D_800970A5 == 0x14) {
        D_8009723F = 2;
        func_8003D308(0x1D, 0x40);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x18;
            M2C_FIELD(temp_v0, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);

void func_800F0134(void* arg0) {
    if (D_800CCEDF == 0) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_8003D308(0x14, 0x40);
        }
        if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
            M2C_FIELD(arg0, s32*, 0x2C) = 0x6000;
            M2C_FIELD(arg0, s32*, 0x3C) =
                SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 +
                                 SPAD20 + 4);
            ((void (*)(void*, s32))set_animation)(arg0, 7);
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80040488(M2C_UNK);

void func_800F01E0(void* arg0) {
    s32 base;
    // !FAKE: keeps the table word in the third argument register
    register s32 off asm("$6");
    s32 idx;

    if (M2C_FIELD(arg0, s16*, 0xE) < 0x131) {
        M2C_FIELD(arg0, s16*, 0xE) = 0x130;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        base = SPAD20;
        off = *(s32*)(idx * 4 + base);
        M2C_FIELD(arg0, s32*, 0x3C) = base + off;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 0, off);
        func_80040488(0);
        D_800CCEF4 = 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 3;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_8003D330();
s32 func_80040498();
extern u8 D_800CCF5C;
#define D_800CCF5C (*(s8*)&D_800CCF5C)

void func_800F0294(void* arg0) {
    s32 lim;
    // !FAKE: depin: dropping it breaks the match (54/59)
    register s32 hp asm("$3");

    if (func_80040498() != 0) {
        func_8002CCB0(arg0, 0xA0, 0xA0);
        return;
    }
    hp = M2C_FIELD(arg0, s8*, 0x5C);
    lim = D_800CCF5C;
    if (hp < lim) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            play_sound(0, 0xE, 0);
            M2C_FIELD(arg0, s16*, 0x7C) = 3;
        }
        M2C_FIELD(arg0, s8*, 0x5C)++;
        func_8002CCB0(arg0, 0xA0, 0xA0);
        return;
    }
    func_8003D330(lim);
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 5) = 4;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
#undef D_800CCF5C

#include "../shared/rock_02/func_800F0380.c"

#include "common.h"

void func_800F03E4(void) {
}

#define func_800F0380 func_800F03EC
#define D_800FB1E8 D_800FB1EC
#include "../shared/rock_02/func_800F0380.c"
#undef func_800F0380
#undef D_800FB1E8

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800970AA;

void func_800F0450(void* arg0) {
    s32 v;

    if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    v = M2C_FIELD(arg0, u8*, 0x15);
    if (v == 0) {
        v = 0xFFFF0000;
    } else {
        v = 0x10000;
    }
    M2C_FIELD(arg0, s32*, 0x20) = v;
    do {
    } while (0);
    M2C_FIELD(arg0, s32*, 0x3C) =
        SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
    ((void (*)(void*, s32))set_animation)(arg0, 1);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}

#define func_800F0380 func_800F04F4
#define D_800FB1E8 D_800FB1F4
#include "../shared/rock_02/func_800F0380.c"
#undef func_800F0380
#undef D_800FB1E8

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800F0558(void* arg0) {
    s32 idx;
    s32 base;

    M2C_FIELD(arg0, s32*, 0x2C) = 0x8000;
    idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
    base = SPAD20;
    M2C_FIELD(arg0, s32*, 0x3C) = base + *(s32*)(idx * 4 + base);
    ((void (*)(void*, s32))set_animation)(arg0, 2);
    M2C_FIELD(arg0, u8*, 0x88) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}

// clang-format off
INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800F05C0);
// clang-format on

#include "common.h"

void func_800F065C(u8* arg0) {
    s32 v;

    if (*(s8*)(arg0 + 0x46) == 0) {
        arg0[6]++;
    }
    v = *(u16*)(arg0 + 0x7C) + 1;
    *(u16*)(arg0 + 0x7C) = v;
    if (!(v & 1)) {
        *(s32*)(arg0 + 0x24) = -*(s32*)(arg0 + 0x24);
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800F06B0(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0xE) < 0x131) {
        M2C_FIELD(arg0, s16*, 0xE) = 0x130;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 5) = 4;
        M2C_FIELD(arg0, u8*, 6) = 1;
    }
}

#define func_800F0380 func_800F0730
#define D_800FB1E8 D_800FB208
#include "../shared/rock_02/func_800F0380.c"
#undef func_800F0380
#undef D_800FB1E8

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800970AA;

void func_800F0794(void* arg0) {
    s32 base;
    s32 idx;
    s32 g;

    g = D_800970AA;
    if (M2C_FIELD(arg0, s16*, 0xA) < g) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
    base = SPAD20;
    M2C_FIELD(arg0, s32*, 0x3C) = base + *(s32*)(idx * 4 + base);
    ((void (*)(void*, s32))set_animation)(arg0, 5);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}

#define func_800F0380 func_800F0820
#define D_800FB1E8 D_800FB210
#include "../shared/rock_02/func_800F0380.c"
#undef func_800F0380
#undef D_800FB1E8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800F0884(struct X4_MainObj* arg0) {
    arg0->sprite_frames =
        (const u8*)(SPAD20 + *(s32*)(func_8002A47C(arg0->id) * 4 + SPAD20));
    ((void (*)(void*, s32))set_animation)(arg0, 0);
    arg0->unk7 = 0;
    arg0->action_phase++;
}

#include "common.h"

extern s16 D_800970AA;

void func_800F08E8(u8* arg0) {
    s32 g = D_800970AA;

    if (*(s16*)(arg0 + 0xA) < g) {
        arg0[0x15] = 0x40;
    } else {
        arg0[0x15] = 0;
    }
    if (*(s8*)(arg0 + 7) != 0) {
        arg0[5] = 5;
        arg0[6] = 0;
    }
}

#define func_800F0380 func_800F0934
#define D_800FB1E8 D_800FB238
#include "../shared/rock_02/func_800F0380.c"
#undef func_800F0380
#undef D_800FB1E8

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800F0998(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x3C) =
        SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
    ((void (*)(void*, s32))set_animation)(arg0, 1);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 6) += 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern s8 D_80097244;
extern u8 D_800FB220[];
extern u8 D_800FB230[];

void func_800F09FC(struct X4_MainObj* self) {
    // !FAKE: depin: dropping it breaks the match (64/70)
    register s32 lim asm("$4");
    s32 v;

    v = self->x_speed;
    lim = 0x40000;
    if ((v > lim) || (lim = -0x40000, v < lim)) {
        self->x_speed = lim;
        self->x_accel = 0;
    }
    if (self->unk15 == 0) {
        if (self->collision_flags & 2) {
            // !FAKE: goto into the other arm's hit block keeps block order; inverted returns moved bytes
            goto block_7;
        }
        return;
    }
    if (self->collision_flags & 1) {
    block_7:
        play_sound(2, 5, self);
        ((void (*)(s32))start_pad_vibration)(3);
        if (self->collision_flags & 2) {
            func_80027BA0(0, 0x17B0, 0xD0, D_800FB220);
        } else {
            func_80027BA0(0, 0x1930, 0xD0, D_800FB230);
        }
        D_80097244 = 1;
        self->x_speed = 0;
        self->x_accel = 0;
        ((void (*)(s32, s32, s32))func_80029478)(-0x6A, 4, 2);
        self->unk7C = 0;
        self->action_phase++;
    }
}

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002A47C(s32);
extern s8 D_80097244;

void func_800F0B14(void* arg0) {
    s32 base;
    s32 idx;
    s32 t;

    if ((s16)++M2C_FIELD(arg0, u16*, 0x7C) == 0xB4) {
        func_80027BA0(0, 0x17B0, 0xD0, D_800FB218);
        func_80027BA0(0, 0x1930, 0xD0, D_800FB218 + 0x10);
        D_80097244 = 1;
        idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        base = SPAD20;
        t = *(s32*)(idx * 4 + base);
        M2C_FIELD(arg0, s32*, 0x3C) = base + t;
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        M2C_FIELD(arg0, s32*, 0x24) = 0x10000;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F0BDC(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0xE) < 0x131) {
        M2C_FIELD(arg0, s16*, 0xE) = 0x130;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 5) = 5;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern void (*D_800FB24C[])(void*);

void func_800F0C0C(u8* arg0) {
    if (arg0[0x84] < 0x32U) {
        arg0[0x84] = 0x64;
    }
    D_800FB24C[(s8)arg0[6]](arg0);
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002A47C(s32);
extern s8 D_80097244;

void func_800F0C88(void* arg0) {
    s32 off;

    D_800FBC74 = 1;
    func_80027BA0(0, 0x17B0, 0xD0, D_800FB218);
    func_80027BA0(0, 0x1930, 0xD0, D_800FB218 + 0x10);
    D_80097244 = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    off = *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20 + 4);
    M2C_FIELD(arg0, s32*, 0x3C) = SPAD20 + off;
    set_animation(arg0, 6);
    play_sound(2, 2, arg0);
    M2C_FIELD(arg0, u8*, 6)++;
}

#include "common.h"
#define M2C_UNK s32
#define SPAD20_800F0D58 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800F0D58(s8* arg0) {
    s32 t;

    if (arg0[0x46] == 0) {
        *(s32*)(arg0 + 0x2C) = 0x6000;
        t = func_8002A47C(arg0[1]);
        *(s32*)(arg0 + 0x3C) =
            SPAD20_800F0D58 + *(s32*)(t * 4 + SPAD20_800F0D58 + 4);
        ((void (*)(void*, s32))set_animation)(arg0, 7);
        arg0[6]++;
    }
}
#undef SPAD20_800F0D58

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);

void func_800F0DCC(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        ((void (*)(s32, s32, void*))play_sound)(2, 5, arg0);
        ((void (*)(s32))start_pad_vibration)(3);
        D_800FBC74 = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20 + 4);
        ((void (*)(void*, s32))set_animation)(arg0, 8);
        ((void (*)(s32, s32, s32))func_80029478)(0x3C, 4, 2);
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_800FAF0C;

#define F0E78_SP20 (*(s32*)(0x1F800020))

void func_800F0E78(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0xE) < 0x131) {
        M2C_FIELD(arg0, s16*, 0xE) = 0x130;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FAF0C;
        M2C_FIELD(arg0, void**, 0x58) = &D_80074B5C;
        M2C_FIELD(arg0, u8*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x3C) =
            F0E78_SP20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + F0E78_SP20);
        set_animation(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 4;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_80041AB8 func_800F0F10
#define D_80075FD8 D_800FB260
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32
#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F0F4C(void* arg0) {
    void* temp_v0;
    s8 v;
    s32 t;

    t = M2C_FIELD(arg0, u16*, 0x7C) - 1;
    M2C_FIELD(arg0, u16*, 0x7C) = t;
    if ((t << 0x10) == 0) {
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s8*, 0) = -0x7F;
            M2C_FIELD(temp_v0, s8*, 1) = 0x1A;
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        if ((M2C_FIELD(arg0, s8*, 0x61) -= 5) >= 0x1A) {
            M2C_FIELD(arg0, s8*, 0x61) = 0;
        }
        v = M2C_FIELD(arg0, s8*, 0x61);
        {
            // !FAKE: depin: dropping it breaks the match (52/64)
            register s32 m asm("$2");

            if (v >= 6) {
                m = v;
                M2C_FIELD(arg0, s16*, 0x7E) = m;
            } else {
                m = 5;
                M2C_FIELD(arg0, s16*, 0x7E) = m;
            }
        }
    }
    func_8002CCB0(arg0, 0xA0, 0xA0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

s32 func_8002A47C(s32);
void* alloc_sprite_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F104C(void* arg0) {
    void* s1;

    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        s1 = alloc_sprite_slot();
        if (s1 != 0) {
            M2C_FIELD(s1, u8*, 0) = 0x41;
            M2C_FIELD(s1, u8*, 1) = 0x10;
            M2C_FIELD(s1, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(s1, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(s1, u8*, 2) = 0;
            M2C_FIELD(s1, void**, 0x50) = arg0;
            M2C_FIELD(s1, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40) + 0x300;
            M2C_FIELD(s1, s16*, 0x42) =
                ((func_8002A47C(0x89) * 4 + 0x20) % 16) |
                (((func_8002A47C(0x89) + 8) / 4 + 0x1E0) << 6);
            M2C_FIELD(s1, s32*, 0x3C) =
                SPAD20 + *(s32*)(func_8002A47C(0x89) * 4 + SPAD20);
        }
        M2C_FIELD(arg0, u8*, 5)++;
    }
    func_8002CCB0(arg0, 0xA0, 0xA0);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F117C(u16* arg0) {
    arg0[0x21] &= 0x7FFF;
    func_8002CCB0(arg0, 0xA0, 0xA0);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F11AC(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
    M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
    M2C_FIELD(arg0, u8*, 0x61) = 0x19;
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x5) = M2C_FIELD(arg0, u8*, 0x5) + 1;
    func_8002CCB0(arg0, 0xA0, 0xA0);
}

#include "common.h"
#define M2C_UNK s32

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F11FC(void* arg0) {
    void* temp_v0;
    s8 temp_v1;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x1A;
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        M2C_FIELD(arg0, s8*, 0x61) -= 5;
        if (M2C_FIELD(arg0, s8*, 0x61) >= 0x1A) {
            M2C_FIELD(arg0, s8*, 0x61) = 0;
        }
        temp_v1 = M2C_FIELD(arg0, s8*, 0x61);
        {
            // !FAKE: depin: dropping it breaks the match (52/64)
            register s32 var_v0 asm("$2");
            if (temp_v1 >= 6) {
                var_v0 = temp_v1;
                M2C_FIELD(arg0, s16*, 0x7E) = var_v0;
            } else {
                var_v0 = 5;
                M2C_FIELD(arg0, s16*, 0x7E) = var_v0;
            }
        }
    }
    func_8002CCB0(arg0, 0xA0, 0xA0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F12FC(struct X4_MainObj* arg0) {
    struct X4_MainObj* p = (struct X4_MainObj*)arg0->ext.raw[0];

    if (p->active != 0) {
        if (p->unk7 == 0) {
            if (--arg0->unk7E == -1) {
                arg0->unk7E = 5;
                arg0->unk42 ^= 0x8000;
            }
            func_8002CCB0(arg0, 0xA0, 0xA0);
        }
    } else {
        clear_object_slot();
    }
}

#define func_80046C64 func_800F1388
#define D_800762A0 D_800FB280
#include "../shared/d1000/func_80046C64.c"
#undef func_80046C64
#undef D_800762A0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F13C8(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F13E8(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F1408(void) {
    clear_object_slot();
}

#include "common.h"
#include "mmx6/rock_02.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*);                  /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */
M2C_UNK func_80030ECC(void*);                   /* extern */
s32 check_enemy_hits(void*);                    /* extern */
M2C_UNK func_80049E50(void*);                   /* extern */

void func_800F1428(struct MainObj* arg0) {
    if ((D_800FBC70 != 0) || (D_800FBC74 != 0)) {
        arg0->state = 2;
        return;
    }
    if ((check_enemy_hits(arg0) < 0) || (arg0->collision_flags != 0)) {
        func_80049E50(arg0);
        arg0->state = 2;
        return;
    }
    func_80030ECC(arg0);
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x10, 0x10);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F14D0(void) {
    clear_object_slot();
}

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);

void func_800F14F0(struct ObjectHeader* arg0) {
    if (D_800FBC70 != 0 || D_800FBC74 != 0 ||
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 4) == 2) {
        arg0->state = 2;
        return;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x30, 0x20);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F1574(void) {
    clear_object_slot();
}

#include "common.h"
#include "mmx6/rock_02.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*);                  /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */

void func_800F1594(void* arg0) {
    u8 temp_v0;
    void* temp_a0;
    void* temp_v1;

    if (D_800FBC70 != 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
    temp_v0 = M2C_FIELD(temp_v1, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x15) = temp_v0;
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) + 8;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) - 8;
    }
    temp_a0 = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, s16*, 0xE) = (s16)(M2C_FIELD(temp_a0, s16*, 0xE) - 8);
    if ((M2C_FIELD(temp_a0, s8*, 5) != 0xA) ||
        (M2C_FIELD(temp_a0, s8*, 6) >= 4)) {
        func_8002CCB0(arg0, 0x40, 0x40);
    }
    animate_object(arg0);
    apply_object_motion(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F165C(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_02.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);

void func_800F167C(struct X4_MainObj* arg0) {
    struct X4_MainObj* temp_a1;

    temp_a1 = M2C_FIELD(arg0, struct X4_MainObj**, 0x7C);
    arg0->unk15 = temp_a1->unk15;
    arg0->x_pos.u.hi = temp_a1->x_pos.u.hi;
    arg0->y_pos.u.hi = temp_a1->y_pos.u.hi;
    if (D_800FBC70 != 0) {
        arg0->state = 2;
        return;
    }
    if (temp_a1->unk17 == 0xC) {
        func_8002CCB0(arg0, 0x40, 0x40);
    }
    animate_object(arg0);
    apply_object_motion(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F1704(void) {
    clear_object_slot();
}
