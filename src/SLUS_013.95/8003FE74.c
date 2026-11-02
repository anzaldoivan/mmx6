#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
M2C_UNK func_801EB02C(void*);          /* extern */

void func_8003FE74(void* arg0, s32 arg1) {
    s8 var_v0;

    M2C_FIELD(arg0, s8*, 7) = 0;
    if (((M2C_FIELD(arg0, s32*, 4) & 0xFFFF00) == 0xB00) ||
        (M2C_FIELD(arg0, s8*, 5) == 0x2F)) {
        func_8003BA04(arg0, 0xBB);
        var_v0 = 2;
        goto block_6;
    }
    if (arg1 == 0) {
        func_8003BA04(arg0, 0xB7);
        M2C_FIELD(arg0, s8*, 7) = 0;
    } else {
        func_8003BA04(arg0, 0xB8);
        var_v0 = 1;
    block_6:
        M2C_FIELD(arg0, s8*, 7) = var_v0;
    }
    M2C_FIELD(arg0, s8*, 5) = 0x4C;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    func_801EB02C(arg0);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);

void func_8003FF1C(void* arg0, s32 arg1) {
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0x26;
    if (arg1 == 0) {
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        func_8003BA04(arg0, 0xB9);
    } else {
        M2C_FIELD(arg0, u8*, 0x7) = 1;
        func_8003BA04(arg0, 0xBA);
    }
    M2C_FIELD(arg0, u8*, 0x86) = 0xA;
    player_spawn_visual(1, 0x1B, 6, 0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_8003FF90(struct X4_PlayerObj* arg0, s32 arg1) {
    s8 i = arg1;
    // !FAKE: first table byte held in the second return register, as the target allocates it
    register s32 v asm("$3");
    s8* p;
    s8 w;
    // !FAKE: result byte held in the first return register, as the target allocates it
    register s32 c asm("$2");
    // !FAKE: compare constant held in the second return register, as the target allocates it
    register s32 k asm("$3");

    p = (s8*)arg0 + i;
    v = p[0x9B];
    p = 0;
    if ((s8)v == 0) {
        return 0;
    }
    if (v == 1) {
        c = 0x26;
    shared:
        arg0->flash_palette = c;
        return 1;
    }
    k = 0x14;
    p = (s8*)arg0 + i;
    w = p[0x94];
    c = 0x29;
    if (w != k) {
        // !FAKE: shared store block placed after the v == 1 arm, as the target lays it out
        goto shared;
    }
    arg0->flash_palette = 0x2F;
    return 1;
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8003FFF4);
// clang-format on

#include "common.h"

extern s8 D_80074074[];
extern s8 D_800740B4[];

s8 func_800400B4(u8* arg0, s8 arg1) {
    s8 v = D_80074074[arg1];

    if (*(s32*)(arg0 + 0xEC) & 0x40000) {
        v = D_800740B4[arg1];
    }
    return v;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D230();
extern s32 D_800741F4[];
extern s32 D_800970A8;

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800400F4(void* arg0) {
    s32 v;

    if (F_S8(arg0, 6) == 0) {
        F_S8(arg0, 6)++;
        if (D_800970A8 < F_S32(arg0, 8)) {
            F_S32(arg0, 0x20) = D_800741F4[F_S8(arg0, 0x63) - 5];
        } else {
            F_S32(arg0, 0x20) = -D_800741F4[F_S8(arg0, 0x63) - 5];
        }
        F_S32(arg0, 0x28) = 0x3000;
        F_S32(arg0, 0x24) = 0;
        F_S32(arg0, 0x2C) = 0;
        if (F_S8(arg0, 0x63) == 5) {
            F_U8(arg0, 0x61) = 0x12;
        } else {
            F_U8(arg0, 0x61) = 1;
        }
    }
    func_8002D230(arg0);
    v = F_S32(arg0, 0x20);
    if ((v < 0 ? -v : v) < 0x6000) {
        F_S32(arg0, 0x20) = 0;
        F_S32(arg0, 0x28) = 0;
    }
    if (F_U8(arg0, 0x70) & 3) {
        F_S32(arg0, 0x20) = 0;
        F_S32(arg0, 0x28) = 0;
    }
    if ((s8)((s8)F_U8(arg0, 0x61) % 9) != 0) {
        F_U16(arg0, 0x42) &= 0x7FFF;
    } else {
        F_U16(arg0, 0x42) |= 0x8000;
    }
    if (--F_S8(arg0, 0x61) == 0) {
        F_S8(arg0, 5) = 1;
        F_S8(arg0, 6) = 0;
        F_S32(arg0, 0x20) = 0;
        F_S32(arg0, 0x28) = 0;
        F_U16(arg0, 0x42) &= 0x7FFF;
    }
}

#undef F_S8
#undef F_U8
#undef F_U16
#undef F_S32

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_80040290);
// clang-format on
