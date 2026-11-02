#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800743DC;
extern struct X4_PlayerObj g_Player;
extern s32 D_800F6720;
extern s32 D_800F6724;
extern s32 D_800F6728;
extern s32 D_800F6A00;

void func_800E9B30(void* self) {
    u8 t;
    s32 v;

    M2C_FIELD(self, void**, 0x30) = &D_800F6A00;
    t = g_Player.bg_offset;
    M2C_FIELD(self, u8*, 0x16) = 5;
    M2C_FIELD(self, void**, 0x68) = &D_800F6720;
    M2C_FIELD(self, void**, 0x50) = &D_800F6724;
    M2C_FIELD(self, void**, 0x54) = &D_800F6728;
    M2C_FIELD(self, void**, 0x58) = &D_800743DC;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0x40000;
    M2C_FIELD(self, u8*, 0x5C) = 12;
    M2C_FIELD(self, u8*, 3) = 0;
    M2C_FIELD(self, u8*, 0x61) = 0;
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, u8*, 0x60) = 4;
    M2C_FIELD(self, u8*, 0x14) = t;
    switch (M2C_FIELD(self, s8*, 2)) {
    case 0:
        if (g_Player.unk2 == 0) {
            M2C_FIELD(self, u8*, 5) = 6;
        } else {
            M2C_FIELD(self, u8*, 5) = 4;
        }
        break;
    case 1:
        if (g_Player.unk2 == 0) {
            M2C_FIELD(self, u8*, 5) = 7;
        } else {
            M2C_FIELD(self, u8*, 5) = 5;
        }
        break;
    case 2:
        M2C_FIELD(self, u8*, 5) = 2;
        break;
    case 3:
        M2C_FIELD(self, u8*, 5) = 3;
        break;
    case 4:
        v = 2;
        goto common;
    case 5:
        v = 3;
    common:
        M2C_FIELD(self, u8*, 5) = v;
        M2C_FIELD(self, u8*, 7) = 0;
        M2C_FIELD(self, s32*, 0x68) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x2C) = 0;
        break;
    }
    M2C_FIELD(self, u8*, 6) = 0;
    M2C_FIELD(self, u8*, 4)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern M2C_UNK D_800F69F8;
extern M2C_UNK D_800F6A94;

void func_800E9C84(struct X4_BaseObj* self) {
    u8 flags;
    s8* p;

    if (check_enemy_hits(self) < 0) {
        goto die;
    }
    flags = M2C_FIELD(self, u8*, 0x70);
    if ((flags & 0xC) == 0xC || (flags & 3) == 3) {
        func_80049E50(self);
        func_800477E4(5, &D_800F69F8, self);
        goto set2;
    }
    func_80030ECC(self);
    if ((u8)(M2C_FIELD(self, u8*, 2) - 4) < 2) {
        func_8002CCB0(self, 0x40, 0x30);
        p = M2C_FIELD(self, s8**, 0x80);
        if (p[4] == 4 && self->unk7 == 0) {
        die:
            func_80049E50(self);
            func_800477E4(5, &D_800F69F8, self);
            func_8004E654(self, 0x11);
        set2: {
            // !FAKE: depin: dropping it breaks the match (91/94)
            register s32 st asm("$3") = 2;
            self->state = st;
        }
            return;
        }
        if (p[4] == 2) {
            self->unk7 = 1;
            M2C_FIELD(self, u8*, 2) -= 2;
        }
    } else {
        if (func_8002CBFC(self, 0x40, 0x30) != 0) {
            self->state = 3;
            return;
        }
        func_8002CCB0(self, 0x40, 0x30);
    }
    func_8002D230(self);
    func_80017A04(self);
    {
        // !FAKE: depin: dropping it breaks the match (88/94)
        register s32* tbl asm("$2") = &D_800F6A94;
        // !FAKE: depin: dropping it breaks the match (92/94)
        register void* fn asm("$5") = ((void**)tbl)[self->unk5];
        ((void (*)(struct X4_BaseObj*))fn)(self);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800E9DFC);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj g_Player;
extern s32 D_800F6720;

#define S_ID(s) M2C_FIELD(s, u8*, 0x0)
#define S_2(s) M2C_FIELD(s, s8*, 0x2)
#define S_STATE(s) M2C_FIELD(s, s8*, 0x6)
#define S_7(s) M2C_FIELD(s, s8*, 0x7)
#define S_X(s) M2C_FIELD(s, s16*, 0xA)
#define S_Y(s) M2C_FIELD(s, s16*, 0xE)
#define S_FACE(s) M2C_FIELD(s, u8*, 0x15)
#define S_46(s) M2C_FIELD(s, s8*, 0x46)
#define S_TIMER(s) M2C_FIELD(s, s16*, 0x7C)

#define ABS(v) ((v) < 0 ? -(v) : (v))

void func_800EA048(void* self) {
    void* parent;
    void* p;

    parent = M2C_FIELD(self, void**, 0x80);
    if (S_2(self) == 5 && S_7(self) == 0 &&
        (S_Y(self) = S_Y(parent) - 0x27) > 0x520 && S_STATE(parent) == 6) {
        M2C_FIELD(self, void**, 0x68) = &D_800F6720;
    }

    if (g_Player.x_pos.i.hi > S_X(self)) {
        S_FACE(self) = 0x40;
    } else {
        S_FACE(self) = 0;
    }
    S_TIMER(self)++;
    switch (S_STATE(self)) {
    case 0:
        ((void (*)(void*, s32))set_animation)(self, 3);
        S_TIMER(self) = 0;
        S_STATE(self)++;
        break;
    case 1:
        if (ABS(g_Player.x_pos.i.hi - S_X(self)) < 0xB5) {
            goto attack;
        } else if (S_TIMER(self) % 200 == 0) {
            ((void (*)(void*, s32))set_animation)(self, 4);
            S_STATE(self)++;
        }
        break;
    case 2:
        if (ABS(g_Player.x_pos.i.hi - S_X(self)) < 0xB5) {
        attack:
            set_animation(self, 5);
            S_TIMER(self) = 0;
            S_STATE(self) = 3;
        } else if (S_46(self) == 0) {
            S_STATE(self) = 0;
        }
        break;
    case 3:
        if (S_TIMER(self) == 0xC) {
            p = func_8002C458();
            if (p != NULL) {
                u8 id = S_ID(self);
                M2C_FIELD(p, u8*, 1) = 5;
                M2C_FIELD(p, u8*, 2) = 2;
                M2C_FIELD(p, void**, 0x7C) = self;
                M2C_FIELD(p, u8*, 0) = id;
            }
        } else if (S_TIMER(self) == 0x5A) {
            S_STATE(self) = 0;
        }
        break;
    }
}

#include "../shared/rock_04/func_800EA2A8.c"

#define func_800ED14C func_800EA60C
#include "../shared/rock_22/func_800ED14C.c"
#undef func_800ED14C

#include "../shared/rock_04/func_800EA970.c"

#include "../shared/rock_04/func_800EAC6C.c"

#include "../shared/rock_04/func_800EAF68.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F6AB8;
extern s32 D_800F6ABC;

void func_800EB110(void* self) {
    void* parent;

    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, s16*, 0x42) = M2C_FIELD(parent, s16*, 0x42) & 0x7FFF;
    M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(parent, u8*, 0x14);
    M2C_FIELD(self, u8*, 0x16) = 4;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, u8*, 0x3) = 0;
    M2C_FIELD(self, s32*, 0x68) = 0;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, s32*, 0x58) = 0;
    M2C_FIELD(self, u8*, 0x15) = M2C_FIELD(parent, u8*, 0x15);
    if (M2C_FIELD(parent, s8*, 0x2) == 0) {
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) - 0x29;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(parent, s16*, 0xE) + 6;
            set_animation(self, 0xF);
            {
                // !FAKE: depin: dropping it breaks the match (37/99)
                register s32 a asm("$2") = (s32)&D_800F6AB8;
                M2C_FIELD(self, s32*, 0x50) = a;
            }
        } else {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) + 0x24;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(parent, s16*, 0xE) - 0x11;
            set_animation(self, 0x1E);
            {
                // !FAKE: depin: dropping it breaks the match (48/99)
                register s32 a asm("$2") = (s32)&D_800F6ABC;
                M2C_FIELD(self, s32*, 0x50) = a;
            }
        }
    } else {
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) - 0x24;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(parent, s16*, 0xE) - 0x11;
            set_animation(self, 0x1E);
            {
                // !FAKE: depin: dropping it breaks the match (62/99)
                register s32 a asm("$2") = (s32)&D_800F6ABC;
                M2C_FIELD(self, s32*, 0x50) = a;
            }
        } else {
            M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) + 0x29;
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(parent, s16*, 0xE) + 6;
            set_animation(self, 0xF);
            {
                // !FAKE: depin: dropping it breaks the match (38/99)
                register s32 a asm("$2") = (s32)&D_800F6AB8;
                M2C_FIELD(self, s32*, 0x50) = a;
            }
        }
    }
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, u8*, 0x5C) = 1;
    M2C_FIELD(self, u8*, 0x60) = 4;
    play_sound(2, 0x10, self);
    M2C_FIELD(self, u8*, 0x6) = 0;
    M2C_FIELD(self, u8*, 0x5) = 0;
    M2C_FIELD(self, u8*, 0x4)++;
}

#include "../shared/rock_04/func_800EB29C.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800743DC;
extern s16 D_800970AA;
extern s32 D_800F6AC0;
extern s32 D_800F6AC4;
extern s32 D_800F6AC8;

void func_800EB3C8(void* self) {
    void* parent;
    void* p2;
    s32 d;
    u8 t;

    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    t = M2C_FIELD(parent, u8*, 0x14);
    M2C_FIELD(self, u8*, 0x16) = 4;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, void**, 0x68) = &D_800F6AC0;
    M2C_FIELD(self, void**, 0x50) = &D_800F6AC4;
    M2C_FIELD(self, u8*, 3) = 0;
    M2C_FIELD(self, void**, 0x54) = &D_800F6AC8;
    M2C_FIELD(self, void**, 0x58) = &D_800743DC;
    M2C_FIELD(self, u8*, 0x14) = t;
    set_animation(self, 0x12);
    p2 = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, u8*, 0x15) = M2C_FIELD(p2, u8*, 0x15);
    if (M2C_FIELD(self, u8*, 0x15) == 0) {
        if (M2C_FIELD(p2, s8*, 5) == 3) {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA) - 12;
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 12;
        } else if (M2C_FIELD(p2, s8*, 5) == 6) {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA) - 16;
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 12;
        } else {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA);
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 14;
        }
    } else {
        if (M2C_FIELD(p2, s8*, 5) == 3) {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA) + 12;
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 12;
        } else if (M2C_FIELD(p2, s8*, 5) == 6) {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA);
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 14;
        } else {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p2, u16*, 0xA) + 16;
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(p2, u16*, 0xE) - 12;
        }
    }
    d = (D_800970AA - M2C_FIELD(self, s16*, 0xA)) << 16;
    M2C_FIELD(self, s32*, 0x24) = 0x30000;
    M2C_FIELD(self, s32*, 0x2C) = 0x1800;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, u8*, 0x5C) = 2;
    M2C_FIELD(self, u8*, 0x60) = 3;
    M2C_FIELD(self, s32*, 0x20) = d / 70;
    play_sound(2, 0xF, self);
    M2C_FIELD(self, u8*, 6) = 0;
    M2C_FIELD(self, u8*, 5) = 0;
    M2C_FIELD(self, u8*, 4)++;
}

#include "../shared/rock_04/func_800EB5A0.c"

#include "common.h"

void func_800EB600(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EB608(void* arg0) {
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 4) < 2U) {
        clear_object_slot();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 4) == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002EE10(void*);

extern void (*D_800F6ACC[])(void*);
extern void (*D_800F6AD8[])(void*);
extern void (*D_800F6AE4[])(void*);

void func_800EB670(u8* self) {
    if (*(s32*)(self + 0x84) == 0 && self[0x70] == 0) {
        func_8002EE10(self);
    }
    self[3] = 0;
    switch ((s8)self[2]) {
    case 0:
        D_800F6ACC[(s8)self[4]](self);
        break;
    case 1:
        D_800F6AD8[(s8)self[4]](self);
        break;
    case 2:
        D_800F6AE4[(s8)self[4]](self);
        break;
    }
}

#include "../shared/rock_04/func_800EB750.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB820(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB840(void) {
    clear_object_slot();
}

#include "../shared/rock_04/func_800EB860.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB94C(void) {
    clear_object_slot();
}

#define func_800ECAB8 func_800EB96C
#define D_800C1220 D_800C1220
#include "../shared/rock_06/func_800ECAB8.c"
#undef func_800ECAB8
#undef D_800C1220

// clang-format off
INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800EBAA0);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CB50();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK collide_solid_object();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
s32 func_80032B34(struct X4_PlayerObj*);
void func_80032BE8(struct X4_PlayerObj*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F6B8C;
extern void (*D_800F6BD8[])(s8*);
extern M2C_UNK D_800F76EC;

void func_800EBF18(s8* arg0) {
    s8* s2;
    s32 d;

    s2 = M2C_FIELD(arg0, s8**, 0x7C);
    D_800F6BD8[arg0[6]](arg0);
    if (arg0[6] == 4 || arg0[6] >= 8) {
        arg0[3] = 0;
        return;
    }
    if (arg0[6] == 5) {
        arg0[3] ^= 1;
        return;
    }
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    func_80032B34((struct X4_PlayerObj*)arg0);
    if (func_8002CBFC(arg0, 0x80, 0x80) == 0) {
        func_8002CB50(arg0);
    }
    if (arg0[2] == 0xC) {
        func_80031F4C((struct X4_PlayerObj*)arg0);
    }
    func_80032BE8((struct X4_PlayerObj*)arg0);
    func_8003208C(arg0);
    {
        struct X4_PlayerObj* p = &g_Player;
        if (((u8*)p)[0xE5] == 0) {
            d = p->x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA);
            if (d >= 0) {
                if (d < 0x30) {
                    goto call;
                }
            } else if (M2C_FIELD(arg0, s16*, 0xA) - p->x_pos.i.hi < 0x30) {
            call:
                collide_solid_object(arg0);
            }
        }
    }
    if (arg0[2] == 0xA) {
        if (s2[7] == 4) {
            func_800477E4(2, &D_800F6B8C, arg0);
            clear_object_slot(arg0);
            return;
        }
        if (arg0[0x72] & 4) {
            __builtin_memcpy(&D_800F76EC, (s32*)&g_Player, 0x154);
            ((void (*)(M2C_UNK*))func_8002F288)(&D_800F76EC);
            if (((u8*)&D_800F76EC)[0x70] & 8) {
                s2[7] = 4;
            }
        }
    } else if ((arg0[0x72] & 4) && arg0[6] == 6) {
        __builtin_memcpy(&D_800F76EC, (s32*)&g_Player, 0x154);
        ((void (*)(M2C_UNK*))func_8002F288)(&D_800F76EC);
        if (((u8*)&D_800F76EC)[0x70] & 8) {
            func_800477E4(3, &D_800F6B8C, arg0);
            s2[7]--;
            {
                u8* q = (u8*)s2 + 0x86;
                q += arg0[7];
                *q -= 1;
            }
            arg0[4] = 4;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
M2C_UNK func_8002F288(M2C_UNK*);
s32 func_800EB96C(struct X4_PlayerObj*, s16, s16);

#define F_6(p) M2C_FIELD(p, u8*, 0x6)
#define F_8(p) M2C_FIELD(p, s16*, 0x8)
#define F_A(p) M2C_FIELD(p, s16*, 0xA)
#define F_E(p) M2C_FIELD(p, s16*, 0xE)
#define F_20(p) M2C_FIELD(p, s32*, 0x20)
#define F_24(p) M2C_FIELD(p, s32*, 0x24)
#define F_70(p) M2C_FIELD(p, u8*, 0x70)
#define F_80(p) M2C_FIELD(p, s8*, 0x80)
#define F_81(p) M2C_FIELD(p, s8*, 0x81)
#define F_82(p) M2C_FIELD(p, u8*, 0x82)
#define F_83(p) M2C_FIELD(p, u8*, 0x83)

#define RX(p) (F_A(p) + F_80(p) + F_82(p))
#define LX(p) (F_A(p) + F_80(p) - F_82(p))
#define FY(p) (F_E(p) + F_81(p) + F_83(p))

void func_800EC1DC(void* arg0) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 vx;
    s16 t;

    ((void (*)(void))move_object)();
    ((void (*)(void*))func_8002F288)(arg0);
    a = func_800EB96C(arg0, (t = RX(arg0), t - 1), FY(arg0));
    b = func_800EB96C(arg0, (t = LX(arg0), t + 1), FY(arg0));
    c = func_800EB96C(arg0, RX(arg0), F_E(arg0) + 0x10);
    d = func_800EB96C(arg0, (t = LX(arg0), t - 1), F_E(arg0) + 0x10);
    e = func_800EB96C(arg0, RX(arg0), F_E(arg0));
    f = func_800EB96C(arg0, (t = LX(arg0), t - 1), F_E(arg0));
    vx = F_20(arg0);
    if ((vx > 0 && (c != 0 || (F_70(arg0) & 1))) ||
        (vx < 0 && (d != 0 || (F_70(arg0) & 2))) ||
        (vx > 0 && (e != 0 || (F_70(arg0) & 1))) ||
        (vx < 0 && (f != 0 || (F_70(arg0) & 2)))) {
        F_20(arg0) = 0;
        F_6(arg0) = 7;
        F_A(arg0) = (F_A(arg0) & 0xFFF0) | 8;
    } else if (a == 0 && b == 0 && !(F_70(arg0) & 8)) {
        F_8(arg0) = 0;
        F_20(arg0) = 0;
        F_24(arg0) = 0xFFFF0000;
        F_6(arg0) = 6;
        F_A(arg0) = (F_A(arg0) & 0xFFF0) | 8;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_80030CCC(void*, s32, s32, s16);
extern s8 D_80097244;
extern u8 D_800F6C00[];
extern void* D_800F6C08;

void func_800EC4DC(void* arg0) {
    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (77/83)
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 0x84) + 1;
        M2C_FIELD(arg0, u8*, 0x84) = t;
        if ((u8)t == 0x20) {
            if (M2C_FIELD(arg0, s8*, 2) == 0xB) {
                if (!(((s32(*)())func_80030CCC)(
                          arg0, M2C_FIELD(arg0, s16*, 0xA),
                          M2C_FIELD(arg0, s16*, 0xE) - 0x1A) &
                      0xFF)) {
                    set_animation(arg0, 2);
                } else {
                    set_animation(arg0, 3);
                }
            } else {
                set_animation(arg0, 2);
            }
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        if (M2C_FIELD(arg0, s8*, 2) == 0xB) {
            if (!(((s32(*)())func_80030CCC)(arg0, M2C_FIELD(arg0, s16*, 0xA),
                                            M2C_FIELD(arg0, s16*, 0xE) - 0x1A) &
                  0xFF)) {
                func_80027BA0(0, M2C_FIELD(arg0, s16*, 0xA) - 0x18,
                              M2C_FIELD(arg0, s16*, 0xE) - 0x20, D_800F6C00);
            } else {
                func_80027BA0(0, M2C_FIELD(arg0, s16*, 0xA) - 0x18,
                              M2C_FIELD(arg0, s16*, 0xE) - 0x18,
                              (u8*)&D_800F6C08);
            }
        } else {
            func_80027BA0(0, M2C_FIELD(arg0, s16*, 0xA) - 0x18,
                          M2C_FIELD(arg0, s16*, 0xE) - 0x20, D_800F6C00);
        }
        D_80097244 = 1;
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK move_object(void*);
M2C_UNK func_8002F288(M2C_UNK*);
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
s32 func_800EB96C(struct X4_PlayerObj*, s16, s16);

void func_800EC628(void* arg0) {
    s32 a;
    s32 b;

    ((void (*)(void*))move_object)(arg0);
    if (FX(arg0, s16, 0xE) >= 0x510) {
        ((void (*)(void*))func_8002F288)(arg0);
        {
            s16 hx =
                FX(arg0, u8, 0x82) + (FX(arg0, s16, 0xA) + FX(arg0, s8, 0x80));
            s16 hy =
                FX(arg0, u8, 0x83) + (FX(arg0, s16, 0xE) + FX(arg0, s8, 0x81));
            a = func_800EB96C(arg0, hx - 1, hy - 1);
        }
        {
            s16 hx =
                FX(arg0, s16, 0xA) + FX(arg0, s8, 0x80) - FX(arg0, u8, 0x82);
            s16 hy =
                FX(arg0, u8, 0x83) + (FX(arg0, s16, 0xE) + FX(arg0, s8, 0x81));
            b = func_800EB96C(arg0, hx, hy - 1);
        }
        if (((u8(*)(void*, s32, s16))func_80030234)(
                arg0, FX(arg0, s16, 0xA) - 0x20, FX(arg0, s16, 0xE)) != 0 &&
            ((u8(*)(void*, s32, s16))func_80030234)(
                arg0, FX(arg0, s16, 0xA) + 0x20, FX(arg0, s16, 0xE)) != 0) {
            FX(arg0, s8, 0x60) = 0x7F;
        }
        if (a != 0 || b != 0) {
            FX(arg0, s32, 0xC) = FX(arg0, s32, 0x1C);
            return;
        }
        if (FX(arg0, u8, 0x70) & 8) {
            FX(arg0, s8, 0x6) = 7;
            FX(arg0, s16, 0xC) = 0;
            FX(arg0, s16, 0x8) = 0;
            FX(arg0, s32, 0x20) = 0;
            FX(arg0, s32, 0x24) = 0;
            FX(arg0, u16, 0xE) = (FX(arg0, u16, 0xE) & 0xFFF0) | 8;
            if (FX(arg0, s8, 0x3) != 0) {
                play_sound(2, 0x11, arg0);
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002BFD0(void*, s32);
s32 random_byte();
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800CCF38;

void func_800EC7DC(struct X4_PlayerObj* arg0) {
    s32 m;
    u8 idx;
    s16 y;
    s32 i;
    u8* tbl;
    u8* p;
    u8* q;
    struct X4_PlayerObj* obj;

    m = 0x80;
    if (D_800CCF38 >= 2) {
        m = 0x40;
    }
    idx = (u32)random_byte() % 6;
    if (arg0->x_pos.i.hi < 0x14C0) {
        if ((M2C_FIELD(arg0, u8*, 0x84) % m) == 0 && arg0->unk7 < 0x12) {
            y = idx * 0x30 + 0x1398;
            p = (u8*)arg0 + 0x86;
            {
                // !FAKE: depin: dropping it breaks the match (265/269)
                register s32 k asm("$2") = 3;
                if (p[idx] == k) {
                    idx++;
                    idx %= 6;
                    for (i = 0; i < 5; i++) {
                        y = idx * 0x30 + 0x1398;
                        q = (u8*)arg0 + 0x86;
                        if (q[idx] == 3) {
                            idx++;
                            idx %= 6;
                        } else {
                            i = 5;
                        }
                    }
                }
                tbl = (u8*)arg0 + 0x86;
            }
            obj = func_8002BFD0(arg0, 0);
            if (obj != 0) {
                obj->active = 0x41;
                obj->id = 7;
                obj->unk2 = 0xC;
                obj->unk40 = arg0->unk40;
                obj->animation_table = arg0->animation_table;
                obj->unk3C = arg0->unk3C;
                obj->unk42 = arg0->unk42;
                obj->x_pos.i.hi = y;
                obj->y_pos.i.hi = 0x4E0;
                obj->unk7 = idx;
                M2C_FIELD(obj, void**, 0x7C) = arg0;
            }
            tbl[idx]++;
            arg0->unk7++;
        }
        if (g_Player.x_pos.i.hi > 0x14A0 &&
            background_objects[0].unk24 == 0x1370) {
            background_objects[0].unk24 = 0x14D0;
            background_objects[0].unk26 = 0x14D0;
            arg0->state = 2;
        }
    } else {
        if ((M2C_FIELD(arg0, u8*, 0x84) % m) == 0 && arg0->unk7 < 0x18) {
            y = idx * 0x30 + 0x14F8;
            p = (u8*)arg0 + 0x86;
            {
                // !FAKE: depin: dropping it breaks the match (265/269)
                register s32 k asm("$2") = 4;
                if (p[idx] == k) {
                    idx++;
                    idx %= 6;
                    for (i = 0; i < 5; i++) {
                        y = idx * 0x30 + 0x14F8;
                        q = (u8*)arg0 + 0x86;
                        if (q[idx] == 4) {
                            idx++;
                            idx %= 6;
                        } else {
                            i = 5;
                        }
                    }
                }
                tbl = (u8*)arg0 + 0x86;
            }
            obj = func_8002BFD0(arg0, 0);
            if (obj != 0) {
                obj->active = 0x41;
                obj->id = 7;
                obj->unk2 = 0xC;
                obj->unk40 = arg0->unk40;
                obj->animation_table = arg0->animation_table;
                obj->unk3C = arg0->unk3C;
                obj->unk42 = arg0->unk42;
                obj->x_pos.i.hi = y;
                obj->y_pos.i.hi = 0x4E0;
                obj->unk7 = idx;
                M2C_FIELD(obj, void**, 0x7C) = arg0;
            }
            tbl[idx]++;
            arg0->unk7++;
        }
        if (g_Player.x_pos.i.hi > 0x1600 &&
            background_objects[0].unk24 == 0x14D0) {
            background_objects[0].unk24 = 0x1650;
            background_objects[0].unk26 = 0x1650;
            arg0->state = 2;
        }
    }
    M2C_FIELD(arg0, u8*, 0x84)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* alloc_class4_slot();
M2C_UNK func_8002F288(M2C_UNK*);
extern s16 D_800F6C10[];

void func_800ECC10(void* arg0) {
    void* p;
    void* e;

    p = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(arg0, s8*, 7) == 4) {
        M2C_FIELD(p, u8*, 5)--;
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0xE) > 0x170) {
        ((void (*)(void*))func_8002F288)(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            if (M2C_FIELD(arg0, s8*, 3) != 0) {
                play_sound(2, 0x11, arg0);
            }
            M2C_FIELD(arg0, s8*, 7) = 1;
            M2C_FIELD(arg0, s32*, 0x68) = 0;
            e = alloc_class4_slot();
            if (e != 0) {
                M2C_FIELD(e, u8*, 0) = 0x41;
                M2C_FIELD(e, u8*, 1) = 7;
                M2C_FIELD(e, u8*, 2) = 0xB;
                M2C_FIELD(e, s16*, 0xA) =
                    M2C_FIELD(arg0, s16*, 0xA) +
                    D_800F6C10[M2C_FIELD(arg0, s8*, 2) - 1];
                M2C_FIELD(e, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
            }
            if ((u16)(M2C_FIELD(arg0, u16*, 0xE) - 0x3D1) < 0x2E ||
                (u16)(M2C_FIELD(arg0, u16*, 0xE) - 0x2E1) < 0x2E) {
                e = alloc_class4_slot();
                if (e != 0) {
                    M2C_FIELD(e, u8*, 0) = 0x41;
                    M2C_FIELD(e, u8*, 1) = 7;
                    M2C_FIELD(e, u8*, 2) = 0xB;
                    M2C_FIELD(e, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x90;
                    M2C_FIELD(e, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
                }
            }
            if ((u16)(M2C_FIELD(arg0, u16*, 0xE) - 0x341) < 0x2E ||
                (u16)(M2C_FIELD(arg0, u16*, 0xE) - 0x2B1) < 0x2E) {
                e = alloc_class4_slot();
                if (e != 0) {
                    M2C_FIELD(e, u8*, 0) = 0x41;
                    M2C_FIELD(e, u8*, 1) = 7;
                    M2C_FIELD(e, u8*, 2) = 0xB;
                    M2C_FIELD(e, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x90;
                    M2C_FIELD(e, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
                }
            }
            M2C_FIELD(arg0, s8*, 4) = 2;
        }
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_80097180;
extern s32 D_800F6B9C;

void func_800ECDE8(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    if (D_80097180 != 2) {
        ((void (**)(void*)) & D_800F6B9C)[M2C_FIELD(arg0, s8*, 4)](arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECE48(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ECE68(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(void*);                       /* extern */

void func_800ECE88(void* arg0) {
    void* temp_s0;

    temp_s0 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_s0, s16*, 0xE) != M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(temp_s0, s16*, 0xE) = (s16)(u16)M2C_FIELD(arg0, s16*, 0xE);
    }
    move_object(arg0);
    if (M2C_FIELD(temp_s0, s8*, 7) == 1) {
        M2C_FIELD(arg0, s8*, 6) = 2;
        M2C_FIELD(arg0, s16*, 0xC) = 0;
        M2C_FIELD(arg0, s16*, 8) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s16*, 0xE) =
            (s16)(((u16)M2C_FIELD(arg0, s16*, 0xE) & 0xFFF0) | 8);
        if (M2C_FIELD(arg0, s8*, 3) != 0) {
            func_8002943C(0x10, 3, 1);
        }
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();
extern s32 D_80075B9C;

void func_800ECF20(void* arg0) {
    void* temp_v0;

    temp_v0 = alloc_sprite_slot();
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, u8*, 0) = 0x41;
        M2C_FIELD(temp_v0, u8*, 1) = 9;
        M2C_FIELD(temp_v0, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(temp_v0, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(temp_v0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(temp_v0, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(temp_v0, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(temp_v0, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0, u16*, 8) = 0;
        M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(temp_v0, u16*, 0xC) = 0;
        M2C_FIELD(temp_v0, void**, 0x50) = arg0;
    }
    M2C_FIELD(arg0, void**, 0x58) = &D_80075B9C;
    M2C_FIELD(arg0, u8*, 0x16) = 7;
    M2C_FIELD(arg0, u8*, 0x84) = 0x1F;
    M2C_FIELD(arg0, u8*, 6) = 3;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80030CCC(void*, s32, s32, s16);

void func_800ECFE8(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    if (!(((s32(*)())func_80030CCC)(arg0, M2C_FIELD(arg0, s16*, 0xA),
                                    M2C_FIELD(arg0, s16*, 0xE)) &
          0xFF)) {
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        M2C_FIELD(arg0, u8*, 0x5C) = 0x20;
        M2C_FIELD(arg0, u8*, 0x6) = 5;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x4) = 2;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_80075B9C;
extern s32 D_800F6B90;
extern s32 D_800F6B94;

void func_800ED044(void* arg0) {
    M2C_FIELD(arg0, void**, 0x58) = &D_80075B9C;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F6B94;
    M2C_FIELD(arg0, void**, 0x68) = (s8*)arg0 + 0x80;
    __builtin_memcpy((s8*)arg0 + 0x80, &D_800F6B90, 4);
    M2C_FIELD(arg0, u8*, 0x6) = 2;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();
extern s32 D_80075B9C;

void func_800ED08C(void* arg0) {
    void* temp_v0;

    temp_v0 = alloc_sprite_slot();
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, u8*, 0) = 0x41;
        M2C_FIELD(temp_v0, u8*, 1) = 9;
        M2C_FIELD(temp_v0, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(temp_v0, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(temp_v0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(temp_v0, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(temp_v0, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(temp_v0, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0, u16*, 8) = 0;
        M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(temp_v0, u16*, 0xC) = 0;
        M2C_FIELD(temp_v0, void**, 0x50) = arg0;
    }
    M2C_FIELD(arg0, void**, 0x58) = &D_80075B9C;
    M2C_FIELD(arg0, u8*, 0x16) = 7;
    M2C_FIELD(arg0, u8*, 0x84) = 0;
    M2C_FIELD(arg0, u8*, 6) = 3;
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_800ED150(void* arg0) {
    struct X4_BackgroundObj* bg;
    // !FAKE: value lives in the first argument register as in the target
    register s32 v asm("$4");

    if (M2C_FIELD(arg0, s16*, 0xA) < 0x14C0) {
        if (g_Player.y_pos.i.hi >= 0x5C1 && g_Player.x_pos.i.hi >= 0x1411) {
            bg = background_objects;
            v = 0x1370;
            // !FAKE: shared store block as in the target
            goto store;
        }
    } else if (g_Player.y_pos.i.hi >= 0x5D1 && g_Player.x_pos.i.hi >= 0x14E1) {
        bg = background_objects;
        v = 0x14D0;
    store: {
        // !FAKE: the state constant loads before the stores as in the target
        register s32 n asm("$3") = 9;
        bg->unk26 = v;
        bg->unk24 = v;
        M2C_FIELD(arg0, u8*, 6) = n;
    }
    }
}

#define func_80048DC8 func_800ED1EC
#define D_80077BC0 D_800F6C1C
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);    /* extern */
M2C_UNK set_animation(void*, M2C_UNK);          /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800ED238(void* arg0) {
    void* temp_a2;

    temp_a2 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, u8*, 0x16) = 0;
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(temp_a2, u16*, 0x40);
    M2C_FIELD(arg0, s16*, 0x42) = M2C_FIELD(temp_a2, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(temp_a2, s32*, 0x30);
    M2C_FIELD(arg0, s32*, 0x3C) = M2C_FIELD(temp_a2, s32*, 0x3C);
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(temp_a2, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x14) = M2C_FIELD(temp_a2, u8*, 0x14);
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x10);
    if (M2C_FIELD(arg0, s8*, 3) != 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x15, arg0);
    }
    ((void (*)(void*, s32))set_animation)(arg0, 4);
    M2C_FIELD(arg0, u8*, 6) = 0x3C;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                        /* extern */
s32 func_8002CAB4(void*);                       /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800ED2F4(void* arg0) {
    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        if (M2C_FIELD(arg0, s8*, 6) != 0) {
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) - 1);
        } else {
            M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        }
    }
    if (func_8002CAB4(arg0) == 0) {
        func_8002CCB0(arg0, 0x30, 0x10);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ED384(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

u8 func_80030234(struct X4_PlayerObj*, s16, s16);
extern struct X4_PlayerObj g_Player;
extern void (*D_800F6C28[])(void*);

#define PL_104 M2C_FIELD(&g_Player, s32*, 0x104)
#define PL_13C M2C_FIELD(&g_Player, s32*, 0x13C)

#define LOWER(v, lo) ((v) > (lo) ? (v) : (lo))
#define UPPER(v, hi) ((v) < (hi) ? (v) : (hi))
#define ABS(v) ((v) < 0 ? -(v) : (v))

#define TILE(dy)                                                               \
    ({                                                                         \
        struct X4_PlayerObj* p_ = &g_Player;                                   \
        struct X4_Unk_unk68* u_ = p_->unk68;                                   \
        s16 y_ = u_->unk1 + (p_->y_pos.u.hi + u_->unk3) + (dy);                \
        s16 x_ = p_->x_pos.i.hi;                                               \
        u8 t_;                                                                 \
        if (u_ == NULL) {                                                      \
            t_ = 0;                                                            \
        } else {                                                               \
            t_ = func_80030234(p_, x_, y_);                                    \
        }                                                                      \
        t_;                                                                    \
    })

void func_800ED3A4(void* self) {
    s32 dx;
    s32 d;

    M2C_FIELD(self, u8*, 0x21) = M2C_FIELD(self, u8*, 0x20);
    M2C_FIELD(self, u8*, 0x20) = TILE(0);
    dx = g_Player.x_pos.val - PL_13C;
    if (g_Player.state == 1) {
    loop:
        switch (M2C_FIELD(self, u8*, 0x20)) {
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
            M2C_FIELD(self, s8*, 4) = 1;
            if (M2C_FIELD(self, u8*, 0x21) == 0x3C && g_Player.unk15 != 0 &&
                g_Player.unk5 != 0xC) {
                g_Player.x_pos.val = PL_13C;
            } else {
                g_Player.x_pos.val = PL_13C + LOWER(dx - 0x38000, -PL_104);
                g_Player.y_pos.val += ABS(LOWER(dx - 0x38000, -PL_104));
            }
            break;
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
            M2C_FIELD(self, s8*, 4) = 1;
            if (M2C_FIELD(self, u8*, 0x21) == 0x3C && g_Player.unk15 == 0 &&
                g_Player.unk5 != 0xC) {
                g_Player.x_pos.val = PL_13C;
            } else {
                d = dx + 0x38000;
                g_Player.x_pos.val = PL_13C + UPPER(d, PL_104);
                g_Player.y_pos.val += ABS(UPPER(d, PL_104));
            }
            break;
        case 0x19:
        case 0x1A:
            M2C_FIELD(self, s8*, 4) = 1;
            if (M2C_FIELD(self, u8*, 0x21) == 0x3C && g_Player.unk15 != 0 &&
                g_Player.unk5 != 0xC) {
                g_Player.x_pos.val = PL_13C;
            } else {
                g_Player.x_pos.val = PL_13C + LOWER(dx - 0x38000, -PL_104);
                g_Player.y_pos.val += ABS(LOWER(dx - 0x38000, -PL_104));
            }
            break;
        case 0x1B:
        case 0x1C:
            M2C_FIELD(self, s8*, 4) = 1;
            if (M2C_FIELD(self, u8*, 0x21) == 0x3C && g_Player.unk15 == 0 &&
                g_Player.unk5 != 0xC) {
                g_Player.x_pos.val = PL_13C;
            } else {
                d = dx + 0x38000;
                g_Player.x_pos.val = PL_13C + UPPER(d, PL_104);
                g_Player.y_pos.val += ABS(UPPER(d, PL_104));
            }
            break;
        case 0x10:
            M2C_FIELD(self, u8*, 0x20) = TILE(-0x10);
            goto loop;
        case 0:
            if (g_Player.unk88.bytes.collision_flags & 8) {
                goto call;
            }
            if (M2C_FIELD(self, s8*, 4) == 2) {
                D_800F6C28[M2C_FIELD(self, s8*, 4)](self);
            }
            M2C_FIELD(self, u8*, 0x1C) = g_Player.unk5;
            goto end;
        case 0x3C:
            goto call;
        default:
            M2C_FIELD(self, s8*, 4) = 1;
            M2C_FIELD(self, u8*, 0x1C) = g_Player.unk5;
            goto end;
        }
        M2C_FIELD(self, u8*, 0x20) = TILE(0);
        switch (M2C_FIELD(self, u8*, 0x20)) {
        case 0:
            if (M2C_FIELD(self, s8*, 4) != 2) {
                D_800F6C28[M2C_FIELD(self, s8*, 4)](self);
            }
            M2C_FIELD(self, u8*, 0x1C) = g_Player.unk5;
            break;
        default:
        call:
            D_800F6C28[M2C_FIELD(self, s8*, 4)](self);
            M2C_FIELD(self, u8*, 0x1C) = g_Player.unk5;
            break;
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x38:
            break;
        }
    }
end:
    if (g_Player.x_pos.val != PL_13C) {
        M2C_FIELD(self, u8*, 0x1E) = (g_Player.x_pos.val >= PL_13C) << 6;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800ED808);
// clang-format on

#define func_800F0CF4 func_800EDB68
#define g_Player g_Player
#include "../shared/rock_07/func_800F0CF4.c"
#undef func_800F0CF4
#undef g_Player

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EDF1C(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x1C) = 0;
    M2C_FIELD(arg0, s8*, 0x1E) = 0;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800C1220[];
extern u8 D_800F6C40[];

void func_800EDF3C(void* arg0) {
    u32 i;
    s8 z;

    if (g_Player.x_pos.i.hi >= 0x1741 && g_Player.y_pos.i.hi < 0x4DC) {
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s16*, 0x18) = 0;
        M2C_FIELD(arg0, s8*, 0x1A) = 0;
        M2C_FIELD(arg0, u8*, 4)++;
        func_80027BA0(0, 0x1740, 0x4F0, D_800F6C40);
        z = 0;
        background_objects[0].unk4C = 1;
        background_objects[0].unk28 = 0x430;
        background_objects[0].unk2A = 0x140;
        for (i = 0; i < 0x50; i++) {
            s8* p = (s8*)&D_800C1220[i * 41];
            if (p[1] == 7) {
                s8* q = p;
                s32 n = 0xA3;
                do {
                    *q++ = z;
                } while (n-- != 0);
            }
        }
    }
}

#include "../shared/rock_04/func_800EE038.c"

#include "../shared/rock_04/func_800EE208.c"

#include "../shared/rock_04/func_800EE258.c"

// clang-format off
INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800EE334);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCEED;
extern M2C_UNK D_800F6CE0;
extern void (*D_800F6CF4[])(void*);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EE5C4(void* arg0) {
    s8 t;

    W(arg0, 0x18) = W(arg0, 0x8);
    W(arg0, 0x1C) = W(arg0, 0xC);
    D_800F6CF4[SB(arg0, 5)](arg0);
    if (check_enemy_hits(arg0) < 0) {
        {
            u8* e = (u8*)&g_playthrough_state;
            if (SB(e, 0x27) == 0) {
                SB(e, 0x27) = 0x78;
            }
        }
        if ((u8)(UB(arg0, 2) - 4) < 2 || SB(arg0, 2) == 7) {
            func_8004E654(arg0, 0x15);
        }
        func_800477E4(3, &D_800F6CE0, arg0);
        goto set2;
    }
    func_80030ECC(arg0);
    t = SB(arg0, 2);
    if (t == 4) {
        if (H(arg0, 0xA) < D_800970AA - 0xF0) {
            goto set2;
        }
        if (D_800CCEED > 0) {
            SB(arg0, 4) = 2;
        }
    } else if (t == 5) {
        if (g_Player.x_pos.i.hi + 0xF0 < H(arg0, 0xA) ||
            (g_Player.y_pos.i.hi >= 0x211 && g_Player.x_pos.i.hi >= 0x13A1)) {
        set2:
            SB(arg0, 4) = 2;
        }
    } else if (t >= 6) {
        if (func_8002CBFC(arg0, 0xF0, 0x40) == 1) {
            SB(arg0, 4) = 2;
        }
        if (UB(arg0, 0x70) & 8) {
            SB(arg0, 0x67) = 0;
        } else if (W(arg0, 0x24) < 0) {
            SB(arg0, 0x67) = -1;
        } else {
            SB(arg0, 0x67) = 1;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230();
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern s32 D_800F6C50[];
extern s32 D_800F6C58[];
extern M2C_UNK D_800F6CE0;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EE78C(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (80/83)
    register s32 t asm("$2");

    if (H(arg0, 0x7C) != 0) {
        W(arg0, 0x54) = 0;
        W(arg0, 0x50) = 0;
        H(arg0, 0x7C)--;
        UB(arg0, 3) ^= 1;
        return;
    }
    if ((UB(arg0, 0x70) & 1) && W(arg0, 0x20) > 0) {
        goto hit;
    }
    if ((UB(arg0, 0x70) & 2) && W(arg0, 0x20) < 0) {
    hit:
        play_sound(2, 0x11, arg0);
        func_800477E4(3, &D_800F6CE0, arg0);
        {
            // !FAKE: depin: dropping it breaks the match (81/83)
            register s32 c asm("$2") = 2;
            UB(arg0, 4) = c;
        }
    }
    UB(arg0, 3) = 1;
    W(arg0, 0x54) = (s32)&D_800F6C58[UB(arg0, 0x80)];
    W(arg0, 0x50) = (s32)&D_800F6C50[UB(arg0, 0x80)];
    func_80017A04(arg0);
    func_8002D230(arg0);
    t = UB(arg0, 0x70);
    if (t & 8) {
        W(arg0, 0x24) = 0x21000;
        W(arg0, 0x2C) = 0x1080;
        func_8002943C(8, 2, 2);
        play_sound(2, 0x11, arg0);
    }
    func_8002F288(arg0);
}

#include "../shared/rock_04/func_800EE8D8.c"

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;
extern void (*D_800F6CE8[])(void*);

void func_800EED40(struct X4_PlayerObj* arg0) {
    if (g_Player.x_pos.i.hi >= 0x1241) {
        if (g_Player.y_pos.i.hi >= 0x4F1) {
            clear_object_slot();
        }
    }
    D_800F6CE8[arg0->state](arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EEDB8(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();    /* extern */
M2C_UNK move_object(void*); /* extern */

void func_800EEDD8(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = (u8)(M2C_FIELD(arg0, u8*, 7) + 1);
    func_80017A04();
    move_object(arg0);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern s32 D_800F6C50[];
extern s32 D_800F6C58[];

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EEE14(void* arg0) {
    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (31/35)
        register s32 t asm("$2") = H(arg0, 0x7C);
        if (t != 0) {
            W(arg0, 0x54) = 0;
            W(arg0, 0x50) = 0;
            H(arg0, 0x7C)--;
            UB(arg0, 3) ^= 1;
            return;
        }
    }
    UB(arg0, 5) = 1;
    UB(arg0, 3) = 1;
    W(arg0, 0x54) = (s32)&D_800F6C58[UB(arg0, 0x80)];
    W(arg0, 0x50) = (s32)&D_800F6C50[UB(arg0, 0x80)];
}

// clang-format off
INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800EEEA0);
// clang-format on

#include "../shared/rock_04/func_800EF160.c"

#define func_80041AB8 func_800EF594
#define D_80075FD8 D_800F6D5C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/rock_04/func_800EF5D0.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF698(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800EF6B8(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();    /* extern */
M2C_UNK move_object(void*); /* extern */

void func_800EF70C(s32 arg0) {
    func_80017A04();
    move_object(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800EF738);

INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800EFA20);
// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern s32 D_800F6D94;
extern s32 D_800F6DA0;

void func_800EFC58(void* arg0) {
    struct X4_PlayerObj* p;
    s32 ang;
    s32 face;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x2) == 0xB) {
            set_animation(arg0, 3);
        } else {
            set_animation(arg0, 1);
        }
        p = &g_Player;
        ang = ratan2(p->y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                     p->x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
        M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 6;
        M2C_FIELD(arg0, s32*, 0x24) = -rsin(ang) << 6;
        face = p->x_pos.val >= M2C_FIELD(arg0, s32*, 0x8);
        M2C_FIELD(arg0, void**, 0x54) = &D_800F6DA0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F6D94;
        M2C_FIELD(arg0, s8*, 0x5) = 2;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x15) = face << 6;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800EFD58);
// clang-format on

#include "../shared/rock_04/func_800EFDB4.c"

#include "../shared/rock_04/func_800EFE78.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EFEF0(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800EFF10(void) {
    ((M2C_UNK(*)())move_object)();
}

#define func_8003744C func_800EFF30
#define D_80073C1C D_800F6DE8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

extern s32 D_800F6D90;
extern s32 D_800F6D9C;

void func_800EFF6C(u8* arg0) {
    arg0[3] ^= 1;
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(s32**)(arg0 + 0x54) = &D_800F6D9C;
        *(s32**)(arg0 + 0x50) = &D_800F6D90;
        arg0[6]++;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFFB8(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_8002A47C(s32);
void* enemy_slot_alloc();
s32 random_byte();
extern s8 g_enemies[];
extern u32* D_80095098;
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AE;
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F6E08[];
extern u16 D_800F6E0C[];

void func_800EFFD8(struct X4_BaseObj* self) {
    s8* ent;
    s8* flag;
    s8* flags;
    s8* base;
    struct X4_PlayerObj* obj;
    s32 i;
    s32 n6;
    s32 n45;
    s32 a;
    s32 b;
    s16 x;
    s32 r;
    s32 q;
    s32 y;

    if (g_playthrough_state.checkpoint < 3) {
        n6 = 0;
        n45 = 0;
        flags = (s8*)self + 0x16;
        base = g_enemies;
        for (i = 0; i < 0x30; i++) {
            ent = base + i * 0x9C;
            if (ent[0] != 0 && ent[1] == 0x11) {
                if (ent[2] == 6 && ent[7] >= 7) {
                    n6 = (n6 + 1) & 0xFF;
                    if (self->unk5 == 0) {
                        play_sound(5, 9, 0);
                        func_80012D9C(5);
                        self->unk5 = 1;
                    }
                } else if ((u32)((u8)ent[2] - 4) < 2U) {
                    n45 = (n45 + 1) & 0xFF;
                    if (self->unk6 == 0) {
                        if (self->unk7 == 0) {
                            play_sound(5, 8, 0);
                            self->unk6 = 1;
                            self->unk7 = -0x10;
                        }
                    }
                }
            }
        }
        if (g_playthrough_state.checkpoint > 0) {
            if (D_800970AE > 0x270) {
                play_sound(5, 3, 0);
            }
            if (n6 == 0 && self->unk5 == 0) {
                play_sound(5, 3, 0);
                self->unk5 = 0;
            }
        }
        if (self->unk7 != 0) {
            self->unk7--;
        }
        if (n6 == 0 && self->unk6 == 0) {
            play_sound(5, 3, 0);
            self->unk5 = 0;
        } else if (n45 == 0 && self->unk5 == 0) {
            if (self->unk7 == 0) {
                play_sound(5, 3, 0);
                self->unk6 = 0;
            }
        }
        if (self->unk7 != 0) {
            self->unk7--;
        }
        for (i = 0; i < 0xF; i++) {
            if (flags[i] != 0) {
                continue;
            }
            x = g_Player.x_pos.i.hi;
            if (D_800F6E08[i * 4] < x && x < D_800F6E08[i * 4] + 0x60) {
                if (i == 12 && g_Player.y_pos.i.hi < 0x1C0) {
                    break;
                }
                if (i == 13 && g_Player.y_pos.i.hi < 0x2B0) {
                    break;
                }
                if (i == 14 && g_Player.y_pos.i.hi < 0x350) {
                    break;
                }
                if (i == 15 && g_Player.y_pos.i.hi < 0x3D0) {
                    break;
                }
                obj = enemy_slot_alloc();
                if (obj != NULL) {
                    obj->active = 0x41;
                    obj->id = 0x11;
                    obj->unk2 = ((u8*)D_800F6E08)[i * 8 + 6];
                    obj->unk40 = D_80095098[func_8002A47C(0x11)] >> 7;
                    a = func_8002A47C(obj->id);
                    b = func_8002A47C(obj->id);
                    obj->unk42 =
                        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
                    obj->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(obj->id)];
                    obj->x_pos.i.hi = M2C_FIELD(&D_800F6E08[i * 4], u16*, 2);
                    if (obj->unk2 == 2) {
                        play_sound(5, 9, 0);
                        ((void (*)(s32))func_80012D9C)(5);
                        M2C_FIELD(obj, s16*, 0x7E) = 0xB4;
                        q = random_byte();
                        obj->y_pos.i.hi =
                            D_800F6E0C[i * 4] + (r = (q & 0x1F) - 0x10);
                    } else if (obj->unk2 != 3) {
                        func_80012D9C(5);
                        play_sound(5, 8, 0);
                        M2C_FIELD(obj, s16*, 0x7E) = 0x168;
                        if (M2C_FIELD(self, s16*, 0x14) < 0x1E0) {
                            M2C_FIELD(self, s16*, 0x14) = 0x1E0;
                        }
                        q = random_byte();
                        y = D_800F6E0C[i * 4];
                        r = (q & 0x1F) - 0x10;
                        obj->y_pos.i.hi = y + r;
                    } else {
                        obj->y_pos.i.hi = D_800F6E0C[i * 4];
                    }
                }
                flags[i] = 1;
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F6DF4[];
extern void (*D_800F6DFC[])(void*);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F049C(void* arg0) {
    if (g_Player.x_pos.i.hi >= 0x12E1 && g_Player.y_pos.i.hi >= 0x4C1) {
        func_80027BA0(0, 0x1240, 0x420, D_800F6DF4);
        play_sound(5, 3, 0);
        clear_object_slot(arg0);
        return;
    }
    if (SH(arg0, 0x14) != 0) {
        if (!(SH(arg0, 0x14) & 1)) {
            background_objects[0].y_pos.i.hi += 3;
        } else {
            background_objects[0].y_pos.i.hi -= 3;
        }
        SH(arg0, 0x14)--;
    }
    D_800F6DFC[SB(arg0, 4)](arg0);
}

#include "../shared/rock_04/func_800F058C.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F05D0(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800F05F0
#define D_80075FD8 D_800F6E80
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/rock_04/func_800F062C.c"

#include "../shared/rock_04/func_800F0718.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800F0758(void) {
    func_8002CA14();
}

// clang-format off
INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800F0778);
// clang-format on

#define func_800EE70C func_800F08B8
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EE70C.c"
#undef func_800EE70C
#undef g_Player

#define func_800EE800 func_800F09AC
#define D_80097420 D_80097420
#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"
extern struct X4_EngineObj g_playthrough_state;

#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800F09AC(u8* arg0) {
    s32 a;
    s32 b;
    void* t;

    a = FU16(arg0, 0x80) + 1;
    b = FU16(arg0, 0x82) - 1;
    FU16(arg0, 0x80) = a;
    FU16(arg0, 0x82) = b;
    if (!(D_80097420.frame_counter & 1)) {
        g_Player.x_pos.i.hi = a;
    } else {
        g_Player.x_pos.i.hi = b;
    }
    if (D_80097420.transition.active == 0) {
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        g_Player.x_pos.i.hi = FU16(arg0, 0x84);
        t = *(void**)(arg0 + 0x88);
        g_playthrough_state.unk10 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk19 = 0;
        g_Player.unk68 = t;
    }
}
#undef func_800EE800
#undef D_80097420

#define func_800EE8C4 func_800F0A70
#define background_objects background_objects
#include "../shared/commander_yammark/func_800EE8C4.c"
#undef func_800EE8C4
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800F0B70);

INCLUDE_ASM("asm/rock_04/nonmatchings/E9860", func_800F0F64);
// clang-format on

#define func_800EA1D8 func_800F1070
#define D_800FAA64 D_800F6ED4
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#define func_800EEF10 func_800F10BC
#define D_800F7808 D_800F6EE4
#include "../shared/commander_yammark/func_800EEF10.c"
#undef func_800EEF10
#undef D_800F7808

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800F1138(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EEFCC func_800F1178
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EEFCC.c"
#undef func_800EEFCC
#undef g_Player

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;
extern s8 D_800CCEF6;

void func_800F11F0(void* arg0) {
    if ((D_800CCEF6 == 0) && (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA))) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800F123C(void* arg0) {
    if (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800F1278
#define D_80073C1C D_800F6EFC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800F12B4
#define D_80073C1C D_800F6F98
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EF144 func_800F12F0
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);
extern s16 D_800970AA;
extern s8 D_800CCEDF;

void func_800F12F0(void* arg0) {
    s32 temp_a0;
    s32 temp_a1;

    M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a1;
    } else {
        D_800970AA = temp_a0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1D) {
        func_800139F4(8);
        D_800CCEDF = M2C_FIELD(arg0, u8*, 2) | 0x40;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF144

#define func_800EF1E8 func_800F1394
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);
extern s16 D_800970AA;

void func_800F1394(void* arg0) {
    s32 temp_a0;
    s32 temp_a1;

    M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a1;
    } else {
        D_800970AA = temp_a0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1D) {
        func_800139F4(8);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF1E8

#define func_800EF27C func_800F1428
#define D_80097420 D_80097420
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

extern s16 D_800970AA;

void func_800F1428(void* arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg0, u16*, 0x80) - 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x82) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a2;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a1;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a2;
    } else {
        D_800970AA = temp_a1;
    }
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF27C
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F1490(void) {
    clear_object_slot();
}
