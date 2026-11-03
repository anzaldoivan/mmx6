// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8001494C);
// clang-format on

#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_80014E60(s32, s32);
u8 func_80016570(void);
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
extern M2C_UNK* D_800B91B8;

s32 func_80014B78(void) {
    u8 sp10;
    s32 off;
    s32 a;
    s32 b;
    s32 s2;
    u8 s1;

    sp10 = 0xA0;
    if ((D_8009509C == 2) && (D_8008EC08 == 0)) {
        D_800B91B8 = D_800E0D30;
        D_800E0374 = D_800E0D34;
        return 1;
    }
    if (D_8009509C & 0xC0) {
        s1 = D_800E0379;
        s2 = D_800E037C;
        D_800E0D30 = D_800B91B8;
        D_800E0D34 = D_800E0374;
        if (func_80064894(1, 0) != 0) {
            CdControlB(9, 0, 0);
        }
        if (D_8009509C != 0x80) {
            D_800E0380 = 0;
        }
        off = s1 * 8;
        D_8009509C = 0;
        D_800E0379 = s1;
        D_800E037C = s2;
        do {
        } while (func_80016570() & 0x40);
        {
            // !FAKE: depin: dropping it breaks the match (69/118)
            register s32 b asm("$5") = *(s32*)(off + rock_bin_file_table);
            // !FAKE: depin: dropping it breaks the match (72/118)
            register s32 a asm("$4") = *(s32*)(rock_bin_file_table + off + 4);
            D_800E01C0 = 0;
            D_800E01AC = (u8*)s2;
            D_800E01B4 = b;
            D_800E01B0 = a;
            D_800E01A8 = a;
            func_80014E60(a, b);
        }
        return 0;
    }
    if (++D_800E0380 >= 0x259U) {
        func_800648B4(0);
        do {
        } while (CdReset(0) == 0);
        do {
        } while (CdControlB(0xE, (s32)&sp10, 0) == 0);
        VSync(3);
        D_8009509C = 0xC0;
    }
    return 0;
}

/* Adapted from sozud/mmx4 @807a01b src/main/3D88.c:func_800136B0, AGPL-3.0; proven shared with X6 by exact signature 630fc0e04ff1 (see THIRD_PARTY.md). */
#include "common.h"
#include "psyq/libds.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
int func_800617A4(X4_CdlLOC* p);
extern u8 D_800DF9A8[0x800];
extern X4_CdlLOC D_800E0388;

s8 func_80014D50(void) {
    s32 temp_v0_2;
    s32 temp_v0_3;
    u32 temp_v0;
    u32 var_v0;

    if ((u32)D_800E01A8 >= 0x801U) {
        DsGetSector(&D_800E0388, 3);
        temp_v0_2 = func_800617A4(&D_800E0388);
        if (temp_v0_2 == (D_800E01B4 + 1)) {
            D_800E01B4 = temp_v0_2;
            DsGetSector(D_800E01AC, 0x200);
            temp_v0 = D_800E01A8 - 0x800;
            D_800E01A8 = temp_v0;
            D_800E01AC += 0x800;
        } else {
            return -1;
        }
    } else {
        DsGetSector(&D_800E0388, 3);
        temp_v0_3 = func_800617A4(&D_800E0388);
        if (temp_v0_3 != (D_800E01B4 + 1)) {
            return -1;
        }
        D_800E01B4 = temp_v0_3;
        DsGetSector(D_800E01AC, ((u32)(D_800E01A8 + 3) >> 2));
        var_v0 = (u32)(D_800E01A8 + 3) >> 2;
        if (var_v0 != 0x200) {
            var_v0 = DsGetSector(&D_800DF9A8, 0x200 - var_v0);
        }
        D_800E01A8 = 0;
    }
}

#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_8001531C(void);
void func_800165A4(void);
void func_800646E4(s32, u8*);
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
extern u8 D_800E01D8;

void func_80014E60(s32 arg0, s32 arg1) {
    u8 sp10;

    sp10 = 0xA0;
    D_8009509C = 0;
    D_800E01D0 = 0;
    func_800646E4(D_800E01B4, &D_800E01D8);
    {
        // !FAKE: depin: dropping it breaks the match (65/68)
        register s32 t asm("$3") = D_800E01B4 - 1;
        D_800E01B4 = t;
    }
    do {
        do {
            while (func_80064894(1, 0) != 0) {
            }
        } while (CdControl(0xE, (s32)&sp10, 0) == 0);
        VSync(3);
    } while (CdControl(2, (s32)&D_800E01D8, 0) == 0);
    if (D_800E01C0 == 0) {
        func_800648B4((X4_CdlCB)func_800165A4);
    } else {
        func_800648B4((X4_CdlCB)func_8001531C);
    }
    while (CdControl(6, 0, 0) == 0) {
    }
    D_8009509C = 1;
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80014F70);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80015230);
// clang-format on

#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libds.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

int func_800617A4(X4_CdlLOC* p);
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);

extern s32 D_80010038[4];
extern u8** D_8006E27C[];
extern M2C_UNK* D_800B91B8;
extern s32* D_800E01B8;
extern s32 D_800E01C4;
extern s32 D_800E036C;
extern u8* D_800E0370;
extern X4_CdlLOC D_800E0388;
extern s32 D_800E0D40[];

#define STEP()                                                                 \
    D_800E01C4--;                                                              \
    D_800E01BC = *D_800E01B8++;                                                \
    D_800E01A8 = *D_800E01B8++;                                                \
    if ((D_800E01BC >> 16) == 0) {                                             \
        D_800E036C = D_800E01A8;                                               \
    }                                                                          \
    D_800E01CD = ret;

void func_8001531C(void) {
    s32 tbl[4];
    s32 ret;
    // !FAKE: depin: dropping it breaks the match (184/197)
    register s32 stop asm("$18");

    __builtin_memcpy(tbl, D_80010038, sizeof(tbl));
    if (D_8009509C == (stop = 0x80)) {
        return;
    }
    ret = func_80064894(1, 0);
    if (ret != 1) {
        func_800648B4(0);
        CdControlB(9, 0, 0);
        D_8009509C = stop;
        return;
    }
    if (D_800E01D0 == 0) {
        D_800E01B8 = D_800E0D40;
        DsGetSector(&D_800E0388, 3);
        if (func_800617A4(&D_800E0388) != D_800E01B4) {
            func_800648B4(0);
            CdControlB(9, 0, 0);
            D_8009509C = stop;
        } else {
            DsGetSector(D_800E01B8, 0x200);
            D_800E01C4 = *D_800E01B8++;
            D_800E01B0 = *D_800E01B8++;
            D_800E01BC = *D_800E01B8++;
            D_800E01A8 = *D_800E01B8++;
            D_800E01CD = ret;
            D_800E0368 = D_800E0370;
            D_800E01D0++;
            D_800E036C = D_800E01A8;
        }
    } else {
        ((void (*)(void))tbl[D_800E01BC >> 16])();
        if (D_800E01A8 == 0) {
            if ((D_800E01BC >> 16) == 0) {
                *D_8006E27C[D_800E01BC] = D_800E0368;
                D_800E0368 += D_800E036C;
            }
            STEP();
            if (D_800E01A8 == 0 && D_800E01C4 != 0) {
                STEP();
            }
        }
        D_800E01D0++;
        if (D_800E01C4 == 0) {
            func_800648B4(0);
            D_8009509C = 0;
            while (CdControl(9, 0, 0) == 0) {
            }
            D_8009509C = 2;
            D_800B91B8 = (M2C_UNK*)D_800E0368;
            D_8009B798 = D_800E0374;
        }
    }
}

#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s8 func_80014D50();
#include "psyq/libsnd.h"
#include "mmx6/globals.h"
X4_CdlCB func_800648B4(X4_CdlCB func);

void func_80015630(void) {
    s8* p;
    u32 i;
    s32 k;

    if (D_800E01CD != 0) {
        D_800E01CD = 0;
        D_800E01AC = D_800E0368;
    }
    if (func_80014D50() == -1) {
        func_800648B4(0);
        CdControlB(9, 0, 0);
        D_8009509C = 0x80;
        return;
    }
    if (D_800E01A8 == 0) {
        i = (D_800E01BC >> 8) & 0xFF;
        p = &D_80090D64[i];
        if (*p != -1) {
            SsSepClose(*p);
            *p = -1;
        }
        *p = SsSepOpen(D_800E0368, D_80090D50[i], 6);
        for (k = 0; k < 6; k++) {
            SsSepSetVol(D_80090D64[i], (s16)k, 0x7F, 0x7F);
        }
    }
}

#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
s8 func_80014D50();
X4_CdlCB func_800648B4(X4_CdlCB func);
extern u16 D_8006E2EC[][2];
extern u16 D_800CF988[];
extern u16 D_800CF98A[];
#define X_ D_800CF988[0]
#define Y_ D_800CF98A[0]
extern u16 D_800CF98C;

void func_8001574C(void) {
    u16 t;
    u16* p;

    D_800E01D6++;
    if (D_800E01D6 - D_800E01D4 >= 0x20) {
        func_800648B4(0);
        CdControlB(9, 0, 0);
        D_8009509C = 0x80;
        return;
    }
    if (D_800E01CD != 0) {
        D_800E01CD = 0;
        p = D_8006E2EC[(u8)D_800E01BC];
        X_ = p[0];
        t = p[1];
        Y_ = t;
        D_800CF98C = t & 0x100;
    }
    D_800E01AC = D_800CF998.sectors[D_800DF999];
    if (func_80014D50() == -1) {
        func_800648B4(0);
        CdControlB(9, 0, 0);
        D_8009509C = 0x80;
        return;
    }
    D_8008EC08 = 1;
    D_800E01E8[D_800DF999].pending = 1;
    D_800E01E8[D_800DF999].callback = 1;
    D_800E01E8[D_800DF999].callback_arg = (X_ << 16) | Y_;
    D_800DF999++;
    if (D_800DF999 == 0x20) {
        D_800DF999 = 0;
    }
    switch ((D_800E01BC & 0xFF00) >> 8) {
    case 0:
        if (Y_ == D_800CF98C + 0xF0) {
            X_ += 0x40;
            Y_ = D_800CF98C;
        } else {
            Y_ += 0x10;
        }
        break;
    case 2:
        if (Y_ == 0xF0) {
            Y_ = 0xB0;
            X_ += 0x40;
        } else {
            Y_ += 0x10;
        }
        break;
    case 3:
        if (Y_ == D_800CF98C + 0x10) {
            X_ -= 0x40;
            Y_ = D_800CF98C + 0xA0;
        } else {
            Y_ -= 0x10;
        }
        break;
    case 1:
    case 4:
        if (Y_ == D_800CF98C + 0xA0) {
            Y_ = 0x10;
            X_ += 0x40;
        } else {
            Y_ += 0x10;
        }
        break;
    case 5:
        if (Y_ == D_800CF98C) {
            Y_ = D_800CF98C + 0xF0;
            X_ -= 0x40;
        } else {
            Y_ -= 0x10;
        }
        break;
    case 6:
        X_ += 0x40;
        Y_ = D_800CF98C;
        break;
    }
}
#undef X_
#undef Y_
