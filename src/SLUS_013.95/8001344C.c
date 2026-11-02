// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8001344C);
// clang-format on

/* Adapted from sozud/mmx4 @807a01b src/main/2824.c:func_800128EC, AGPL-3.0; proven shared with X6 by exact signature ea1f214c77bc (see THIRD_PARTY.md). */
#include "common.h"

void func_80013480(s32 arg0) {

    u16* temp_a0 = (arg0 << 7) + 0x801F8100;

    *temp_a0 |= 0x40;
}

/* Adapted from sozud/mmx4 @807a01b src/main/2824.c:func_80012910, AGPL-3.0; proven shared with X6 by exact signature 56ff4cada450 (see THIRD_PARTY.md). */
#include "common.h"

void func_800134A4(s32 arg0) {

    u16* temp_a0 = (arg0 << 7) + 0x801F8100;

    *temp_a0 &= ~0x40;
}

void func_800134C8(void) {
}

void func_800134D0(void) {
}

#include "common.h"

#define SLOT_PTR (*(u8**)0x801F8300)

void func_800134D8(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        s32 t = i * 2;
        *(u16*)(SLOT_PTR + t + 0x60) = 0;
    }
    for (i = 0; i < 0x10; i++) {
        *(SLOT_PTR + i + 0x71) = 0;
    }
}

#undef SLOT_PTR

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80013530);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
#include "mmx6/state.h"
extern s8 D_800C8861;
extern M2C_UNK func_80013530;

M2C_UNK func_800139A0(s8 arg0) {
    if (D_80097420.transition.active == 0) {
        D_80097420.transition.active = 1;
        D_800C8861 = arg0;
        create_task(2, &func_80013530);
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_800139F4);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
extern M2C_UNK D_80013788;
extern s8 D_80090C8D;

void func_80013A48(s8 arg0) {
    D_80097420.transition.fade_amount = 1;
    if (arg0 < 0) {
        D_80090C8D = -arg0;
        create_task(3, &D_80013788);
        return;
    }
    D_80090C8D = arg0;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
extern M2C_UNK D_80013788;
extern s8 D_80090C8D;

void func_80013AA4(s8 arg0) {
    D_80097420.transition.fade_amount = -1;
    D_80090C8D = arg0;
    create_task(3, &D_80013788);
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80013AE0);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80013B04);
// clang-format on

#include "common.h"

void func_80013B20(s32* src, s32* dst, s32 n) {
    do {
        *dst++ = *src++;
    } while (--n);
}

#include "common.h"

void func_80013B40(s32* src, s32* dst, s32 n) {
    do {
        s32 a = src[0];
        s32 b = src[1];
        // !FAKE: target keeps the third word in t0
        register s32 c asm("$8") = src[2];
        // !FAKE: target keeps the fourth word in t1
        register s32 d asm("$9") = src[3];
        dst[0] = a;
        dst[1] = b;
        dst[2] = c;
        dst[3] = d;
        do {
            src += 4;
        } while (0);
        n--;
        dst += 4;
    } while (n != 0);
}

#include "common.h"

void func_80013B78(s32* arg0, s32* arg1, s32 arg2) {
    do {
        s32 a = arg0[0];
        s32 b = arg0[1];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 c asm("$8") = arg0[2];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 d asm("$9") = arg0[3];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 e asm("$10") = arg0[4];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 f asm("$11") = arg0[5];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 g asm("$12") = arg0[6];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 h asm("$13") = arg0[7];
        do {
            arg1[0] = a;
            arg1[1] = b;
            arg1[2] = c;
            arg1[3] = d;
            arg1[4] = e;
            arg1[5] = f;
            arg1[6] = g;
            arg1[7] = h;
        } while (0);
        arg2--;
        arg0 += 8;
        arg1 += 8;
    } while (arg2 != 0);
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80013BD0);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80013BE4);
// clang-format on
