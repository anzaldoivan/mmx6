#include "common.h"
#include "psyq/libgpu.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

extern s32 D_8006D894;
extern s32 D_8006D9A4;
extern s8 D_8006D9A8;

M2C_UNK end_task_slot(M2C_UNK);
void func_80016B3C();
void func_8001D218();
void func_8001D25C(void);
void func_8002C1DC();

void func_80012EB4(void) {
    if (D_8008EC0C != 0 && D_80097420.transition.active == 0) {
        if ((g_pad1_buttons[0] & 0x900) == 0x900) {
            if (--D_8009741A == 0) {
                D_8006D894 = 0;
                D_8006D9A4 = 0;
                D_8006D9A8 = 0;
                D_8008EC0C = 0;
                D_800E4188 = 0;
                SetDispMask(0);
                end_task_slot(0);
                end_task_slot(1);
                end_task_slot(2);
                end_task_slot(3);
                D_8009741A = 0x3C;
                func_8001D218();
                func_80016B3C();
                func_8002C1DC();
                func_8001D25C();
            }
        } else {
            D_8009741A = 0x3C;
        }
    }
}

#include "common.h"
#include "psyq/libgpu.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80012FA0(void* arg0) {
    ClearOTagR(arg0 + 0x70, 0x20);
    M2C_FIELD(arg0, s8*, 0x2A) = 0;
    M2C_FIELD(arg0, s8*, 0x2C) = 1;
    M2C_FIELD(arg0, s8*, 0x2D) = 0;
    M2C_FIELD(arg0, s8*, 0x2E) = 0;
    M2C_FIELD(arg0, s8*, 0x2F) = 0;
}

// clang-format off
#include "../shared/SLUS_013.95/func_80012FE4.c"
// clang-format on

#include "common.h"

extern s32 D_8006D894;
extern s32 D_8006D9A4;
extern s8 D_8006D9A8;

void func_80013008(void) {
    D_8006D894 = 0;
    D_8006D9A4 = 0;
    D_8006D9A8 = 0;
}

#include "common.h"

#define M2C_UNK s32

void start_pad_vibration(s32);
#define start_pad_vibration ((void (*)())start_pad_vibration)
extern s32 D_8006D894;

void func_80013024(void) {
    if ((D_80097420.transition.suspended == 0) && (D_8006D894 == 0)) {
        start_pad_vibration();
    }
}
#undef start_pad_vibration

#include "common.h"
#include "psyq/libpad.h"

extern u8 D_8006D898[];
extern u8 D_8006D8A0[];
extern s32 D_8006D8A4;

void func_80013064(void) {
    s32 w;
    s32 v;
    // !FAKE: regalloc pin, constant one kept in the second callee-saved register
    register s32 one asm("$17");

    w = PadInfoMode(0, 2, 0);
    v = PadGetState(0);
    one = 1;
    if (v == one) {
        D_8006D8A4 = 0;
    }
    if (D_8006D8A4 == 0) {
        PadSetAct(0, D_8006D8A0, 2);
        if (v == 2 || (v == 6 && (w == 4 || w == 7) &&
                       PadSetActAlign(0, D_8006D898) != 0)) {
            D_8006D8A4 = one;
        }
    }
}

#include "common.h"

extern s32 D_8006D9B0[];

void func_80013128(void) {
    u8* low = 0;
    u8* s;
    s32 buf;
    s32 off;
    s32* dst;
    s32* src;
    s32 i;
    s32 k;

    k = 0x40000404;
    buf = 0x801FEC00;
    off = 0xC0;
    s = (u8*)0x801F8100;
    for (i = 3; i >= 0; i--) {
        *(s16*)s = 0;
        *(s32*)(s + 0xC) = (s32)(*(u8**)(low + 0x110) + off);
        *(s32*)(s + 0x10) = buf;
        buf += 0x400;
        off += 0xC0;
        *(s32*)(*(s32*)(s + 0xC) + 0x94) = k;
        s[0x70] = 0;
        s += 0x80;
    }
    dst = (s32*)0x801F8000;
    src = D_8006D9B0;
    for (i = 8; i >= 0; i--) {
        *dst++ = *src++;
    }
}

#include "common.h"
#define M2C_UNK s32

#include "psyq/libapi.h"
extern s32 D_8006D9AC;
extern s32 D_800CF960;

#define SLOT_PTR (*(u8**)0x801F8300)

void func_800131AC(void) {
    u8* p;

    SLOT_PTR = (u8*)0x801F8100;
    do {
        p = SLOT_PTR;
        switch (*(u16*)p) {
        case 1:
            if (--*(s16*)(p + 2) != 0) {
                break;
            }
        case 2:
        case 4:
        case 0x7F:
            *(u16*)SLOT_PTR = 0x7F;
            ChangeTh(*(s32*)(SLOT_PTR + 8));
            if (D_8006D9AC != 0) {
                D_8006D9AC = 0;
                EnterCriticalSection();
                CloseTh(*(s32*)(SLOT_PTR + 8));
                *(s32*)(SLOT_PTR + 8) =
                    OpenTh(D_800CF960, *(s32*)(SLOT_PTR + 0x10),
                           *(s32*)(SLOT_PTR + 0x44));
                ExitCriticalSection();
            }
            break;
        }
        SLOT_PTR += 0x80;
    } while ((u32)SLOT_PTR < 0x801F8300U);
}
