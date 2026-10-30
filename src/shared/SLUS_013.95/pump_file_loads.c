#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void task_yield(s32);
void func_80014E60(s32, s32);
M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
extern u8 D_8008EC08;
extern s32 D_8008EC0C;
extern u8 D_8009509C;
extern s32 D_800E01A8;
extern u8* D_800E01AC;
extern s32 D_800E01B0;
extern s32 D_800E01B4;
extern s32 D_800E01C0;
extern u8 D_800E0379;
extern u8 D_800E037A;
extern s32 D_800E037C;
extern u32 D_800E0380;
extern s32 rock_dat_file_table[][2];

// 0x80016178 pump_file_loads: steps the queued DAT file reads and re-issues a read on CD error status.
// basis: code src/shared/SLUS_013.95/pump_file_loads.c:65 via=rock_dat_file_table
// callers: func_8001447C, func_800144AC, func_8001731C
void pump_file_loads(void) {
    u8 res[8];
    u8 param[8];
    u8 idx;
    s32 loc;
    // !FAKE: depin: dropping it breaks the match (27/139)
    register s32 a asm("$4");
    s32 b;
    s32* p;

    param[0] = 0xA0;
    D_8008EC0C = 0;
    if (D_8009509C == 2) {
        goto check;
    }
    do {
        {
            if (D_8009509C & 0xC0) {
                if (D_800E01C0 == 0) {
                    idx = D_800E0379;
                    loc = D_800E037C;
                    if (func_80064894(1, 0) != 0) {
                        CdControlB(9, 0, 0);
                    }
                    if (D_8009509C != 0x80) {
                        D_800E0380 = 0;
                    }
                    D_8009509C = 0;
                    D_800E0379 = idx;
                    D_800E037C = loc;
                    do {
                        while (CdControlB(1, 0, res) == 0) {
                        }
                    } while (res[0] & 0x40);
                    D_800E01C0 = 0;
                    D_800E01B0 = b =
                        *(volatile s32*)((p = rock_dat_file_table[idx]) + 1);
                    D_800E01B4 = a = *(volatile s32*)p;
                    D_800E01AC = (u8*)loc;
                    D_800E01A8 = b;
                    func_80014E60(a, 0);
                } else {
                    func_80014F70(D_800E0379, D_800E037A, D_800E037C);
                }
            } else {
                if (++D_800E0380 >= 0x259) {
                    func_800648B4(0);
                    while (CdReset(0) == 0) {
                    }
                    while (CdControlB(0xE, (s32)param, 0) == 0) {
                    }
                    VSync(3);
                    D_8009509C = 0xC0;
                }
            }
            task_yield(1);
        }
        if (D_8009509C == 2) {
        check:
            if (D_8008EC08 == 0) {
                break;
            }
        }
    } while (1);
}
