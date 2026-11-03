#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

void start_pad_vibration(s32);
s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);

#define UNK20(p) (*(s32*)((u8*)(p) + 0x20))

// 0x8004755C func_8004755C: state 2 of the D_800762C8 object: moves until a countdown or flag, then shakes the screen and changes state.
// basis: none
// callers: D_800762C8[2] in func_80047394
void func_8004755C(Probe800473EC* arg0) {
    if (D_800CCEF6 != 0) {
        s32 q;
        s32 v;

        func_80029478(0x3C, 2, 2);
        v = arg0->unk18;
        q = 0x500000 / (v < 0 ? -v : v);
        arg0->unk14 = 0x32;
        q -= (u16)arg0->unk16;
        arg0->unk16 = q;
        UNK20(arg0) = arg0->unk1C;
        play_sound(2, 0x23, 0);
        start_pad_vibration(5);
        {
            // !FAKE: depin: dropping it breaks the match (68/70)
            register s32 c asm("$2") = -0x10000;
            // !FAKE: depin: dropping it breaks the match (67/70)
            register s32 k asm("$3") = 5;

            arg0->unk18 = c;
            arg0->unk5 = k;
        }
        return;
    }
    arg0->unk1C += arg0->unk18;
    if (--arg0->unk16 == 0) {
        func_80029478(0x3C, 2, 2);
        arg0->unk5 = 4;
        play_sound(2, 0x23, 0);
        start_pad_vibration(5);
        {
            s32 t = arg0->unk1C;
            // !FAKE: depin: dropping it breaks the match (64/70)
            register s32 c asm("$2");

            c = -0x10000;
            arg0->unk18 = c;
            c = 0x28;
            arg0->unk14 = c;
            UNK20(arg0) = t;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

// 0x80047674 func_80047674: state 3 of the D_800762C8 object: moves for a countdown, then sets speed and state 1.
// basis: none
// callers: D_800762C8[3] in func_80047394
void func_80047674(u8* arg0) {
    u8* eng;
    s32 var_v0;
    s32 temp_v0;
    s32 sum;
    s32 add;

    eng = (u8*)&g_playthrough_state;
    eng[0x27] = 1;
    sum = *(s32*)(arg0 + 0x1C);
    add = *(s32*)(arg0 + 0x18);
    sum += add;
    temp_v0 = *(u16*)(arg0 + 0x16) - 1;
    *(u16*)(arg0 + 0x16) = temp_v0;
    *(s32*)(arg0 + 0x1C) = sum;
    if ((temp_v0 << 0x10) == 0) {
        var_v0 = eng[0x68] < 2U;
        if (var_v0 != 0) {
            var_v0 = 0x10000;
        } else {
            var_v0 = 0x14000;
        }
        *(s32*)(arg0 + 0x18) = var_v0;
        *(s16*)(arg0 + 0x14) = 0x32;
        arg0[5] = 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

// 0x800476E0 func_800476E0: state 4 of the D_800762C8 object: waits a countdown, then resets position and sets state 1.
// basis: none
// callers: D_800762C8[4] in func_80047394
void func_800476E0(u8* self) {
    if (--*(s16*)(self + 0x14) == 0) {
        {
            u8* e = (u8*)&g_playthrough_state;
            if (e[0x68] >= 2) {
                *(s32*)(self + 0x18) = 0xFFFEC000;
            } else {
                *(s32*)(self + 0x18) = 0xFFFF0000;
            }
            e = 0;
        }
        {
            s8* e = (s8*)&g_playthrough_state;
            if (e[0x1D] == 0) {
                *(u16*)(self + 0x14) = 0x78;
            } else {
                *(u16*)(self + 0x14) = 0x32;
            }
        }
        self[5] = 1;
        *(s32*)(self + 0x1C) = *(s32*)(self + 0x20);
    }
}

#include "common.h"
#include "mmx6/globals.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);

// 0x80047760 func_80047760: state 5 of the D_800762C8 object: waits a countdown, plays a sound, then sets state 3.
// basis: none
// callers: D_800762C8[5] in func_80047394
void func_80047760(u8* arg0) {
    if (--*(s16*)(arg0 + 0x14) == 0) {
        if (D_800CCF38 >= 2) {
            *(s32*)(arg0 + 0x18) = 0xFFFEC000;
        } else {
            *(s32*)(arg0 + 0x18) = 0xFFFF0000;
        }
        arg0[5] = 3;
        play_sound(2, 0x22, arg0);
        *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0x20);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();
s32 random_byte();

void func_800477E4(u8 count, u8* src, void* parent) {
    void* obj;
    s8 t;
    u8 b;

    while (count != 0) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            M2C_FIELD(obj, u8*, 0x0) = 0x41;
            t = M2C_FIELD(parent, s8*, 0x0);
            if (t == 0x61) {
                M2C_FIELD(obj, u8*, 0x0) = t;
                t = M2C_FIELD(parent, s8*, 0x0);
            }
            if (t == 0x21) {
                M2C_FIELD(obj, u8*, 0x0) = t;
            }
            {
                s32 x = M2C_FIELD(parent, u8*, 0x0);
                M2C_FIELD(obj, u8*, 0x1) = 3;
                M2C_FIELD(obj, u8*, 0x2) = 0;
                M2C_FIELD(obj, u8*, 0x0) |= x & 0x10;
            }
            M2C_FIELD(obj, u8*, 0x15) = random_byte() & 0x40;
            M2C_FIELD(obj, u8*, 0x4) = 0;
            M2C_FIELD(obj, u8*, 0x5) = 0;
            M2C_FIELD(obj, u8*, 0x6) = 0;
            M2C_FIELD(obj, s32*, 0x8) =
                M2C_FIELD(parent, s32*, 0x8) + ((random_byte() & 3) << 16);
            M2C_FIELD(obj, s32*, 0xC) =
                M2C_FIELD(parent, s32*, 0xC) + ((random_byte() & 3) << 16);
            b = *src++;
            M2C_FIELD(obj, void**, 0x54) = parent;
            M2C_FIELD(obj, u8*, 0x58) = b;
        }
        count--;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();
s32 random_byte();

void func_800478F0(u8 count, u8* src, void* parent, u16 kind, s32 arg4,
                   s32 arg5) {
    void* obj;
    s32 t;

    while (count != 0) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            M2C_FIELD(obj, u8*, 0x0) = 0x41;
            M2C_FIELD(obj, u8*, 0x1) = 3;
            M2C_FIELD(obj, u8*, 0x2) = 1;
            M2C_FIELD(obj, u8*, 0x15) = random_byte() & 0x40;
            M2C_FIELD(obj, u8*, 0x4) = 0;
            M2C_FIELD(obj, u8*, 0x5) = 0;
            M2C_FIELD(obj, u8*, 0x6) = 0;
            M2C_FIELD(obj, s32*, 0x8) =
                M2C_FIELD(parent, s32*, 0x8) + (random_byte() & 3) + arg4;
            M2C_FIELD(obj, s32*, 0xC) =
                M2C_FIELD(parent, s32*, 0xC) + (random_byte() & 3) + arg5;
            t = *src++;
            M2C_FIELD(obj, void**, 0x54) = parent;
            M2C_FIELD(obj, u16*, 0x42) = kind;
            M2C_FIELD(obj, u8*, 0x58) = t;
            M2C_FIELD(obj, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
            M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
            M2C_FIELD(obj, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
        }
        count--;
    }
}

#include "common.h"

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot(); /* extern */
s32 random_byte();         /* extern */

void func_80047A0C(s32 arg0, u8* arg1, void* arg2, s32 arg3, s32 arg4) {
    s32 var_s1;
    u8* var_s2;
    u8 temp_v0_2;
    void* temp_v0;

    var_s2 = arg1;
    var_s1 = arg0 & 0xFF;
    if (var_s1 != 0) {
        do {
            temp_v0 = alloc_sprite_slot();
            if (temp_v0 != NULL) {
                M2C_FIELD(temp_v0, s8*, 0) = 0x41;
                M2C_FIELD(temp_v0, s8*, 1) = 3;
                M2C_FIELD(temp_v0, s8*, 2) = 0;
                M2C_FIELD(temp_v0, s8*, 0x15) = (s8)(random_byte() & 0x40);
                M2C_FIELD(temp_v0, s8*, 4) = 0;
                M2C_FIELD(temp_v0, s8*, 5) = 0;
                M2C_FIELD(temp_v0, s8*, 6) = 0;
                M2C_FIELD(temp_v0, s32*, 8) = (s32)(M2C_FIELD(arg2, s32*, 8) +
                                                    (random_byte() & 3) + arg3);
                M2C_FIELD(temp_v0, s32*, 0xC) =
                    (s32)(M2C_FIELD(arg2, s32*, 0xC) + (random_byte() & 3) +
                          arg4);
                temp_v0_2 = *var_s2;
                var_s2 += 1;
                M2C_FIELD(temp_v0, void**, 0x54) = arg2;
                M2C_FIELD(temp_v0, u8*, 0x58) = temp_v0_2;
            }
            var_s1 = (var_s1 - 1) & 0xFF;
        } while (var_s1 != 0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80047B34();    /* extern */
M2C_UNK func_80047C30(); /* extern */

void func_80047AF4(struct ObjectHeader* arg0) {
    if (arg0->state == 0) {
        func_80047B34();
        return;
    }
    func_80047C30();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002CB50(struct X4_BaseObj*);
s32 random_byte();
extern s32 D_80077AE0[];
extern s32 D_80077B00[];

void func_80047B34(void* arg0) {
    void* parent;
    s32 t;
    // !FAKE: pin the flag byte in the first argument register
    register s32 b asm("$4");

    M2C_FIELD(arg0, s8*, 0x3) = 1;
    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        parent = M2C_FIELD(arg0, void**, 0x54);
        M2C_FIELD(arg0, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
        M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
        M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
        M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    }
    M2C_FIELD(arg0, u8*, 0x16) = 1;
    b = D_800970B4;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x5000;
    M2C_FIELD(arg0, u8*, 0x14) = b;
    M2C_FIELD(arg0, s32*, 0x20) =
        D_80077AE0[random_byte(b) & 7] +
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x54), s32*, 0x20) / 2;
    t = random_byte();
    t = D_80077B00[t & 7];
    M2C_FIELD(arg0, s32*, 0x24) = t;
    ((void (*)())set_animation)(arg0, M2C_FIELD(arg0, u8*, 0x58), t);
    M2C_FIELD(arg0, u8*, 0x4) += 1;
    func_8002CB50(arg0);
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/3CE30", func_80047C30);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* alloc_sprite_slot();
s32 random_byte();
extern u32* D_80095098;

void func_80047C98(u8 count, u8* src, void* parent, s32 kind, s32 arg4) {
    void* obj;
    s32 a;
    s32 b;
    u8 t;

    while (count != 0) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            M2C_FIELD(obj, u8*, 0x0) = 0x41;
            M2C_FIELD(obj, u8*, 0x1) = 3;
            M2C_FIELD(obj, u8*, 0x2) = 1;
            M2C_FIELD(obj, u8*, 0x15) = random_byte() & 0x40;
            M2C_FIELD(obj, u8*, 0x4) = 0;
            M2C_FIELD(obj, u8*, 0x5) = 0;
            M2C_FIELD(obj, u8*, 0x6) = 0;
            M2C_FIELD(obj, s32*, 0x8) =
                M2C_FIELD(parent, s32*, 0x8) + ((random_byte() & 3) << 16);
            M2C_FIELD(obj, s32*, 0xC) =
                M2C_FIELD(parent, s32*, 0xC) + ((random_byte() & 3) << 16);
            t = *src++;
            M2C_FIELD(obj, void**, 0x54) = parent;
            M2C_FIELD(obj, s32*, 0x30) = arg4;
            M2C_FIELD(obj, u8*, 0x58) = t;
            a = func_8002A47C(kind);
            b = func_8002A47C(kind);
            M2C_FIELD(obj, s16*, 0x42) =
                ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
            M2C_FIELD(obj, u16*, 0x40) = D_80095098[func_8002A47C(kind)] >> 7;
            M2C_FIELD(obj, s32*, 0x3C) =
                (s32)SCRATCH_20 + SCRATCH_20[func_8002A47C(kind)];
        }
        count--;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
M2C_UNK move_object(void*);
void set_velocity_from_angle(void*, s32);
extern s8 D_80077B20[];
extern struct X4_PlayerObj g_Player;

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

void func_80047E34(u8* arg0) {
    s32 vx;
    s32 vy;
    s32 anim;
    s8* tbl;
    u8* sp;
    s32 off;
    struct X4_PlayerObj* pl = &g_Player;

    F8(arg0, 3) = 1;
    U8(arg0, 0x14) = U8(pl, 0x14);
    F32(arg0, 0x38) = 0;
    sp = SCRATCH_1C;
    off = *(s32*)(sp + 4);
    FP(arg0, 0x30) = g_visual_animation_tables;
    F16(arg0, 0x40) = 0;
    F16(arg0, 0x42) = 0x7802;
    F8(arg0, 0x16) = 0x10;
    F8(arg0, 0x15) = 0;
    FP(arg0, 0x3C) = sp + off;
    F32(arg0, 8) = F32(pl, 8);
    F32(arg0, 0xC) = F32(pl, 0xC);
    set_velocity_from_angle(arg0, U8(arg0, 2) & 0x7F);
    vx = F32(arg0, 0x20);
    vy = F32(arg0, 0x24);
    anim = 7;
    if (F8(arg0, 2) & 0x80) {
        F32(arg0, 0x20) = vx * 8;
        F32(arg0, 0x24) = vy * 8;
    } else {
        s32 h;
        s32 m;
        h = vx / 2;
        m = D_80077B20[U8(arg0, 2) & 3];
        F32(arg0, 0x20) = vx + h * m;
        anim = 6;
        F32(arg0, 0x24) = vy + (vy / 2) * D_80077B20[U8(arg0, 2) & 3];
    }
    set_animation(arg0, anim);
    move_object(arg0);
    U8(arg0, 4) = U8(arg0, 4) + 1;
    func_8002CCB0(arg0, 0x80000, 0x80000);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80047E34(u8* arg0); /* extern */
M2C_UNK func_80047FB8();      /* extern */

void func_80047F78(struct ObjectHeader* arg0) {
    if (arg0->state == 0) {
        ((void (*)())func_80047E34)();
        return;
    }
    func_80047FB8();
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/3CE30", func_80047FB8);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
extern s32 D_80077B34[];
extern u8 D_80077B5C[];
extern u16 D_80077B64[];
extern u16 D_80077B70[];
extern u8 D_80077B7C[];
extern u16 D_800E4450[];

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define SCRATCH_28 (*(u8**)0x1F800028)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

void func_80048030(u8* arg0) {
    s32 idx;
    u8 v;
    u16* dst;
    u16* src;
    u32 i;

    if (D_800CCF08 == 0) {
        FP(arg0, 0x3C) = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x24);
    } else {
        FP(arg0, 0x3C) = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x10);
    }
    F16(arg0, 0x40) = 0x1D00;
    FP(arg0, 0x30) = D_80077B34;
    idx = F8(arg0, 2);
    F8(arg0, 4) = 1;
    F8(arg0, 0x14) = -1;
    v = D_80077B5C[idx];
    F16(arg0, 0x42) = (v & 0xF) | (((v >> 4) + 0x1E0) << 6);
    F16(arg0, 0xA) = D_80077B64[idx];
    F16(arg0, 0xE) = D_80077B70[idx];
    F8(arg0, 0x16) = D_80077B7C[idx];
    F8(arg0, 0x15) = 0;
    F32(arg0, 0x20) = 0;
    F32(arg0, 0x28) = 0;
    F32(arg0, 0x24) = 0;
    F32(arg0, 0x2C) = 0;
    F16(arg0, 0x54) = 0;
    F16(arg0, 0x56) = 0;
    F16(arg0, 0x58) = 0;
    F16(arg0, 0x5A) = 0;
    F16(arg0, 0x5C) = 0;
    if (idx < 2) {
        if (idx != 0) {
            dst = D_800E4450;
            src = (u16*)(SCRATCH_28 + 0x200);
            for (i = 0; i < 0x10; i++) {
                *dst++ = *src;
                if (i != 0) {
                    *src = 0x8000;
                } else {
                    *src = 0;
                }
                src++;
            }
            D_800C4560 |= 1;
        }
        set_animation(arg0, 0);
    } else {
        set_animation(arg0, idx - 1);
    }
}
#undef set_animation

#define func_80041AB8 func_800481D0
#define D_80075FD8 D_80077B84
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_8004820C
#define D_80075FD8 D_80077B90
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80048248(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80048584(void*, u8);
extern u8 D_80077B44[];

void func_80048268(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (55/70)
    register s32 t asm("$2");

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), u8*, 0x16) != 0) {
        func_80048584(arg0, 0);
        {
            s8 c = M2C_FIELD(arg0, s8*, 2);
            t = 1;
            M2C_FIELD(arg0, u8*, 5) = t;
            t = 8;
            M2C_FIELD(arg0, u16*, 0x54) = t;
            if (c != 0) {
                M2C_FIELD(arg0, s16*, 0x42) = 0x7840;
                M2C_FIELD(arg0, s32*, 0x20) = 0x4000;
                M2C_FIELD(arg0, s32*, 0x24) = -0x8000;
                return;
            }
        }
        M2C_FIELD(arg0, s32*, 0x20) = -0x4000;
        M2C_FIELD(arg0, s32*, 0x24) = 0x8000;
        play_sound(0, 0xA, 0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0 && M2C_FIELD(arg0, u16*, 0x5C) == 0) {
        t = M2C_FIELD(arg0, u16*, 0x54);
        if (t != 0) {
            M2C_FIELD(arg0, u16*, 0x54) = t - 1;
            return;
        }
        func_80048584(arg0, D_80077B44[M2C_FIELD(arg0, u16*, 0x58)]);
        {
            t = M2C_FIELD(arg0, u16*, 0x58);
            M2C_FIELD(arg0, u16*, 0x58) = ++t;
            if ((u16)t >= 0xE) {
                M2C_FIELD(arg0, u16*, 0x58) = 0;
                M2C_FIELD(arg0, u16*, 0x5C) = 1;
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK apply_object_motion();
extern s8 D_800CCEEE;
extern u16 D_800E4450[];

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_80048380(void* arg0) {
    s32 a;
    // !FAKE: depin: dropping it breaks the match (64/70)
    register s32 b asm("$3");

    if (F16(arg0, 0x56) != 0) {
        F16(arg0, 0x56)--;
        return;
    }
    if (--F16(arg0, 0x54) == 0) {
        if (F8(arg0, 6) == 0) {
            if (F8(arg0, 2) != 0) {
                a = -0x4000;
                b = 0x8000;
            } else {
                a = 0x4000;
                b = -0x8000;
            }
            do {
                F32(arg0, 0x20) = a;
                F32(arg0, 0x24) = b;
            } while (0);
            F8(arg0, 6) = 1;
            F16(arg0, 0x54) = 8;
            F16(arg0, 0x56) = 0x1E;
            return;
        }
        F8(arg0, 5) = 2;
        F8(arg0, 6) = 0;
        F16(arg0, 0x42) = 0x7801;
        if (F8(arg0, 2) != 0) {
            F32(arg0, 0x20) = 0xFFF00000;
            load_palette(0x10, (s32*)D_800E4450, 1);
        } else {
            F32(arg0, 0x20) = 0x100000;
        }
        F32(arg0, 0x24) = 0;
        F16(arg0, 0xA) = 0xA0;
        F16(arg0, 0xE) = 0x78;
        D_800CCEEE = 1;
        return;
    }
    apply_object_motion(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK apply_object_motion(); /* extern */

void func_80048498(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 3) != 0) {
        apply_object_motion();
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 2;
    M2C_FIELD(arg0, s8*, 5) = 0;
}

#include "../shared/SLUS_013.95/func_800484D8.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CB50(struct X4_BaseObj*); /* extern */
#include "mmx6/state.h"

void func_80048524(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    if (D_80097420.frame_counter & 0x10) {
        ((s32(*)())func_8002CB50)();
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CB50(struct X4_BaseObj*); /* extern */

void func_80048560(struct ObjectHeader* arg0) {
    arg0->on_screen = 1;
    ((s32(*)())func_8002CB50)();
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/3CE30", func_80048584);
// clang-format on

#include "common.h"

#define SCRATCH_1C (*(s32*)0x1F80001C)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800485BC(u8* arg0) {
    s32 u;

    if (F8(arg0, 4) == 0) {
        s32 t;

        F8(arg0, 3) = 1;
        F8(arg0, 0x14) = -1;
        F32(arg0, 0x38) = 0;
        u = F8(arg0, 2);
        t = SCRATCH_1C;
        F32(arg0, 0x30) = 0;
        F16(arg0, 0x40) = 0x1880;
        F32(arg0, 0x3C) = t;
        F16(arg0, 0x42) = (u == 0) ? 0x7804 : 0x7807;
        F8(arg0, 0x15) = 0;
        F8(arg0, 0x16) = 0;
        arg0[4]++;
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/3CE30", func_80048628);
// clang-format on

#define func_80046C64 func_80048980
#define D_800762A0 D_80077BB0
#include "../shared/d1000/func_80046C64.c"
#undef func_80046C64
#undef D_800762A0

#include "common.h"
#define M2C_UNK s32

s32 func_8002CB50(struct X4_BaseObj*); /* extern */

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define SCRATCH_3C (*(u8**)0x1F80003C)

void func_800489C0(void* arg0) {
    u8* p;

    F16(arg0, 0x40) = 0x1F00;
    p = SCRATCH_3C;
    p += *(s32*)(p + 4);
    F8(arg0, 0x14) = -1;
    F8(arg0, 0x15) = 0;
    F32(arg0, 0x3C) = (s32)p;
    if (F16(arg0, 0xE) == 0x10) {
        F16(arg0, 0xE) = 0x30;
        F16(arg0, 0x42) = 0x7C11;
    } else {
        F16(arg0, 0x42) = 0x7C10;
    }
    F8(arg0, 0x16) = 0;
    F8(arg0, 4) = F8(arg0, 4) + 1;
    F8(arg0, 0x47) = F8(arg0, 2);
    func_8002CB50(arg0);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80048A50(void* arg0) {
    s16 var_v0;

    if (M2C_FIELD(arg0, s16*, 0xE) != 0x30) {
        var_v0 = 0x7C10;
        if (M2C_FIELD(arg0, s8*, 7) == D_80097420.transition.selection) {
            var_v0 = 0x7C12;
        }
        M2C_FIELD(arg0, s16*, 0x42) = var_v0;
    }
    M2C_FIELD(arg0, s8*, 3) = 1;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50();
extern u16 D_800C4570;
extern M2C_UNK D_800CD3F8;

void func_80048A8C(void* arg0, s32 arg1, void* arg2) {
    if (M2C_FIELD(arg0, u8*, 0x55) == 0) {
        if (M2C_FIELD(arg0, s8*, 2) == -1 || (D_800C4570 & 0x10) ||
            ((D_800C4570 & 0x800) && M2C_FIELD(&D_800CD3F8, s8*, 0) == 0xA)) {
            M2C_FIELD(arg0, s8*, 2) = -1;
        }
        if (M2C_FIELD(arg0, s8*, 2) == -1 || (D_800C4570 & 0x10) ||
            ((D_800C4570 & 0x800) && M2C_FIELD(&D_800CD3F8, s8*, 0) == 8)) {
            M2C_FIELD(arg0, s8*, 2) = -1;
        }
    }
    if (M2C_FIELD(arg0, s8*, 2) != -1) {
        arg2 = (u8*)&D_80097420;
        if (M2C_FIELD(arg0, u8*, 0x54) != D_80097420.transition.selection) {
            M2C_FIELD(arg0, u16*, 0xE) =
                ((u8*)(D_80097420.transition.selection * 3 +
                       M2C_FIELD(arg0, s32*, 0x50)))[2];
            M2C_FIELD(arg0, u8*, 0x54) = D_80097420.transition.selection;
        }
    }
    ((M2C_UNK(*)())func_8002CB50)(arg0, arg0, arg2);
}

#define func_80046C64 func_80048B98
#define D_800762A0 D_80077BB8
#include "../shared/d1000/func_80046C64.c"
#undef func_80046C64
#undef D_800762A0

#include "common.h"

#define M2C_UNK s32
#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8F(p, o) (*(s8*)((u8*)(p) + (o)))
#define S16F(p, o) (*(s16*)((u8*)(p) + (o)))
#define S32F(p, o) (*(s32*)((u8*)(p) + (o)))
#define SCRATCH_3C (*(s32**)0x1F80003C)

s32 func_8002CB50(struct X4_BaseObj*); /* extern */

void func_80048BD8(void* arg0) {
    s32* t;
    s32 v;
    s32 x;

    S16F(arg0, 0x40) = 0x1E00;
    t = SCRATCH_3C;
    x = *t;
    S8F(arg0, 0x14) = -1;
    S16F(arg0, 0x42) = 0x7E11;
    S32F(arg0, 0x3C) = (s32)t + x;
    S16F(arg0, 0xE) =
        U8F(S32F(arg0, 0x50) + D_80097420.transition.selection * 3, 2);
    v = D_80097420.transition.selection;
    U8F(arg0, 0x16) = 0;
    U8F(arg0, 4) = U8F(arg0, 4) + 1;
    U8F(arg0, 0x47) = 0x47;
    U8F(arg0, 0x54) = v;
    ((s32(*)())func_8002CB50)(arg0, v);
}

#include "common.h"

#define FB_BASE ((s32*)0x801F3000)

void func_80048C68(u8* arg0) {
    s32 t;
    s32 v;

    t = *(s8*)(arg0 + 2);
    arg0[0] = 1;
    arg0[3] = 1;
    arg0[0x15] = 0;
    *(s8*)(arg0 + 0x14) = -1;
    switch (t) {
    case 0:
        arg0[0x16] = 2;
        *(s32*)(arg0 + 0x3C) = FB_BASE[2] + (s32)FB_BASE;
        {
            s32 r = *(s8*)(arg0 + 0x56);
            *(s16*)(arg0 + 0x40) = 0x1E00;
            v = ((r + 8) % 4 + 0x10) | (((r + 8) / 4 + 0x1F0) << 6);
        }
        break;
    case 1: {
        s8 n1;
        arg0[0x16] = 2;
        *(s32*)(arg0 + 0x3C) = FB_BASE[0] + (s32)FB_BASE;
        n1 = *(s8*)(arg0 + 0x56);
        *(s16*)(arg0 + 0x40) = 0x1F00;
        v = ((s8)(n1 % 4) + 0x10) | ((n1 / 4 + 0x1F0) << 6);
    } break;
    case 2:
        // !FAKE: goto from case 2 shapes the case tree (C0176); merged case 2/3 labels moved bytes
        goto arm23;
    case 3:
    arm23:
        arg0[0x16] = t;
        *(s32*)(arg0 + 0x3C) = FB_BASE[4] + (s32)FB_BASE;
        {
            s32 r = *(s8*)(arg0 + 0x56);
            *(s16*)(arg0 + 0x40) = 0x1D00;
            v = ((r + 0x18) % 4 + 0x10) | (((r + 0x18) / 4 + 0x1F0) << 6);
        }
        break;
    default:
        arg0[4] = 1;
        arg0[6] = 0;
        return;
    }
    *(s16*)(arg0 + 0x42) = v;
    arg0[4] = 1;
    arg0[6] = 0;
}

#include "../shared/d1000/func_80048DC8.c"

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();           /* extern */
s32 func_8002CB50(struct X4_BaseObj*); /* extern */

void func_80048E14(void* arg0) {
    ((s32(*)())func_8002CB50)();
    if (M2C_FIELD(arg0, s8*, 0x54) != D_800CCED1) {
        clear_object_slot(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x55) != D_80097420.transition.selection) {
        clear_object_slot(arg0);
    }
}

#define func_80048DC8 func_80048E7C
#define D_80077BC0 D_80077BC8
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"
#include "mmx6/globals.h"

#define FB_BASE ((s32*)0x801F3000)

void func_80048EC8(u8* arg0) {
    s32 t;

    arg0[0] = 1;
    *(s8*)(arg0 + 0x14) = -1;
    t = arg0[2] & 0xF;
    arg0[0x15] = 0;
    switch (t) {
    case 0: {
        s32 b = (s32)FB_BASE;
        s32 v;
        arg0[0x16] = 2;
        v = FB_BASE[5];
        *(s16*)(arg0 + 0x40) = 0x1F00;
        *(s16*)(arg0 + 0x42) = 0x7C10;
        *(s32*)(arg0 + 0x3C) = v + b;
        arg0[0x47] = D_800CCED3;
        arg0[5] = 0;
    } break;
    case 1: {
        s32 b = (s32)FB_BASE;
        s32 v;
        arg0[0x16] = 2;
        v = FB_BASE[2];
        *(s16*)(arg0 + 0x40) = 0x1E00;
        *(s16*)(arg0 + 0x42) = 0x7C92;
        arg0[0x47] = t;
        arg0[5] = t;
        *(s32*)(arg0 + 0x3C) = v + b;
    } break;
    case 2: {
        s32 b = (s32)FB_BASE;
        s32 v;
        arg0[0x16] = t;
        v = FB_BASE[2];
        *(s16*)(arg0 + 0x40) = 0x1E00;
        *(s16*)(arg0 + 0x42) = 0x7C92;
        arg0[0x47] = 0x32;
        arg0[5] = t;
        *(s32*)(arg0 + 0x3C) = v + b;
    } break;
    }
    arg0[4]++;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CB50();
extern void (*D_80077BDC[])();

void func_80048FD4(s8* arg0) {
    D_80077BDC[arg0[5]](arg0);
    if (arg0[4] == 1) {
        ((void (*)())func_8002CB50)(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80049030(void) {
    clear_object_slot();
}

#include "common.h"
#include "mmx6/globals.h"

extern u16 D_80077BD4[][2];

void func_80049050(u8* arg0) {
    s32 idx;

    idx = (s32)(arg0[2] << 0x18) >> 0x1C;
    arg0[0x47] = D_800CCED3;
    *(s16*)(arg0 + 0xA) = D_80077BD4[idx][0];
    *(s16*)(arg0 + 0xE) = D_80077BD4[idx][1];
}

#include "common.h"
#include "mmx6/globals.h"

extern u16 D_80077BD4[][2];

void func_80049090(u8* arg0) {
    s32 idx;

    idx = (s32)(arg0[2] << 0x18) >> 0x1C;
    if (D_800CCEDA == 0) {
        *(s16*)(arg0 + 0xA) = 0x28;
    } else {
        *(s16*)(arg0 + 0xA) = 0x68;
    }
    *(s16*)(arg0 + 0xE) = D_80077BD4[idx][1] + 0x10;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800490DC(void* arg0) {
    M2C_FIELD(arg0, s16*, 0xA) = 0x3F;
    M2C_FIELD(arg0, s16*, 0xE) =
        (s16)((D_80097420.transition.selection * 0x10) + 0x30);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK clear_object_slot();
s32 func_8002CB50(struct X4_BaseObj*);
void func_80049748(struct X4_BaseObj* arg0, struct X4_BaseObj* arg1);
extern struct X4_PlayerObj g_Player;

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_80049100(struct X4_VisualObj* arg0) {
    s32 var_v1;
    u8* p;
    s32 off;

    if (g_Player.action == 0x14) {
        ((void (*)())clear_object_slot)();
        return;
    }
    if (arg0->state == 0) {
        arg0->on_screen = 1;
        arg0->unk38 = 0;
        p = SCRATCH_1C;
        off = *(s32*)(p + 4);
        arg0->animation_table = g_visual_animation_tables;
        arg0->unk40 = 0;
        arg0->unk42 = 0x7802;
        arg0->unk16 = 3;
        arg0->unk3C = p += off;
        ((void (*)())func_80049748)(arg0, &g_Player, p, off);
        ((void (*)())set_animation)(arg0, 2);
        arg0->state++;
    } else {
        ((void (*)())animate_object)(arg0);
        ((void (*)())func_80049748)(arg0, &g_Player);
        var_v1 = 0;
        if (g_Player.dash_momentum > 0) {
            if (g_Player.unk17 != 0x10) {
                var_v1 = g_Player.unk17 != 0x80;
            }
        } else if (g_Player.unk17 != 0x55 && g_Player.unk17 != 0x12 &&
                   g_Player.unk17 != 0xAB && g_Player.unk17 != 0xAC &&
                   g_Player.unk17 != 0xAD && g_Player.unk17 != 0xA9) {
            var_v1 = 1;
        }
        if (arg0->animation_step.fields.relative_step < 0) {
            var_v1 = 1;
        }
        if (var_v1 != 0) {
            ((void (*)())clear_object_slot)(arg0);
            return;
        }
    }
    ((s32(*)())func_8002CB50)(arg0);
}
