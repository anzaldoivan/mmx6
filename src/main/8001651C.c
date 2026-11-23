#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

void func_80015C5C(void); /* extern */

void func_8001651C(void) {
    if (D_8008EC08 != 0) {
        func_80015C5C();
    }
}

#include "common.h"
#include "mmx6/globals.h"

s32 func_80016548(s32 arg0, s32* arg1) {
    s32* p = rock_dat_file_table[arg0];
    *arg1 = p[1];
    return p[0];
}

#include "common.h"
#include "psyq/libcd.h"

#define M2C_UNK s32

u8 func_80016570(void) {
    u8 sp10;

    do {

    } while (CdControlB(1, 0, &sp10) == 0);
    return sp10;
}

#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s8 func_80014D50();
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
extern M2C_UNK* D_800B91B8;

void func_800165A4(void) {
    if (D_8009509C != 0) {
        D_800E01D0 += 1;
        if (func_80064894(1, 0) != 1) {
        fail:
            func_800648B4(0);
            CdControlB(9, 0, 0);
            D_8009509C = 0x80;
        } else if (func_80014D50() == -1) {
            // !FAKE: shared failure block, target places it first
            goto fail;
        } else if (D_800E01A8 == 0) {
            func_800648B4(0);
            D_8009509C = 0;
            do {
            } while (CdControl(9, 0, 0) == 0);
            D_8009509C = 2;
            D_800B91B8 = (M2C_UNK*)D_800E0368;
            D_8009B798 = D_800E0374;
        }
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/3D88.c:func_80014140, AGPL-3.0; proven shared with X6 by exact signature 6ba38c1ddd23 (see THIRD_PARTY.md). */
#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
X4_CdlCB func_800648B4(X4_CdlCB func);
s8 func_80014D50();

void func_8001668C(void) {
    if (D_800E01CD != 0) {
        D_800E01CD = 0;
        D_800E01AC = D_800E0368;
    }
    if (func_80014D50() == -1) {
        func_800648B4(0);
        CdControlB(CdlPause, NULL, NULL);
        D_8009509C = 0x80;
    }
}

void func_800166FC(void) {
}

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern X4_RECT D_800E01E0;

void func_80016704(void) {
    u16* p;
    u8* t;
    u8* q;
    s32 o;

    D_800E01E0.w = 0x40;
    t = (u8*)D_800E01E8;
    o = D_800DF998 * 0xC;
    q = t + 4;
    t = 0;
    p = (u16*)(o + q);
    D_800E01E0.h = 0x10;
    D_800E01E0.x = p[1];
    D_800E01E0.y = p[0];
    LoadImage((M2C_UNK*)&D_800E01E0, (M2C_UNK*)D_800CF998.sectors[D_800DF998]);
}
