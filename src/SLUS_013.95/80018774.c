// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80018774);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80064C94(M2C_UNK*, u32); /* extern */
#define func_80064C94 ((M2C_UNK(*)(M2C_UNK*, u8))func_80064C94)
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)
extern M2C_UNK D_800E2E10;
extern u8 D_800E2E15;

void func_800187A0(s32 arg0) {
    u32 temp_v1;
    u8 temp_a1;

    temp_a1 = arg0 & 0xFF;
    D_800E2E15 = temp_a1;
    if (D_800CC869 == 1) {
        M2C_FIELD(&D_800E2E10, u8*, 0) = temp_a1;
        M2C_FIELD(&D_800E2E10, s8*, 1) = 0;
        M2C_FIELD(&D_800E2E10, u8*, 2) = temp_a1;
        M2C_FIELD(&D_800E2E10, s8*, 3) = 0;
    } else {
        temp_v1 = temp_a1 >> 1;
        M2C_FIELD(&D_800E2E10, u8*, 0) = (u8)temp_v1;
        M2C_FIELD(&D_800E2E10, s8*, 1) = (s8)temp_v1;
        M2C_FIELD(&D_800E2E10, u8*, 2) = (u8)temp_v1;
        M2C_FIELD(&D_800E2E10, s8*, 3) = (s8)temp_v1;
    }
    func_80064C94(&D_800E2E10, temp_a1);
}
#undef D_800CC869
#undef func_80064C94

#include "common.h"

extern s8 D_80097418;
extern s32 D_800E2E4C;
extern s32 D_800E2E5C;

void func_8001881C(void) {
    D_80097418 = 0;
    D_800E2E5C = 0;
    D_800E2E4C = 0;
}

#include "common.h"
#include "psyq/libcd.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*); /* extern */
extern s8 D_800CD40C;
extern s32 D_800E2E18;
extern u8 D_800E2E40;

void func_80018838(void) {
    s8 temp_v0;

    temp_v0 = func_80064874(1, &D_800E2E40);
    if ((temp_v0 == 2) && !(D_800E2E40 & 0x40) &&
        (CdControl(0x1B, 0, &D_800E2E40) != 0)) {
        D_800CD40C = temp_v0;
        D_800E2E18 = (s32)temp_v0;
    }
}

#include "common.h"
#include "psyq/libcd.h"

#define M2C_UNK s32

extern u8 D_800A21B4;
extern s8 D_800E2E16;
extern s32 D_800E2E18;
extern u8 D_800E2E40;
extern s16 D_800E2E48;

void func_800188BC(void) {
    if (D_800E2E48 & D_800A21B4) {
        do {

        } while (CdControl(9, 0, &D_800E2E40) == 5);
        D_800E2E18 = 3;
        if (D_800E2E40 & 0x10) {
            D_800E2E16 = 1;
        }
    }
}

#include "common.h"
#include "psyq/libcd.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*); /* extern */
extern u8 D_800A21B4;
extern s8 D_800E2E16;
extern s32 D_800E2E18;
extern u8 D_800E2E40;
extern s16 D_800E2E48;
extern s32 D_800E2E4C;

void func_80018948(void) {
    s32 temp_v0;

    temp_v0 = func_80064874(1, 0);
    if ((temp_v0 == 2) && (D_800E2E4C != 0) && (D_800A21B4 == 0) &&
        (CdControl(0x1B, 0, &D_800E2E40) != 0)) {
        D_800E2E48 = 0;
        D_800E2E18 = temp_v0;
        if (D_800E2E40 & 0x10) {
            D_800E2E16 = 1;
        }
    }
}

#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32

void func_800187A0(s32 arg0);
#include "psyq/libsnd.h"
s8 func_80064874(M2C_UNK, u8*);
extern u8 D_800E2E14;
extern s32 D_800E2E18;
extern s32 D_800E2E4C;

void func_800189E4(void) {
    s32 temp_v0;

    temp_v0 = func_80064874(1, 0);
    if (temp_v0 == 2) {
        if (D_800E2E4C == temp_v0) {
            if (CdControlB(9, 0, 0) != 0) {
                SsSetSerialAttr(0, 0, 0);
                D_800E2E14 = 0;
                func_800187A0(0);
                D_800E2E4C = 0;
                D_800E2E18 = 0;
            }
        } else {
            SsSetSerialAttr(0, 0, 0);
            D_800E2E14 = 0;
            func_800187A0(0);
            D_800E2E18 = 0;
        }
    }
}

#include "common.h"
#include "psyq/libcd.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*); /* extern */
extern M2C_UNK D_800E2E04;
extern s32 D_800E2E18;
extern s32 D_800E2E4C;
extern u8 D_800E2E60;

void func_80018A90(void) {
    s32 var_v0;

    if (func_80064874(1, 0) == 2) {
        if (D_800E2E60 == 0) {
            var_v0 = CdControl(0x15, &D_800E2E04, 0);
        } else {
            var_v0 = CdControlF(0x15, &D_800E2E04);
        }
        if (var_v0 != 0) {
            D_800E2E18 = 1;
        }
        D_800E2E4C = 2;
    }
}

#include "common.h"
#include "psyq/libcd.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*); /* extern */
extern s32 D_800E2E18;
extern M2C_UNK D_800E2E64;

void func_80018B10(void) {
    if ((func_80064874(1, 0) == 2) && (CdControl(0xD, &D_800E2E64, 0) != 0)) {
        D_800E2E18 = 5;
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:func_80016E84, AGPL-3.0; proven shared with X6 by exact signature adc4ba01bdcd (see THIRD_PARTY.md). */
#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#include "mmx6/x4.h"
extern u8 D_800E2E40;
#define D_800E2E40 (*(u8(*)[]) & D_800E2E40)
extern s8 D_800E2E16;
extern s32 D_800E2E18;

#define M2C_UNK s32
/* libcd command, status and mode bits used here (values as in the SDK's libcd.h) */
#ifndef CdlSetmode
#define CdlSetmode 0x0E
#define CdlComplete 0x02
#define CdlModeSpeed 0x80
#define CdlModeRT 0x40
#define CdlModeSF 0x08
#endif
s8 func_80064874(M2C_UNK, u8*);
void func_80018B60(void) {
    u8 sp10;

    if (((int (*)())func_80064874)(1, 0) == CdlComplete) {
        sp10 = CdlModeSpeed | CdlModeRT | CdlModeSF;
        if (((int (*)())CdControl)(CdlSetmode, &sp10, &D_800E2E40) != 0) {
            VSync(3);
            D_800E2E18 = 6;
            if (D_800E2E40[0] & 0x10) {
                D_800E2E16 = 1;
            }
        }
    }
}
#undef D_800E2E40

#include "common.h"

s32 func_80018BE0(s32 arg0, u8* arg1) {
    u16* src;
    u16* dst;
    u16* p;
    u32 flags;
    u32 bit;
    s32 n;
    u32 len;
    u32 off;
    u32 t;
    u16 tmp;

    src = (u16*)arg0;
    dst = (u16*)arg1;
    for (;;) {
        flags = *src++;
        bit = 0x8000;
        n = 16;
        do {
            if (!(bit & flags)) {
                tmp = *src++;
                bit >>= 1;
                n--;
                *dst++ = tmp;
                continue;
            }
            off = *src++;
            t = off & 0xF800;
            if (t != 0) {
                len = t >> 11;
                off &= 0x7FF;
            } else {
                len = *src++;
            }
            if ((len | off) == 0) {
                return;
            }
            if (off == 0) {
                bit >>= 1;
                n--;
                while (len != 0) {
                    *dst++ = 0;
                    len--;
                }
            } else {
                p = dst - off;
                bit >>= 1;
                n--;
                while (len != 0) {
                    *dst++ = *p++;
                    len--;
                }
            }
        } while (n != 0);
    }
}

#include "common.h"

void func_8001A330(u8, s32, s32, s32, s32, s32);
extern s32 D_800CCF60;

void func_80018CBC(void) {
    u8 d[6];
    s32 x;
    s32 h;
    s32 m;
    s32 s;

    if (D_800CCF60 > 0x57E3F) {
        d[0] = 9;
        d[1] = 9;
        d[2] = 5;
        d[3] = 9;
        d[4] = 9;
        d[5] = 9;
    } else {
        x = D_800CCF60;
        d[0] = x / 36000;
        h = x / 3600;
        d[1] = h % 60 % 10;
        m = x / 60 - h * 60;
        d[2] = m / 10;
        d[3] = m % 10;
        s = (x - x / 60 * 60) * 100 / 60;
        d[4] = s / 10;
        d[5] = s % 10;
    }
    func_8001A330(0x3C, 0xA8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[0] + 0x21, 0xB8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[1] + 0x21, 0xC8, 0xD8, 0x21, 1, 0);
    func_8001A330(0x2B, 0xD8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[2] + 0x21, 0xE8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[3] + 0x21, 0xF8, 0xD8, 0x21, 1, 0);
    func_8001A330(0x2C, 0x108, 0xD8, 0x21, 1, 0);
    func_8001A330(d[4] + 0x21, 0x118, 0xD8, 0x21, 1, 0);
    func_8001A330(d[5] + 0x21, 0x128, 0xD8, 0x21, 1, 0);
}

#include "common.h"

extern u8 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)
void func_8001A330(u8, s32, s32, s32, s32, s32);
s32 get_reploid_status(s32);

void func_80018F98(void) {
    s32 i;
    s32 n;

    if (D_800CCEDC != 0) {
        n = 0;
        i = 0;
        do {
            if (get_reploid_status(i) == 2) {
                n += 1;
            }
            i += 1;
        } while (i < 0x80);
        func_8001A330(0x39, 0xB0, 0x68, 0x21, 1, 0);
        func_8001A330(n / 100 + 0x21, 0xC0, 0x68, 0x21, 1, 0);
        func_8001A330(n % 100 / 10 + 0x21, 0xD0, 0x68, 0x21, 1, 0);
        func_8001A330(n % 10 + 0x21, 0xE0, 0x68, 0x21, 1, 0);
    }
}
#undef D_800CCEDC

#include "common.h"
#include "mmx6/x4.h"

void func_8001A330(u8, s32, s32, s32, s32, s32);
extern s8 D_800970A2;
extern struct X4_EngineObj g_playthrough_state;

void func_800190FC(void) {
    s32 v;

    if (g_playthrough_state.stage != 0) {
        v = *(s16*)((u8*)&g_playthrough_state + D_800970A2 * 2 + 0xD2);
        if (v >= 10000) {
            v = 9999;
        }
        func_8001A330(0x3B, 0xF0, 0x68, 0x21, 1, 0);
        func_8001A330(v / 1000 + 0x21, 0x100, 0x68, 0x21, 1, 0);
        func_8001A330(v % 1000 / 100 + 0x21, 0x110, 0x68, 0x21, 1, 0);
        func_8001A330(v % 100 / 10 + 0x21, 0x120, 0x68, 0x21, 1, 0);
        func_8001A330(v % 10 + 0x21, 0x130, 0x68, 0x21, 1, 0);
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_800192CC);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80070C84[][6];
extern u8 D_8008EAFC;
extern X4_P_TAG* D_8008EB08[2][4][8];
u32 func_800260C4(s32 arg0, s32 arg1, s32 arg2);
u8 func_8002624C(u8, u8, s32, s32);

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PRIM (*(u8**)0x1F800100)
#define SCR_TPAGE (*(u32**)0x1F800104)
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))

void func_800199E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5,
                   s32 arg6) {
    u8* prim;
    u32* tp;
    s32 x1;
    s32 y1;
    u32 c;
    s32 lo;

    x1 = arg0 + arg2;
    tp = SCR_TPAGE;
    prim = SCR_PRIM;
    y1 = arg1 + arg3;
    prim[3] = 8;
    prim[7] = 0x38;
    *(s16*)(prim + 0x8) = arg0;
    *(s16*)(prim + 0xA) = arg1;
    *(s16*)(prim + 0x10) = x1;
    *(s16*)(prim + 0x12) = arg1;
    *(s16*)(prim + 0x20) = x1;
    *(s16*)(prim + 0x22) = y1;
    *(s16*)(prim + 0x18) = arg0;
    *(s16*)(prim + 0x1A) = y1;
    prim[4] = D_80070C84[arg4][0];
    prim[5] = D_80070C84[arg4][1];
    prim[6] = D_80070C84[arg4][2];
    prim[0xC] = D_80070C84[arg4][3];
    prim[0xD] = D_80070C84[arg4][4];
    prim[0xE] = D_80070C84[arg4][5];
    prim[0xC] = func_8002624C(prim[0xC], prim[4], arg5, arg6);
    prim[0xD] = func_8002624C(prim[0xD], prim[5], arg5, arg6);
    prim[0xE] = func_8002624C(prim[0xE], prim[6], arg5, arg6);
    prim[0x1E] = prim[0xE];
    prim[0x1C] = prim[0xC];
    prim[0x1D] = prim[0xD];
    prim[0x14] = prim[4];
    prim[0x15] = prim[5];
    prim[0x16] = prim[6];
    if (D_8008EAFC != 0) {
        c = func_800260C4(prim[4], prim[5], prim[6]) >> 1;
        prim[6] = c;
        prim[5] = c;
        prim[4] = c;
        c = func_800260C4(prim[0xC], prim[0xD], prim[0xE]) >> 1;
        prim[0xE] = c;
        prim[0xD] = c;
        prim[0xC] = c;
        c = func_800260C4(prim[0x14], prim[0x15], prim[0x16]) >> 1;
        prim[0x16] = c;
        prim[0x15] = c;
        prim[0x14] = c;
        c = func_800260C4(prim[0x1C], prim[0x1D], prim[0x1E]) >> 1;
        prim[0x1E] = c;
        prim[0x1D] = c;
        prim[0x1C] = c;
    }
    ((u8*)tp)[3] = 1;
    lo = 4;
    tp[1] = 0xE1000000;
    SETADDR(D_8008EB08[SCR_BUF][0][lo], tp);
    SETADDR(tp, prim);
    D_8008EB08[SCR_BUF][0][lo] = (X4_P_TAG*)prim;
    SCR_PRIM += 0x28;
    SCR_TPAGE += 2;
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80019C84);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_MiscObj g_displayed_sprites[];

void func_800232D4(void*);
void func_800239CC(void*);

void func_8001A278(void) {
    struct X4_MiscObj* p;

    for (p = g_displayed_sprites; p < g_displayed_sprites + 0x60; p++) {
        if (p->on_screen != 0 && p->id == 0x16) {
            if (p->on_screen == 1) {
                func_800232D4(p);
            }
            if (p->on_screen == 2) {
                func_800239CC(p);
            }
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8001A330);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8001A3D4);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8001A494(s8* arg0) {
    s8 q;
    s32 v;

    q = arg0[2] / 3;
    {
        s32 k = 0xD0;
        v = ((s8*)&g_playthrough_state - -q)[k];
    }
    if (q != 0) {
        v = -v;
    }
    if (v < 0) {
        arg0[0x47] = 0x24;
        arg0[3] = 1;
        return;
    }
    arg0[3] = 0;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8001A4FC(u8* arg0) {
    // !FAKE: row base in the first return register
    register s8* b asm("$2");
    // !FAKE: idx in the first argument register
    register s32 i asm("$4");
    // !FAKE: value in the second return register
    register s32 v asm("$3");

    i = (s8)((s8)arg0[2] / 3);
    b = (s8*)&g_playthrough_state;
    b -= -i;
    v = b[0xD0];
    if (v < 0) {
        v = -v;
    }
    if (v >= 10) {
        arg0[0x47] = 0x19;
        arg0[3] = 1;
        return;
    }
    arg0[3] = 0;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8001A570(u8* arg0) {
    s32 v;
    s8 i;
    s8* p;

    i = (s8)arg0[2] / 3;
    p = (s8*)&g_playthrough_state;
    v = __builtin_abs((p - -i)[0xD0]);
    arg0[3] = 1;
    arg0[0x47] = (v % 10) + 0x18;
}

#include "../shared/stage/func_8001A5F8.c"

#include "common.h"

extern void (*D_80070C6C[])(s8*);
extern u16 D_80070C44[][2];

void func_8001A604(s8* arg0) {
    D_80070C6C[arg0[5]](arg0);
    *(u16*)(arg0 + 0xA) = D_80070C44[arg0[2]][0];
    *(u16*)(arg0 + 0xE) = D_80070C44[arg0[2]][1];
}

#include "common.h"

void clear_object_slot(void* arg0);
extern s8 D_800CCED1;
extern void (*D_80070C7C[])(s8*);

void func_8001A674(s8* arg0) {
    if (D_800CCED1 == 0) {
        ((void (*)())clear_object_slot)();
    } else {
        D_80070C7C[arg0[4]](arg0);
    }
}
