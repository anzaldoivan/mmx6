// clang-format off
INCLUDE_ASM("asm/rock_19/nonmatchings/E9860", D_800E9860);
// clang-format on

#include "common.h"

extern u16 D_800C4570;
extern s32 D_800EA760[];

s32 play_sound(s32, s32, void*);

void func_800E9864(u8* arg0) {
    s32 i = (s32)arg0;
    s32 v = D_800EA760[i];

    if (v < 0) {
        // !FAKE: retail block order, out-of-range arm shares the clear block
        goto clear;
    }
    if (v >= 2) {
        if (v >= 0xB) {
            // !FAKE: retail block order, out-of-range arm shares the clear block
            goto clear;
        }
        // !FAKE: retail places the count arm after the low arm
        goto count;
    }
    if (D_800C4570 & 0x1000) {
        D_800EA760[i] = v + 1;
        return;
    }
    if (D_800C4570 & 0x4000) {
        D_800EA760[i] = 0;
    }
    return;
count:
    if (D_800C4570 & 0x4000) {
        if (++D_800EA760[i] == 0xB) {
            play_sound(5, 1, 0);
        }
    }
    return;
clear:
    if (D_800C4570 & 0x5000) {
        D_800EA760[i] = 0;
    }
}

#include "common.h"

extern u16 D_800C4570;
extern s32 D_800EA760[];

s32 play_sound(s32, s32, void*);

void func_800E9958(s32 arg0) {
    switch (D_800EA760[arg0]) {
    case 0 ... 1:
        if (D_800C4570 & 0x4000) {
            D_800EA760[arg0]++;
            return;
        }
        if (D_800C4570 & 0x1000) {
            D_800EA760[arg0] = 0;
        }
        break;
    case 2 ... 10:
        if (D_800C4570 & 0x1000) {
            if (++D_800EA760[arg0] == 0xB) {
                play_sound(5, 1, 0);
            }
        } else if (D_800C4570 & 0x4000) {
            D_800EA760[arg0] = 0;
        }
        break;
    default:
        if (D_800C4570 & 0x4000) {
            D_800EA760[arg0] = 0;
        }
        break;
    }
}

#include "common.h"
#include "psyq/libgpu.h"

extern u16 g_pad1_buttons[];
extern s32 D_800EA760[];

void func_800133A0();
void func_800139F4(s32);
s32 play_sound(s32, s32, void*);
void func_8001D218();
void func_8001D25C(void);
void func_800E9864(u8* arg0);
void func_800E9958(s32);

#define F38 (*(s8*)&arg0[0x38])

void func_800E9A50(u8* arg0) {
    s8 old;
    s8 t;

    old = F38;
    if (g_pad1_buttons[2] & 0x8000) {
        F38 = 0;
    }
    if (g_pad1_buttons[2] & 0x2000) {
        F38 = 1;
    }
    if (old != F38) {
        s32* p;
        play_sound(5, 0, 0);
        p = D_800EA760;
        p[0] = 0;
        p[1] = 0;
    } else if (old == 0) {
        func_800E9864(0);
    } else {
        func_800E9958(old);
    }
    if (F38 == 0) {
        arg0[0x5F] = 1;
        arg0[0x5E] = 1;
    } else {
        arg0[0x5F] = 0x10;
        arg0[0x5E] = 5;
    }
    if (g_pad1_buttons[2] & 0x840) {
        arg0[1]++;
        func_800139F4(8);
        play_sound(5, 1, 0);
        t = F38;
        if (D_800EA760[t] == 0xB) {
            if (t == 0) {
                arg0[0x5F] = 8;
                arg0[0x5E] = 4;
                return;
            }
            arg0[0x5F] = 0x31;
        }
    } else if (g_pad1_buttons[2] & 0x10) {
        SetDispMask(0);
        func_8001D218();
        func_8001D25C();
        func_800133A0();
    }
}
#undef F38

#define func_8001D9CC func_800E9BDC
#define D_800710D0 D_800EA164
#include "../shared/save_file/func_8001D9CC.c"
#undef func_8001D9CC
#undef D_800710D0

// clang-format off
INCLUDE_ASM("asm/rock_19/nonmatchings/E9860", func_800E9C30);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002B36C(M2C_UNK);
void* alloc_sprite_slot();
#include "mmx6/state.h"

void func_800E9D54(u8* arg0) {
    s32 i;
    u8* p;
    u8* a;
    u8* self;

    self = arg0;
    if (D_80097420.transition.active != 0) {
        return;
    }
    a = arg0;
    i = 0;
    do {
        p = alloc_sprite_slot(a);
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x1C;
            p[2] = i;
        }
        i++;
        a = 0;
    } while (i < 2);
    self[2] = 0;
    self[1]++;
    func_8002B36C(0);
    *(s16*)(self + 4) = 2;
}

#include "common.h"

s32 func_8002B2F8(s32);
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800E9DEC(u8* arg0) {
    if (*(s16*)(arg0 + 4) != 0) {
        D_800CF854 = 0x1F;
        D_80097430 = 0x3E0;
        D_80090D5C = 0x7C00;
        *(s16*)(arg0 + 4) -= 1;
        return;
    }
    arg0[1]++;
    func_8002B2F8(0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001D218();
M2C_UNK reset_level();
extern struct X4_BackgroundObj background_objects[3];

void func_800E9E60(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        func_8001D218();
        {
            // !FAKE: retail keeps the background table base in the second return register
            register struct X4_BackgroundObj* bg asm("$3") = background_objects;
            bg[0].unk3 = 0;
            bg[1].unk3 = 0;
            bg[2].unk3 = 0;
        }
        reset_level();
        {
            s32 f = arg0[0x66];
            if (f == 0) {
                arg0[0xC] = 0;
                arg0[0xD] = 0;
                arg0[0x1D] = 0;
                arg0[0] = 7;
            }
        }
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
    }
}

#define func_80041AB8 func_800E9ED8
#define D_80075FD8 D_800EA218
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800EA1B0[];
extern u16 D_800EA1D0[][2];
extern u8 D_800EA1F0[];

#define SCR20 (*(s32**)0x1F800020)
#define F(T, o) (*(T*)((u8*)arg0 + (o)))

void func_800E9F14(void* arg0) {
    s32* p;
    s8 idx;
    s32 off;

    F(u16, 0x40) = 0x1880;
    p = SCR20;
    idx = F(s8, 0x2);
    off = *p;
    {
        void* t = D_800EA1B0;
        F(u16, 0x42) = 0x7800;
        F(void*, 0x30) = t;
    }
    F(u8, 0x15) = 0;
    F(s8, 0x14) = -1;
    F(s32, 0x3C) = (s32)p + off;
    F(u16, 0xA) = D_800EA1D0[idx][0];
    F(u16, 0xE) = D_800EA1D0[idx][1];
    set_animation(arg0, D_800EA1F0[idx]);
    {
        // !FAKE: test value in the first return register
        register s32 t asm("$2") = F(u8, 0x2);
        if ((u32)(t - 6) < 2) {
            F(u16, 0x42) = 0x7804;
        }
    }
    F(u8, 0x16) = 3;
    F(u8, 0x4) = F(u8, 0x4) + 1;
    F(u8, 0x5) = F(u8, 0x2);
    if (F(s8, 0x5) >= 2) {
        F(u8, 0x3) = 1;
    }
}
#undef SCR20
#undef F

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */
extern s8 D_800CCF08;

void func_800EA000(struct ObjectHeader* arg0) {
    if (D_800CCF08 == 0) {
        arg0->on_screen = 1;
    } else {
        arg0->on_screen = 0;
    }
    func_80017A04();
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern s8 D_800CCF08;

void func_800EA03C(s8* arg0) {
    s32 v = D_800CCF08;

    if (v == 1) {
        arg0[3] = v;
    } else {
        arg0[3] = 0;
    }
    func_80017A04();
}

#include "../shared/rock_19/func_800EA078.c"

#include "../shared/rock_19/func_800EA09C.c"

#define func_800EA078 func_800EA0C0
#include "../shared/rock_19/func_800EA078.c"
#undef func_800EA078

#define func_800EA09C func_800EA0E4
#include "../shared/rock_19/func_800EA09C.c"
#undef func_800EA09C

#define func_80041AB8 func_800EA108
#define D_80075FD8 D_800EA1F8
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

// clang-format off
INCLUDE_ASM("asm/rock_19/nonmatchings/E9860", func_800EA144);

INCLUDE_ASM("asm/rock_19/nonmatchings/E9860", func_800EA164);
// clang-format on
